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
//
//    2008-01-15 greatly simplified all color handling

string strip_color(string str) {
  return terminal_colour( ( str ? str : "" ), TERMINAL_D->query_term_info("unknown"));
}

string arrange_string(string str, int x) {
  int actuallen, vislen, codelen;
  string code = "%^";

  if(!str || str == "" || !intp(x) || x < 1)
    return "";

  if(intp(str)) 
    str = str+"";
  
  str = wrap(str, x);
  str = str[0..strsrch(str, "\n")-1];

  for (int i = strlen(strip_color(str)); i < x; i++)
    str += " ";

  return str;
}
