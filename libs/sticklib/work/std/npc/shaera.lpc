/* A somewhat castrated version of Shaera from StickMud. No
 * kingdom-related stuff. Doomdark, 28-Aug-98.
 */

#include <npc.h>
#include <unique.h>
#include <areas.h>
#include <city_name.h>
#include <mud_name.h>
#include <config.h>

void
create_monster()
{
    set_name("sharea");
    set_id(({"shaera"}));
    set_dead_ob(this_object());

    set_short("Shaera, the evil brother of Leo");
    set_long("You look upon a dark creature going by the name of \
Shaera. By defeating his noble brother Leo, he was able to lay \
his evil shadow all over the " CITY_NAME " city and surroundings. \
Shaera is not an ugly man, one could even feel attracted to \
his looks of nobility were it not for those creaturelike eyes \
of his. Never will you be the same upon looking into them.");
    //  set(NPC_FOLLOW_ATTACKER);
    //  set(NPC_MOVE_AREA, CHIOS_BASE+"armnah");
    set_level(40);
    set_hp(5000);
    load_a_chat(40, ({
	"Shaera vigorously tumbles your masterly attempt to hit him!",
	"Shaera says: Why are you fighting me? It is within YOU I see the war!",
	"Shaera says: Strike me down and I will be more powerful than you could \
ever conceive!",
	"Shaera says: Good! Let the evil demons flow through your hands!",
	"Shaera says: Enough whining. Now I will kill you." }));
}

status monster_died(object p)
{
    object sce;
    object id;

    this_player()->tell_me("You have an empty feeling about not getting\
 the power you should. Weird.");

    return 0;
}

