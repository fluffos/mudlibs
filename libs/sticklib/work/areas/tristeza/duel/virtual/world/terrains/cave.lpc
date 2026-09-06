 
/* 
**   cave.c
**
**   (C) Tron 
**
*****************/
              
 
#include <virtual_room.h>
#include <areas.h>
 
private string
rnd_desc(string *arr) {
 
  if (arr)
    return arr[random(sizeof(arr))];
  return 0;
}
 
 
private string
*do_descs() {
 
string *adjA;
string *sub;
string *rndmsg;
string *gen;
 
 adjA = ({"wet", "humid", "damp", "cool", "dusty", "stinking",
        "warm", "thick", "fresh", "clear"});
 sub = ({ "water", "mud", "stone rubble", "sand"});
    
 rndmsg=({"The walls are dripping water.\n",
          "Your steps echo sharply from the walls.\n",
          "Water drops down from the ceiling on you.\n",
          "Stone walls and darkness make you feel alone.\n",
          "Your breathing echoes from the walls.\n",
          "You hear water dropping down <blib> <blib>.\n",
          "It's pretty cold here.\n",
          "You hear voices all around...or is it you?\n",
          });
 
 gen  =({"The ground is full of "+rnd_desc(sub),
         capitalize(rnd_desc(sub))+" is everywhere",
         "There is a floor built in here",
         "Other side of the cave tunnel has collapsed",
         "The cave tunnel is quite narrow here",
         "The cave makes wild turns here",
         "There are stalagtites here",
         "Floor is covered with "+rnd_desc(sub)+" here", 
         "The air is "+rnd_desc(adjA),
         "You breathe "+rnd_desc(adjA)+" air"
        });
 
 return ({"The caves. "+rnd_desc(rndmsg)+rnd_desc(gen)+".\n" });
}
 
void 
create_virtual() {
 
	set_light_level(LT_DARKNESS);
 
	set_short("The caves");
 

  set_outdoors(WD_INDOORS);
  add_virtual_exit("north", 0, -1);
  add_virtual_exit("south", 0,  1);
  add_virtual_exit("west", -1,  0);
  add_virtual_exit("east",  1,  0);
 
  add_random_object("1:8:"+AREA_DUEL_ARENA+"npc/orc");
  add_random_object("2:10:"+AREA_DUEL_ARENA+"npc/skeleton");
  add_random_object("1:3:"+AREA_DUEL_ARENA+"npc/corc");

  add_item(({"wall", "walls"}), "They are cold and wet.");
  add_item(({"stalagtite", "stalagtites"}), "They are pointy "+
           "formations of stone sticking out from the ground and the "+
           "roof of the cave tunnel.");
  add_item("ground", "It's mostly wet and slippery.");
  add_item("floor", "It's made of large square pieces of some "+
           "red stone.");
 
  set_effects ( ({ "You hear the sound of water dripping down.\n",
                "Sharp echos emerge when you move.\n",
                "A low and weak echo of something catches your attention.\n",
             }) ); 
                            
  set_random_desc(do_descs());
 
}
