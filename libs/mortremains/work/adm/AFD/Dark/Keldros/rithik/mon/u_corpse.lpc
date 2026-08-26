#include <mudlib.h>
#include "../defs.h"
inherit MONSTER;

void set_default(){
             set("short", "the undead corpse of something strange");
             set("long", "It appears to be humanoid, but the many years of decay,\nand worm feeding have had quite a toll\non the cosmetics of the body.\n");
             set("gender", "neuter");
             add("id", ({ "humanoid", "something", "something strange" }));
             set_name("humanoid");
             set("weapon_name", "fists");
             add("race", "dwarf");
}

   void is_wrink(){
               set("short","the undead corpse of Mrs. Wrinkleberry.");
               set("long", "It looks like she died of old age.\n");
               set("att_chat_output", ({ "Mrs. Wrinkleberry says:\"You are very noughty!, You need to be tought a good lesson!\"\n", }));
               set("gender", "female");
               add("id", ({"wrinkleberry"}));
               set("weapon_name", "broken cane");
               set_verbs( ({ "swing at", "attempt to clonk" }));
               set_name("mrs. Wrinkleberry");
               add("race", "dwarf");
               }

   void is_war(){
                set("short","the undead corpse of an unfortunate warrior.");
                set("long", "The corpse has a huge gash in the middle of his forehead, exposing\ndecayed brain matter.\n");
                add("id", ({"warrior"}));
                set("gender", "male");
                set_name("unfortunate warrior");
                set("weapon_name", "ruined hand-axe");
                wear(ARMOR(u_armor), "armor");
               set_verbs( ({ "chop at", "swing at", "attack" }) );
               add("race", "dwarf");
           }

  void is_kronk(){       
               set("short","the undead corpse of old Mr. Kronk");
               add("id", ({ "kronk"}));
               set("long", "The old man must have been chopping wood when he died,\nfor splinters cover his hands.\n");
                set("gender", "male");
                set_name("old Mr. Kronk");
               set("weapon_name", "fists");
              add("race", "dwarf");
              }

  void is_krauss(){     
               set("short","the undead corpse of Mr. Krauss");
               set("long", "This man must have died from poisoning, because he has no marks on his body.\n");
               set_name("mr. Krauss");
               add("id", ({ "krauss" }));
               set("gender", "male");
               set("weapon_name", "fists");       
               add("race", "dwarf");
        }

  void is_barney(){
              set("short","the undead corpse of Barney, a faithful hound");
              set("long", "He's was a good dog.\n");
              add("id", ({ "barney", "hound" }));
              set("gender", "neuter");
              set_name("barney, the faithful hound");
              set("weapon_name", "frothing teeth");
              set_verbs(({ "bite at", "chomp at", "tear at" }));
         }

void create(){
enable_commands();
  ::create();
 switch(random(6)){
   case 0: if (find_living("mrs. Wrinkleberry")){ set_default(); }else{ is_wrink(); } break;
   case 1: if (find_living("unfortunate warrior")){ set_default(); }else{ is_war(); }; break;
   case 2: if (find_living("mr. Krauss")){ set_default(); }else{ is_krauss(); } break;
   case 3: if (find_living("old Mr. Kronk")){ set_default(); }else{ is_kronk(); } break;
   case 4: if(find_living("barney, the faithful hound")){ set_default(); }else{ is_barney(); } break;
   default: set_default(); break;
 }
  set_verbs( ({ "clobber at", "swing at", "attack", "jab at" }) );
  set("author", "Waxer");
  add("id", ({ "corpse", "dwarf" }) );
  set("size", 4);
  set("undead", 1);
  set_level(7);
  credit(random(100)+25);
  set("weapon", 13);
  set("damage", ({ 5, 20 }) );
set_alignment(-random(10)-15);

}
