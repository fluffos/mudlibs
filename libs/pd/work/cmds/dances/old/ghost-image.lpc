// ghost image for the dance of a thousand nights
// Kaknal 4-14-02
#include <std.h>
inherit MONSTER;
int noatt;
object owner;
void set_owner(object tp) {
  set_short("A ghostly image of "+tp->query_cap_name());
  set_long("This spirit looks very similar to "+tp->query_cap_name()+
    ", except it is partly transparent.");
  set_name("ghostly image");
  set_id(({"thousand-nights-ghost-image","ghostly image","ghost",
    "ghost image","image",tp->query_name()}));
  set_gender(tp->query_gender());
  set_level(tp->query_level()/3);
  set_body_type(tp->query_body_type());
  set_alignment(0);  
  set_hp(query_max_hp());
  set_sp(query_max_sp());
  set_mp(query_max_mp());
  owner=tp;
  set_exp_share(owner, to_float(1/2));
}
void create() {
  ::create();
  set_property("no_corpse",1);
  set_race("undead");
  set_die("The ghostly image slowly fades away.");
}
void heart_beat() {
  object att;
  int i;
  ::heart_beat();
  if (!owner)
    remove();
  if (!present(owner->query_cap_name(),environment())) {
    if (!present("thousand-nights-ghost-image",environment(owner))) {
      message("info","The ghostly presence follows you..",owner);
      message("info","A ghostly presence trails after "+
        owner->query_cap_name()+".", ({environment(),environment(owner)}),
        owner);
    }
    move(environment(owner));
  }
  if (query_current_attacker()) {
    noatt=0;
    return;
  }
  att=owner->query_current_attacker();
  if (att) {
    // safeguard -> there's no room with 50 mobs in it (I hope)
    for (i=1; i<50; i++) {
      if (present(att->query_id()[0]+" "+i, environment()) == att) {
        force_me("kill "+att->query_id()[0]+" "+i);
        break;
      }
    }
  }
  else noatt++;
  
  if (noatt > 12) {
    message("info","The ghostly image slowly fades away.",environment());
    owner->add_mp(5+random(6));
    remove();
  }
}
