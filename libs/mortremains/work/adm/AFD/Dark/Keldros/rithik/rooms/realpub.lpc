inherit CHATTING_ROOM;   
#include "../defs.h"
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "Scar's delight.");
  
set("long", @ENDLONG
Scar's Delight serves as the town pub.  The smell of slow roasted coffee and
hearty ales fills your lungs.  The walls are lined with drawing of warriors.
Each table is unique of its own design.  The dwarves here seem friendly,
but the Ogre bartender.  After being in the room a few minutes, it looks
like this pub is a meeting place for a fighters' guild.  To the west is the
main road.
ENDLONG
);

  set("item_desc", ([
    "bartender" : "Scar is about eleven feet tall and weighs over six hundred
pounds.\n",
    "table" : "Tables vary in size and shape.\n",
    "walls" : "The walls serve as a memorial to fallen warriors of Keldros.\n",
   "drawings" : "Each drawing has been made with black chalk, with a name
inscribed under it.\n",
]) );
set("objects", ([ MON(raider) : 1, ]));
  set("smell", ([
    "default" : "The smell of slow roasted coffee and
hearty ales fill your lungs.\n", ]) );
set("item_desc", ([ "menu" : "You can read it.\n", "sign" : "You can read it\n", ]) );

set("exits", ([ "west" : ROOMS(inter2), ]) );
set("chat_delay", 60);
  set("chat_random", 40);
  set("room_chats", ({
    "An arm wrestling match begins at one of the tables.\n",
    "Scar booms: 'A round of Kirisian Malt on the house in memory of our lost
comrade!'\n",
    "An old dwarf yells: 'One day Dryox will bring the whole of Keldros from
its knees, and we can return to the hills where we belong!\n",
    "A young adventurer whispers to you: 'Would you like to go with me to kill
that pig Anrough?  He will die for what he has done.\n",
    "An attractive young dwarf twirls her beard and winks at you seductively.\n",
    "You hear a blood curdling scream in the back of the room.\n",
    "The entire pub bursts into song as a jolly old dwarf begins 'The Hymn of Maltov'.\n",
    "A chill runs up your spine as you see scar sharpening a knife on one of is tusks.\n",
    "Someone piches your behind, but you can't notice exactly who it is.\n", 
  }) );
  ::create();  
}
void init(){
add_action("buy", "buy");
add_action("list", "list");
add_action("read", "read");
}

int list(){
    write(@ENDLONG
             The following beverages are availible.
>>>>>>>>>>>>>>>>>>>>ALCOHOLIC<<<<<<<<<<<<<<<<<<<<<<<<<<<<

1)Average Beer.--------------8 coins
2)Imported Ale.--------------25 coins
3)Stout Lager.---------------120 coins

>>>>>>>>>>>>>>>>>>>>>SOBERING<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

4)Rithik Spritzer.------------10 coins
5)Beldra's Coffee.------------20 coins

>>>>>>>>>>>>>>>>>>>>SPIRITUAL<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

6)Spirit's Delight------------27 coins
7)Liquid Soul----------------70

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<

ENDLONG
);
return 1;
}
int read(string str){
    if(str !="menu" && !="sign") notify_fail("Read what?\n"); return 1; }
    if(str =="menu"){ list(); return 1; }
    if(str =="sign"){ write(@ENDLONG
          Scar's Delight does NOT accept credit!

     So don't even ASK!
           -Management
  );
  return 1;
}


int buy(string dude){
int makedrunk;
int conchek;
int spichek;
int bedrunk;
conchek = TP->query("stat/constitution");
spichek = TP->query("stat/spirit");
makedrunk = TP->query("drunk");
bedrunk = (spichek + conchek) /2;
 if(dude == "spritzer")
  {                        TP->debit(10);
                           if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            if(makedrunk >0){
                            write("Ahhhhh, that feels good!\n");
                            TP->add("drunk", -1);        
                            return 1;
                            
                            }
                            if(makedrunk < 1){
                            TP->debit(10);
                                if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            write("Ahhhhh, that feels good!\n");
                            return 1;
                            }
 }
  if(dude == "4")
  {                        TP->debit(10);
                           if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            if(makedrunk >0){
                            write("Ahhhhh, that feels good!\n");
                            TP->add("drunk", -1);        
                            return 1;
                            
                            }
                            if(makedrunk < 1){
                            TP->debit(10);
                                if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            write("Ahhhhh, that feels good!\n");
                            return 1;
                            }
 }
if(dude == "coffee")
  {              
                           if(!TP->debit(20)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            if(makedrunk >1){
                            write("You aren't too sure you want to that again!\n");
                            TP->add("drunk", -2);        
                            return 1;
                            
                            }
                            if(makedrunk < 1){
                                if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            write("You aren't too sure you want to that again!\n");
                            return 1;
                            }
 }
if(dude == "5")
  { 
                           if(!TP->debit(20)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            if(makedrunk >1){
                            write("You aren't too sure you want to that again!\n");
                            TP->add("drunk", -2);        
                            return 1;
                            
                            }
                            if(makedrunk < 1){
                                if(!TP->debit(20)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            write("You aren't too sure you want to that again!\n");
                            return 1;
                            }
 }

  if(dude=="delight")
  {
                            TP->debit(35);
                           if(!TP->debit(35)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("Your spine tingles as the delight slides into you.\n");
                            TP->add("spell_points", 5 + random(15));
                           
                            return 1;
  }
if(dude=="6")
  {
                            TP->debit(35);
                           if(!TP->debit(35)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("Your spine tingles as the delight slides into you.\n");
                            TP->add("spell_points", 5 + random(15));
                           
                            TP->debit(35);
                            return 1;
  }
 if(dude=="soul")
  {
                            TP->debit(70);
                           if(!TP->debit(70)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("Your soul is chilled as energy flows through you.\n");
                            TP->add("spell_points", 10+random(15) );
                           
                            return 1;
  }
 if(dude=="7")
  {
                            TP->debit(70);
                           if(!TP->debit(70)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("Your soul is chilled as energy flows through you.\n");
                            TP->add("spell_points", 10+random(15) );
                           
                            return 1;
  }

if(makedrunk > bedrunk){ write("You are just too drunk to do that.\n"); return 1; }
  if(dude=="beer")
  {                       TP->debit(8);
                           if(!TP->debit(8)){ write("The bar does not accept credit.\n");  return 1; }
                              write("It tastse like crap, but it does get the job done.\n");
                              TP->add("drunk", 1);
                              TP->receive_healing(1 + random(4));
                              
                              return 1;
                        
   
  }
 if(dude=="1")
  {                        TP->debit(20);
                           if(!TP->debit(20)){ write("The bar does not accept credit.\n");  return 1; }
                           write("It tastse like crap, but it does get the job done.\n");
                              TP->add("drunk", 1);
                              TP->receive_healing(1 + random(4));
                              
                              return 1;
                             
   
  }
  if(dude=="ale")
  {
                           if(!TP->debit(35)){ write("The bar does not accept credit.\n");  
                                return 1; }
                             write("The ale slides smoothly down your throat.\n");
                             TP->add("drunk", 3);
                             TP->receive_healing(3 + random(4));
                             
                             return 1;
                             
 } 
if(dude=="2")
  {
                           if(!TP->debit(35)){ write("The bar does not accept credit.\n"); 
                               return 1;}
                             write("The ale slides smoothly down your throat.\n");
                             TP->add("drunk", 3);
                             TP->receive_healing(3 + random(4));
                             
                             return 1;
                          
 }
 if(dude=="lager")
  {
                           if(!TP->debit(120)){ write("The bar does not accept credit.\n");  return 1; }
                              write("Thick lager barely allows you to swallow it.\n");
                              TP->add("drunk", 4);
                              TP->receive_healing(5 + random(21));
                              
                              return 1;
                        
   
  }
if(dude=="3")
  { 
                           if(!TP->debit(120)){ write("The bar does not accept credit.\n");  return 1; }
                              write("Thick lager barely allows you to swallow it.\n");
                              TP->add("drunk", 4);
                              TP->receive_healing(5 + random(21));
                              
                              return 1;
                        
   
  }
return 1;
}

