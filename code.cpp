#include <iostream>
#include <string.h>
using namespace std;

void fixId(char* id){
	
	if(strlen(id) == 1){
		id[3] = id[0];
		id[0] = id[1] = id[2] = '0';
		id[4] = '\0';
	}

    if(strlen(id) == 2){
  		id[3] = id[1];
		id[2] = id[0];
		id[0] = id[1] = '0';
		id[4] = '\0';
    }

    if(strlen(id) == 3){
		id[3] = id[2];
		id[2] = id[1];
		id[1] = id[0];
		id[0] = '0';
		id[4] = '\0';
    }
}

int main(){
	char var1[20] = "T",
		 var2[20] = "01",
		 var3[20] = "990",
		 var4[20] = "T285",
		 var5[20] = "J123456";

	fixId(var1);
	cout << var1; 

	cout << endl;
	return 0;
}
