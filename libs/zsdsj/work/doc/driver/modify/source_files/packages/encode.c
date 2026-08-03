
#ifdef LATTICE
#include "/lpc_incl.h"
#else
#include "../lpc_incl.h"
#endif

#ifdef F_ENCODE
void f_encode PROT((void))
{
  unsigned ch;
  char *str, *crypt_key;
  int i, l, size;
  
  crypt_key = sp->u.string;
  l = strlen(crypt_key);
  pop_stack();

  str = sp->u.string;
  size = strlen(str);
  
  for(i = 0; i < size; i++)
  {
    ch = (unsigned char)str[i] + (unsigned char)crypt_key[i % l];
    
    if(ch >= 256)
      ch -= 255;
    
    str[i] = (char)ch;
  }

}
#endif

#ifdef F_DECODE
void f_decode PROT((void))
{
  unsigned ch;
  char *str, *crypt_key;
  int i, l, size;

  crypt_key = sp->u.string;
  l = strlen(crypt_key);
  pop_stack();

  str = sp->u.string;
  size = strlen(str);  
  
  for(i = 0; i < size; i++)
  {
    if((unsigned char)str[i] > (unsigned char)crypt_key[i % l])
      ch = (unsigned char)str[i] - (unsigned char)crypt_key[i % l];
    else
      ch = (unsigned char)str[i] + 255 - (unsigned char)crypt_key[i % l];
    
    str[i] = (char)ch;
  }

}
#endif

