
#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL RES+"%^CYAN%^"
#define COL2 RES+"%^ORANGE%^"

inherit SONG;

void ball_damage(object tp, object tgt, int num);

void create() {
  ::create();
  set_verses(({
    "The laughing man is seldom a threat,",
    "But those who chuckle soon forget,",
    "The disarray he can beget!",
  }));
  set_type("attack");
  set_auto(1);
  set_target_required(1);
  set_song_name("jokers jingle");
}

int song() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("euphony") >= 30*3 &&
      tp->query_skill("entertainment") >= 30*6)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing jokers jingle [to whom]>\n\n"
    "A jester song that drops juggling balls on your opponent's head.",
    this_player());
}

void performance(int round) {
  if (round == 2)
    ball_damage(query_caster(), query_target(), 1);
}

void finish() {
  ball_damage(query_caster(), query_target(), 2);
}

void ball_damage(object tp, object tgt, int num) {
  int dmg, rank;
  string limb;
  object env;

  if (!tp || !tgt || environment(tp) != environment(tgt))
    return;

  env = environment(tgt);
  limb = "head";
  if (!tgt->query_is_limb(limb))
    limb = tgt->return_target_limb();

  rank=3;
  
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"euphony", "entertainment"}),
    ({"charisma"}),
    ({"charisma", "intelligence"}) );

  dmg = dmg/3;

  for (int i = 0; i < num; i++) {
    object ob = new(DIR_CLASS_CMDS+"/obj/pocket/ball");
    if (!ob) {
      message("info", "An error occurred, please contact a staff member.", tp);
      return;
    }
    message("song", COL+"A juggling ball "+
        COL2+"falls "+COL+"from "+COL2+"the "+COL+"sky and "
        "hits you in the "+limb+"!"+RES, tgt);
    message("song", COL+"A juggling ball "+
        COL2+"falls "+COL+"from "+COL2+"the "+COL+"sky and "
        "hits "+tgt->query_cap_name()+" in the "+limb+"!",
        env, tgt);

    tgt->do_damage(limb, dmg, DAMAGE_SONG | DAMAGE_IMPACT, DAMAGE_NO_SEVER, tp);

    ob->move(env);
    DELAY_D->add_delay(10, ob, "remove_if_untouched", ({}), 0);
  }

}

