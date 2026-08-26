// Last edited by deforce on 11-25-2007
//:PLAYERCOMMAND
//USAGE: describe
//
// This command lets you enter the description people see when they look at you.
#include <commands.h>
#include <mudlib.h>

inherit CMD;
inherit M_INPUT;

#define MAX_DESCRIP_SIZE 6

private string* descrip = ({});

private void end_describe()
{
   if (!sizeof(descrip))
   {
      this_body()->set_description("");
      write("Description removed.\n");
   }
   else
   {
      this_body()->set_description(implode(descrip, "\n"));
      write("Description changed.\n");
   }

   destruct();
}

private void receive_line(string input)
{
   if (input == ".")
   {
      modal_pop();
      end_describe();
      return;
   }

   if (input == "~q")
   {
      write("Describe has not been changed.\n");
      modal_pop();
      destruct();
      return;
   }

   descrip += ({input});

   if (sizeof(descrip) == MAX_DESCRIP_SIZE)
   {
      write("Maximum lines reached.  Terminating input.\n");
      modal_pop();
      end_describe();
   }
}

nomask void begin_describing()
{
   if (previous_object() != find_object(CMD_OB_DESCRIBE))
   {
      error("Invalid attempt to use describe.\n");
   }

   modal_push((: receive_line :), "");
}


void create()
{
   ::create();
   no_redirection();
}

private void main(string s)
{
   if (stringp(s) && strlen(s))
   {
      descrip = explode(s, "\n");
      end_describe();
      return;
   }

   out("Describe yourself in " + MAX_DESCRIP_SIZE + " lines or less.\n"
      + "Type '.' on the next line when finished.\n"
      + "Type '~q' to quit without saving.\n"
      + "-----------------------------------------\n");

   new(CMD_OB_DESCRIBE)->begin_describing();
}