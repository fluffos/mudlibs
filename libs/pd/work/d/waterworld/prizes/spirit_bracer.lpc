//// Armour for Waterworld level 1 -- Tirun bay
////

#include <std.h>
#include <waterworld.h>

inherit ARMOUR;

int wear_ok;
int extra_worn();
int extra_remove();

////////////////////////////////////////////////////////////////////////
//

int controller = 5 ;

// Adjust this value if you wish to lengthen or shorten the healing rate
//
////////////////////////////////////////////////////////////////////////

void create() {
  ::create();
  set_name("spirit bracers");
  set_id(({"spirit bracers","bracer","bracers"}));
  set_short("The %^BLACK%^%^BOLD%^Spirit%^WHITE%^%^BOLD%^ bracers");
  set_long("The %^BLACK%^%^BOLD%^Spirit%^WHITE%^%^BOLD%^ bracers%^RESET%^ of Atlantis. Energy pulses from them like a rhythmic %^RED%^heartbeat%^RESET%^.");
  set_type("bracers");
  set_ac(2);
  set_weight(8);
  set_limbs(({"right arm","left arm"}));

  set_heart_beat(1);
  set_wear( (: extra_worn :) );
  set_remove( (: extra_remove :) );

}

/// mpecial effects

int extra_worn() {
  object tp=this_player();
  string cap_tp=tp->query_cap_name();

  if(tp->query_property("spirit_bracer") < 1) {
    message("info","The bracers burst into a shower of sparks.",tp);
    message("info","The bracers burst into a shower of sparks as "+cap_tp+" tries to wear them.",environment(tp),tp);
    this_object()->remove();
    return 0;
  }
  if( (tp->query("spiritbracers"))==0) {
    message("info","Your %^BLACK%^%^BOLD%^spirit%^RESET%^ hums as the power of the bracers fill you with %^ORANGE%^%^BOLD%^energy%^RESET%^!!",tp);
    message("info",(tp->query_cap_name())+" hums as the power of the bracers fills "+tp->query_objective()+" with %^ORANGE%^%^BOLD%^energy%^RESET%^!!",environment(tp),tp);
    tp->set("spiritbracers",1);
    return 1;
  }
  else
  {
    message("info","Wearing two sets of these bracers would nullify the effect.",tp);
    return 0;
  }

}
int extra_remove() {

  object tp;

  tp=this_player();

  tp->set("spiritbracers",0);
  message("info","The hum surrounding you fades away.", tp);
  message("info","The hum surrounding "+tp->query_cap_name()+" fades away.", environment(tp), tp);
  return 1;
}

void heart_beat() {
  object tp;
  int tp_mmp;
  int m_rate;
  int counter;

  if(this_object()->query_worn()) {
    tp=this_object()->query_worn();
    tp_mmp=tp->query_max_mp();
    m_rate=((tp_mmp)/100);

    if(counter > controller ) tp->add_mp(m_rate);
    else counter = counter + 1;
  }
}
