#include <std.h>
inherit OBJECT;
int uses;
object ob;

void create() {
::create();
set_id(({"ambrosia", "flask", "ambrosia flask", "object"}));
set_name("ambrosia flask");
set_long("A flask of %^BOLD%^%^WHITE%^a%^YELLOW%^m%^RESET%^%^ORANGE%^b%^BOLD%^%^YELLOW%^r%^WHITE%^o%^YELLOW%^s%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^a%^RESET%^, a nectar of the gods.");
set_short("%^BOLD%^%^YELLOW%^ambrosia flask%^RESET%^ (20 uses)");
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
    if (!str || str == "" || str != "ambrosia") {
       write("Drink what?");
       return 1;
       }
    if (uses < 1) {
       write("%^BOLD%^%^ORANGE%^There is no more ambrosia in the flask.%^RESET%^");
       return 1;
       }
    if (this_player()->query_disable()){
      notify_fail("You are busy.\n");
    return 1;
       }
    uses--;
    write("%^BOLD%^%^WHITE%^Y%^YELLOW%^o%^RESET%^%^ORANGE%^u %^BOLD%^%^YELLOW%^t%^WHITE%^a%^YELLOW%^k%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^ a %^WHITE%^d%^YELLOW%^r%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^n%^WHITE%^k%^YELLOW%^ f%^RESET%^%^ORANGE%^r%^BOLD%^%^YELLOW%^o%^WHITE%^m%^YELLOW%^ t%^RESET%^%^ORANGE%^h%^BOLD%^%^YELLOW%^e%^WHITE%^ f%^YELLOW%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^s%^WHITE%^k.%^RESET%^");
    message("info", "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" %^YELLOW%^d%^RESET%^%^ORANGE%^r%^BOLD%^%^YELLOW%^i%^WHITE%^n%^YELLOW%^k%^RESET%^%^ORANGE%^s%^BOLD%^%^YELLOW%^ f%^WHITE%^r%^YELLOW%^o%^RESET%^%^ORANGE%^m %^BOLD%^%^YELLOW%^h%^WHITE%^i%^YELLOW%^s %^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^m%^WHITE%^b%^YELLOW%^r%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^s%^WHITE%^i%^YELLOW%^a%^RESET%^%^ORANGE%^ f%^BOLD%^%^YELLOW%^l%^WHITE%^a%^YELLOW%^s%^RESET%^%^ORANGE%^k.%^RESET%^",environment(tp), tp);
    ob->set_short("%^BOLD%^%^YELLOW%^ambrosia flask%^RESET%^ ("+uses+" uses)");
    ob->set_weight(uses);
    this_player()->set_disable();
    call_out("drinkdone", 3, tp);
    return 1;
   }

int drinkdone(object tp) {
    int result;
    result = (70+random(90));
    tp->add_sp(result);
    write("%^BOLD%^%^WHITE%^T%^YELLOW%^h%^WHITE%^e%^YELLOW%^ s%^WHITE%^w%^YELLOW%^e%^WHITE%^e%^YELLOW%^t %^WHITE%^n%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^a%^YELLOW%^r %^WHITE%^s%^YELLOW%^u%^WHITE%^f%^YELLOW%^f%^WHITE%^u%^YELLOW%^s%^WHITE%^e%^YELLOW%^s%^WHITE%^ y%^YELLOW%^o%^WHITE%^u%^YELLOW%^r%^WHITE%^ b%^YELLOW%^e%^WHITE%^i%^YELLOW%^n%^WHITE%^g.%^RESET%^");
    if (uses < 1) {
       ob->remove();
       }
    return 1;
}

int autoload() {
    if (this_player()->query_guild() == "illuminati") return 1;
    return 0;
}

