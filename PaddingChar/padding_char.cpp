#include <iostream>
#include <string.h>
using namespace std;

char* fixId(char* id){
	char* res = new char[5];

	if(strlen(id) == 1){
		res[0] = '0';
		res[1] = '0';
		res[2] = '0';
		res[3] = id[0];
		res[4] = '\0';
		return res;
	}

    if(strlen(id) == 2){
        res[0] = '0';
        res[1] = '0';
        res[2] = id[0];
        res[3] = id[1];
        res[4] = '\0';
		return res;
    }

    if(strlen(id) == 3){
        res[0] = '0';
        res[1] = id[0];
        res[2] = id[1];
        res[3] = id[2];
        res[4] = '\0';
		return res;
    }
	return id;
}

int main(){
	char var1[] = "T",
		 var2[] = "01",
		 var3[] = "990",
		 var4[] = "T285",
		 var5[] = "J123456";

	cout << strcmp(fixId(var1),"000T") << endl;
	cout << fixId(var2) << endl;
	cout << fixId(var3) << endl;
	cout << fixId(var4) << endl;
	cout << fixId(var5) << endl;

	cout << endl;
	return 0;
}
