/*
** FILE:    animate.c
** DATE:    August 28, 1996
**
** PURPOSE: The level 9 spell of the necromancer's guild, i.e.
**             "The Dark Cabal"
**
** CHANGES:
**    28 Aug 96   Cyanide    Created the file.
*/

#define BASE_COST 44

#include <m_spells.h>
#include <p_spells.h>

inherit SPELL;

varargs int invoke_animate(string str, int obj) {
    object body, zombie, *stuff;
    int sp, cost, level, mass, mlevel, i;
    mapping stats;
    string name, creator;

    seteuid ( getuid() );
    body = present("dead body", environment(TP));

    if (!body) {
	write("There is no corpse here for you to animate.\n");
	return 1;
    }

    mlevel = body->query("level");

    if (!mlevel || body->query("embalmed")) {
	write("The body twitches, but otherwise nothing "+
	  "happens.\n");
	say (wrap(TPN+" tries to animate the corpse of "+
	    name+", but it doesn't seem to work."));
	return 1;
    }

    stuff = all_inventory(body);
    name = body->query("name");
    mass = body->query("mass");
    stats = body->query("stats");
    creator = TP->query("name");
    sp = TP->query("spell_points");
    level = query_caster_level(TP, "priest");

    cost = ((mlevel*15) + BASE_COST - (level*10));
    if (cost<50) cost = 50;
    if (!invoke_spell(TP, cost)) return 0;

    if ((mlevel) > (level)) {
	write("The body twitches, but otherwise nothing happens.\n");
	say(wrap(TPN+" tries to animate the corpse of "+name+", but it "+
	    "doesn't seem to work.\n"));
	return 1;
    }

    zombie = clone_object(M_OBJ(zombie.c));
    if (!zombie) {
	write("You sense a wrongness in the fabric of space.\n");
	write("Please notify Cyanide.\n");
	return 0;
    }
    zombie->move(environment(this_player()));
    zombie->set_name(name);
    zombie->set("mass", mass);
    zombie->set("creator", creator);
    zombie->set("stat", stats);
    zombie->add("id", (string *)body->query("old_id") );

    for (i=sizeof(stuff)-1; i>=0; i--)
	stuff[i]->move(zombie);

    if (mlevel > 1) mlevel--;

    zombie->set("undead", mlevel);
    zombie->set_level(mlevel);
    zombie = summon(zombie, TP);
    TP->add("followers", ({ zombie }) );
    body->remove();

    write(wrap("You collect the biggest chunks of "+
	name+" and begin your magical rites...\n"+
	"The corpse rises!\n"));
    say(wrap(TPN+" collects the biggest chunks of "+
	name+" and begins "+POSS+" magical rites...\n"+
	"The corpse rises!\n"));

    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Animate Dead (Wizard/Priest - Level V - Necromancy)

Duration: Permanent			Area of Effect: 1 Corpse
Cost: 44 SP + Special

	This spell creates the lowest of the undead monsters--
skeletons or zombies--usually from the bones or bodies of 
deceased monsters. The spell causes existing remains to 
become animated and obey the simple verbal commands of the 
caster. The skeletons or zombies can follow the caster, 
remain in an area and attack any creature entering the place,
etc. The undead remain animated until they are destroyed 
in combat or are turned; the magic cannot be dispelled. 
The following types of dead creatures can be animated:
EndSpellcraft
    );
}
