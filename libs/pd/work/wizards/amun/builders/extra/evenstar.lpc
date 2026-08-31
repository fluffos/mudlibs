#include <std.h>
#include <amun.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Evenstar");
    set("id", ({"star", "evenstar", "necklace", "chain" }) );
    set_short("%^RESET%^E%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nst%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^As a gift from the Elf Gods, this necklace, known as 'Th%^RESET%^%^WHITE%^e E%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nst%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r', was given to Artemis to call about a faithful and gorgoeus tiger, named %^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s.  This elegant pendant, donned upon the Goddess's neck by a cr%^RESET%^%^WHITE%^y%^BOLD%^%^WHITE%^st%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^ll%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^z%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^d ch%^RESET%^%^WHITE%^ai%^BOLD%^%^WHITE%^n, is shaped like an elf and has a mystically white dia%^RESET%^%^WHITE%^mond s%^BOLD%^%^WHITE%^tar laid upon its heart.  After chanting the words '%^BLACK%^La%^WHITE%^s%^BLACK%^to be%^WHITE%^th n%^BLACK%^in, me%^WHITE%^llon n%^BLACK%^in%^WHITE%^', the clear crystal will turn a %^BLACK%^deep black %^WHITE%^and begin to %^YELLOW%^glow%^WHITE%^, causing the tiger to emerge from it.%^RESET%^");
    set_type("necklace");
    set_ac(5);
    set_limbs( ({ "torso" }) );
    set_weight(10);
}

void init() {
    ::init();
    add_action("command_evenstar", "command");
    add_action("show_commands", "show");
    add_action("chant_mellon", "chant");
    add_action("stroke_otis", "stroke");
    add_action("pet_otis", "pet");
    add_action("frighten_otis", "frighten");
    add_action("bow_otis", "bow");
}

int command_evenstar(string str) {
    if (!str || str != "evenstar to show commands") {
	return 0;
    }
    write("show command [number]");
    write("%^BOLD%^1. chant Lasto beth nin, mellon nin.%^RESET%^");
    write("%^BOLD%^YELLOW%^2. Stroke Otis.%^RESET%^");
    write("%^BOLD%^3. Pet Otis.%^RESET%^");
    write("%^BOLD%^YELLOW%^4. Frighten Otis.%^RESET%^");
    write("%^BOLD%^WHITE%^5. Bow Otis.%^RESET%^");
    return 1;
}

int show_commands(string str) {
    int number;

    if (!str || (sscanf(str, "command %d", number) != 1)) {
	return notify_fail("show command [number]\n");
    }
    switch(number) {
    case 1:
	write("%^BOLD%^WHITE%^This will bring forth %^BOLD%^%^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s%^BLACK%^%^WHITE%^, the mighty %^BLACK%^T%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r%^BOLD%^%^WHITE%^.%^RESET%^");
	break;
    case 2:
	write("%^BOLD%^YELLOW%^This will allow me to shoot off a specific firework.%^RESET%^");
	break;
    case 3:
	write("%^BOLD%^This will allow me to shoot off a second specific firework.%^RESET%^");
	break;
    case 4:
	write("%^BOLD%^YELLOW%^This will allow me to shoot off a third specific firework.%^RESET%^");
	break;
    case 5:
	write("%^BOLD%^This will cause %^BOLD%^%^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s%^BLACK%^%^WHITE%^ to be sucked back into my %^RESET%^E%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nst%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r.%^RESET%^");
	break;
    }
    return 1;
}

int chant_mellon(string str) {
    if (str == "Lasto beth nin, mellon nin.") {
	write("%^BOLD%^%^WHITE%^You hold Th%^RESET%^%^WHITE%^e E%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nst%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r in your hand as you chant '%^BLACK%^La%^WHITE%^s%^BLACK%^to be%^WHITE%^th n%^BLACK%^in, me%^WHITE%^llon n%^BLACK%^in%^WHITE%^', causing the %^RESET%^cr%^BOLD%^%^WHITE%^y%^RESET%^st%^BOLD%^%^WHITE%^a%^RESET%^l %^BOLD%^%^WHITE%^to turn a %^BLACK%^deep black %^WHITE%^and begin to %^YELLOW%^glow%^WHITE%^, causing the %^BLACK%^t%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r %^WHITE%^to emerge from it.%^RESET%^");
	message("info", "%^BOLD%^%^WHITE%^Artemis holds 'Th%^RESET%^%^WHITE%^e E%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nst%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r' in her hand as she chants '%^BLACK%^La%^WHITE%^s%^BLACK%^to be%^WHITE%^th n%^BLACK%^in, me%^WHITE%^llon n%^BLACK%^in%^WHITE%^', causing the %^RESET%^cr%^BOLD%^%^WHITE%^y%^RESET%^st%^BOLD%^%^WHITE%^a%^RESET%^l %^BOLD%^%^WHITE%^to turn a %^BLACK%^deep black %^WHITE%^and begin to %^YELLOW%^glow%^WHITE%^, causing a %^BLACK%^t%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r %^WHITE%^to emerge from it.%^RESET%^", environment(this_player()), ({this_player()}) );
	new("/wizards/amun/otis")->move(environment(this_player()));
	return 1;
    }
}

int pet_otis(string str) {
    if (str == "otis") {
	if( this_player()->query_mp() != this_player()->query_max_mp() )
	{
	    write("You do not have enough power to do that.");
	    return 1;
	}
	this_player()->set_mp(0);
	write("%^BOLD%^%^BLACK%^You pet behind the ears of the great tiger, causing him to purr loudly.%^RESET%^");
	call_out("shoot_firework", 1);
	return 1;
    }
}

void shoot_firework() {
    message("info", "%^BOLD%^%^BLACK%^Artemis pets O%^WHITE%^t%^BLACK%^i%^WHITE%^s%^BLACK%^ behind the ears, causing him to purr loudly.%^RESET%^", environment(this_player()), ({this_player()}) );
    message("info", "%^BOLD%^%^BLACK%^The r%^WHITE%^e%^BLACK%^a%^WHITE%^l%^BLACK%^m%^WHITE%^s %^BLACK%^shake slightly as a loud p%^WHITE%^u%^BLACK%^r%^WHITE%^r %^BLACK%^is heard across the mud.%^RESET%^", users());
}

int stroke_otis(string str) {
    if (str == "otis") {
	if( this_player()->query_mp() != this_player()->query_max_mp() )
	{
	    write("You do not have enough power to do that.");
	    return 1;
	}
	this_player()->set_mp(0);
	write("%^BOLD%^%^BLACK%^You stroke the head of the T%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r causing it to shoot off a %^YELLOW%^Fi%^WHITE%^rewo%^YELLOW%^rk%^WHITE%^.");
	call_out("shoot_second_firework", 1);
	return 1;
    }
}

void shoot_second_firework() {
    message("info", "%^BOLD%^%^BLACK%^Artemis strokes the head of the t%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r, causing it to shoot off a %^YELLOW%^Fi%^WHITE%^rewo%^YELLOW%^rk%^WHITE%^.", environment(this_player()), ({this_player()}));
    message("info", "%^BOLD%^%^WHITE%^A large head of a %^BLACK%^t%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r %^WHITE%^is formed in the %^CYAN%^sky %^WHITE%^for all to see.%^RESET%^", users());
}

int frighten_otis(string str) {
    if (str == "otis") {
	if( this_player()->query_mp() != this_player()->query_max_mp() )
	{
	    write("You do not have enough power to do that.");
	    return 1;
	}
	this_player()->set_mp(0);
	write("%^BOLD%^%^BLACK%^You frighten O%^WHITE%^t%^BLACK%^i%^WHITE%^s %^BLACK%^, causing him to roar loudly across the land.%^RESET%^");
	call_out("shoot_third_firework", 1);
	return 1;
    }
}

void shoot_third_firework() {
    message("info", "%^BOLD%^%^BLACK%^Artemis frightens O%^WHITE%^t%^BLACK%^i%^WHITE%^s %^BLACK%^, causing him to roar loudly across the land.%^RESET%^.", environment(this_player()), ({this_player()}) );
    message("info", "%^BOLD%^%^BLACK%^A loud %^RED%^BOOMING %^BLACK%^roar is heard across the mud as a %^RED%^warning %^BLACK%^of %^RESET%^%^GREEN%^danger%^BOLD%^%^BLACK%^.%^RESET%^", users());
}

int bow_otis(string str) {
    if (str == "otis") {
	write("%^BOLD%^%^WHITE%^Th%^RESET%^%^WHITE%^e E%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nst%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r %^BLACK%^glows a deep black %^WHITE%^as %^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s %^WHITE%^is sucked back in.%^RESET%^");
	message("info", "%^BOLD%^%^WHITE%^Artemis's E%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nst%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^r %^BLACK%^glows a deep black %^WHITE%^as %^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s %^WHITE%^is sucked back in.%^RESET%^", environment(this_player()), ({this_player()}));
	children("/wizards/amun/otis")->remove();
	return 1;
    }
}

int query_auto_load()
{
    if (this_player()->query_name() == "artemis")
	return 1;
}
