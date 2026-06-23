int ft_str_is_alpha(char *str) {
  int i;

  i = 0;
  while (str[i]) {
    if (!(str[i] >= 97 && str[i] <= 122) || !(str[i] >= 65 && str[i] <= 90))
      return (0);
    i++;
  }
  return (1);
}
