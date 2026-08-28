inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("leave","/wizards/moonstar/areas/wasteland/cave5.c");
  short_desc = "The Blade Dancers Guild";
  long_desc = "You have arrived on a small room. There are many dummies\n"+
      "around the room and many strange looking warriors are training\n"+
      "their skills here. There is also a small sign on the wall.\n";

items = allocate(2);
items[0] = "sign";
items[1] = "***************** WELCOME TO THE BLADE DANCERS GUILD******************\n"+
           "*                                                                    *\n"+
           "*  The blade dancers are deadly group of bandits who train to use    *\n"+
           "*  their axe and blade skills. They try to master many hard          *\n"+
           "*  offensive skills and try to understand their weapons better.      *\n"+
           "**********************************************************************";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 10;
}
guild_name() {
  return "blade dancers";
}

check_joining_rec() {
  if(this_player()->query_guild_level("berserkers") < 10) {
    write("You must first complete the guild of berserkers.\n");
    return 0;

  }
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;

}

get_bonuses(level) {
  return "str 1 , dex 1 , ";

}


skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  skill += (["whirling slash":guild_level*10]);
  skill += (["vital points":guild_level*10]);
  skill += (["crushing":guild_level*10]);
  skill += (["finishing move":guild_level*10]);

    if (guild_level >= 10) {
      skill += (["whirling slash":(int) 100]);
      skill += (["vital points":(int) 100]);
      skill += (["crushing":(int) 100]);
      skill += (["finishing move":(int) 100]);
    }
  return skill;
}


