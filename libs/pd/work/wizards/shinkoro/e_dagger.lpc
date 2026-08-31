#include <std.h>
inherit WEAPON ;
 
create() {
    ::create();
    set_short("%^BOLD%^%^RED%^E%^BLUE%^l%^RESET%^%^RED%^e%^BLUE%^m%^BOLD%^RED%^e%^BLUE%^n%^RESET%^%^RED%^t "
             "%^BOLD%^%^YELLOW%^Dagger%^RESET%^");
    set_name("Element Dagger");
   set_id( ({"dagger"}) );
   set_long("%^BOLD%^%^YELLOW%^This special dagger was created by a powerfull Druid."
  " The blade is made of a material that you can not distinguish.  Two small gems, one %^RED%^red%^YELLOW%^"   
" and the other %^BLUE%^blue%^YELLOW%^, are set into the %^WHITE%^marble%^YELLOW%^ handle.%^RESET%^");
   set_weight(20);
   set_curr_value("gold", 5000);
   set_wc(25);
   set_ac(2);
   set_type("knife");
    set("skill level", 100);
   set_wield("%^YELLOW%^You feel torn between %^BOLD%^%^RED%^fire %^RESET%^%^YELLOW%^and %^BOLD%^BLUE%^ice%^RESET%^");
   set_hit((: this_object(), "weapon_hit" :));


}
int weapon_hit()
{
    int result;
    object ob;
    ob=(object)this_player()->query_current_attacker();
    if(random(100) > 75) {
        write("%^BOLD%^%^YELLOW%^Your dagger suddenly feels %^BLUE%^COLD %^YELLOW%^as it cuts%^RED%^ "+ob->query_cap_name()+"%^RESET%^") ;
        say("%^BOLD%^%^BLUE%^" +(string) this_player()->query_cap_name()+"%^RESET%^%^CYAN%^shivers%^BOLD%^%^YELLOW%^ as his Element Dagger hits "+ob->query_cap_name()+"%^RESET%^") ; 
       
result=(random(300))+((this_player()->query_level()));
  ob->set_paralyzed(random(3));
    if(random(100) > 85) {
      write("%^BOLD%^%^YELLOW%^Your dagger suddenly feels %^RED%^HOT %^YELLOW%^as it"
         "cuts%^RED%^ "+ob->query_cap_name()+"%^RESET%^");
    say("%^BOLD%^%^YELLOW%^" +(string)this_player()->query_cap_name()+"%^RED%^ sweats %^YELLOW%^"
  "as his Element Dagger hits "+ob->query_cap_name()+"%^RESET%^");
result=(random(10))*((this_player()->query_level()));
return result;
}
    }
}
int query_auto_load() {
  if(this_player()->query_level() > 36) return 1; 
}
