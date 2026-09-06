#include <equipped_group_npc.h>
#include <guild.h>
#include "/areas/tristeza/DEFS.h"

#include <invis_levels.h>

#include <tune.h>

#include "dirs.h"

int yelled;

/* Fake "controlled" monster - makes player kills PKs */
status query_ctrl() { return 1; }

void
invis()
{
    environment()->tell_here(short_desc + " hides into the shadows.", this_object());
    set_invis(IL_SNEAKING);
}

void
vis()
{
    environment()->tell_here(short_desc + " was hiding in the shadows!", this_object());
    set_invis(IL_VISIBLE);
}

varargs string
query_short(int mode, object me)
{
    if (!me && !(me = this_player())) return ::query_short(mode, me);
    if (query_invis() && (string) me->query_guild() == GN_THIEF)
	return short_desc + " (hiding)";
    return ::query_short(mode, me);
}

void
create_monster()
{
    string n;

    n = (string) (NAMEGEN_C)->random_name();
    set_name("assassin"); /* So that the exits etc will recognize us */
    set_race("human");
    set_group("thief_guard");
    set_id(({ n, "guild_guard", "lesser_thief_guard" }));
    n = capitalize(n);
    set_short(n + " the assassin");
    set_gender(1 + random(2));
    set_long(
      "Oh no! " + n + " is one of the feared Assassins. You'd better watch\
 your back. He is here to kill intruders.");
    set_level(40);
    set_ep(10000);
    set_wander(2);
    set_wimpy(0);
    set_hp(900);
    set_money(random(50) + 50);
    set_alignment(AL_NASTY);

    add_weapon("short sword", "short sword", 0, 5,
      n + " takes the short sword and wields it.");

    set_wc(60);
    set_ac(50);

    set_guild("thief");
    yelled = 0;
}

int
extra_aggressive(object ob)
{
    object att;

    if (!ob) return 0;
    if ((string)ob->query_guild() == GN_THIEF) return 0;
    if (ob->query_coder_level()) return 0;
    if (!(att = (object)ob->query_attack())) return 0;

    // Is it attacking a thief or guard?
    if ((string)att->query_guild() == GN_THIEF) return 1;
    if (att->id("thief_guard")) return 1;

    return 0;
}

/* First attack() is a stab if we were hiding. */
status
attack()
{
    object o;

    if ((o = query_attack()) && query_invis() > 0 && environment() &&
      present(o, environment())) {
	if ((int) o->query_ac() < random(40)) {
	    o->tell_me(
	      "You feel a terrible, SHARP pain in your back! You got backstabbed!");
	    o->hit_player(TUNE_THIEF_DAMAGE(10 + random(60) + random(55)),
	      DT_IMPALE, 10, this_object());
	} else {
	    o->tell_me("Someone tried to stab you, but you manage to dodge!");
	}
	vis();
    }

    return ::attack();
}

void
random_move()
{
    string where;
    int i;

    if (!environment()) return;

    if (sscanf(object_name(environment()), GDIR2 + "rooms/%s", where) != 1) {
	if (query_invis())
	    environment()->tell_here("Someone says: Abracadabra.", this_object());
	else
	    environment()->tell_here(query_name() + " says: Abracadabra.");
	move_player("X", GDIR + "rooms/guild");
	return;
    }

    if ((i = member(({ "entry", "thief_pub", "tshop", "inner" }), where)) != -1) {
	command(({ "east", "south", "north", "west"})[i]);
	return;
    }

    command(({"north","south","east","west"})[random(4)]);
    set_condition();
}
