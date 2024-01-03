#include <stdio.h>
#include <stdlib.h>

// Fonction pour afficher le contenu d'un fichier
void displayFile(char* filename) {
    FILE* file = fopen(filename, "r");
    char ch;
    while((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

// Fonction pour compter la fréquence d'un caractère dans un fichier
int countChar(char* filename, char x) {
    FILE* file = fopen(filename, "r");
    char ch;
    int count = 0;
    while((ch = fgetc(file)) != EOF) {
        if(ch == x) {
            count++;
        }
    }
    fclose(file);
    return count;
}

// Fonction pour substituer un caractère par un autre dans un fichier
void substituteChar(char* filename, char x, char y) {
    FILE* file = fopen(filename, "r+");
    char ch;
    while((ch = fgetc(file)) != EOF) {
        if(ch == x) {
            fseek(file, -1, SEEK_CUR);
            fputc(y, file);
            fseek(file, 0, SEEK_CUR);
        }
    }
    fclose(file);
}

// Fonction pour concaténer deux fichiers
void concatenateFiles(char* filename1, char* filename2, char* filename3) {
    FILE* file1 = fopen(filename1, "r");
    FILE* file2 = fopen(filename2, "r");
    FILE* file3 = fopen(filename3, "w");

    char ch;
    while((ch = fgetc(file1)) != EOF) {
        fputc(ch, file3);
    }
    while((ch = fgetc(file2)) != EOF) {
        fputc(ch, file3);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
}

int main() {
    while(1) {
        printf("1. Display file\n2. Count character\n3. Substitute character\n4. Concatenate files\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
// change this to switch(choice) {
   switch(choice) {
        case 1: {
            char filename[100];
            printf("Enter filename: ");
            scanf("%s", filename);
            displayFile(filename);
            break;
        }
        case 2: {
            char filename[100], x;
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter character to count: ");
            scanf(" %c", &x);  // space before %c to skip any whitespace characters
            printf("Count: %d\n", countChar(filename, x));
            break;
        }
        case 3: {
            char filename[100], x, y;
            printf("Enter filename: ");
            scanf("%s", filename);
            printf("Enter character to replace: ");
            scanf(" %c", &x);  // space before %c to skip any whitespace characters
            printf("Enter new character: ");
            scanf(" %c", &y);  // space before %c to skip any whitespace characters
            substituteChar(filename, x, y);
            break;
        }
        case 4: {
            char filename1[100], filename2[100], filename3[100];
            printf("Enter first filename: ");
            scanf("%s", filename1);
            printf("Enter second filename: ");
            scanf("%s", filename2);
            printf("Enter output filename: ");
            scanf("%s", filename3);
            concatenateFiles(filename1, filename2, filename3);
            break;
        }   
    }
    if(choice == 5) {
        break;
    }

}
return 0;
}