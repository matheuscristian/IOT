#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *arr;
    int _s, _i;
};

int top(struct stack *s) {
    return s->arr[s->_i];
}

void push(struct stack *s, int x) {
    if (s->_s - s->_i < 3) {
        int temp_arr[s->_s];
        for (int i = 0; i < s->_i; i++) {
            temp_arr[i] = s->arr[i];
        }

        free(s->arr);

        s->_s += 10;
        s->arr = (int*)malloc(sizeof(int) * (s->_s));

        for (int i = 0; i < s->_i; i++) {
            s->arr[i] = temp_arr[i];
        }
    }

    s->arr[++s->_i] = x;
}

void pop(struct stack *s) {
    if (s->_i > 0) {
        s->_i--;
    }
}

struct stack create_stack() {
    struct stack s;
    s._i = 0;
    s._s = 10;

    s.arr = (int *)malloc(sizeof(int) * s._s);

    return s;
}

int main() {
    struct stack s = create_stack();

    push(&s, 3);
    push(&s, 10);

    printf("%d\n", top(&s));

    return 0;
}
