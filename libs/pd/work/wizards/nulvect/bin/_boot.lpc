
#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^WHITE%^"
#define COL2 "%^RED%^"
#define RES "%^RESET%^"

#define BOOT_PROP "boot_abil_time"
#define BOOT_DELAY 45
#define BOOT_CMD_ID "boot_check_cmd"
#define COMMAND_OB DIR_CLASS_CMDS+"/obj/command"

inherit DAEMON;

void end_boot(class Effect);
int check_target(string);


int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("attack") >= to_int(18*4.5))
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <boot [whom]>\n\n"
    "A solid kick to the gut that can double an attacker over "
    "for a moment or two.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your foot would pass right through.");

  if (!tgt)
    FAIL("Boot whom?");

  if (!tgt->is_living())
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("That would be rather difficult.");

  if (tp->query_riding())
    FAIL("You must dismount first!");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_boot(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, ob;
  int dmg, rank, cost, hit, miss, time;
  class Effect boot;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  rank = 2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "attack", "melee" }),
    ({ "strength", "dexterity" }),
    ({ "strength" }) );

  dmg /= 3;

  cost = dmg/6;
  if (cost < 15) cost = 15;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->kill_ob(tgt);
  tp->add_sp(-(cost+random(3+cost/4)));

  hit = tp->query_stats("dexterity");
  hit += tp->query_skill("attack") + 25;

  miss = tgt->query_stats("dexterity");
  miss += tgt->query_skill("defense");

  if (tgt->query_blind())
    hit = miss+50;
  else if (tp->query_blind() || tgt->query(BOOT_PROP) >= time())
    miss = hit+50;

  if (miss > hit+random(10)) {
    message("combat", "You miss your kick at "+tgt->query_cap_name()+".", tp);
    message("combat", tp->query_cap_name()+" misses a kick at you.", tgt);
    message("combat", tp->query_cap_name()+" misses a kick at "+
      tgt->query_cap_name()+".", env, ({ tp, tgt }) );
    return 1;
  }

  time = 2;
  if (tp->query_skill("melee") > tgt->query_skill("defense")/2)
    time += 2;

  message("combat", "You "+COL2+"b"+COL+"oo"+COL2+"t"+RES+" "+
    tgt->query_cap_name()+" right in the gut!", tp);
  message("combat", tp->query_cap_name()+" "+
    COL2+"b"+COL+"oo"+COL2+"t"+COL+"s"+RES+" you right in the gut!", tgt);
  message("combat", tp->query_cap_name()+" "+
    COL2+"b"+COL+"oo"+COL2+"t"+COL+"s"+RES+" "+
    tgt->query_cap_name()+" right in the gut!", env, ({ tp, tgt }) );

  tgt->do_damage("torso", dmg);
  tgt->set(BOOT_PROP, time()+time+BOOT_DELAY);
  tgt->remove_attacker(tp);
  tp->remove_attacker(tgt);

  if (tp->query_stats("strength") > tgt->query_stats("constitution")*175/100) {
    message("combat", "You double over in "+COL2+"pain"+RES+"!", tgt);
    message("combat", tgt->query_cap_name()+" doubles over in "+
      COL2+"pain"+RES+"!", env, tgt);
    tgt->set_paralyzed(time,
      "You are doubled over in pain!", "You finally recover from the kick.");
  }
  else {
    ob = new(COMMAND_OB);
    if (!ob)
      FAIL("An error occurred, please contact a staff member.");
    ob->set_id( ({ BOOT_CMD_ID }) );
    ob->set_catchall(1);
    ob->set_function(this_object(), "check_target");
    ob->move(tgt);
    boot = new(class Effect);
    boot->name = "boot";
    boot->desc = "You have been kicked in the gut!";
    boot->caster = tp;
    boot->target = tgt;
    boot->castername = tp->query_name();
    boot->endtime = time()+time;
    boot->endfunc = (: end_boot :);
    boot->endmessages = ({
      "You finally recover from the kick.",
    });
    boot->misc = ob;
    tgt->add_effect(boot);
  }

  return 1;
}

void end_boot(class Effect boot) {
  object tgt = boot->target;
  object ob = boot->misc;
  if (ob)
    ob->remove();
  else if (tgt && tgt->query_paralyzed())
    tgt->remove_paralyzed();

  if (tgt && tgt->is_monster() && boot->caster) {
    tgt->force_me("kill "+boot->castername);
    tgt->kill_ob(boot->caster);
  }
}

int check_target(string str) {
  object tp = this_player();
  object env = environment(tp);
  class Effect boot;
  object caster, cmd;
  string name, file;
  int stopit = 0;

  // find the boot effect that was set up with the command ob that is
  // running this check_target function
  // (should only be 1 boot effect possible at a time, but just in case...)
  foreach (boot in tp->query_effects("boot"))
    if (boot->misc == previous_object())
      break;

  // none of the boot effects are holding our object, this should never happen
  if (boot->misc != previous_object())
    return 0;

  caster = boot->caster;
  name = boot->castername;

  if (!caster)
    return 0;

  if (environment(caster) != env)
    return 0;

  // aiming ANY command at him specifically
  if (str && present(str, env) == caster)
    stopit = 1;

  // if trying to use any attack against him
  else if (!str && (object)tp->query_current_attacker() == caster) {
    file = CMD_D->find_cmd(query_verb(), tp->query_search_path());
    if (strlen(file)) {
      cmd = load_object(file);
      if (cmd && (cmd->abil() || cmd->spell()) && cmd->type() == "attack")
        stopit = 1;
    }
  }

  if (stopit) {
    message("info", "You are too stunned to do anything to "+
      caster->query_cap_name()+".", tp);
    return 1;
  }
  
  return 0;
}

