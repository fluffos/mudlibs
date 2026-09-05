#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"

RangerPower(string str, string type){
   int i, j;
   object *Encourage;
   object attack;
   object *update;
   update = ({});
   if(!this_player()->query_attack()){
      write("You must be attacking something.\n");
      return 1;
   }
   Encourage = all_inventory(ENV(TP));
   attack = TP->query_attack();
   for(i=0; i<sizeof(Encourage); i++){
      if(Encourage[i]->query_attack() == attack){
         if(present("RangerCommunicator",Encourage[i])){
            j += 1;
            update += ({ present("RangerCommunicator", Encourage[i]) });
         }
      }
   }
   for(i = 0; i<sizeof(update); i++){
      update[i]->SEncourage(attack, attack->query_name(), j);
   }
   return 1;
}


      