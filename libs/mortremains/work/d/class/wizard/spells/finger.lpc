/*
** file: finger.c (Finger of Death)
** Purpose: 7th level necromantic spell for mages.
** Damage: Death or 3-17.
** Cost: 80
** Credits:
**    31 July 97   Cyanide made this.  :)
*/

#include <m_spells.h>
#include <mudlib.h>

#define COST 80

inherit SPELL;

int cast_finger (string str, int obj) {
    object targ;
    int hp, damage;

    if (!str) targ = this_player()->query_current_attacker();
    else
	targ = present(str, environment(this_player()));

    if (!targ) {
	write("There is nothing of that name to kill here!\n");
	return 1;
    }

    if (!living(targ)) {
	write(capitalize(str)+" isn't even alive!\n");
	return 1;
    }

    if (!this_player()->cast_spell(COST)) {
	write(NOT_ENOUGH_SP);
	return 1;
    }


    write("You begin casting Finger of Death!\n");
    say(TPN+" shouts something in an arcane tongue, and points at "+
      targ->query("cap_name")+".\n", ({ targ }) );
    tell_object(targ,TPN+" shouts something in an arcane tongue, and points"+
      " at you!\n");

    if (!obj) obj=query_caster_level(TP, "wizard");

    hp = (int)targ->query("hit_points");
    hp += 10;
    if (targ->query_level() > TP->query_level()) hp = random(70)+11; //10d8

    if (!check_magic_resist(obj, targ, COST, hp)) return 0;

    if (!targ->save_throw()) 
	damage = targ->receive_damage(hp, "necromancy", this_player());
    else {
	damage = random(8) + random(8) + 3;     //2d8+1
	damage = targ->receive_damage(damage,"necromancy",this_player());
    }

    targ->set("last_attacker", TP);
    hp-=10;
    if (damage > (int)targ->query("hit_points")) {
	tell_object(targ, wrap("You are filled with a world of coldness as"+
	    " your soul is torn from your body!"));
	write(wrap("Your black magics snuff out "+targ->query("cap_name")+
	    "'s very life force!"));
	say(targ->query("cap_name")+"'s soul is snuffed out by "+TPN+
	  "'s profane magics!\n", ({ targ }) );
    } else {
	tell_object(targ, "Immense cold fills your soul as you feel death"+
	  " pass near.\n");
	write(targ->query("cap_name")+" was not slain by your magics.\n");
	say("A chill runs up your spine as "+targ->query("cap_name")+
	  " narrowly escapes death.\n", ({ targ }) );
    }

    return 1;
}
string spellcraft() {
    return (@EndSpell
Finger of Death (Level VII Wizard Spell - Necromancy)

Cost: 80 Spell Points

The caster utters the finger of death spell incantation,
points his index finger at the creature to be slain, 
and unless the victim succeeds in a saving throw vs. spell,
death occurs. A creature successfully saving still receives
10d8 points of damage.
EndSpell
    );
}
