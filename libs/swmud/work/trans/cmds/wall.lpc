//:COMMAND
// Sends a broadcast message to anyone and everyone on the mud
// Admin use only
// Usage:  wall <message>
#include <mudlib.h>
#include <log.h>

inherit CMD;
inherit M_GRAMMAR;

#define SYNTAX  "Usage: wall <message>\n"

void create()
{
   ::create();
   no_redirection();
}

private void main(string arg)
{
   string broadcast;

   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      write("Must be a Wizard Master or Teacher to use wall.\n");
      return;
   }

   if (!sizeof(arg))
   {
      write(SYNTAX);
      return;
   }

   broadcast = sprintf("System message from %s at %s:\n    %s\n",
      this_body()->query_name(), ctime(time()), punctuate(arg));

   LOG_D->log(LOG_WALL, broadcast);

   tell(users(), broadcast, MSG_INDENT);
}