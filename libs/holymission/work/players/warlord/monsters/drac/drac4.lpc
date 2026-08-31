/* ************************************************************************
                        K A P A K   D R A C O N I A N
   ************************************************************************
                                                 c1993 renegade@iastate.edu
*/

inherit "obj/monster";
#define CHANCE 15 

reset (arg) 
{
    ::reset(arg);
    if (arg) return;
    set_name("draconian");
    set_alt_name("kapak");
    set_level(16+random(5));
    set_hp(500+random(700));
    add_money(500+random(500));
    set_alias("dracon");
    set_al(-1000);
    set_ac(8);
    set_aggressive(1);
    set_wc(14);
    set_gender(0+random(2));
    set_race("draconian");
    set_short("Draconian");
    set_long("A deadly kapak draconian.\n"+
	      "It stands over 6 feet tall has large wings\n"+
	      "hungrily at you.\n");
    set_chance(30);
    set_spell_mess1("You cry out in pain as he claws you.\n");
    set_spell_mess2("He whips his tail around and hits you.\n");
    set_spell_dam(25);
}

attack() {

object vic;
vic=TP->query_attack();

  if(::attack()) {
    if(random(100)<CHANCE) {
      tell_room(E(), me->query_name()+" spits venom at "+
                vic->query_name()+"!\n");
      tell_object(vic,"It spits venom at you!  You are poisoned!\n");
      vic->add_poison(vic->query_max_hp()/18+4);
        }
      }
  return 1;
  }
