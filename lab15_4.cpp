#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void shuffle(int &,int &,int &,int &);

int main(){
	int a = 50, b = 100, c = 500, d = 1000;
	
	srand(time(0));	
	
	for(int i = 0;i < 10;i++){
	    shuffle(a,b,c,d);
	    cout << a << " " << b << " " << c << " " << d << endl;
	}
	
	return 0;
}

//Do not modify source code above this line
void shuffle(int &a, int &b, int &c, int &d) {
    // นำ Reference ของทั้ง 4 ตัวแปรมาเก็บไว้ใน Array ของ Pointer 
    // เพื่อให้ง่ายต่อการใช้ Loop ในการสลับตำแหน่ง
    int *arr[] = {&a, &b, &c, &d};

    // ใช้ Fisher-Yates Shuffle Algorithm ในการสุ่มสลับตำแหน่ง
    for (int i = 3; i > 0; i--) {
        // สุ่มหา Index ตัวที่จะเอามาสลับ (0 ถึง i)
        int j = rand() % (i + 1);

        // ทำการ Swap ค่าในตัวแปรที่ Pointer ชี้อยู่
        int temp = *arr[i];
        *arr[i] = *arr[j];
        *arr[j] = temp;
    }
}