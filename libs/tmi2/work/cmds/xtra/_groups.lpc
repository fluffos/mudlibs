// The "groups" command - will show all the groups defined in /adm/etc/groups
// and list all members; those that are logged on are marked with '*'
// Note: in the case of the 'admin' group, which includes the root group,
// the root members will be filtered out so only non-root admins are shown.
// Written by Publius@TMI-2 - 8-05-93
// Modified a little by Artagel Aug 12 1993.  Grendel suggested that sprintf
// might handle the indenting better, and I thought that multiple write 
// statements meant multiple calls to receive_message() in this_player()
// which seemed like a waste of CPU to me.
// Small problem fixed by Publius on 8-24-93 - command did not respect
// invisibility to other wizards, so a non-admin wizard could find you
// with this command.
//
// Added -s option, since it was confusing . Leto 941111

#include <mudlib.h>

inherit DAEMON;

mapping groups;

void fix(string str, int grouplen);

int cmd_groups(string str)
{
   string output;
   string line, *group, *names, name;
   int counter, counter2, invis;
   object who;

   groups=master()->query_groups();
//   groups["admin"]=filter_array(groups["admin"], "filter_root",
//                            this_object());
   group=sort_array(keys(groups), "do_alpha", this_object());

   output = sprintf("Groups and their members on %s:\n",
                capitalize(MUD_NAME));

   for(counter=0; counter<sizeof(group); counter++)
   {
if( (str=="-s") && ( sizeof( groups[ group[counter] ] ) < 2 ) ) continue;
      groups[group[counter]]=sort_array(groups[group[counter]],
                  "do_alpha", this_object());
      line="";
      for(counter2=0; counter2<sizeof(groups[group[counter]]); counter2++)
      {
         name=groups[group[counter]][counter2];
         who=find_player(name);
         if(who && visible(who, this_player()))
            line+="*";
         line+=capitalize(name)+" ";
      }
      output += sprintf("%s: %-=65s\n", group[counter], line);
   }
   write(output + "(\"*\" = currently logged on)\n");
   return 1;
}

int do_alpha(string str1, string str2)
{
   return strcmp(str1, str2);
}

int filter_root(string who)
{
   if(member_array(who, groups["root"])>-1)
      return 0;
   return 1;
}

int help()
{
    write("Usage: groups [-s]\n\n"+
         "This command will list all groups recognized by the master\n"+
         "object and the members of those groups. Those who are currently\n"+
         "logged in are marked with \"*\"\n"+
         "NB1: Members of the \"root\" group are filtered out of the\n"+
         "     \"admin\" group to show the distinction.\n"+
          "NB2: Groups with a single member are not shown when\n"+
         "     using the -s option, suce they usually refer to domains.\n");
   return 1;
}
