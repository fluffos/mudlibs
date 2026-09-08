// Way to the smugglers hideout.
// The squeeze function is quite tricky :)

// created:          Taurec [26-Nov-1997]

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int squeeze_through(string str);
int follow_prints(string str);

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"In the dunes");
   Set(P_INT_LONG,
     "You are in a little hollow between large sandhills. Without the "
     "hedge to your north and the roar of the surf to the west as "
     "means of orientation, you'd surely get lost. Every hill just "
     "looks very alike. On a second glance, you notice that nature is "
     "not untouched here - several fresh footprints meander like a "
     "chain of pearls through the sand.\n");

   Set(P_INT_WIZMSG,
     "Squeeze <living|myself|me> through the bushes to harbour area.\n"
     "Follow the footsteps to smugglers nest.\n");

   AddVItem(([
    P_IDS: ({"dunes","sandhills","hills","dune","hill","sandhill"}),
    P_ADS: ({"sandy","steep","slippery"}),
    P_LONG:
    "Large sandhills with steep walls, making your horizon very "
    "limited. The only possibility to get out of the hollow here "
    "is to follow the way the footprints lead.\n"
    ]));

   AddVItem(([
    P_IDS: ({"bush","bushes","row","rows"}),
    P_ADS: ({"thick-leaved","thorny"}),
    P_LONG:
    "Evergreen, thick-leaved thorny bushes, standing so close together "
    "that no one can pass them. But you wonder why the chain of "
    "footprints runs directly into the hedge though... is there a gap "
    "in the bushes perhaps?\n"
    ]));

   AddVItem(([
    P_IDS: ({"gap"}),
    P_ADS: ({"small","hidden","secret"}),
    P_LONG:
    "You guess that this gap is a \"backdoor\"to the harbour of Silvere. "
    "Sqeezing yourself through it will surely be no pleasure.\n"
    ]));

   AddVItem(([
    P_IDS: ({"footprints","prints","print","footprint"}),
    P_ADS: ({"meandering","sandy"}),
    P_LONG:
    "Those footprints that lead in from the southeast head directly "
    "towards the row of bushes to the north. You could follow them "
    "into the dunes if you are not afraid to get lost there..."]));

   Set(P_INT_NOISE,
     "You hear the eternal roar of the waves that meet the beach "
     "to your west.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -260,20,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
       "You try to walk up one of the sandy hills, "
       "but it's too steep and you slide back again.\n");
   AddRoomCmd("squeeze","squeeze_through");
   AddExit("follow",#'follow_prints /*'*/);
}

int squeeze_through(string str)
{
   object somebody;
   string *exp,*sb,*who;
   int i;
   notify_fail("Squeeze? What do you want to squeeze... yourself "+
     "through the bushes perhaps?\n",NOTIFY_NOT_VALID);
   if(!str) return 0;
   who=({"me","myself"});
   who+=({({string})TP->QueryName()});
   str=norm_id(str);
   exp=explode(str," through ");
   if (sizeof(exp)!=2) {
     return 0;
   }
   exp[0]=strip_article(exp[0]);
   exp[1]=strip_article(exp[1]);
   if (member(({"gap","bush","bushes","bushrow"}),exp[1])==-1) {
     return 0;
   }
   somebody=TP;
   if (member(who,exp[0])==-1){  // squeezing somebody through, not oneself
     sb=explode(exp[0]," ");
     if (sizeof(sb)==0) return 0;  // No argument in object place
     for (i=0;i<sizeof(sb);i++){   // Check if arguments before through=living
       if (somebody=find_living(lower_case(sb[i]))) break;
     }
     if(!somebody) return 0; // no living obj found, returning.
     if(environment(somebody)!=TO) return 0;
   }
   if(somebody!=TP){
     write("With an unexpected movement and a mischievous grin on your "
      "face, you push "+CAP(NAME(somebody))+" into the thorny bushes. "
      "Cursing and struggling wildly with the thorns, "+HESHE(somebody)+
      " disappears through the gap.\n");
     tell_object(somebody,"With an unexpected movement and a mischievous "
      "grin on "+HISHER(TP)+" face, "+CAP(NAME(TP))+" pushes you into the "
      "thorny bushes. Ouch! Struggling wildly, you finally reach the other "
      "side of the bushrow.\n");
     show_room(TO,"With an unexpected movement and a mischievous grin on "+
       HISHER(TP)+" face, "+CAP(NAME(TP))+" pushes "+CAP(NAME(somebody))+
      " into the thorny bushes. Cursing and struggling wildly with the "
      "thorns, "+HESHE(somebody)+" disappears through the gap.\n",
      "Someone chuckles mischievously. ",({TP,somebody}));
   }
   else{
     write("You take a deep breath and squeeze yourself through these "
      "thorny bushes, carefully trying to avoid the sharp "
      "bloodlusty thorns. Ouch! Struggling wildly.. Ouch! Ouch! ... "
      "you finally... OUCH! ... get through. \"Phew!!!\" - You wipe the "
      "sweat from your forehead. You are back in the harbour now.\n");
   show_room(TO,
    "Cursing and struggling wildly with the thorns, "+CAP(NAME(somebody))+
    " disappears through the bushes.\n",
    "You hear someone cursing and the sound of breaking "
    "branches.\n",({somebody}));
   }
   show_room(SIL_HARBOUR("quay2_3"),"There's a sudden noise in "
    "the bushes to the north! Branches are cracking with a "
    "sound as if something huuuge breaks through the bushes! "
    "Suddenly, "+CAP(NAME(somebody))+" appears. Wiping the sweat from "
    +HISHER(somebody)+" forehead, "+HESHE(somebody)+" goes: \"Phew!!!\"\n",
    "There's a sudden noise in the bushes to your south! "
    "Branches are cracking with a sound as if something huuge "
    "breaks through the bushes! Finally you hear someone "
    "saying: \"Phew!!!\"\n");
   somebody->move(SIL_HARBOUR("quay2_3"),M_GO);
// reduce HP a bit here if you like to *grin evilly*
   return 1;
}

int follow_prints(string str)
{
   object sand;
   string *exp;
   notify_fail("What do you want to follow?\n",NOTIFY_NOT_VALID);
   if (!str) return 0;
   str=norm_id(str);
   str=strip_article(str);
   exp=explode(str," ");
   if (sizeof(exp)!=1) return 0;
   if ((strstr(lower_case(exp[0]),"step")==-1) &&
       (strstr(lower_case(exp[0]),"print")==-1)) return 0;
   write("You start to follow the footprints. Having passed several "
    "dunes, sand valleys and seagull's nests, the trace of footprints "
    "suddenly comes to an end.\n"
    "The wind has blown so much sand into your eyes that they are "
    "quite encrusted now, making it difficult for you to see the "
    "surroundings.\n");
   show_room(TO,
     CAP(NAME(TP))+" starts to stomp along the line of footprints, "
    "watching them attentively. Finally "+HESHE(TP)+" disappears "
    "behind a dune.\n",
    "You hear someone stomping away through the sand.\n",({TP}));
   show_room(SIL_HARBOUR("smugglers2"),"Suddenly, "+CAP(NAME(TP))+
    " comes along and stops here, staring at the sand-floor "
    "as if he misses something.\n",
    "You hear someone (or something?!?) stomping through the "
    "sand moving towards you. Suddenly there's silence.\n");
   if (!deep_present("blinder")){
     sand = clone_object(OBJ("sandy_eyes"));
     if (({int})sand->move(TP,M_SILENT) != ME_OK){
       sand->remove();
       if (sand) destruct (sand);
     }
   }
   TP->move(SIL_HARBOUR("smugglers2"),M_SILENT);
   return 1;
}
