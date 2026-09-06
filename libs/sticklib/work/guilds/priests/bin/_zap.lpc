#include <living_defs.h>
#include "../priest.h"

#define ZAP_LIMIT 10

#define ENV environment

// We'll get the alignment level between -100 and 100
private int
calculate_alignment(object who) {
    int i;

    if (!who) return 0;
    i = who->query_alignment();
    if(i > 2000) i = 2000;
    else if(i < -2000) i = -2000;
    i /= 20;
    return i;
}

status
zap_cmd(object who, object sym, string s)
{
    object victim, room, staff;
    string zname, vname, staff_id;

    if(!s) return notify_fail("Zap who?\n"),0;

    staff = STAFF_D->query_staff(who);
    if(!staff || (environment(staff) != who))
	return notify_fail("It's rather difficult to zap anything without \
a staff, isn't it?\n"),0;

    if(staff->query_zapping())
	return notify_fail("But you are already zapping!"),0;

    if(staff->query_cur_sps() < ZAP_LIMIT)
	return notify_fail(sprintf("Your staff doesn't have enough \
(%d) points stored in it.", ZAP_LIMIT)),0;

    if(!(room = environment(who))) return 0;
    if(!(victim = present(s, room)))
	return notify_fail(sprintf("You can't see %s here.\n",s)), 0;

    if(!victim->query(LIV_IS_PLAYER_OR_NPC))
	return notify_fail ("Your staff refuses to zap anything \
other than players and monsters!"),0;

    if(IS_PRIEST(victim)) {
	who->tell_me("As you are about to point your staff at \
%<him.name>%, you hear voice of " GOD_NAME " in your head saying: \
Shame on you, %<me.real_name>%! Thou shalt NOT zap fellow priests or \
priestesses!\nYou feel ashamed!",0,0,who,victim,0);
	room->tell_here(":%<me.capname>% looks like %<me.pronoun>% was \
going to raise %<me.possessive>% "+staff->query_staff_name()+", but suddenly lowers \
it again.",0,0,who,who,0,0);
	return 1;
    }
    if(!victim->attacked_by(who,-1)) {
	who->tell_me("As you try to point %<him.name>% with your staff \
to zap %<him.objective>%, you feel that staff resists!\n This probably \
isn't the right place to zap fellow players...",0,0,who,victim,0);
	return 1;
    }
    call_out("zap_cmd2",2,who,victim,staff);
    staff_id = staff->query_staff_id();
    room->tell_here(":%<me.capname>% points %<me.possessive>% %<1>% \
toward %<him.name>%!",0,({0,staff}),({who,victim}),
      who,victim,0);
    who->tell_me(":You point your %<1>% toward %<him.name>%!",
      0,({0, staff_id}),0,victim,0);
    victim->tell_me(":%<me.capname>% points %<me.possessive>% %<1>% \
toward you!",({0,staff_id}),0,who,0,0);
    return 1;
}


void
zap_cmd2(object who, object victim, object staff)
{
    int ratio, dmg_ratio, damage, my_damage;
    int al1, al2, has_sp;
    object zapper, room;
    string zname, vname;
    string my_tell, victim_tell, other_tell;
    string staff_id;

    if(!who) return;
    if(!(room = ENV(who))) return;

    staff_id = staff->query_staff_id();
    if (!victim) {
	who->tell_me("You notice that your enemy has just \
disappeared, and lower your "+staff_id+".");
	room->tell_here(":%<me.capname>% notices that %<me.possessive>% \
enemy has disappeared, and lowers %<me.possessive>%"+staff_id+".",
	  0,0,who,who,0,0);
	return;
    }
    if(ENV(victim) != room) { /* Victim fled! */
	who->tell_me(":You notice that %<him.name>% just fled! \
You lower your "+staff_id+".",0,0,who,victim,0);
	room->tell_here(":%<me.capname>% notices that %<me.possessive>% \
enemy has disappeared, and lowers <me.possessive>%"+staff_id+".",
	  0,0,who,who,victim,0);
	return;
    }
    /* The staff is 'ratio' % full. */
    has_sp = staff->query_cur_sps();
    ratio = has_sp * 100 / staff->query_max_sps();
    dmg_ratio = 50 - (ratio / 4);
    dmg_ratio += random(dmg_ratio + 1);
    if(interactive(victim)) dmg_ratio = dmg_ratio * 75 / 100;

    al1 = calculate_alignment(who);
    al2 = calculate_alignment(victim);
    if(al1 * al2 >= 0) {
	al1 = (al1 > al2) ? (al1 - al2) : (al2 - al1);
	al1 /= 8; /* Since max. a1 could have been 200. */
	if (al1 > 25) al1 = 25; /* Not needed, but still... */
	al1 -= 25;
    } else {
	al1 = (al1 > al2) ? (al1 - al2) : (al2 - al1);
	al1 /= 8;
	if (al1 > 25) al1 = 25;
    }
    damage = 3 * has_sp * (dmg_ratio + al1) / 100;
    my_damage = 0;
    staff->set_sps(0);

    my_tell = ":The mighty wrath of " GOD_NAME " flows from \
your "+staff_id+" and forms huge flaming sphere in the air!\n\
The sphere starts heading towards %<him.name>%!";
    other_tell = "The mighty wrath of " GOD_NAME " flows from \
%<me.name>%'s "+staff_id+" and forms huge flaming sphere in the air!\
The sphere starts heading towards %<him.name>%!";
    victim_tell ="The mighty wrath of " GOD_NAME" flows from \
%<me.name>%'s "+staff_id+" and forms huge flaming sphere in the air!\n\
The sphere starts heading towards YOU!";

    if((ratio >= 49) && (random(100) < (ratio - 30))) {
	/* So, the staff will break. */
	STAFF_D->put_data(who->query_real_name(),"staff","broken");

	my_tell += "\nYou feel something is NOT going right... \
Your "+staff_id+" begins to tremble violently... Feels like it can't \
handle this much energy!\nJust as the sphere hits %<him.name>%, your "+
	staff_id+" explodes!";
	other_tell += "\nYou notice %<me.name>% seems to lose control \
of %<me.objective>% "+staff_id+". It begins to tremble violently! Just \
as the sphere hits %<him.name>%, %<me.name>%'s "+staff_id+" explodes!";
	victim_tell +=
	"\nThe sphere hits you! You feel extreme pain in your whole body!";

	my_damage = damage * (25 + random(26)) / 100;
	/* Zapper gets is 25 - 50% of the inflicted damage. */
	damage -= my_damage;
	destruct(staff);
    } else {
	my_tell +=
	"\nThe sphere hits %<him.name>%! %<him.name>% writhes in pain!";
	other_tell +=
	"\nThe sphere hits %<him.name>%! %<him.name>% writhes in pain!";
	victim_tell += 
	"\nThe sphere hits you! You feel extreme pain in your whole body!";
    }

    if (who->query_coder_level())
	my_tell += "\nDamage: " + damage + " hit points.";

    who->tell_me(my_tell,0,0,who,victim,0);
    victim->tell_me(victim_tell,0,0,who,victim,0);
    room->tell_here(other_tell, 0,0,({ who, victim }),who,victim,0);

    victim->hit_player(damage);
    who->hit_player(my_damage);
}
