
#include <std.h>
#include <locations.h>
#include <h2k7.h>

inherit MONSTER;

int count = 0;
object where;

void create() {
  ::create();
  set_property("no corpse", 1);
  set_property("no bump", 1);
  set_undead(1);
  set_name("shade");
  set_id( ({ "shade", "dark shade", "halloween shade" }) );
  set_short("a dark shade");
  set_long("This dark spirit is barely visible. It blends into the "
      "shadows with ease. It has no definite shape, but two yellow "
      "eyes stare out from the darkness.");
  set_race("ghost");
  set_body_type("human");
  set_level(45);
  set_alignment(-1000);
  set_class("mage");
  set_subclass("necromancer");
  set_spells( ({ "umbra me", "buffer me" }) );
  set_spell_chance(30);
  set_chats(20, ({
    "The dark shade cackles.",
    "The dark shade whispers: He is mine now...",
    "The dark shade whispers: His pain tastes so delicious...",
  }) );
  set_stats("strength", 10);
  set_stats("dexterity", 10);
  set_stats("constitution", 200);
  set_stats("wisdom", 200);
  set_skill("attack", 20);
  set_skill("melee", 20);
  set_skill("defense", 400);
  set_skill("magic defense", 400);
  set_max_hp(9000);
  set_hp(9000);
}

void heart_beat() {
  object env = environment(this_object());
  object ob;
  ::heart_beat();
  if (!this_object()) return;

  if (query_current_attacker() && !count) count = 1;

  switch (count) {
  case 0: break;

  case 1: 
    command("grin");
    command("say So foolish...");
  break;

  case 2:
    command("say I guess I'll have to put my meal away for later.");
  break;

  case 3:
    message("magic", "The dark shade makes a motion and the spirit "
	"vanishes suddenly.", env );
    if (ob = present("spirit of alan hosseldorf", env)) ob->remove();
  break;

  case 4:
    command("cackle");
    message("info", "%^BOLD%^%^BLACK%^The dark shade fades away.%^RESET%^", env);
    where = env;
    this_object()->move(TEMP_LOC);
    this_object()->cease_all_attacks();
  break;

  default:
  case 5:
    if (where) {
      message("info", "%^ORANGE%^A voice calls from the darkness: "+
	"Please help me, I'm trapped in a...%^RESET%^\n"
	"The voice is abruptly silenced.", where);
    }
    ob = new(H2K7ITEMS+"pumpkinspirit");
    load_object(H2K7D)->place_random(ob);
    load_object(H2K7D)->do_reminder();
    this_object()->remove();
  break;

  }
  if (count) count++;
}

void add_hp(int x) { return; }
void do_damage(string l, int x) { return; }
void damage(int x) { return; }

