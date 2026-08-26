#include <mudlib.h>
inherit OBJECT;

void create(){
  seteuid(getuid());
  set("short" , "An inflatable pig");
  set( "long" , @EndText
  Ms. Piggy the inflatable pig. You can <inflate>, you can <caress>,
  and you can <screw> it. The skin is almost real, it is soft and
  pink. If you ever get tired of her, just <pop> her.

EndText
  );
  set("mass" , 10);
  set("bulk" , 5);
  set("id" , ({ "pig" }) );
}

void init() {
  add_action( "pop_pig" , "pop" );
  add_action( "inflate_pig" , "inflate" );
  add_action( "caress_pig" , "caress" );
  add_action( "screw_pig" , "screw");
}
int inflate_pig(string str){
  if(!str){
    write("Inflate what?\n");
  return 1;
  }
  if(str == "pig"){
    write("You pop out the cork and press your lips to the valve. The pig slowly stats to fill up with air.\n");
    say(TPN+" pops out the cork and slowly starts to inflate the pig with the valve.\n");
    return 1;
  }
  return 1;
}
int caress_pig(string str){
  if(!str){
    write("Caress what?\n");
  return 1;
  }
  if(str == "pig"){
    write("You gently caress the pig, and she seems to oink with pleasure.\n");
    say(TPN+" gently caresses the inflatable pig, she seems to oink with pleasure.\n");
  return 1;
  }
  return 1;
}
int screw_pig(string str){
  if(!str){
    write("What is it that you want to screw....pervert?\n");
  return 1;
  }
  if(str == "pig"){
    write("You screw the pig like the pervert you are.\n");
    say(TPN+" screws the pig like the pervert that they are.\n");
    return 1;
  }
  return 1;
}
int pop_pig(string str){
  if(!str){
    write("What do you want to pop?\n");
  return 1;
  }
  if(str == "pig"){
    write("With a loud <BANG> you pop the pig and it dissapears.\n");
    say("There is a loud <BANG> and "+TPN+"'s pig dissapears.\n");
    remove();
    return 1;
  }
  return 1;
}
