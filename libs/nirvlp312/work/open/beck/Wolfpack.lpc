object *Wolfpack;
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"

RangerPower(string str, string type){
   int i, j;
   object attack;
   object *update;
   if(PO->QRangerTactic == "Wolfpack"){
      write("You are no longer using special tactics.\n");
      i = member_array(PO, Wolfpack);
      if(i > -1)
         Wolfpack -= ({ Wolfpack[i-1], Wolfpack[i] });
      PO->SRangerTactic(0,0,0,0);
   }
   if(!Wolfpack)
      Wolfpack = ({});
   update = ({});
   if(!this_player()->query_attack()){
      write("You must be attacking something.\n");
      return 1;
   }
   attack = TP->query_attack();
   Wolfpack += ({attack, PO});
   for(i=0; i<sizeof(Wolfpack); i++){
      if(Wolfpack[i]){
         if(Wolfpack[i] == attack){
            j += 1;
            update += ({ Wolfpack[i+1] });
            i = i+1;
         }
      }
      else {
         Wolfpack -= ({ Wolfpack[i], Wolfpack[i+1] });
         i = i-1;
      }
   }
   for(i = 0; i<sizeof(update); i++){
      update[i]->SRangerTactic("Wolfpack", attack, 2*j);
   }
   return 1;
}
