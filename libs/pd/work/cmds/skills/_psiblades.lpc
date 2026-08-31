#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
#include <effect_cl.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s)

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define COL3 RES+"%^RED%^"

#define PSIBLADES_OB DIR_CLASS_CMDS+"/obj/psiblades_ob"
#define CMD_OB DIR_CLASS_CMDS+"/obj/command"

inherit DAEMON;

string *psiblades_cmds = ({ "slash", "stab", "block" });
string *allowed_spells = ({ "feed" });


int psi_cmd(string);
int do_notify(object, object);
void use_mp(class Effect);
void remove_psiblades(class Effect);


int spell() {
  object tp = this_player();
  if (tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 50*6 &&
      tp->query_skill("magic attack") >= 50*6 &&
      tp->query_skill("conjuring") >= 50*4)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <psiblades>\n"
    "        <psiblades ("+
      replace_string(list(psiblades_cmds, 0, ""), ", ", " | ")+
      ") [living]>\n"
    "        <stop psiblades>\n"
    "\n"
    "Sorcerors using this spell create blades of psionic energy that they "
    "can control. The blades can slash, stab, or block, but they "
    "require a great deal of concentration. It is impossible to use other "
    "spells while controlling psiblades.",
    this_player() );
}

int can_cast(object tp) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your powers fail to manifest.");

  if (tp->query_mp() < 250)
    FAIL("Too low on magic.");

  return 1;
}

int can_attack(object tp, object tgt) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (!tgt)
    FAIL("Attack who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Not the brightest idea.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_psiblades(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object cmd, bladesob;
  class Effect psi;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  psi = tp->query_effect("psiblades");

  // no psiblades exist, make them
  if (!psi) {
    cmd = new(CMD_OB);
    cmd->set_catchall(1);
    cmd->set_function(this_object(), "psi_cmd");
    cmd->set_notify("do_notify");

    bladesob = new(PSIBLADES_OB);
    bladesob->set_owner(tp);
    bladesob->move(env);

    psi = new(class Effect);
    psi->name = "psiblades";
    psi->castername = tp->query_name();
    psi->caster = tp;
    psi->target = tp;
    psi->desc = "You are controlling blades of psionic energy.";
    // setting an interval but no maxhits means this never ends
    // unless we make it... the func and commands will check user's mp
    // and end when it gets too low
    psi->interval = 2;
    psi->func = (: use_mp :);
    psi->endfunc = (: remove_psiblades :);
    psi->endmessages = ({
      COL+"Your psionic blades dissipate."+RES,
      COL+"The psionic blades around "+tp->query_cap_name()+" dissipate."+RES
    });
    psi->misc = ({ cmd, bladesob });

    tp->add_effect(psi);
    cmd->move(tp);

    tp->add_mp(-(250+random(50)-random(50)));
    tp->set_magic_round(1);

    message("magic",
      COL+"You mold your "+COL2+"ps"+COL+"ion"+COL2+"ic"+COL+" "+
      COL2+"energy"+COL+" into "+COL3+"dea"+COL+"dl"+COL3+"y "+
      "bl"+COL+"ad"+COL3+"es"+COL+"!"+RES,
      tp
    );
    message("magic",
      COL+tp->query_cap_name()+" molds "+
      COL2+"ps"+COL+"ion"+COL2+"ic"+COL+" "+
      COL2+"energy"+COL+" into "+COL3+"dea"+COL+"dl"+COL3+"y "+
      "bl"+COL+"ad"+COL3+"es"+COL+"!"+RES,
      env, tp
    );
  }

  // user has psiblades on, interpret arguments as commands to the blades
  else {
    if (!str)
      FAIL("Command the psiblades to do what?");

    if (str == "stop")
      return psi_cmd("stop");

    if (member_array(str, psiblades_cmds) == -1)
      FAIL("The psiblades can "+list(psiblades_cmds, 0, "or")+".");
  }

  return 1;
}

int psi_cmd(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  class Effect psi = tp->query_effect("psiblades");
  string file, psicmd, tgtname, tpmsg, tgtmsg, envmsg;
  int dmg, cost, dtype, time, psi_skill;
  string *stats;

  if (!psi)
    return -2;

  if (psi->endtime)
    return 0;

  if (str) {
    if (sscanf(str, "%s %s", psicmd, tgtname) != 2) {
      psicmd = str;
    }
  }

  switch (query_verb()) {
    case "stop":
      if (str && str == "psiblades") {
	psicmd = "stop";
      }
      else {
	break;
      }
    // conditional break only: "stop psiblades" == "psiblades stop"

    case "psiblades":

      if (tgtname)
	tgt = present(tgtname, env);
      else
	tgt = tp->query_current_attacker();
      
      switch (psicmd) {
	case "slash":
	case "stab":
          if (!tgt)
	    FAIL("Use the psiblades against whom?");
	  if (!can_attack(tp, tgt))
	    return 0;
	  if (tp->query_busy())
	    FAIL("You are busy.");

	  if (psicmd == "stab") {
	    dtype = DAMAGE_MAGIC | DAMAGE_PSYCHIC | DAMAGE_STAB;
	    stats = ({
	      "intelligence", "intelligence",
	      "intelligence", "intelligence", "wisdom"
	    });
	    tpmsg = COL+"You send the psiblades to attack "+
	      tgt->query_cap_name()+"!\n"+
	      COL2+"The psionic blades "+COL3+"stab"+COL2+" through "+
	      tgt->query_objective()+"!"+RES;
	    tgtmsg = COL+"The psiblades around "+tp->query_cap_name()+
	      " "+COL2+"shoot"+COL+" toward you, "+COL3+"stabbing"+COL+
	      " through your body!"+RES;
	    envmsg = COL+"The psiblades around "+tp->query_cap_name()+
	      " "+COL2+"shoot"+COL+" toward "+tgt->query_cap_name()+
	      ", "+COL3+"stabbing"+COL+
	      " through "+tgt->query_possessive()+" body!"+RES;
	  }
	  else {
	    dtype = DAMAGE_MAGIC | DAMAGE_PSYCHIC | DAMAGE_SLASH;
	    stats = ({ "intelligence", "wisdom" });
	    tpmsg = COL+"You send the psiblades to attack "+
	      tgt->query_cap_name()+"!\n"+
	      COL2+"The psionic blades "+COL3+"radiate"+COL2+" out, "
	      "then fly at "+tgt->query_cap_name()+", "+
	      COL3+"slashing"+COL2+" "+tgt->query_objective()+
	      " from all sides!"+RES;
	    tgtmsg = COL+"The psiblades around "+tp->query_cap_name()+
	      " "+COL2+"radiate"+COL+" outward, then fly at you, "
	      +COL3+"slashing"+COL+" from all sides!"+RES;
	    tgtmsg = COL+"The psiblades around "+tp->query_cap_name()+
	      " "+COL2+"radiate"+COL+" outward, then fly at "+
	      tgt->query_cap_name()+", "
	      +COL3+"slashing"+COL+" from all sides!"+RES;
	  }

	  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
	    ({ "psionics", "psionics", "magic attack", "conjuring" }),
	    stats,
	    ({ "psionics" })
	  );
	  dmg = dmg * 95 / 100;
	  cost = BALANCE3_D->get_cost(dmg, 4, "mp");

	  tp->add_mp(-cost);
	  tp->kill_ob(tgt);
	  tp->set_magic_round(1);
	  tgt->do_damage("target", dmg, dtype, DAMAGE_BYPASS_ARMOUR, tp);

	  message("magic", tpmsg, tp);
	  message("magic", tgtmsg, tgt);
	  message("magic", envmsg, env, ({ tp, tgt }) );

	  return 1;
	break;

	case "block":
	  time = 10; // seconds, not rounds
	  psi_skill = tp->query_skill("psionics");
	  tp->add_magic_protection( ({
	    0,
	    BALANCE3_D->diminishing_returns(tp->query_stats("wisdom"), 0.3),
	    time
	  }) );
	  tp->add_skill_bonus("defense", psi_skill*30/100, time);
	  tp->add_skill_bonus("psionics", -(psi_skill*15/100), time);
	  tp->set_magic_round(1);
	  tp->add_mp(-(psi_skill*6/100 + random(15)));

	  message("magic", COL+"You bring some of the psiblades "
	    "into a defensive position."+RES, tp);
	  message("magic", COL+"The psiblades around "+tp->query_cap_name()+
	    " move into a defensive position."+RES, env, tp);

	  return 1;
	break;

	case "stop":
	  message("magic", "You release your concentration.", tp);
	  psi->endtime = time()-2;
	  return 1;
	break;
      }
    break;

    default:
      if (wizardp(tp)) break;
      if (member_array(query_verb(), allowed_spells) != -1) break;
      file = CMD_D->find_cmd(query_verb(), tp->query_search_path());
      if (file && function_exists("spell", load_object(file)) != 0) {
	message("info", "You are too busy concentrating on your psiblades!", tp);
	return 1;
      }
    break;
  }

  return 0;
}

int do_notify(object killer, object victim) {
  if (victim->query_effect("psiblades")) {
    victim->remove_effect("psiblades");
  }
  return 0;
}

void use_mp(class Effect psi) {
  object tp = psi->caster;

  if (tp->query_mp() < 50+random(25)) {
    message("magic", "Your magic is too low to maintain the psiblades!", tp);
    psi->endtime = time()-2;
  }
  else if (tp->query_ghost()) {
    psi->endtime = time()-2;
  }
  else {
    tp->add_mp(-(15+random(15)));
  }
}

void remove_psiblades(class Effect psi) {
  object cmd = psi->misc[0];
  object bladesob = psi->misc[1];

  if (cmd)
    cmd->remove();

  if (bladesob)
    bladesob->remove();
}

