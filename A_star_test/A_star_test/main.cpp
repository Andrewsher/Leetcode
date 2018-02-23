#include <Windows.h>
#include <math.h>
#include <iostream>
#include <random>
#include <stdlib.h>
using namespace std;

class pos {
public:
	int x, y;
};

class ListVertex {
public:
	int x, y;
	int fun;
	ListVertex* pre;
	ListVertex* next;
	ListVertex* parent;
	void setFun(pos dest) {
		// 计算f值
		int g = 1;
		for (ListVertex* cur = parent; cur != NULL; cur = cur->parent, g++);
		int h1 = x > dest.x ? x - dest.x : dest.x - x;
		int h2 = y > dest.y ? y - dest.y : dest.y - y;
		int h = 0.4 * (h1 + h2);
		fun = g + h;
		cout << x << ", " << y << " fun = " << fun << endl;
	}
	ListVertex() {
		x = 0;
		y = 0;
		fun = 0;
		pre = NULL;
		next = NULL;
		parent = NULL;
	}
};
class List {
	
private:
	// openList， 待查列表
	ListVertex* openFirstPos;
	ListVertex* openLastPos;
	// closeList, 无需检查的列表
	ListVertex* closeFirstPos;
	ListVertex* closeLastPos;
public:
	/*void setFirstVertex(pos vertex) {
		openFirstPos = new ListVertex();
		openFirstPos->x = vertex.x;
		openFirstPos->y = vertex.y;
		openFirstPos->pre = NULL;
		openFirstPos->next = NULL;
		openFirstPos->parent = NULL;
		openLastPos = openFirstPos;
	}*/
	ListVertex* getFirstOpenVertex() {
		return openFirstPos;
	}
	void addVertex(ListVertex* parent, pos vertex, pos dest) {
		// 将vertex位置作为parent的邻居添加进openList，同时计算fun值
		ListVertex* tmpVertex = new ListVertex();
		tmpVertex->x = vertex.x;
		tmpVertex->y = vertex.y;
		tmpVertex->pre = openLastPos;
		tmpVertex->next = NULL;
		tmpVertex->parent = parent;
		if (openFirstPos == NULL) openFirstPos = tmpVertex;
		if(openLastPos != NULL) openLastPos->next = tmpVertex;
		openLastPos = tmpVertex;
		//cout << tmpVertex->x << " and " << tmpVertex->y << " added!" << endl;
		tmpVertex->setFun(dest);
	}
	ListVertex* removeMinVertex() {
		// 从openList移除具有最小fun值的vertex并将其添加到closeList
		ListVertex* cur = openFirstPos, *min = openFirstPos;
		if (cur == NULL) return NULL;
		while (cur != NULL) {
			if (cur->fun < min->fun) {
				min = cur;
			}
			cur = cur->next;
		}
		
		if (min->pre) min->pre->next = min->next;
		if (min->next) min->next->pre = min->pre;
		if (min == openFirstPos) openFirstPos = min->next;
		if (min == openLastPos) openLastPos = min->pre;
		
		if (closeFirstPos == NULL) {
			closeFirstPos = min;
			min->pre = NULL;
			min->next = NULL;
			closeLastPos = min;
		}
		else {
			closeLastPos->next = min;
			min->pre = closeLastPos;
			min->next = NULL;
			closeLastPos = min;
		}
		
		return min;
	}
	void printCloseList() {
		ListVertex* cur = closeFirstPos;
		while (cur != NULL) {
			cout << cur->x << " " << cur->y << endl;
			cur = cur->next;
		}
	}
	bool isInOpenList(pos vertex) {
		// 检查vertex是否在openList中
		for (ListVertex* cur = openFirstPos; cur != NULL; cur = cur->next) {
			if (cur->x == vertex.x && cur->y == vertex.y) {
				return TRUE;
			}
		}
		return FALSE;
	}
	bool isInCloseList(pos vertex) {
		// 检查vertex是否在closeList中
		for (ListVertex* cur = closeFirstPos; cur != NULL; cur = cur->next) {
			if (cur->x == vertex.x && cur->y == vertex.y) {
				return TRUE;
			}
		}
		return FALSE;
	}
	ListVertex* findInCloseList(pos dest) {
		ListVertex* cur = closeFirstPos;
		while (TRUE) {
			if (cur == NULL) break;
			else if (cur->x == dest.x && cur->y == dest.y) break;
			cur = cur->next;
		}
		return cur;
	}
	bool isOpenListEmpty() {
		if (openFirstPos == NULL) return TRUE;
		else return FALSE;
	}
	bool isCloseListEmpty() {
		if (closeFirstPos == NULL) return TRUE;
		else return FALSE;
	}

	List() {
		openFirstPos = NULL;
		openLastPos = NULL;
		closeFirstPos = NULL;
		closeLastPos = NULL;
	}
	~List() {
		ListVertex* cur = openFirstPos;
		for(; cur != openLastPos; cur = cur->next) {
			if (cur->pre != NULL) {
				delete cur->pre;
			}
		}
		if (cur == NULL) return;
		if (cur->pre == NULL) delete cur;
		if (cur->pre != NULL) {
			delete cur->pre;
		}
		delete cur;
		cur = closeFirstPos;
		for (; cur != closeLastPos; cur = cur->next) {
			if (cur->pre != NULL) {
				delete cur->pre;
			}
		}
		if (cur->pre != NULL) {
			delete cur->pre;
		}
		delete cur;
	}
};


class human {
protected:
	int x, y;
	int mapSizeX, mapSizeY;
public:
	void setPos(int x, int y) {
		// Set x
		if (x < 0) this->x = 0;
		else if(x <= mapSizeX) this->x = x;
		else this->x = mapSizeX;
		 // Set y
		if (y < 0) this->y = 0;
		else if (y <= mapSizeY) this->y = y;
		else this->y = mapSizeY;
	}
	pos getPos() {
		pos res;
		res.x = this->x;
		res.y = this->y;
		return res;
	}
	void setMap(int x, int y) {
		this->mapSizeX = x;
		this->mapSizeY = y;
	}
};

class ghost :public human {
public:
	void moveUp() {
		setPos(this->x, this->y +1);
	}
	void moveDown() {
		setPos(this->x, this->y - 1);
	}
	void moveLeft() {
		setPos(this->x -1,this->y);
	}
	void moveRight() {
		setPos(this->x + 1, this->y);
	}
};

int main() {
	// 初始化地图
	int n = 10;	// 地图大小0-10
	const static int BLACK = 0;	// 空白
	const static int BLOCK = 1;	// 砖块
	const static int ROAD = 2;	// 路径
	int** map = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		map[i] = new int[n + 1];
	}
	for (int j = 0; j <= n; j++) {
		for (int i = 0; i <= n; i++) {
			if (i + j == n  && i != 0 && i != n) map[i][j] = BLOCK;
			else if (i == 3 && j != 0 && j < n ) map[i][j] = BLOCK;
			else if (j == 4 && i != 0 && i < n ) map[i][j] = BLOCK;
			else if (i == 7 && j != 0 && j != n) map[i][j] = BLOCK;
			else map[i][j] = BLACK;
		}
	}
	map[0][0] = 0;
	map[n][n] = 0;
	map[0][n] = 01;

	cout << "map size: " << n << endl;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (map[i][j] == 0) cout << ' ';
			else cout << '#';
		}
		cout << endl;
	}

	// 初始化目的位置
	pos dest = { n, n };
	// 初始化所在位置
	pos firPos = { 0, 0 };

	List* L = new List();

	// 将起始位置添加到openList
	if (L->isOpenListEmpty()) {
		L->addVertex(NULL, firPos, dest);
	}
	ListVertex* curNode = L->getFirstOpenVertex();
	// 循环处理
	while (TRUE) {
		if (curNode == NULL) break; // 不能继续处理
		if (L->isInCloseList(dest)) break; // 已经到达目的位置
		// 将当前位置的上下左右可通行位置加入openList
		int i = curNode->x, j = curNode->y;
		if (j >= 0 && j <= n) {
			if (i + 1 <= n && map[i + 1][j] == 0 && !L->isInCloseList(pos{ i + 1,j }) && !L->isInOpenList(pos{ i + 1,j })) {
				L->addVertex(curNode, pos{ i + 1,j }, dest);
			}
			if (i - 1 >= 0 && map[i - 1][j] == 0 && !L->isInCloseList(pos{ i - 1,j }) && !L->isInOpenList(pos{ i - 1,j })) {
				L->addVertex(curNode, pos{ i - 1,j }, dest);
			}
		}
		if (i >= 0 && i <= n) {
			if (j + 1 <= n && map[i][j + 1] == 0 && !L->isInCloseList(pos{ i ,j + 1 }) && !L->isInOpenList(pos{ i,j + 1 })) {
				L->addVertex(curNode, pos{ i,j + 1}, dest);
			}
			if (j - 1 >= 0 && map[i][j - 1] == 0 && !L->isInCloseList(pos{ i,j - 1 }) && !L->isInOpenList(pos{ i,j - 1 })) {
				L->addVertex(curNode, pos{ i ,j - 1 }, dest);
			}
		}
		
		// 将fun值最小的vertex添加到CloseList
		curNode = L->removeMinVertex();
	}

	curNode = L->findInCloseList(dest);
	if (curNode == NULL) {
		cout << "找不到路径！" << endl;
		//L->printCloseList();
	}
	else {
		while (curNode != NULL) {
			map[curNode->x][curNode->y] = ROAD;
			curNode = curNode->parent;
		}
	}
	cout << "map size: " << n << endl;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (map[i][j] == BLOCK) cout << "#"; // 不可通行
			//else if (L->isInCloseList(pos{ i, j })) cout << "$";
			else if (map[i][j] == ROAD) cout << "O"; // 路径
			else cout << " ";	// 空白
		}
		cout << endl;
	}

	delete L;

	// 回收地图
	for (int i = 0; i < n; i++) {
		delete[] map[i];
	}
	delete[] map;

	system("pause");
	return 0;
}