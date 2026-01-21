#ifndef FILESTATS_H
#define FILESTATS_H
typedef enum {
    ErrOpeningFile,
    GetFileStatsSuccess
} fileStatsError;

typedef struct {
    int characters_count;
    int word_count;
    int lines_count;
} fileStats;

fileStatsError get_file_stats(fileStats *file_stats, char *filename);
void print_file_stats(char *filename);
#endif //FILESTATS_H