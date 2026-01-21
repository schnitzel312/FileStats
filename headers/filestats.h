#ifndef HTTP_SERVER_C_FILESTATS_H
#define HTTP_SERVER_C_FILESTATS_H
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
#endif //HTTP_SERVER_C_FILESTATS_H