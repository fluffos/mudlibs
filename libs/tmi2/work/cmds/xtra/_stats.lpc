// file:   wizlist.c
// mudlib: Basis
// date:   1992/11/10
// author: Truilkan
// Leto added quick #ifdef check 1-1-95 (local time ;)

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int help() ;

void
header()
{
write(
"name         moves     objects  cost       errors  hb       worth    array\n"
);
write(
"---------    --------  -------  --------   ------  -------  -------  -------\n"
);
}

void
entry(string name, mapping e)
{
   printf("%-12s %8d  %7d  %8d  %7d  %7d  %7d  %7d\n", name,
      e["moves"], e["objects"], e["cost"], e["errors"], e["heart_beats"],
      e["worth"], e["array_size"]);
}

varargs mapping
get_stats(string type, string arg)
{
#ifdef HAS_MUDLIB_STATS
   if (type=="domain")
      return arg ? domain_stats(arg) : domain_stats();
   else
      return arg ? author_stats(arg) : author_stats() ;
#else

  write("Driver compiled without MUDLIB_STATS (see options.h)\n");
  return ;
#endif
}

int
cmd_stats(string arg)
{
   mapping list;
   string *makers;
   string s1, s2 ;
   int j;

   if (!arg) {
      return help() ;
   }
   sscanf (arg, "%s %s", s1, s2) ;
   if (s2) {
      if (s1!="author" && s1!="domain") {
	 return help() ;
      }
      list = this_object()->get_stats(s1,s2);
      if (!list) {
         notify_fail("makers: couldn't find " + s2 + ".\n");
         return 0;
      }
      header();
      entry(s2, list);
      return 1;
   }
   if (arg!="domain" && arg!="author") return help() ;
   list = (mapping)this_object()->get_stats(arg) ;
   makers = keys(list);
   header();
   for (j = 0; j < sizeof(makers); j++) {
      entry(makers[j], list[makers[j]]);
   }
   return 1;
}

int help() {
	write ("Usage: stats [author|domain]\n\n"+
"The stats command shows you what objects have been loaded and how\n"+
"much resources they are using. If the argument \"author\" is supplied,\n"+
"they are grouped by UID of the object that loaded them. If the argument\n"+
"\"domain\" is supplied, they are grouped by domain UID. Or something\n"+
"like that, anyway.\n"+
"The driver needs to have been compiled with MUD_STATS defined,\n"+
"if you want useful information returned here.\n"+
"See also: man pages on domain_stats and author_stats.\n") ;
	return 1 ;
}
