//    Zerker rage object.
//    By Nightshade.
 
#include <std.h>

inherit OBJECT;

object owner;
int sp;
int elite;
string *types;
mapping abilities;
int attbonus;
int defbonus;
int ferocity;

void setup(object tp, int el, string *ty, mapping all, int attb, int defb, int stam, int fero);
int rage_hook(string str);
int cmd_special(string str);
int cmd_fright(string str);
void finish();

void create() {
  ::create();
  set_heart_beat(1);
  set_short("");
  set_long("");
  set_weight(0);
  set_value(0);
  set_id(({"rage_ob_id"}));
  
  owner = 0;
  elite = 0;
  types = ({});
  abilities = ([]);
  attbonus = 0;
  defbonus = 0;
  sp = 0;
}

void setup(object tp, int el, string *ty, mapping all, int attb, int defb, int stam, int fero) {
  if (!tp || !sizeof(ty) || !sizeof(all)) {
    remove();
    return;
  }

  owner = tp;
  elite = el;
  types = ty;
  abilities = all;
  attbonus = attb;
  defbonus = defb;
  sp = stam;
  ferocity = fero;
  
  set_heart_beat(1);
}

void init() {
  ::init();
  add_action("rage_hook","", 1);
  add_action("cmd_fright", "rage_fright");
  add_action("cmd_special", "rage_special");
}

int rage_hook(string str) {
  string verb;

  if (wizardp(this_player()))
    return 0;

  verb = query_verb();

  switch(verb) {
    case "quit":
    case "age":
    case "look":
    case "cost":
    case "skills":
    case "stats":
    case "score":
    case "body":
    case "armour":
    case "time":
    case "hp":
    case "party":
    case "tell":
    case "reply":
    case "stand":
    case "status":
      return 0;
    default:
  }
  
  if (this_player()->query_forced())
    return 0;

  message("info", "You are too furious to bother with such trivialities!",
      this_player());

  return 1;
}

void heart_beat() {
  object *stuff;
  string which;
  string *low = ({});
  string *high = ({});
  string *all = ({});
  string *wtypes;

  if (!environment() || !owner || environment() != owner ||
      !(environment()->is_living()) || !environment(owner) ||
      environment(owner)->query_property("no attack")) {
        remove();
        return;
  }

  owner->add_skill_bonus("attack", attbonus, 4);
  owner->add_skill_bonus("defense", defbonus, 4);

  stuff = filter(all_inventory(environment(owner)),
    function (object who, object owner) {
      string party = owner->query_party();
      if (!(who->is_living()))
        return 0;
      if (who == owner)
        return 0;
      if (who == owner->query_riding())
        return 0;
      if (sizeof(party) && who->query_party() == party)
        return 0;
      if (sizeof(party) && who->query_rider() && who->query_rider()->query_party() == party)
        return 0;
      return 1;
    }, owner);

  foreach (object who in stuff)
    if (member_array(owner,who->query_attackers()) == -1)
      owner->kill_ob(who);

  owner->clean_up_attackers();

  if (!sizeof(owner->query_attackers()) || !(owner->query_current_attacker()) ||
      file_name(environment(owner)) == "/d/nopk/standard/freezer") {
        finish();
        return;
  }

  if (owner->query_rest_type())
    owner->force_me("stand");

  if (sizeof(owner->query_wielded()))
    wtypes = owner->query_wielded()->query_type();
  else
    wtypes = ({"melee"});

  wtypes = filter(wtypes, (: member_array($1, types) != -1 :) );

  foreach (string type in wtypes) {
    low += abilities[type]["low"];
    high += abilities[type]["high"];
  }

  all = low + high + ({"rage_fright","rage_special"});

  if (sizeof(high))
    for (int i=ferocity/50; i > 0; i--)
      all += ({high[random(sizeof(high))]});

  which = all[random(sizeof(all))];

  owner->force_me(which+" "+stuff[0]->query_id()[0]);

  if (owner->query_sp() < sp)
    owner->set_sp(sp);
}

int cmd_special(string str) {
  object ob;
  string what;

  if (!str || str == "") ob = owner->query_current_attacker();
  else ob=present(str,environment(owner));

  if(owner->query_paralyzed()) {
    message("info", "%^RESET%^%^BOLD%^In a feat of strength, you break free of "
                    "your paralyzed state!%^RESET%^", owner);
    message("info", "%^RESET%^%^BOLD%^In a feat of strength, "+
                    owner->query_cap_name()+" breaks free of "+owner->query_possessive()+
                    " paralyzed state!", environment(owner), owner);
    owner->set_paralyzed(0);
    return 1;
  }

  if (!ob) return 0;

  if (owner->query_subclass() == "red")
    what = "claws";
  else if (!sizeof(owner->query_wielded()))
    what = "fists";
  else
    what = "weapon";
  
  message("info", "You roar %^CYAN%^mightily%^RESET%^ and "
                  "%^MAGENTA%^cleave%^RESET%^ your opponent!%^RESET%^",owner);
  message("info", owner->query_cap_name()+" roars %^CYAN%^mightily%^RESET%^ "
                  "and %^MAGENTA%^cleaves%^RESET%^ "+owner->query_possessive()+
                  " opponent!%^RESET%^", environment(owner), owner);
  message("info", owner->query_cap_name()+" slams into you with "+
                  owner->query_possessive()+" "+what+"!", ob);

  if (elite)
    ob->do_direct_damage(ob->return_target_limb(),
        (owner->query_skill("attack")/2 + owner->query_stats("strength")));
  else
    ob->do_direct_damage(ob->return_target_limb(),
        (owner->query_skill("attack")/3 + owner->query_stats("strength")));

  return 1;
}

int cmd_fright(string str) {
  object ob;
    
  if (!str || str == "") ob = owner->query_current_attacker();
  else ob = present(str, environment(owner));

  if (!ob) return 0;
  
  if (owner->query_paralyzed()) return 0;

  message("info", "Your eyes %^BOLD%^light up%^RESET%^, instilling "
                  "%^ORANGE%^fear%^RESET%^ in your opponent.%^RESET%^", owner);
  message("info", owner->query_cap_name()+"'s eyes %^BOLD%^light up%^RESET%^, "
                  "instilling %^ORANGE%^fear%^RESET%^ in "+
                  owner->query_possessive()+ " opponent.%^RESET%^",
                  environment(owner), owner);
  message("info", owner->query_cap_name()+" scares you with "+
                  owner->query_possessive()+" savageness!", ob);

  ob->set_paralyzed(2 + random(4), owner->query_cap_name()+" has scared you senseless!");

  return 1;
}

void finish() {
  if (owner) {
    message("info", "You finally calm down, breathless.",owner);
    message("info", owner->query_cap_name()+" finally calms down, "
                    "breathing hard.", environment(owner), owner);
    if (!elite)
      owner->set_sp(0);
    if (owner->query_subclass() == "berserker")
      owner->add_skill_points("rage", 10 + random(10));
  }
  remove();
  if (this_object()) this_object()->destroy(this_object());
}


