#include <stdio.h>

// โครงสร้างสินค้า
struct Product {
    char name[30];
    int price;
    int stock;
    int day, month, year; // วันหมดอายุ
};

// ฟังก์ชันตรวจสอบวันหมดอายุ (1 = หมดอายุ, 0 = ยังไม่หมด)
int isExpired(int d, int m, int y, int cd, int cm, int cy) {
    if (y < cy) return 1;
    if (y == cy && m < cm) return 1;
    if (y == cy && m == cm && d < cd) return 1;
    return 0;
}

// ฟังก์ชันเช็คว่ายังมีสินค้าคงเหลือหรือไม่
int hasStock(struct Product products[], int n) {
    for (int i = 0; i < n; i++) {
        if (products[i].stock > 0) return 1; // ยังมีสินค้า
    }
    return 0; // ของหมดทุกตัว
}

int main() {
    // กำหนดวันที่ปัจจุบัน (fix ไว้ในโค้ด)
    int currentDay = 29, currentMonth = 8, currentYear = 2025;

    // สินค้าสูงสุด 20 ชิ้น
    struct Product products[3] = {
        {"น้ำดื่ม", 10, 20, 1, 12, 2025},    // หมดอายุ 01/12/2025
        {"ขนม", 15, 20, 15, 7, 2025},        // หมดอายุ 15/07/2025
        {"น้ำอัดลม", 20, 20, 30, 9, 2025}   // หมดอายุ 30/09/2025
    };

    // ตรวจสอบสินค้าที่หมดอายุตั้งแต่แรก
    for (int i = 0; i < 3; i++) {
        if (isExpired(products[i].day, products[i].month, products[i].year,
                      currentDay, currentMonth, currentYear)) {
            products[i].stock = 0; // ถ้าหมดอายุ ให้ตัดสต็อกออกทั้งหมด
        }
    }

    while (hasStock(products, 3)) { // รันจนกว่าสินค้าหมดทั้งหมด
        int choice, qty, totalPrice, money = 0, pay, change, method;

        printf("\n=== ตู้กดสินค้า ===\n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s ราคา %d บาท (เหลือ %d ชิ้น)\n",
                   i + 1, products[i].name, products[i].price, products[i].stock);
        }

        printf("เลือกสินค้าที่ต้องการ (1-3): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("ไม่มีสินค้านี้\n");
            continue;
        }

        choice--; // index ของ array

        // ตรวจสอบสต็อก
        if (products[choice].stock <= 0) {
            printf("ไม่สามารถขาย %s ได้ (สินค้าหมดหรือหมดอายุแล้ว)\n", products[choice].name);
            continue;
        }

        printf("คุณเลือก: %s ราคา %d บาท\n", products[choice].name, products[choice].price);

        // เลือกจำนวนสินค้า
        printf("กรอกจำนวนที่ต้องการซื้อ: ");
        scanf("%d", &qty);

        if (qty <= 0) {
            printf("จำนวนไม่ถูกต้อง\n");
            continue;
        }
        if (qty > products[choice].stock) {
            printf("มีสินค้าไม่พอ (เหลือ %d ชิ้น)\n", products[choice].stock);
            continue;
        }

        totalPrice = qty * products[choice].price;
        printf("รวมราคาทั้งหมด: %d บาท\n", totalPrice);

        // เลือกวิธีการชำระเงิน
        printf("เลือกวิธีการชำระเงิน:\n");
        printf("1. หยอดเหรียญ/ธนบัตร\n");
        printf("2. สแกน QR จ่ายเงิน\n");
        printf("เลือก: ");
        scanf("%d", &method);

        if (method == 1) {
            // รับเงินหยอด
            while (money < totalPrice) {
                printf("ใส่เงิน (รับเฉพาะ 1, 5, 10, 20, 50, 100): ");
                scanf("%d", &pay);

                if (pay == 1 || pay == 5 || pay == 10 || pay == 20 || pay == 50 || pay == 100) {
                    money += pay;
                    printf("ยอดเงินปัจจุบัน: %d บาท\n", money);
                } else {
                    printf("ไม่รับธนบัตร/เหรียญนี้\n");
                }
            }
        } else if (method == 2) {
            printf("กรุณาสแกน QR เพื่อชำระเงิน %d บาท...\n", totalPrice);
            printf("(สมมติว่าผู้ใช้ชำระเงินเรียบร้อย)\n");
            money = totalPrice; // จ่ายครบ
        } else {
            printf("วิธีการชำระเงินไม่ถูกต้อง\n");
            continue;
        }

        // ตรวจสอบและคืนเงินทอน
        if (money >= totalPrice) {
            change = money - totalPrice;
            products[choice].stock -= qty; // ลดจำนวนสินค้า
            printf("กำลังจ่ายสินค้า...\n");
            printf("รับ %s จำนวน %d ชิ้น ของคุณได้เลย!\n", products[choice].name, qty);
            if (change > 0) {
                printf("เงินทอนของคุณ: %d บาท\n", change);
            }
            printf("เหลือสินค้า: %d ชิ้น\n", products[choice].stock);
        }

        printf("=== ทำรายการเสร็จสิ้น ===\n");
    }

    printf("\n--- สินค้าหมดทั้งหมด ตู้กดปิดการทำงาน ---\n");
    return 0;
}
