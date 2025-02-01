#include <stdio.h>  
#include <stdlib.h>  

struct Proc {  
    int pid;  
    int at; // Arrival Time  
    int bt; // Burst Time  
    int wt; // Waiting Time  
    int tat; // Turnaround Time  
    struct Proc* next;  
};  

struct Proc* createProc(int pid, int at, int bt) {  
    struct Proc* newProc = (struct Proc*)malloc(sizeof(struct Proc));  
    newProc->pid = pid;  
    newProc->at = at;  
    newProc->bt = bt;  
    newProc->wt = 0;  
    newProc->tat = 0;  
    newProc->next = NULL;  
    return newProc;  
}  

void calculateWTandTAT(struct Proc* head) {  
    int currentTime = 0;  
    struct Proc* curr = head;  

    while (curr != NULL) {  
        if (currentTime < curr->at) {  
            currentTime = curr->at;   
        }  
        curr->wt = currentTime - curr->at;  
        currentTime += curr->bt;  
        curr->tat = curr->wt + curr->bt;  
        curr = curr->next;  
    }  
}  

void sortProcesses(struct Proc** head) {  
    if (*head == NULL || (*head)->next == NULL) return;  

    struct Proc* sorted = NULL;  
    struct Proc* curr = *head;  
    
    while (curr != NULL) {  
        struct Proc* minProc = curr;  
        struct Proc* minPrev = NULL;  
        struct Proc* temp = curr;  
        struct Proc* prev = NULL;  

        while (temp != NULL) {  
            if (temp->at <= curr->at + curr->bt) {  
                if (temp->bt < minProc->bt) {  
                    minProc = temp;  
                    minPrev = prev;  
                }  
            }  
            prev = temp;  
            temp = temp->next;  
        }  

        if (minPrev == NULL) {  
            *head = curr->next;  
        } else {  
            minPrev->next = curr->next;  
        }  

        minProc->next = sorted;  
        sorted = minProc;  

        curr = *head; // Restart from the head after sorting  
    }  

    *head = sorted;  
}  

void printProcs(struct Proc* head) {  
    printf("PID\tAT\tBT\tWT\tTAT\n");  
    struct Proc* curr = head;  
    while (curr != NULL) {  
        printf("%d\t%d\t%d\t%d\t%d\n", curr->pid, curr->at, curr->bt, curr->wt, curr->tat);  
        curr = curr->next;  
    }  
}  

void calcAvgTimes(struct Proc* head) {  
    int totalWT = 0, totalTAT = 0, count = 0;  
    struct Proc* curr = head;  

    while (curr != NULL) {  
        totalWT += curr->wt;  
        totalTAT += curr->tat;  
        count++;  
        curr = curr->next;  
    }  

    printf("Average Waiting Time: %.2f\n", (float)totalWT / count);  
    printf("Average Turnaround Time: %.2f\n", (float)totalTAT / count);  
}  

int main() {  
    struct Proc* head = NULL;  
    struct Proc* tail = NULL;  
    int n, pid, at, bt;  

    printf("Enter the number of processes: ");  
    scanf("%d", &n);  

    for (int i = 0; i < n; i++) {  
        printf("Enter PID, Arrival Time and Burst Time (PID AT BT): ");  
        scanf("%d %d %d", &pid, &at, &bt);  

        struct Proc* newProc = createProc(pid, at, bt);  

        if (head == NULL) {  
            head = newProc;  
            tail = newProc;  
        } else {  
            tail->next = newProc;  
            tail = newProc;  
        }  
    }  

    sortProcesses(&head);  
    calculateWTandTAT(head);  
    printProcs(head);  
    calcAvgTimes(head);  

    struct Proc* curr = head;  
    while (curr != NULL) {  
        struct Proc* temp = curr;  
        curr = curr->next;  
        free(temp);  
    }  

    return 0;  
}