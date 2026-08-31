// assassin demon for the summon spell
// based on original by Inferno
// -Nulvect
#include <std.h>
#include <dirs.h>

inherit DIR_CLASS_CMDS+"/obj/summon/kataan_demon";

int do_assassinate(string);

void create() {
  ::create();
  set_name("assassin");
  set_id( query_id() | ({ "assassin", "assassin demon" }) );
  set_gender("male");
  set_short("an assassin demon");
  set_level(22);
  set_long("The assassin demon looks like a human with oil "
   "black skin and blazing white eyes. Two horns jut "
   "out of its head, leading down its spine.");
  set_body_type("human");
  set_alignment(-1000);
  set_race("demon");
  set_class("rogue");
  set_subclass("assassin");
  set_spell_chance(40);
  set_spells( ({ "stab" }) );
  set_skill("murder", 100);
  set_skill("knife", 80);
  set_stats("dexterity", 50);
  set_stats("strength", 40);
  new(DIR_CLASS_CMDS+"/obj/summon/assassin_knife")->move(this_object());
  command("wield knife");
  add_action("do_assassinate", "assassinate");
  set_reveal("<assassinate [player]>");
}

int do_assassinate(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment();
  object tgt, tgtenv;

  if (tp != to) return 0;
  if (!str) return 0;

  str = lower_case(str);
  if (!(tgt = find_player(str))) return 0;

  if (!to->ok_to_kill(tgt)) return 0;

  if (tgt == query_owner()) return 0;

  if (to->query_following()) to->query_following()->remove_follower(to);
  tgtenv = environment(tgt);
  if (tgtenv != env) to->move(tgtenv);

  command("kill "+str);
  to->kill_ob(tgt);

  return 1;
}
