#include <std.h>
#include <daemons.h>
#include <damage_types.h>

#define COL "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"
#define BALANCE3_D "/daemon/balance3_d"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_class() == "wanderer" &&
      (tp->query_skill("blade") >= 30 || 
       tp->query_skill("knife") >= 30 ||
       tp->query_skill("blunt") >= 30) )
         return 1;
  return 0;
}

string type() { return "attack"; }

int ok_cast(object tp, object tgt, object *weps) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You cannot attack yourself.\n");

  if (!sizeof(weps))
    FAIL("You can only strike with a sword, knife, or blunt weapon.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_strike(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, skill;
  int cost, rank, i;
  string *skills;
  string *types = ({ });
  string *adverbs = ({"barely","lightly","solidly","forcefully"});

  if (!abil()) return 0;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  foreach (string type in ({"blade","knife","blunt"}))
    if (tp->query_skill(type) >= 30) types += ({type});
  
  weps = filter(tp->query_wielded(),
           function (object w, string *ty) {
             if (member_array(w->query_type(), ty) != -1) return 1;
           }, types );
  
  if (!ok_cast(tp,tgt,weps)) return 0;

  // this anonymous function sorts backwards so it puts the strongest weapon at weps[0]
  weps = sort_array(weps,
    function (object a, object b) {
      object t=this_player();
      int as = t->query_skill(a->query_type());
      int bs = t->query_skill(b->query_type());
      if (as > bs) return -1;
      else if (as < bs) return 1;
      else /*(as == bs)*/ return 0;
    } );

  skill=weps[0]->query_type();

  if (tp->query_skill(skill) >= 140) rank=3;
  else if (tp->query_skill(skill) >= 75) rank=2;
  else rank=1;

  if (rank > 1 && sizeof(weps) > 1)
    skills = ({ "attack", "double wielding" });
  else
    skills = ({ "attack" });

  // this looks complicated, but it's a max of 3 hits for raknids or
  // 2 hits for everyone else and each extra hit is a rank weaker and
  // has the damage halved from the previous hit
  i=0;
  foreach (object w in weps) {
    int dmg;

    skill=weps[i]->query_type();

    dmg=BALANCE3_D->get_damage(tp, tgt, rank,
          ({skill})+skills, ({ "strength", "dexterity" }),
          ({"strength","dexterity"}) );
    dmg = dmg*7/10;
    if (rank > 1) dmg = dmg+weps[i]->query_wc()*4;
    dmg = dmg/to_int(pow(2.0, to_float(i)));

    cost=BALANCE3_D->get_cost(dmg, rank, "sp") * 110 / 100;
  
    if (tp->query_sp() < cost)
      FAIL("You are too tired to continue.\n");

    tp->set_disable(1);
    tp->add_sp(-(cost+random(cost/10)));

    if (dmg < rank*5) {
      message("combat","You strike at "+tgt->query_cap_name()+
                       ", but miss.", tp);

      message("combat",tp->query_cap_name()+" strikes at "+tgt->query_cap_name()+
                       ", but misses.", environment(tp), ({ tp, tgt }) );
      
      message("combat",tp->query_cap_name()+" strikes at you, but misses.", tgt);
    }
    else {
      wep = w->query_name();
      message("combat","You "+COL+"strike"+RES+" "+tgt->query_cap_name()+" "+
                       adverbs[rank-i]+" with "+wep+"!", tp);
      
      message("combat",tp->query_cap_name()+" "+COL+"strikes"+RES+" you "+
                       adverbs[rank-i]+" with "+wep+"!", tgt);

      message("combat",tp->query_cap_name()+" "+COL+"strikes"+RES+" "+
                     tgt->query_cap_name()+" "+adverbs[rank-i]+" with "+wep+"!",
                     environment(tp), ({ tp, tgt }) );
    
      tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | (weps[0]->query_damage_type()), 0, tp);
    }
    if (++i >= rank) break;
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <strike [living]>\n\n"
    "A standard attack for wanderers. They can strike at their foes "
    "using swords, knives, or blunt weapons.",
    this_player());
}

