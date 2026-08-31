
#include <std.h>

#define IMAGE_ID "nights_ghost_ob"

inherit PET;

int false(string a, string b) { return 0; }

void setup(object tp, int l) {
  set_short("A ghostly image of "+tp->query_cap_name());
  set_long("This spirit looks very similar to "+tp->query_cap_name()+
    ", except it is partly transparent.");
  set_name("ghost");
  set_id(({IMAGE_ID,"ghostly image","ghost","ghost image","image",tp->query_name()}));
  set_gender(tp->query_gender());
  set_level(l);
  set_body_type(tp->query_body_type());
  set_alignment(0);  
  set_hp(query_max_hp());
  set_sp(query_max_sp());
  set_mp(query_max_mp());
  set_owner(tp);
  add_assist(tp);
}

void create() {
  ::create();
  set_property("no_corpse",1);
  set_property("no monster", 1);
  set_undead(1);
  set_race("ghost");
  set_die("The ghostly image slowly fades away.");
  set_exp_percent(75);
  set_command_check( (: false :) );
}


