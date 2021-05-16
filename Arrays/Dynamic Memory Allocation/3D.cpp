#include <iostream>
using namespace std;

int main()
{
	int x = 2, y = 3, z = 4;
	int count = 0;

	int* a = new int[x * y * z];

	// Traverse the 3D array
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {

				// Assign values to the
				// memory blocks created
				*(a + i * y * z + j * z + k) = ++count;
			}
		}
	}

	// Traverse the 3D array again
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {

				// Print values of the
				// memory blocks created
				cout << *(a + i * y * z + j * z + k) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	// Deallocate memory
	delete[] a;

	return 0;
}
