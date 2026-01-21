#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/filestats.h"


bool is_new_line(int curr_char) {
    return curr_char == '\n';
}

bool is_word(int prev_char, int curr_char) {
    return !isspace((unsigned char) prev_char) && prev_char != EOF && (
               isspace((unsigned char) curr_char) || curr_char == EOF);
}

bool is_character(int curr_char) {
    return curr_char != EOF;
}

fileStatsError get_file_stats(fileStats *file_stats, char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) { return ErrOpeningFile; }
    int prev_char = fgetc(fptr);
    bool is_eof = prev_char == EOF;
    int characters = is_eof ? 0 : 1;
    int words = 0;
    int lines = is_eof ? 0 : 1;
    while (true) {
        int curr_char = fgetc(fptr);
        is_eof = curr_char == EOF;
        lines += is_new_line(prev_char) ? 1 : 0;
        words += is_word(prev_char, curr_char) ? 1 : 0;
        characters += is_character(curr_char) ? 1 : 0;
        if (is_eof) {
            break;
        }
        prev_char = curr_char;
    }
    fclose(fptr);
    file_stats->characters_count = characters;
    file_stats->word_count = words;
    file_stats->lines_count = lines;
    return GetFileStatsSuccess;
}

void print_file_stats(char *filename) {
    fileStats file_stats;
    fileStatsError error = get_file_stats(&file_stats, filename);

    if (error == ErrOpeningFile) {
        printf("Error opening file\n");
        return;
    }
    printf("File: %s\nCharacters: %d\nWords: %d\nLines: %d\n",
           filename,
           file_stats.characters_count,
           file_stats.word_count,
           file_stats.lines_count);
}
