#include <stdio.h>
#include <stdlib.h>

// Šlo by udělat ta rotace pomocí linked listu, v tom smyslu, že když je želva otočena doprava a uživatel zadá r, tak v linked listu bude uložena
// current rotace a jako next node by byla rotace dolů ? A takto pro každou rotaci? Nebo to moc overthinkuju
typedef enum {
    RIGHT,
    DOWN,
    LEFT,
    UP
} DIRECTION;

typedef struct {
    int x;
    int y;
    char znak;
    DIRECTION dir;
} ZELVA;

char* initCanvas(const size_t rows, const size_t cols, ZELVA* zelva);
void printCanvas(char* canvas, const size_t rows, const size_t cols, ZELVA* zelva);
void moveTurtle(ZELVA* zelva);

int main() {
    char input = 'a';
    ZELVA zelva;
    size_t rows, cols = 0;
    scanf("%zu %zu", &rows, &cols);
    char* canvas = initCanvas(rows, cols, &zelva);
    while(input != 'x') {
        scanf("%c", &input);
        switch(input) {
            case 'r':
                if (zelva.dir != 3) {
                    zelva.dir++;
                } else {
                    zelva.dir = RIGHT;
                }
            break;

            case 'l':
                if (zelva.dir != 0) {
                    zelva.dir--;
                } else {
                    zelva.dir = UP;
                }
            break;

            case 'm':
                moveTurtle(&zelva);
            break;

            case 'o':
                // TODO: Replace '.' with o
            break;
        }
    }
    printCanvas(canvas, rows, cols, &zelva);
    free(canvas);
}

char* initCanvas(const size_t rows, const size_t cols, ZELVA* zelva) {
    char *canvas = (char*) malloc(rows * cols * sizeof(char));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            canvas[i * cols + j] = '.';
        }
    }
    zelva->x = 0;
    zelva->y = 0;
    zelva->znak = 'z';
    zelva->dir = RIGHT;
    return canvas;
}

void printCanvas(char* canvas, const size_t rows, const size_t cols, ZELVA* zelva) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == zelva->y && j == zelva->x) {
                printf("%c ", zelva->znak);
            } else {
                printf("%c ", canvas[i * cols + j]);
            }
        }
        printf("\n");
    }
}

void moveTurtle(ZELVA* zelva) {
     switch(zelva->dir) {
        case RIGHT:
            zelva->x += 1;
        break;

        case DOWN:
            zelva->y += 1;
        break;

        case LEFT:
            zelva->x -= 1;
        break;

        case UP:
            zelva->y -= 1;
        break;
    } 
}

