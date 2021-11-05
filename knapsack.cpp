#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j;
    int popSize = 50, chromLen = 10;
    int profit[] = {1, 2, 5, 6, 4, 2, 6, 8, 9, 3}, weight[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, capacity = 15; // For 0/1 Knapsack Problem
    int fitness[popSize], maxFit = 0, maxFitNum = -1;
    int population[popSize][chromLen], parent[popSize][chromLen], offspring[popSize][chromLen]; // popSize
    int pc = 0.7, pm = (1 / chromLen);                                                          // Crossover Probability is 70%
    int generation = 0, termination = 5;                                                        // Termination at 50th Generation
    int x1, x2;

    // Initialization
    for (i = 0; i < popSize; i++)
    {
        for (j = 0; j < chromLen; j++)
        {
            if (rand() % (1 + 1) > 0)
            {
                population[i][j] = 1; // Gene set to 1
            }
            else
                population[i][j] = 0; // Gene set to 0
        }
    }

    for (generation = 0; generation < termination; generation++)
    {
        // Fitness Calculation
        for (i = 0; i < popSize; i++)
        {
            for (j = 0; j < chromLen; j++)
            {
                fitness[i] += population[i][j] * profit[j]; // Gene set to 1
            }
            if (fitness[i] > maxFit)
            {
                maxFit = fitness[i];
                maxFitNum = i;
            }
        }

        //Termination
        generation++;
        if (maxFit == capacity)
        {
            printf("Genration: %d, Chromosome: ", generation);
            for (j = 0; j < chromLen; j++)
            {
                printf("%d", population[maxFitNum][j]);
            }
            return 0;
        }

        // parent Selection
        for (i = 0; i < popSize; i++)
        {
            x1 = rand() % (popSize + 1);
            do
            {
                x2 = rand() % (popSize + 1);
            } while (x2 == x1);

            if (fitness[x1] > fitness[x2])
            {
                for (j = 0; j < chromLen; j++)
                {
                    parent[i][j] = population[x1][j];
                }
            }
            else
            {
                for (j = 0; j < chromLen; j++)
                {
                    parent[i][j] = population[x2][j];
                }
            }
            printf("\n %d ", i);
            for (j = 0; j < chromLen; j++)
            {
                printf("%d ", parent[1][j]);
            }
        }

        // Crossover
        for (i = 0; i < popSize; i += 2)
        {
            if (rand() % (10 + 1) < 10 * pc)
            {
                i = rand() % (chromLen + 1); // Crossover Point
                for (j <= 0; j < i; j++)     // Before Crossover Point
                {
                    offspring[i][j] = parent[i][j];
                    offspring[i + 1][j] = parent[i + 1][j];
                }
                for (j = i; j < chromLen; j++) // After Crossover Point
                {
                    offspring[i][j] = parent[i + 1][j];
                    offspring[i + 1][j] = parent[i][j];
                }
            }
        }

        // Mutation
        for (i = 0; i < popSize; i++)
        {
            for (j = 0; j < chromLen; j++)
            {
                if (rand() % (chromLen + 1) < 1)
                {
                    offspring[i][j] = (offspring[i][j] + 1) % 2;
                }
            }
        }

        // Survival Selection
        for (i = 0; i < popSize; i++)
        {
            for (j = 0; j < chromLen; j++)
            {
                population[i][j] = offspring[i][j]; //Since Generational Survival selection (replace all)
            }
        }
    }

    printf("Genration: %d, Chromosome: ", generation);
    for (j = 0; j < chromLen; j++)
    {
        printf("%d ", population[maxFitNum][j]);
    }
    return 0;
}