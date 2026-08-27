/* This is a very simple spell that adds 1 light factor to the room
 * the player casting the spell is in. How long the rooms will be
 * lit depends on the intelligence of the caster, and success on the
 * wisdom. The skill in spellcraft is counted in.
 *
 * The formula is: duration = random(int / 5) + random(skill / 3) + 35
 */

#include <ss_types.h>
#include <stdproperties.h>
#include <comb_mag.h>
#include <macros.h>

#define MANA_LIMIT      5  /* How much mana does it cost to cast this spell? */
#define CAST_LIMIT      20 /* How wise and skilled must the caster be? */
#define SPELL_DIR       "/d/Genesis/doc/examples/spells/" 
				/* Where is our spell dir? */

/* Function name: light
 * Description:   Will light up the room if it's a success with 1 factor
 *                It costs equal mana on success or failure.
 * Arguments:     str - the string from the light spell casted, must be 'room'
 * Returns:       1/0
 */
nomask mixed
light(string str)
{
    object room, lighter;

    if (str != "room")
        return "This spell can only light up rooms. Try 'light room'\n";

    if (!(room = environment(this_player())) || !(room->query_prop(ROOM_I_IS)))
        return "Your are not standing in a room.\n";

    if (RNMAGIC(room)) /* Checks if prop ROOM_I_NO_MAGIC is set. */
        return "Some force in this room prevents you from concetrating.\n";

    if (this_player()->query_mana() < MANA_LIMIT)
        return "You can't concetrate enough to cast this spell.\n";

    this_player()->add_mana(-MANA_LIMIT);

    if (random(this_player()->query_stat(SS_WIS) +
                this_player()->query_stat(SS_SPELLCRAFT)) < random(CAST_LIMIT))
        return "You failed to pronounce the words right.\n";

    write("You concentrate very hard and manage to speak the words right.\n");
    say(QCTNAME(this_player()) + " mumbles something.\n");

    seteuid(getuid(this_object()));
    lighter = clone_object(SPELL_DIR + "obj/lighter");
    lighter->set_duration(random(this_player()->query_stat(SS_INT) / 5) +
        random(this_player()->query_skill(SS_FORM_CONJURATION) / 3) + 45);
    lighter->move(room);
    return 1;
}

/* Function name:
 * Description:
 * Arguments:
 * Returns:
 */


