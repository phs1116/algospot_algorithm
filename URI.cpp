#include <iostream>
using namespace std;
#define MAX 100
int testcase;
int main() {

	cin >> testcase;
	int ascii;
	getchar();
	while (testcase--) {
		char input[100];
		char output[100];
		int k = 0;
		while ((input[k] = getc(stdin)) != '\n') {
			k++;
		}

		int i = 0;
		int j = 0;
		while (input[i] != '\n') {
			if (input[i] == '%') {
				if (input[i + 1]>=48 && input[i + 1]<=57)  {
					ascii  = atoi(input[i+1])*16;
					if(input[i + 2]>=48 && input[i + 2]<=57)
						ascii  += atoi(input[i+1])
					}

				}
				i += 3;
				
			}
			else {
				output[j++] = input[i++];
			}
		}

		output[j] = '\0';

		fputs(output, stdout);
		cout << endl;
	}


}
