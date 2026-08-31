//  Command _posting.c
//  Written by Hanse@Nightmare 6/21/93
 
#include <std.h>
inherit DAEMON;
 
int cmd_posting(string str) {
   object *list;
   int i;
 
   if(str) return 0;
   list=users();
   write("\nList of users in various editors:\n");
   for(i=0;i<sizeof(list);i++)
      if(!list[i]->query_invis() && list[i]->query_name())
         if(present("mailer", list[i]))
             printf("%s - In mailer.\n",
                arrange_string( (string)list[i]->query_cap_name(), 20));
         else if(in_edit(list[i]) || in_input(list[i]))
             printf("%s - Editing.\n",
                arrange_string( (string)list[i]->query_cap_name(), 20));
   return 1;
}
 
void help() {
   write(@END
Syntax: posting
Displays if a user is in editor, posting on a bulletin board, or in the
mailer.
END
);
}
