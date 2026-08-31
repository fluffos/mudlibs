//    Zerker greater rage object.
//    By Hermes
// Based on original berserker object by Nightshade.  Credit where it's due I'm just modifying his stuff
 
#include <std.h>
inherit OBJECT;
object owner;
void special();
void fright();
 
void create() {
  ::create();
  set_name("crazie");
  set_heart_beat(1);
  set_short("");
  set_long("blah");
  set_weight(0);
  set_value(0);
  set_id(({"zerker_object"}));
}
void init() {
  ::init();
  add_action("blah","", 1);
}
int blah(string str) {
  string verb;
  if(wizardp(this_player()))
    return 0;
  verb = query_verb();
  if(verb == "quit")
    return 0;
  switch(verb) {
      case "age":
      case "look":
      case "cost":
      case "skills":
      case "score":
      case "body":
      case "time":
      case "hp":
      case "party":
      case "tell":
      case "reply":
      case "stand":
      case "status": return 0;
      default:
  }
  if((verb == "slash") && (owner->query_forced()))
    return 0;
  if((verb == "jab") && (owner->query_forced()))
    return 0;
  if((verb == "whirl") && (owner->query_forced()))
    return 0;
  if((verb == "rush") && (owner->query_forced()))
    return 0;
  if((verb == "headbutt") && (owner->query_forced()))
    return 0;
  write("You are too furious to bother with such trivialities!");
  return 1;
}
void heart_beat() {
  object *stuff;
  int i;
  if((!owner) && (environment(this_object())->is_living())) {
    owner = environment(this_object());
    message("info", "You fly into a fit of rage!",owner);
    message("info", owner->query_cap_name()+" flies into a fit of rage!",
environment(owner), owner);
    owner->add_skill_bonus("attack",owner->query_skill("rage")*(5/4));
    owner->add_skill_bonus("defense",-owner->query_skill("rage")/10);
  }
  if(!environment(this_object())->is_living())
    this_object()->remove();
  stuff = all_inventory(environment(owner));
  i = sizeof(stuff);
  while (i--)
    if((stuff[i]->query_attackers() != owner) && (!userp(stuff[i])) &&
(living(stuff[i]))
       && stuff[i] != owner->query_riding() && stuff[i] != owner)
      owner->kill_ob(stuff[i]);
    owner->clean_up_attackers();
  if(!sizeof(owner->query_attackers()) || !owner->query_current_attacker()) {
    if(file_name(environment(owner)) == "/d/standard/freezer")
      return;
    this_object()->finish();
    return;
  }
  if(owner->query_rest_type())
    owner->force_me("stand");
  while(i < owner->query_skill("ferocity")/8)
  i = random(100);
  if(i > 80)
    special();
  else if(i > 70)
    fright();
  else 
    if(!sizeof(owner->query_wielded()))
      owner->force_me("rush");
    else
      owner->force_me("slash");
  
    if(owner->query_sp() < 100)
    owner->set_sp(100);
  if(!userp(environment(this_object())))
    this_object()->remove();
}
void special() {
    object ob;
    if(owner->query_paralyzed()) {
        message("info", "In a feat of strength, you break free of your paralyzed
state!", owner);
        message("info", "In a feat of strength, "+owner->query_cap_name()+"
breaks free of "+possessive(owner)+" paralyzed state!", environment(owner),
owner);
        owner->set_paralyzed(0);
        return;
    }
    message("info", "You roar mightily and cleave your opponent!",owner);
    message("info", owner->query_cap_name()+" roars mightily and cleaves
"+possessive(owner)+" opponent!", environment(owner), owner);
    ob = owner->query_current_attacker();
    message("info", owner->query_cap_name()+" slams into you with their
weapon!", ob);
    ob->add_hp(-1 * (owner->query_skill("attack")/2 +
owner->query_stats("strength")));
}
void fright() {
    object ob;
    if(owner->query_paralyzed()) return;
    ob = owner->query_current_attacker();
    message("info", "Your eyes light up, instilling fear in your
opponent.",owner);
    message("info", owner->query_cap_name()+"'s eyes light up, instilling fear
in their opponent.", environment(owner), owner);
    message("info", owner->query_cap_name()+" scares you with their
savageness!", ob);
    ob->set_paralyzed(2 + random(5), owner->query_cap_name()+" has scared you
senseless!");
}
void finish() {
    if(!owner) owner = environment(this_object());
    message("info", "You finally calm down, breathless.",owner);
    message("info", (string)owner->query_cap_name()+" finally calms down,
breathing hard.", environment(owner), owner);
    owner->add_skill_bonus("attack",-owner->query_skill("rage")*(5/4));
    owner->add_skill_bonus("defense",owner->query_skill("rage")/10);
    owner->set_sp(owner->query_sp()/8);
    owner->add_skill_points("rage", random(50) + random(10));
    this_object()->remove();
    if(this_object()) destroy(this_object());
}
