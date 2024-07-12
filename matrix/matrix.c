#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/random.h"

typedef struct {
    int size;
    double* nums;
} Vector;

Vector* initVector(int size, double* values) {
    Vector* v = malloc(sizeof(Vector));
    v->size = size;
    v->nums = malloc(v->size * sizeof(int));

    for (int i = 0; i < v->size; i++) {
        v->nums[i] = values[i];
    }
    return v;
}

Vector* initRandomVector(int size) {
    Vector* v = malloc(sizeof(Vector));
    v->size = size;
    v->nums = malloc(v->size * sizeof(double));

    for (int i = 0; i < v->size; i++) {
        v->nums[i] = randomDouble();
    }
    return v;
}

void printVector(Vector* v) { 
    for (int i = 0; i < v->size; i++) {
        printf("%f ",v->nums[i]);
    }
    printf("\n");
}

double dotProduct(Vector* v1, Vector* v2) {
    double res = 0;
    if (v1->size != v2->size) { 
        exit(-1);
    }
    for (int i = 0; i < v1->size; i++) {
        res += (v1->nums[i] * v2->nums[i]);
    }
    return res;
}

int main() {
    srand(time(0));
    int vecSize = 5;
    Vector* v1 = initRandomVector(vecSize);
    Vector* v2 = initRandomVector(vecSize);
    printVector(v1);
    printf("Dot Product -> %f\n",dotProduct(v1,v2));
    return 0;
}