#include <vector>
#include "towerofhanoi.hh"

using namespace std;

int main() {
	vector<Tower> towers;
	for(int i=0;i < 3; i++) {
		Tower tower(i+1);
		towers.push_back(tower);
	}
	for(int i=3; i > 0; i--)
		towers[0].addTo(i);
	towers[0].moveDisks(3, towers[2], towers[1]);
	return 0;
}
