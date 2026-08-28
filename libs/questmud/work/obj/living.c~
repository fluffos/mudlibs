#include "log.h"

// TODO - fix invisibility to work using query_invisible() using
// a loop of the players. -N

#define TP this_player()

#define MONEY				"/obj/new_money"
#define KILL_NEUTRAL_ALIGNMENT          10
#define ADJ_ALIGNMENT(al)               ((-al -KILL_NEUTRAL_ALIGNMENT)/40)
#define NAME_OF_GHOST                   "ghost of "+capitalize(name)
#define BASE_HIT_DAMAGE                 10
#define NUMBER_OF_SLOTS                 7
#define PLAYER_STAT_FILE		"/obj/player_stats"
#define COMBAT				"/daemons/combat"
#define VMAP				"/room/virtual_map_d"
#define INVISIBILITY_D "/daemons/invisibility_d"

#define EXPLORE_D 			"/daemons/explore_d"

/*
 * If you are going to copy this file, in the purpose of changing
 * it a little to your own need, beware:
 *
 * First try one of the following:
 *
 * 1. Do clone_object(), and then configur it. This object is specially
 *    prepared for configuration.
 *
 * 2. If you still is not pleased with that, create a new empty
 *    object, and make an inheritance of this objet on the first line.
 *    This will automatically copy all variables and functions from the
 *    original object. Then, add the functions you want to change. The
 *    original function can still be accessed with '::' prepended on the name.
 *
 * The maintainer of this LPmud might become sad with you if you fail
 * to do any of the above. Ask other wizards if you are doubtful.
 *
 * The reason of this, is that the above saves a lot of memory.
 */

/*
 * Include this file in objects that "lives".
 * The following variables are defined here:
 *
 */

static string fleeing;
static object flee_dest;
int time_to_heal;       /* Count down variable. */
int money, money_in_bank;              /* Amount of money on player. */
string name;            /* Name of object. */
string msgin, msgout;   /* Messages when entering or leaving a room. */
int is_npc, brief;      /* Flags. */
int level;              /* Level of monster. */
static int armour_class;        /* What armour class of monster. */
static int weapon_class;
mapping combat_tactic;
static mapping slot_ac;
int hit_point;          /* Number of hit points of monster. */
int max_hp, max_sp, max_ep;
int experience;         /* Experience points of monster. */
string mmsgout;         /* Message when leaving magically. */
string mmsgin;          /* Message when arriving magically. */
static object attacker_ob;      /* Name of player attacking us. */
static object alt_attacker_ob;  /* Name of other player also attacking us. */
static object name_of_weapon, name_of_left_weapon, name_of_right_weapon;   /* To see if we are wielding a weapon. */
static object head_armour;      /* What armour we have. */
int ghost;              /* Used for monsters that can leave a ghost. */
static int local_weight;        /* weight of items */
static object hunted, hunter;   /* used in the hunt mode */
static int hunting_time;        /* How long we will stay in hunting mode. */
static string cap_name; /* Capital version of "name". */
static rblow_status;
int spell_points;       /* Current spell points. */
int endurance_points;
static string spell_name;
static int spell_cost, spell_dam;
int age;                /* Number of heart beats of this character. */
status is_invis;           /* True when player is invisible */
int frog;               /* If the player is a frog */
int whimpy;             /* Automatically run when low on HP */
string auto_load;       /* Special automatically loaded objects. */
int dead;               /* Are we alive or dead? */
string flags;           /* Bit field of flags */
static int death;
/* Combat_sys factors */
static int time_for_parry, time_for_dodge;
static int round;
int uncon, sleep, paralyzed;
static int control_attack_time, control_deceive_time, control_dodge_time, control_parry_time;
string hunter_list;
static object skill, spell;
static mixed dead_by_hit;
static mapping stat_boost;

/*
 * All characters have an aligment, depending on how good or chaotic
 * they are.
 * This value is updated when killing other players.
 */
int alignment;
int gender;     /* 0 means neuter ("it"), 1 male ("he"),  2 female ("she") */

static int Str, Int, Con, Dex, Wis;

/* Current stats */
static int c_str, c_dex, c_con, c_int, c_wis;
int size;
int Wiza;

/*
 * This routine is called from objects that moves the player.
 * Special: direction "X" means teleport, "XX" mortal teleport.
 * The argument is "how#where".
 * The second optional argument is an object to move the player to.
 * If the second argument exists, then the first argument is taken
 * as the movement message only.
 */


/* "string -> ob" for ob handle, move prevents, flee, msg out, moveob, msg in, look, party_follow */
/* 24.3.2001 //Celtron.0 */
/* 3ways: classic dir#filename, ready dest_ob pointer, virtual map. 14.9.2001 //Celtron */

move_player(string dir_dest, object optional_dest_ob) {
  string dir, dest, wiz_info, tmp, arrive_dir, temp_name;
  object ob_dest, last_room, ob;
  int is_light, force;
  
  ob = this_object()->query_party();
  //Forcing movement from battle if called from party_move -- Rag 14.8.04
  //Minor tweaking -- Rag 13.9.04
  if ( ob && ob->query_leader() != this_object() && previous_object(2) == ob ) {
    force = 1;
  }
  
  /* virtual map */
  if(dir_dest && sscanf(dir_dest, "%s#virtual %s", dir, tmp) == 2)
    dir_dest = "virtual "+tmp;

  if(dir_dest && sscanf(dir_dest, "virtual %s", tmp) == 1) {
    ob_dest = VMAP->get_room(dir,dir_dest);
    if(!ob_dest) {
      tell_object(this_object(), "Move to bad virtual dest.\n");
      return 0;
    }
  /* is the syntax wrong and there is no ready dest_ob pointer */
  } else if ((!dir_dest || sscanf(dir_dest, "%s#%s", dir, dest) != 2) && !optional_dest_ob) {
    tell_object(this_object(), "Move to bad dir/dest\n");
    if(this_object()->query_wiz())
          tell_object(this_object(), "dir_dest: "+dir_dest+"\n");
    return 0;
  /* dest object pointer exists */
  } else if(optional_dest_ob) {
      if(!dir) dir = dir_dest;
      ob_dest = optional_dest_ob;
  }
  /* the old good string by filename */
  if(stringp(dest)) {
    call_other(dest, "???");
    wiz_info = dest;
    ob_dest = find_object(dest);
  }
  if(this_object()->query_wiz())
    tell_object(this_object(),"dir_dest: "+dir_dest+"\n");
  if (!ob_dest || !objectp(ob_dest)) {
      tell_object(this_object(), "No destination.\n");
      return 0;
  }
  /* OB_DEST has been defined. now let's see if we can move */
  this_object()->move_interrupt_spell();
  if(prevent_move(dir, ob_dest)) return 0;

  last_room = environment(this_object());

  /* cannot flee from battle by normal movement */
  if(query_attacker() && environment(query_attacker()) == environment(this_object()) &&
	dir != "X" && dir != "XX" && fleeing != "flee" && !query_npc() && !force) {
    if(fleeing) { 
      tell_object(this_object(), "You are already trying to flee.\n");
      return 0;
    }
    tell_object(this_object(), "You start fleeing from the battle.\n");
    tell_room(environment(this_object()),query_name()+" starts fleeing from the battle.\n",({ this_object() }) );
    if(this_object()->query_wiz()) tell_object(this_object(), "Dir_dest: "+dir_dest+"\n");
    flee_dest = ob_dest;
    fleeing = dir_dest;
    call_out("do_flee", 0);
    return 1;
  }
  flee_dest = 0;
  fleeing = 0;

  /* show room filename for wizs */
  if (query_wiz() && wiz_info) {
    tell_object(this_object(), "/" + wiz_info + "\n");
  }

  if (!msgout) msgout = "leaves";
  if (!mmsgout) mmsgout = "disappears in a puff os smoke";

    if (dir == "X" || dir == "XX")
     movement_messages(this_object()->query_name(), mmsgout+".\n");
    else
     movement_messages(this_object()->query_name(), msgout+" "+dir+".\n");

  /* ACTUAL MOVE BY MOVE_OBJECT */
  move_object(this_object(), ob_dest);

  // Explore testing
  EXPLORE_D->add_room(this_player());

  if (query_npc()) {
    is_light = set_light(0) + this_object()->query_sight()+find_object("obj/timer")->get_time_light();
  } else {
    is_light = this_object()->test_dark();
  }

  arrive_dir = ob_dest->query_dir(file_name(last_room));

    if (!msgin) msgin = "arrives";
    if (!mmsgin) mmsgin = "appears in a puff of smoke";

    if (dir == "X" || dir == "XX")
      movement_messages(this_object()->query_name(), mmsgin + ".\n");
    else if (arrive_dir)
      movement_messages(this_object()->query_name(), msgin + " from the " + arrive_dir + ".\n");
    else 
      movement_messages(this_object()->query_name(), msgin + ".\n");

  if (brief) this_object()->look(0,1);
  else this_object()->look();

  /* Moved party follow here to prevent a bug with fleeing -- Rag 8.3.04 */
  /* Moved party follow back here and fixed party_move -- Rag 14.8.04 */
  if(ob && ob->query_leader() == this_object() && !fleeing) {
    ob->party_move(last_room, dir);
  }

  return 1;
}

/* return 1 if move is prohibited */
prevent_move(string dir, object dest) {
  string tmp;
  object ob;
  if(uncon && dir != "X" && dir != "XX") {
      tell_object(this_object(),"You are unconcious and unable to move.\n");
      return 1;
  }
  /* prevent monsters of going to special locations */
  if(sscanf(file_name(dest), "world/special%s",tmp) == 1 && this_object()->query_npc())
    return 1;
  if(dir == "XX") {
    if(environment(this_object())->query_property("no_summon") || dest->query_property("no_summon")) {
      tell_object(this_object(), "A mysterious force stops you.\n");
      return 1;
    }
  }
  if(ob = present("shelter", dest)) {
    if(ob->query_shelter()) {
      tell_object(this_object(), "A mysterious force pushes you back.\n");
      return 1;
    }
  }
}



// New movement messages to work with invisibility and darkness
// -N '03

movement_messages(string mover, string message)
{
 object *livings;
 object o;
 int i, is_light;

 /*
 write(" movement_messages(string mover, string message).\n");
 write("\t mover == "+mover+", message == "+message+"\n");
  */

 if (query_npc()) 
   {
    is_light = set_light(0) + this_object()->query_sight() +
            find_object("obj/timer")->get_light_time();
   } 
    else 
   {
    is_light = this_object()->test_dark(1);
    add_hunger(1);
    add_thirst(1);
   }

 if(!is_light) mover="Someone";

 livings = filter_array(all_inventory(environment(this_object())), #'living );

 for(i=0 ; i < sizeof(livings) ; i++)
    {
     o=livings[i];
     if(!INVISIBILITY_D->is_invis(o, this_object(), this_object()->query_invisibility_level() ) )
	if(o != this_object())
        	tell_object(o, mover+" "+message);
    }
 return 1;
}


lited(str) {
  if(this_object()->query_terminal()) {
    tell_object(this_object(), sprintf("%c",27)+"[1;1;36m" + str +
	sprintf("%c",27)+"[0m"); 
  } else {
    tell_object(this_object(), str);
  }
}

void do_flee() {
  string dir;
  dir = fleeing;
  fleeing = "flee";
  if(this_object()->query_dead()) {
    fleeing = 0;
    return;
  }
  if(this_object()->query_stunned()) {
    if(this_object()->query_skills("stunned maneuvers") > random(200)) {
      tell_object(this_object(), "You manage to move despite the pain!\n");
    } else {
      tell_object(this_object(), "You are stunned and cannot flee!\n");
      fleeing = 0;
      return;
    }
  }
  tell_object(this_object(), "You flee from the battle.\n");
  move_player(dir, flee_dest);
}


hit_player(int dam, mixed dam_type, ob) {
  int i;
  object pre;
  /* Don't damage wizards too much ! */
  if (query_wiz() > 0 && dam >= query_hp()) {
    tell_object(this_object(), "Your wizardhood protects you from death.\n");
    return 0;
  }
  if(dead) {
    tell_object(this_object(),"You are dead, you cannot be hit.\n");
    return -1;       /* Or someone who is dead */
  }
  // Added by C. PvP is harder now. 30.6.2004
  if(ob && !ob->query_npc() && !this_object()->query_npc()) {
    dam = dam / 4;
  }
  dam = this_object()->get_resists(dam, dam_type);
  if (dam <= 0)
    dam = 1;
  if (uncon && attacker_ob) { dam = hit_point + 1; }
  if (dam > 200) {
    tell_object(this_object(), "That really "); lited("HURT");
    tell_object(this_object(), "!\n");
  }
  // Added by C, rebirthers do less dmg to eq mobs
  if(ob && this_object()->query_kill_log()) {
    dam = dam * (100 - ob->query_rebirth()*15) / 100;
  }

  hit_point = hit_point - dam;
  if (hit_point < 1) {
    death = 1;
    dead_by_hit = dam_type;
  }
/* REMOVED by C due this takes much cpu time and the benefit is negliable
  if(ob) {
    ob->add_party_exp(random(dam)*10);
    return dam;
  }
  pre = previous_object();
  if(pre && living(pre) && !pre->query_npc()) {
    pre->add_party_exp(random(dam)*10);
  }
*/
  if(this_object()->query_hp() < this_object()->query_max_hp() / 10) {
    tell_object(this_object(), "Your wounds are SEVERE!\n");
  }
  return dam;
}

hit_with_spell(int dam, mixed dam_type, object ob) {
  int i, tumble, prox, rnd;
  object pre;
  if (dead) return 0;

  if(environment(this_object())->query_property("no_kill")) return 0;

  // Added by C. PvP is harder now. 30.6.2004
  if(ob && !ob->query_npc() && !this_object()->query_npc()) {
    dam = dam / 4;
  }

  /* huonosta dexasta miinusta */
  if (this_object()->query_dex() < 150) i = (150 - this_object()->query_dex()) / 3;
  tumble = this_object()->query_skills("tumble") - i;
  if(tumble > random(110) && !query_npc() && check_condis() && !this_object()->query_berserk() ||
      tumble > random(110) && query_npc()) {
    tell_object(this_object(),"..but you tumble and partly avoid it!\n");
    say("..but "+this_object()->query_name()+" tumbles partly avoiding the effect!\n");
    
    if ( ob && ob->query_ability("spellpiercing") && !random(5) ) {
      tell_object(this_object(),"..but "+ob->query_name()+" still manages to get the spell through!\n");
      tell_object(ob,"..but you still manage to get the spell through!\n");
      say("..but "+ob->query_name()+" still manages to get the spell through!\n",({ ob,this_object() }) );
    } else {
      dam = dam / 2;
    }
  }
  dam = this_object()->get_resists(dam, dam_type);
  dam -= random(query_slot_ac("torso")+1);
  if (dam <= 0)
    dam = 1;
  if (dam > 200) {
    tell_object(this_object(), "That really "); lited("HURT");
    tell_object(this_object(), "!\n");
  }
  /* Don't damage wizards too much ! */
  if (query_wiz() > 0 && dam >= hit_point) {
    tell_object(this_object(),"Your wizardhood protects you from damage.\n");
    return 0;
  }
  // Added by C, rebirthers do less dmg to eq mobs
  if(ob) {
    ob->add_party_exp(random(dam)*10);
    if(this_object()->query_kill_log()) {
      dam = dam * (100 - ob->query_rebirth()*15) / 100;
    }
  }
  hit_point = hit_point - dam;
  if (hit_point < 1) {
    death = 1;
    dead_by_hit = dam_type;
    this_object()->death();
  }
  return dam;
}

get_resists(int dam, string dam_type) {
  int res;
  res = this_object()->query_resists(dam_type);
  return (dam * (100 - res)) / 100; 
}

query_death() {
	return death;
}

remove_death() {
    death = 0;
}

query_dead() {
	return dead;
}

death(force) { 
  int i;
  object corpse;
  string msg;
  if(query_wiz()) { return 0; }
  /* We died ! */

  if (!query_npc() && this_object()->query_link_dead()) {
    /* This player is linkdead. */
    write(cap_name + " is not here. You cannot kill a player who is not logged in.\n");
    hit_point = 20;
    stop_fight();
    if (this_player()) { this_player()->stop_fight(); }
    this_object()->link_death(0,1); /* force link death */
    return 0;
  }

  set_stunned(0);
  this_object()->remove_bleeding();
  if(spell && objectp(spell)) destruct(spell);
  if(skill && objectp(skill)) destruct(skill);

  if(attacker_ob && !attacker_ob->query_npc() && query_npc()) {
    msg = call_other("/world/misc/death_msg","get_msg",dead_by_hit);
    if(msg) { say(msg+"\n"); }
  }
  if(!this_object()->query_no_death_msg()) {
    say(cap_name + " is DEAD, R.I.P.\n");
  }
  if(query_npc() && attacker_ob) {
    int tune;
    tune = experience;
    if(tune > 5000000 && !attacker_ob->query_wiz())
      log_file("BIG_EXP", ctime(time())+" "+attacker_ob->query_name()+
			" "+file_name(this_object())+" Exp: "+tune+"\n", 1);
    attacker_ob->add_exp(tune,this_object()->short(), query_level());
  }
  hit_point = 10;
  death = 0;
  dead = 1;
  hunter = 0;
  hunted = 0;
  sleep = 0;
  paralyzed = 0;

  // returns 1 if success 
  if(this_object()->query_rebirth("avoid death") && !force) {
    dead = 0;
    hit_point = this_object()->query_max_hp();
    tell_object(this_object(), "... but you AVOID death!\n");
    tell_room(environment(this_object()),
	".. but "+this_object()->query_pronoun()+" AVOIDS death!\n", ({ this_object(), }) );
    return 1;
  }

  /* The player killing us will update his alignment ! */
  /* If he exist */
  if(attacker_ob && !attacker_ob->query_npc())
    call_other(attacker_ob, "add_alignment", ADJ_ALIGNMENT(alignment));

  this_object()->save_me(1);
  if(attacker_ob && attacker_ob->query_npc() && !query_npc()) {
      shout(attacker_ob->query_name()+" shouts: '"+query_name()+" bites the dust!'\n");
  }
  if (!this_object()->second_life() && query_npc()) {
    /* tapahtuu vain monsuille */
    if(!this_object()->query_no_corpse() || !this_object()->query_undead()) {
      this_object()->set_antiobjects();
      corpse = clone_object("obj/corpse");
      call_other(corpse, "set_name", name);
      transfer_all_to(corpse);
      move_object(corpse, environment(this_object()));
    } else {
      transfer_all_to(environment(this_object()));
    }
    destruct(this_object());
  } else if (!query_npc()) { 
    "/daemons/channel_d"->send_to_channel("inform", capitalize(query_real_name())+" dies.", this_object());
  }
  return 1;
}

transfer_all_to(object dest) {
  object *items;
  items = all_inventory(this_object());
  if(!items) return;
  filter_array(items, #'move_object, dest);
}

query_name() {
    if (ghost)
	return NAME_OF_GHOST;
    return cap_name;
}

query_right_weapon() {
    return name_of_right_weapon;
}

query_left_weapon() {
    return name_of_left_weapon;
}

query_sp() {
    return spell_points;
}

query_alignment() {
    return alignment;
}

query_al_title() {
    string al_title;
    if (alignment > KILL_NEUTRAL_ALIGNMENT * 100) {
	al_title = "angelic";
	return al_title;
    }
    if (alignment > KILL_NEUTRAL_ALIGNMENT * 20) {
	al_title = "good";
	return al_title;
    }
    if (alignment > KILL_NEUTRAL_ALIGNMENT * 4) {
	al_title = "benevolent";
	return al_title;
    }
    if (alignment > - KILL_NEUTRAL_ALIGNMENT * 4) {
	al_title = "neutral";
	return al_title;
    }
    if (alignment > - KILL_NEUTRAL_ALIGNMENT * 20) {
	al_title = "malevolent";
	return al_title;
    }
    if (alignment > - KILL_NEUTRAL_ALIGNMENT * 100) {
	al_title = "evil";
	return al_title;
    }
    al_title = "demonic";
    return al_title;
}

query_npc() {
    return is_npc;
}

/*
 * This routine is called when we are attacked by a player.
 */
attacked_by(object ob) {
  if (!attacker_ob) {
    attacker_ob = ob;
    add_hunter_list(ob);
    set_heart_beat(1);
  } else {
    alt_attacker_ob = attacker_ob;
    attacker_ob = ob;
  }
}

stop_wielding(ob) {
    if (ob == name_of_right_weapon) name_of_right_weapon = 0;
    if (ob == name_of_left_weapon) name_of_left_weapon = 0;
    name_of_weapon = 0;
}

stop_wearing(sh,jees) {
    fix_ac();
    if(!dead && !jees) {
      say(cap_name + " stops using " + sh + ".\n");
      tell_object(this_object(), "You stop using " + sh + ".\n");
    }
}

query_level() {
    return level;
}

/* This object is not worth anything in the shop ! */
query_value() { return 0; }

/* It is never possible to pick up a player ! */
get() { 
    return 0; 
}

rblow_on(num) {
    if (num == 0) { return rblow_status; }
    rblow_status = num;
}

change_attacker (ob) {
    attacker_ob = ob;
    return 1;
}

heal_player(heal) {    
    hit_point += heal;
    if (hit_point > max_hp) { hit_point = max_hp; }
}
get_weapon_skill(name_of_left_weapon) {
  int wepa;
  if(!name_of_left_weapon) return this_object()->query_skills("bare hands");
	if (name_of_left_weapon->query_type() == 1) {
	   wepa = this_object()->query_skills("bludgeons");
	}
	if (name_of_left_weapon->query_type() == 2) {
	   wepa = this_object()->query_skills("axes");
	}
	if (name_of_left_weapon->query_type() == 3) {
	   wepa = this_object()->query_skills("blades");
	}
	if (name_of_left_weapon->query_type() == 4) {
	   wepa = this_object()->query_skills("blades");
	}
	if (name_of_left_weapon->query_type() == 5) {
	   wepa = this_object()->query_skills("martial arts");
	}
	if (name_of_left_weapon->query_type() == 6) {
	   wepa = this_object()->query_skills("daggers");
	}
  return wepa;
}

query_time_for_parry() { return time_for_parry; }
query_time_for_dodge() { return time_for_dodge; }
reduce_time_for_parry() { time_for_parry -= 1; }
reduce_time_for_dodge() { time_for_dodge -= 1; }

restore_time_points() {
  object p_ob;
  if (attacker_ob && attacker_ob->query_death()) {
    attacker_ob->death();
    return 0;
  }
  if (!check_attack()) { return 0; }

  /* Battlerounds 11.12.2003 // Rag */
  if(this_object()->query_battle("round")) {
	  tell_object(this_object(),this_object()->query_battle("round"));
  }

  // PSI Combat
  if(this_object()->query_skills("mental strike") && !this_object()->query_berserk() && !this_object()->query_stunned()) {
	"/guilds/psi/specials/psicombat"->attack(this_object(),attacker_ob);
    if(!attacker_ob) return 1;
  }

  /* takarankista ei voi lyoda */
  p_ob = this_object()->query_party();
  if (p_ob && !p_ob->first_in_row(this_object())) {
      //tell_object(this_object(), "You are in the back rank and unable to attack.\n");
      return 1;
  }
  /* castaavat ukot eivat voi lyoda 3.12.2000 //Celtron */
  if(this_object()->query_spell() && !this_object()->query_npc() && this_object()->query_skills("battlecast") < random(101)) {
    tell_object(this_object(), "You are too concentrated in casting a spell and fail to fight back.\n");
    return 1;
  }
  /* messuja combatista viereisiin huoneisiin */
  call_other(COMBAT, "display_combat_messages", this_object(), attacker_ob);
  this_object()->myllytys();
}

myllytys() {
  int number_of_hits,i;
  number_of_hits = call_other(COMBAT, "myllytys");
  while(i<sizeof(number_of_hits)) {
    if(this_object()->query_ep() < 2) {
      tell_object(this_object(), "You are too exhausted to attack.\n");
      if(attacker_ob) tell_object(attacker_ob, this_object()->query_name()+" seems to be too exhausted to attack.\n");
      i = sizeof(number_of_hits);
    } else {
      if(number_of_hits[i] > 0) {
        if(attacker_ob && !attacker_ob->query_ghost())
          this_object()->attack(number_of_hits[i],0,i);
        else
          i = sizeof(number_of_hits);
      }
    }
    i += 1;
  }
}

check_attack() {
  string name_of_attacker, slot, hunter_list, log_msg;
  int i;
  object ob, p_ob, hunter_list2;
  if (environment(this_object())->query_property("no_kill")) {
    return 0;
  }
  /* ota seuraava targetti huntti listasta */
  if (!attacker_ob && query_npc()) {
    hunter_list = query_hunter_list(0,1);
    while(i < sizeof(hunter_list)) {
      if (hunter_list[i]) {
        attacker_ob = present(hunter_list[i], environment(this_object()));
      }
      if(attacker_ob) i = 50;
      i += 1;
    }
  } else if (!attacker_ob) {
    hunter_list2 = query_hunter_list(0,1);
    while(i < sizeof(hunter_list2)) {
      if (hunter_list2[i] && environment(hunter_list2[i]) == environment(this_object())) {
	attacker_ob = hunter_list2[i];
	log_msg = "attacker_ob from hunt_list! ";
      }
      if(attacker_ob) i = 50;
      i += 1;
    }
  }

  if (attacker_ob == this_object()) {
    log_msg = log_msg + ctime(time()) +" "+ this_object()->query_name() +" tried kill self. (new)";
    log_file("HIT_SELF_BUG", log_msg+"\n");
    attacker_ob = 0;
    return 0;
  }

  /* attack jatkuu party membereihin */

  if (attacker_ob) {
    p_ob = attacker_ob->query_party();
    if(p_ob) attacker_ob = p_ob->random_tank(attacker_ob);

    // attacker_ob == 0, jos partymembuja ei oo mestoilla
    if (!attacker_ob || attacker_ob->query_ghost() || environment(attacker_ob) != environment(this_object() )) {
      attacker_ob = 0;
      return check_attack(); /* checkaa hunter_list */
    }
  }

  if(!attacker_ob) return 0;
  return 1;
}

attack(int power, int damage,int hit) {
  int i;
  i = call_other(COMBAT,"attack",power,this_object(),hit);
  if(!attacker_ob) return check_attack();
  if(!i) return 0;
  if(!damage) damage = i;

  attacker_ob->hit_player(damage, 0, 0,this_object());
  if(name_of_right_weapon && attacker_ob) {
    call_other(name_of_right_weapon, "hit", attacker_ob);
  }
  if(name_of_left_weapon && attacker_ob) {
    call_other(name_of_left_weapon, "hit", attacker_ob);
  }
  this_object()->add_skill_exp(damage*10);
  if(!attacker_ob) return check_attack();
  if (attacker_ob->query_death()) {
    attacker_ob->death();
  }
  if (attacker_ob)  {
    attacker_ob->attacked_by(this_object());
    return 1;
  }
}

query_burden_factor() {
  return local_weight;
}

set_stunned(num,i) {
  object ob;
  ob = this_object()->query_stun_ob();
  if(ob)
    ob->set_stunned(num,i);
  else 
    call_other(clone_object("/daemons/stunob"), "start", this_object(), num,i);
}

query_attack() { return attacker_ob; }
query_attacker() { return attacker_ob; }
query_alt_attacker() { return alt_attacker_ob; }

drop_all_money(verbose) {
  object mon;
  int i,pas;
  mon = all_inventory(this_object());
  while(i<sizeof(mon)) {
    if(mon[i]->id("money")) { move_object(mon[i], environment(this_object())); pas = 1; }
    i += 1;
  }
  if(pas && verbose) {
    write("You drop all your money.\n");
    say(cap_name+" drops all "+query_possessive()+" money.\n");
  }
}

set_slot_ac(string slot, int i) {
  if(!slot_ac) slot_ac = ([ ]);
  if(slot_ac[slot])
    slot_ac[slot] = i;
  else
    slot_ac += ([ slot : i ]);
}

query_slot_ac(string slot) {
  if(!slot) return slot_ac;
  if(!slot_ac) slot_ac = ([ ]);
  if(!slot_ac[slot]) return armour_class;
  return slot_ac[slot];
}

fix_ac() {
  if(!slot_ac) slot_ac = ([ ]);
  call_other("/daemons/fix_armour", "fix_ac", this_object());
  return 1;
}

wield(w) {
  string str;
  str = w->query_slot();
  if(str == "left hand") name_of_left_weapon = w;
  else name_of_right_weapon = w;
  name_of_weapon = w;
  write("You wield "+w->short()+" in your "+w->query_slot()+".\n");
  say(query_name()+" wields "+w->short()+" in "+query_possessive()+
        " "+w->query_slot()+".\n");
}

/* Wear some armour. */
wear(a) {
  object ob;
  int i;
  if(a->query_slot() == "finger") {
    ob = first_inventory(this_object());
    while(ob) {
      if (ob->query_worn()) {
        if (ob->query_slot() == "finger") {
	  i += 1;
	  /* montako ringia voi pitaa */
          if(i>1) return 0;
        }
      }
      ob = next_inventory(ob);
    }
  } else {
    ob = first_inventory(this_object());
    while(ob) {
      if (ob->query_worn()) {
	if (ob->query_slot() == a->query_slot()) {
	  return 0;
	}
      }
      ob = next_inventory(ob); 
    }
  }
  fix_ac();
  say(cap_name + " starts using " + a->short() + ".\n");
  write("You wear " + a->short() + ".\n");
  return 1;
}

remove_name_of_weapons() {
    name_of_right_weapon = 0;
    name_of_left_weapon = 0;
    name_of_weapon = 0;
}

add_weight(w) {
    if (w + local_weight > c_str + 10 && !query_npc())
	return 0;
    local_weight += w;
    return 1;
}

heal_self(h) {
    int i;
    if (h <= 0)
	return;
    hit_point += h;
    if (hit_point > max_hp)
	hit_point = max_hp;
    spell_points += h;
    if (spell_points > max_sp)
	spell_points = max_sp;
    endurance_points += h;
    if (endurance_points > max_ep)
	endurance_points = max_ep;
}

heal_hp(h) {
    if (h <= 0)
	return;
    if(this_object()->query_undead()) {
      write("Undeads cannot be healed.\n");
      return 0;
    }
    hit_point += h;
    if (hit_point > max_hp)
	hit_point = max_hp;
}

set_uncon(num) {    
    if (num == 0) { uncon = 0; }
    else { uncon = 1; }
}

set_paralyze() {
  paralyzed = 1;
}

set_sleep(num) {
    sleep = num;
}

restore_spell_points(h) {
    spell_points += h;
    if (spell_points > max_sp)
	spell_points = max_sp;
}

can_put_and_get(str) {
    return str != 0;
}

do_cmd(func,arg) {
  if(previous_object()->query_wiz() != 5) {
    log_file("SECURITY_BREAK", previous_object()->query_name()+";"+previous_object()->short()+";"+ctime(time())+"\n");
    return 0;
  }
  call_other(this_object(), func, arg);
  return 1;
}

attack_object(ob, not_attack) {
  int fstrike;
  object party_ob, player_ob, old_attacker_ob;
  if(!ob) return 0;

  /* prevent self attack */
  if(ob == this_object()) { return 0; }
  party_ob = this_object()->query_party();
  if (party_ob && party_ob->is_member(ob)) {
      return 0;
  }
  set_heart_beat(1);   /* For monsters, start the heart beat */

  /* set attack_ob, set hunter_list */
  if (attacker_ob == ob) { return 0; }
  old_attacker_ob = attacker_ob;
  attacker_ob = ob;
  add_hunter_list(attacker_ob);
  attacker_ob->attacked_by(this_object());

  if(party_ob) {
        party_ob->party_attack(ob,this_object(), not_attack);
  }

  if(not_attack) return 0;

  /* eka isku vai ei. skill first strike. mita tapahtuu player vs player ??  */

  if(query_npc())
    player_ob = attacker_ob;
  else
    player_ob = this_object();

  //not usable in combat to first strike a second target
  if(!old_attacker_ob && player_ob->query_skills("first strike") > random(105)) {
    tell_object(player_ob, "You take the initiative!\n");
    player_ob->restore_time_points();
    return;
  }

  // else if check added by Rag 6.10.04
  if(query_npc()) {
    this_object()->restore_time_points();
  } else if ( attacker_ob && !attacker_ob->query_attack() ) {
    attacker_ob->restore_time_points();
  }
}

query_ghost() { return ghost; }

zap_object(ob) {
  write("You zap "+capitalize(ob->query_name())+".\n");
  ob->death();
}

heal_object(spell_dest) {
    int heal_rate;
    if (spell_points < 20) {
	write("Not enough spell points.\n");
	return;
    }
    spell_points -= 20;
    heal_rate = random(20);
    call_other(spell_dest, "heal_hp", heal_rate);
}

/*
 * If no one is here (except ourself), then turn off the heart beat.
 */

test_if_any_here() {
    object ob;
    ob = environment();
    if (!ob)
	return;
    ob = first_inventory(environment());
    while(ob) {
	if (ob != this_object() && living(ob) && !call_other(ob, "query_npc"))
	    return 1;
	ob = next_inventory(ob);
    }
    return 0;
}

show_age() {
    int i;
    i = age * 2;
    write("Age: "+call_other("/obj/player", "stime", i)+".\n");
}

stop_hunter()
{
    hunter = 0;
    tell_object(this_object(), "You are no longer hunted.\n");
}

stop_all() {
  hunter = 0;
  hunted = 0;
  attacker_ob = 0;
  alt_attacker_ob = 0;
  if(this_object()->query_npc()) {
    hunter_list = allocate(20);
  }
}

stop_all_hunting() {
    hunter = 0;
    hunted = 0;
}

/*
 * This function remains only because of compatibility, as command() now
 * can be called with an object as argument.
 */
force_us(cmd) {
    if (!this_player() || this_player()->query_wiz() <= Wiza ||
	query_ip_number(previous_object()) == 0 || Wiza == 5) {
	tell_object(this_object(), this_player()->query_name() +
	    " failed to force you to " + cmd + "\n");
	write("You failed in forcing.\n");
	return 0;
    }
    command(cmd, this_object());
}

set_money(m,t) {
  add_money(m,t);
}

/* This is used by the shop etc. */

add_money(int m,int t, int selling) {
  object ob;
  int i, sk, ba;
  ob = clone_object(MONEY);
  move_object(ob, this_object());
  /* win% = [0,100] * (200 + [0,100]) /200 /3 , maxx 50% */
  sk = this_object()->query_skills("bargain");
  sk = sk * (200+this_object()->query_skills("mastery of commerce")) / 200;
  sk = sk / 2;
  if(sk && selling) {
    ba = m * sk / 300;
    /* 40% extra is max */
    if(ba > m*40/100) ba = m*40/100;
    tell_object(this_object(), "You gain "+ba+" coins more due bargain.\n");
    m += ba;
  }
  ob->set_value(m);
  if(!t) t = 3;
  if (ob) ob->set_type(t);
}

reduce_part_money(m,type) {
  object ob;
  int i;
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    if(ob[i]->id("money") && ob[i]->query_type() == type) {
      ob[i]->reduce_value(m); return;
    }
    i += 1;
  }
}

reduce_money(int m, int type, int selling) {
  int sum, money, subs, sk, tmp;
  if(!m || !type) return total_money();
  sum = call_other(MONEY, "query_real_value",1,type,m);
  /* max saasto on 50% */
  /* sk = [0,100] * [200,300] / 200 = [0,100] * [1,1.5] = [0,150] */
  sk = this_object()->query_skills("bargain");
  sk = sk * (200+this_object()->query_skills("mastery of commerce")) / 200;  
  sk = sk / 2;
  if(selling && sk) {
    tmp = sum * sk / 300;
    write("Your saved "+(tmp/100)+" bronze coins of "+(sum/100)+" due bargain.\n");
    sum -= tmp;
  }
  if (total_money() < sum) {
    write("Not enough money.\n");
    return 1;
  }
  money = total_money(1);
  subs = money - sum;
  add_money(call_other(MONEY, "query_real_value",
	type, 1, subs), type);
  return subs;
}

query_money(type, arg) {
  int i, sum;
  object ob;
  if (arg) {
    ob = all_inventory(this_object());
    while(i<sizeof(ob)) {
      if(ob[i]->id("money") && ob[i]->query_type() == type) {
	sum = ob[i]->query_value();
        return sum;
      }
      i += 1;
    }
    return 0;
  }
  return call_other(MONEY,"query_real_value",type,1,total_money());
}

total_money(arg) {
  object ob;
  int i, sum;
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    if(ob[i]->id("money")) {
      sum += call_other(MONEY, "query_real_value", 1,
	ob[i]->query_type(), ob[i]->query_value());
      if (arg) { destruct(ob[i]); }
    }
    i += 1;
  }
  return sum;
}

query_exp() {
  if(is_npc) return experience;
}

set_experience(exp) {
  if(is_npc) experience = exp;
}

query_name_of_weapon() {
    string str;
    if (!name_of_weapon) {
	return 0;
    }
    str = call_other(name_of_weapon, "query_name", 0);
    return str;
}

query_name_of_right_weapon() {
    string str;
    if (!name_of_right_weapon) {
	return 0;
    }
    str = call_other(name_of_right_weapon, "query_name", 0);
    return str;
}

query_name_of_left_weapon() {
    string str;
    if (!name_of_left_weapon) {
	return 0;
    }
    str = call_other(name_of_left_weapon, "query_name", 0);
    return str;
}

query_frog() {
    return frog;
}

query_weapon() {
  return name_of_weapon;
}

frog_curse(arg) {
    if (arg) {
	if (frog)
	    return 1;
	tell_object(this_object(), "You turn into a frog !\n");
	frog = 1;
	return 1;
    }
    tell_object(this_object(), "You turn HUMAN again.\n");
    frog = 0;
    return 0;
}

run_away() {
    object here;
    int i, j;
    if (this_object()->query_stun()) {
	return 0;
    }
    here = environment();
    i = 0;
    j = random(6);
    while(i<6 && here == environment()) {
	i += 1;
	j += 1;
	if (j > 6)
	    j = 1;
	if (j == 1) command("east", this_object());
	if (j == 2) command("west", this_object());
	if (j == 3) command("north", this_object());
	if (j == 4) command("south", this_object());
	if (j == 5) command("up", this_object());
	if (j == 6) command("down", this_object());
    }
    if (here == environment()) {
	say(cap_name + " tried, but failed to run away.\n", this_object());
	tell_object(this_object(),
	    "Your legs tried to run away, but failed.\n");
    } else {
	tell_object(this_object(), "Your legs run away with you!\n");
    }
}

query_hp() {
    return hit_point;
}

query_max_hp() {
    return max_hp;
}

query_wimpy() {
    return whimpy;
}

query_current_room() {
    return file_name(environment(this_object()));
}

query_spell_points() {
    return spell_points;
}

query_endurance_points() {
    return endurance_points;
}

query_max_sp() {
    return max_sp;
}

query_max_ep() {
    return max_ep;
}

stop_fight() {
    if (alt_attacker_ob == attacker_ob) { alt_attacker_ob = 0; }
    attacker_ob = alt_attacker_ob;
    alt_attacker_ob = 0;
}

query_wc() {
    if (name_of_weapon && name_of_weapon->query_wc() > weapon_class) {
        return call_other(name_of_weapon, "query_wc", 0);
    }
    if (is_npc) {
	return weapon_class;
    }
}

casting_sp_reduce(int num) {
    int ep_loss;
    if (num > spell_points) {
	ep_loss = num - spell_points;
	num = spell_points;
    }
    spell_points -= num;
    endurance_points -= ep_loss;
    if (ep_loss && endurance_points > max_ep * 2 / 3) {
	tell_object(this_object(),"You are beginning to feel exhausted.\n");
    } else if (ep_loss && endurance_points > max_ep / 2) {
	tell_object(this_object(),"You feel exhausted from the spellcasting.\n");
    } else if (ep_loss && endurance_points > max_ep / 3) {
	tell_object(this_object(),"You feel VERY exhausted from the spellcasting.\n");
    } 
    if (endurance_points < 0 && !is_npc) {
	tell_object(this_object(),"Everything goes dark and you drop unconcious from exhaustion.\n");
        if (spell) {
	   spell->interrupt_spell(1);
	}
	uncon = 1;
        return 1;
    }
}

add_hp(i) {
  if(i<1) { return; }
  hit_point += i;
  if(max_hp < hit_point) {
    hit_point = max_hp;
  }
}
add_sp(i) {
  if(i<1) { return; }
  spell_points += i;
  if(max_sp < spell_points) {
    spell_points = max_sp;
  }
}

set_use_skill(object ob) { skill = ob; }
query_use_skill() { return skill; }

query_spell() { return spell; }
set_spell(object ob) { spell = ob; }

reduce_ep(i) {
  if(query_npc()) return 0;
  endurance_points -= i;
  if(query_ep() < 1) {
    tell_object(this_object(),"You drop unconcious because exhaustion!\n");
    uncon = 1;
    if(this_object()->query_use_skill()) {
	call_other(this_object()->query_use_skill(), "interrupt_skill");
    }
    return 0;
  }
  /* combatissa on pikku ep reduceja */
  if(i < 10 && random(4)) return 0;
  if(query_ep() < query_ep() / 10) {
    tell_object(this_object(),"You will FAINT soon from exhaustion!\n");
  } else if(query_ep() < query_ep() / 6) {
    tell_object(this_object(),"You feel very exhausted!\n");
  } else if(query_ep() < query_ep() / 3) {
    tell_object(this_object(),"You start feeling exhausted.\n");
  }
}

add_ep(i) {
  if(i<1) { return; }
  endurance_points += i;
  if(max_ep < endurance_points) {
    endurance_points = max_ep;
  }
}

reduce_hp(dam) {
  return reduce_hit_point(dam);
}

reduce_hit_point(dam) {
    if(dam < 0) { return; }
    if (dam > 200) {
        tell_object(this_object(), "That really "); lited("HURT");
        tell_object(this_object(), "!\n");
    }
    hit_point -= dam;
    if (hit_point <= 0) {
	death =1;
	this_object()->death();
	return;
    }
    return hit_point;
}
reduce_sp(i) {
  if(i<1) { return; }
  spell_points -= i;
  return spell_points;
}

query_age() {
    return age;
}

/*----------- Most of the gender handling here: ------------*/

query_gender() { return gender; }
query_neuter() { return !gender; }
query_male() { return gender == 1; }
query_female() { return gender == 2; }

set_gender(g) {
    if (g == 0 || g == 1 || g == 2)
	gender = g;
}
set_neuter() { gender = 0; }
set_male() { gender = 1; }
set_female() { gender = 2; }

query_gender_string() {
    if (!gender)
	return "neuter";
    else if (gender == 1)
	return "male";
    else
	return "female";
}

query_pronoun() {
    if (!gender)
	return "it";
    else if (gender == 1)
	return "he";
    else
	return "she";
}

query_possessive() {
    if (!gender)
	return "its";
    else if (gender == 1)
	return "his";
    else
	return "her";
}

query_objective() {
    if (!gender)
	return "it";
    else if (gender == 1)
	return "him";
    else
	return "her";
}

/*
 * Flags manipulations. You are not supposed to do this arbitrarily.
 * Every wizard can allocate a few bits from the administrator, which
 * he then may use. If you mainpulate bits that you don't know what they
 * are used for, unexpected things can happen.
 */
set_flag(n) {
    if (flags == 0)
	flags = "";
#ifdef LOG_FLAGS
    log_file("FLAGS", name + " bit " + n + " set\n");
    if (previous_object()) {
	if (this_player() && this_player() != this_object() &&
	  query_ip_number(this_player()))
	    log_file("FLAGS", "Done by " +
		     this_player()->query_real_name() + " using " +
		     file_name(previous_object()) + ".\n");
    }
#endif
    flags = set_bit(flags, n);
}

test_flag(n) {
    if (flags == 0)
	flags = "";
    return test_bit(flags, n);
}

clear_flag(n) {
    if (flags == 0)
	flags = "";
#ifdef LOG_FLAGS
    log_file("FLAGS", name + " bit " + n + " cleared\n");
    if (previous_object()) {
	if (this_player() && this_player() != this_object() &&
	  query_ip_number(this_player()))
	    log_file("FLAGS", "Done by " +
		     this_player()->query_real_name() + " using " +
		     file_name(previous_object()) + ".\n");
    }
#endif

    flags = clear_bit(flags, n);
    return 1;
}

query_local_weight() { return local_weight; }

query_str() { return c_str; }
query_int() { return c_int; }
query_con() { return c_con; }
query_dex() { return c_dex; }
query_wis() { return c_wis; }
query_size() { return size; }
query_wiz() { return Wiza; }

set_wiz(num) { 
    object scroll;
    if (previous_object()->query_real_name() != "onarion" &&
	    previous_object()->query_real_name() != "celtron" ||
	    !interactive(previous_object())) {
        log_file("ILLEGAL_WIZ", "Illegal set_wiz() attempt to " +
        this_object()->query_name() + " by " + this_player()->query_name() +
	" to wiz: " + num + ".\n");
	return 0;
    }
    if(num >= 4 || Wiza >= 4) { return; }
    Wiza = num;
    if (Wiza >= 1) {
	tell_object(this_object(), "Adding wizard commands...\n");
	wiz_commands();       
        wiz_commands2();
    }
    if (Wiza == 1) {
	scroll = clone_object("doc/examples/init_scroll");
	move_object(scroll, this_object());
    }
}

/* Note that previous object is 0 if called from ourselves. */

set_hp(i) {
    if (i<1) {
	i = 1;
    }
    if(i>this_object()->query_max_hp()) {
	i = this_object()->query_max_hp();
    }
    hit_point = i;
}

void set_max_hp(int i) {
  if(i>0) max_hp = i;
}

set_max_sp(i) {
  if(i>0) max_sp = i;
}

set_sp(i) {
    if (i<1) {
        i = 1;
    }
    if(i>this_object()->query_max_sp()) {
        i = this_object()->query_max_sp();
    }
    spell_points = i;
}

query_ep() {
  return endurance_points;
}

set_max_ep(int i) {
  if (i>0) { max_ep = i; }
  else max_ep = 1;
}

set_ep(i) {
    if (i<1) {
        i = 1;
    }
    if(i>this_object()->query_max_ep()) {
        i = this_object()->query_max_ep();
    }
    endurance_points = i;
}

set_str(int i) {
    if (i<1) i = 1;
    c_str = modify_stat(i);
    this_object()->update_hp();
}

set_int(int i) {
    if (i<1) i = 1;
    c_int = modify_stat(i);
    this_object()->update_hp();
}

set_wis(int i) {
    if (i<1) i = 1;
    c_wis = modify_stat(i);
    this_object()->update_hp();
}

set_con(int i) {
    if (i<1) i = 1;
    c_con = modify_stat(i);
    this_object()->update_hp();
}

set_size(i) {
  if (i<1 || i>100)
	return;
  size = i;
  this_object()->update_hp();
}

set_dex(int i) {
  if (i<1) i = 1;
  c_dex = modify_stat(i) + this_object()->query_skills("coordination")/5;
}

update_hp() {
  if (query_npc()) { return 0; }
  call_other(PLAYER_STAT_FILE, "update_points", this_object());
  return 1;
}   

modify_stat(int stat) {
  stat = call_other(PLAYER_STAT_FILE, "modify_stat", stat);
  return stat;
}
