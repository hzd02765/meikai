int int_cmp(const int *a, const int *b)
{
  if(*a < *b){
    return (1);
  }else if(*a > *b){
    return (-1);
  }else{
    return (0);
  }
}
