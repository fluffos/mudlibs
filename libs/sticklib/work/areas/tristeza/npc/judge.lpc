#include "citymonster.h"

#include <city_name.h>

void
create_monster()
{
    string tmp;

    set_name("judge");
    set_short("Yellowliver, the High Judge of " CITY_NAME);
    set_race("human");
    set_group("cityguard");
    set_gender(G_MALE);
    set(NPC_SET_PK_FLAG, 1);
    set_hp(2500);
    set_alignment(1000); /* It's Very Evil to kill him! */
    set_id(({ "yellowliver", "high judge" }));

    set_long(
      "Judge Yellowliver is an old, grossly fat man with long, shaggy white "+
      "hair and beard. He wears the Purple Robes of a High City Official. "+
      "He is a genius and knows all his laws from memory. He has been the "+
      "High Judge for over twenty years, and has sentenced over ten thousand "+
      "criminals. He has never failed to do that.");

    set_level(32);

    tmp = "Judge says: ";

    load_chat(3, ({
	tmp + "Call the next defendant!",
	tmp + "Overruled.",
	tmp + "Jury decided against law. Overruled. Defendant is guilty.",
	tmp + "Prosecutor shall begin cross-examination. Call the torturer!",
	tmp + "Law #1: I am the law.",
	tmp + "Law #2: The defendant shall remain quiet during the trial.",
	tmp + "Law #3: Guilty until proven innocent.",
	tmp + "Law #4: Lawyers shall remain quiet during the trial.",
	tmp + "Law #5: No poofters.",
	tmp + "Law #6: There is no Law #6.",
	tmp + "Law #7: It's illecal to prosecute City Officials.",
	tmp + "Law #8: Death by hanging from neck until dead.",
	tmp + "Law #9: No poofters."
      }));

    set_wc(10);
}

/* Guards defend us immediately */
int
attacked_by(object orig, int to_top, int flags)
{
    object *inv;
    int i, s;

    int ret;

    if (!(ret = ::attacked_by(orig, to_top, flags)) || to_top < 0) return ret;
    extra_attacked_by(orig); /* Assault? */
    inv = all_inventory(environment());
    s = sizeof(inv);

    for(i = 0; i < s; i++) {
	if (inv[i] != this_object() && living(inv[i]) &&
	  inv[i]->id("city_guard")) {
	    inv[i]->attack_object(orig);
	}
    }

    return ret;
}
