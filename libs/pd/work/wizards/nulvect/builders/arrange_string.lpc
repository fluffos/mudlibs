//     /adm/simul_efun/arrange_string.c
//     from the Nightmare mudlib
//     makes a string a certain length
//     created by Descartes of Borg 23 december 1992
//     modified to take into account ansi colour :) codes
//       by Blodgett 10 september 1993 (europosis!)
//
//     completely rewritten by Nulvect 2006-09-10 to make it _actually_
//     work with color codes and to fix a major bug that crashed the mud
//     also added the strip_color sefun

string strip_color(string str) {
  string ret = "";
  string code = "%^";
  string *tmp;
  int flag;
  
  if (!str || str == "")
    return "";

  tmp = explode(str, code);

  if (strsrch(str, code) == 0) flag=1;
  else flag=0;

  for (int i=flag; i<sizeof(tmp); i+=2)
    ret += tmp[i];
  
  return ret;
}

string arrange_string(string str, int x) {
  int actuallen, vislen, codelen;
  string code = "%^";

  if(!str || str == "" || !intp(x) || x < 1)
    return "";

  if(intp(str)) 
    str = str+"";
  
  actuallen = strlen(str);
  vislen = strlen(strip_color(str));
  codelen = actuallen - vislen;
  if (codelen < 0) codelen=0; // should be impossible, but just in case

  // shrinking a string...
  if (vislen > x) {
    // shrinking a string with no color
    if (!codelen)
      str = str[0..x-1];
    // shrinking a string that has color, might be slow due to explode/implode
    else {
      string *tmp;
      int i, count, flag;

      tmp = explode(str, code);

      if (str[0..sizeof(code)-1] == code) flag=0;
      else flag=1;

      for (i = 0, count=0; i < sizeof(tmp) && count < x; i++) {
        if (i%2 != flag)
          count += sizeof(tmp[i]);
      }

      i--;

      if (i%2 != flag)
        tmp[i] = tmp[i][0..<(count-x+1)];
      else
        tmp[i] = tmp[i] + code;

      str = implode(tmp[0..i], code);
      if (flag == 0)
        str = code + str;
      
    }
  }
  // expanding a string by adding spaces
  else if (vislen < x)
    for (int i=vislen; i<x; i++)
      str += " ";

  return str;
}
