//#pragma save_binary

/*
 * parse and load in the group file
 * 
 * wayfarer 2/20/92
 */
#include <uid.h>

#define GROUP_FILE "/adm/etc/groups"

// This is noisy...
// #define DEBUG

 mapping groups;

string remove_whitespace (string members)
{
  members = replace_string(members, " ", "");
  members = replace_string(members, "\t", "");
  return members;
}

int load_groups()
{
  string *tmp, *lines, *memlist;
  string file, oneline, name, members;
  string tmpstr;
  string *tmplist;
  mapping oldgroups;
  int i, j;

  seteuid(getuid());
#ifdef DEBUG
  write("Seteuid stage completed.  Euid is now " + 
    geteuid(this_object()) + ".\n");
#endif
  /* save the old groups */
  oldgroups = groups; 
  groups = ([]);
#ifdef DEBUG
  write("Reading group file.\n");
#endif
  file = read_file (GROUP_FILE);
  tmp = explode(file,"\n");
  lines = ({});
  oneline = 0;
#ifdef DEBUG
  write("Processing group file contents.\n");
#endif
  for (i = 0; i < sizeof(tmp); i++)
    {
      if (tmp[i][0] == '#' || tmp[i][0] == '\n' || tmp[i] == "")
	continue;
      if (!oneline)
	oneline = tmp[i];
      else 
	oneline += tmp[i];
      if (tmp[i][strlen(tmp[i])-1] != ':') 
	{
	  lines += ({oneline});
	  oneline = 0;
	}
    }
#ifdef DEBUG
  write("Entering second loop of group file processing.\n");
#endif
  for (i = 0; i < sizeof(lines); i++)
    {
      if(sscanf (lines[i],"(%s)%s",name,members) != 2)
	continue;
      members = remove_whitespace(members) + ":";
      tmp = explode(members,":");
      memlist = ({});
      for (j = 0; j < sizeof(tmp); j++)
	{
	  if (tmp[j][0] == '(')
	    {
	      sscanf(tmp[j],"(%s)",tmpstr);
	      tmplist = groups[tmpstr];
	      if (!tmplist)
		{
		  notify_fail("Parse error in group: "+name+"\n"+
			      "Group "+tmp[j]+" not defined.\n"+
			      "Aborting parse.\n");
		  groups = oldgroups;
		  return 0;
		}
	      memlist += tmplist;
	    }
	  else
	    memlist += ({tmp[j]});
	}
#ifdef DEBUG
      write("Adding a new mapping to the group mapping.\n");
#endif
      groups += ([ name : memlist]);
    } // for (i = 0; i < sizeof(lines); i++)
   return 1;
}


mapping query_groups() 
{ 
  return copy(groups);
}

int query_member_group(string member,string group)
{
  if (!groups) {
    load_groups();
  }
  if (groups[group])
    return member_array(member, groups[group]) + 1;
  else
    return 0;
}
