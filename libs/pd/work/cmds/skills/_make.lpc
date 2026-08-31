//  based on make by Nightshade
//  written by Nulvect 2006-08-06
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s)

inherit DAEMON;

string use_resources(object tp, string type);
mixed *check_resources(object tp, string type);
string a_or_an(string blah);

mapping reqs = ([
  "cloak" : ([
    "skins" : 3,
    "mud" : 1,
    "sinew" : 1
  ]),
  "hat" : ([
    "skins" : 2,
    "sinew" : 2,
    "mud" : 1
  ]),
  "jacket" : ([
    "skins" : 3,
    "sinew" : 2,
    "mud" : 1
  ]),
  "boots" : ([
    "skins" : 2,
    "sinew" : 2,
    "mud" : 2
  ]),
  "gloves" : ([
    "skins" : 2,
    "sinew" : 2,
    "mud" : 2
  ]),
  "chaps" : ([
    "skins" : 2,
    "sinew" : 1,
    "mud" : 2
  ]),
  "bag" : ([
    "sinew" : 2,
    "skins" : 2
  ]),
  "spear" : ([
    "wood" : 2,
    "sinew" : 1,
    "mud" : 2
  ]),
  "bow" : ([
    "wood" : 3,
    "sinew" : 2
  ]),
  "arrows" : ([
    "wood" : 1
  ]),
  "quiver" : ([
    "skins" : 3,
    "sinew" : 2,
    "mud" : 1
  ])
]);

mapping obids = ([
  "wood" : "forage_wood_ob",
  "mud" : "forage_mud_ob",
  "sinew" : "gut_sinew_ob",
  "skins" : "skin_skin_ob"
]);

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "ranger" &&
      tp->query_skill("nature") >= to_int(10*5.5))
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <make [spear | bow | quiver | arrows]>\n"
    "        <make [bag | gloves | boots | chaps ]>\n"
    "        <make [cloak | jacket | hat]>\n\n"
    "Rangers can make many things using natural materials.\n"
    "The ranger must have a quiver before making arrows.\n"
    "All armour is made to fit the ranger making it, except for "
    "boots, which can't be made for centaurs, weimics, or raknids.",
    this_player());
}

int can_cast(object tp, string type) {
  object env;
  string what;
  mixed *err;
  
  if (!tp) return 0;

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (member_array(type, keys(reqs)) == -1)
    FAIL("You cannot make that.\n");
  
  err=check_resources(tp, type);
  
  if (stringp(err[0]))
    FAIL("You do not have enough "+err[0]+" to make that.\n");

  return 1;
}

int cmd_make(string str) {
  object tp=this_player();
  object env=environment(tp);
  
  if (!abil()) return 0;

  if (!str || str == "")
    FAIL("Make what?\n");

  if (!can_cast(tp, str))
    return 0;

  tp->set_disable();
  tp->set_paralyzed(8,"You are busy making something.");
  tp->add_sp(-(25+random(10)));

  message("info", "You start to make "+
                  (str[<1..<1]=="s"?"some ":"a ")+str+".", tp);
  message("info", tp->query_cap_name()+" begins to make something.", env, tp);

  call_out("make_something", 6, ({tp, str}));

  return 1;
}

void make_something(mixed *args) {
  object tp=args[0];
  string type=args[1];
  object env;
  object ob;
  object *quiv;
  object *tmp;
  string err;
  string skintype;
  int nat;

  if (!tp) return;

  if (type == "arrows") {
    quiv = filter(all_inventory(tp), (: $1->is_quiver() :) );
    if (!sizeof(quiv)) {
      message("info","You can't find a quiver to store your arrows!", tp);
      tp->set_paralyzed(0);
      return;
    }
  }

  if (sizeof(tmp=filter(check_resources(tp, type), (: $1->id(obids["skins"]) :))))
    skintype = tmp[0]->query("skin_race");

  if (sizeof(err=use_resources(tp, type))) {
    message("info","You seem to be missing some "+err+".",tp);
    tp->set_paralyzed(0);
    return;
  }

  env = environment(tp);
  nat = tp->query_skill("nature");

  if (nat < random(to_int(20*5.5))) {
    message("info", "You mess up, ruining your materials.",tp);
    message("info", tp->query_cap_name()+" messes up and scraps "+
                    tp->query_possessive()+" "+type+".", env, tp);
  }
  else {
    message("info", "You craft "+(type[<1..<1]=="s"?"some ":"a ")+type+".", tp);
    message("info", tp->query_cap_name()+" finishes making something.",
      env, tp);
    if (type == "arrows") {
      quiv[0]->set_arrows(quiv[0]->query_arrows()+nat/32+1+random(3));
      message("info","You put your arrows into "+quiv[0]->query_name()+".",tp);
      return;
    }
    ob = call_other(this_object(), "do_"+type, nat, skintype, tp->query_race());
    ob->move(tp);
  }

  tp->set_paralyzed(0);
}

mixed *check_resources(object tp, string type) {
  mapping resources = ([
    "wood" : ({}),
    "skins" : ({}), 
    "mud" : ({}),
    "sinew" : ({})
  ]);
  object *ret = ({});
  object *ai = all_inventory(tp);

  foreach (string req in keys(reqs[type])) {
    resources[req] = filter(ai,
      function(object thing, string id) {
        if (thing->id(id)) return 1;
        else return 0;
      }, obids[req]);
    if (sizeof(resources[req]) < reqs[type][req])
      return ({req});
    for (int i=0; i < reqs[type][req]; i++)
      ret += ({resources[req][i]});
  }
  return ret;
}   
    
// the only way we could be missing resources is if
// somebody stole them...
string use_resources(object tp, string type) {
  mixed *delme = check_resources(tp, type);
  if (stringp(delme[0]))
    return delme[0];
  else
    delme->remove();
  return "";
}   

object do_spear(int nat, string skintype, string race) {
  object ob;
  ob = new(WEAPON);
ob->set_property("no store", 1);
  ob->set_name("spear");
  ob->set_id(({"spear", "wooden spear"}));
  ob->set_long("A sturdy wooden spear.");
  ob->set_short("a wooden spear");
  ob->set_weight(8+random(3));
  ob->set_type("projectile");
  ob->set_curr_value("gold", nat/10+random(10));
  ob->set_wc(nat/27+2);
  if (ob->query_wc() > 14)
    ob->set_wc(14);
  if (ob->query_wc() >= 8)
    ob->set_decay_rate(400+nat*2);
  return ob;
}

object do_bow(int nat, string skintype, string race) {
  object ob;
  ob = new(WEAPON);
ob->set_property("no store", 1);
  ob->set_name("bow");
  ob->set_id(({"bow", "wooden bow"}));
  ob->set_long("A sturdy wooden bow.");
  ob->set_short("a wooden bow");
  ob->set_weight(6+random(3));
  ob->set_type("ranged");
  ob->set_curr_value("gold", nat/8+random(10));
  ob->set_wc(nat/25+2);
  if (ob->query_wc() > 16)
    ob->set_wc(16);
  if (ob->query_wc() >= 8)
    ob->set_decay_rate(500+nat*2);
  return ob;
}

object do_quiver(int nat, string skintype, string race) {
  object ob;
  string a=a_or_an(skintype);
  ob = new(QUIVER);
ob->set_property("no store", 1);
  ob->set_name("quiver");
  ob->set_id(({"quiver", skintype+"skin quiver"}));
  ob->set_long("A quiver made of "+skintype+" skins.");
  ob->set_short(a+" "+skintype+"skin quiver");
  ob->set_weight(10+random(4));
  ob->set_curr_value("gold", nat/9+random(10));
  ob->set_ac(1+nat/120);
  ob->set_limbs(({"torso"}));
  ob->set_arrows(0);
  if (ob->query_ac() > 2)
    ob->set_ac(2);
  return ob;
}

object do_bag(int nat, string skintype, string race) {
  object ob;
  string a=a_or_an(skintype);
  ob = new(BAG);
ob->set_property("no store", 1);
  ob->set_name("bag");
  ob->set_id(({"bag",skintype+"skin bag"}));
  ob->set_long("A bag made of "+skintype+" skin.");
  ob->set_short(a+" "+skintype+"skin bag");
  ob->set_weight(12+random(3));
  ob->set_curr_value("gold", nat/11+random(20));
  ob->set_max_internal_encumbrance(400+nat);
  return ob;
}

object do_gloves(int nat, string skintype, string race) {
  object ob;
  string what;
  ob = new(ARMOUR);
ob->set_property("no store", 1);
  ob->set_name("gloves");
  ob->set_id(({"gloves",skintype+"skin gloves"}));
  ob->set_weight(4+random(3));
  ob->set_type("gloves");
  ob->set_curr_value("gold", nat/12+random(10));
  ob->set_ac(nat/110+1);
  if (ob->query_ac() > 3)
    ob->set_ac(3);
  switch (race) {
    case "raknid":
      ob->set_limbs(({"first hand","second hand","third hand","fourth hand"}));
      what="set";
    break;
    case "bastet":
      ob->set_limbs(({"left paw", "right paw"}));
      what="pair";
    break;
    default:
      ob->set_limbs(({"left hand","right hand"}));
      what="pair";
  }
  ob->set_long("A "+what+" of gloves made from "+skintype+" skins.");
  ob->set_short("a "+what+" of "+skintype+"skin gloves");
  ob->set_fingers(RACE_D->query_fingers(race));
  return ob;
}

object do_chaps(int nat, string skintype, string race) {
  object ob;
  string what;
  ob = new(ARMOUR);
ob->set_property("no store", 1);
  ob->set_name("chaps");
  ob->set_id(({"chaps",skintype+"skin chaps"}));
  ob->set_weight(7+random(3));
  ob->set_type("leggings");
  ob->set_curr_value("gold", nat/10+random(10));
  ob->set_ac(nat/70+1);
  if (ob->query_ac() > 4)
    ob->set_ac(4);
  switch (race) {
    case "centaur":
    case "weimic":
    case "raknid":
      ob->set_limbs(({"left foreleg", "right foreleg", "left rear leg", "right rear leg"}));
      what="set";
    break;
    default:
      ob->set_limbs(({"left leg", "right leg"}));
      what="pair";
  }
  ob->set_long("A "+what+" of chaps made from "+skintype+" skins.");
  ob->set_short("a "+what+" of "+skintype+"skin chaps");
  return ob;
}

object do_boots(int nat, string skintype, string race) {
  object ob;
  ob = new(ARMOUR);
ob->set_property("no store", 1);
  ob->set_name("boots");
  ob->set_id(({"boots", skintype+"skin boots"}));
  ob->set_weight(7+random(3));
  ob->set_type("boots");
  ob->set_curr_value("gold", nat/8+random(10));
  ob->set_ac(nat/55+1);
  if (ob->query_ac() > 6)
    ob->set_ac(6);
  switch (race) {
    case "bastet":
      ob->set_limbs(({"left rear paw", "right rear paw"}));
    break;
    default:
      ob->set_limbs(({"left foot", "right foot"}));
  }
  ob->set_long("A pair of boots made from "+skintype+" skins.");
  ob->set_short("a pair of "+skintype+"skin boots");
  return ob;
}

object do_hat(int nat, string skintype, string race) {
  object ob;
  string a=a_or_an(skintype);
  ob = new(ARMOUR);
ob->set_property("no store", 1);
  ob->set_name("hat");
  ob->set_id(({"hat",skintype+"skin hat"}));
  ob->set_long("A hat made from "+skintype+" skin.");
  ob->set_short(a+" "+skintype+"skin hat");
  ob->set_weight(2+random(3));
  ob->set_type("helmet");
  ob->set_curr_value("gold", nat/10+random(10));
  ob->set_ac(nat/65+1);
  if (member_array("horns",RACE_D->query_limbs(race)) != -1)
    ob->set_limbs(({"head", "horns"}));
  else
    ob->set_limbs(({"head"}));
  if (ob->query_ac() > 6)
    ob->set_ac(6);
  return ob;
}

object do_cloak(int nat, string skintype, string race) {
  object ob;
  string a=a_or_an(skintype);
  ob = new(ARMOUR);
ob->set_property("no store", 1);
  ob->set_name("cloak");
  ob->set_id(({"cloak",skintype+"skin cloak"}));
  ob->set_long("A cloak made from "+skintype+" skins.");
  ob->set_short(a+" "+skintype+"skin cloak");
  ob->set_weight(16+random(3));
  ob->set_type("cloak");
  ob->set_curr_value("gold", nat/6+random(10));
  ob->set_ac(nat/70+1);
  if (ob->query_ac() > 4)
    ob->set_ac(4);
  switch (race) {
    case "centaur":
      ob->set_limbs(({"torso","left arm","right arm","horse torso"}));
    break;
    case "weimic":
      ob->set_limbs(({"torso","left arm","right arm","feline torso"}));
    break;
    case "raknid":
      ob->set_limbs(({"torso","first arm","second arm","third arm","fourth arm","abdomen"}));
    break;
    default:
      ob->set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg"}));
  }
  return ob;
}

object do_jacket(int nat, string skintype, string race) {
  object ob;
  string a=a_or_an(skintype);
  ob = new(ARMOUR);
ob->set_property("no store", 1);
  ob->set_name("jacket");
  ob->set_id(({"jacket",skintype+"skin jacket"}));
  ob->set_long("A jacket made from "+skintype+" skins.");
  ob->set_short(a+" "+skintype+"skin jacket");
  ob->set_weight(12+random(3));
  ob->set_type("body armour");
  ob->set_curr_value("gold", nat/8+random(10));
  ob->set_ac(nat/35+1);
  if (ob->query_ac() > 9)
    ob->set_ac(9);
  switch (race) {
    case "raknid":
      ob->set_limbs(({"torso","first arm","second arm","third arm","fourth arm"}));
    break;
    default:
      ob->set_limbs(({"torso","left arm","right arm"}));
  }
  return ob;
}

string a_or_an(string blah) {
  string one=blah[0..0];
  string two=blah[1..1];
  string *vowels = ({"a","e","i","o","u"});
  if (member_array(one,vowels) != -1)
    return "an";
  else if (one == "y" && member_array(two,vowels) == -1)
    return "an";
  else
    return "a";
}
