#include <std.h>

inherit DAEMON;
int query_wizard(object fucker);
void print_wizard(object dickweed);

int cmd_wizards(string str) {
   object *wizards;
   int i;
   printf("\n");
   wizards = filter_array(users(), "query_wizard", this_object());
   for (i=0; i<sizeof(wizards); i++)
      print_wizard(wizards[i]);
   return 1;
}

int query_wizard(object fucker)
   {
   if (wizardp(fucker))
      return 1;
   return 0;
   }

void print_wizard(object dickweed)
   {
   string spooge;
   spooge = capitalize(dickweed->query_true_name());
   printf("%s the %s:\n", spooge, dickweed->query_position());
   if (dickweed->query_invis())
      printf("\t%s is invisible.\n", spooge);
   if (query_idle(dickweed) > 60)
      printf("\t%s is idle. (what an asshole)\n", spooge);
   if (in_edit(dickweed))
      printf("\t%s is editing. (aaaah! Coding! Wrong! Evil!)\n", spooge);
   if (environment(dickweed))
      printf("\t%s is in %s.\n", spooge, file_name(environment(dickweed)) );
   }
int help() {
    write("Shows list of wizards on the mud\n");
}

