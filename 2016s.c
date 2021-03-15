#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int, int);

typedef struct node1{
    int month;
    int day;
    char* week;
    struct node1* next;
} daySeek;

int main() {
    // char* answer;
    solution(5, 24);
    // printf("%s\n", answer);
}

char* solution(int a, int b) {
    
    char* week[7] = {"THU", "FRI","SAT", "SUN", "MON", "TUE", "WED" };

    daySeek* seeker_head = NULL;
    daySeek* seeker_tail = NULL;
    daySeek* seeker_cursor = NULL;
    daySeek* newSeeker = NULL;

    int cnt = 1;

    for(int i = 0; i < 12; i++) {
        
        for(int j = 0; j < 31; j++) {
            int rest = cnt % 7;
            if(rest == 0) {
                cnt = 0;
            } 

            newSeeker = (daySeek*)malloc(sizeof(daySeek));
            newSeeker->month = i+1;
            newSeeker->next = NULL;
            

            if(i == 1) {
                if(j == 29 || j == 30) {
                    newSeeker->day = 0;
                    newSeeker->week = NULL;
                    cnt--;
                    // printf("%s %d %d\n", newSeeker->week, newSeeker->month, newSeeker->day);
                }                
                else {
                    newSeeker->day = j + 1;
                    newSeeker->week = week[rest];
                    // printf("%s %d %d\n", newSeeker->week, newSeeker->month, newSeeker->day);
                }
            }
            else if(i == 3 || i == 5 || i == 8 || i == 10) {
                if(j == 30) {
                    newSeeker->day = 0;
                    newSeeker->week = NULL;
                    cnt--;
                    // printf("%s %d %d\n", newSeeker->week, newSeeker->month, newSeeker->day);
                }
                else {
                    newSeeker->day = j + 1;
                    newSeeker->week = week[rest];
                    // printf("%s %d %d\n", newSeeker->week, newSeeker->month, newSeeker->day);
                }
            }
            else {                
            
                newSeeker->day = j + 1;
                newSeeker->week = week[rest];
                // printf("%s %d %d\n", newSeeker->week, newSeeker->month, newSeeker->day);
            }

            if(seeker_head == NULL) {
                seeker_head = newSeeker;
                
            }
            else {
                seeker_tail->next = newSeeker;
            }
            seeker_tail = newSeeker;
            cnt++;
        }
    }   

    seeker_cursor = seeker_head;
    while(seeker_cursor->next != NULL) {
        seeker_cursor = seeker_cursor->next;
        if(seeker_cursor->month == a && seeker_cursor->day == b) {
            // 리턴할 값은 메모리를 동적 할당해주세요.
            char* answer = (char*)malloc(sizeof(char) * 3);
            answer = seeker_cursor->week;
            printf("answer: %s\n", answer);
            return answer;
        }
    }
    
}