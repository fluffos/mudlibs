inherit "/obj/armor";
#include "/players/jaraxle/define.h";

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   set_name("fairy amulet");
   set_short("Fairy "+YEL+"Am"+HIR+"ul"+NORM+YEL+"et"+NORM);
   set_type("amulet");
   set_weight(1);
   set_long("A long necklace made of "+GRN+"wrapped and twined vine"+NORM+".\nA small piece of "+YEL+"amber"+NORM+" is attached to the center.\n");
   set_ac(1); /* physical ac */
   set_value(100+random(300));
}

do_special(owner){
   if(!random(6)){
      tell_object(owner, "The "+YEL+"amber "+YEL+"gem"+NORM+" in your necklace flashes "+HIY+BLINK+"brightly"+NORM+"!\n");
      if(this_player() && this_player()!=owner)
         write(owner->query_name()+"'s amber gem necklace flashes brightly!\n");
      if(owner->query_sp() >=1){
         owner->add_sp(-1);
         return 1; }
      return 0;
   }
}
