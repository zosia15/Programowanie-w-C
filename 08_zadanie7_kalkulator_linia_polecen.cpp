#include <iostream>
#include <cstring>

void usage(char *programName) {
    printf("Usage: %s number1 operation number2\n", programName);
    printf("Available operations:\n");
    printf("\tadd\n");
    printf("\n");
}

int main(int argc, char* argv[]) {

    int number1 = 0;
    int number2 = 0;
    int result = 0;

    if (argc == 4) {
        number1 = atoi(argv[1]);
        number2 = atoi(argv[3]);

        if (!strcmp("add", argv[2])) {
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
            return 0;
        }

    }

    usage(argv[0]);

    return 0;
}


// void usage(const char *program_name) {
//     printf("Sposob uzycia: %s <komunikat> <#powtorzen>\n", program_name);
//     exit(1);
// }
//
// int main(int argc, char const *argv[]) {
//     if (argc < 3)
//         usage(argv[0]);
//     int count = atoi(argv[2]);
//     printf("Powtarzam %d razy..\n", count);
//     for (int i = 0; i < count; i++)
//         printf("%3d - %s\n", i, argv[1]);
//     return 0;
// }

// int main(int argc, char const *argv[]) {
//     printf("Podano %d argumentow:\n", argc);
//     for (int i = 0; i < argc; i++) {
//         printf("Argunent #%d\t-\t%s\n", i, argv[i]);
//     }
//
//     return 0;
// }