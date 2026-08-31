// Specially made for roston -- the lava daemon by inferno
#include <daemons.h>
#include <std.h>
#define TIME    3

string *MESSAGE = ({
"Lava drips down from the ceiling, onto your head.",
"Scorching hot flames shoot up from the ground, around you!",
"The heat burns your skin!",
"Your blood begins to boil.",
"You accidentally slip and step into a puddle of lava!",
"A sudden wave of heat hits you.",
"Your body bursts into flames, but you manage to put out the fire.",
"You fall to the ground from the unbarable heat, injuring yourself.",
"You begin to feel dizzy from the heat.",
"Flames engulf your body!"
});

string *RANCOL = ({
"%^RESET%^%^RED%^",
"%^RESET%^%^YELLOW%^",
"%^RESET%^%^ORANGE%^",
"%^BOLD%^%^RED%^"
});

inherit DAEMON;
inherit ROOM;


void create() {
 daemon::create();
 room::create();
   set_no_clean(TIME);
 
}

void init()
{
 ::init();
 set_heart_beat(3);
}

void heart_beat() {
 int i, x = random(sizeof(MESSAGE)-1), t = random(sizeof(RANCOL)-1),
     b=0;
 object *ob;

  ob = all_inventory(this_object());
  
  if (random(100) < 77) {
   for (i = 0;i < sizeof(ob);i++) {
      if (interactive(ob[i])) b=1;
        if (!present("lava helm", ob[i]) && !ob[i]->is_monster()) {
         message("info", RANCOL[t]+MESSAGE[x]+"%^RESET%^", ob[i]);
         ob[i]->add_hp(- (random(100)));
         ob[i]->force_me("hp");
        }
   }
  }
// if (!b) set_heart_beat(0);
}


