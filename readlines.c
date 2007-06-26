/**
 * K&R 5.7
 */
int readlines(char *lineptr[], int nlines, char *alloc_buf, int buf_size)
{
  int len, nlines;
  char *p = alloc_buf, line[MAXLEN];

  while ((len = getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p - alloc_buf + len > buf_size))
      {
        return -1;
      }
    else
      {
        line[len - 1] = '\0';
        lineptr[nlines++] = p;
        strcpy(p+=len, line);
      }
  return nlines;
}

        
