#include <std.h>
#include <amun.h>
inherit OBJECT;
int uses;
object ob;
void create() {
    ::create();
    set_id(({"honey", "ambrosia", "phial", "ambrosia phial", "object", "honey ambrosia", "honey ambrosia phial"}));
    set_name("honey ambrosia phial");
    set_long("%^BOLD%^%^YELLOW%^This %^WHITE%^phial %^RESET%^%^ORANGE%^is %^BOLD%^%^YELLOW%^filled %^WHITE%^with %^RESET%^%^ORANGE%^the %^BOLD%^%^YELLOW%^healing %^WHITE%^greatness %^RESET%^%^ORANGE%^of %^BOLD%^%^YELLOW%^God. %^WHITE%^With %^RESET%^%^ORANGE%^a %^BOLD%^%^YELLOW%^splash %^WHITE%^of %^RESET%^%^ORANGE%^honey %^BOLD%^%^YELLOW%^added, %^WHITE%^it %^RESET%^%^ORANGE%^is %^BOLD%^%^YELLOW%^rather %^WHITE%^tasty %^RESET%^%^ORANGE%^as %^BOLD%^%^YELLOW%^it %^WHITE%^fills %^RESET%^%^ORANGE%^the %^BOLD%^%^YELLOW%^drink %^WHITE%^with %^RESET%^%^ORANGE%^light.%^RESET%^");
    set_short("%^BOLD%^%^YELLOW%^H%^WHITE%^o%^RESET%^%^ORANGE%^n%^BOLD%^%^YELLOW%^e%^WHITE%^y %^RESET%^%^ORANGE%^A%^BOLD%^%^YELLOW%^m%^WHITE%^b%^RESET%^%^ORANGE%^r%^BOLD%^%^YELLOW%^o%^WHITE%^s%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^a %^WHITE%^P%^RESET%^%^ORANGE%^h%^BOLD%^%^YELLOW%^i%^WHITE%^a%^RESET%^%^ORANGE%^l %^BOLD%^%^WHITE%^(20 uses)");
    set_weight(20);
    set_curr_value("gold", 300);
    ob = this_object();
    uses = 20;
}

void init() {
    ::init();
    add_action("drinkamon", "drink");
}

int drinkamon(string str) {
    object tp;
    tp = this_player();
    if (!str || str == "" || str != "phial") {
	write("Drink What?");
	return 1;
    }
    if (uses < 1) {
	write("There is no more honey ambrosia in the phial.");
	return 1;
    }
    if (this_player()->query_disable()){
	notify_fail("You are busy.\n");
	return 1;
    }
    uses--;
    write("%^BOLD%^%^WHITE%^You take a drink from your phial.%^RESET%^");
    message("info", ""+tp->query_cap_name()+" takes a drink of their phial.",environment(tp), tp);
    ob->set_short("ambrosia phial ("+uses+" uses)");
    ob->set_weight(uses);
    this_player()->set_disable();
    call_out("drinkdone", 1, tp);
    return 1;
}

int drinkdone(object tp) {
    int result;
    result = (150+random(50));
    tp->add_sp(result);
    write("%^BOLD%^%^YELLOW%^The %^WHITE%^sweet %^RESET%^%^ORANGE%^taste %^BOLD%^%^YELLOW%^of %^WHITE%^the %^RESET%^%^ORANGE%^Honey %^BOLD%^%^YELLOW%^Ambrosia %^WHITE%^flows %^RESET%^%^ORANGE%^throughout %^BOLD%^%^YELLOW%^your %^WHITE%^entire %^RESET%^%^ORANGE%^body, %^BOLD%^%^YELLOW%^allowing %^WHITE%^it %^RESET%^%^ORANGE%^to %^BOLD%^%^YELLOW%^heal %^WHITE%^your %^RESET%^%^ORANGE%^wounds.%^RESET%^");
    if (uses < 1) {
	ob->remove();
    }
    return 1;
}
