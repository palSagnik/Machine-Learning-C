#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//training set 
float trainSet [][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}
};
#define trainSetCount (sizeof(trainSet)/sizeof(trainSet[0]))

float randomFloat (size_t seed)
{
    srand(seed);
    return (float) rand() / (float) RAND_MAX;
}

float costFunction (float w, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < trainSetCount; i++)
    {
        float x = trainSet[i][0];
        float y = x*w + b;
        float err = y - trainSet[i][1];
        result = result + err*err;    
    }
    result /= trainSetCount;
    return result;
}

void gradientDescent (float w, float b, size_t iters, float eps, float learnRate)
{
    for (size_t i = 0; i < iters; i++)
    {
        float dw = (costFunction(w + eps, b) - costFunction(w, b))/eps;
        float db = (costFunction(w, b + eps) - costFunction(w, b))/eps;
        w -= learnRate*dw;
        b -= learnRate*db;

        printf("Cost: %f, w: %f, b: %f\n", costFunction(w, b), w, b);
    }
    printf("---------------------------\n");
    printf("Final w: %f Final b: %f\n", w, b);

}

int main()
{   
    //parameters for gradient descent
    float w = randomFloat(100000) * 10.0f;
    float b = randomFloat(100000) * 5.0f;
    float eps = 1e-3;
    float rate = 1e-3;
    float iters = 15000;

    gradientDescent(w, b, iters, eps, rate);
    return 0;
}
