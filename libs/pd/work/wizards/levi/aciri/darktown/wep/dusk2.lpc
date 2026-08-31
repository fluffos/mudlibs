# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("dagger");
    
set_short("%^BLUE%^Dusk Dagger%^RESET%^");
    set_long("In the beginning there was chaos.  From that chaos "
        "a dagger was forged by the divine spirits and hidden.");
    set_id(({"dagger", "dusk dagger"}));
    set_wc(16);            
    set_type("knife");   

}

int weapon_hit(){    int result;    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(102) > 85) {
       write("%^BLUE%^You quickly stab your enemy and drain it's life force.");
       say((string)this_player()->query_cap_name()+
	  "'s dagger drains the life force of "
	  +this_player()->query_possessive()+".");
        result=(random(55+random(50)-random(50))*((this_player()->query_level()/20)+1));
        result=random(result)+1;        
        this_player()->add_hp(result);
        return result;    
      }
}

int query_auto_load() { if (this_player()->query_level() >=1) return 1; }


