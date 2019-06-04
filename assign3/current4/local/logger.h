/*
 * Joel Doumit
 * logger.h
 * Code written by Andrew Schwartzmeyer for his 120++ compiler.
 *
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

struct tree;

void log_error(const char *format, ...);
void log_debug(const char *format, ...);
void log_assert(bool p);

void log_lexical(const char *format, ...);
void log_semantic(struct tree *n, const char *format, ...);
void log_check(const char *format, ...);
void log_unsupported();

#endif /* LOGGER_H */
