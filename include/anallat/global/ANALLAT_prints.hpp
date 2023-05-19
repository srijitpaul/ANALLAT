/*
 * ANALLAT_error
 * inspired by QUDA
 */

#ifndef ANALLAT_PRINTS_HPP
#define ANALLAT_PRINTS_HPP

#include <cstddef>
#include <iostream>
#include <cstdio>
#include <array>

extern const bool ANALLAT_init_flag;
extern const bool ANALLAT_hold_exit;

constexpr size_t MAX_PREFIX_SIZE = 100;
constexpr size_t MAX_BUFFER_SIZE = 1000;

const static std::array<char, MAX_PREFIX_SIZE> prefix_{};
const static std::FILE* const outfile_ = stdout;
const static std::array<char, MAX_BUFFER_SIZE> buffer_{};

static inline const char* getOutputPrefix() { return prefix_.data(); }
static inline const std::FILE* getOutputFile() { return outfile_; }
static inline const char* getPrintBuffer() { return buffer_.data(); }

#define ANALLAT_error(...) do {                                     \
    ANALLAT_hold_exit = true;                                       \
    std::fprintf(getOutputFile(), "%sERROR: ", getOutputPrefix());  \
    std::fprintf(getOutputFile(), __VA_ARGS__);                     \
    std::fflush(getOutputFile());                                   \
    ANALLAT_hold_exit = false;                                      \
} while(0)

#define ANALLAT_printf(...) do {                                    \
    std::printf(__VA_ARGS__);                                       \
    std::fflush(getOutputFile());                                   \
    std::sprintf(getPrintBuffer(), __VA_ARGS__);                    \
} while(0)

#define ANALLAT_warning(...) do {                                   \
    if (ANALLAT_init_flag) {                                        \
        std::sprintf(getPrintBuffer(), __VA_ARGS__);                \
        std::fprintf(getOutputFile(), "%sWARNING: ", getOutputPrefix()); \
        std::fprintf(getOutputFile(), "%s", getPrintBuffer());      \
        std::fprintf(getOutputFile(), "\n");                        \
        std::fflush(getOutputFile());                               \
    } else {                                                        \
        std::cout << "WARNING: " << __VA_ARGS__ << std::endl;       \
    }                                                               \
} while (0)

#endif  // ANALLAT_PRINTS_H_