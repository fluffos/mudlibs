#include <mudlib.h>
inherit OBJECT;

void create(){
  seteuid(getuid());
  set( "short" , "A Gilbert Rugby Ball" );
  set( "long" , @EndText
  This is an official Gilbert Rugby ball, as used in the World Cup in
  1996. Written across the side of it in bold black letters is the
  name 'GILBERT'. You can <scoretry>, <kick ball>, or <tackle> a dummy.

EndText
  );
  set("no_drop" , 1);
  set("auto_load" , 1);
  set("mass" , 10);
  set("bulk" , 5);
  set("id" , ({ "ball" }) );
}

void init() {
  add_action( "score_a_try" , "scoretry" );
  add_action( "kick_ball" , "kick" );
  add_action( "tackle_dummy" , "tackle" );
}
int score_a_try(string str){
  if(!str){
    write("You move like Campese himself and place the ball under the uprights to the delight and cheers of the crowd.\n");
    say(TPN+" astounds you as he moves like Campese himself and places the ball under the uprights, you can't help but cheer!\n");
    return 1;
  }
  return 1;
}
int kick_ball(string str){
  if(!str){
    write("Kick what?\n");
    return 1;
  }
  if (str == "ball"){
    write("You give the ball a solid boot and catch it on its way down.\n");
    say(TPN+" gives the ball a perfect boot, and catches it one the way down.\n");
    return 1;
  }
  return 1;
}
  int tackle_dummy(string str){
  if(!str){
    write("A dummy apprears out of nowhere and you stun everyone by tackling it with a bone crushing sound.\n");
    say(TPN+" surprises you as he lays a bone crunching tackle on a dummy that just appeared.\n");
    return 1;
  }
  return 1;
}
