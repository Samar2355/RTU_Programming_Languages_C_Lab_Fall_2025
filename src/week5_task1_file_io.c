// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    // TODO: 1. Open file for writing (mode = "w")    
    fp = fopen("data.txt", "w");
    // TODO: 2. Check if file opened successfully
    if (fp == NULL) 
        printf("The file is not opened.");
    else{

        printf("The file is now opened.\n");
    // TODO: 3. Write 2–3 lines of text to the file using fprintf()
    fputs("Hello, Im Samar Joshi. \nCurrently i am writing in this file for our fifth week. \nThank you.", fp);
    // TODO: 4. Close the file
     fclose(fp);

    // TODO: 5. Open file again for reading (mode = "r")
    fp = fopen("data.txt", "r");
    // TODO: 6. Use fgets() in a loop to read and print each line to the console
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    // TODO: 7. Close the file
    fclose(fp);

    // BONUS: ask user for filename instead of using default "data.txt"
    printf("\nEnter the filename to read: ");
    scanf("%s", filename);
    rename("data.txt", filename);
    fp = fopen(filename, "r");
    // BONUS: count number of lines read
    int line_count = 0;
    if (fp == NULL) {
        printf("Could not open file %s for reading.\n", filename);
    } else {
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
            line_count++;
        }
        printf("\nTotal lines read: %d\n", line_count);
        fclose(fp);
    }
    return 0;
}
}