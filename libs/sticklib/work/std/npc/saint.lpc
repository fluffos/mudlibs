/*
 * Tim the Enchanter - NOT "Sorcerer"!!! //Graah
 *
 * 9-Jan-97 / Graah: Added all offensive priest spells to bans.
 */

#include <treasure.h>
#include <player_defs.h>

void
create_treasure()
{
    set_name("Tim");
    set_id(({ "tim", "enchanter", "tim the enchanter" }));
    set_short("Tim the Enchanter");
    set_long(
      "Tim looks at you and sends balls of fire up in the sky. \
He seems to be busy.");
}

void
init()
{
    if (!this_player()) return;
    if (this_player() != this_object() && this_player()->is_npc()
      && !this_player()->id("armageddon")
      && !this_player()->id("santa claus") &&
      !this_player()->id("zippy") && !this_player()->id("mud_guide") &&
      !this_player()->id("santa_claus") &&
      !this_player()->id("ogre slayer") && !this_player()->query_ctrl())
    {
	this_player()->init_command("south");
	return;
    }
    else if(this_player()->query(LIV_OK_TO_PK) &&
      // A temporary kludge, just to make it work at least somehow.
      !this_player()->query_ghost() &&
      !this_player()->id("armageddon") &&
      !this_player()->id("zippy") && !this_player()->id("mud_guide") &&
      !this_player()->id("ogre slayer") && !this_player()->query_ctrl() &&
      !this_player()->query_coder_level() &&
      !this_player()->query_testplayer()) {
	environment(this_player())->tell_here(
	  "Tim says: Criminals cannot take refuge in temple yard. Away with ye. ");
	environment(this_player())->tell_here(
	  this_player()->query_name()+" is teleported to the south by Tim. ", this_player());
	move_object(this_player(), environment()->query_exit("south"));
	return;
    }
    add_action("not_allowed", "steal");
    add_action("not_allowed", "bash");
    add_action("not_allowed", "slash");
    add_action("not_allowed", "assassin");
    add_action("not_allowed", "aim");
    add_action("not_allowed", "smash");
    add_action("not_allowed", "stab");
    add_action("not_allowed", "backstab");
    add_action("not_allowed", "berserk");
    add_action("not_allowed", "tth");
    add_action("not_allowed", "nth");
    add_action("not_allowed", "mth");
    add_action("not_allowed", "mkick");
    add_action("not_allowed", "kick");
    add_action("not_allowed", "knee");
    add_action("not_allowed", "slap");
    add_action("not_allowed", "kill");
    add_action("not_allowed", "missile");
    add_action("not_allowed", "shock");
    add_action("not_allowed", "fireball");
    add_action("not_allowed", "deathball");
    add_action("not_allowed", "db");
    add_action("not_allowed", "shout");
    add_action("not_allowed", "cast");

    // Priest stuff
    add_action("not_allowed", "paralyze");
    add_action("not_allowed", "earthquake");
    add_action("not_allowed", "holocaust");
    add_action("not_allowed", "disease");
    add_action("not_allowed", "demon");
    add_action("not_allowed", "fury");
    add_action("not_allowed", "pwk");
    add_action("not_allowed", "drain");
    add_action("not_allowed", "purify");
}

not_allowed(who)
{
    if (!objectp(who)) who = this_player();
    if (!who) return;
    who->tell_me("Tim the Sorcerer glares at you.");
    environment()->tell_here(
      "Tim the Sorcerer glares stonily at " + who->query_name()
      + ".", ({ who }));

    return 1;
}

get() { return 0; }
