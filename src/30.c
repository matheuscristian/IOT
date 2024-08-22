int str_to_int(const char *str) {
  int sign = 1;
  int result = 0;
  int i = 0;

  if (str[0] == '-') {
    sign = -1;
    i++;
  }

  while (str[i] != '\0') {
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
    result = result * 10 + (str[i] - '0');
    i++;
  }

  return result * sign;
}