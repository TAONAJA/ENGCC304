#include <stdio.h>
#include <math.h>    // สำหรับใช้ฟังก์ชัน sqrt()

// ฟังก์ชันตรวจสอบจำนวนเฉพาะ
int isPrime(int num) {
    if (num <= 1) return 0;           // จำนวนที่น้อยกว่าหรือเท่ากับ 1 ไม่ใช่จำนวนเฉพาะ
    for (int i = 2; i <= sqrt(num); i++) {  // ตรวจสอบหารจาก 2 ถึง sqrt(num)
        if (num % i == 0) return 0;   // ถ้าหารลงตัวไม่ใช่จำนวนเฉพาะ
    }
    return 1;  // ถ้าไม่เจอว่าแบ่งลงตัวเลย แสดงว่าเป็นจำนวนเฉพาะ
}

int main() {
    int N;

    // รับค่าจำนวนสมาชิกของอาเรย์
    printf("Enter N :\n");
    scanf("%d", &N);

    int arr[N];  // ประกาศอาเรย์ขนาด N

    // รับค่าทีละตัวเก็บลงในอาเรย์
    for (int i = 0; i < N; i++) {
        printf("Enter value[%d] :\n", i);
        scanf("%d", &arr[i]);
    }

    // แสดงหัวตาราง Index
    printf("Index: ");
    for (int i = 0; i < N; i++) {
        printf("%3d", i);
    }
    printf("\n");

    // แสดงค่าในอาเรย์ (เฉพาะจำนวนเฉพาะเท่านั้น)
    printf("Array: ");
    for (int i = 0; i < N; i++) {
        if (isPrime(arr[i])) {
            printf("%3d", arr[i]);  // ถ้าเป็นจำนวนเฉพาะ แสดงเลข
        } else {
            printf("  #");         // ถ้าไม่ใช่ แสดง #
        }
    }
    printf("\n");

    return 0;
}