inherit "/room/room";
#define TR(x) tell_room(this_object(),x) 
#define TP this_player()
#define OPN TP->query_name()
#define TO this_object()
#define env environment

object pl;

void reset(int arg){
if (!arg){
 set_light(1);
 short_desc=("In the vulcano");
 long_desc=
 ("You are standing on a stony bridge ringing a volcano.  Many "+
  "feet below you see the sea surrounding the island you are "+
"on.  Smoke rises out of the crater above you.\n");

 smell="You smell acid hot air";
 items=({"island",long_desc,
         "vulcano",long_desc,
	 "lava","Molten hot lava",
         });
}
 ::reset(arg);

}


init(){
 ::init();
  add_action("jump","jump");
  if (interactive(TP))
  {
      pl = TP;
      TR("Bulp..\n");
      set_heart_beat(1);
  }
}   

void heart_beat()
{
  if (present(pl,TO) && interactive(pl))
  {
    if (!random(5)){
     TR("Bulp..\n");
     TR("A cloud of steam rises up from the crater.\n");
    }
   }

  else 
     set_heart_beat(0);
}
   

int jump(string str){
 notify_fail("Jump where?\n");
 if (str=="down"){
   write("You jump down.\n\nYou are fallingggggggg\n\n"+
	 "You fall into molten lava.\n");
   say(OPN+" falls down to lava.\n");
   TP->hit_player(12000);
   return 1;
 }
}
 
