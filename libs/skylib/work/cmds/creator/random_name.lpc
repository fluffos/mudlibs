#include <random_names.h>
inherit COMMAND_BASE;

string lang_list;

void create() {
  lang_list = implode((string *)RANDOM_NAME_GENERATOR->query_languages(), "|");
} /* create() */

mixed cmd(string pattern, string my_lang) {
  string *langs;
  int i;

  if (pattern == "") {
    write("Generating one word from each language.  To generate more "
          "words in a particular language, specify the language on the "
          "command line.\n");
    langs = (string *)RANDOM_NAME_GENERATOR->query_languages();
    for (i=0;i<sizeof(langs);i++)
      write(capitalize(langs[i])+": "+
            (string)RANDOM_NAME_GENERATOR->random_name(langs[i])+"\n");
    return 1;
  }
  write("Generating 10 names in "+my_lang+"\n\n");
  for (i=0;i<10;i++)
    write( (string)RANDOM_NAME_GENERATOR->random_name(my_lang)+"\n");
  return 1;
} /* cmd() */

mixed *query_patterns() {
  return ({ "", (: cmd($5, "") :),
            "{"+lang_list+"}", (: cmd($5, $4[0]) :) });
} /* query_patterns() */
