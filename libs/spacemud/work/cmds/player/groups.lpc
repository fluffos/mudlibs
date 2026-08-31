/* Do not remove the headers from this file! see /USAGE for more info. */

// More Crypic #@$t from Belboz
//

// : PLAYERCOMMAND
// USAGE
// ``groups [-a | -d] [groupname] [name 1] [name 2] ...``
//
// The groups command allows you to add personal groups that may
// be used to alias a group of people, generally for sending mail.
//
// No flag:  Shows the mud's standard groups and your private groups.
//
// |   -a :  Adds a group to your groups info, along with a list of
// |         at least 1 name, all separated by spaces.
// |   -d :  Deletes a group, or if you give a list of names, deletes
// |         that list from the specified personal group.
//
// .. TAGS: RST

inherit CMD;
inherit M_FRAME;

#define SYNTAX "Usage: groups [-a | -d] [groupname] [name 1] [name 2] ... \n"

private
nomask string *print_groups(mapping groups);

private
void main(string arg)
{
   mapping groups;
   string this_group;
   string output = " \n";
   string header;
   mixed valid;
   mixed not ;
   string *arglist;

   frame_init_user();
   set_frame_title("Mail Groups");
   set_frame_left_header();
   header = title(mud_name()) + "\n";
   groups = this_body()->query_perm("groups");
   if (!groups)
      groups = ([]);
   if (!arg || arg == "")
   {
      string *sarg = print_groups(GROUP_D->get_group_data());
      header += sarg[0];
      output += sarg[1];
      header += "\n" + title(this_body()->query_name()) + "<res>\n";

      if (!mapp(groups) || !sizeof(groups))
         output += "\nYou have no groups defined.\n";
      else
         output += " \n\n";

      sarg = print_groups(groups);
      header += sarg[0];
      output += sarg[1];
      set_frame_header(header);
      set_frame_content(output);
      out(frame_render());
      return;
   }

   arglist = explode(arg, " ");

   if (sizeof(arglist) < 2 || (arglist[0] != "-a" && arglist[0] != "-d"))
   {
      out(SYNTAX);
      return;
   }

   this_group = arglist[1];
   if (arglist[0] == "-a")
   {
      if (sizeof(arglist) < 3)
         out(SYNTAX);

      arglist = filter_array(
          arglist[2..],
          function(string x, string this_group, string * grp_members) {
             if (arrayp(grp_members) && member_array(grp_members, x) != -1)
             {
                outf("%s is already in group %s.\n", x, this_group);
                return;
             }
             else
             {
                outf("%s added to group %s.\n", x, this_group);
                return 1;
             }
          },
          this_group);

      arglist = clean_array(arglist);

      this_body()->set_perm("groups",
                            groups + ([this_group:arglist ? (mixed)arglist : (mixed)(([]) + groups[this_group]), ]));
      return;
   }

   if (sizeof(arglist) == 2)
   {
      if (groups[arglist[1]])
      {
         map_delete(groups, arglist[1]);
         outf("Group %s nuked.\n", arglist[1]);
         return;
      }
      outf("You have no defined group called '%s'!\n", arglist[1]);
      return;
   }
   arglist = arglist[2..];
   if (!groups[this_group])
   {
      outf("Group %s does not exist.\n", this_group);
      return;
   }
   valid = filter_array(arglist, ( : member_array($1, $(groups[this_group])) != -1 :));
   not = clean_array(arglist - valid);
   valid = clean_array(valid);

   if (sizeof(not ))
      out(sprintf("Unable to remove: %s.\n", implode(not, ", ")));

   if (sizeof(valid))
   {
      out(sprintf("Removed: %s from %s.\n", implode(valid, ", "), this_group));
      groups[this_group] -= valid;
      if (!sizeof(groups[this_group]))
         map_delete(groups, this_group);
      this_body()->set_perm("groups", groups);
      return;
   }
   out(frame_render());
}

private
nomask string *print_groups(mapping groups)
{
   string header = "";
   string content = "";
   foreach (string k, string * members in groups)
   {
      header += sprintf("%s\n", k);
      content += sprintf("%s\n", implode(map_array(sort_array(members, 1), ( : capitalize:)), ", "));
   }

   return ({header, content});
}
