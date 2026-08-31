#include <std.h>
#define TP this_player()
inherit OBJECT;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("statue");
    set("id", ({"statue", "dragon statue"}) );
    set_short("Dragon Statue, Venenum");
    set_long("This small statue was lovingly hand carved by Azire from a volcanic stone in Venenum's den. It is a statue of Venenum himself, the male red dragon curled up into a ball, sleeping. His muzzle rests on his front claws, his tail curled up against his tummy. The detail on the piece is incredible, with individual scales visible, reflecting the dedication and care placed into such an item. Oddly enough, it is warm to the touch and strangely soft. You could probably kiss, hug, pet, snuggle, huggle, squeeze, or fondle this statue as it seems to be almost alive.");
}

void init() {
    add_action("cmd_hug", "hug");
    add_action("cmd_pet", "pet");
    add_action("cmd_snuggle", "snuggle");
    add_action("cmd_huggle", "huggle");
    add_action("cmd_squeeze", "squeeze");
    add_action("cmd_fondle", "fondle");
    add_action("cmd_kiss", "kiss");
}

int cmd_hug(string str) {
    if (str == "statue") {
	message("info", "%^RED%^You press the statue against your chest warmly, rocking it back and forth gently. Venenum's image purrs happily as you do so, it's little legs squirming happily as they rub back against you.%^RESET%^", TP);
	message("info", "%^RED%^"+TP->query_cap_name()+" hugs a statue of a red dragon to "+TP->query_possessive()+" chest warmly.  The statue's tiny stone legs squirm as they rub back against "+TP->query_possessive()+".%^RESET%^", environment(TP), TP);
	return 1;
    }
    else {return 0;}
}

int cmd_pet(string str) {
    if (str == "statue") {
	message("info", "%^RED%^You reach out and gently pat the statue on it's back. Venenum's statue arcs his back as you do so, closing his eyes happily, his tail flicking from side to side.%^RESET%^", TP);
	message("info", "%^RED%^"+TP->query_cap_name()+" gently pats a stone statue of a red dragon on the back. The statue arches it's back happily, eyes closed, his tail flicking from side to side.%^RESET%^", environment(TP), TP);
	return 1;
    }
    else {return 0;}
}

int cmd_snuggle(string str) {
    if (str == "statue") {
	message("info", "%^RED%^You snuggle the warm stone statue up against your front, rocking it from side to side gently. The statue squirms playfully, wiggling his back up against your chest.%^RESET%^", TP);
	message("info", "%^RED%^"+TP->query_cap_name()+" snuggles a stone statue of a red dragon up against his chest. The statue seemingly comes to life, snuggling back up against him happily.%^RESET%^", environment(TP), TP);
	return 1;
    }
    else {return 0;}
}

int cmd_huggle(string str) {
    if (str == "statue") {
	message("info", "%^RED%^You give the statue a warm huggle and it purrs happily, returning the favor.%^RESET%^", TP);
	message("info", "%^RED%^"+TP->query_cap_name()+" huggles a statue of a red dragon warmly. It purrs happily, returning the favor.%^RESET%^", environment(TP), TP);
	return 1;
    }
    else {return 0;}
}

int cmd_squeeze(string str) {
    if (str == "statue") {
	message("info", "%^RED%^You squeeze the statue around the middle with your claws. It emits a playful peep and squirms, its tail wiggling like a worm on a hook.%^RESET%^", TP);
	message("info", "%^RED%^"+TP->query_name()+" playfully squeezes a statue of a red dragon in "+TP->query_possessive()+" claws.  It giggles playfully and squirms, its tail wiggling like a worm on a hook.%^RESET%^", environment(TP), TP);
	return 1;
    }
    else {return 0;}
}

int cmd_fondle(string str) {
    if (str == "statue") {
	message("info", "%^RED%^You cheekily rub between the statue's legs. The statue emits a loud *peep!* and blushes furiously, giggling just a bit, smiling at you sheepishly.%^RESET%^", TP);
	message("info", "%^RED%^"+TP->query_cap_name()+" rubs gently between the legs of a statue of a red dragon.  The statue blushes furiously, giggling a little.%^RESET%^", environment(TP), TP);
	return 1;
    }
    else {return 0;}
}

int cmd_kiss(string str) {
    if (str == "statue") {
	message("info", "%^RED%^You bring the statue up to your muzzle and gently smooch it on its warm, stone lips.%^RESET%^", TP);
	message("info", "%^RED%^"+TP->query_cap_name()+" gently kisses a statue of a red dragon on the lips, churring fondly as it kisses "+TP->query_objective()+" back.%^RESET%^", environment(TP), TP);
	return 1;
    }
    else {return 0;}
}

int drop() {
    write("%^RED%^Venenum whines and dives back into your backpack!\n%^RESET%^");
    return 1;
}

int sell() {
    write("%^RED%^Venenum cries! And doesn't wanna be sold!\n%^RESET%^");
    return 1;
}

int bury() {
    write("%^RED%^Venenum clings to your claw! No bury Venven in the cold icky ground!\n%^RESET%^");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "azire")
	return 1;
    if(this_player()->query_name() == "venenum")
	return 1;
}
