/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


class Solution {
public:
	void swap(Interval& x, Interval& y) {
		int tmp;
		tmp = x.start;
		x.start = y.start;
		y.start = tmp;
		tmp = x.end;
		x.end = y.end;
		y.end = tmp;
	}
	void sort_as_start(vector<Interval>& intervals) {
		for(int i = 0; i < intervals.size(); i++) {
			for (int j = 0; j < intervals.size() - 1; j++) {
				if(intervals[j].start > intervals[j + 1].start) {
					swap(intervals[j], intervals[j + 1]);
				}
			}
		}
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		if(intervals.size() <= 0) return result;
		sort_as_start(intervals);
		Interval tmp(intervals[0].start, intervals[0].end);
		for(int i = 0; i < intervals.size(); i++) {
			if(intervals[i].start <= tmp.end && intervals[i].end > tmp.end) {
				tmp.end = intervals[i].end;
			}
			else if(intervals[i].start > tmp.end){
				result.push_back(tmp);
				tmp.start = intervals[i].start;
				tmp.end = intervals[i].end;
			}
			else if(intervals[i].end <= tmp.end);
			else;
		}
		result.push_back(tmp);
		return result; 
	}
};