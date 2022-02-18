#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
//#include <visualiser.c>

void plot(char* f){
}

void outputCSV(size_t N, int arr[N][N], char webArray[N][1024])
{
    FILE *fp;
    fp = fopen("output.csv", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, ",%s", webArray[i]);
    }

    fprintf(fp, "\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%s", webArray[i]);
        for (int j = 0; j < N; j++)
        {
            fprintf(fp, ",%d", webArray[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    plot("output.csv");
}

void print2d(size_t N, int arr[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int isReflexive(size_t N, int arr[N][N])
{
    for(int i = 0; i < N; i++)
    {
        if (arr[i][i] != 1)
            return 0;
    }

    return 1;
}

int isTransitive(size_t N,int arr[N][N]){
    int arr1[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr1[i][j] = arr[i][j];
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr1[i][j] = arr1[i][j] || ((arr1[i][k] && arr1[k][j]));
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(arr1[i][j] != arr[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

void printTransitiveClosure(size_t N, int arr[N][N], char webArray[N][1024])
{
    int arr1[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr1[i][j] = arr[i][j];
        }
    }
 
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr1[i][j] = arr1[i][j] || ((arr1[i][k] && arr1[k][j]));
            }
        }
    }
 
    FILE *fp;
    fp = fopen("output.csv", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, ",%s", webArray[i]);
    }

    fprintf(fp, "\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%s", webArray[i]);
        for (int j = 0; j < N; j++)
        {
            fprintf(fp, ",%d", arr1[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    plot("output.csv");
    print2d(N, arr1);
}
 
void printReflexiveClosure(size_t N, int arr[N][N], char webArray[N][1024])
{
    int arr1[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr1[i][j] = ((i==j) ? 1 : arr[i][j]);
        }
    }
 
    FILE *fp;
    fp = fopen("output.csv", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, ",%s", webArray[i]);
    }

    fprintf(fp, "\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%s", webArray[i]);
        for (int j = 0; j < N; j++)
        {
            fprintf(fp, ",%d", arr1[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    plot("output.csv");
    print2d(N, arr1);
}
 
void printSymmetricClosure(size_t N, int arr[N][N], char webArray[N][1024])
{
    int arr1[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr1[i][j] = (arr[i][j] || arr[j][i]) ? 1 : 0;
        }
    }
 
    FILE *fp;
    fp = fopen("output.csv", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, ",%s", webArray[i]);
    }

    fprintf(fp, "\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%s", webArray[i]);
        for (int j = 0; j < N; j++)
        {
            fprintf(fp, ",%d", arr1[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    plot("output.csv");
    print2d(N, arr1);
}

int isSymmetric(size_t N, int arr[N][N])
{
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == arr[j][i])
                counter++;
        }
    }
    if (counter == N * N)
    {
        return 1;
    }
    return 0;
}

int isAntiSymmetric(size_t N, int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1 && arr[j][i] == 1 && i != j)
                return 0;
        }
    }
    return 1;
}

void printClasses(size_t N, int arr[N][N])
{
    int elements[N];
    for (int i = 0; i < N; i++)
    {
        elements[i] = 0;
    }
        
    for (int i = 0; i < N; i++)
    {
        if(elements[i] !=0 )
            continue;
        for (int j = 0; j < N; j++)
        {
            printf("Partition : \n");
            elements[i] = 1;
            if(arr[i][j] == 1)
            {
                elements[j] = 1;
                printf("%d ", j);
            }
            printf("%d\n", i);
        }
    }
}

void printHasseDiagram(size_t N, int arr[N][N], char webArray[N][1024])
{
    int arr1[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr1[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        arr1[i][i] = 0;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(arr1[i][j] == 1){
                for (int k = 0; k < N; k++){
                    if(arr1[j][k] == 1){
                        arr1[i][k] = 0;
                    }
                }
            }
        }
    }

    FILE *fp;
    fp = fopen("output.csv", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, ",%s", webArray[i]);
    }

    fprintf(fp, "\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%s", webArray[i]);
        for (int j = 0; j < N; j++)
        {
            fprintf(fp, ",%d", arr1[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    plot("output.csv");

    print2d(N, arr1);
}

void printEquivalence(size_t N, int arr[N][N], char webArray[N][1024])
{
    int arr1[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j)
                arr1[i][j] = 1;
            else if(arr[i][j] == 1 || arr[j][i] == 1)
                arr1[i][j] = 1;
            else
                arr1[i][j] = arr[i][j];
        }
    }
    
    int arr2[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr2[i][j] = arr1[i][j];
        }
    }
 
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr2[i][j] = arr2[i][j] || ((arr2[i][k] && arr2[k][j]));
            }
        }
    }
 
    FILE *fp;
    fp = fopen("output.csv", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, ",%s", webArray[i]);
    }

    fprintf(fp, "\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%s", webArray[i]);
        for (int j = 0; j < N; j++)
        {
            fprintf(fp, ",%d", arr2[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    plot("output.csv");
    print2d(N, arr2);
}

//returns -1 if does not exist, otherwise returns the index of the element
int greatestLowerBound(size_t N, int arr[N][N], int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i][x] == 1 && arr[i][y] == 1)
            count++;
    }
    int lowerBounds[count];
 
    for (int i = 0; i < count; i++)
    {
        lowerBounds[i] = 0;
    }
    int z = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i][x] == 1 && arr[i][y] == 1)
            lowerBounds[z++] = i;
    }
    for (int i = 0; i < count; i++)
    {
        int found = 1;
        for (int j = 0; j < count; j++)
        {
            if (arr[lowerBounds[j]][lowerBounds[i]] == 0 && i != j)
            {
                found = 0;
                break;
            }
        }
        if (found == 1)
            return lowerBounds[i];
    }
    return -1;
}
 
//returns -1 if does not exist, otherwise returns the index of the element
int lowestUpperBound(size_t N, int arr[N][N], int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[x][i] == 1 && arr[y][i] == 1)
            count++;
    }
 
    int upperBounds[count];
    for (int i = 0; i < count; i++)
    {
 
        upperBounds[i] = 0;
    }
 
    int z = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[x][i] == 1 && arr[y][i] == 1)
            upperBounds[z++] = i;
    }
 
    for (int i = 0; i < count; i++)
    {
        int found = 1;
        for (int j = 0; j < count; j++)
        {
            if (arr[upperBounds[i]][upperBounds[j]] == 0 && i != j)
            {
                found = 0;
                break;
            }
        }
        if (found == 1)
            return upperBounds[i];
    }
    return -1;
}
 
int isLattice(size_t N, int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (greatestLowerBound(N, arr, i, j) == -1 || lowestUpperBound(N, arr, i, j) == -1)
            {
                return 0;
            }
        }
    }
 
    return 1;
}
 
int isDistributive(size_t N, int arr[N][N])
{
    int lubs[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            lubs[i][j] = lowestUpperBound(N, arr, i, j);
        }
    }
 
    int glbs[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            glbs[i][j] = greatestLowerBound(N, arr, i, j);
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                int lhs1 = lubs[i][glbs[j][k]];
                int rhs1 = glbs[lubs[i][j]][lubs[i][k]];
 
                int lhs2 = glbs[i][lubs[j][k]];
                int rhs2 = lubs[glbs[i][j]][glbs[i][k]];
 
                if (lhs1 != rhs1 || lhs2 != rhs2)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void menu4case6(size_t N, char webArray[N][1024], int arr[N][N])
{
    int x;
    printf("Enter number of inputs : ");
    scanf("%d", &x);
    int userInputs6[x];
    printf("Enter index number of the website : \n");
    for (int i = 0; i < x; i++)
    {
        int index;
        scanf("%d", &index);
        userInputs6[i] = index;
    }

    printf("Reachable : \n");
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        int exists = 1;
        for (int j = 0; j < x; j++)
        {
            if (arr[userInputs6[j]][i] == 0)
                exists = 0;
        }
        if (exists == 1)
        {
            c = 1;
            printf("%d\n",i);
        }
    }
    if (c == 0)
    printf("Doesn't exist\n");
}


void menu4case7(size_t N, char webArray[N][1024], int arr[N][N])
{
    int y;
    printf("Enter number of inputs : ");
    scanf("%d", &y);
    int userInputs7[y];
    printf("Enter index number of the website : \n");
    for (int i = 0; i < y; i++)
    {
        int index;
        scanf("%d", &index);
        userInputs7[i] = index;
    }

    printf("Reachable : \n");
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        int exists = 1;
        for (int j = 0; j < y; j++)
        {
            if (arr[i][userInputs7[j]] == 0)
                exists = 0;
        }
        if (exists == 1)
        {
            c = 1;
            printf("%d\n",i);
        }
    }
    if (c == 0)
    printf("Doesn't exist\n");
}

int main()
{
    char buffer[1024];

    char *record, *line, *cell;
    FILE *filePointer = fopen("test.csv", "r");

    if (filePointer == NULL)
    {
        printf("\n file opening failed ");
        return -1;
    }

    char *firstLine;
    firstLine = fgets(buffer, sizeof(buffer), filePointer);

    int numberOfWebs = 0;
    int i, j = 0;
    while (firstLine[i] != '\0')
    {
        if (firstLine[i] == ',')
            numberOfWebs++;
        i++;
    }

    char *websiteNames = strtok(firstLine, ",");

    char webArray[numberOfWebs][1024]; //compile with -std-gnu99 flag
    int relation[numberOfWebs][numberOfWebs];

    i = 0;
    while (websiteNames != NULL)
    {
        strcpy(webArray[i], websiteNames);
        websiteNames = strtok(NULL, ",");
        i++;
    }

    // for (int j = 0; j < numberOfWebs; j++){
    //     printf("%s\n", webArray[j]);
    // } access website Names

    i = 0, j = 0;

    while ((line = fgets(buffer, sizeof(buffer), filePointer)) != NULL)
    {
        record = strtok(line, "\n");
        while (record != NULL)
        {
            char *temp;
            for (temp = record; *temp != '\0'; temp++)
            {
                if (*temp == ',')
                {
                    temp++;
                    relation[i][j++] = ((*temp) - '0');
                }
            }
            record = strtok(NULL, "\n");
            j = 0;
        }
        ++i;
    }

    int length = strlen(webArray[numberOfWebs - 1]);
    webArray[numberOfWebs-1][length-1] = 0;

    printf("The input relation is : \n");
    print2d(numberOfWebs, relation);
    printf("\n");
   
    const char *mainMenu[9];
    mainMenu[0] = "1. Does every website has a link to itself?";                                                    //check matrix diag
    mainMenu[1] = "2. Is it possible to return back to the previous website from the current website in one step?"; // ** rel(prev, curr)
    mainMenu[2] = "3. Does every website have all the links to the websites which are reachable from it?";          // check transitivity
    mainMenu[3] = "4. Does there exist any website that contains a link to itself?";                                // if any diag element is 1
    mainMenu[4] = "5. Is it impossible to return to the previous website from the current website in one step?";
    mainMenu[5] = "6. Is it impossible to return to the previous website from the current website in one step? (excluding the cases where the current and previous website name is same)";
    mainMenu[6] = "7. Is it possible to divide the network into multiple pieces such that every website in a piece is reachable from every other website in that piece?"; //equivalence class
    mainMenu[7] = "8. Is this relation an example of a poset?";
    mainMenu[8] = "9. Exit";

    const char *menu2[1];
    menu2[0] = "1. Do you want to visualize how the network will look if we add minimum links to satisfy the property ? (If yes, display the graph else return back to Main Menu)";

    const char *menu3[1];
    menu3[0] = "1. Do you want to know the nodes in each piece? (List all the pieces and their corresponding websites else return to Main Menu)";

    const char *menu4[9];
    menu4[0] = "1. Display the Hasse diagram.";
    menu4[1] = "2. Display the website whose link is available in every website.";
    menu4[2] = "3. Display the website which has links of every website";
    menu4[3] = "4. Display the websites that do not have links to any other website except itself.";
    menu4[4] = "5. Display the websites that can’t be reached from any other website except itself.";
    menu4[5] = "6. Given some websites, display the websites which are reachable from all of them.(Take input from user and display result)";
    menu4[6] = "7. Given some websites, display the websites from which you can reach all those websites.(Process similar to 5)";
    menu4[7] = "8. Is this relation an example of lattice ?";
    menu4[8] = "9. Return to Main Menu.";

    const char *menu5[4];
    menu5[0] = "1. Given two websites A and B display the website which is reachable by both A and B and can also reach to all such websites that A and B can reach.";
    menu5[1] = "2. Given two websites A and B display the website which is reachable by both A and B and is also reachable from all such websites which can reach to both A and B.";
    menu5[2] = "3. Is the lattice distributive?";
    menu5[3] = "4. Return to Menu 4.";

  

    while (true)
    {  printf("Main Menu\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%s \n", mainMenu[i]);
    }
        printf("\nSelect option number\n");
        int opt;
        scanf("%d", &opt);
        switch (opt)
        {

        case 1:
            if (isReflexive(numberOfWebs, relation))
                printf("Yes");
            else
            {
                printf("No\n");
                printf("%s\n", menu2[0]);
                int inp;
                scanf("%d", &inp);
                if (inp == 1)
                {
                    printReflexiveClosure(numberOfWebs, relation, webArray);
                }
            }
            break;

        case 2:
            if (isSymmetric(numberOfWebs, relation))
                printf("Yes");
            else
            {
                printf("No\n");
                printf("%s\n", menu2[0]);
                printf("Enter 1 if yes else enter 0\n");
                int inp;
                scanf("%d", &inp);
                if (inp == 1)
                {
                    printSymmetricClosure(numberOfWebs, relation, webArray);
                }
            }
            break;

        case 3:
            if (isTransitive(numberOfWebs, relation))
                printf("Yes");
            else
            {    printf("No\n");
                printf("%s\n", menu2[0]);
                printf("Enter 1 if yes else enter 0\n");
                int inp;
                scanf("%d", &inp);
                if (inp == 1)
                {
                    printTransitiveClosure(numberOfWebs, relation, webArray);
                }
            }
            break;

        case 4:
            for (int i = 0; i < numberOfWebs; i++)
            {

                if (relation[i][i] == 1)
                {
                    printf("Yes");
                    break;
                }
            }
            break;

        case 5:
            if (isAntiSymmetric(numberOfWebs, relation) == 1){
                int countReflexive = 0;
                for (int i = 0; i < numberOfWebs; i++)
                {
                    if(relation[i][i] == 1){
                        countReflexive++;
                    }
                }
                if(countReflexive > 0){
                    printf("No");
                }else{
                    printf("Yes");
                }
            }
            else
            {
                printf("No\n");
            }
            break;

        case 6:
            if (isAntiSymmetric(numberOfWebs, relation) == 1){
                printf("Yes\n");
            }   
            else
            {
                printf("No\n");
            }
            break;

        case 7:
            if (isSymmetric(numberOfWebs, relation) && isTransitive(numberOfWebs, relation) && isReflexive(numberOfWebs, relation)){
                printf("Yes\n");
                printf("\nMENU 3\n%s\n(Enter 1 if yes else enter 0)\n", menu3[0]);
                int inp;
                scanf("%d", &inp);
                if (inp == 1)
                {
                   printClasses(numberOfWebs,relation);
                }
            } 
            else
            {
                printf("No\n");
                printf("\nMENU 2\n%s\n(Enter 1 if yes else enter 0)\n", menu2[0]);
                int inp;
                scanf("%d", &inp);
                if (inp == 1)
                {
                    //@nachiket implement menu 2 code here
                    printEquivalence(numberOfWebs,relation, webArray);
                }
            }
            break;
        case 8:
            if (isAntiSymmetric(numberOfWebs,relation) && isTransitive(numberOfWebs,relation)  && isReflexive(numberOfWebs,relation)){
                printf("Yes\n");

                printf("Menu 4 \n");
                for (int i = 0; i < 9; i++)
                {
                    printf("%s \n", menu4[i]);
                }
                printf("Select option number\n");

                int inp;
                scanf("%d", &inp);
                switch (inp)
                {
                case 1:
                    printHasseDiagram(numberOfWebs, relation, webArray);
                    break;
                case 2:
                    for (int c = 0; c < numberOfWebs; c++)
                    {
                        int count = 0;
                        for (int r = 0; r < numberOfWebs; r++)
                        {
                            if(relation[r][c] == 1){
                                count++;
                            }
                        }
                        if(count == numberOfWebs){
                            printf("%s\n", webArray[c]);
                            break;
                        }
                    }
                    break;

                case 3:
                     for (int c = 0; c < numberOfWebs; c++)
                    {
                        int count = 0;
                        for (int r = 0; r < numberOfWebs; r++)
                        {
                            if(relation[c][r] == 1){
                                count++;
                            }
                        }
                        if(count == numberOfWebs){
                            printf("%s\n", webArray[c]);
                            break;
                        }
                    }
                    break;

                case 4:
                
                    for (int i = 0; i < numberOfWebs; i++)
                    {int count=0;
                        for (int j = 0; j < numberOfWebs; j++)
                        {
                            if (relation[i][j] == 0)
                            {
                              count++;
                            }
                            
                            
                        }
                         if(relation[i][i]==1&count==numberOfWebs-1)printf("%s\n", webArray[i]);
                    }
                    break;
                case 5:
                for (int i = 0; i < numberOfWebs; i++)
                    {int count=0;
                        for (int j = 0; j < numberOfWebs; j++)
                        {
                            if (relation[j][i] == 0)
                            {
                              count++;
                            }
                            
                            
                        }
                         if(relation[i][i]==1&&count==numberOfWebs-1)printf("%s\n", webArray[i]);
                    }
                    break;
                case 6:
                    /* code */
                   menu4case6(numberOfWebs,webArray,relation);
                    break;
                case 7:
                    /* code */
                   menu4case7(numberOfWebs,webArray,relation);
                    break;
                case 8:
                if(isLattice(numberOfWebs,relation)==1)
                {
                    printf("Yes\n");
                     printf("Menu 5 \n");
                for (int i = 0; i < 4; i++)
                {
                    printf("%s \n", menu5[i]);
                }
                 printf("Select option number\n");
                int inp;
                scanf("%d", &inp);
                switch(inp){
                    case 1:
                    printf("Enter Website A index\n");
                    int a;
                    scanf("%d", &a);
                    printf("Enter Website B index\n");
                    int b;
                    scanf("%d", &b);
                    printf("%d",webArray[lowestUpperBound(numberOfWebs,relation,a,b)]);
                         break;
                    case 2:
                    printf("Enter Website A index\n");
                    int c;
                    scanf("%d", &c);
                    printf("Enter Website B index\n");
                    int d;
                    scanf("%d", &d);
                    printf("%d",webArray[greatestLowerBound(numberOfWebs,relation,c,d)]);
                        break;
                    case 3:
                    if(isDistributive(numberOfWebs,relation)==1)printf("Yes");
                    else printf("No");
                    
                        break;
                    case 4:
                        break;
                    default:
                        break;
                }
                    
                    }
                    else printf("No\n");
                    break;
                
                
                 case 9:
                    /* code */
                    break;
                default:
                    break;
                }
            }else{
                printf("No\n");
            }
            break;
        case 9:
            break;
        default:
            break;
        }
    }
    return 0;
}
