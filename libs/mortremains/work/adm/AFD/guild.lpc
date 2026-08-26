#include <quest.h>
#include <daemons.h>
#define DEBUG 0
// guild.c - The standard guild.  Inherit this for your guild hall.

// The only people who can advance here are those with the property
// "guild_string" set to the filename of this object!

#include <mudlib.h>
#include <daemons.h>
#include <levels.h>

inherit ROOM;

private string guild_string;
string guild_name;

void extra_advance(int level);

void
create() {
  ::create();
  guild_string = file_name(this_object());
}

string
query_guild_string() {
  return guild_string;
}

nomask int
member_guild() {
  string guild;
  guild = (string)this_player()->query("guild_string");
  if(!guild || guild == "") {
    if(guild_string == ADV_GUILD)
      return 1;
    return 0;
  }
  if(guild == guild_string) return 1;
  return 0;
}

init() {
  add_action("register", "register");
  add_action("join","join");
  add_action("leave","leave");
  add_action("cost","cost");
  add_action("advance","advance");
  add_action("dump_levels", "levels");
  add_action("list","list");
}

nomask int dump_levels(string str) {
 int work ;
  if (!wizardp(TP)) return 0;
  if (str) {
  if (sscanf(str, "%d", work)!=1) {
     write("Usage: levels [highest level you'd like to see]\n");
     return 1;
  }
  }
  else work = 99;
  if (work<20) work = 20;
 GUILD_D->dump_levels(work);
  return 1;
}

nomask int register() {
  if (wizardp(TP)) {
  write("Go make your own title, Wizard!  Don't you have some coding to do?\n");
   return 1;
  }
  if (!member_guild()) {
   write("You are not a member, why would you want these titles?\n");
    return 1; 
  }
  write("Your title has been fixed.\n");
  extra_advance((int)this_player()->query_level());
  TP->force_me("save") ;
  return 1;
}
nomask int
advance(string arg) {
  int ret;
  string stat;
  if(!member_guild())
    return notify_fail("You are not a member, you can't advance here.\n");
  if (!arg) return notify_fail("Advance what?\n");
  if (arg == "level") {
  if (wizardp(this_player())) {
    return notify_fail("You're a wizard, get outta here!\n");
   }
    ret = GUILD_D->advance_level();
    if(ret == -1) {
      write("You can not advance your level any higher.\n");
      return 1;
    } else if (ret == -2) {
      write("This is not a registered guild.\n");
      return 1;
    } else if (ret == -3) {
  write("You must solve the following quest before advancing your level:\n");
  write(QUEST_D->query_short_for_quest(this_player()->query_level()+1)+"\n");
      return 1;
    } else if (!ret) {
      write("You don't have enough experience to advance your level.\n");
      return 1;
    }
    write("Congratulations, you are now level "+ret+"!\n");
    say((string)this_player()->query("cap_name")
     +" is now level "+ret+".\n");
    extra_advance(ret);
  write("You are now known as: '"+TP->query_title()+"'.\n") ;
   TP->force_me("save") ;
    return 1;
  }
   write("Advance what?\n");
  return 1;
}

void
extra_advance(int level) {
// use this function for setting titles etc.
  return;
}

int
cost() {
  return GUILD_D->query_costs();
}

int list(string num) {
  string qnumber;
// OOPS!
  write("The quest daemon isn't functioning yet.  Sorry. ;)\n");
  return 1;
  if(num && (sscanf(num, "%s", qnumber) == 1))
    QUEST_D->list_quests(qnumber);
  else QUEST_D->count();
  return 1;
}

