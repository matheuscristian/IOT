#include <stdio.h>
#include <stdlib.h>

struct queue {
    int *arr;
    int _s, _i;
};

int front(struct queue *q) {
    return q->arr[0];
}

void push(struct queue *q, int x) {
    if (q->_s - q->_i < 3) {
        int temp_arr[q->_s];
        for (int i = 0; i < q->_i; i++) {
            temp_arr[i] = q->arr[i];
        }

        free(q->arr);

        q->_s += 10;
        q->arr = (int*)malloc(sizeof(int) * (q->_s));

        for (int i = 0; i < q->_i; i++) {
            q->arr[i] = temp_arr[i];
        }
    }

    q->arr[q->_i++] = x;
}

void pop(struct queue *q) {
    if (q->_i > 0) {
        for (int i = 0; i < q->_i - 1; i++) {
            q->arr[i] = q->arr[i + 1];
        }
        q->_i--;
    }
}

struct queue create_queue() {
    struct queue q;
    q._i = 0;
    q._s = 10;

    q.arr = (int *)malloc(sizeof(int) * q._s);

    return q;
}

int main() {
    struct queue q = create_queue();

    push(&q, 3);
    push(&q, 10);

    pop(&q);

    printf("%d\n", front(&q));

    return 0;
}