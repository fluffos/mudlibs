#include <std.h>
#include <effect_cl.h>
inherit SONG;

void create() {
  ::create();
  set_verses(({
    "Rain patters on soft, calm ground",
    "Flower, plant, leaf of tree",
    "Growing here on hallowed mound;",
    "Nature, set my spirit free"
   }));
  set_type("beneficial");
  set_target_required(1);
  set_song_name("ode to nature");
}

int song() {
  object o=this_player();
  if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 40)
    return 1;
  return 0;
}

void help() {
  message("help",
   "Syntax: <sing ode to nature [to whom]>\n\n"
   "This song calls upon natural forces to protect whomever "
   "the singer chooses.",
   this_player() );
}

void finish() {
  object ob, tp;
  int time;
  class Effect eff;

  tp = query_caster();
  ob = query_target();
  if (!ob || !present(ob, environment(tp)) || 
   ob->query_magic_protection() >= tp->query_level()/5) {
    message("info", "Nothing happens.", tp);
    return;
  }

  time = tp->query_skill("euphony")*3/2;
  message("song", "Your skin hardens.", ob);
  message("song", ob->query_cap_name()+"'s skin hardens.",
   environment(ob), ob);

  eff = new(class Effect);
  eff->name = "ode to nature";
  eff->endtime = time()+time;
  eff->caster = tp;
  eff->target = ob;
  eff->castername = tp->query_name();
  eff->desc = "Your skin has become magically hard.";
  eff->endmessages = ({ "Your skin returns to normal.", ob->query_cap_name()+"'s skin returns to normal." });
  ob->add_effect(eff);
  ob->add_magic_protection(({0, 3+(tp->query_level()/10), time}));
}
