
#include <std.h>
#include <damage_types.h>
#include <damage.h>

#define BAIL(s) return notify_fail(s);

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp &&
      tp->query_subclass() == "pyromancer" &&
      tp->query_skill("pyromancy") >= 6*8)
    return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  object tp=this_player();
  message("help",
    "Syntax: <cauterize [living]>\n\n"
    "A healing spell of sorts. It uses fire to seal your wounds, "
    "which helps you stay alive at the cost of damage to your body.",tp);
}

string *rearrange_array(string *limbs);

int cmd_cauterize(string str) {

  object tp=this_player();
  object ob;
  int py, intel;
  int currdam, newdam;
  int cost;
  float amt;
  string *limbs;
  
  if (!spell()) return 0;
  if (tp->query_busy())
    BAIL("You are busy.\n");

  if (environment(tp)->query_property("no magic"))
    BAIL("You cannot cast that here.\n");
  
  if (str == "me") str=tp->query_name();
  if (!str || !(ob=present(str,environment(tp))))
    BAIL("You don't see that here.\n");

  if (!living(ob))
    BAIL("That is not alive.\n");

  py= tp->query_skill("pyromancy");
  intel= tp->query_stats("intelligence");

  cost = py/2 + intel/2;
  if (tp->query_mp() < cost)
    BAIL("You are too low on magic.\n");

  // can't cauterize little wounds, only big ones
  if (ob->query_hp() > ob->query_max_hp()*22/30)
    BAIL((ob==tp?"You have":ob->query_subjective()+" has")+" no large wounds to cauterize.\n");
  
  // if you just use query_limbs() it always comes out the same so it
  // always burns the same limb til it gets too damaged
  limbs = rearrange_array(ob->query_limbs());
  
  amt = to_float(py/6)*((30.0+random(11))/40.0)/100.0;
  if (amt > 0.7) amt=0.7+(random(11)/100);

  foreach (string limb in limbs) {
    currdam = ob->query_body_mapping()[limb]["damage"];
    newdam = ob->query_body_mapping()[limb]["max_dam"]*amt;
    
    if (currdam+newdam < ob->query_body_mapping()[limb]["max_dam"]*8/10) {
      tp->add_mp(-(cost+random(20)));

      //ob->heal_limb(limb, -newdam );
      ob->do_damage(limb, newdam, DAMAGE_MAGIC | DAMAGE_FIRE,
         DAMAGE_NO_HP | DAMAGE_NONLETHAL | DAMAGE_NO_SEVER | DAMAGE_BYPASS_ARMOUR, tp);
      ob->add_hp(py+intel*4/3);
      ob->add_bleeding(-(py/2 + intel/2));

      if (tp == ob) {
        message("magic","%^YELLOW%^You burn your wounds closed.%^RESET%^",tp);
        message("magic","%^YELLOW%^"+tp->query_cap_name()+" burns "+
          tp->query_possessive()+" wounds closed.%^RESET%^",environment(tp),tp);
      }
      else {
        message("magic","%^YELLOW%^You burn "+ob->query_cap_name()+"'s wounds closed.%^RESET%^",tp);
        message("magic","%^YELLOW%^"+tp->query_cap_name()+" burns your wounds closed.%^RESET%^",ob);
        message("magic","%^YELLOW%^"+tp->query_cap_name()+" burns "+ob->query_cap_name()+
          "'s wounds closed.%^RESET%^", environment(tp), ({tp,ob}));
      }
      tp->set_magic_round();
      return 1;
    }
  }
  
  // if it gets here all the limbs are already hurt very badly
  BAIL((ob==tp?"Your":ob->query_subjective())+" limbs are charred far too badly already!\n");

}

string *rearrange_array(string *limbs) {
  string *newarr = ({});
  string moveit;
  int i;
  if (!(i=sizeof(limbs))) return ({ });
  while (i--) {
    moveit = limbs[random(i-1)];
    limbs -= ({moveit});
    newarr += ({moveit});
  }
  return newarr;
}

