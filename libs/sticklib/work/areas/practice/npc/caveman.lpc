// A very simple, unequipped "monster" / Graah.

#include <group_npc.h>

void
create_monster()
{
    string a;
    int l;

    // This is not actually a state-of-the art way of doing this, but...
    a = ({ "short", "tall", "fat", "thin", "scarred", "hairy",
      "bald", "long-bearded", "muscled", "old", "young",
      "squint-eyed", "broken-nosed"
    })[random(13)];

    // Names, descs and ids are always important
    set_name(a + " caveman");
    set_id(({ "caveman", "man", a }));
    set_race("caveman");

    a = capitalize(a) + " caveman"; // This is now suitable for descs and chats.
    set_short(a);
    set_long(
      a + " is a typical primitive humanoid, perhaps a Homo erectus or \
even a Homo heidelbergensis. It eyes you with great curiosity.");

    // Cavemans will defend each other.
    set_group("caveman");

    // Their level varies quite a bit.
    l = 7 + random(20);
    set_level(l);
    set_hp(150 + l * 20); // Cavemen are quite hardy.

    // Cavemen can be of any alignment, but not too strongly.
    set_alignment( AL_GOOD - random(2 * AL_EVIL));

    // Cavemen are effectively neuter here. This is a simple
    // caveman. If we have both genders, we will need better
    // descriptions.
    set_gender(G_NEUTER);

    // Some weird "talk".
    load_chat(4, ({
	a + " says: Ugh!",
	a + " asks: Ungka bum bum oggo?",
	a + " exclaims: Unga unga!",
	a + " sings: Ugga-bugga, ugga-bugga, ugga-bugga!",
      }));

    // This can be done if there is no special functions or variables.
    // This doesn't - it only needs create_monster(), so we can do this.
    // replace_program saves some memory.
    replace_program(GROUP_NPC_FILE);
}
