#include <npc.h>

void
create_monster()
{
    string poss;

    set_name("leper");
    set_short("Leper");
    set_gender(1 + random(2));
    poss = query_possessive();
    set_level(10 + random(20));
    /* Real easy to find and kill... */
    set_ep(query_ep() / 3);
    set_hp(query_level() * 30);
    /* Attacking a poor leper is a SIN! */
    /* God has forsaken the leper, so why shouldn't we?
      set(NPC_SET_PK_FLAG, 1);
    Starks, Jan 25, 1999 */
    set_money((5 + random(6)) * level);
    set_alignment(query_level() * 5);
    set_race(({"human","dwarf","half-orc","hobbit"})[random(4)]);
    set_long(
      "This poor " + query_race() + " has been cursed with the most \
horrible fate: the awful, uncureable disease of leprosy! " +
      capitalize(query_pronoun()) + " wearing full robes and has covered " +
      poss + " head with a hood. " + capitalize(query_pronoun()) +
      " is also carrying a bell to announce " + poss +
      " coming with.");
    set_random_pick(2);
    set_wander(12);

    load_chat(8, ({
	"Leper bangs a bell and cries: Unclean!",
	"Leper croaks: May I ask You for some spare coins, Sire, \
may Boccob bless You!",
	"You can smell a terrible stench coming from Leper.",
	"Leper coughes violently.",
	"Leper sneezes.",
	"Leper is rotting.",
	"Leper drops a finger.",
	"Leper drops " + poss + " nose.",
	"Leper drops an ear.",
	"Leper drops a toe.",
	"Leper drops a tooth.",
	"Leper drops one of " + poss + " hands.",
	"Leper drops one of " + poss + " feet.",
	"Leper cries: Watch out, Unclean!",
      }));

    load_a_chat(10, ({
	"Leper drops a finger.",
	"Leper drops " + poss + " nose.",
	"Leper drops an ear.",
	"Leper drops a toe.",
	"Leper drops a tooth.",
	"Leper drops one of " + poss + " hands.",
	"Leper drops one of " + poss + " feet.",
	"Leper cries: Don't come near me! UNCLEAN!",
      }));
}

void
give_object_by(object who, mixed what)
{
    int i;

    if (intp(what))
    {
	if (who)
	    environment()->tell_here("Leper croaks: Thank you, great " +
	      (string)who->query_name() + ", may Boccob bless you!");

	/* Give some good alignment. However, also rise the
	   leper's alignment! This way it is not too good to
	   just give them money, then kill them. */
	i = what / 8; // Better than beggars.
	if (i > 500) i = 500;
	who->add_alignment(-i);
	add_alignment(-i);

	return;
    }

    if (!objectp(what)) return;

    if (what->is_drink())
    {
	for (i = 0; i < 6; i++)
	    if (what) init_command("drink " + (string)what->query_name());
	for (i = 0; i < 6; i++)
	    if (what) init_command("quaff " + (string)what->query_name());
	init_command("drop bottle");
	return;
    }

    if (what->is_food())
    {
	for (i = 0; i < 6; i++)
	    if (what) init_command("eat " + (string)what->query_name());
	return;
    }

    init_command("drop " + (string)what->query_name());
    return;
}
