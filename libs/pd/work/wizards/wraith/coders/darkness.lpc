#include <std.h>
inherit WEAPON;

int weapon_hit();

void create() {
::create();
    set_name("%^BOLD%^%^BLACK%^Da%^RESET%^%^WHITE%^rk%^BOLD%^%^WHITE%^ne%^BLACK%^ss%^RESET%^");

set_short("%^BOLD%^%^BLACK%^Da%^RESET%^%^WHITE%^rk%^BOLD%^%^WHITE%^ne%^BLACK%^ss%^RESET%^");
set_long(  @ENDTEXT                                  
%^BOLD%^%^BLACK%^    +++
%^BOLD%^%^BLACK%^     ++++
%^BOLD%^%^BLACK%^     ++ ++
%^BOLD%^%^BLACK%^       ++ ++
%^BOLD%^%^BLACK%^         ++ ++
%^BOLD%^%^BLACK%^           ++ ++
%^BOLD%^%^BLACK%^             ++ ++
%^BOLD%^%^BLACK%^               ++ ++
%^BOLD%^%^BLACK%^                 ++ ++
%^BOLD%^%^BLACK%^                   ++ ++
%^BOLD%^%^BLACK%^                     ++ ++
%^BOLD%^%^BLACK%^                       ++ ++
%^BOLD%^%^BLACK%^                         ++ ++
%^BOLD%^%^BLACK%^                           ++ ++                       %^RESET%^%^RED%^*
%^BOLD%^%^BLACK%^                             ++ ++                      %^RESET%^%^RED%^**
%^BOLD%^%^BLACK%^                               ++ ++                      %^RESET%^%^RED%^**
%^BOLD%^%^BLACK%^                                 ++ ++                     %^RESET%^%^RED%^***
%^BOLD%^%^BLACK%^                                   ++ ++                    %^RESET%^%^RED%^***
%^BOLD%^%^BLACK%^                                     ++ ++                  %^RESET%^%^RED%^***
%^BOLD%^%^BLACK%^                                       ++ ++               %^RESET%^%^RED%^****
%^BOLD%^%^BLACK%^                                         ++ ++            %^RESET%^%^RED%^****
%^BOLD%^%^BLACK%^                                           ++ ++         %^RESET%^%^RED%^****
%^BOLD%^%^BLACK%^                                             ++ ++      %^RESET%^%^RED%^****
%^BOLD%^%^BLACK%^                                               ++ ++   %^RESET%^%^RED%^****
%^BOLD%^%^BLACK%^                                                 +++  %^RESET%^%^RED%^****
%^BOLD%^%^BLACK%^                                                   + %^RESET%^%^RED%^****%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                                    %^RESET%^%^RED%^****%^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^\
%^BOLD%^%^BLACK%^                                                  %^RESET%^%^RED%^ ****  %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                                 %^RESET%^%^RED%^ ****    %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                        %^RESET%^%^RED%^ *       ****      %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                        %^RESET%^%^RED%^ **     ****        %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                         %^RESET%^%^RED%^***   ****          %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                           %^RESET%^%^RED%^******             %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                            %^RESET%^%^RED%^****               %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                                                %^BOLD%^%^WHITE%^%%^BOLD%^%^RED%^%%%^BOLD%^%^WHITE%^%
%^BOLD%^%^BLACK%^                                                                             
                                                                               
%^BOLD%^%^WHITE%^
%^BOLD%^%^RED%^                                                                               
%^RESET%^%^RED%^
                                                                               

                                                                               

                                                      

ENDTEXT  );

    set_id( ({"blade", "sword", "darkness"}) );
    set_hands(1);
    set_wc(11);          
    set_ac(2);   
    set_type("blade");        
    set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 50) {
write("%^BOLD%^%^BLACK%^Da%^RESET%^%^WHITE%^rk%^BOLD%^%^WHITE%^ne%^BLACK%^ss%^WHITE%^ impales into your foes chest, %^RED%^Blood sprays across the room!%^RESET%^");
say((string)"%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+"'s %^BLACK%^Da%^RESET%^%^WHITE%^rk%^BOLD%^%^WHITE%^ne%^BOLD%^%^BLACK%^ss%^WHITE%^ impales into their foes chest, %^RED%^blood sprays across the room!");
result=(random(55))+((this_player()->query_level())*3/2);
this_player()->add_sp(result)/4;
if(random(100) < 50) {
write("%^BOLD%^%^BLACK%^Da%^RED%^%^WHITE%^rk%^BOLD%^%^WHITE%^ne%^BLACK%^ss%^WHITE%^ impales your foes chest, You twist the blade paralyzing your opponent!");
say("%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+"'s %^BLACK%^Da%^RESET%^%^WHITE%^rk%^BOLD%^%^WHITE%^ne%^BLACK%^ss%^WHITE%^ impales into their foes chest, Darkness twists paralyzing their opponent!");
atk->set_paralyzed(random(3));
return result;
}
}
}
int query_auto_load()
{                                   
if (this_player()->query_level() > 50) return 1;
}
