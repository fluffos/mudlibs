#include <std.h>
inherit WEAPON;
int special1(object atk);
int special2(object atk);
void create() {
    ::create();
    set_name("dagger");
    set_short("%^CYAN%^R%^BOLD%^%^GREEN%^i%^RESET%^%^CYAN%^sk%^BOLD%^%^GREEN%^y %^RESET%^%^CYAN%^D%^BOLD%^%^GREEN%^a%^RESET%^%^CYAN%^gg%^BOLD%^%^GREEN%^e%^RESET%^%^CYAN%^r%^RESET%^");
    set_long("A creepy-looking dagger with a tinted-green blade and cyan hilt.");
    set_id(({"dagger", "knife", "risky dagger"}));
    set_wc(10);
    set_hit((: call_other, this_object(), "weapon_hit" :));
    set_type("knife");
    set_mass(100);
    set_hit((:this_object(),"weapon_hit":));  
}
int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    switch(random(2)) {
    case(0) : return special1(atk);
        break;
    case(1) : return special2(atk);
        break;
    }
    return result;
}
int special1(object atk) {
    int result;
    if(random(100) > 75) {
        write("You throw your dagger up in the air! It comes down upon your head!");
        say((string)this_player()->query_cap_name()+
          "throws a dagger up! It comes down on "+this_player()->query_cap_name()+"'s head!");
        result=(random(60+random(40)-random(30))*((this_player()->query_level()/20)+1));
        result=random(result)+10;
        return result;
    }
}
int special2(object atk) {
    int result;
    if(random(100) >50) {
        write("You throw your dagger up in the air! It comes down upon "+atk->query_cap_name()+"'s head! ");
        say((string)this_player()->query_cap_name()+" throws a dagger up! It comes down on "+atk->query_cap_name()+"'s head!");
        result=(random(60+random(40)-random(30))*((this_player()->query_level()/20)+1));
        result=random(result)+10;
        return result;
    }
}
int query_autoload() { if (this_player()->query_level() > 4) return 1; }
