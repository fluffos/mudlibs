#include "../defs.h"
/*  
    This is going to make the desert a REAL desert.
  It makes it werk =)
*/
#define SPAM(x) tell_object(TO, "x"+"\n");
void start_chat(){
call_out("chat_loop", 60+random(30));
}

void chat_loop(){
   int x;
   x = random(10);
   switch(x){
     case 0: SPAM(Your precious bodily fluids flow freely from your every pore.) break;
     case 1: SPAM(You hear the distant sound of an amarat horn.) break;
     case 2: SPAM(The dunes around you reflect the sunlight burning your eyes.) break;
     case 3: SPAM(A group of camels can be seen wandering in the distance.) break;
     case 4: SPAM(You wearily rub your eyes) break;
     case 5: SPAM(Is that an oasis ahead?) break;
     case 6: SPAM(Your muscles ache from the hellish surroundings.) break;
     case 7: SPAM(The smell of water rolls into your nostrils) break;
     case 8: SPAM(It seems linshara must roll on to the ends of the world ) break;
     case 9: SPAM(You could almost swear you see a pond up ahead) break;
     default: SPAM(You fear for your life) break;
  }

   call_out("chat_loop", 60+random(30));
}
void init(){
  int x;
  seteuid(getuid());
  x = random(100);
  switch(x){
     case 0: if(!present("oasis", TO)) clone_object(OBJ(bad_oasis))->move(TO); break;
     case 1..2: if(!present("oasis", TO)) clone_object(OBJ(bad_oasis))->move(TO);break;
     default: break;
}
  if((int)TP->query("thirst") > 9){ write("You need water badly.\n"); TP->receive_damage(random(15)); return; }
  TP->add("thirst", 1);
}