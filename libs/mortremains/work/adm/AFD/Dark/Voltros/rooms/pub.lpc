
inherit ROOM;

#include "../defs.h"

void create() {
		object ob;
  seteuid(getuid());   
  set("author", "Gendor");
		ob=clone_object(CHATTER);  
  set("light", 1);
  set("short", "Dorothy's Place.");
  
set("long", @ENDLONG
Dorothy's Place is the most happening place in the area.  Parties
go on here daily, but somehow, nothing gets broken.  The bar is
in the northern part of the bar.  Tables are strewn out all over
the room, in no particular order.  The walls are not painted, 
neither are the stools.  The barkeep must like natural tones.
ENDLONG
);

  set("item_desc", ([
    "barkeep" : "The barkeep is Dorothy herself, and, if you remember correctly,
she somehow traveled through dimensions.\n",
    "table" : "Tables vary in size and shape.\n",
    "walls" : "The walls are rough planks, held togther by an epoxy of some sort.\n",
    "bar" : "The bar is only 3 feet high....\n",
				"stools" : "The stools are definately made for smaller folk.\n"

]) );

  set("smell", ([
    "default" : "The smell of coffee and alcohol fill your lungs.\n", ]) );
set("exits", ([ "south" : ROOMS(tsquare), ]) );

ob->set("chat_chance", 5);
  ob->set("chat_output", ({
"An dancing couple bumps into you, pushing you back a little.\n",
"Dorothy says in a loving voice: 'Thanks for choosing Dorothy's Place!'\n",
"The noise in here is deafening.  There must be 40 people in here!\n",
"An old man is telling a tale about dragons in the far eastern corner.\n",
"Someone screams: 'Barkeep!!  Another round for me laddies!'\n",
"A munchkin approaches you and asks if you have a light.\n",
"You see Dorothy give a giggling couple the keys to the back room.\n",
  }) );
ob->move(TO);
  ::create();  
}
void init(){
add_action("buy", "buy");
add_action("list", "list");
add_action("read","read");
}

int list(){
    write(@ENDLONG

*************************************
*     Drink               Cost    		
*																																			
***************ALCOHOLIC*************
*1) Boring Grog            10       
*2) Decent Brew            25       
*3) Nice Liquor            70      
*                                   
**************SOBERING***************
*																																			
*4) Black Coffee           10 						
*5) Dorothy's "Stuff"      20							
*																																			
**************SPIRITUAL**************
*																																			
*6) Wizards Essence        47							
*7) Mana Matrix            100						
*																																			
*************************************

ENDLONG
);
return 1;
}

int read(string arg){
  if(!arg || arg !="sign" && arg !="menu"){ write("Read what?\n"); return 1; }
  if(arg =="sign"){ write(@EndText
 -------------------------------
 |                             |
 | If yer broke, SCRAM!!!!     |
 |                             |
 |     No credit here!         | 
 |                             |
 -------------------------------
EndText
);
return 1; }
  if(arg =="menu"){ list(); return 1; }
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
 if(dude == "coffee")
  {
                           if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            if(makedrunk >0){
                            write("Ahhhhh, that feels good!\n");
                            TP->add("drunk", -1);        
                            return 1;
                            
                            }
                            if(makedrunk < 1){
                                if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            write("Ahhhhh, that feels good!\n");
                            return 1;
                            }
 }
  if(dude == "4")
  {
                           if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                                     return 1; }
                            if(makedrunk >0){
                            write("Ahhhhh, that feels good!\n");
                            TP->add("drunk", -1);        
                            return 1;
                            
                            }
                            if(makedrunk < 1){
                                if(!TP->debit(10)){ write("The bar does not accept credit.\n");
                             return 1; }
                            TP->set("drunk", 0);
                            write("Ahhhhh, that feels good!\n");
                            return 1;
                            }
 }
if(dude == "stuff")
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
                            TP->set("drunk", 0);
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
                            TP->set("drunk", 0);
                            write("You aren't too sure you want to that again!\n");
                            return 1;
                            }
 }

  if(dude=="essence")
  {

                           if(!TP->debit(47)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("You feel lightheaded.\n");
                            TP->add("spell_points", 5 + random(25));
                           
                            return 1;
  }
if(dude=="6")
  {

                           if(!TP->debit(47)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("You feel lightheaded.\n");
                            TP->add("spell_points", 5 + random(25));
                           
                            TP->debit(47);
                            return 1;
  }
 if(dude=="matrix")
  {

                           if(!TP->debit(100)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("You feel your blood boil as energy seeps into you.\n");
                            TP->add("spell_points", 10+random(45) );
                           
                            return 1;
  }
 if(dude=="7")
  {
                           if(!TP->debit(100)){ write("The bar does not accept credit.\n");
                                     return 1;} 
                            write("You feel your blood boil as energy seeps into you.\n");
                            TP->add("spell_points", 10+random(45) );
                           
                            return 1;
  }

if(makedrunk > bedrunk){ write("You are just too drunk to do that.\n"); return 1; }
  if(dude=="grog")
  {                           
                if(!TP->debit(10)){ write("The bar does not accept credit.\n");  return 1; }
                              write("It tastse like crap, but it does get the job done.\n");
                              TP->add("drunk", 1);
                              TP->receive_healing(1 + random(6));
                              
                              return 1;
                        
   
  }
 if(dude=="1")
  { 
                           if(!TP->debit(10)){ write("The bar does not accept credit.\n");  return 1; }
                           write("It tastse like crap, but it does get the job done.\n");
                              TP->add("drunk", 1);
                              TP->receive_healing(1 + random(6));
                              
                              return 1;
                             
   
  }
  if(dude=="brew")
  {
                           if(!TP->debit(25)){ write("The bar does not accept credit.\n");  
                                return 1; }
                             write("The brew slides smoothly down your throat.\n");
                             TP->add("drunk", 3);
                             TP->receive_healing(3 + random(14));
                             
                             return 1;
                             
 } 
if(dude=="2")
  {
                           if(!TP->debit(25)){ write("The bar does not accept credit.\n"); 
                               return 1;}
                             write("The brew slides smoothly down your throat.\n");
                             TP->add("drunk", 3);
                             TP->receive_healing(3 + random(14));
                             
                             return 1;
                          
 }
 if(dude=="liquor")
  {
                           if(!TP->debit(70)){ write("The bar does not accept credit.\n");  return 1; }
                              write("You swear that you can breathe fire!\n");
                              TP->add("drunk", 4);
                              TP->receive_healing(15 + random(21));
                              
                              return 1;
                        
   
  }
if(dude=="3")
  { 
                           if(!TP->debit(70)){ write("The bar does not accept credit.\n");  return 1; }
                              write("You swear that you can breathe fire!\n");
                              TP->add("drunk", 4);
                              TP->receive_healing(15 + random(21));
                              
                              return 1;
                        
   
  }
return 1;
}

