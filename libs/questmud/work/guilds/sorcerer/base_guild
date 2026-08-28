inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("north","/guilds/sorcerer/tower/floor1/room8.c");
  add_exit("west", "/guilds/sorcerer/tower/floor1/room11.c");	
  add_exit("south", "/guilds/sorcerer/tower/floor1/room7.c");
  short_desc = "Izyldran's room";
  long_desc = "A huge hall. In the middle of the room is huge statue.\n";
}


init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}
guild_name() {
    return "Sorcerer scholars of the Will";
}

check_joining_rec() {
    return 0;
  }

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;

}

get_bonuses(level) {
  return "wis 2 , int 2";

}
skill_list(int guild_level) {
    mapping skill;

    skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["cast will": 20]);
      skill += (["cast minor ztrand": 20]);
      skill += (["cast wounding": 15]);
      skill += (["recharge staff": 10]);
    }
    if (guild_level >= 2) {
      skill += (["cast will": 30]);
    }
    if (guild_level >= 3) {
      skill += (["cast wounding": 25]);
      skill += (["recharge staff": 20]);
    }
   if (guild_level >= 4) {
      skill += (["cast will": 35]);
      skill += (["cast minor ztrand": 30]);
    }
    if (guild_level >= 5) {
      skill += (["cast wounding": 30]);
      skill += (["recharge staff": 30]);
      skill += (["chanting": 5]);
    }
    if (guild_level >= 6) {
      skill += (["cast will": 40]);
      skill += (["cast minor ztrand": 40]);
      skill += (["cast wounding": 35]);
    }
    if (guild_level >= 7) {
      skill += (["cast will": 45]);
      skill += (["recharge staff": 40]);
      skill += (["chanting": 10]);
    }
    if (guild_level >= 8) {
      skill += (["cast wounding": 40]);
}
     if (guild_level >= 9) {
      skill += (["cast minor ztrand": 50]);
       }
    if (guild_level >= 10) {
      skill += (["cast will": 50]);
      skill += (["cast wounding": 45]);
      skill += (["recharge staff": 55]);
      skill += (["knowledge of power": 5]);
      skill += (["chanting": 20]);
      skill += (["sorcerers touch": 5]);
    }
    if (guild_level >= 11) {
      skill += (["path of the will": 5]);
    }
    if (guild_level >= 12) {
      skill += (["cast will": 60]);
      skill += (["cast minor ztrand": 55]);
      skill += (["cast wounding": 50]);
    }
      if (guild_level >= 13) {
      skill += (["cast minor ztrand": 60]);
      skill += (["recharge staff": 70]);
      skill += (["path of the will": 10]);
    }
    if (guild_level >= 14) {
      skill += (["chanting": 30]);
      skill += (["sorcerers touch": 20]);
}
    if (guild_level >= 15) {
      skill += (["cast minor ztrand": 70]);
      skill += (["cast wounding": 60]);
      skill += (["recharge staff": 85]);
      skill += (["knowledge of power": 10]);
      skill += (["sorcerers touch": 30]);
      skill += (["path of the will": 15]);
      }
    if (guild_level >= 16) {
      skill += (["cast will": 75]);
      skill += (["cast wounding": 70]);
      skill += (["knowledge of power": 15]);
    }
    if (guild_level >= 17) {
      skill += (["cast minor ztrand": 80]);
      skill += (["recharge staff": 100]);
      skill += (["sorcerers touch": 30]);
    }
    if (guild_level >= 18) {
      skill += (["knowledge of power": 20]);
      skill += (["sorcerers touch": 40]);
    }
    if (guild_level >= 19) {
      skill += (["cast will": 85]);
      skill += (["cast minor ztrand": 85]);
      skill += (["cast wounding": 80]);
      skill += (["path of the will": 20]);
}
     if (guild_level >= 20) {
      skill += (["cast will": 100]);
      skill += (["cast minor ztrand": 100]);
      skill += (["cast wounding": 100]);
      skill += (["knowledge of power": 35]);
      skill += (["chanting": 40]);
      skill += (["sorcerers touch": 50]);
      skill += (["path of the will": 30]);
}
return skill;
}

