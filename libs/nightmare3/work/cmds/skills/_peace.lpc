/*	_peace.c
 *	Monk and cleric ability
 *	created by Descartes 14 November 1992
 *      modified by Bohemund 9 March 1994
 *        - You automatically stop yourself from attacking
 *        - Removed unnecessary parameter
 *        - Added ansi; neatened output strings
 *        - Chance per monster of making it stop attacking. The
 *          monster's level and aggressiveness are taken into
 *          account. It costs as much as each living thing's level.
 */

#include <std.h>

inherit DAEMON;

int cmd_peace() {
    object *inv, who;
    string Class;
    int faith, i, agg, level;
  
    who = this_player();
    if(creatorp(who)) Class = "cleric";
    else Class = who->query_class();
    if(Class != "mage" && Class != "monk" && Class != "kataan" && Class != "cleric")
        return notify_fail("You mumble in confusion.\n");
  if((string)who->query_class() == "kataan") {
    notify_fail("It is not in your nature to desire peace.\n");
    return 0;
  }
    if (!creatorp(who) && (int)who->query_mp() < 10) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
  if(!creatorp(who) && !alignment_ok(who)) {
    notify_fail("You have betrayed the source of your power.\n");
    return 0;
  }
  faith = (int)who->query_skill("faith");
  if (!creatorp(who)) who->add_alignment(5);
  inv = all_inventory(environment(who));
  write("%^BOLD%^%^BLUE%^You call for peace.");
  say((string)who->query_cap_name()+" calls for peace.");
  who->cease_all_attacks();

  for(i=0; i<sizeof(inv); i++) {
    if(!living(inv[i])) continue;
    if(inv[i] == who) continue;
    agg = 10;
    level = (int)inv[i]->query_level();
    if(!creatorp(who) && (random(agg) + level) > random(faith)) continue;
    if (!creatorp(who)) who->add_mp(-level);
    if (!creatorp(who)) who->add_skill_points("faith", 5);
    inv[i]->cease_all_attacks();
  }
  return 1;
}

void help() {
  write("Syntax: <peace>\n"
        "This prayer attempts to bring full peace to all beings in "
	"an area. The chance of the spell working and its cost "
	"vary.\n");
}
