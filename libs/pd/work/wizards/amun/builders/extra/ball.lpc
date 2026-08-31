#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("ball of fire");
    set("id", ({"ball", "ball of fire"}) );
    set_short("%^BOLD%^BLACK%^Ball of%^RESET%^%^RED%^F%^RESET%^%^RED%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This Ball of %^RED%^F%^RESET%^%^RED%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^is used by the one and only '%^WHITE%^Lady of the %^RESET%^%^GREEN%^W%^BOLD%^%^GREEN%^oo%^RESET%^%^GREEN%^d%^BOLD%^%^BLACK%^' to bring forth a %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x%^BOLD%^%^BLACK%^RESET%^.");
}

void init() {
    ::init();
    add_action("command_fire", "command");
    add_action("show_commands", "show");
    add_action("light_fire", "light");
    add_action("pull_phoenix_feather", "pull");
    add_action("stroke_phoenix", "stroke");
    add_action("warn_phoenix", "warn");
    add_action("follow_allow_phoenix", "follow");
    add_action("revoke_flame", "revoke");
}

int command_fire(string str) {
    if (!str || str != "fire to show commands") {
	return 0;
    }
    write("show command [number]");
    write("%^BOLD%^1. light fire%^RESET%^");
    write("%^BOLD%^YELLOW%^2. pull phoenix feather%^RESET%^");
    write("%^BOLD%^3. stroke phoenix%^RESET%^");
    write("%^BOLD%^YELLOW%^4. warn phoenix%^RESET%^");
    write("%^BOLD%^5. follow allow phoenix%^RESET%^");
    write("%^BOLD%^YELLOW%^6. revoke flame%^RESET%^");
    return 1;
}

int show_commands(string str) {
    int number;

    if (!str || (sscanf(str, "command %d", number) != 1)) {
	return notify_fail("show command [number]\n");
    }
    switch(number) {
    case 1:
	write("%^BOLD%^This will light the Ball of Fire and a flame will rise and then turn to ash, causing the Phoenix to rise.%^RESET%^");
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
	write("%^BOLD%^YELLOW%^This will make the Phoenix follow me. (Amun).%^RESET%^");
	break;
    case 6:
	write("%^BOLD%^This will cause the Phoenix to be sucked into my ball of fire, causing a flame to rise.%^RESET%^");
	break;
    }
    return 1;
}

int light_fire(string str) {
    if (str == "fire") {
	write("%^WHITE%^You %^BOLD%^BLACK%^i%^RED%^gn%^%^BOLD%^BLACK%^it%^RED%^e %^WHITE%^the %^BOLD%^%^BLACK%^ball of %^RED%^f%^RESET%^%^RED%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e %^BOLD%^%^WHITE%^causing a %^RED%^fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e%^BOLD%^%^WHITE%^ to rise 20 feet into the air; within a second the %^RED%^fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e%^BOLD%^%^WHITE%^ is deteriorated and the %^YELLOW%^light%^WHITE%^ returns to normal.");
	message("info", "%^WHITE%^Carina %^BOLD%^BLACK%^i%^RED%^gn%^BOLD%^BLACK%^it%^RED%^e%^BOLD%^BLACK%^s %^WHITE%^her %^BOLD%^%^BLACK%^ball of %^RED%^f%^RESET%^%^RED%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e %^BOLD%^%^WHITE%^causing a %^RED%^fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e%^BOLD%^%^WHITE%^ to rise 20 feet into the air; within a second the %^RED%^fl%^RESET%^%^RED%^a%^BOLD%^%^RED%^m%^RESET%^%^RED%^e%^BOLD%^%^WHITE%^ is deteriorated and the %^YELLOW%^light%^WHITE%^ returns to normal.", 
	  environment(this_player()), ({this_player()}) );
	new("/wizards/daos/custom/phoenix")->move(environment(this_player()));
	return 1;
    }
}

int pull_phoenix_feather(string str) {
    if (str == "phoenix feather") {
	if( this_player()->query_mp() != this_player()->query_max_mp() )
	{
	    write("You do not have enough power to do that.");
	    return 1;
	}
	this_player()->set_mp(0);
	write("%^BOLD%^%^WHITE%^You pull a %^RED%^bright red feather %^WHITE%^from the %^RESET%^%^MAGENTA%^back %^WHITE%^of the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^WHITE%^causing it to shoot off a %^RED%^Fi%^WHITE%^rewo%^RED%^rk%^WHITE%^.");
	call_out("shoot_firework", 2);
	return 1;
    }
}

void shoot_firework() {
    message("info", "%^BOLD%^%^WHITE%^Amun pulls a %^RED%^bright red feather %^WHITE%^from the %^RESET%^%^MAGENTA%^back %^WHITE%^of the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^WHITE%^causing it to shoot off a %^RED%^Fi%^WHITE%^rewo%^RED%^rk%^WHITE%^.", 
      environment(this_player()), ({this_player()}) );
    message("info", "%^BOLD%^%^WHITE%^The %^CYAN%^skies %^RED%^burst%^WHITE%^ into a %^YELLOW%^gold%^RED%^en fl%^YELLOW%^ame %^WHITE%^giving %^YELLOW%^light %^WHITE%^to the entire Kingdom.", users());
}

int stroke_phoenix(string str) {
    if (str == "phoenix") {
	if( this_player()->query_mp() != this_player()->query_max_mp() )
	{
	    write("You do not have enough power to do that.");
	    return 1;
	}
	this_player()->set_mp(0);
	write("%^BOLD%^%^WHITE%^You stroke the %^YELLOW%^head %^WHITE%^of the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^WHITE%^causing it to shoot off a %^YELLOW%^Fi%^WHITE%^rewo%^YELLOW%^rk%^WHITE%^.");
	call_out("shoot_second_firework", 2);
	return 1;
    }
}

void shoot_second_firework() {
    message("info", "%^BOLD%^%^WHITE%^Amun strokes the %^YELLOW%^head %^WHITE%^of the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^WHITE%^causing it to shoot off a %^YELLOW%^Fi%^WHITE%^rewo%^YELLOW%^rk%^WHITE%^.", environment(this_player()), ({this_player()}));
    message("info", "%^BOLD%^%^BLACK%^The %^CYAN%^skies %^BLACK%^blacken as a %^RESET%^ORANGE%^dr%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^g%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^n %^BOLD%^%^BLACK%^flies down into the %^YELLOW%^K%^WHITE%^i%^YELLOW%^ngd%^WHITE%^o%^YELLOW%^m %^BLACK%^leaving areas to %^RED%^b%^BLACK%^u%^RED%^rn%^BLACK%^.", users());
}

int warn_phoenix(string str) {
    if (str == "phoenix") {
	if( this_player()->query_mp() != this_player()->query_max_mp() )
	{
	    write("You do not have enough power to do that.");
	    return 1;
	}
	this_player()->set_mp(0);
	write("%^BOLD%^%^WHITE%^You %^RESET%^%^RED%^warn %^BOLD%^%^WHITE%^the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x%^BOLD%^%^WHITE%^ of %^RED%^danger%^WHITE%^ causing it to shoot off a 
%^BLACK%^fi%^RED%^rewo%^BLACK%^rk%^WHITE%^.");
        call_out("shoot_third_firework", 2);
        return 1;
    }
}

void shoot_third_firework() {
    message("info", "%^BOLD%^%^WHITE%^Amun %^RESET%^%^RED%^warns %^BOLD%^%^WHITE%^the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x%^BOLD%^%^WHITE%^ of %^RED%^danger%^WHITE%^ causing it to shoot off a 
%^BLACK%^fi%^RED%^rewo%^BLACK%^rk%^WHITE%^.", environment(this_player()), ({this_player()}) );
    message("info", "%^BOLD%^%^BLACK%^A %^RESET%^%^GREEN%^green mark %^BOLD%^%^BLACK%^of a sk%^WHITE%^u%^BLACK%^ll, with a 
%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^rp%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^nt %^BOLD%^%^BLACK%^protruding from the mouth, is shot into the %^CYAN%^sky%^BLACK%^ as a %^RED%^warning%^BLACK%^.", users());
}

int follow_allow_phoenix(string str) {
    object tp;
    int following;

    if (str == "allow phoenix") {
        following = 1;
        tp = this_player();
        message("info", "%^BOLD%^%^GREEN%^Fawkes %^YELLOW%^fl%^WHITE%^ie%^YELLOW%^s %^WHITE%^onto Amun's back and sings 
%^CYAN%^h%^WHITE%^a%^CYAN%^rm%^WHITE%^o%^CYAN%^n%^WHITE%^iou%^CYAN%^sly%^WHITE%^.", environment(tp));
        message("info", "The Phoenix is now following you.", tp);
        following = 0;
        return 1;
    }
}

int revoke_flame(string str) {
    if (str == "flame") {
        write("%^BOLD%^%^BLACK%^You hear a screech as the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^BLACK%^bursts into %^RED%^fl%^BLACK%^am%^RED%^es %^BLACK%^and is sucked back into your Ball of %^RED%^F%^RESET%^%^RED%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^.");
        message("info", "%^BOLD%^%^BLACK%^You hear a screech as the %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^BLACK%^bursts into %^RED%^fl%^BLACK%^am%^RED%^es %^BLACK%^and is sucked back into Carina's Ball of %^RED%^F%^RESET%^%^RED%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^.", environment(this_player()), ({this_player()}));
        children("/wizards/daos/custom/phoenix")->remove();
        return 1;
    }
}

int query_auto_load()
{
    if (this_player()->query_name() == "amun")
        return 1;
}
