varargs string extract(string str, int index1, int index2)
{
  if(!index2) {
    if(index1 < strlen(str))
      return str[index1..strlen(str) - 1];
  } else {
    if((index1 < index2) && index2 < strlen(str))
      return str[index1..index2];
  }
  return str;
}
