//From ICF
// Inherit this if you want to write your own guild

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
  guild_name = "";
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
  add_action("join","join");
  add_action("leave","leave");
  add_action("cost","cost");
  add_action("advance","advance");
  add_action("list","list");
}

nomask int
advance(string arg) {
  int ret;
  string stat;
  if(!member_guild())
    return notify_fail("You are not a member, you can't advance here.\n");
  if(!arg || arg == "level") {
    ret = GUILD_D->advance_level();
   if (ret == -1 ) return 1;
   else if (ret == -2 ) {
      write("This is not a registered guild.\n");
      return 1;
    } else if(!ret) {
      write("You don't have enough experience to advance your level.\n");
      return 1;
    }
    write("Congratulations, you are now level "+ret+"!\n");
    say((string)this_player()->query("cap_name")
     +" is now level "+ret+".\n");
    extra_advance(ret);
    return 1;
  }
  arg = lower_case(arg);
  switch(arg) {
    case "str" :
    case "strength" :
      stat = "strength";
      ret = GUILD_D->advance_str();
      break;
    case "int" :
    case "intelligence" :
      stat = "intelligence";
      ret = GUILD_D->advance_int();
      break;
    case "dex" :
    case "dexterity" :
      stat = "dexterity";
      ret = GUILD_D->advance_dex();
      break;
    case "con" :
    case "constitution" :
      stat = "constitution";
      ret = GUILD_D->advance_con();
      break;
    case "spirit" :  
            stat = "spirit" ;
         ret = GUILD_D->advance_spirit();
      break;
    default :
      return notify_fail("I dont think I can advance that one.\n");
  }
  if(!ret) {
    write("You dont have enough experience to advance your "+stat+".\n");
    return 1;
  } else if (ret == -2) {
    write("This is not a registered guild.\n");
    return 1;
  } else if (ret == -1) {
    write("You can't advance your stats any higher until you go up a level.\n");
    return 1;
  } else if (ret == -4) {
    write("You can't advance that stat any higher.\n");
    return 1;
  } else if (ret == -3) {
    write("You don't have enough experience to raise that stat.\n");
    return 1;
  }
  write("Your "+stat+" is now "+ret+".\n");
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

int
list(string num) {
  string qnumber;
  if(num && (sscanf(num, "%s", qnumber) == 1))
    QUEST_D->list_quests(qnumber);
  else QUEST_D->count();
  return 1;
}
