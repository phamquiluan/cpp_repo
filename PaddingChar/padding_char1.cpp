#include <iostream>
#include <string.h>
using namespace std;

string fixId(char* id){
	char res[5];

	if(strlen(id) == 1){
		res[0] = '0';
		res[1] = '0';
		res[2] = '0';
		res[3] = id[0];
		res[4] = '\0';
		return string(res);
	}

    if(strlen(id) == 2){
        res[0] = '0';
        res[1] = '0';
        res[2] = id[0];
        res[3] = id[1];
        res[4] = '\0';
		return string(res);
    }

    if(strlen(id) == 3){
        res[0] = '0';
        res[1] = id[0];
        res[2] = id[1];
        res[3] = id[2];
        res[4] = '\0';
		return string(res);
    }
	return string(id);
}

int main(){
	char var1[] = "T",
		 var2[] = "01",
		 var3[] = "990",
		 var4[] = "T285",
		 var5[] = "J123456";

	if(fixId(var1) == string("000T"))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << fixId(var2) << endl;
	cout << fixId(var3) << endl;
	cout << fixId(var4) << endl;
	cout << fixId(var5) << endl;

	cout << endl;
	return 0;
}
