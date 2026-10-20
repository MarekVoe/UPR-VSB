#include <stdio.h>
#include <stdlib.h>

char* initCanvas(const size_t rows, const size_t cols);
void printCanvas(char* canvas, const size_t rows, const size_t cols);

// TODO: Vytvořit strukturu pro želvu, bude tam znak, pozice

int main() {
    size_t rows, cols = 0;
    scanf("%zu %zu", &rows, &cols);
    char* canvas = initCanvas(rows, cols);
    printCanvas(canvas, rows, cols);
}

char* initCanvas(const size_t rows, const size_t cols) {
    char *canvas = (char*) malloc(rows * cols * sizeof(char));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            canvas[i * cols + j] = '.';
        }
    }
    return canvas;
}

void printCanvas(char* canvas, const size_t rows, const size_t cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", canvas[i * cols + j]);
        }
        printf("\n");
    }
}

