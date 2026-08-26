#include "../defs.h"

inherit MONSTER;
object slip;
int done;
void init(){
add_action("make", "make");
}
void create() {
  seteuid(getuid());
  ::create();
  set("short", "Secillia, the Mayor's secretary");
  set("long", @ENDLONG
Secillia is very well built for a dwarf, with heaving breasts
and blonde hair.  She wears glasses and carries a very sharp
pencil.
ENDLONG
  );
  set_alignment(30);
  set_name("secillia");
  set("id", ({
    "secillia",
    "secretary",
  }));
  set("size", 4);
  set("damage", ({ 8, 20 }) );
  set("armor_class", 3);
  set("attack_strength", 12);
  set("race", "dwarf");
  set("attrib1", "attractive");  set("attrib2", "blonde-haired");
  set("gender", "female");
  set("weapon_name", "a sharp pencil");
  set_verbs( ({
    "attempt to skewer",
    "jab at",
    
}));
  credit(30+random(70));
  set_skill("defense", 3, "dexterity");
  set_skill("attack", 3, "strength");
  set_level(9);
  set("forgetful", 1);
  set("chat_chance", 8);
  set("chat_output", ({
      "Secillia says: \"Would you like an appointment?\"\n",
      "Secillia says: \"The mayor is quite a busy man.\"\n",
      "Secillia shuffles some papers into different piles",
      "The secretary brushes her hair.\n",
}) );
  set("att_chat_output", ({
      "Secellia yells for help.\n",
      "Secillia slaps you hard across the face!\n",
      "Secillia screams at you.\n",
      "The secretary yells: \"You will never get an appointment like this!\"\n",
}) );
}
int make(string str){
if(str !="appointment"){
      write("Make what?\n");
      return 1;
    }
if(done){
    write("Secillia says: 'I am sorry, but the mayors schedule is booked up for 
the week.'\n");
    say(TPN+" tries to make an appointment with the mayor, but it looks like the mayor is booked up for the week.'\n");
    return 1;
  }
      write("The secretary says: \"Thank you, if there is a cancellation, I will let you 
know, take this slip to remind you; the mayor is quite busy this week, but I will 
try to fit you into his schedule.\"\n");
     say(TPN+" makes an appointment to see the mayor.\n");
     clone_object(OBJ(slip))->move(TP);
     TP->improve_skill("Bureaucracy", 1);
     done = 1;
     return 1;
}


