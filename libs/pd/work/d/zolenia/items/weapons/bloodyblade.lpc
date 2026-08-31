#include <std.h>
#include <zolenia.h>
inherit WEAPON;

int weapon_hit();
void create() {::create();;
     set_name("bloody blade");;
     set_short("%^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy b%^RESET%^l%^RED%^%^BOLD%^ade%^RESET%^");;
     set_long("The bloody blade appears to be made completely from crystallized blood.");;
     set_id( ({"blade", "sword", "bloody blade"}) );;
     set_hands(1);;
     set_wc(12);;
     set_ac(3);;
     set_curr_value("gold", 400+random(35));;
     set_type("blade");;
     set_wield("%^RED%^%^BOLD%^Blood spreads from your bloody blade and covers your arms.%^RESET%^");
     set_hit((:weapon_hit:));;
}
int weapon_hit()
{
int result;
object atk;

     if(random(100) < 15) {write("The %^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy b%^RESET%^l%^RED%^%^BOLD%^ade%^RESET%^ splashes boiling blood onto the face of your opponent.");;
say((string)""+this_player()->query_cap_name()+"'s %^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy b%^RESET%^l%^RED%^%^BOLD%^ade%^RESET%^ splashes out boiling blood.");;
result=(random(100))+((this_player()->query_level())*3);;
return result;;
}
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}

