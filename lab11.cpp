#include <stdio.h>
#include <math.h>  // สำหรับใช้ pow()

// ฟังก์ชันตรวจสอบว่าเป็นเลขอาร์มสตรองหรือไม่
int isArmstrong(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;
    int temp = num;

    // หาจำนวนหลักของเลข
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = num; // นำค่าเดิมกลับมาใช้ใหม่

    // คำนวณผลรวมของแต่ละหลักยกกำลังจำนวนหลัก
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits); // ยกกำลัง
        temp /= 10;
    }

    // เปรียบเทียบว่าเท่ากับเลขต้นฉบับหรือไม่
    if (sum == original) {
        return 1; // เป็นเลขอาร์มสตรอง
    } else {
        return 0; // ไม่ใช่
    }
}

int main() {
    int number;

    // รับค่าจากผู้ใช้
    printf("Enter Number:\n");
    scanf("%d", &number);

    // เรียกใช้ฟังก์ชันตรวจสอบ
    if (isArmstrong(number)) {
        printf("Pass.\n");
    } else {
        printf("Not Pass.\n");
    }

    return 0;
}
