#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//AND-gate 
float trainSet [][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1},
    };

#define trainSetCount (sizeof(trainSet)/sizeof(trainSet[0]))

float randomFloat (size_t seed)
{
    srand(seed);
    return (float) rand() / (float) RAND_MAX;
}

float costFunction (float w1, float w2)
{
    float result = 0.0f;
    for (size_t i = 0; i < trainSetCount; i++)
    {
        float x1 = trainSet[i][0];
        float x2 = trainSet[i][1];
        float y = x1*w1 + x2*w2;
        float err = y - trainSet[i][2];
        result = result + err*err;    
    }
    result /= trainSetCount;
    return result;
}

void finiteDifference (float w1, float w2, float eps, float learnRate, size_t iters)
{
    for (size_t i = 0; i < iters; i++)
    {
        float dw1 = (costFunction(w1 + eps, w2) - costFunction(w1, w2))/eps;
        float dw2 = (costFunction(w1, w2 + eps) - costFunction(w1, w2))/eps;
        w1 -= learnRate*dw1;
        w2 -= learnRate*dw2;

        printf("Cost: %f, w: %f, w2: %f\n", costFunction(w1, w2), w1, w2);
    }
    printf("---------------------------\n");
    printf("Final w: %f Final w2: %f\n", w1, w2);

}

int main (void)
{
    float w1 = randomFloat(10000) * 10.0f;
    float w2 = randomFloat(20000) * 10.0f;

    float eps = 1e-3;
    float rate = 1e-3;
    float iters = 6000;

    finiteDifference(w1, w2, eps, rate, iters);
    return 0;
}
