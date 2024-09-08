//#include <ncurses.h>
//#include <signal.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//#define HEIGHT 25
//#define LENGTH 80
//#define LIFE "*"
//#define DEAD " "
//#define MAXSPEED 1.9
//#define MINSPEED 0.1
//#define ITERSPEED 0.1
//#define STARTSPEED 100000
//
//void printMenuOptions();
//void saveScan(int *command);
//void inputRules();
//void game(int mode);
//void changeStream(int mode);
//int allocMemory(char ***matrix);
//void freeMemory(char **matrix);
//void fieldCreation(char **matrix);
//int fieldUpdate(char ***matrix, char ***buff);
//int countAliveCells(char **matrix, int i, int j);
//char cellUpdate(char cell, int count, int *changeFlag);
//void fieldOutput(char **matrix, WINDOW *win);
//void changeSpeed(char button, float *speed);
//
//int main(void) {
//    int command = -1;
//    printMenuOptions();
//    saveScan(&command);
//    game(command);
//    return 0;
//}
//
//
//void printMenuOptions(void) {
//  printf("1 - пользовательский ввод игры\n");
//// реализовать рандом и несколько картинок красивых с инета взять
//// cообщение о том за что какая кнопка отвечает
//}
//
//
//
//void scan_mode(int *command) {
//  int check = 0;
//  while (!check) {
//    printf("Ввод команды: ");
//    check = scanf("%d", command);
//    if (!check) {
//      printf("Ошибка ввода, попробуем снова.\n");
//      getchar();
//    } else if (*command < 1 || *command > 6) {
//      printf("Неизвестная комманда, попробуем снова.\n");
//      check = 0;
////      stdin = freopen("/dev/tty", "r", stdin);
//    }
//  }
//}
//
//void inputRules() {
//  printf("Корректный ввод мертвой клетки: 0 или - \n");
//  printf("Корректный ввод живой клетки: 1 или  o \n");
//
//    // на усмотрение кто как хочет чтобы выглядел ввод (на самом деле не очень важно)
//}
//
//void game(int mode) {
//  char **matrix;
//  char **buff;
//  float speed = 1.0f;
//  char button = '\0';
//  allocMemory(&matrix);
//  allocMemory(&buff);
//  changeStream(mode);
//  fieldCreation(matrix);
//  stdin = freopen("/dev/tty", "r", stdin);
//  initscr();
//  noecho();
//  WINDOW *win = newwin(HEIGHT, LENGTH, 0, 0);
//  wrefresh(win);
//  fieldOutput(matrix, win);
//  wrefresh(win);
//  while (fieldUpdate(&matrix, &buff) && !(button == 'q' || button == 'Q')) {
//    fieldOutput(matrix, win);
////    mvwprintw(win, HEIGHT - 1, 5, "Speed: x%.1f", 2.0 - speed);
//    halfdelay(1);
//    button = wgetch(win);
//    changeSpeed(button, &speed);
//    usleep(STARTSPEED * speed);
//    wrefresh(win);
//  }
//  freeMemory(matrix);
//  freeMemory(buff);
//  endwin();
//}
//
//void changeStream(int mode) {
//  switch (mode) {
//  case 1:
//    inputRules();
//    break;
//  case 2:
////    stdin = freopen("./presets/cow.txt", "r", stdin); здесь нужно больше таких файлов и добавить рандом
//    break;
//
//  }
//}
//
//int allocMemory(char ***matrix) {
//  int check = 1;
//  (*matrix) = malloc(HEIGHT * sizeof(char *));
//  if (*matrix != NULL) {
//    for (int i = 0; i < HEIGHT; i++) {
//      (*matrix)[i] = malloc(LENGTH * sizeof(char));
//      if ((*matrix)[i] == NULL) {
//        check = 0;
//        for (int j = 0; j < i; j++)
//          free((*matrix)[i]);
//        free(matrix);
//        break;
//      }
//    }
//  } else {
//    check = 0;
//  }
//  return check;
//}
//
//void freeMemory(char **matrix) {
//  for (int i = 0; i < HEIGHT; i++)
//    free(matrix[i]);
//  free(matrix);
//}
//
//void fieldCreation(char **matrix) {
//  for (int i = 0; i < HEIGHT; i++) {
//    for (int j = 0; j < LENGTH; j++) {
//      char c;
//      scanf("%c ", &c);
//      if (c == '-')
//        c = '0';
//      if (c == 'o')
//        c = '1';
//      matrix[i][j] = c;
//    }
//  }
//}
//
//int fieldUpdate(char ***matrix, char ***buff) {
//  int livCells = 0;
//  int changeFlag = 0;
//  int count;
//  int check = 1;
//  for (int i = 0; i < HEIGHT; i++) {
//    for (int j = 0; j < LENGTH; j++) {
//      count = countAliveCells(*matrix, i, j);
//      livCells += count;
//      (*buff)[i][j] = cellUpdate((*matrix)[i][j], count, &changeFlag);
//    }
//  }
//  char **temp = *matrix;
//  *matrix = *buff;
//  *buff = temp;
//  if (livCells == 0 || changeFlag == 0)
//    check = 0;
//  return check;
//}
//
//int countAliveCells(char **matrix, int i, int j) {
//  int count = 0;
//  for (int istep = -1; istep <= 1; istep++) {
//    for (int jstep = -1; jstep <= 1; jstep++) {
//      if ((matrix[(HEIGHT + i + istep) % HEIGHT]
//                 [(LENGTH + j + jstep) % LENGTH] == '1') &&
//          !(istep == 0 && jstep == 0))
//        count++;
//    }
//  }
//  return count;
//}
//
//char cellUpdate(char cell, int count, int *changeFlag) {
//  char newCell;
//  if (cell == '1') {
//    if (count != 2 && count != 3) {
//      newCell = '0';
//      *changeFlag = 1;
//    } else {
//      newCell = '1';
//    }
//  } else {
//    if (count == 3) {
//      newCell = '1';
//      *changeFlag = 1;
//    } else {
//      newCell = '0';
//    }
//  }
//  return newCell;
//}
//
//void fieldOutput(char **matrix, WINDOW *win) {
//  for (int i = 0; i < HEIGHT; i++) {
//    for (int j = 0; j < LENGTH; j++) {
//      if (matrix[i][j] == '1') {
//        mvwprintw(win, i, j, LIFE);
//        printw(LIFE);
//      } else {
//        mvwprintw(win, i, j, DEAD);
//      }
//    }
//  }
//}
//
//void changeSpeed(char button, float *speed) {
//    if (*speed > MINSPEED && (button == 'a' || button == 'A')) {
//        *speed -= ITERSPEED;
//    }
//    if (*speed < MAXSPEED && (button == 'z' || button == 'Z')) {
//        *speed += ITERSPEED;
//    }
//}



//#include <ncurses.h>
//#include <signal.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//
//#define GRID_HEIGHT 25
//#define GRID_WIDTH 80
//#define ALIVE_CELL "*"
//#define DEAD_CELL " "
//#define MAX_GAME_SPEED 1.9
//#define MIN_GAME_SPEED 0.1
//#define SPEED_INCREMENT 0.1
//#define INITIAL_SPEED 100000
//
//void displayMenu(void);
//void getCommand(int *cmd);
//void showInputRules(void);
//void startGame(int mode);
//void setupStream(int mode);
//int allocateGridMemory(char ***grid);
//void deallocateGridMemory(char **grid);
//void createInitialField(char **grid);
//int updateField(char ***current, char ***buffer);
//int countLivingNeighbors(char **grid, int row, int col);
//char updateCellState(char cell, int neighborCount, int *hasChanged);
//void renderField(char **grid, WINDOW *window);
//void adjustSpeed(char input, float *speed);
//
//int main(void) {
//    int command = -1;
//    displayMenu();
//    getCommand(&command);
//    startGame(command);
//    return 0;
//}
//
//void displayMenu(void) {
//    printf("1 - Ввести игровое поле вручную\n");
//    printf("2 - Загрузить карту cow\n");
//    printf("3 - Загрузить карту gunGospy\n");
//    printf("4 - Загрузить карту gunSim\n");
//    printf("5 - Загрузить карту agar\n");
//    printf("6 - Загрузить карту shipNew\n");
//}
//
//void getCommand(int *cmd) {
//    int valid = 0;
//    while (!valid) {
//        printf("Введите команду: ");
//        valid = scanf("%d", cmd);
//        if (!valid) {
//            printf("Ошибка ввода, попробуйте снова.\n");
//            getchar();
//        } else if (*cmd < 1 || *cmd > 6) {
//            printf("Неизвестная команда, попробуйте снова.\n");
//            valid = 0;
//        }
//    }
//}
//
//void showInputRules(void) {
//    printf("Для мертвой клетки: 0 или - \n");
//    printf("Для живой клетки: 1 или o \n");
//}
//
//void startGame(int mode) {
//    char **currentGrid;
//    char **bufferGrid;
//    float gameSpeed = 1.0f;
//    char userInput = '\0';
//
//    allocateGridMemory(&currentGrid);
//    allocateGridMemory(&bufferGrid);
//    setupStream(mode);
//    createInitialField(currentGrid);
//    stdin = freopen("/dev/tty", "r", stdin);
//
//    initscr();
//    noecho();
//    WINDOW *window = newwin(GRID_HEIGHT, GRID_WIDTH, 0, 0);
//    wrefresh(window);
//    renderField(currentGrid, window);
//    wrefresh(window);
//
//    while (updateField(&currentGrid, &bufferGrid) && !(userInput == 'q' || userInput == 'Q')) {
//        renderField(currentGrid, window);
//        mvwprintw(window, GRID_HEIGHT - 1, 5, "Скорость: x%.1f", 2.0 - gameSpeed);
//        halfdelay(1);
//        userInput = wgetch(window);
//        adjustSpeed(userInput, &gameSpeed);
//        usleep(INITIAL_SPEED * gameSpeed);
//        wrefresh(window);
//    }
//
//    deallocateGridMemory(currentGrid);
//    deallocateGridMemory(bufferGrid);
//    endwin();
//}
//
//void setupStream(int mode) {
//    switch (mode) {
//        case 1:
//            showInputRules();
//            break;
//        case 2:
//            stdin = freopen("./presets/cow.txt", "r", stdin);
//            break;
//        case 3:
//            stdin = freopen("./presets/gunGospy.txt", "r", stdin);
//            break;
//        case 4:
//            stdin = freopen("./presets/gunSim.txt", "r", stdin);
//            break;
//        case 5:
//            stdin = freopen("./presets/agar.txt", "r", stdin);
//            break;
//        case 6:
//            stdin = freopen("./presets/shipNew.txt", "r", stdin);
//            break;
//    }
//}
//
//int allocateGridMemory(char ***grid) {
//    int success = 1;
//    *grid = malloc(GRID_HEIGHT * sizeof(char *));
//    if (*grid != NULL) {
//        for (int i = 0; i < GRID_HEIGHT; i++) {
//            (*grid)[i] = malloc(GRID_WIDTH * sizeof(char));
//            if ((*grid)[i] == NULL) {
//                success = 0;
//                for (int j = 0; j < i; j++) {
//                    free((*grid)[j]);
//                }
//                free(grid);
//                break;
//            }
//        }
//    } else {
//        success = 0;
//    }
//    return success;
//}
//
//void deallocateGridMemory(char **grid) {
//    for (int i = 0; i < GRID_HEIGHT; i++) {
//        free(grid[i]);
//    }
//    free(grid);
//}
//
//void createInitialField(char **grid) {
//    for (int i = 0; i < GRID_HEIGHT; i++) {
//        for (int j = 0; j < GRID_WIDTH; j++) {
//            char cell;
//            scanf("%c", &cell);
//            if (cell == '-') cell = '0';
//            if (cell == 'o') cell = '1';
//            grid[i][j] = cell;
//        }
//    }
//}
//
//int updateField(char ***current, char ***buffer) {
//    int livingCells = 0;
//    int changed = 0;
//    int neighbors;
//
//    for (int i = 0; i < GRID_HEIGHT; i++) {
//        for (int j = 0; j < GRID_WIDTH; j++) {
//            neighbors = countLivingNeighbors(*current, i, j);
//            livingCells += neighbors;
//            (*buffer)[i][j] = updateCellState((*current)[i][j], neighbors, &changed);
//        }
//    }
//
//    char **temp = *current;
//    *current = *buffer;
//    *buffer = temp;
//
//    return (livingCells != 0 && changed != 0);
//}
//
//int countLivingNeighbors(char **grid, int row, int col) {
//    int count = 0;
//    for (int i = -1; i <= 1; i++) {
//        for (int j = -1; j <= 1; j++) {
//            if (grid[(GRID_HEIGHT + row + i) % GRID_HEIGHT][(GRID_WIDTH + col + j) % GRID_WIDTH] == '1' &&
//                !(i == 0 && j == 0)) {
//                count++;
//            }
//        }
//    }
//    return count;
//}
//
//char updateCellState(char cell, int neighborCount, int *hasChanged) {
//    char newState;
//    if (cell == '1') {
//        if (neighborCount != 2 && neighborCount != 3) {
//            newState = '0';
//            *hasChanged = 1;
//        } else {
//            newState = '1';
//        }
//    } else {
//        if (neighborCount == 3) {
//            newState = '1';
//            *hasChanged = 1;
//        } else {
//            newState = '0';
//        }
//    }
//    return newState;
//}
//
//void renderField(char **grid, WINDOW *window) {
//    for (int i = 0; i < GRID_HEIGHT; i++) {
//        for (int j = 0; j < GRID_WIDTH; j++) {
//            if (grid[i][j] == '1') {
//                mvwprintw(window, i, j, ALIVE_CELL);
//                printw(ALIVE_CELL);
//            } else {
//                mvwprintw(window, i, j, DEAD_CELL);
//            }
//        }
//    }
//}
//
//void adjustSpeed(char input, float *speed) {
//    if (*speed > MIN_GAME_SPEED && (input == 'a' || input == 'A')) {
//        *speed -= SPEED_INCREMENT;
//    }
//    if (*speed < MAX_GAME_SPEED && (input == 'z' || input == 'Z')) {
//        *speed += SPEED_INCREMENT;
//    }
//}


#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define GRID_HEIGHT 25
#define GRID_WIDTH 80
#define ALIVE_CELL "*"
#define DEAD_CELL " "
#define MAX_GAME_SPEED 1.9
#define MIN_GAME_SPEED 0.1
#define SPEED_INCREMENT 0.1
#define INITIAL_SPEED 100000

void displayMenu(void);
void getCommand(int *cmd);
void showInputRules(void);
void startGame(int mode);
void setupStream(int mode);
int allocateGridMemory(char ***grid);
void deallocateGridMemory(char **grid);
void createInitialField(char **grid);
void createRandomField(char **grid);
int updateField(char ***current, char ***buffer);
int countLivingNeighbors(char **grid, int row, int col);
char updateCellState(char cell, int neighborCount, int *hasChanged);
void renderField(char **grid, WINDOW *window);
void adjustSpeed(char input, float *speed);

int main(void) {
    int command = -1;
    displayMenu();
    getCommand(&command);
    startGame(command);
    return 0;
}

void displayMenu(void) {
    printf("Ввести игровое поле вручную: 1\n");
    // еще команды
    printf("Случайное игровое поле: 7\n");
}

void getCommand(int *cmd) {
    int valid = 0;
    while (!valid) {
        printf("Введите команду: ");
        valid = scanf("%d", cmd);
        if (!valid) {
            printf("Ошибка ввода, попробуйте снова.ё\n");
            getchar();
        } else if (*cmd < 1 || *cmd > 7) {
            printf("попробуйте снова\n");
            valid = 0;
        }
    }
}

void showInputRules(void) {
    printf("Для мертвой клетки: 0 или - \n");
    printf("Для живой клетки: 1 или o \n");
}

void startGame(int mode) {
    char **currentGrid;
    char **bufferGrid;
    float gameSpeed = 1.0f;
    char userInput = '\0';

    allocateGridMemory(&currentGrid);
    allocateGridMemory(&bufferGrid);
    setupStream(mode);
    if (mode == 7) {
        createRandomField(currentGrid);
    } else {
        createInitialField(currentGrid);
    }
    // Перенаправляем stdin

    initscr(); // Инициализируем ncurses после перенаправления stdin
    noecho();
    WINDOW *window = newwin(GRID_HEIGHT, GRID_WIDTH, 0, 0);
    wrefresh(window);
    renderField(currentGrid, window);
    wrefresh(window);

    while (updateField(&currentGrid, &bufferGrid) && !(userInput == 'q' || userInput == 'Q')) {
        renderField(currentGrid, window);
        mvwprintw(window, GRID_HEIGHT - 1, 5, "Скорость: x%.1f", 2.0 - gameSpeed);
        halfdelay(1);
        userInput = wgetch(window);
        adjustSpeed(userInput, &gameSpeed);
        usleep(INITIAL_SPEED * gameSpeed);
        wrefresh(window);
    }

    deallocateGridMemory(currentGrid);
    deallocateGridMemory(bufferGrid);
    endwin();
}

void setupStream(int mode) {
    switch (mode) {
        case 1:
            showInputRules();
            break;
        case 2:
            stdin = freopen("ПУТЬ К ФАЙЛУ", "r", stdin);
            break;
    }
}

int allocateGridMemory(char ***grid) {
    int success = 1;
    *grid = malloc(GRID_HEIGHT * sizeof(char *));
    if (*grid != NULL) {
        for (int i = 0; i < GRID_HEIGHT; i++) {
            (*grid)[i] = malloc(GRID_WIDTH * sizeof(char));
            if ((*grid)[i] == NULL) {
                success = 0;
                for (int j = 0; j < i; j++) {
                    free((*grid)[j]);
                }
                free(grid);
                break;
            }
        }
    } else {
        success = 0;
    }
    return success;
}

void deallocateGridMemory(char **grid) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);
}

void createInitialField(char **grid) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            char cell;
            scanf("%c ", &cell);
            if (cell == '-') cell = '0';
            if (cell == 'o') cell = '1';
            grid[i][j] = cell;
        }
    }
}

void createRandomField(char **grid) {
    srand(time(NULL));
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = (rand() % 2) ? '1' : '0';
        }
    }
}

int updateField(char ***current, char ***buffer) {
    int livingCells = 0;
    int changed = 0;
    int neighbors;

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            neighbors = countLivingNeighbors(*current, i, j);
            livingCells += neighbors;
            (*buffer)[i][j] = updateCellState((*current)[i][j], neighbors, &changed);
        }
    }

    char **temp = *current;
    *current = *buffer;
    *buffer = temp;

    return (livingCells != 0 && changed != 0);
}

int countLivingNeighbors(char **grid, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (grid[(GRID_HEIGHT + row + i) % GRID_HEIGHT][(GRID_WIDTH + col + j) % GRID_WIDTH] == '1' &&
                !(i == 0 && j == 0)) {
                count++;
            }
        }
    }
    return count;
}

char updateCellState(char cell, int neighborCount, int *hasChanged) {
    char newState;
    if (cell == '1') {
        if (neighborCount != 2 && neighborCount != 3) {
            newState = '0';
            *hasChanged = 1;
        } else {
            newState = '1';
        }
    } else {
        if (neighborCount == 3) {
            newState = '1';
            *hasChanged = 1;
        } else {
            newState = '0';
        }
    }
    return newState;
}

void renderField(char **grid, WINDOW *window) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (grid[i][j] == '1') {
                mvwprintw(window, i, j, ALIVE_CELL);
                printw(ALIVE_CELL);
            } else {
                mvwprintw(window, i, j, DEAD_CELL);
            }
        }
    }
}

void adjustSpeed(char input, float *speed) {
    if (*speed > MIN_GAME_SPEED && (input == 'a' || input == 'A')) {
        *speed -= SPEED_INCREMENT;
    }
    if (*speed < MAX_GAME_SPEED && (input == 'z' || input == 'Z')) {
        *speed += SPEED_INCREMENT;
    }
}
