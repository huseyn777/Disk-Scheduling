#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

 int main(int argc, char *argv[])
 {
        int number_of_requests = 1000;
        int requests [number_of_requests];
        int i = 0;
        int choice = 2;
        //FILE *fileOut = fopen("test.txt", "w");

        if(argc == 3)
        {
            int num = 0;
            FILE *file = fopen (argv[2], "r");
            fscanf (file, "%d", &num);
            fscanf (file, "%d", &num);
            while (!feof (file))
            {
                requests[i] = num;
                fscanf (file, "%d", &num);
                fscanf (file, "%d", &num);
                i++;
            }
            requests[i] = num;
        }


        else
        {
            srand(time(0));
            for(i = 0; i < number_of_requests; i++)
            {
                requests [i] = rand() % 5000;
                //fprintf(fileOut, "%d ", i+1);
                //fprintf(fileOut, "%d\n", requests [i]);
            }
        }


// FCFS
        int headPos = atoi(argv[1]);
        int totalMovment = 0;

        for(i = 0; i < number_of_requests; i++)
        {
              totalMovment = totalMovment + abs(headPos - requests [i]);
              headPos = requests [i];
        }

        printf("FCFS: %d\n",totalMovment);

//SSTF
        headPos = atoi(argv[1]);
        totalMovment = 0;

        int distance [number_of_requests];
        int shortest = 5000;
        int j;
        int victim;

        int accesPermit [number_of_requests];
        for(i = 0; i < number_of_requests; i++)
        {
            accesPermit[i] = 1;
        }


        for(i = 0; i < number_of_requests; i++)
        {
            for(j = 0; j < number_of_requests; j++)
            {
                if(accesPermit[j] == 1)
                    distance [j] = abs(headPos - requests [j]);
            }

            for(j = 0; j < number_of_requests; j++)
            {
                if(distance[j] < shortest && accesPermit[j] == 1)
                {
                    shortest = distance[j];
                    victim = j;
                }
            }
            headPos = requests [victim];
            accesPermit[victim] = 0;
            totalMovment = totalMovment + shortest;
            shortest = 5000;
        }

        printf("SSTF: %d\n",totalMovment);

//SCAN
        headPos = atoi(argv[1]);
        totalMovment = 0;
	int temp = headPos - 1;


        for(i = headPos; i < 5000; i++)
        {

            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }
        totalMovment = totalMovment + (4999-headPos);
        headPos = 4999;
        for(i = temp; i >= 0; i--)
        {
            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }

         printf("SCAN: %d\n",totalMovment);

//C-SCAN
        headPos = atoi(argv[1]);
        totalMovment = 0;
	temp = headPos;

        for(i = headPos; i < 5000; i++)
        {

            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }
        totalMovment = totalMovment + (4999-headPos);
        totalMovment = totalMovment + 4999;
        headPos = 0;
        for(i = headPos; i < temp; i++)
        {
            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }

         printf("C-SCAN: %d\n",totalMovment);

//Look
        headPos = atoi(argv[1]);
        totalMovment = 0;
	temp = headPos - 1;


        for(i = headPos; i < 5000; i++)
        {

            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }

        for(i = temp; i >= 0; i--)
        {
            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }

         printf("LOOK: %d\n",totalMovment);

//C-Look
        headPos = atoi(argv[1]);
        totalMovment = 0;
	temp = headPos;


        for(i = headPos; i < 5000; i++)
        {

            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }

        for(i = 0; i < temp; i++)
        {
            for(j = 0; j < number_of_requests; j++)
            {
                if(i == requests [j])
                {
                    totalMovment = totalMovment + abs(headPos - requests [j]);
                    headPos = requests [j];
                }
            }
        }

         printf("C-LOOK: %d\n",totalMovment);
	 return 0;
 }
