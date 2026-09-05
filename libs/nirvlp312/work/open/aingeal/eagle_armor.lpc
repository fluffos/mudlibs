inherit "obj/armor";
#include "/players/jaraxle/define.h"
reset(arg){
   if(arg) return;
   ::reset();
   set_name("eagle armor");
   set_alias("eagle");
   set_short(HIY+"Ea"+HIW+"g"+HIY+"le Armor"+NORM);
   set_long("A thick piece of leather armor with mithril\n"+
      "chain in the shape of an eagles head adorning\n"+
      "the front, offering superrior protection.\n");
   set_ac(4);
   set_type("armor");
   set_weight(2);
   set_light(2);
   set_value(4000);
}

do_special(owner) {
   object att;
   if(!owner || !owner->query_attack()) return 1;
   if(!owner->is_player()) return 1;
   att = owner->query_attack();
   if(att->query_alignment() > 10) return -2;
   if(att->query_wc() > 17 && owner->query_alignment() > 200 &&
         random(owner->query_attrib("pie")) > random(30)) {
      tell_object(owner, HIY+"The armor deflects the blow!\n"+NORM);
      owner->add_hit_point(2); return 1; }

if(att->query_spell_dam() && !att->is_npc() && (att->query_attack()==owner)) {
tell_object(owner, 
"Your armor vibrates as it absorbs part of your opponents spell!\n");
/*
owner->add_hit_point(att->query_spell_dam()/3);
*/
 owner->add_hit_point(random(att->query_spell_dam() / ((int)owner->query_attrib("pie") / 10)));
  }     
   return 0; }
