/* Do not remove the headers from this file! see /USAGE for more info. */

// Tsath 2024

//: COMMAND
// USAGE ``governance``
//
// Shows leaders and manager for all guilds on the MUD.
// Can also set managers and leaders. Use:
//
//    governance <guild name>
//
// and follow the prompts.
//
// .. TAGS: RST

inherit CMD;
inherit M_INPUT;

#define PROMPT "[larpq]>"

private
mapping leaders;
private
mapping managers;
private
string *guilds;

private
int valid_entry(string s)
{
   return member_array(s, ({"l", "r", "a", "q", "p"})) != -1;
}

private
void print_prompt()
{
   out("Options:\n\tl - change leader      a - add manager     r - remove manager\n\tp - print all guilds   q - quit");
}

private
string print_guild(string g)
{
   string output = "";
   output += "<154>[" + upper_case(g) + "]<res> - members online: " + sizeof(GUILD_D->belongs_to(g)) + "\n";
   output += "\t<226>Leader:<res> " + (leaders[g] ? capitalize(leaders[g]) : "None") + "\n";
   output += "\t<226>Managers:<res> " +
             (managers[g] ? implode(map(managers[g], (
                                                         : capitalize($1)
                                                         :)),
                                    ", ")
                          : "None") +
             "\n";
   output += "\n";
   return output;
}

private
cache_governance()
{
   leaders = GOVERNANCE_D->copy_leaders();
   managers = GOVERNANCE_D->copy_managers();
   guilds = clean_array(keys(leaders) + keys(managers) + GUILD_D->query_guilds());
}

private
void print_guilds()
{
   foreach (string g in guilds)
      write(print_guild(g));
}

private
varargs void gather_info(string g, int step, string last, string s)
{
   // TBUG("Guild: "+g + " Step: " + step + " Last: " + last + " String: " + s);
   switch (step)
   {
   case 0:
      write(print_guild(g));
      print_prompt();
      break;
   case 1:
      if (!valid_entry(s))
      {
         if (strlen(s))
            write("** Invalid option '" + s + "', 'q' to quit.\n");
         modal_simple(( : gather_info, g, 1, "" :), PROMPT);
         return;
      }
      if (s == "p")
      {
         print_guilds();
         modal_simple(( : gather_info, g, 1, "" :), PROMPT);
         return;
      }
      if (s == "q")
         return;
      modal_simple(( : gather_info, g, 2, s:), "Enter name >");
      break;
   case 2:
      if (last == "l")
      {
         GOVERNANCE_D->set_leader(g, s);
         write("Leader for " + g + " set to " + s + ".");
      }
      else if (last == "a")
      {
         GOVERNANCE_D->add_manager(g, s);
         write("Manager " + s + " added to " + g + ".");
      }
      else if (last == "r")
      {
         if (GOVERNANCE_D->remove_manager(g, s))
            write("Manager " + s + " removed from " + g + ".");
         else
            write("** Failed to remove manager " + s + " from " + g + ".");
      }

      cache_governance();
      gather_info(g, 0, "");
      modal_simple(( : gather_info, g, 1, "" :), PROMPT);
      break;
   }
}

void main(string arg)
{

   // ### Ew, globals
   cache_governance();

   if (strlen(arg) && member_array(arg, guilds) != -1)
   {
      gather_info(arg, 0, "");
      modal_simple(( : gather_info, arg, 1, "" :), PROMPT);
      return;
   }

   print_guilds();
}
