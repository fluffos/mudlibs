
//      /adm/simul_efun/wrap.c
//      Part of the TMI distribution mudlib and now Nightmare's
//      Inserts "\n"'s into text so lines arn't wider than screens
//      Author unknown, but thanks to the MudOS driver team for sprintf
//      Moved to Nightmare by Pallando 93-05-28

#define SZ 80
#include <daemons.h>

varargs string wrap2(string str, int width);
varargs string wrap(string str, int width);

varargs string wrap(string str, int width) {
 string wrapped, junk;
 string *parsed;
 int a, b, cnt = 0;

 if (!width) width = SZ;
 return terminal_colour(str, TERMINAL_D->query_term_info("ansi-status"),width, 0)+"\n";
 wrapped = "--";
 b = sizeof ( parsed = explode(str, " ") );
 if (!a) return str;
 if (!sscanf(str, "%%^%s%%^", junk)) return wrap2(str, width);
 for (a=0; a < b; a++)
    { 
      if (cnt + sizeof(TERMINAL_D->no_colours(parsed[a])) > width) 
        {
          wrapped += "\n"+parsed[a];
          cnt = 0;
          continue;
        }
      cnt += sizeof(TERMINAL_D->no_colours(parsed[a]));
      wrapped += parsed[a];
    }
 return (wrapped+"\n"); 
} 
 
varargs string wrap2(string str, int width) {
 
	if (!width) return sprintf("%-="+SZ+"s", str + "\n");
	else return sprintf("%-="+width+"s", str + "\n");
}

