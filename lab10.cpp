#include <stdio.h>
#include <string.h>
#include <ctype.h>  // สำหรับใช้ฟังก์ชัน tolower()

int main() {
    char word[100];         // ประกาศอาร์เรย์รับคำขนาดไม่เกิน 100 ตัวอักษร
    char cleaned[100];      // สำหรับเก็บข้อความที่แปลงเป็นตัวพิมพ์เล็กแล้ว และลบช่องว่าง (ถ้ามี)
    int len, i, j = 0, is_palindrome = 1;

    // รับข้อความจากผู้ใช้
    printf("Enter word:\n");
    fgets(word, sizeof(word), stdin);

    // ลบ '\n' ออกจากข้อความที่รับมา
    len = strlen(word);
    if (word[len - 1] == '\n') {
        word[len - 1] = '\0';
        len--;
    }

    // เตรียมข้อมูล: แปลงเป็นตัวพิมพ์เล็กทั้งหมด และลบช่องว่าง/อักขระพิเศษ (ถ้าต้องการ)
    for (i = 0; i < len; i++) {
        if (isalnum(word[i])) {  // รับเฉพาะตัวอักษรหรือตัวเลข (ถ้าไม่ต้องการลบช่องว่าง ให้ลบเงื่อนไขนี้ออก)
            cleaned[j++] = tolower(word[i]);
        }
    }
    cleaned[j] = '\0'; // ปิดท้าย string

    // ตรวจสอบว่าเป็นพาลินโดรมหรือไม่
    int cleaned_len = strlen(cleaned);
    for (i = 0; i < cleaned_len / 2; i++) {
        if (cleaned[i] != cleaned[cleaned_len - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }

    // แสดงผลลัพธ์
    if (is_palindrome) {
        printf("Pass.\n");
    } else {
        printf("Not Pass.\n");
    }

    return 0;
}
