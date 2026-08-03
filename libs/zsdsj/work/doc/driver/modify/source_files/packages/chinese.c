
#ifdef LATTICE
#include "/lpc_incl.h"
#else
#include "../lpc_incl.h"
#endif

#include "chinese.h"

/*
 * Written 2001/7/7 01:02上午 by lismo <lismo@ms66.hinet.net>
 *
 * 增加 ansi color 處理及新增一個參數可以做第一行的縮排工作. <clode@rw.muds.net>
 *
 */

#ifdef F_CWRAP
void f_cwrap PROT((void))
{
  register int i, j;
  int width, slen, blanks;
  register unsigned char *istr, *ostr, *ret;

  if(st_num_arg >= 2)
  {
    if(st_num_arg == 3)
    {
      blanks = sp->u.number;
      pop_stack();

      if(blanks < 0)
        blanks = 0;
    }
    else
      blanks = 4;

    width = sp->u.number;
    pop_stack();

    if(width < 2)
      width = 64;

    if(width - blanks < 2)
    {
      width = 64;
      blanks = 4;
    }
  }
  else
  {
    blanks = 4;
    width = 64;
  }

  istr = sp->u.string;
  slen = SVALUE_STRLEN(sp);

  if(slen < blanks)
    blanks = 0;

  i = blanks;

  ostr = ret = new_string(slen+slen/width+blanks, "f_cwrap");

  while(blanks--)
    *ostr++ = ' ';

  while(*istr)
  {
    if(*istr == '\n')
    {
      istr++;
      continue;
    }

    if(istr[0] == 27 && istr[1] == '[')
    {
      j=2;

      while(istr[j] && (isdigit(istr[j]) || istr[j]==';'))
        j++;

      if(istr[j++] == 'm')
      {
        while(j--)
          *ostr++ = *istr++;

        continue;
      }
    }

    i++;
    *ostr++ = *istr++;

    if(is_B51((unsigned char)*(istr-1)))
    {
      i++;
      *ostr++ = *istr++;
    }
    else if((unsigned char)*(istr-1) == '\t')
           i += 4;

    if(i >= width)
    {
      *ostr++ = '\n';
      i = 0;
    }
  }

  *ostr = '\0';

  ostr = string_copy(ret, "f_cwrap");
  FREE_MSTR(ret);

  free_string_svalue(sp);
  put_malloced_string(ostr);
}
#endif

#ifdef F_BG5CC
void f_bg5cc PROT((void))
{
  char *istr, *ostr, *ret;
  unsigned char s;

  istr =  sp->u.string;

  if(SVALUE_STRLEN(sp) == 0)
    push_number(0);

  if(!strchr(istr, '\\'))
  {
    ret = string_copy(istr, "f_bg5cc");
  }
  else
  {
    ostr = ret = new_string(max_string_length, "f_bg5cc");

    while(*istr)
    {
      *ostr++ = s = *istr++;

      if(is_B51(s))
      {
        *ostr++ = s = *istr++;

        if(s == '\\' && *istr != '\\')
          *ostr++ = s;
      }
    }

    *ostr = '\0';
  }

  free_string_svalue(sp);
  put_malloced_string(ret);
}

#endif

/*
 * BIG5 <-> GB 互轉程式修改自 CCF
 */

#ifdef F_G2B
void f_G2B PROT((void))
{
  int i;
  char *istr, *ostr;

  istr = sp->u.string;
  i = SVALUE_STRLEN(sp);

  if(i == 0)
  {
    push_number(0);
    free_string_svalue(sp);
    return;
  }

  ostr = new_string(i, "f_G2B");
  GB2Big(istr, ostr, i);

  free_string_svalue(sp);
  put_malloced_string(ostr);
}
#endif

#ifdef F_B2G
void f_B2G PROT((void))
{
  int i;
  char *istr, *ostr;

  istr = sp->u.string;
  i = SVALUE_STRLEN(sp);

  if(i == 0)
  {
    push_number(0);
    free_string_svalue(sp);
    return;
  }
  
  ostr = new_string(i, "f_B2G");
  Big2GB(istr, ostr, i);

  free_string_svalue(sp);
  put_malloced_string(ostr);
}
#endif

nosave void g2b(char *s)
{
  unsigned int i;

  if((c2 >= 0xa1) && (c2 <= 0xfe))
  {
    if((c1 >= 0xa1) && (c1 <= 0xa9))
    {
      i = ((c1 - 0xa1) * 94 + (c2 - 0xa1)) * 2;
      s[0] = GtoB[i++];
      s[1] = GtoB[i];
      return;
    }
    else if((c1 >= 0xb0) && (c1 <= 0xf7))
    {
      i = ((c1 - 0xb0 + 9) * 94 + (c2 - 0xa1)) * 2;
      s[0] = GtoB[i++];
      s[1] = GtoB[i];
      return;
    }
  }

  s[0] = GtoB_bad1;
  s[1] = GtoB_bad2;
}

nosave void b2g(char *s)
{
  unsigned int i;

  if((c1 >= 0xa1) && (c1 <= 0xf6))
  {
    if((c2 >= 0x40) && (c2 <= 0x7e))
    {
      i = ((c1 - 0xa1) * 157 + (c2 - 0x40)) * 2;
      s[0] = BtoG[i++];
      s[1] = BtoG[i];
      return;
    }
    else if((c2 >= 0xa1) && (c2 <= 0xfe))
    {
      i = ((c1 - 0xa1) * 157 + (c2 - 0xa1) + 63) * 2;
      s[0] = BtoG[i++];
      s[1] = BtoG[i];
      return;
    }
  }
  else if((c1 == 0xf7) && (c2 >= 0x40) && (c2 <= 0x55))
  {
    i = ((c1 - 0xa1) * 157 + (c2 - 0x40)) * 2;
    s[0] = BtoG[i++];
    s[1] = BtoG[i];
    return;
  }

  s[0] = BtoG_bad1;
  s[1] = BtoG_bad2;
}

nosave void Big2GB(char *istr, char *ostr, int inlen)
{
  unsigned char s[2];

#ifdef DEBUG
  debug_message("translate BIG5 to GB.\n");
#endif

  while(inlen >= 2)
  {
    s[0] = *istr++;
    s[1] = *istr++;

    if(is_B51(s[0]) && is_B52(s[1]))
    {
      b2g(s);
      *ostr++ = s[0];
      *ostr++ = s[1];
      inlen -= 2;
    }
    else
    {
      *ostr++ = s[0];
      istr--;
      inlen--;
    }
  }

  if(inlen > 0)
    *ostr++ = *istr;

  *ostr = '\0';
}

nosave void GB2Big(char *istr, char *ostr, int inlen)
{
  unsigned char s[2];

#ifdef DEBUG
  debug_message("translate GB to BIG5.\n");
#endif

  while(inlen >= 2)
  {
    s[0] = *istr++;
    s[1] = *istr++;

    if(is_GB1(s[0]) && is_GB2(s[1]))
    {
      g2b(s);
      *ostr++ = s[0];
      *ostr++ = s[1];
      inlen -= 2;
    }
    else
    {
      *ostr++ = s[0];
      istr--;
      inlen--;
    }
  }

  if(inlen > 0)
    *ostr++ = *istr;

  *ostr = '\0';
}
