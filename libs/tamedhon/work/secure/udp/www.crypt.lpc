/* SilberLand MUDlib
 *
 * /secure/udp/www.crypt.c -- cryptologic functionality to conceal path names
 *
 * $Date: 1997/03/16 00:42:48 $
 * $Revision: 1.1 $
 * $Log: www.crypt.c,v $
 * Revision 1.1  1997/03/16 00:42:48  Woody
 * prepared for revision control
 *
 */

// MorgenGrauen MUDlib Contribution

#pragma strong_types
#pragma combine_strings

string _crypt(string str, string tab, string passwd)
{
  int i;
  i = sizeof(str);
  while(i--)
    str[i]= tab[(member(tab, str[i]) 
          + member(tab, passwd[i % sizeof(passwd)])) % sizeof(tab)];
  return str;
}

string _decrypt(string str, string tab, string passwd)
{
  int i, tmp;
  i = sizeof(str);
  while(i--) {
    if ((tmp=(member(tab, str[i]) - member(tab, passwd[i%sizeof(passwd)])))<0)
      tmp += sizeof(tab);
    str[i] = tab[tmp];
  }
  return str;
}
