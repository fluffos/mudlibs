inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({ "a goblin warrior", "goblin", "warrior" }));
     set_short("a goblin warrior is staring at you with bloodlust in his eyes");
     set_long(wrap("Before you stands a goblin warrior.  His skin is dark green and his eyes "+
      "are a bright, burning red.  He is around 5 and 1/2 feet tall and is rather ugly.  "+
      "He stares at you with bloodlust in his eyes and prepares to run you through with "+
      "his longsword.\n"));

     set_race ("goblin");

     set_language("grahnik");

     set_emote(({"The goblin grunts something under it's breath.", 
                 "The goblin slobbers all over itself."}));

     set_talk(({"We claim the forest for ourselves!"}));
     
     set_wander(1, 30);
     set_gender (1);     
     
     add_weapon("iron_longsword");
     
     set_levels(([ "fighter" : 9 + random(8) ]));

     set_aggressive();
     add_alignx (-random(200));
     add_aligny (-random(200));
     add_money (0 + random(2));
}
