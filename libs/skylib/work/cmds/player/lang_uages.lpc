
#include <move_failures.h>
#include <language.h>

inherit COMMAND_BASE;

mixed cmd(object *obs, string indir, string str) {
   int i;
   string *langs;

   langs = LANGUAGE_HAND->query_languages();
   for (i = 0; i < sizeof(langs); i++) {
      if (TP->query_skill(
               LANGUAGE_HAND->query_language_spoken_skill(langs[i])) > 1 ||
          TP->query_skill(
               LANGUAGE_HAND->query_language_written_skill(langs[i])) > 1) {
      } else {
         langs = langs[0..i-1] + langs[i+1..];
         i--;
      }
   }

   write("You can currently speak " +( TP->query_womens_day()?"wommon":
                 implode(langs, ", ") ) +" and grunt.\n");
   return 1;
}

