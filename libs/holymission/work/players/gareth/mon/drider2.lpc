#include "/players/gareth/define.h"
inherit "/obj/npc";
object scimitar;

reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("drider");
    set_short("A drider");
    set_race("drider");
    set_long("It's yellow eyes make you shiver from fright.\n"+
      "It appears to be a cross between a giant spider and a drow.\n" +
      "The head, torso, and arms of a pale, bloated drow sprout\n"+ 
      "eight spider legs. Due to it's bloated form it's impossible\n"+ 
      "to tell the sex of the drider.\n") ;
    set_level(40);        
    set_ac(55);
    set_wc(55);
    set_hp(2000);
    set_al(-1000);
    set_aggressive(1);
    set_chance(50);
    set_spell_mess1("The drider incinerates you with a fireball!");
    set_spell_mess2("The drider bakes you with his flame!");
    set_spell_dam(70);
    set_attacks(2);
    set_attacks_change(55);
    set_attacks_change(25);
    set_fol_change(50);
    set_rid_change(10);
    set_dodge(45);
    add_money(1500);
    
    scimitar=TR(CO(ITEM+"scimitar"),TO);
    init_command("wield scimitar");

}
}

#define CHANCE 10 
#define MSG this_object()->query_name()+" bites "+vic->query_name()+" !!!\n"
    attack() {

object vic;
vic=this_player()->query_attack();
    if(::attack()) {
      if(random(40)<CHANCE) {
      tell_object (vic," You feel its teeth in your flesh !\n");
      vic->add_poison(random(20));
     }

}
 return 1;
}
init() {

  ::init();
}

