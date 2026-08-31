#include <std.h>

#define TP this_player()

inherit OBJECT;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("statue");
    set("id", ({"statue", "dragon statue"}) );
    set_short("%^BOLD%^%^WHITE%^Dragon Statue, Azire%^RESET%^");
    set_long("This small statue was lovingly hand carved from river "
      "stone by the dragon Venenum.  It depicts a female dragon curled "
      "up in sleep, her muzzle resting on her front paws as she "
      "slumbers.  It is incredibly well detailed, down to each individual "
      "scale on her back, reflecting the dedication and passion placed into "
      "such an item.  It is warm to the touch, and strangely, soft.  You could "
      "probably kiss, hug, pet, snuggle, huggle, squeeze, or fondle this statue "
      "as it seems to be almost alive.");
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
	message("info", "%^BOLD%^CYAN%^You press the statue to your chest, hugging "
	  "it against yourself fondly.  The statue purrs loudly as you do so, its tiny "
	  "stone claws reaching out to hug you back as best it can%^RESET%^.", TP);
	message("info", "%^BOLD%^CYAN%^"+TP->query_cap_name()+" hugs a statue of a "
	  "white dragon to himself, purring happily.  The statue's tiny stone claws "
	  "reach out to hug him back as best he can%^RESET%^.", environment(TP), TP);
	return 1;
    }
}

int cmd_pet(string str) {
    if (str == "statue") {
	message("info", "%^BOLD%^CYAN%^You reach out and gently pat the statue "
	  "between her horns.  The statue squirms happily as you do, cooing up to you "
	  "with her big round eyes%^RESET%^.", TP);
	message("info", "%^BOLD%^CYAN%^"+TP->query_cap_name()+" gently pats a stone "
	  "statue of a white dragon between the horns.  Strangely, the statue squirms "
	  "to life, emitting soft affectionate cooing "
	  "noises%^RESET%^.", environment(TP), TP);
	return 1;
    }
}

int cmd_snuggle(string str) {
    if (str == "statue") {
	message("info", "%^BOLD%^CYAN%^You snuggle the warm stone statue up against " 
	  "your chest.  The statue wiggles happily, snuggling back up against "
	  "you%^RESET%^.", TP);
	message("info", "%^BOLD%^CYAN%^"+TP->query_cap_name()+" snuggles a stone "
	  "statue of a whit dragon up against his chest.  The statue seemingly comes "
	  "to life, snuggling back up against him happily"
	  "%^RESET%^.", environment(TP), TP);
	return 1;
    }
}

int cmd_huggle(string str) {
    if (str == "statue") {
	message("info", "%^BOLD%^CYAN%^You give the statue a huggle and it purrs "
	  "happily, returning the favor%^RESET%^.", TP);
	message("info", "%^BOLD%^CYAN%^"+TP->query_cap_name()+" huggles a statue of "
	  "a white dragon warmly.  It purrs happily, returning the "
	  "favor%^RESET%^.", environment(TP), TP);
	return 1;
    }
}

int cmd_squeeze(string str) {
    if (str == "statue") {
	message("info", "%^BOLD%^CYAN%^You squeeze the statue between your claws "
	  "fondly.  It emits a playful giggle and squirms, its tail wiggling like a "
	  "worm on a hook%^RESET%^.", TP);
	message("info", "%^BOLD%^CYAN%^"+TP->query_name()+" playfully squeezes a "
	  "statue of a white dragon in his claws.  It giggles playfully and squirms, "
	  "its tail wiggling like a worm on a hook%^RESET%^.", environment(TP), TP);
	return 1;
    }
}

int cmd_fondle(string str) {
    if (str == "statue") {
	message("info", "%^BOLD%^CYAN%^You gently scritch the statue's chest "
	  "area.  The statue glows a bright pink and darts away from you, only to "
	  "return a second later, giggling happily%^RESET%^.", TP);
	message("info", "%^BOLD%^CYAN%^"+TP->query_cap_name()+" scritches gently "
	  "at the chest area of a statue of a white dragon.  The statue turns a "
	  "bright pink and darts away from him, only to return a second later, "
	  "giggling happily%^RESET%^.", environment(TP), TP);
	return 1;
    }
}

int cmd_kiss(string str) {
    if (str == "statue") {
	message("info", "%^BOLD%^CYAN%^You bring the statue up to your muzzle and "
	  "gently smooch it on its warm, stone lips%^RESET%^.", TP);
	message("info", "%^BOLD%^CYAN%^"+TP->query_cap_name()+" gently kisses a "
	  "statue of a white dragon on the lips, churring fondly as it kisses him "
	  "back%^RESET%^.", environment(TP), TP);
	return 1;
    }
}

int drop() {
    write("Azire whines and dives back into your backpack!\n");
    return 1;
}

int sell() {
    write("Azire cries! And doesn't wanna be sold!\n");
    return 1;
}

int bury() {
    write("Azire clings to your claw! No bury Azzy in the cold icky ground!\n");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "venenum")
	return 1;
}
