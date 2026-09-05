/* A War Daemon to handle the battle vs. the Goblins. */
#include "/players/maledicta/ansi.h"
int *mobs;
int king;
int rdragon;

id(str){ return str == "contwardaemon"; }

reset(arg){
   if(arg) return;
   rdragon = 1;
   king = 1;
   mobs = allocate(16);
   mobs = ({0,500,1800,2000,0,0,0,0,500,2500,2500,0,0,800,800,0});
   restore_object("players/maledicta/cont/war/war");
   call_out("events", 1);
   call_out("events2", 1);   
   }

dest_me(){
	destruct(this_object());
	return 1;
}
add_mobs(int i){ mobs[i] += 100;
save_object("players/maledicta/cont/war/war");
} 

query_mobs_left(int i){ return mobs[i]; }

sub_mob(int i){ 
mobs[i] -= 1;
save_object("players/maledicta/cont/war/war");
}

query_king(){ return king; }
kill_king(){ king = 0; save_object("players/maledicta/cont/war/war"); }

query_rdragon(){ return rdragon; }
kill_rdragon(){ rdragon = 0; save_object("players/maledicta/cont/war/war"); }

query_goblins(int i){ return mobs[i]; }
query_total_goblins(){ return mobs[1] + mobs[2] + mobs[3] + mobs[8] +
                       mobs[9] + mobs[10] + mobs[13] + mobs[14]; 
                     }



events(){ 
int i;
object *peeps;
remove_call_out("events");
if(rdragon && random(100) < 20){
   peeps = users();
  for(i=0; i < sizeof(peeps); i++){
     if(environment(peeps[i]) && peeps[i]->query_level() < 20){
     if(present("cont_goblin", environment(peeps[i]))){
     peeps[i]->hit_player(random(100) + 30);
     tell_object(peeps[i],
     HIW+"Something soars down, darkening the area around you..."+NORM+"\n"+
     RED+"         () ( ) (  ) (  "+HIR+"FIERY BREATH CONSUMES YOU!"+
     NORM+RED+"  ) (  ) ( ) ()"+NORM+"\n"+
     HIW+"A Red Dragon sails high into the clouds above..."+NORM+"\n");
     tell_room(environment(peeps[i]),
     peeps[i]->query_name()+" screams as "+peeps[i]->query_pronoun()+" is engulfed in"+      
     " flame!\n", ({ peeps[i] }));
     }
    }
   }
  }
remove_call_out("events");
call_out("events", 500 + random(100));
}

events2(){
  int i;
  object *peeps;
  remove_call_out("events2");
  peeps = users();
  for(i=0; i < sizeof(peeps); i++){
     if(environment(peeps[i]) && peeps[i]->query_level() < 20){
     if(present("cont_goblin", environment(peeps[i]))){
     peeps[i]->hit_player(random(20) + 20);
     tell_object(peeps[i],
     HIW+"Arrows from the backline soar through the air!"+NORM+"\n"+
     "          X       X\n"+
     "  X STRIKE    X    STRIKE X\n"+
     "          X       X\n"+
     HIW+"You cry out in pain as arrows pierce you!"+NORM+"\n");
     tell_room(environment(peeps[i]),
     peeps[i]->query_name()+" cries out as arrows rip into "+peeps[i]->query_objective()+"!\n", ({ peeps[i] }));
     }
    }
   }
 remove_call_out("events2");
 call_out("events2", 200 + random(100));
 }
