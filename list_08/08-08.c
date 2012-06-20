int str_len(const char *s)
{
  const char *p = s;

  while (*s){
    s++;
  }

  return (s - p);
}
