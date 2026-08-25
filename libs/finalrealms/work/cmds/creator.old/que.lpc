
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
  {
  position = 1;
}

protected int cmd(string str, object me)
  {
  string guild;
  object victim;

  if (!str)
  {
    notify_fail("Syntax: que <someone>\n");
    return 0;
  }
  
  if (!victim = find_player(str))
  {
    notify_fail("Not here.\n");
    return 0;
  }

  guild = (string)victim->query_guild_ob();
  //guild->set_main_skill("wis");
  write ("Playername: " + (string)victim->query_name() + "\n");
  write ("Body AC mod: " + (string)victim->query_body_ac() + "\n");
  write ("Eq AC mod: " + (string)victim->query_equip_ac() + "\n");
  write ("Total AC: " + (string)victim->query_total_ac() + "\n");
  write ("Thac0: " + (string)victim->query_thac0() + "\n");
  write ("To hit bonus: " + (string)victim->query_tohit_bonus() + "\n");
  write ("Guildname: " + (string)guild->query_name() + "\n");
  //write ("Extreme: " + (int)guild->query_extr_str() + "\n");
  write ("Dice: " + (int)guild->query_dice() + "\n");
  write ("Thac0 step: " + (int)guild->query_thac0_step() + "\n");
  write ("Advance cost:" + (int)guild->query_advance_cost() + "\n");
  write ("XP base cost:" + (int)guild->query_xp_cost() + "\n");
  write ("Main skill: " + (string)guild->query_main_skill() + "\n");

  return 1;
} /* void do_q */
