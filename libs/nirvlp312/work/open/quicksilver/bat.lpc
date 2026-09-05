#include "/players/quicksilver/666/include/std.h"
inherit MONSTER;

reset(arg) {
   if(!arg) {
      set_race("bat");
      set_name("a bat");
      set_alias("bat");
      set_short("A small, friendly-looking bat");
      set_long("This bat is very peaceful and passive.\nDon't offset it's temper by attacking it.\n");
      set_ac(100000);
      set_hp(100);
      set_level(1);
      set_moveable(1);
      set_move_chance(15);
      set_domain("players/quicksilver");
      msgin="flies in";
      msgout="flies";
   }
   ::reset(arg);
   return 1;
}
