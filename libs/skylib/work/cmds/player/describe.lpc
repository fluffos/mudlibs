
#include <player.h>
inherit COMMAND_BASE;

int cmd(string str) {
   string desc;

   desc = TP->query_desc();
   if (!str) {
      if (desc)
         write("Description reads:\n" + TP->query_cap_name() + " " +
               desc + "\n");
      else
         write("No description set.\n");
      return 1;
   }
   else if (str == "clear") {
      write("Description cleared.\n");
      TP->set_desc(0);
      return 1;
   }
   else if (str == "edit") {
      /*
       * The cap name is stuck on so they can see what their desc will look
       * like.
       */
      if (desc)
         this_player()->do_edit(sprintf("%-=*s", this_player()->query_cols(),
                                        this_player()->query_cap_name() + " " +
                                        replace(desc, "\n", "\n\n") + "\n"),
                                "finish_desc_edit");
      else
         this_player()->do_edit("", "finish_desc_edit");
      return 1;
   }
   else if (strlen(str) > MAX_DESC) {
      notify_fail("Description unchanged.  Given description was too long.  "
                  "Maximum allowed length is " + MAX_DESC+ ".\n");
      return 0;
   }
   TP->set_desc(str);
   write("Description set.\n");
   return 1;
}

void finish_desc_edit(string str) {
   string cname;
   
   if (!str) {
      write("Description unchanged.\n");
     return;
   }
   /* Save them some trouble if they started off with their name... */
   cname = this_player()->query_cap_name();
   if (str[0 .. strlen(cname)] == cname + " ")
      str = str[strlen(cname) + 1 .. 10000];
   str = replace(str, ({ "\n\n", "$NEW_LINE$", "\n", " " }));
   str = replace(str, "$NEW_LINE$", "\n");
   if (strlen(str) > MAX_DESC) {
      write("Description unchanged.  Given description was too long.  "
            "Maximum allowed length is " + MAX_DESC+ ".\n");
      return;
   }
   TP->set_desc(str);
   write("Description set.\n");
   return;
}

mixed *query_patterns()  {
   return ({ "", (: cmd(0) :),
             "<string'description'>", (: cmd($4[0]) :),
             "edit", (: cmd("edit") :),
             "clear", (: cmd("clear") :) });
}
