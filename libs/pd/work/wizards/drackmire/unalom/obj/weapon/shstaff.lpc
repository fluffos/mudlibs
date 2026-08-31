#include <std.h>
inherit WEAPON;
 
void create() {
    ::create();
   set_id(({ "staff", "shimmering staff" }));
   set_name("shimmering staff");
   set_short("a %^GREEN%^sh%^CYAN%^im%^BOLD%^m%^WHITE%^e%^GREEN%^r%^WHITE%^i%^CYAN%^ng%^RESET%^ staff");
   set_long("This staff seems to be made of a strange, shimmering metal.  When "
   "the light reflects off it, it seems to create a negative energy.");
   set_weight(12);
   set_curr_value("gold", 100+random(30));
   set_wc(6);
   set_type("blunt");
   set_hit((: this_object(), "weapon_hit" :));
   }

int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 1) {
    write("%^BLACK%^BOLD%^You feel the staff's metal coalescing into a new form.%^RESET%^");
    this_object()->set_wc(atk->query_level()/10);
    }
    if(random(100) < 10) {
    
    write("%^RED%^BOLD%^You bash the staff over the head of your opponent!%^RESET%^");
    message("you", "%^RED%^BOLD%^"+this_player()->query_cap_name()+" bashes you over the head with "
    +this_player()->query_possessive()+" staff!%^RESET%^", atk);
 
    atk->do_damage("head", atk->query_level()*3);
       }
      result=10;
      return result;

    }
int query_auto_load() { if (this_player()->query_level() > 30) return 1; }
