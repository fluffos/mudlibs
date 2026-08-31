#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "A lizard", "A baby lizard", "A brown lizard",
           "A honry toad" });

 i = random(sizeof(name));
   set_name("lizard");
   set_short(name[i]);
   set_level(i+35);
   set("aggressive", (i+25) );
   set_race("lizard");
   set_body_type("snake");
   set_gender("male");
   set_id(({ "lizard", name[i] }));
 if (name[i]=="A lizard")
   set_long("This Lizard has rough skin and sharp claws. He can "
            "run fast, and has deep black eyes.");
 if (name[i]=="A baby lizard")
   set_long("This Little baby lizard was born a few weeks ago and "
            "is still learning to hunt for food.");
 if (name[i]=="A brown lizard")
   set_long("This lizard is a deep brown color, almost the same "
          "as the sand in most deserts. His skin looks very rough.");
 if (name[i]=="A honry toad")
   set_long("The honry toad lives most of his life in a desert, he "
            "eats what he can find. This honry toad would even eat you.");

}
