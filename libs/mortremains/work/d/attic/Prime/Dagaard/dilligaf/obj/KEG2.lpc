#include <mudlib.h>

inherit ARMOR ;
int query_auto_load(){
return 1;
}

void create() {
  set("id" , ({ "keg" }) );
  set("short" , "A keg of Guinness(tm)");
  set("long" , @EndText
  This is a Keg Of Guinness. You can <tap>, <pour>, <booze>, <kegstand>,
  or if you aren't screwing around...<getfuckedup>.

EndText
  );
  set("bulk" , 0);
  set("size" , -1);
  set("mass" , 0);
  set("type" , "ring");
  set_armor_type("ring");
  set("armor" , 50);
  set("magic_defense" , 20);
}
void init(){
  add_action("pour_beer" , "pour");
  add_action("tap_keg" , "tap");
  add_action("kegstand" , "kegstand");
  add_action("get_fucked" , "getfuckedup");
  add_action("booze" , "booze");
}
int pour_beer(string str){
  if(!str){
    write("You pour yourself a Guinness and make everyone jealous.\n");
    say(TPN+" pours themself a Guinness and it makes you jealous.\n");
  return 1;
  }
  return 1;
}
int tap_keg(string str){
  if(!str){
    write("You pull a tap from your backpocket and slam it into the top of the keg of Guinness. Now its party time...where did all the chicks come from?\n");
    say(TPN+" pulls a tap from their backpocket and slams it into the top of the keg of Guinness. Now its party time...you wonder where all the chicks just came from.\n");
    return 1;
  }
  return 1;
}
int kegstand(string str){
  if(!str){
  write("You put the keg down and do a handstand on it, shoving the spout into your mouth and pumping the tap with your head. KEG STAND! KEG STAND! are the chants all around you.\n");
    say(TPN+" slams the keg on the floor and jumps on top of it. Slamming the spout into their mouth and pumping the tap with their head. You can't help but start cheering 'KEG STAND! KEG STAND!'\n");
  return 1;
  }
  return 1;
}
int get_fucked(string str){
  if(!str){
    write("You slam 7 Guinnesses in a row and proceed to fall on you face shouting 'WOW! I'm FUCKED UP!'\n");
    say(TPN+" falls flat on their face and shouts 'WOW! I'm FUCKED UP!' after pounding 7 Guinnesses in a row.\n");
    return 1;
  }
  return 1;
}
int booze(string str){
  if(!str){
    write("You behave like a true sophisticate and sip your Guinness politely. Ahh! You can't wait to finish so that you can go and get another.\n");
    say(TPN+" behaves like a true sophisticate and sips their Guinness slowly and politely. Basically they are getting bozed, just its taking more time.\n");
    return 1;
  }
  return 1;
}
