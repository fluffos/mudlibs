//	/std/living/combat.c
//	from the Nightmare mudlib
//	code for combat
//	based upon the LOS combat by Buddha@TMI
//	created by Descartes of Borg september 1992

#include <std.h>
#include <party.h>
#include <daemons.h>
#include <rooms.h>
#include <council.h>
#include <balance.h>
#include <security.h>

#define MAX_MELEE_WC	    20
#define MAX_ATTACK_BONUS    5
#define NEWBIE_LEVEL 3
#define KILL_RANGE 5
#define DEFAULT_PARALYZE_MESSAGE "You are stiff as stone."

inherit BODY;
inherit SKILLS;

nosave int paralyzed, magic_round;
nosave int hunting;
int wimpy;
private string wimpydir;
private nosave object *attackers;
private  nosave int any_attack;
private  nosave int casting;
private nosave object *hunters;
private  nosave mapping magic_protection;
private  nosave string paralyze_message;

int ok_to_kill(object targ);
void miss(int magic, string type, string target_thing);
void set_casting(int x);
void set_paralyzed(int x, string drow);
void remove_paralyzed();
int query_paralyzed();
int query_outlaw();
int query_ghost();
int query_casting();
int clean_up_attackers();
int get_damage(object weap);
void run_away();
void send_messages(int magic, object current, string what, int x);
void set_wimpydir(string str);
void set_wimpy(int x);
string query_wimpydir();
int query_wimpy();
int kill_ob(object victim, int which);
int sight_adjustment();
void continue_attack();
void update_current_skill();
void cease_all_attacks();
private string check_up(string limb);
void execute_attack();
void set_magic_protection(string limb, int x);
void add_magic_protection(mixed *info);
int query_magic_protection(string limb);
int query_magic_round();
string query_paralyze_message();

//  This function is used to initialize various variables

void init_attack() {
    init_complex_body();
    hunters = ({});
    attackers = ({});
    wimpydir = "out";
}

//  Remove dead or non-existing objects out of the list of attackers
// Return true if there are still attackers around

private int clean_up_attackers() {
    object *hunters_tmp, *attackers_tmp, *full_tmp;
    int i, tmp;

    attackers_tmp = ({});
    hunters_tmp = ({});
    full_tmp = attackers + hunters;
    for(i=0, tmp = sizeof(full_tmp); i<tmp; i++) {
        if( !full_tmp[i] || !living(full_tmp[i]) ||
          full_tmp[i]->query_ghost() ||
          (full_tmp[i]->is_player() && !interactive(full_tmp[i]))
        ) continue;
        if(member_array(full_tmp[i], (attackers_tmp+hunters_tmp)) != -1)
          continue;
        if(environment(full_tmp[i]) != environment(this_object()))
            hunters_tmp += ({ full_tmp[i] });
        else attackers_tmp += ({ full_tmp[i] });
    }
    attackers = attackers_tmp;
    hunters = hunters_tmp;
    any_attack = sizeof(attackers);
    hunting = sizeof(hunters);
    return any_attack;
}

//  This is the kill command.  If the victim is not yet attacked
//  then it is entered first into the list of victims.  If it
//  is already in the list, then it becomes the first entry

int kill_ob(object victim, int which) {
    object *borg_people;
    int i;

    borg_people = (object *)victim->query_attackers();
    if(!borg_people) borg_people = ({});
    if(member_array(this_object(), borg_people) == -1)
        if(!ok_to_kill(victim)) {
            message("my_combat", sprintf("Supernatural forces prevent you "
              "from attacking %s.", (string)victim->query_cap_name()),
              this_object());
           return 0;
        }
    /* changed from 0 to 1 to faciliate PK patch */
    if(this_object()->query_attacked()) return 1;
    i = member_array(victim, attackers);
    if( i>-1 ) {
	if(attackers[0] == victim) {
	    if(!which) notify_fail("You are already doing so!\n");
	    return 1;
	}
	attackers[i] = attackers[0];
	attackers[0] = victim;
	return 1;
    }
    attackers = ({ victim }) + attackers;
    any_attack = 1;
    if(!which) victim->kill_ob(this_object(), 1);
    return 1;
}

void set_attackers(object *what) {
    attackers = what;
    any_attack = 1;
}

//  Called from heart_beat
//  Here is where we see if we are dead or in combat

void continue_attack() {
    string attack_limb, lost_limb;
    string *nin;
    object *death;
    int n, xxx;

    if(!environment(this_object()) || this_object()->query_ghost()) return;
    if(this_object()->is_player() && !interactive(this_object())) return;
    if(player_data["general"]["hp"] < 1 && !this_object()->query_ghost() ) {
      if(creatorp(this_object())) {
	player_data["general"]["hp"] = 1;
        message("my_combat", "You are immortal and cannot die.",this_object());
      }
      else {
       if(attackers) {
        if(sizeof(attackers) && attackers[0]) {
	  attackers[0]->adj_alignment( (int)this_object()->query_alignment() );
          attackers[0]->add_kill((string)this_object()->query_name());
          add_death((string)attackers[0]->query_name());
          if(!this_object()->is_player())
            attackers[0]->add_exp((int)this_object()->query_exp() / DEATH_EXP_MOD);
	  else {
	    log_file("kills",
		this_object()->query_name()+" ("+(int)this_object()->query_level()+
                ") was killed by "+attackers[0]->query_name()+" ("+
                (int)attackers[0]->query_level()+"): "+ctime(time())+"\n");
	    log_file("kills",
		file_name(attackers[0])+" (PRIV:"+query_privs(attackers[0])+")\n");
            if(attackers[0]->is_player()) {
              nin = explode((string)attackers[0]->getenv("TITLE"), " ");
              if(!nin || !sizeof(nin) || (n=member_array("$N", nin)) == -1)
                attackers[0]->setenv("TITLE", capitalize(query("race"))+" murderer $N");
              else attackers[0]->setenv("TITLE",
                capitalize(query("race"))+" murderer $N "+
                  implode(nin[n+1..sizeof(nin)-1], " "));
            }
            xxx = sizeof(death = all_inventory(attackers[0]));
            while(xxx--) death[xxx]->notify_kill(this_object());
  	  }
          this_object()->die((attackers && attackers[0] ? attackers[0] : 0));
          attackers = ({});
  	  return;
        }
       }
     }
    }
    if(!any_attack) casting = 0;
    if(!any_attack && !hunting) return;
    if(!clean_up_attackers()) return;
    if(environment(this_object())->query_property("no attack")) return;
    if( (player_data["general"]["hp"] * 100) / player_data["general"]["max_hp"] < wimpy ) {
	run_away();
	return;
    }
    if(!query_paralyzed()) execute_attack();
    else message("my_combat", query_paralyze_message(),
      this_object());
}

void execute_attack() {
    object *weapons;
    object current;
    string this_spell, target_thing;
    int protection, damage, to_hit, pois, i, num_attacks, x;

    if(member_array(this_object(),(object *)attackers[0]->query_attackers())
      == -1) attackers[0]->kill_ob(this_object(), 0);
    if((int)this_object()->query_spell_chance() > random(100)) {
        this_spell = (string)this_object()->get_random_spell();
        if(this_spell) this_object()->force_me(this_spell);
    }
    if(magic_round && !casting) return;
    if(casting) num_attacks = 1;
    else {
        if(!(num_attacks = sizeof(weapons=distinct_array(query_wielded())))) {
            if(random(100) > 160-query_skill("melee")) num_attacks = 2;
            else num_attacks = 1;
        }
    }
    for(i=0; i<num_attacks; i++) {
        target_thing = (string)attackers[0]->return_target_limb();
        if(casting || !sizeof(weapons)) current = 0;
        else current = weapons[i];
        to_hit = (int)attackers[0]->mobility(casting);
        if(casting) to_hit+=3*((int)this_object()->query_stats("intelligence"));
        else {
            to_hit += 35-to_int(percent(query_encumbrance(),
              query_max_encumbrance())/4);
            to_hit += (int)this_object()->query_stats("dexterity");
        }
        if(to_hit < random(110)) {
            if(!current) miss(casting, 0, target_thing);
            else miss(0, (string)current->query_type(), target_thing);
            continue;
        }
        if(casting) damage = casting;
        else {
            damage = get_damage(current) + random(query_sp())/10;
            if(damage > 5 && this_object()->is_player()) add_sp(-1);
        }
        protection = (int)attackers[0]->query_current_protection(target_thing);
        damage += (int)this_object()->query_physical()/2 - protection -
          sight_adjustment();
        if(damage > 0) x = (int)attackers[0]->do_damage(target_thing, damage);
        else x = 0;
        if(current && (pois = (int)current->query_poisoning()) &&
          damage > random(101)) {
            current->add_poisoning(-(pois = random(pois+1)));
            attackers[0]->add_poisoning(pois);
        }
        if(x > 0) {
            add_skill_points("attack", x/ATTACK_ATTACK_SKILL_MOD);
            if(!current && !casting)
              add_skill_points("melee", x/ATTACK_MELEE_SKILL_MOD);
            else if(current) {
                current->decay();
                add_skill_points((string)current->query_type(),
                  x/ATTACK_TYPE_SKILL_MOD);
                this_object()->add_exp(x/ATTACK_DAMAGE_EXP_MOD);
                if(num_attacks > 1)
                  add_skill_points("double wielding",x/ATTACK_DOUBLE_SKILL_MOD);
            }
        }
        else {
            if(!current && !casting) add_skill_points("melee", 1);
            else if(!casting) add_skill_points((string)current->query_type(),1);
            add_skill_points("attack", 1);
            if(num_attacks > 1) add_skill_points("double wielding", 1);
        }
        send_messages(casting, current, target_thing, x);
        if(x > 0) attackers[0]->check_on_limb(target_thing);
    }
    casting = 0;
}

void stop_hunting() {
    hunting = 0;
    hunters = ({});
}
void cease_all_attacks() {
    attackers = ({});
    any_attack = 0;
}

object query_current_attacker() {
    if(!sizeof(attackers)) return 0;
    else return attackers[0];
}

void run_away() {
    string *str, *enters;
    int e, s;

    str = (string *)environment(this_object())->query_exits();
    enters = (string *)environment(this_object())->query_exits();
    if((!str || !(s = sizeof(str))) && (!enters || !sizeof(enters))) {
        message("my_combat", "There is nowhere to run!!!", this_object());
        return;
    }
    message("my_combat", "You run away.", this_object());
    if(member_array(wimpydir, str) != -1)
      this_object()->force_me("go "+wimpydir);
    else if(enters && (e = sizeof(enters)) && member_array(wimpydir,enters)!=-1)
      this_object()->force_me("enter "+wimpydir);
    else if(s) this_object()->force_me("go "+str[random(s)]);
    else this_object()->force_me("enter "+enters[random(e)]);
}

void set_wimpydir(string str) {
    if(!stringp(str)) return;
    wimpydir = str;
}

void set_wimpy(int x) { wimpy = x; }

string query_wimpydir() { return wimpydir; }

int query_wimpy() { return wimpy; }

int get_damage(object weap) {
    int damage, melee, attack, two_handed, double_wielding, use;
    int weap_class;
    int x, y, i, j;
    mixed f;
    object ob;

    attack = query_skill("attack");
    if(!weap) {
	melee = query_skill("melee");
       damage = random(2+((melee*MAX_MELEE_WC)/100)+((attack*MAX_ATTACK_BONUS)/100));
    }
    else {
	weap_class = (int)weap->query_wc();
	use = query_skill((string)weap->query_type());
	if((string)weap->query_type() == "two handed") damage = (use/10) -random(8);
	else damage = (use/7) -5;
	if(num_wielded > 1) {
	    double_wielding = query_skill("double wielding");
            damage = random(damage + (double_wielding*weap_class)/100)/(random(num_wielded)+1);
	}
	else {
	    if( (weap_class + damage) < 0 ) damage = 0;
	    else damage = random( (damage + weap_class + 2) );
	}
	damage += ((attack*MAX_ATTACK_BONUS)/100);
    }
    if(this_object()) damage -= ((int)this_object()->query_intox())/80;
    if(weap) {
        if(!(f=(mixed)weap->query_hit())) return damage;
        if(stringp(f)) message("my_action", f, this_object());
        else damage += (int)((*f)(attackers[0]));
        return damage;
    }
    return damage;
}

void set_casting(int x) { casting = x; }

int query_casting() { return casting; }

void set_magic_protection(string limb, int x) {
    if(!magic_protection) magic_protection = ([]);
    if(!limb) magic_protection["overall"] = x;
    else magic_protection[limb] = x;
}

void add_magic_protection(mixed *info) {
    string limb;
    int time, x, i;

    if(sizeof(info) != 3) return;
    limb = info[i];
    x= info[1];
    time = info[2];
    if(!magic_protection) magic_protection = ([]);
    if(!limb) magic_protection["overall"] += x;
    else magic_protection[limb] += x;
    if(time > 0) call_out("add_magic_protection", time, ({ limb, -x, 0 }) );
}

int query_magic_protection(string limb) {
    if(!magic_protection) return 0;
    if(!limb) return magic_protection["overall"];
    else return (magic_protection["overall"] + magic_protection[limb]);
}

void send_messages(int magic, object current, string what, int x) {
    string your_name, my_name;
    string me, you, others, used, type;
    string *verb, *adverb;
    int i;

    your_name = (string)attackers[0]->query_cap_name();
    my_name = query_cap_name();
    if(magic) type = "magic";
    else if(current) type = (string)current->query_type();
    else type = "melee";
    i = x/4;
    if(i<0) i=0;
    if(i>11) i=11;
    if(current) used = (string)current->query_name();
    else if(magic) used = "magic";
    else {
        used = limbs[random(sizeof(limbs))];
        while(used == "torso") used = limbs[random(sizeof(limbs))];
    }
    if(x < 1) {
        me = "You hit "+your_name+" ineffectively in the "+what+".";
        you = my_name+" hits you ineffectively in the "+what+".";
        others = my_name+" hits "+your_name+" ineffectively in the "+what+".";
    }
    else if(used == "head") {
        if(x < 5) {
            me = "You bonk "+your_name+" viciously in the head.";
            you = my_name+" bonks you viciously in the head.";
            others = my_name+" bonks "+your_name+" viciously in the head.";
        }
        else {
            me = "You headbutt "+your_name+" furiously.";
            you = my_name+" headbutts you furiously.";
            others = my_name+" headbutts "+your_name+" furiously.";
        }
    }
    else {
      if(type == "magic" || type == "melee" || type == "blunt" ||
        type == "two handed" || type == "projectile") {
        verb = ({ "tap", "tickle", "sting", "hurt", "strike", "strike",
          "send", "knock", "slam", "blast", "destroy", "destroy"
        });
        adverb = ({ "innocently", "lightly", 0, "mildly", "badly", 0,
          "a bone crushing blow", 0, "mercilessly", "powerfully", 0, "utterly"
        });
      }
      else if(type == "blade" || type == "knife") {
        verb = ({ "tap", "tickle", "sting", "graze", "cut", "slice",
          "slice", "shear", "strike", "mutilate", "dismember", "destroy"
        });
        adverb = ({ 0, 0, "sharply", 0, 0, 0, "horribly", "to pieces",
          "letting blood", 0, 0, "utterly"
        });
      }
      me = sprintf("You %s %s%sin the %s with your %s.", verb[i], your_name,
        (adverb[i] ? " "+adverb[i]+" " : " "), what, used);
      you = sprintf("%s %ss you%sin the %s with %s %s.", my_name, verb[i],
        (adverb[i] ? " "+adverb[i]+" " : " "), what,
        (string)this_object()->query_possessive(), used);
      others = sprintf("%s %ss %s%sin the %s with %s %s.", my_name, verb[i],
        your_name, (adverb[i] ? " "+adverb[i]+" " : " "), what,
        (string)this_object()->query_possessive(), used);
    }
    message("my_combat", me, this_object());
    message("my_combat", you, attackers[0]);
    message("other_combat", others, environment(this_object()),
      ({ attackers[0], this_object() }));
}

object *query_hunted() { return hunters; }

object *query_attackers() {
    if(!attackers) return ({});
    if(!sizeof(attackers)) return ({});
    return attackers;
}

int sight_adjustment() {
    int elight, ret;

    ret = 0;
    elight = effective_light(this_object());
    if(elight >6 || elight < 1)
	ret = random(5);
    if(attackers[0] && attackers[0]->query_invis()) {
	ret += 45 / (1+random((int)this_object()->query_skill("wisdom")));
        attackers[0]->add_sp(-ret);
    }
    return ret;
}

void miss(int magic, string type, string target_thing) {
    string you, me;
    string *missed;

    you = (string)attackers[0]->query_cap_name();
    me = query_cap_name();
    if(magic) {
        message("my_combat", "Your magic powers fail you.", this_object());
        message("my_combat", sprintf("%s's magic powers fail in an attack "
          "on you.", me), attackers[0]);
        message("other_combat", sprintf("%s's magic powers fail in an attack "
          "on %s.", me, you), environment(this_object()),
          ({ this_object(), attackers[0] }));
        return;
    }
    missed = ({
      "You miss.",
      "You deal a deadly blow... to empty space!",
      you+" sidesteps your poorly planned attack.",
      "You decide to daydream a moment instead of attack.",
      "A swing and a miss...  Strike "+(1+random(3))+" for you!",
      you+" dances around as you miss.",
      you+" never knew what missed "+(string)attackers[0]->query_objective()+".",
      you+" dodges your inept attack."
    });
    message("my_combat", missed[random(sizeof(missed))], this_object());
    message("other_combat", sprintf("%s misses %s attack on %s.",
      me, (string)this_object()->query_possessive(), you),
      environment(this_object()), ({ this_object(), attackers[0] }));
    message("my_combat", sprintf("%s missed you.", me), attackers[0]);
}

void set_paralyzed(int x, string drow) {
    if(archp(this_object())) {
        message("my_action", "Your Archhood just saved you from being "
          "paralyzed.", this_object());
        return;
    }
    if(!drow)
        paralyze_message = DEFAULT_PARALYZE_MESSAGE;
    else
        paralyze_message = drow;
    paralyzed = 1;
    call_out("remove_paralyzed", x);
}

string query_paralyze_message() { return paralyze_message; }

int query_paralyzed() { return paralyzed; }

void remove_paralyzed() {
    if(!this_object()) return;
    remove_call_out("remove_paralyzed");
    paralyzed = 0;
    message("my_combat", "You can move again.", this_object());
}

int mobility(int magic) {
    int ret;

    if(magic) ret = 70 - (int)this_object()->query_stats("wisdom");
    else {
        ret = to_int(percent(query_encumbrance(),query_max_encumbrance()))/4;
        ret += 35-(int)this_object()->query_stats("dexterity");
    }
    if(ret > 50) ret = 50;
    if(ret < 0) ret = 0;
    return ret;
}

int query_current_protection(string target_thing) {
    int prot, tmp;

    prot = query_ac(target_thing)+query_skill("defense")/15;
    add_skill_points("defense", 2*prot);
    tmp = query_magic_protection(target_thing);
    add_skill_points("magic defense", tmp);
    prot += tmp;
    return prot;
}

void set_magic_round() { magic_round = 1; }

int query_magic_round() { return magic_round; }

int ok_to_kill(object targ) {
    if((int)targ->is_invincible()) return 0;
    if(query_ghost() || (int)targ->query_ghost()) return 0;
    if(creatorp(this_object()) || !userp(this_object()) || !userp(targ))
      return 1;
    if(!query_outlaw() && !((int)targ->query_outlaw()))
      this_object()->set_outlaw(1);
//These lines commented at forlocks request, due to the jail being buggy.
    //if(!((int)targ->query_outlaw()))
      //ROOM_SHERIFF->rescue_me(targ, this_object());
    if(leaderp(this_object())) return 1;
    if((int)targ->query_level() > NEWBIE_LEVEL) return 1;
    return 0;
}

int query_outlaw() { return 0; }

int query_ghost() { return 0; }
