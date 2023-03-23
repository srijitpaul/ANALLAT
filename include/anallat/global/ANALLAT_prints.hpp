/*
 * ANALLAT_error
 * inspired by QUDA
 */

#pragma once

extern bool ANALLAT_init_flag;
extern bool ANALLAT_hold_exit;

static const size_t MAX_PREFIX_SIZE = 100;

static char prefix_[MAX_PREFIX_SIZE] = "";
static FILE *outfile_ = stdout;

static const int MAX_BUFFER_SIZE = 1000;
static char buffer_[MAX_BUFFER_SIZE] = "";

static inline char *getOutputPrefix() { return prefix_; }
static inline FILE *getOutputFile() { return outfile_; }
static inline char *getPrintBuffer() { return buffer_; }

#define ANALLAT_error(...) do {						\
    ANALLAT_hold_exit = true;						\
    fprintf(getOutputFile(), "%sERROR: ", getOutputPrefix());		\
    fprintf(getOutputFile(), __VA_ARGS__);				\
    fflush(getOutputFile());						\
    ANALLAT_hold_exit = false;						\
} while(0)

#define ANALLAT_printf(...) do {						\
    printf(__VA_ARGS__);                    \
    fflush(getOutputFile());                           \
    sprintf(getPrintBuffer(), __VA_ARGS__);				\
  } while(0)

#define ANALLAT_warning(...) do {					\
    if (ANALLAT_init_flag) {						\
        sprintf(getPrintBuffer(), __VA_ARGS__);				\
        fprintf(getOutputFile(), "%sWARNING: ", getOutputPrefix());	\
        fprintf(getOutputFile(), "%s", getPrintBuffer());		\
        fprintf(getOutputFile(), "\n");				\
        fflush(getOutputFile());					\
}   else {								\
        printf("WARNING: ");						\
        printf(__VA_ARGS__);						\
}									\
} while (0)
