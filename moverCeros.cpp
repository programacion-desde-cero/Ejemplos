#include <iostream>
#include <vector>
using namespace std;


void moverCeros(vector<int>& numeros) {
	for (int i = 0, ultimoCero = 0; i < numeros.size(); i++) {
 		if (numeros[i] != 0) {
			swap(numeros[ultimoCero++], numeros[i]);
		}
	}
}


int main() {
    vector<int> nums = {8, 0, 7, 22, 0, 0, 4};
    moverCeros(nums);
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
