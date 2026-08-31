/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_WIDGETS;

string guild;
mapping contrib;

void setup(string g)
{
   set_id("open ledger", "ledger");
   set_attached(1);
   set_long("It's the ledger of " + capitalize(g) + ", try reading it?");
   guild = g;
}

void read_entry(string s)
{
   string long_desc = "";
   string *logs = GUILD_D->guild_log(guild);

   if (!sizeof(logs))
   {
      write("The ledger is blank.\n");
      return;
   }
   long_desc += simple_divider();
   long_desc += "%^YELLOW%^" + implode(explode(upper_case(guild), ""), " ") + "%^RESET%^ - Ledger.\n\n";

   foreach (string l in logs)
   {
      long_desc += l + "\n";
   }
   long_desc += simple_divider();

   more(long_desc);
}

void read()
{
   read_entry(0);
}

mixed direct_read_obj()
{
   return 1;
}