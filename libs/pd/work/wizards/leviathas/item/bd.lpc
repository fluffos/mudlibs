# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("blade");
    
set_short("%^BOLD%^%^BLACK%^Bl%^RESET%^%^BOLD%^ad%^RESET%^e of "
         "D%^BOLD%^ea%^BLACK%^th%^RESET%^");
    set_long("The blade of death is a tarnished silver colour, it's hilt a dark ruby colour with an old bony hand reaching about it as protection. ");
    set_id(({"blade"}));
    set_wc(20);            
    set_type("blade");   

}

int bury() { this_player()->do_damage("head", 1000000);
this_player()->check_on_limb("head"); 

tell_room(environment(this_player()), this_player()->query_cap_name()+
     " attempts to bury the Blade of Death.  It spins upward and cleaves ()->query_cap_gender()+ head off." }));
   tell_object(ob, this_player()->query_cap_name()+" attempts to bury the Blade of Death.  It spins upward and beheads ()->query_cap_gender()");
   write("You attempt to bury the blade of death.  It spins up and beheads you!");
}

int query_auto_load() { if (this_player()->query_level() >=50) return 1; }

