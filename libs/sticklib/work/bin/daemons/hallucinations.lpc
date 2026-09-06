/*
 * /bin/daemons/hallucinations.c
 *
 * Wow, man! This daemon (hmm, it's rather a server) looks so cosmic!
 *
 */
#include <conditions.h>
#include <macros.h>

#define NAME ((string)ob->query_name())
#define TH env->tell_here
#define TM ob->tell_me

string *liv_names, *obj_names;
int livsize, objsize;

nomask void
create()
{
    liv_names = ({
      "Death", "Purple dragon", "Lucy in the sky with diamonds",
      "Troll", "Game Driver", "Armageddon", "Batmud", "The clouds",
      "The ground under your feet", "The tiny green man", "Vainamoinen",
      "Your liege", "Alice in Wonderland", "Your brain", "Flowers",
      "Bulletin board", "Aardvark", "Amazon", "Satan",
      "Ancient Multi-Hued Dragon", "Attorney", "Audrey II",
      "Basilisk", "Battlemech", "Beholder", "Bookworm", "Boomer",
      "Borg", "Brogmoid", "Christmas-tree monster", "Creeping coins",
      "Dalek", "Doppelganger", "Dornbeast", "Earthquake beast", "Efreeti",
      "Emu", "Ent", "Evil Iggy", "Ewok", "Giant cockroach",
      "Giant pigmy", "Giant dwarf", "Giant slug", "Giant Teddybear",
      "Gnu", "Grue", "Harpy", "Hologram", "Hydra", "Invid", "It",
      "Jabberwocky", "Jester", "Jumbo shrimp", "The Thing",
      "Kestrel", "Killer bunny", "Killer penguin", "Killer Rabbit",
      "Killer tomato", "King Kong", "Klingon", "Lion-dog", "Luck eater",
      "Luggage", "Maggot", "Marid", "Microscopic space fleet",
      "Nickelpede", "Nightmare", "Ninja hobbit", "Nymph", "Ohmu",
      "Christian Borg", "One-eyed one-horned flying purple people eater",
      "Paskald", "Pterodactyl", "Pushmi-pullyu", "Rat-ant",
      "Ravenous Bugblatter Beast of Traal", "Rhinovirus", "Robot",
      "Rodent of unusual size", "Rot grub", "Samurai rabbit", "Shadow",
      "Siren", "Sleazoid", "Smokey the bear", "Smurf", "Snark",
      "Tangle tree", "Nonet", "Teenage mutant ninja turtle", "Terminator",
      "Totoro", "Tribble", "Tyrannosaurus rex", "Venus flytrap",
      "White rabbit", "Wiggle", "Witch doctor", "Monty Python", "Mom",
      "Pink oliphant", "The Jelly That Ate Cleveland", "Carnivorous bag",
      "Small green man", "Browny", "Shrink", "Witch-king",
      "Sauron", "Morgoth", "Semprini", "God"
    });

    livsize = sizeof(liv_names);

    obj_names = ({
      "The thing that your aunt gave you which you don't know what it is",
      "No tea", "Hitchhiker's Guide to the Galaxy", "A toothbrush",
      "Pocket fluff", "Electronic Sub-Etha signaling device", "Babel fish",
      "Portable Improbability Generator", "Empty Coca-Cola can",
      "Old slice of Camembert cheese", "Lightsabre", "Red herring",
      "Red tape", "Huge gold bar", "Onklunk", "Some potato salad",
      "Some plague bacteria", "Sickly green lump of mucus", "Vorpal sword",
      "Gigantic three-handed sword", "Invulnerability potion",
      "Holy handgranade", "Large scale", "Portable hole", "Tricycle",
      "Death trap", "Scythe", "Flying carpet", "Hydra's toothpick",
      "Board of keys","Iceberg", "Bug", "Lord's Crown", "Shimmering door",
      "Arrow pointing east", "Wand of zapping", "Wand of wonder",
      "Red button", "Green button", "Foreign host", "Fabric of space",
      "Colours", "Stars like dust", "Pebbles in the sky",
      "Currents of space", "Kantele", "A bankbook", "A firebreather",
      "Fishscale leggins", "Snake scalemail", "Amulet of Yendor",
      "Omelet of Yendor", "Ring of extra finger", "Corpse of Dragon",
      "Red slippers", "Mushroom of hallucination", "Healing potion",
      "Book of magic", "Spell book", "Spelling book",
      "A huge finger from the sky pointing at you", "Giant foot",
      "1000000 gold coins", "Toilet seat", "Jack-in-the-box",
      "Lekythos", "Mason jar", "Can of Spam", "A panpipe",
      "A puffball", "Sedan chair", "The One Ring",
      "A huge weight with a text: \"16 TONS\"", "Semprini"
    });

    objsize = sizeof(obj_names);
}

/*
 * mode 1: living
 * mode 2: non-living
 *
 */
nomask string
random_short(int mode)
{
    object *u;
    int i;

    if (mode == 1) {
	u = users();

	switch(random(3)) {
	case 0:
	    i = random(sizeof(u));
	    if (!(u[i]->query_coder_level()))
		return capitalize((string)u[i]->query_real_name());

	default:
	    return liv_names[random(livsize)];
	}
    }

    /* Non-livings */
    return obj_names[random(objsize)];
}


/* Other things which happen sometimes... */

void
hallu_effect(object ob)
{
    object env;

    if (!ob || !living(ob)) return;
    if (!(env = environment(ob))) return;

    switch(random(5))
    {
    case 0:
	TH(NAME + " looks amazed.", ob);
	TM("Pink oliphant arrives.\nPink oliphant leaves east.");
	break;
    case 1:
	TH(NAME + " has a blank look in " + (string)ob->Possessive() +
	  " eyes.", ob);
	TM("You see sparkling colours!");
	break;
    case 2:
	TH(NAME + " says: My Deity! It's full of stars.", ob);
	TM("All those stars above your head, where did they come?");
	break;
    case 3:
	TH(NAME + " starts to laugh without any apparent reason.", ob);
	TM("You see twelve hilarious clowns doing funny tricks here!");
	break;
    default:
	TH(NAME + " has a stupid smile on " +
	  (string)ob->Possessive() + " face.", ob);
	TM("You feel you are better than the rest.");
	break;
    }
}
