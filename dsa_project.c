#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int staticArr[MAX];
int staticSize = 0;

int *dynArr = NULL;
int dynSize = 0;
int dynCapacity = 0;

int stackArr[MAX];
int stackTop = -1;

struct StackNode {
    int data;
    struct StackNode *next;
};
struct StackNode *stackLLTop = NULL;
int stackLLSize = 0;

int linQueue[MAX];
int linFront = -1, linRear = -1;

int circQueue[MAX];
int circFront = -1, circRear = -1, circCount = 0;

int dequeArr[MAX];
int dequeFront = -1, dequeRear = -1, dequeCount = 0;

struct SNode {
    int data;
    struct SNode *next;
};
struct SNode *sHead = NULL;

struct CNode {
    int data;
    struct CNode *next;
};
struct CNode *cHead = NULL;

struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};
struct DNode *dHead = NULL;

int sortArr[MAX];
int sortSize = 0;

void mainMenu();

void arrayMenu();
void dynamicArrayMenu();
void staticArrayMenu();

void dynCreate();
void dynInsert();
void dynSort();
void dynDelete();
void dynSearchMenu();
void dynReplace();
void dynFindByIndex();
void dynDisplay();

void staticEnterValues();
void staticSort();
void staticDelete();
void staticSearchMenu();
void staticReplace();
void staticFindByIndex();
void staticDisplay();

void stackMenu();
void stackArrayMenu();
void stackLLMenu();

void saPush();
void saPop();
void saPeek();
void saIsEmpty();
void saIsFull();
void saSize();
void saDisplay();
void saClear();
void saSearchMenu();

void slPush();
void slPop();
void slPeek();
void slIsEmpty();
void slIsFull();
void slSize();
void slDisplay();
void slClear();
void slSearchMenu();

void queueMenu();
void linearQueueMenu();
void circularQueueMenu();
void dequeMenu();

void lqEnqueue();
void lqDequeue();
void lqFront();
void lqRear();
void lqIsEmpty();
void lqIsFull();
void lqSize();
void lqDisplay();

void cqEnqueue();
void cqDequeue();
void cqFront();
void cqRear();
void cqIsEmpty();
void cqIsFull();
void cqSize();
void cqDisplay();

void dqPushFront();
void dqPushRear();
void dqPopFront();
void dqPopRear();
void dqFront();
void dqRear();
void dqIsEmpty();
void dqIsFull();
void dqSize();
void dqDisplay();

void linkedListMenu();
void singlyLinkedListMenu();
void circularLinkedListMenu();
void doublyLinkedListMenu();

void sAppend();
void sPrepend();
void sInsert();
void sDelete();
void sSearch();
void sLength();
void sReverse();
void sDisplay();

void cAppend();
void cPrepend();
void cInsert();
void cDelete();
void cSearch();
void cLength();
void cReverse();
void cDisplay();

void dAppend();
void dPrepend();
void dInsert();
void dDelete();
void dSearch();
void dLength();
void dReverse();
void dDisplay();

void sortMenu();
void sortEnterValues();
void bubbleSort();
void selectionSort();
void insertionSort();
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void heapSort();
void heapify(int arr[], int n, int i);
void printSortArr();

void clearInputBuffer();

int main() {
    mainMenu();
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mainMenu() {
    int choice;
    while (1) {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Array\n");
        printf("2. Stack\n");
        printf("3. Queue\n");
        printf("4. Linked List\n");
        printf("5. Sort\n");
        printf("6. Exit\n");
        printf("================================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: arrayMenu(); break;
            case 2: stackMenu(); break;
            case 3: queueMenu(); break;
            case 4: linkedListMenu(); break;
            case 5: sortMenu(); break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void arrayMenu() {
    int choice;
    while (1) {
        printf("\n----- ARRAY MENU -----\n");
        printf("1. Dynamic Array\n");
        printf("2. Static Array\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: dynamicArrayMenu(); break;
            case 2: staticArrayMenu(); break;
            case 3: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void dynamicArrayMenu() {
    int choice;
    while (1) {
        printf("\n----- DYNAMIC ARRAY MENU -----\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Sort\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Replace\n");
        printf("7. Find by Index\n");
        printf("8. Display\n");
        printf("9. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: dynCreate(); break;
            case 2: dynInsert(); break;
            case 3: dynSort(); break;
            case 4: dynDelete(); break;
            case 5: dynSearchMenu(); break;
            case 6: dynReplace(); break;
            case 7: dynFindByIndex(); break;
            case 8: dynDisplay(); break;
            case 9: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void dynCreate() {
    int n, i;

    if (dynArr != NULL) {
        free(dynArr);
        dynArr = NULL;
    }

    printf("Enter initial number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size. Must be between 1 and %d.\n", MAX);
        return;
    }

    dynCapacity = n + 5;   
    dynArr = (int *) malloc(dynCapacity * sizeof(int));

    if (dynArr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &dynArr[i]);
    }

    dynSize = n;
    printf("Dynamic array created successfully.\n");
}

void dynInsert() {
    int value;

    if (dynArr == NULL) {
        printf("Array not created yet. Please use Create first.\n");
        return;
    }

    if (dynSize >= dynCapacity) {
        int newCapacity = dynCapacity * 2;
        int *temp = (int *) realloc(dynArr, newCapacity * sizeof(int));
        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            return;
        }
        dynArr = temp;
        dynCapacity = newCapacity;
        printf("Array capacity expanded to %d.\n", dynCapacity);
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    dynArr[dynSize] = value;
    dynSize++;
    printf("Value inserted successfully.\n");
}

void dynSort() {
    int i, j, temp;

    if (dynArr == NULL || dynSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    for (i = 0; i < dynSize - 1; i++) {
        for (j = 0; j < dynSize - i - 1; j++) {
            if (dynArr[j] > dynArr[j + 1]) {
                temp = dynArr[j];
                dynArr[j] = dynArr[j + 1];
                dynArr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
    dynDisplay();
}

void dynDelete() {
    int index, i;

    if (dynArr == NULL || dynSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index to delete (0 to %d): ", dynSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= dynSize) {
        printf("Invalid index.\n");
        return;
    }

    for (i = index; i < dynSize - 1; i++) {
        dynArr[i] = dynArr[i + 1];
    }
    dynSize--;
    printf("Element deleted successfully.\n");
}

void dynSearchLinear() {
    int value, i, found = 0;

    if (dynArr == NULL || dynSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    for (i = 0; i < dynSize; i++) {
        if (dynArr[i] == value) {
            printf("Value found at index %d.\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void dynSearchBinary() {
    int value, low, high, mid, found = 0;

    if (dynArr == NULL || dynSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Note: Binary search requires a sorted array.\n");
    printf("Enter value to search: ");
    scanf("%d", &value);

    low = 0;
    high = dynSize - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (dynArr[mid] == value) {
            printf("Value found at index %d.\n", mid);
            found = 1;
            break;
        } else if (dynArr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Value not found.\n");
    }
}

void dynSearchMenu() {
    int choice;
    while (1) {
        printf("\n---- SEARCH (Dynamic Array) ----\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: dynSearchLinear(); break;
            case 2: dynSearchBinary(); break;
            case 3: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void dynReplace() {
    int index, value;

    if (dynArr == NULL || dynSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index to replace (0 to %d): ", dynSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= dynSize) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);
    dynArr[index] = value;
    printf("Value replaced successfully.\n");
}

void dynFindByIndex() {
    int index;

    if (dynArr == NULL || dynSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index (0 to %d): ", dynSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= dynSize) {
        printf("Invalid index.\n");
        return;
    }

    printf("Value at index %d is %d.\n", index, dynArr[index]);
}

void dynDisplay() {
    int i;

    if (dynArr == NULL || dynSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Dynamic Array: ");
    for (i = 0; i < dynSize; i++) {
        printf("%d ", dynArr[i]);
    }
    printf("\n");
}

void staticArrayMenu() {
    int choice;

    
    if (staticSize == 0) {
        printf("Static array is empty. Let's enter some values first.\n");
        staticEnterValues();
    }

    while (1) {
        printf("\n----- STATIC ARRAY MENU -----\n");
        printf("1. Sort\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Replace\n");
        printf("5. Find by Index\n");
        printf("6. Display\n");
        printf("7. Re-enter Values\n");
        printf("8. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: staticSort(); break;
            case 2: staticDelete(); break;
            case 3: staticSearchMenu(); break;
            case 4: staticReplace(); break;
            case 5: staticFindByIndex(); break;
            case 6: staticDisplay(); break;
            case 7: staticEnterValues(); break;
            case 8: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void staticEnterValues() {
    int n, i;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size.\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &staticArr[i]);
    }

    staticSize = n;
    printf("Static array filled successfully.\n");
}

void staticSort() {
    int i, j, temp;

    if (staticSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    for (i = 0; i < staticSize - 1; i++) {
        for (j = 0; j < staticSize - i - 1; j++) {
            if (staticArr[j] > staticArr[j + 1]) {
                temp = staticArr[j];
                staticArr[j] = staticArr[j + 1];
                staticArr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
    staticDisplay();
}

void staticDelete() {
    int index, i;

    if (staticSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index to delete (0 to %d): ", staticSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= staticSize) {
        printf("Invalid index.\n");
        return;
    }

    for (i = index; i < staticSize - 1; i++) {
        staticArr[i] = staticArr[i + 1];
    }
    staticSize--;
    printf("Element deleted successfully.\n");
}

void staticSearchLinear() {
    int value, i, found = 0;

    if (staticSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    for (i = 0; i < staticSize; i++) {
        if (staticArr[i] == value) {
            printf("Value found at index %d.\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void staticSearchBinary() {
    int value, low, high, mid, found = 0;

    if (staticSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Note: Binary search requires a sorted array.\n");
    printf("Enter value to search: ");
    scanf("%d", &value);

    low = 0;
    high = staticSize - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (staticArr[mid] == value) {
            printf("Value found at index %d.\n", mid);
            found = 1;
            break;
        } else if (staticArr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Value not found.\n");
    }
}

void staticSearchMenu() {
    int choice;
    while (1) {
        printf("\n---- SEARCH (Static Array) ----\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: staticSearchLinear(); break;
            case 2: staticSearchBinary(); break;
            case 3: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void staticReplace() {
    int index, value;

    if (staticSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index to replace (0 to %d): ", staticSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= staticSize) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);
    staticArr[index] = value;
    printf("Value replaced successfully.\n");
}

void staticFindByIndex() {
    int index;

    if (staticSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Enter index (0 to %d): ", staticSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= staticSize) {
        printf("Invalid index.\n");
        return;
    }

    printf("Value at index %d is %d.\n", index, staticArr[index]);
}

void staticDisplay() {
    int i;

    if (staticSize == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Static Array: ");
    for (i = 0; i < staticSize; i++) {
        printf("%d ", staticArr[i]);
    }
    printf("\n");
}

void stackMenu() {
    int choice;
    while (1) {
        printf("\n----- STACK MENU -----\n");
        printf("1. Stack Implementation using Array\n");
        printf("2. Stack Implementation using Linked List\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: stackArrayMenu(); break;
            case 2: stackLLMenu(); break;
            case 3: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void stackArrayMenu() {
    int choice;
    while (1) {
        printf("\n----- STACK (ARRAY) MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Size\n");
        printf("7. Display\n");
        printf("8. Clear\n");
        printf("9. Search\n");
        printf("10. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: saPush(); break;
            case 2: saPop(); break;
            case 3: saPeek(); break;
            case 4: saIsEmpty(); break;
            case 5: saIsFull(); break;
            case 6: saSize(); break;
            case 7: saDisplay(); break;
            case 8: saClear(); break;
            case 9: saSearchMenu(); break;
            case 10: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void saPush() {
    int value;
    if (stackTop == MAX - 1) {
        printf("Stack is full.\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &value);
    stackTop++;
    stackArr[stackTop] = value;
    printf("Value pushed successfully.\n");
}

void saPop() {
    if (stackTop == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Popped value: %d\n", stackArr[stackTop]);
    stackTop--;
}

void saPeek() {
    if (stackTop == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top value: %d\n", stackArr[stackTop]);
}

void saIsEmpty() {
    if (stackTop == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

void saIsFull() {
    if (stackTop == MAX - 1) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }
}

void saSize() {
    printf("Stack size: %d\n", stackTop + 1);
}

void saDisplay() {
    int i;
    if (stackTop == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (i = stackTop; i >= 0; i--) {
        printf("%d ", stackArr[i]);
    }
    printf("\n");
}

void saClear() {
    stackTop = -1;
    printf("Stack cleared.\n");
}

void saSearchLinear() {
    int value, i, found = 0;
    if (stackTop == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (i = 0; i <= stackTop; i++) {
        if (stackArr[i] == value) {
            printf("Value found at position %d (0 = bottom).\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void saSearchBinary() {
    int value, low, high, mid, found = 0;
    if (stackTop == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Note: Binary search requires the underlying array to be sorted.\n");
    printf("Enter value to search: ");
    scanf("%d", &value);

    low = 0;
    high = stackTop;
    while (low <= high) {
        mid = (low + high) / 2;
        if (stackArr[mid] == value) {
            printf("Value found at position %d (0 = bottom).\n", mid);
            found = 1;
            break;
        } else if (stackArr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void saSearchMenu() {
    int choice;
    while (1) {
        printf("\n---- SEARCH (Array Stack) ----\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: saSearchLinear(); break;
            case 2: saSearchBinary(); break;
            case 3: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void stackLLMenu() {
    int choice;
    while (1) {
        printf("\n----- STACK (LINKED LIST) MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Size\n");
        printf("7. Display\n");
        printf("8. Clear\n");
        printf("9. Search\n");
        printf("10. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: slPush(); break;
            case 2: slPop(); break;
            case 3: slPeek(); break;
            case 4: slIsEmpty(); break;
            case 5: slIsFull(); break;
            case 6: slSize(); break;
            case 7: slDisplay(); break;
            case 8: slClear(); break;
            case 9: slSearchMenu(); break;
            case 10: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void slPush() {
    int value;
    struct StackNode *newNode;

    if (stackLLSize == MAX) {
        printf("Stack is full.\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    newNode = (struct StackNode *) malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = stackLLTop;
    stackLLTop = newNode;
    stackLLSize++;
    printf("Value pushed successfully.\n");
}

void slPop() {
    struct StackNode *temp;

    if (stackLLTop == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    temp = stackLLTop;
    printf("Popped value: %d\n", temp->data);
    stackLLTop = stackLLTop->next;
    free(temp);
    stackLLSize--;
}

void slPeek() {
    if (stackLLTop == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top value: %d\n", stackLLTop->data);
}

void slIsEmpty() {
    if (stackLLTop == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

void slIsFull() {
    if (stackLLSize == MAX) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }
}

void slSize() {
    printf("Stack size: %d\n", stackLLSize);
}

void slDisplay() {
    struct StackNode *cur = stackLLTop;

    if (cur == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void slClear() {
    struct StackNode *cur = stackLLTop;
    struct StackNode *next;

    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    stackLLTop = NULL;
    stackLLSize = 0;
    printf("Stack cleared.\n");
}

void slSearchLinear() {
    int value, position = 0, found = 0;
    struct StackNode *cur = stackLLTop;

    if (cur == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (cur != NULL) {
        if (cur->data == value) {
            printf("Value found at position %d (0 = top).\n", position);
            found = 1;
            break;
        }
        cur = cur->next;
        position++;
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void slSearchBinary() {
    int temp[MAX];
    int n = 0, value, low, high, mid, found = 0;
    struct StackNode *cur = stackLLTop;

    if (cur == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    
    while (cur != NULL && n < MAX) {
        temp[n] = cur->data;
        n++;
        cur = cur->next;
    }

    printf("Note: Binary search requires the stack contents to be sorted.\n");
    printf("Enter value to search: ");
    scanf("%d", &value);

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (temp[mid] == value) {
            printf("Value found (position %d from top).\n", mid);
            found = 1;
            break;
        } else if (temp[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void slSearchMenu() {
    int choice;
    while (1) {
        printf("\n---- SEARCH (Linked List Stack) ----\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: slSearchLinear(); break;
            case 2: slSearchBinary(); break;
            case 3: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void queueMenu() {
    int choice;
    while (1) {
        printf("\n----- QUEUE MENU -----\n");
        printf("1. Linear Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Double Ended Queue (Deque)\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: linearQueueMenu(); break;
            case 2: circularQueueMenu(); break;
            case 3: dequeMenu(); break;
            case 4: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void linearQueueMenu() {
    int choice;
    while (1) {
        printf("\n----- LINEAR QUEUE MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. isEmpty\n");
        printf("6. isFull\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: lqEnqueue(); break;
            case 2: lqDequeue(); break;
            case 3: lqFront(); break;
            case 4: lqRear(); break;
            case 5: lqIsEmpty(); break;
            case 6: lqIsFull(); break;
            case 7: lqSize(); break;
            case 8: lqDisplay(); break;
            case 9: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void lqEnqueue() {
    int value;

    if (linRear == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }

    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    if (linFront == -1) {
        linFront = 0;
    }
    linRear++;
    linQueue[linRear] = value;
    printf("Value enqueued successfully.\n");
}

void lqDequeue() {
    if (linFront == -1 || linFront > linRear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Dequeued value: %d\n", linQueue[linFront]);
    linFront++;

    if (linFront > linRear) {
        linFront = -1;
        linRear = -1;
    }
}

void lqFront() {
    if (linFront == -1 || linFront > linRear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front value: %d\n", linQueue[linFront]);
}

void lqRear() {
    if (linRear == -1 || linFront > linRear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Rear value: %d\n", linQueue[linRear]);
}

void lqIsEmpty() {
    if (linFront == -1 || linFront > linRear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

void lqIsFull() {
    if (linRear == MAX - 1) {
        printf("Queue is full.\n");
    } else {
        printf("Queue is not full.\n");
    }
}

void lqSize() {
    if (linFront == -1 || linFront > linRear) {
        printf("Queue size: 0\n");
    } else {
        printf("Queue size: %d\n", linRear - linFront + 1);
    }
}

void lqDisplay() {
    int i;
    if (linFront == -1 || linFront > linRear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (i = linFront; i <= linRear; i++) {
        printf("%d ", linQueue[i]);
    }
    printf("\n");
}

void circularQueueMenu() {
    int choice;
    while (1) {
        printf("\n----- CIRCULAR QUEUE MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. isEmpty\n");
        printf("6. isFull\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: cqEnqueue(); break;
            case 2: cqDequeue(); break;
            case 3: cqFront(); break;
            case 4: cqRear(); break;
            case 5: cqIsEmpty(); break;
            case 6: cqIsFull(); break;
            case 7: cqSize(); break;
            case 8: cqDisplay(); break;
            case 9: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void cqEnqueue() {
    int value;

    if (circCount == MAX) {
        printf("Queue is full.\n");
        return;
    }

    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    if (circCount == 0) {
        circFront = 0;
        circRear = 0;
    } else {
        circRear = (circRear + 1) % MAX;
    }
    circQueue[circRear] = value;
    circCount++;
    printf("Value enqueued successfully.\n");
}

void cqDequeue() {
    if (circCount == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Dequeued value: %d\n", circQueue[circFront]);
    circFront = (circFront + 1) % MAX;
    circCount--;

    if (circCount == 0) {
        circFront = -1;
        circRear = -1;
    }
}

void cqFront() {
    if (circCount == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front value: %d\n", circQueue[circFront]);
}

void cqRear() {
    if (circCount == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Rear value: %d\n", circQueue[circRear]);
}

void cqIsEmpty() {
    if (circCount == 0) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

void cqIsFull() {
    if (circCount == MAX) {
        printf("Queue is full.\n");
    } else {
        printf("Queue is not full.\n");
    }
}

void cqSize() {
    printf("Queue size: %d\n", circCount);
}

void cqDisplay() {
    int i, index;
    if (circCount == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front to rear): ");
    index = circFront;
    for (i = 0; i < circCount; i++) {
        printf("%d ", circQueue[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}

void dequeMenu() {
    int choice;
    while (1) {
        printf("\n----- DEQUE MENU -----\n");
        printf("1. Push Front\n");
        printf("2. Push Rear\n");
        printf("3. Pop Front\n");
        printf("4. Pop Rear\n");
        printf("5. Front\n");
        printf("6. Rear\n");
        printf("7. isEmpty\n");
        printf("8. isFull\n");
        printf("9. Size\n");
        printf("10. Display\n");
        printf("11. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: dqPushFront(); break;
            case 2: dqPushRear(); break;
            case 3: dqPopFront(); break;
            case 4: dqPopRear(); break;
            case 5: dqFront(); break;
            case 6: dqRear(); break;
            case 7: dqIsEmpty(); break;
            case 8: dqIsFull(); break;
            case 9: dqSize(); break;
            case 10: dqDisplay(); break;
            case 11: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void dqPushFront() {
    int value;

    if (dequeCount == MAX) {
        printf("Deque is full.\n");
        return;
    }

    printf("Enter value to push at front: ");
    scanf("%d", &value);

    if (dequeCount == 0) {
        dequeFront = 0;
        dequeRear = 0;
    } else {
        dequeFront = (dequeFront - 1 + MAX) % MAX;
    }
    dequeArr[dequeFront] = value;
    dequeCount++;
    printf("Value pushed at front successfully.\n");
}

void dqPushRear() {
    int value;

    if (dequeCount == MAX) {
        printf("Deque is full.\n");
        return;
    }

    printf("Enter value to push at rear: ");
    scanf("%d", &value);

    if (dequeCount == 0) {
        dequeFront = 0;
        dequeRear = 0;
    } else {
        dequeRear = (dequeRear + 1) % MAX;
    }
    dequeArr[dequeRear] = value;
    dequeCount++;
    printf("Value pushed at rear successfully.\n");
}

void dqPopFront() {
    if (dequeCount == 0) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Popped from front: %d\n", dequeArr[dequeFront]);
    dequeFront = (dequeFront + 1) % MAX;
    dequeCount--;

    if (dequeCount == 0) {
        dequeFront = -1;
        dequeRear = -1;
    }
}

void dqPopRear() {
    if (dequeCount == 0) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Popped from rear: %d\n", dequeArr[dequeRear]);
    dequeRear = (dequeRear - 1 + MAX) % MAX;
    dequeCount--;

    if (dequeCount == 0) {
        dequeFront = -1;
        dequeRear = -1;
    }
}

void dqFront() {
    if (dequeCount == 0) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Front value: %d\n", dequeArr[dequeFront]);
}

void dqRear() {
    if (dequeCount == 0) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Rear value: %d\n", dequeArr[dequeRear]);
}

void dqIsEmpty() {
    if (dequeCount == 0) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque is not empty.\n");
    }
}

void dqIsFull() {
    if (dequeCount == MAX) {
        printf("Deque is full.\n");
    } else {
        printf("Deque is not full.\n");
    }
}

void dqSize() {
    printf("Deque size: %d\n", dequeCount);
}

void dqDisplay() {
    int i, index;
    if (dequeCount == 0) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque (front to rear): ");
    index = dequeFront;
    for (i = 0; i < dequeCount; i++) {
        printf("%d ", dequeArr[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}

void linkedListMenu() {
    int choice;
    while (1) {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Singly Linked List\n");
        printf("2. Circular Linked List\n");
        printf("3. Doubly Linked List\n");
        printf("4. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: singlyLinkedListMenu(); break;
            case 2: circularLinkedListMenu(); break;
            case 3: doublyLinkedListMenu(); break;
            case 4: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void singlyLinkedListMenu() {
    int choice;
    while (1) {
        printf("\n----- SINGLY LINKED LIST MENU -----\n");
        printf("1. Append\n");
        printf("2. Prepend\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Length\n");
        printf("7. Reverse\n");
        printf("8. Display\n");
        printf("9. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: sAppend(); break;
            case 2: sPrepend(); break;
            case 3: sInsert(); break;
            case 4: sDelete(); break;
            case 5: sSearch(); break;
            case 6: sLength(); break;
            case 7: sReverse(); break;
            case 8: sDisplay(); break;
            case 9: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void sAppend() {
    int value;
    struct SNode *newNode, *cur;

    printf("Enter value to append: ");
    scanf("%d", &value);

    newNode = (struct SNode *) malloc(sizeof(struct SNode));
    newNode->data = value;
    newNode->next = NULL;

    if (sHead == NULL) {
        sHead = newNode;
    } else {
        cur = sHead;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    printf("Value appended successfully.\n");
}

void sPrepend() {
    int value;
    struct SNode *newNode;

    printf("Enter value to prepend: ");
    scanf("%d", &value);

    newNode = (struct SNode *) malloc(sizeof(struct SNode));
    newNode->data = value;
    newNode->next = sHead;
    sHead = newNode;
    printf("Value prepended successfully.\n");
}

void sInsert() {
    int value, pos, i;
    struct SNode *newNode, *cur;

    printf("Enter position to insert at (0 = head): ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct SNode *) malloc(sizeof(struct SNode));
    newNode->data = value;

    if (pos == 0 || sHead == NULL) {
        newNode->next = sHead;
        sHead = newNode;
        printf("Value inserted successfully.\n");
        return;
    }

    cur = sHead;
    for (i = 0; i < pos - 1 && cur->next != NULL; i++) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    printf("Value inserted successfully.\n");
}

void sDelete() {
    int value;
    struct SNode *cur, *prev;

    if (sHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (sHead->data == value) {
        cur = sHead;
        sHead = sHead->next;
        free(cur);
        printf("Value deleted successfully.\n");
        return;
    }

    prev = sHead;
    cur = sHead->next;
    while (cur != NULL) {
        if (cur->data == value) {
            prev->next = cur->next;
            free(cur);
            printf("Value deleted successfully.\n");
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Value not found.\n");
}

void sSearch() {
    int value, position = 0, found = 0;
    struct SNode *cur = sHead;

    if (cur == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (cur != NULL) {
        if (cur->data == value) {
            printf("Value found at position %d.\n", position);
            found = 1;
            break;
        }
        cur = cur->next;
        position++;
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void sLength() {
    int count = 0;
    struct SNode *cur = sHead;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    printf("Length of list: %d\n", count);
}

void sReverse() {
    struct SNode *prev = NULL, *cur = sHead, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    sHead = prev;
    printf("List reversed successfully.\n");
}

void sDisplay() {
    struct SNode *cur = sHead;
    if (cur == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Singly Linked List: ");
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void circularLinkedListMenu() {
    int choice;
    while (1) {
        printf("\n----- CIRCULAR LINKED LIST MENU -----\n");
        printf("1. Append\n");
        printf("2. Prepend\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Length\n");
        printf("7. Reverse\n");
        printf("8. Display\n");
        printf("9. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: cAppend(); break;
            case 2: cPrepend(); break;
            case 3: cInsert(); break;
            case 4: cDelete(); break;
            case 5: cSearch(); break;
            case 6: cLength(); break;
            case 7: cReverse(); break;
            case 8: cDisplay(); break;
            case 9: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void cAppend() {
    int value;
    struct CNode *newNode, *cur;

    printf("Enter value to append: ");
    scanf("%d", &value);

    newNode = (struct CNode *) malloc(sizeof(struct CNode));
    newNode->data = value;

    if (cHead == NULL) {
        cHead = newNode;
        newNode->next = cHead;
    } else {
        cur = cHead;
        while (cur->next != cHead) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->next = cHead;
    }
    printf("Value appended successfully.\n");
}

void cPrepend() {
    int value;
    struct CNode *newNode, *cur;

    printf("Enter value to prepend: ");
    scanf("%d", &value);

    newNode = (struct CNode *) malloc(sizeof(struct CNode));
    newNode->data = value;

    if (cHead == NULL) {
        cHead = newNode;
        newNode->next = cHead;
    } else {
        cur = cHead;
        while (cur->next != cHead) {
            cur = cur->next;
        }
        newNode->next = cHead;
        cur->next = newNode;
        cHead = newNode;
    }
    printf("Value prepended successfully.\n");
}

void cInsert() {
    int value, pos, i;
    struct CNode *newNode, *cur;

    printf("Enter position to insert at (0 = head): ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct CNode *) malloc(sizeof(struct CNode));
    newNode->data = value;

    if (pos == 0 || cHead == NULL) {
        if (cHead == NULL) {
            cHead = newNode;
            newNode->next = cHead;
        } else {
            cur = cHead;
            while (cur->next != cHead) {
                cur = cur->next;
            }
            newNode->next = cHead;
            cur->next = newNode;
            cHead = newNode;
        }
        printf("Value inserted successfully.\n");
        return;
    }

    cur = cHead;
    for (i = 0; i < pos - 1 && cur->next != cHead; i++) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    printf("Value inserted successfully.\n");
}

void cDelete() {
    int value;
    struct CNode *cur, *prev;

    if (cHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    
    if (cHead->next == cHead && cHead->data == value) {
        free(cHead);
        cHead = NULL;
        printf("Value deleted successfully.\n");
        return;
    }

    
    if (cHead->data == value) {
        cur = cHead;
        while (cur->next != cHead) {
            cur = cur->next;
        }
        cur->next = cHead->next;
        free(cHead);
        cHead = cur->next;
        printf("Value deleted successfully.\n");
        return;
    }

    prev = cHead;
    cur = cHead->next;
    while (cur != cHead) {
        if (cur->data == value) {
            prev->next = cur->next;
            free(cur);
            printf("Value deleted successfully.\n");
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Value not found.\n");
}

void cSearch() {
    int value, position = 0, found = 0;
    struct CNode *cur = cHead;

    if (cur == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    do {
        if (cur->data == value) {
            printf("Value found at position %d.\n", position);
            found = 1;
            break;
        }
        cur = cur->next;
        position++;
    } while (cur != cHead);

    if (!found) {
        printf("Value not found.\n");
    }
}

void cLength() {
    int count = 0;
    struct CNode *cur = cHead;

    if (cur == NULL) {
        printf("Length of list: 0\n");
        return;
    }

    do {
        count++;
        cur = cur->next;
    } while (cur != cHead);

    printf("Length of list: %d\n", count);
}

void cReverse() {
    struct CNode *prev, *cur, *next, *oldHead;

    if (cHead == NULL || cHead->next == cHead) {
        printf("List reversed successfully.\n");
        return;
    }

    oldHead = cHead;
    prev = cHead;
    cur = cHead->next;

    while (cur != oldHead) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    oldHead->next = prev;
    cHead = prev;
    printf("List reversed successfully.\n");
}

void cDisplay() {
    struct CNode *cur = cHead;

    if (cur == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != cHead);
    printf("(back to head)\n");
}

void doublyLinkedListMenu() {
    int choice;
    while (1) {
        printf("\n----- DOUBLY LINKED LIST MENU -----\n");
        printf("1. Append\n");
        printf("2. Prepend\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Length\n");
        printf("7. Reverse\n");
        printf("8. Display\n");
        printf("9. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: dAppend(); break;
            case 2: dPrepend(); break;
            case 3: dInsert(); break;
            case 4: dDelete(); break;
            case 5: dSearch(); break;
            case 6: dLength(); break;
            case 7: dReverse(); break;
            case 8: dDisplay(); break;
            case 9: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void dAppend() {
    int value;
    struct DNode *newNode, *cur;

    printf("Enter value to append: ");
    scanf("%d", &value);

    newNode = (struct DNode *) malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = NULL;

    if (dHead == NULL) {
        newNode->prev = NULL;
        dHead = newNode;
    } else {
        cur = dHead;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->prev = cur;
    }
    printf("Value appended successfully.\n");
}

void dPrepend() {
    int value;
    struct DNode *newNode;

    printf("Enter value to prepend: ");
    scanf("%d", &value);

    newNode = (struct DNode *) malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dHead;

    if (dHead != NULL) {
        dHead->prev = newNode;
    }
    dHead = newNode;
    printf("Value prepended successfully.\n");
}

void dInsert() {
    int value, pos, i;
    struct DNode *newNode, *cur;

    printf("Enter position to insert at (0 = head): ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode = (struct DNode *) malloc(sizeof(struct DNode));
    newNode->data = value;

    if (pos == 0 || dHead == NULL) {
        newNode->prev = NULL;
        newNode->next = dHead;
        if (dHead != NULL) {
            dHead->prev = newNode;
        }
        dHead = newNode;
        printf("Value inserted successfully.\n");
        return;
    }

    cur = dHead;
    for (i = 0; i < pos - 1 && cur->next != NULL; i++) {
        cur = cur->next;
    }

    newNode->next = cur->next;
    newNode->prev = cur;
    if (cur->next != NULL) {
        cur->next->prev = newNode;
    }
    cur->next = newNode;
    printf("Value inserted successfully.\n");
}

void dDelete() {
    int value;
    struct DNode *cur;

    if (dHead == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    cur = dHead;
    while (cur != NULL) {
        if (cur->data == value) {
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            } else {
                dHead = cur->next;
            }
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            free(cur);
            printf("Value deleted successfully.\n");
            return;
        }
        cur = cur->next;
    }
    printf("Value not found.\n");
}

void dSearch() {
    int value, position = 0, found = 0;
    struct DNode *cur = dHead;

    if (cur == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (cur != NULL) {
        if (cur->data == value) {
            printf("Value found at position %d.\n", position);
            found = 1;
            break;
        }
        cur = cur->next;
        position++;
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void dLength() {
    int count = 0;
    struct DNode *cur = dHead;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    printf("Length of list: %d\n", count);
}

void dReverse() {
    struct DNode *cur = dHead;
    struct DNode *temp = NULL;

    while (cur != NULL) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if (temp != NULL) {
        dHead = temp->prev;
    }
    printf("List reversed successfully.\n");
}

void dDisplay() {
    struct DNode *cur = dHead;
    if (cur == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: NULL <-> ");
    while (cur != NULL) {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void sortMenu() {
    int choice;
    while (1) {
        printf("\n----- SORT MENU -----\n");
        printf("1. Enter Values\n");
        printf("2. Bubble Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Heap Sort\n");
        printf("8. Back\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { if (feof(stdin)) { printf("\nInput ended. Exiting program.\n"); exit(0); } clearInputBuffer(); continue; }

        switch (choice) {
            case 1: sortEnterValues(); break;
            case 2: bubbleSort(); break;
            case 3: selectionSort(); break;
            case 4: insertionSort(); break;
            case 5:
                if (sortSize == 0) {
                    printf("Please enter values first.\n");
                } else {
                    mergeSort(sortArr, 0, sortSize - 1);
                    printf("Array sorted using Merge Sort.\n");
                    printSortArr();
                }
                break;
            case 6:
                if (sortSize == 0) {
                    printf("Please enter values first.\n");
                } else {
                    quickSort(sortArr, 0, sortSize - 1);
                    printf("Array sorted using Quick Sort.\n");
                    printSortArr();
                }
                break;
            case 7: heapSort(); break;
            case 8: return;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}

void sortEnterValues() {
    int n, i;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size.\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &sortArr[i]);
    }

    sortSize = n;
    printf("Values entered successfully.\n");
}

void printSortArr() {
    int i;
    printf("Sorted Array: ");
    for (i = 0; i < sortSize; i++) {
        printf("%d ", sortArr[i]);
    }
    printf("\n");
}

void bubbleSort() {
    int i, j, temp;

    if (sortSize == 0) {
        printf("Please enter values first.\n");
        return;
    }

    for (i = 0; i < sortSize - 1; i++) {
        for (j = 0; j < sortSize - i - 1; j++) {
            if (sortArr[j] > sortArr[j + 1]) {
                temp = sortArr[j];
                sortArr[j] = sortArr[j + 1];
                sortArr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted using Bubble Sort.\n");
    printSortArr();
}

void selectionSort() {
    int i, j, minIndex, temp;

    if (sortSize == 0) {
        printf("Please enter values first.\n");
        return;
    }

    for (i = 0; i < sortSize - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < sortSize; j++) {
            if (sortArr[j] < sortArr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = sortArr[i];
            sortArr[i] = sortArr[minIndex];
            sortArr[minIndex] = temp;
        }
    }
    printf("Array sorted using Selection Sort.\n");
    printSortArr();
}

void insertionSort() {
    int i, j, key;

    if (sortSize == 0) {
        printf("Please enter values first.\n");
        return;
    }

    for (i = 1; i < sortSize; i++) {
        key = sortArr[i];
        j = i - 1;
        while (j >= 0 && sortArr[j] > key) {
            sortArr[j + 1] = sortArr[j];
            j--;
        }
        sortArr[j + 1] = key;
    }
    printf("Array sorted using Insertion Sort.\n");
    printSortArr();
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[MAX], right[MAX];

    for (i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    int j, temp;

    for (j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void quickSort(int arr[], int l, int r) {
    int p;
    if (l < r) {
        p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort() {
    int i, temp;

    if (sortSize == 0) {
        printf("Please enter values first.\n");
        return;
    }

    for (i = sortSize / 2 - 1; i >= 0; i--) {
        heapify(sortArr, sortSize, i);
    }

    for (i = sortSize - 1; i > 0; i--) {
        temp = sortArr[0];
        sortArr[0] = sortArr[i];
        sortArr[i] = temp;
        heapify(sortArr, i, 0);
    }

    printf("Array sorted using Heap Sort.\n");
    printSortArr();
}
