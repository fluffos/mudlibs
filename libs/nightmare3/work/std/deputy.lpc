//	/std/deputy.c
//	from the Nightmare mudlib
//	a monster to assist the victim of a PK attack
//	by Aleas

#include <std.h>
#include <rooms.h>
#include <deputies.h>

inherit MONSTER;

int query_deputy() { return 1; }

object currvict, currfoe;

object query_pk_victim() { return currvict; }

object query_pk_attacker() { return currfoe; }

void create()
{
    ::create();
    set_properties( ([
	"no bump":1,
	"no paralyze":1,
    ]) );
    set_name("deputy");
    set_race(({"kender","elf","human","gnone","halfling"})[random(5)]);
    set_gender(({"male","female"})[random(2)]);
    set_alignment(0);
    set_body_type("human");
    set_class("fighter");
    set_id( ({"deputy"}) );
    set_short("deputy");
    currvict = 0;
    currfoe = 0;
}

void launch_deputy(object victim, object attacker, int nr) {
    int alevel, i, j, tmp, * deps;

    currvict = victim;
    currfoe = attacker;
    if (nr)
    {
	set_short(possessive_noun(victim->query_name())+ " " + (nr == 1 ? "first" : "second")+" deputy");
	set_id( ({"deputy", (nr == 1 ? "first" : "second")+" deputy" }) );
    }
    else
	set_short(possessive_noun(victim->query_name())+" deputy");
    set_long("You remember the face of this strong "+query_gender()+" "+query_race()+" fighter "
	"from the Praxis sheriff's office. "+capitalize(nominative(query_gender()))+" looks very angry. ");
    set_emotes(10,({"%^BOLD%^%^BLUE%^"+capitalize(query_short())+" shouts:%^RESET%^ "+
	attacker->query_cap_name()+"! How dare you attack "+victim->query_cap_name()+"?"}),1);
    alevel = attacker->query_level();
    if (alevel <= 20)
	deps = DEPUTIES_LOW;
    else
	deps = DEPUTIES_HIGH;
    alevel <<= 1;
    j = deps[0];
    if ( (tmp = sizeof(deps)) > 1 )
	for (i = 1; i < tmp; i++)
	    if ( absolute_value( deps[i] - alevel ) < absolute_value( j - alevel ) )
		j = deps[i];

    set_level(j);

    // BALANCE: adjust here! 
    set_stats("constitution",j * 2);
    set_stats("strength", j * 2);
    set_stats("intelligence", j * 2);
    set_stats("wisdom", j * 2);
    set_stats("dexterity", j * 2);
    set_stats("charisma", j * 2);
    set_skill("melee", j * 5);
    set_skill("attack", j * 5);
    set_skill("defense", j * 5);

    this_object()->kill_ob(attacker,0);
}

void heart_beat() {
    object env;

    ::heart_beat();
    env = environment(this_object());
    if (this_object()->query_current_attacker() == 0) {
	if (env)
	    message("mout",capitalize(query_short())+" leaves for the sheriff.",env);
	// attention! change ROOM_VOID's go_back callout to check for this_player() != 0
	// otherwise this fails
	this_object()->move(ROOM_VOID);
	this_object()->remove();
	return;
    }
    if (env) {
	if (!currvict || !objectp(currvict) || !interactive(currvict) ||
		environment(currvict) != env || currvict->query_ghost()) {
	    message("mout",capitalize(query_short())+" leaves for the sheriff.",env);
	    this_object()->move(ROOM_VOID);
	    this_object()->remove();
	}
    }
}
