string *alpha(string *str)
{
  int i, x;
  string *newString, tmp, tmp2;
  x = sizeof(str);
  while(x--)
  {
   tmp = str[x];
     tmp2 = (x != 0) ? str[x - 1] : str[x];
   newString =  sort_array(str, strcmp(tmp, tmp2) );
  }
 // newString = sort_array(str, strcmp((string)str[0..x-1], (string)str[0..x-1]));
  return newString;
 }
   
    