
//      /adm/simul_efun/wrap.c
//      Part of the TMI distribution mudlib and now Nightmare's
//      Inserts "\n"'s into text so lines arn't wider than screens
//      Author unknown, but thanks to the MudOS driver team for sprintf
//      Moved to Nightmare by Pallando 93-05-28
//
//      2008-01-15 greatly simplified color handling - Nulvect

#define SZ 80
#include <daemons.h>

varargs string wrap2(string str, int width);
varargs string wrap(string str, int width);

varargs string wrap(string str, int width, int indent) {

  if (nullp(str)) return "";
  if (nullp(width)) width = SZ;
  if (nullp(indent)) indent = 0;

  return terminal_colour(str, TERMINAL_D->query_term_info("wrap"), width, indent)+"\n";
} 
 
varargs string wrap2(string str, int width) {
 
	if (!width) return sprintf("%-="+SZ+"s", str + "\n");
	else return sprintf("%-="+width+"s", str + "\n");
}

