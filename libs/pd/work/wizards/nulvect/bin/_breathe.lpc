//      Written by Nightshade
//      a dungeonware.net Modification by Stormbringer
//      modified for elites
//      completely rewritten by Nulvect 2006-07-18
//
//      To add more dragon colors:
//      
//      add a case statement in the get_damage function,
//      
//      add a case statement in the get_message function,
//      here tpn and obn are set to the names of this_player
//      and the object he's attacking (except the initial
//      messages, where obn is "your enemy" or "your enemies"),
//      
//      if their breathe should do anything besides damage
//      then add a new function called do_extra_{color}, just
//      copy the prototypes for white/black/blue, this will
//      get called _before_ damage is done

#include <std.h>
#include <daemons.h>
#include <rest.h>
inherit DAEMON;

int get_damage(object tp, object ob);
string get_message(object tp, mixed ob, string mess);
string ok_to_attack_ob(object tp, object ob);

void do_extra_white(object tp, object ob, int dam, int stronghit);
void do_extra_black(object tp, object ob, int dam, int stronghit);
void do_extra_blue(object tp, object ob, int dam, int stronghit);

int abil() {
    object o = this_player();
    if (!o) return 0;
    if (o->query_class() == "dragon" &&
        o->query_skill("breath") >= 25 &&
        o->query_level() >= 10)
          return 1;
    return 0;
}

void help() {
  object tp=this_player();
  string color;
  
  message("help","Syntax: <breathe [living]>",tp);
  
  if (this_player()->query_race() == "dragon") {
    
    if ((color=get_message(tp, "help", "help")) != "")
      message("help", color, tp);
    
    message("help", "\nVery powerful dragons breathe so hard they can hit many "
                    "opponents with a single breath attack. They can aim it at "
                    "a specific opponent if they choose, though.", tp);
  }
  else
    message("help","The ability of dragons to use their natural breath weapon.",tp);
}

int cmd_breathe(string str) {
    object tp, env;
    object *tgts;
    int level, cost;
    string party, color;

    tp = this_player();
    env = environment(this_player());
    level=tp->query_level();
    color=tp->query_subclass();

    if(!abil())
      return 0;
    
    if(tp->query_ghost())
        return notify_fail("You can't do that as a ghost.\n");

    if (tp->query_disable())
        return notify_fail("You are too busy to do that.\n");
        
    if (env->query_property("no attack")) {
        message("info","Greater powers prevent your malice.",tp);
        return 1;
    }

    tp->clean_up_attackers();

    if (!str || str == "" || str == "all") {
      if (level < 50) {
        tgts=({tp->query_current_attacker()});
        if (!sizeof(tgts)) {
          return notify_fail("Breathe at whom?\n");
        }
      }
      else {
        str = "all";
      }
    }

    if (str != "all") {
      if (!sizeof(tgts))
        tgts=({present(str,env)});
      if (!sizeof(tgts))
        return notify_fail("You do not see that here.\n");
      if (!living(tgts[0]))
        return notify_fail("That is not alive.\n");
      if (tgts[0] == tp)
        return notify_fail("Not the brightest idea.\n");
    }
    else {
      party=tp->query_party();
      if (!party || party == "")
        tgts=filter(all_inventory(env)-({tp}),
              (: living($1) :) );
      else
        tgts=filter(all_inventory(env)-({tp}),
               function(object who, string p) {
                 if (living(who) && who->query_party() != p)
                   return 1;
               }, party);
      if (!sizeof(tgts))
        return notify_fail("There is nobody here to attack.\n");
    }
    
    cost = tp->query_skill("breath")/5;
    if (sizeof(tgts) > 1)
      cost += (cost*2/3)*(sizeof(tgts)-1);
    
    if (tp->query_sp() < cost) {
      message("info", "You do not have the energy to breathe right now.",tp);
      return 1;
    }
    
    if (sizeof(tgts) > 1) {
      message("info", get_message(tp, "your enemies", "my_initial"), tp);
      message("info", get_message(tp, tp->query_possessive()+" enemies",
            "their_initial"), env, tp);
    }
    else {
      message("info", get_message(tp, "your enemy", "my_initial"), tp);
      message("info", get_message(tp, tp->query_possessive()+" enemy",
            "their_initial"), env, tp);
    }

    foreach (object ob in tgts) {
      int dam=0;
      int stronghit=0;
      string err;

      if ((err=ok_to_attack_ob(tp, ob)) != "") {
        message("info",err,tp);
        continue;
      }

      dam=get_damage(tp, ob);
      
      if (dam < 1) {
        message("info","You breathe towards "+ob->query_cap_name()+
                       ", but miss "+ob->query_objective()+"!",tp);
        message("info",tp->query_cap_name()+" tries to use a breath attack, but fails!",
          env, tp);
        continue;
      }

      if (dam > ob->query_max_hp()/10)
        stronghit=1;

      if (stronghit) {
        message("info", get_message(tp, ob, "my_strong"), tp);
        message("info", get_message(tp, ob, "your_strong"), ob);
        message("info", get_message(tp, ob, "their_strong"), env, ({tp,ob}));
      }
      else {
        message("info", get_message(tp, ob, "my_hit"), tp);
        message("info", get_message(tp, ob, "your_hit"), ob);
        message("info", get_message(tp, ob, "their_hit"), env, ({tp,ob}));
      }
      
      if (function_exists("do_extra_"+color,this_object()) != 0)
        call_other(this_object(), "do_extra_"+color, tp, ob, dam, stronghit);
      
      if (sizeof(tgts) == 1)
        dam = dam*4/3;

      ob->do_damage(ob->return_target_limb(), dam);
      
      if (ob->query_hp() < 1) ob->heart_beat();
      
    }

    tp->set_disable();

    tp->add_sp(-(cost+random(cost/10)-random(cost/10)));
    tp->add_skill_points("breath", 20+sizeof(tgts));

    return 1;
}

string ok_to_attack_ob(object tp, object ob) {

  if (ob->is_player() && !interactive(ob))
    return "You cannot attack link-dead players.";
  
  if (!(tp->kill_ob(ob)))
    return ob->query_cap_name()+" can't be attacked by you yet.";

  return "";
}

int get_damage(object tp, object ob) {
  int level;
  int dam;
  if (!tp || !ob) return 0;
  level=tp->query_level();

  if (level >= 50) {
    dam = BALANCE_D->get_damage( tp, ob, 4,
            ({ "breath", "breath", "breath", "attack" }),
            ({ "strength", "intelligence" }),
            ({ "wisdom" }) );
  }
  else if (level >= 25) {
    dam = BALANCE_D->get_damage( tp, ob, 3,
            ({ "breath", "breath", "breath", "attack" }),
            ({ "strength", "intelligence" }),
            ({ "wisdom" }) );
  }
  else {
    dam = BALANCE_D->get_damage( tp, ob, 2,
            ({ "breath", "breath", "breath", "attack" }),
            ({ "strength" }) );
  }
  dam = dam*7/6 + random(dam/3);

  switch (tp->query_subclass()) {
    case "red":
      dam = dam*8/10;
      break;
      
    case "white":
      dam = dam*7/10;
      break;

    case "black":
      dam = dam*6/10;
      break;
      
    case "blue":
      dam = dam*6/10;
      break;
      
    default:
      dam = 0;
  }
  return dam;
}

string get_message(object tp, mixed ob, string mess) {
  string tpn, obn;
  if (!tp || !ob) return;
  tpn=tp->query_cap_name();
  if (objectp(ob))
    obn=ob->query_cap_name();
  else if (stringp(ob))
    obn=ob;
  switch (tp->query_subclass()) {
    case "red":
      switch (mess) {

        case "help":
          return "This attack sends a shot of flame at your opponent, "
                 "singing him or possibly engulfing him in flames, "
                 "and causing a lot of damage.";

        case "my_initial":
          return "You breathe %^BOLD%^%^RED%^FIRE%^RESET%^ towards "+obn+"!";
        case "their_initial":
          return tpn+" breathes %^BOLD%^%^RED%^FIRE%^RESET%^ towards "+obn+"!";

        case "my_hit":
          return "You %^ORANGE%^singe%^RESET%^ "+obn+" badly.";
        case "your_hit":
          return tpn+" %^ORANGE%^singes%^RESET%^ you badly.";
        case "their_hit":
          return tpn+" %^ORANGE%^singes%^RESET%^ "+obn+" badly.";

        case "my_strong":
          return "You %^BOLD%^%^RED%^E%^YELLOW%^N%^RED%^G"
                 "%^YELLOW%^U%^RED%^L%^YELLOW%^F%^RESET%^ "+obn+
                 " in %^ORANGE%^flames%^RESET%^!";
        case "your_strong":
          return tpn+" %^BOLD%^%^RED%^E%^YELLOW%^N%^RED%^G"
                 "%^YELLOW%^U%^RED%^L%^YELLOW%^F%^RED%^S%^RESET%^ "
                 "you in %^ORANGE%^flames%^RESET%^!";
        case "their_strong":
          return tpn+" %^BOLD%^%^RED%^E%^YELLOW%^N%^RED%^G"
                 "%^YELLOW%^U%^RED%^L%^YELLOW%^F%^RED%^S%^RESET%^ "+
                 obn+" in %^ORANGE%^flames%^RESET%^!";

        default: return "";
      }

    case "white":
      switch (mess) {
        case "help":
          return "This attack sends a cloud of poisonous gas at your opponent. "
                 "The poison can cause long-term damage, and even cause him "
                 "to fall to the ground and be sick.";
        
        case "my_initial":
          return "You breathe %^BOLD%^%^GREEN%^POISON%^RESET%^ towards "+obn+"!";
        case "their_initial":
          return tpn+" breathes %^BOLD%^%^GREEN%^POISON%^RESET%^ towards "+obn+"!";
        
        case "my_hit":
          return "You make "+obn+" very %^GREEN%^ill%^RESET%^.";
        case "your_hit":
          return tpn+" makes you very %^GREEN%^ill%^RESET%^.";
        case "their_hit":
          return tpn+" makes "+obn+" very %^GREEN%^ill%^RESET%^.";

        case "my_strong":
        case "their_strong":
          return obn+" becomes so badly %^RED%^poisoned%^RESET%^, "+
                 ob->query_subjective()+" falls over %^GREEN%^p%^CYAN%^u"
                 "%^GREEN%^k%^CYAN%^i%^GREEN%^n%^CYAN%^g%^RESET%^!";
        case "your_strong":
          return tpn+" %^RED%^poisons%^RESET%^ you so badly that you fall over "
                 "%^GREEN%^p%^CYAN%^u%^GREEN%^k%^CYAN%^i%^GREEN%^n%^CYAN%^g%^RESET%^!";
        
        default: return "";
      }

    case "black":
      switch (mess) {
        case "help":
          return "This attack sends a bolt of lightning at your opponent. "
                 "The shock may send him into convulsions.";
        
        case "my_initial":
          return "You breathe %^BOLD%^LIGHTNING%^RESET%^ towards "+obn+"!";
        case "their_initial":
          return tpn+" breathes %^BOLD%^LIGHTNING%^RESET%^ towards "+obn+"!";
        
        case "my_hit":
          return "You %^BOLD%^ZAP%^RESET%^ "+obn+" badly.";
        case "your_hit":
          return tpn+" %^BOLD%^ZAPS%^RESET%^ you badly.";
        case "their_hit":
          return tpn+" %^BOLD%^ZAPS%^RESET%^ "+obn+" badly.";
        
        case "my_strong":
          return "You send "+obn+" into %^BOLD%^%^RED%^violent %^CYAN%^convulsions%^RESET%^!";
        case "your_strong":
          return tpn+" sends you into %^BOLD%^%^RED%^violent %^CYAN%^convulsions%^RESET%^!";
        case "their_strong":
          return tpn+" sends "+obn+" into %^BOLD%^%^RED%^violent %^CYAN%^convulsions%^RESET%^!";

        default: return "";
      }

    case "blue":
      switch (mess) {
        case "help":
          return "This attack sends a blast of ice at your opponent. "
                 "As well as damage, the cold saps away his energy.";
                 
        case "my_initial":
          return "You breathe %^BOLD%^%^CYAN%^ICE%^RESET%^ towards "+obn+"!";
        case "their_initial":
          return tpn+" breathes %^BOLD%^%^CYAN%^ICE%^RESET%^ towards "+obn+"!";
        
        case "my_hit":
          return "You give "+obn+" a terrible %^CYAN%^chill%^RESET%^.";
        case "your_hit":
          return tpn+" gives you a terrible %^CYAN%^chill%^RESET%^.";
        case "their_hit":
          return tpn+" gives "+obn+" a terrible %^CYAN%^chill%^RESET%^.";
        
        case "my_strong":
        case "their_strong":
          return obn+" %^BOLD%^%^RED%^SCREAMS%^RESET%^ as "+
                 ob->query_possessive()+" skin %^BOLD%^%^BLUE%^freezes%^RESET%^!";
        case "your_strong":
          return "You %^BOLD%^%^RED%^SCREAM%^RESET%^ as your skin %^BOLD%^%^BLUE%^freezes%^RESET%^!";

        default: return "";
      }
    default: return "";
  }
  return "";
}

void do_extra_white(object tp, object ob, int dam, int stronghit) {
  if (!tp || !ob) return;
  if (tp->query("poisoner"))
    if (!find_object(tp->query("poisoner")) ||
        find_object(tp->query("poisoner")) == ob)
          ob->add_poisoning(dam/10);
  tp->set("poisoner", file_name(ob));
  if (stronghit)
    ob->set_rest_type(SIT);
}

void do_extra_black(object tp, object ob, int dam, int stronghit) {
  if (!tp || !ob) return;
  if (random(100) < 50)
    ob->set_paralyzed(2,
        "You are unable to control your muscles because of the electricity!");
}

void do_extra_blue(object tp, object ob, int dam, int stronghit) {
  if (!tp || !ob) return;
  ob->add_sp(-(dam/4));
}
