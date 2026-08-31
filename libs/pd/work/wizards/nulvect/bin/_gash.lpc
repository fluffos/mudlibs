
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define BLADECOL "%^BOLD%^%^WHITE%^"
#define KNIFECOL RES+"%^RED%^"
#define DWCOL "%^BOLD%^%^BLUE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "warrior" &&
      tp->query_skill("blade") >= 11*6 &&
      tp->query_skill("knife") >= 11*6 &&
      tp->query_skill("double wielding") >= 11*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <gash [whom]>\n\n"
    "With this move, a warrior can slash at a target with a sword, "
    "then quickly slice the same area with a knife, opening a sizable "
    "gash.",
    this_player() );
}

int can_cast(object tp, object tgt, object *blades, object *knives) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are dead.");

  if (!sizeof(blades) || !sizeof(knives))
    FAIL("You must use a sword and a knife.");

  if (tp->query_rest_type())
    FAIL("You can't do that while sitting!");

  if (!tgt)
    FAIL("Gash whom?");

  if (!living(tgt))
    FAIL("That would dull your weapons.");

  if (tgt == tp)
    FAIL("There are better ways to kill yourself.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_gash(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *blades = ({}), *knives = ({});
  int bdmg, kdmg, bcost, kcost, rank;
  string limb, kname;

  if (!abil()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  foreach (object wep in tp->query_wielded()) {
    switch (wep->query_type()) {
      case "blade": blades += ({wep}); break;
      case "knife": knives += ({wep}); break;
      default:
    }
  }

  if (!can_cast(tp, tgt, blades, knives)) return 0;

  rank = 1+tp->query_skill("double wielding")/(6*15);
  if (rank > 4) rank=4;
  
  bdmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"attack", "blade", "discipline"}),
    ({"strength", "dexterity"}),
    ({"strength", "dexterity"}) );

  bdmg *= 0.6;
  bdmg += random(bdmg/5);

  bcost = bdmg/11;
  
  if (tp->query_sp() < bcost)
    FAIL("You are too tired.");

  tp->add_sp(-(bcost+random(bcost/15)));
  tp->set_disable();
  limb = tgt->return_target_limb();

  message("combat", "You "+BLADECOL+"sl"+DWCOL+"a"+BLADECOL+"sh"+RES+
                    " "+tgt->query_cap_name()+
                    " down "+DWCOL+"ac"+BLADECOL+"ro"+DWCOL+"ss"+RES+
                    " the "+limb+"!", tp);
  message("combat", tp->query_cap_name()+" "+
                    BLADECOL+"sl"+DWCOL+"ash"+BLADECOL+"es"+RES+
                    " you down "+DWCOL+"ac"+BLADECOL+"ro"+DWCOL+"ss"+RES+
                    " the "+limb+"!", tgt);
  message("combat", tp->query_cap_name()+" "+
                    BLADECOL+"sl"+DWCOL+"ash"+BLADECOL+"es"+RES+
                    " "+tgt->query_cap_name()+
                    " down "+DWCOL+"ac"+BLADECOL+"ro"+DWCOL+"ss"+RES+
                    " the "+limb+"!", env, ({tp, tgt}) );

  tgt->do_damage(limb, bdmg);
  
  kdmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"double wielding", "knife"}),
    ({"dexterity", "dexterity", "strength"}),
    ({"dexterity"}) );
  
  kdmg *= 0.4;
  if (kdmg >= 200)
    kdmg += knives[0]->query_wc()*6;
  kdmg += random(kdmg/7);

  kcost = kdmg/12;
  
  if (tp->query_sp() < kcost)
    FAIL("You are too tired to get in another hit.");

  tp->add_sp(-(kcost-random(kcost/10)));
  kname=knives[0]->query_name();
  
  message("combat", "You "+KNIFECOL+"slice"+RES+" your "+kname+
                    " "+DWCOL+"over"+RES+" the wound, opening a large "+
                    KNIFECOL+"ga"+DWCOL+"sh"+RES+"!", tp);
  message("combat", tp->query_cap_name()+" "+KNIFECOL+"slices"+RES+
                    " "+tp->query_possessive()+" "+kname+
                    " "+DWCOL+"over"+RES+" the wound, opening a large "+
                    KNIFECOL+"ga"+DWCOL+"sh"+RES+"!", env, tp);
  
  tgt->do_damage(limb, kdmg);
  
  return 1;
}

