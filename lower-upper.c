/**
 * K&R 2-10
 */

char lower (char c)
{
  return (c <= 'Z' && c >= 'A') ? c - 'A' + 'a' : c;
}

char upper (char c)
{
  return (c <= 'z' && c >= 'a') ? c - 'a' + 'A' : c;
}

int main ()
{
  char c;
  for (c='A'; c <= 'z'; c++)
    printf("%c -> %c\n", c, lower(c));
}
