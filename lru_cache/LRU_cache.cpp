#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <stdio.h>
using namespace std;


class LRUCache {

public:

	LRUCache(int c) {
		capacity = c;
	}

	int get(int key) {
		if (memo.find(key) == memo.end())
			return -1;

		list<key_value>::iterator pos = memo[key];
		key_value ans = *pos;
		queue.erase(pos);
		queue.push_front(ans);
		memo[key] = queue.begin();
		return ans.value;
	}

	void put(int key, int value) {
		if (get(key) != -1) {
			memo[key]->value = value;
			return;
		}

		key_value pairCur(key, value);
		queue.push_front(pairCur);
		memo[key] = queue.begin();

		while (queue.size() > capacity) {
			memo.erase(queue.back().key);
			queue.pop_back();
		}
	}


private:

	struct key_value {
		int key;
		int value;
		key_value(int k, int v) {
			key = k;
			value = v;
		}
	};

	int capacity;
	list<key_value> queue;
	unordered_map<int, list<key_value>::iterator> memo;

};


int main() {

	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;

	return 0;

}