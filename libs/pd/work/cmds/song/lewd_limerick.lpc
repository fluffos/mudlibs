#include <std.h>

inherit SONG;

string *male = ({
  "There once was a guy named Tim,",
  "Who loved to go for a swim;",
  "He drank from a weird spring -",
  "His crotch started to sting -",
  "Now his friends all know him as Kim!"
});
string *female = ({
  "There once was a girl named Estelle, ",
  "Whose beauty from afar you could tell, ",
  "But she messed with a witch -",
  "Some curses were pitched -",
  "Now her knickers don't fit very well!"
});

void create() {
  ::create();
  set_verses(male);
  set_auto(0);
  set_type("other");
  set_target_required(1);
  set_song_name("lewd limerick");
}

int song() {
  object tp = this_player();
  if (tp->query_subclass() == "jester" && tp->query_skill("euphony") >= 3*40)
    return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing lewd limerick to [whom]>\n\n"
    "A bawdy jester song that can cause some very entertaining changes in his audience.",
    this_player() );
}

int check() {
  object tgt = query_target();
  object tp = this_player();
  if (tp->query_mp() < tp->query_max_mp())
    return notify_fail("Your magical energies are too low.\n");
  if (tgt && tgt->query_gender() != "male") set_verses(female);
  return 1;
}

void finish() {
  object tp = query_caster();
  object tgt = query_target();
  object env;

  if (!tp) return;
  env = environment(tp);

  if (!tgt || environment(tgt) != env || tgt->query_race() == "nymph") {
    message("song", "Nothing happens.", tp);
    return;
  }

  if (tgt->query_gender() == "male") tgt->set_gender("female");
  else tgt->set_gender("male");

  message("song", tgt->query_cap_name()+" seems changed.", env, tgt);
  message("song", "You feel your body changing strangely.", tgt);

  // to help prevent abuse, can only use with full mp
  tp->set_mp(0);

}
