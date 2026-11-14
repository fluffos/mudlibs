//fisch defines usw fuer quest


#define FO "/d/dschungel/dante/fisch/obj/"
#define FN "/d/dschungel/dante/fisch/npc/"


#define NOLIST if(!present("DANTE_FISCH_LISTE", TP))  { write(BS("Du musst zuerst mit Doby Mick reden!")); return 1; }

#define WEG 3

#define INFO SetProp(P_INFO, TO->QueryProp(P_SHORT)+" ist nur begrenzt haltbar.\n");
  
#define MAT  _query_material()   {write (BS( TO->QueryProp(P_SHORT)+" besteht aus essbarem Fischfleisch.\n"));return "";   }
#define NOBUY SetProp(P_NOBUY, 1);
#define RESET reset()  {::reset(); count++;if(count>=WEG)   {write(TO->QueryProp(P_SHORT)+" verfault gaenzlich!\n");remove();   } }
  
#define FINFO SetProp(P_FOOD_INFO, ([F_HEAL: 5, F_SOAK: 5, F_ALCOHOL: 0,F_POISON: 0]));  

#define WEIGHT SetProp(P_WEIGHT, 500+random(1000));
#define VALUE  SetProp(P_VALUE, random(500));
#define ESSEN BeimEssen(){write(TO->QueryProp(P_SHORT)+" wird von Dir verschlungen!\n");say(TO->QueryProp(P_SHORT)+" wird von "+TPN+" verschlungen.\n"); return::BeimEssen();}
