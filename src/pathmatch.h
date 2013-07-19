#ifndef PATHMATCH_H
#define PATHMATCH_H

/* Pattern Language:
 *
 * * - matches zero-or-more of any character(s) but '/'
 * ** - matches zero-or-more of any character(s)
 * ? - matches exactly one of any character but '/'
 * ?? - matches exactly one of any character
 *
 * All other characters in the pattern are taken as literal
 * 
 * There is no way to escape a ? or *
 *
 * Returns 1 on successful match, 0 otherwise
 *
 */
int pathmatch(const char *pattern, const char *text);

#endif
