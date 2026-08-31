
// original polymorph by Daboura
// polymorphing players and making it an effect added by Nulvect 2009-04-14

#include <std.h>
#include <rest.h>
#include <rooms.h>
#include <effect_cl.h>
#include <dirs.h>

#define CMD_OB DIR_CLASS_CMDS+"/obj/command"
#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^ORANGE%^"
#define COL2 "%^BOLD%^%^BLACK%^"

inherit DAEMON;

void poly_player(object, object, int);
void poly_mob(object);
mixed *chicken_info(object);

string intricate =
  "%^BOLD%^%^WHITE%^in%^RESET%^%^CYAN%^tr%^BOLD%^%^WHITE%^ic%^RESET%^%^CYAN%^ate%^RESET%^"
;

int spell() {
  object tp = this_player();
  if (tp->query_subclass() == "wizard" &&
      tp->query_skill("conjuring") >= to_int(35*4.5) &&
      tp->query_skill("wizardry") >= 35*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <polymorph [who]>\n\n"
    "A powerful wizard can transform a creature into a less fearsome beast "
    "with this strange and old spell.\n"
    "Its effect against other players will be temporary unless they <allow> "
    "you to permanently lower them.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack") ||
      environment(tp)->query_property("no magic"))
        FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("It is too dangerous to manipulate such "
         "powerful magic in your current state.");

  if (!tgt)
    FAIL("Polymorph who?");

  if (!(tgt->is_player() || tgt->is_monster()))
    FAIL("This magic only works against living things.");

  if (tgt->query_property("no polymorph") ||
      tgt->query_property("no magic"))
        FAIL(tgt->query_cap_name()+" is immune to such magic.");

  if (tgt->query_effect("polymorph"))
    FAIL(
      (tgt == tp ? "You have" : capitalize(tgt->query_subjective())+" has")+
      " already been polymorphed!");

  if (tp->query_mp() < 100)
    FAIL("Your magic is too low.");

  return 1;
}

int cmd_polymorph(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *allowed;
  int cost, allow;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  cost = tp->query_skill("wizardry")/5 + random(tp->query_stats("wisdom")/2);

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  allowed = tgt->query_allow("polymorph");
  if (member_array(tp->query_name(), allowed) != -1)
    allow = 1;

  if (!allow &&
      (tgt->query_skill("magic defense") > tp->query_skill("conjuring") ||
      tgt->query_stats("wisdom")*3/2 > tp->query_stats("wisdom")))
        FAIL("Your magic bounces off of "+tgt->query_cap_name()+"!");

  message("magic", COL+"You move your hands in an "+intricate+COL+" pattern, "
    "and suddenly a cloud of "+COL2+"smoke"+COL+" appears around "+
    tgt->query_cap_name()+" then fades away!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" moves "+tp->query_possessive()+
    "hands in an "+intricate+COL+" pattern, "
    "and suddenly a cloud of "+COL2+"smoke"+COL+" appears around "
    "you then fades away!\n\n"+COL2
    "You feel an overwhelming urge to cluck... like a chicken."+RES, tgt);
  message("magic", COL+tp->query_cap_name()+" moves "+tp->query_possessive()+
    "hands in an "+intricate+COL+" pattern, "
    "and suddenly a cloud of "+COL2+"smoke"+COL+" appears around "+
    tgt->query_cap_name()+" then fades away!"+RES, env, ({ tp, tgt }) );

  if (tgt->is_player()) {
    cost *= 3;
    poly_player(tp, tgt, allow);
  }
  else if (tgt->is_monster())
    poly_mob(tgt);

  tp->add_mp(-cost);
  tp->set_magic_round(1);
  tp->add_skill_points("conjuring", 10+random(10));
  tp->add_skill_points("wizardry", 10+random(10));

  return 1;
}

void poly_player(object tp, object tgt, int perm) {
  class Effect poly = new(class Effect);
  object *eq;
  object cmd;
  mapping debuff = allocate_mapping(25);
  mixed *info;
  int time;
  
  cmd = new(CMD_OB);
  if (!cmd) {
    message("info", "An error occurred, please contact a staff member.", tp);
    return;
  }

  cmd->set_id( ({ "polymorph_spell_cmd_ob" }) );
  cmd->set_command( ({ "fly", "wield", "wear" }) );
  cmd->set_function(this_object(), "catch_cmds");
  cmd->set_notify("catch_die");
  cmd->move(tgt);
  debuff["cmdob"] = cmd;

  // min 8 rounds, add 1 round for every 10 int past 50
  time = (8+((tp->query_stats("intelligence")-50)/25))*2;

  eq = all_inventory(tgt);
  eq->set_theft(1);
  eq->unequip();
  eq->set_theft(0);

  if (perm) {
    int level;
    if (tgt->query_level() > 20) {
      level= tgt->query_level() - (2+random(4));
      if (level < 20) level = 20;
      tgt->set_level(level);
      tgt->fix_skills();
      if (random(100) >= 80) {
        string *stats = tgt->query_all_stats();
        string stat = stats[random(sizeof(stats))];
        tgt->set_stats(stat, tgt->query_base_stats(stat) - 1);
      }
    }
    tgt->remove_allow("polymorph", tp->query_name());
    time *= 2;
  }

  poly->name = "polymorph";
  poly->target = tgt;
  poly->caster = tp;
  poly->castername = tp->query_name();
  poly->desc = "You have been polymorphed into a chicken!";
  poly->endmessages = ({
    COL+"A puff of "+COL2+"smoke"+COL+" surrounds you as you "
      "change back into "+COL2+indefinite_article(tgt->query_race())+COL+"!",
    COL+"A puff of "+COL2+"smoke"+COL+" surrounds "+tgt->query_cap_name()+" "
      "as "+tgt->query_subjective()+" "
      "changes back into "+COL2+indefinite_article(tgt->query_race())+COL+"!"
  });
  poly->endtime = time() + time;
  // this should be fine here since debuff is a reference type
  poly->misc = debuff;
  poly->endfunc = function(class Effect poly) {
    object tgt = poly->target;
    mapping debuff = poly->misc;
    object cmd = debuff["cmdob"];
    foreach (string stat in tgt->query_all_stats()) {
      int amt = debuff[stat];
      tgt->add_stat_bonus(stat, amt);
    }
    foreach (string skill in tgt->query_all_skills()) {
      int amt = debuff[skill];
      tgt->add_skill_bonus(skill, amt);
    }
    tgt->remove_disguised_name();
    tgt->remove_disguised_short();
    tgt->remove_disguised_long();
    tgt->remove_disguised_id();
    if (cmd) cmd->remove();
  };
  
  foreach (class Effect eff in tgt->query_all_effects()) {
    eff->endmessages = 0;
    tgt->remove_effect(eff);
  }
  foreach (object atk in tgt->query_attackers())
    atk->remove_attacker(tgt);
  tgt->cease_all_attacks();

  foreach (string stat in tgt->query_all_stats()) {
    int amt = tgt->query_stats(stat)*2/5;
    debuff[stat] = amt;
    tgt->add_stat_bonus(stat, -amt);
  }
  foreach (string skill in tgt->query_all_skills()) {
    int amt = tgt->query_skill(skill)*2/5;
    debuff[skill] = amt;
    tgt->add_skill_bonus(skill, -amt);
  }

  info = chicken_info(tgt);

  tgt->set_disguised_name(capitalize(info[0]));
  tgt->set_disguised_short(info[1]);
  tgt->set_disguised_long(info[2]);
  tgt->set_disguised_id(info[3]);

  tgt->fix_vital_bonus();
  tgt->add_effect(poly);

}

void poly_mob(object tgt) {
  object mob;
  mixed *info;

  info = chicken_info(tgt);

  mob = new(MONSTER);
  mob->set_name(info[0]);
  mob->set_short(info[1]);
  mob->set_long(info[2]);
  mob->set_id(info[3]);
  mob->set_level(tgt->query_level()*4/5);
  mob->set_body_type("foul");
  mob->set_race("chicken");
  mob->set_gender(tgt->query_gender());
  mob->set_alignment(tgt->query_alignment());
  mob->set_aggressive(2);

  mob->move(environment(tgt));

  tgt->move(ROOM_VOID);
  if (tgt->query_rest_type() == SLEEP && present("sleep_pillow", tgt))
    present("sleep_pillow", tgt)->remove();

  tgt->remove();
}

mixed *chicken_info(object tgt) {
  string name, short, long, gender;
  string *id = ({});

  gender = tgt->query_gender();

  switch (tgt->query_level()) {
    case 1..9:
      name = "%^YELLOW%^chick%^RESET%^";
      short = "%^YELLOW%^chick%^RESET%^";
      long = "A very small and young chick, it looks so cute and cuddly.";
      id = ({ "chick" });
    break;

    case 10..29:
      switch (gender) {
        case "male":
          name = "rooster";
          short = "%^BOLD%^%^RED%^R%^BLACK%^o%^RED%^o%^BLACK%^s%^RED%^t%^BLACK%^e%^RED%^r%^RESET%^";
          long = "A small rooster stands here, perhaps looking for a mate.";
          id = ({ "rooster" });
        break;
        case "female":
          name = "hen";
          short = "%^BOLD%^%^WHITE%^H%^RED%^e%^WHITE%^n%^RESET%^";
          long = "A small regular hen, perhaps looking for a place to lay eggs.";
          id = ({ "hen" });
        break;
        default:
          name = "chicken";
          short = "%^BOLD%^%^WHITE%^Ch%^RED%^i%^WHITE%^c%^RED%^k%^WHITE%^en%^RESET%^";
          long = "A confused looking chicken.";
      }
    break;

    case 30..49:
      switch (gender) {
        case "male":
            name = "large rooster";
            id = ({ "rooster", "large rooster" });
            short = "Large %^BOLD%^%^RED%^r%^BLACK%^o%^RED%^o%^BLACK%^s%^RED%^t%^BLACK%^e%^RED%^r%^RESET%^";
            long = "A large rooster, he is searching for food.";
        break;
        case "female":
            name = "large hen";
            id = ({ "large hen", "hen" });
            short = "Large %^BOLD%^%^WHITE%^h%^RED%^e%^WHITE%^n%^RESET%^";
            long = "A large hen, looking for food to gather.";
        break;
        default:
            name = "chicken";
            short = "Large %^BOLD%^%^WHITE%^ch%^RED%^i%^WHITE%^c%^RED%^k%^WHITE%^en%^RESET%^";
            long = "A large, confused chicken.";
      }
    break;

    case 50..99:
      switch (gender) {
        case "male":
            name = "mutant rooster";
            id = ({ "rooster", "mutant rooster", "mutant" });
            short = "Mutant %^BOLD%^%^GREEN%^r%^BLACK%^o%^GREEN%^o%^BLACK%^s%^GREEN%^t%^BLACK%^e%^GREEN%^r%^RESET%^";
            long = "A mutant rooster, he looks hungry for meat!";
        break;
        case "female":
            name = "mutant hen";
            id = ({ "hen", "mutant hen", "mutant" });
            short = "Mutant %^BOLD%^%^WHITE%^h%^GREEN%^e%^WHITE%^n%^RESET%^";
            long = "A mutant hen, she looks hungry for blood!";
        break;
        default:
            name = "mutant chicken";
            id = ({ "mutant chicken", "mutant" });
            short = "Mutant %^BOLD%^%^WHITE%^ch%^GREEN%^i%^WHITE%^c%^GREEN%^k%^WHITE%^en%^RESET%^";
            long = "A confused mutant chicken, it looks hungry for brains!";
      }
    break;

    case 100..1000:
      switch (gender) {
        case "male":
            name = "king rooster";
            id = ({ "rooster", "king rooster", "king" });
            short = "King %^BOLD%^%^CYAN%^r%^BLACK%^o%^CYAN%^o%^BLACK%^s%^CYAN%^t%^BLACK%^e%^CYAN%^r%^RESET%^";
            long = "The king rooster, he watches over all other roosters.";
        break;
        case "female":
            name = "queen hen";
            id = ({ "hen", "queen hen", "queen" });
            short = "Queen %^BOLD%^%^WHITE%^h%^CYAN%^e%^WHITE%^n%^RESET%^";
            long = "The queen hen, she watches over all other hens.";
        break;
        default:
            name = "jester chicken";
            id = ({ "jester", "jester chicken" });
            short = "Jester %^BOLD%^%^WHITE%^ch%^CYAN%^i%^WHITE%^c%^CYAN%^k%^WHITE%^en%^RESET%^";
            long = "A confused jester chicken, it just likes to play around.";
      }
    break;
  }

  id |= ({ "chicken" });

  return ({ name, short, long, id });
}

int catch_cmds(string str) {
  object tp = this_player();
  object env = environment(tp);
  string verb = query_verb();
  
  switch (verb) {
    case "fly":
      message("info", "You flap your wings as hard as you can, "
        "but fail to leave the ground.", tp);
      message("info", capitalize(tp->query_cap_name())+" flaps "+tp->query_possessive()+
        " wings wildly.", env, tp);
      return 1;
    case "wield":
      message("info", "Your hands have become wings!", tp);
      return 1;
    case "wear":
      message("info", "You cannot seem to make anything fit!", tp);
      return 1;
  }

  return 0;
}

int catch_die(object killer, object victim) {
  class Effect poly = victim->query_effect("polymorph");

  if (!poly) return 0;

  victim->remove_effect(poly);

  return -1;
}
