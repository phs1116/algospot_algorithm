#include <iostream>
using namespace std;
#define MAX 100
int testcase;
int main() {
	cin >> testcase;;
	getchar();
	while (testcase--) {
		char input[100];
		char output[100];
		int k = 0;
		while ((input[k] = getc(stdin)) != '\n') k++;
		int i = 0;
		int j = 0;
		while (input[i] != '\n') {
			if (input[i] == '%') {
				if (input[i + 1] == '2') {
					switch (input[i + 2]) {
					case '0':
						output[j++] = ' '; break;
					case '1':
						output[j++] = '!'; break;
					case '4':
						output[j++] = '$'; break;
					case '8':
						output[j++] = '('; break;
					case '9':
						output[j++] = ')'; break;
					case 'a':
						output[j++] = '*'; break;
					case '5':
						output[j++] = '%'; break;
					}
				}
				i += 3;			
		}else output[j++] = input[i++];
			
		}
		output[j] = '\0';
		fputs(output, stdout);
		cout << endl;
	}
}
