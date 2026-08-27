/* source file -- Guildmaster's Office */
#include "path.h"

  /* inheritance */
inherit "/d/ss/daggerford/thieves/vthief_guild";

  /* global variables */
string tmp_msg;

  /* function definitions */
void setup()
{
  set_short("Guildmaster's Office");
  set_long("The floor of this office is tiled with marble flagstones, "+
    "the ceiling is plastered with stucco, and the walls are ornamented "+
    "with friezes.  A large desk occupies the center of the room with "+
    "two chairs in front of it and a big, ornate chair behind it.  "+
    "The room is lit by a small lamp that stands atop the desk.\n");
  set_light(70);
  set_zone("private");

  add_item( ({"frieze", "friezes"}),
    "The friezes enact some unknown legends of warriors, wizards, "+
    "priests, and rogues.  Not only do they struggle against "+
    "powerful monsters, but each other as well.\n");
  add_item( "desk", "The large black desk is artistically carved "+
    "and enladen with colorful veins of mineral.  An assortment of "+
    "journals and booklets are stacked on the desktop as well as "+
    "other utensils for scribing.\n");
  add_item("lamp", "There is nothing particulary interesting about "+
    "the oil lamp other than the fact that it is burning.\n");
  add_item( ({"journals", "booklets"}),
    "The journals are simply legers for common guild business.\n");
  add_exit("north", ROOM + "treasury", "door");
  add_exit("south", ROOM + "chambers", "door");
  add_exit("west", ROOM + "hall4", "door");
  set_save_file("/d/ss/daggerford/thieves/black_masks");
}

void init() {
  ::init();
  add_action("do_edit", "edit");
}

int do_edit(string str) {
  string name, guildmaster;
  string *officers, *patrons;

  name = this_player()->query_name();
  guildmaster = query_guildmaster();
  officers = query_guild_officers();
  patrons = query_guild_patrons();
  if (name != guildmaster)
    if (member_array(name, patrons) == -1)
      if (member_array(name, officers) == -1) {
        notify_fail("You don't have clearance to make changes "+
          "to this guild.  Contact the guildmaster, an officer, "+
          "or hope that a patron will answer your summons.\n");
        return 0;
      }
  switch (str)
  {
    case "protect": case "restrict": case "protections":
      printf("\nEnter a player's name and the number of exempt days "+
        "to add him/her to the list.\nEnter a player's name to "+
        "remove him/her from the list.\nEnter nothing to list the "+
        "current protections.\n: ");
      input_to("do_protect");
      return 1;
    case "message":
      if (member_array(name, patrons) == -1)
      if (name != guildmaster) {
        notify_fail("The guild message is for the guildmaster only.\n");
        return 0;
      }
      tmp_msg = "";
      printf("\nEnter your message for the guild.  Terminate with "+
        "'**'.\n] ");
      input_to("do_message");
      return 1;
    case "officers":
      if (member_array(name, patrons) == -1)
        if (name != guildmaster) {
          notify_fail("Only the guildmaster can offically change "+
            "the offices of the guild.\n");
          return 0;
        }
      printf("\nEnter a player's name and the exact office title "+
        "to change the office.\nSeperate the name and title with "+
        "a comma.\nEnter the office title to remove the office.\n"+
        "Enter nothing to list the current officers.\n: ");
      input_to("do_officers");
      return 1;
    case "members":
      printf("\nEnter a player's name to add/remove him or her from "+
        "the roster.\nEnter nothing to list the current roster.\n: ");
      input_to("do_members");
      return 1;
    default:
      notify_fail("Available edit options are 'protections', "+
        "'message', 'officers', and 'members'.\n");
      return 0;
  }
}

int do_protect(string str) {
  mixed *protect;
  int i, n;
  string name;

  if (!str || str == "") {
    printf("\nCurrent Player Restrictions:\n");
    if (!(protect = query_protect()))
      return 0;
    if ((n = sizeof(protect)) < 1) {
      printf("Everybody is fair game.\n");
      return 1;
    }
    for (i = 0; i < n; i += 2)
      printf("  %-15s%s\n", capitalize(protect[i]), ctime(protect[i+1]));
    return 1;
  }
  if (sscanf(str, "%s %d", name, n) == 2) {
    i = add_protect(name, n);
    printf("Added %s to list until %s.\n", capitalize(name), ctime(i));
  }
  else if (sscanf(str, "%s", name) == 1) {
    remove_protect(name);
    printf("Removed %s from the list.\n", capitalize(name));
  }
  return 1;
}

int do_message(string str) {
  if (str == "**") {
    set_guild_message(tmp_msg);
    printf("\nMessage saved.\n");
    return 1;
  }
  tmp_msg += str + "\n";
  printf("] ");
  input_to("do_message");
}

int do_officers(string str) {
  string *officers;
  int i, n;
  string name, office;

  if (!str || str == "") {
    printf("\nOfficers:\n");
    officers = query_guild_officers();
    if (!officers)
      return 0;
    if ((n = sizeof(officers)) < 1) {
      printf("  No officers.\n");
      return 1;
    }
    for (i = 0; i < n; i += 2)
      printf("  %s, %s\n", capitalize(officers[i]), officers[i+1]);
    return 1;
  }
  if (sscanf(str, "%s, %s", name, office) == 2)
  {
    set_guild_office(name, office);
    printf("Changed the officer of %s to %s.\n", office, capitalize(name));
  }
  else if (sscanf(str, "%s", office) == 1)
  {
    remove_guild_office(office);
    printf("Removed the office, %s.\n", office);
  }
  return 1;
}

int do_members(string str) {
  string *members;
  int i, n;

  members = query_guild_members();
  if (!members)
    return 0;
  if (!str || str == "") {
    printf("\nGuild members:\n");
    if ((n = sizeof(members)) < 1)
      printf("  No guild members.\n");
    for (i = 0; i < n; i += 4) {
      printf("  %-15s", capitalize(members[i]));
      if (i+1 < n)
        printf("%-15s", capitalize(members[i+1]));
      if (i+2 < n)
        printf("%-15s", capitalize(members[i+2]));
      if (i+3 < n)
        printf("%-15s", capitalize(members[i+3]));
      printf("\n");
    }
    return 1;
  }
  str = lower_case(str);
  if (member_array(str, members) == -1) {
    add_guild_member(str);
    printf("Added %s to the roster.\n", capitalize(str));
  } else {
    remove_guild_member(str);
    printf("Removed %s from the roster.\n", capitalize(str));
  }
  return 1;
}


