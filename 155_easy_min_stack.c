// To be fair, I looked at the discussions and saw this in Python. It makes
// a ton of sense -- the min element must be / come before the current element
// in the stack, so why not cache it?

typedef struct { int min; int val; } MSEntry;
typedef struct { MSEntry stack[10000]; int top; } MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *newMS = (MinStack *) malloc(sizeof(MinStack));
    *newMS = (MinStack) { .top = -1 };
    return newMS;
}

void minStackPush(MinStack* obj, int x) {
    obj->stack[++obj->top] = (MSEntry) {
        .min = !obj->top || x < obj->stack[obj->top-1].min ? x : obj->stack[obj->top-1].min,
        .val = x };
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->stack[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
