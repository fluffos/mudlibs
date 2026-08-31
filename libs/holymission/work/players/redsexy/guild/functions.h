#define CHECK_ATTACK();\
  if((att = TP->query_attack()) && present(att, ENV(TP))) {\
    write("You cannot do that while attacking.\n");\
    return 1;\
  }
#define CHECK_GHOST();\
  if(TP->query_ghost()) {\
    write("You cannot do that as a ghost.\n");\
    return 1;\
  }
#define CHECK_INTOX();\
  if(TP->query_intoxination() > MAXINTOX) {\
    write("You cannot do that while drunk.\n");\
    return 1;\
  }
#define CHECK_LEVEL(x);\
  if(x > TP->LEVEL) {\
    write("You cannot do that yet.\n");\
    return 1;\
  }
#define CHECK_SP(x);\
  if(x > TP->SP) {\
    write("You do not have enough spell points.\n");\
    return 1;\
  }\
  TP->ADDSP(-x);

#define CHECK_FIGHT();\
  att = TP->query_attack();\
  if(!(att && present(att, ENV(TP)))) {\
    write("You are not fighting.\n");\
    return 1;\
  }
#define CHECK_NO_FIGHT();\
  if(ENV(TP)->query_property("no_fight") ||\
     ENV(TP)->query_no_fight()) {\
    write("This place does not allow you to summon Attackers.\n");\
    return 1;\
  }

#define CHECK_ARM();\
  if(check_arm()) return 1;

#define CHECK_WEAP();\
  if(check_weap()) return 1;

#define ADDHP(x)   reduce_hit_point(-(x))
#define ADDSP(x)   restore_spell_points(x)
#define HIT(x)     hit_player(x)

check_fail(arg) {
  if(arg > random(100)) return 1;
  return;
}

check_arm() {
if(TP->query_worn() && !TP->query_worn()->query_summoner_wear()){
      write("You cannot do that while wearing the " +
      TP->query_wielded()->NAME+ ".\n");
      return 1;
    }
}

check_weap() {
if(TP->query_wielded() && !TP->query_wielded()->query_summoner_wield()){
      write("You cannot do that while wielding the " +
      TP->query_wielded()->NAME+ ".\n");
      return 1;
    }
}
    
new_tell_object(obj, str) {
  int level;
  level = obj->query_earmuff_level();
  obj->listen_shout();
  tell_object(obj, str);
  obj->listen_shout(level);
  return 1;
}

tell_select(str, obj1, obj2) {
  int i;
  object inv;
  object obj;
  if(!(obj = ENV(obj1))) return;
  inv = all_inventory(ENV(obj1));
  for(i = 0; i < sizeof(inv); i++)
    if((inv[i] != obj1) && (inv[i] != obj2))
      TELL(inv[i], str);
  return 1;
}

tell_room_select(room, str, obj1, obj2) {
  int i;
  object inv;
  if(!room) return;
  inv = all_inventory(room);
  for(i = 0; i < sizeof(inv); i++)
    if((inv[i] != obj1) && (inv[i] != obj2))
      TELL(inv[i], str);
  return 1;
}
