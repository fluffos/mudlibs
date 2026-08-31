/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Governance daemon for controlling elections and governance
** for many different things.
** Tsath 2020 (another Covid-19 lock-up creation)
*/

inherit M_DAEMON_DATA;
inherit M_WIDGETS;

private
mapping leaders = ([]);
private
mapping managers = ([]);

mapping copy_leaders()
{
   return copy(leaders);
}

mapping copy_managers()
{
   return copy(managers);
}

void set_leader(string what, string leader)
{
   leaders[what] = leader;
   save_me();
}

string query_leader(string what)
{
   return leaders[what];
}

void add_manager(string what, string manager)
{
   if (!managers[what])
      managers[what] = ({});
   managers[what] += ({manager});
   save_me();
}

int remove_manager(string what, string manager)
{
   int s = sizeof(managers[what]);
   if (!managers[what])
      return;
   managers[what] -= ({manager});
   save_me();
   return sizeof(managers);
}

string *query_managers(string what)
{
   return managers[what] || ({});
}

string leader_board()
{
   string out = "";
   out += sprintf("  %-16s  %-20s %-s\n", "Association", "Leader", "Managers");
   out += simple_divider();
   foreach (string assoc, string leader in leaders)
   {
      string *mngrs = map(query_managers(assoc), ( : capitalize($1) :));

      out += sprintf("  %-16s  %-20s %-s\n", capitalize(assoc), capitalize(leader), implode(mngrs, " "));
   }

   return out;
}

void create()
{
   ::create();
}
