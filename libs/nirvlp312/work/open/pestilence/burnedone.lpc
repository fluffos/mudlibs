#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(""+RED+"Burned One"+NORM+""); 
  set_alt_name("burned one");
  set_alias("one");
  set_short("the "+RED+"Burned One"+NORM+"");
  set_long("This is the body of a once trapped soul.  He has spent\n"+
           "most of his afterlife burning in the flames of hell, which\n"+
           "has left his body with no living skin.  Everything on\n"+
           "his body is blistered and scarred.\n");
  set_race("undead");
  set_gender("male");
  set_level(10);
  set_wc(13+random(4));
  set_ac(8+random(2));
  set_hp(180+random(20));
  set_ac_bonus(0);
  set_wc_bonus(4);
  set_heal(1,15);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat(""+RED+"The Burned One"+NORM+" moans loudly.\n");
  load_chat(""+HIW+"The Skeletal Warrior growls fiercely"+NORM+".\n");
  set_chat_chance(20);
  load_a_chat("A blister from the "+RED+"Burned One"+NORM+" pops, spraying you with fluid.\n");
  set_a_chat_chance(20);
  set_spell_mess2("The "+RED+"Burned One"+NORM+" grabs you.\nYou "+RED+"burn"+NORM+" from the touch.\n");
  set_spell_mess1("The "+RED+"Burned One"+NORM+" burns his attacker with his touch\n");
  set_chance(15);
  set_spell_dam(5);
}

id(str) { return (::id(str) || str == "burned"); }


monster_died() {
  tell_room(environment(this_object()),
        "The "+RED+"Burned One"+NORM+" falls to the ground, tearing some of\n"+
        "his scar tissue from his body.\n");
return 0; }

flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say(""+RED+"Flames fly from the Burned One's"+NORM+" hands hitting "+ATT_NAME+" with a viscious blow.\n");
attacker_ob->hit_player(random(30), "other|fire");



}



heart_beat(){
 ::heart_beat();

if(attacker_ob){
i = random(20);
switch(i){


    case 0..5: flesh_tear();
  break;

    case 6..20: return 0;
  break;

    }
  }
}
