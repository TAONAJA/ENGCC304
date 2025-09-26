#include <stdio.h>
#include <string.h>

struct Student {
    char Name[50];
    char ID[10];
    float ScoreSub[5];
};
typedef struct Student S;

// ฟังก์ชันแปลงคะแนนเป็นเกรด
const char* getGrade(float score) {
    if (score >= 80) return "A";
    else if (score >= 75) return "B+";
    else if (score >= 70) return "B";
    else if (score >= 65) return "C+";
    else if (score >= 60) return "C";
    else if (score >= 55) return "D+";
    else if (score >= 50) return "D";
    else return "F";
}

int main() {
    S students[3];
    float sum;
    printf("Enter the details of 3 students :\n");

    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);

        printf("Name: \n");
        fgets(students[i].Name, sizeof(students[i].Name), stdin);
        students[i].Name[strcspn(students[i].Name, "\n")] = '\0'; // ลบ \n ออก

        printf("ID: \n");
        fgets(students[i].ID, sizeof(students[i].ID), stdin);
        students[i].ID[strcspn(students[i].ID, "\n")] = '\0';

        for (int j = 0; j < 5; j++) {
            printf("Scores in Subject %d: \n", j + 1);
            scanf("%f", &students[i].ScoreSub[j]);
        }

        getchar(); // clear '\n' หลัง scanf เพื่อไม่ให้ fgets ข้ามรอบถัดไป
    }

    // แสดงผล
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].Name);
        printf("ID: %s\n", students[i].ID);

        printf("Scores: ");
        for (int j = 0; j < 5; j++) {
            printf("%.0f ", students[i].ScoreSub[j]);
        }
        printf("\n");

        printf("Grades: ");
        for (int j = 0; j < 5; j++) {
            printf("%s ", getGrade(students[i].ScoreSub[j]));
        }
        printf("\n");

        sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += students[i].ScoreSub[j];
        }

        printf("Average Scores: %.1f\n", sum / 5.0);
    }

    return 0;
}
