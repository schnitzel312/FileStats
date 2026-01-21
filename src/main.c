#include "../headers/filestats.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    char *filename = argv[1];
    print_file_stats(filename);
    return 0;
}
