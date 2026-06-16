#include <cstdio>

void toLower(char text[]) {
    while (*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}

int textSize(char *text) {
    int size = 0;

    while (*text) {
        size++;
        text++;
    }

    return size;
}

int main() {
    char text[] = "Ala Ma Kota.";

    printf("%s\n", text);

    toLower(text);

    printf("%s\n", text);

    printf("Length: %d\n", textSize(text));

    return 0;
}