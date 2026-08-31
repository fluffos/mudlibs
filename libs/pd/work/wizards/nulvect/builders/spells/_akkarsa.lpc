#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan" &&
      tp->query_skill("summoning") >= 210)
    return 1;
  return 0;
}

int ok_cast(object tp) {
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  return 1;
}

int cmd_akkarsa(string str) {
  object tp=this_player();

  int wis, summ, faith;
  int cost, len;
  int bad=0;
  float amt;
  
  if (!spell()) return 0;

  if (tp->query_disable()) return 1;

  if (!ok_cast(tp)) return 0;
  
  wis=tp->query_stats("wisdom");
  summ=tp->query_skill("summoning");
  faith=tp->query_skill("faith");
  
  amt=0.5+to_float((summ-210)/600);
  if (amt > 0.7) amt=0.7;
  len=summ/22+faith/26+wis*3/2;
  len=len*3/5;
  cost=len*4+50;
  
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");

  tp->set_disable(1);
  tp->add_mp(-cost);

  message("magic",COL+"You chant the word %^BOLD%^%^RED%^akkarsa"+RES+COL+".",tp);
  message("magic",COL+tp->query_cap_name()+" chants something."+RES,environment(tp),tp);
  
  if (tp->query_alignment() > -800) {
    message("magic","A horrible feeling washes over you.",tp);
    bad=1;
  }

  call_out("summon",2,({tp,amt,len,bad}));
  
  return 1;
}

int kill_him(object blah,string party) {
  if (blah == this_player()) return 0;
  if (party && userp(blah) && blah->query_party() && blah->query_party() == party)
    return 0;
  if (blah->is_living()) {
    if (blah->query_stat_bonus("constitution") < 0) return 0;
    else return 1;
  }
  else return 0;
}

void summon(mixed *args) {
  object tp=args[0];
  float amt=args[1];
  int len=args[2];
  int bad=args[3];

  int size;
  string party;
  object *vic;

  if (!tp) return;
  
  if (!(party=tp->query_party())) party="";
  if ((size=sizeof(vic=filter(all_inventory(environment(tp)),"kill_him",this_object(),party)))==0) {
    message("magic","Nothing happens.",tp);
    return;
  }

  if (bad==1) {
    vic=({tp});
    size=1;
  }
  
  for (size--; size>=0; size--) {
    message("magic",COL+"Dark forms swoop in and dive into your body!\n"
                    "You feel your vitality draining away!"+RES,vic[size]);
    message("magic",COL+"Dark forms swoop in and dive into "+vic[size]->query_cap_name()+"!"+RES,
            environment(vic[size]),vic);
    vic[size]->add_skill_bonus("defense",-(to_int(vic[size]->query_skill("defense")*amt)),len);
    vic[size]->add_stat_bonus("constitution",-(to_int(vic[size]->query_stats("constitution")*amt)),len);
  }

  if (tp->query_alignment() <= -1000)
    tp->add_skill_points("summoning",len/3);

  call_out("remove",len,vic);

}

void remove(mixed *args) {
  object *vic=args;
  int size=sizeof(vic);

  for (size--; size>=0; size--) {
    if (vic[size]) {
      message("magic",COL+"Dark forms suddenly dart out from your body!\n"
                      "You feel your vitality returning."+RES,vic[size]);
      message("magic",COL+"Dark forms suddenly dart out of "+vic[size]->query_cap_name()+"'s body!"+RES,
                      environment(vic[size]),vic);
    }
  }
}

void help() {
  message("help",
    "Syntax: <akkarsa>\n"
    "This spell summons akkarsa demons to possess the caster's foes.\n"
    "Akkarsa feed on the vitality of their victims.",
    this_player());
}

