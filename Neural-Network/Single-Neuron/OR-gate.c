#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// c math naming
// using it for our activation function
float sigmoidf(float x)
{
    return 1.f / (1.f + expf(-x));
}

// OR-gate
float trainSet[][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 1},
};

#define trainSetCount (sizeof(trainSet) / sizeof(trainSet[0]))

float randomFloat(size_t seed)
{
    srand(seed);
    return (float)rand() / (float)RAND_MAX;
}

float costFunction(float w1, float w2, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < trainSetCount; i++)
    {
        float x1 = trainSet[i][0];
        float x2 = trainSet[i][1];

        // applying activation function
        float y   = sigmoidf(x1 * w1 + x2 * w2 + b);
        float err = y - trainSet[i][2];
        result    = result + err * err;
    }
    result /= trainSetCount;
    return result;
}

void finiteDifference(float w1, float w2, float b, float eps, float learnRate, size_t iters)
{
    for (size_t i = 0; i < iters; i++)
    {
        float dw1 = (costFunction(w1 + eps, w2, b) - costFunction(w1, w2, b)) / eps;
        float dw2 = (costFunction(w1, w2 + eps, b) - costFunction(w1, w2, b)) / eps;
        float db  = (costFunction(w1, w2, b + eps) - costFunction(w1, w2, b)) / eps;

        b  -= learnRate * db;
        w1 -= learnRate * dw1;
        w2 -= learnRate * dw2;

        printf("Cost: %f, w: %f, w2: %f\n", costFunction(w1, w2, b), w1, w2);
    }
    printf("---------------------------\n");
    printf("Final w: %f Final w2: %f Final b: %f\n", w1, w2, b);
}

int main(void)
{
    float w1 = randomFloat(10000) * 10.0f;
    float w2 = randomFloat(20000) * 10.0f;
    float b = randomFloat(30000) * 5.0f;
    float eps = 1e-3;
    float rate = 1e-1;
    float iters = 15000;

    finiteDifference(w1, w2, b, eps, rate, iters);
    return 0;
}
