#include <mudlib.h>
inherit WEAPON;
int query_auto_load(){
return 1;
}

void create(){
  set("short" , "A Fatty Boom Batty Blunt");
  set( "long" , @EndText
  This has got to be the fattest hugest biggest fuckin joint you have
  ever seen. Its about 4 feet long and 2 inches thick. Small flecks of
  weed are getting squeezed out of the front, but its ok...you just
  wanna SMOKE! You can <smoke>, blow some <rings>, and <pass> your fatty
  around the room. Smoke on fuckers.

EndText
  );
  set("mass" , 1);
  set_bonus(50,50,50);
  set_weapon_type("knife");
  set("name" , "fatty");
  set_verbs( ({ "pummel" , "smoke up" }) );
  set("bulk" , 1);
  set("id" , ({ "joint" , "fatty", "bone" }) );
}

void init() {
  add_action("light_fatty" , "light");
  add_action("smoke_fatty" , "smoke");
  add_action( "smoke_rings" , "rings" );
  add_action( "extinguish" , "extinguish");
  add_action("pass_bone" , "pass");
}
  int smoke_fatty(string str){
    if(!str){
    write("What do ya wanna smoke?\n");
  return 1;
  }
  if(str == "bone"){
    write("You take a fucking HUGE pull from the fatty. You hold it in and start to make wheezing noises from somewhere in your nasal cavity, then you slowly start to let it out...psssssssssss...AAAAAAAH!\n");
    say(TPN+" takes a HUGE pull from the fatty, makes some strange nasal noises...and lets the smoke out slowly.\n");
    return 1;
  }
  return 1;
}
int smoke_rings(string str){
  if(!str){
    write("You pathetically try to make smoke rings, then 6 Jamaicans jump outta nowhere and beat the shit out of you for wasting good smoke.\n");
    say(TPN+" pathetically tries to make smoke rings from the joint when suddenly 6 Jamicans jump out of nowhere and beat the shit out of "+objective(TP->query("gender"))+" for wasting smoke.\n");
    return 1;
  }
  return 1;
}
int pass_bone(string str){
  if(!str){
    write("What do you want to pass?\n");
  return 1; }
  if(str == "bone"){
    write("How generous! You offer your 4 foot bone around the room. Everyone smokes up and gets fuckin' cooked. By the time you get it back though, all that is left is a roach...so you pop that in your mouth and eat it while rolling another fatty.\n");
    say(TPN+" offers everyone in the room some of his fatty, 4 foot joint. You take a puff and pass it on. By the time it gets back to "+TPN+" all "+subjective(TP->query("gender"))+" had left is a roach. So "+subjective(TP->query("gender"))+" eats it. Then pulls some paper out and rolls another.\n");
  return 1; }
return 1;
}
