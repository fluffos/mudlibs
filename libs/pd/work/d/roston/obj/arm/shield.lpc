#include <std.h>
  inherit ARMOUR;
      
   void create() {
       ::create();   
       set_name("Shield");
       set_short("Holy shield");
   set_long(@ENDTEXT
%^BOLD%^%^CYAN%^
 :\ ,___.^.___, /;
 : `           ` ;
 :     %^YELLOW%^ .-.%^CYAN%^      ;
 :    %^YELLOW%^ _: :_ %^CYAN%^    ;
 :    %^YELLOW%^:_   _:  %^CYAN%^  ;
 :    %^YELLOW%^  : :    %^CYAN%^  ;
 :    %^YELLOW%^  : :    %^CYAN%^  ;
 :    %^YELLOW%^  : :    %^CYAN%^  ;
 `.   %^YELLOW%^  :_:   %^CYAN%^   !
   `.          .`
     `-.,,,,.-`%^RESET%^
ENDTEXT);
       set_id(({"shield", "Holy shield"}));
       set_ac(3);               
       set_mass(35);
    set_curr_value("gold", 40);    
       set_type("shield");   
set_limbs( ({"torso", "left arm", "right arm"}) );
}

int query_auto_load()
{
 if(this_player()->query_level() < 21) return 0;
 return 1;
}
