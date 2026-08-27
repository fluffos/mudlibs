/*
 * This is the object used for a spell that has got away.
 * It was 12 feet long!  Honest!
 */
inherit "/obj/monster";

int power_level;
string spell_type;

void create() {
  power_level = 10;
  spell_type = "attack";
  ::create();
  load_chat(100, ({
1, "@zip",
1, ":splashes colour around the room",
1, ":spakles slightly",
1, ":writhes in concentration"
    }));
  load_a_chat(100, ({
1, ":buzzes angrily"
    }));
  msgout = "@$N flashes out $D";
  msgin = "@$N flashes in from $D";
} /* create() */

/* How much damage it does it dependant on its power level. */
void set_power(int pow) {
/* Its a zap!  Remove the attack */
  remove_attack("zap");
  power_level = pow;
/* Zzzzzap! */
  add_attack("zap", 0, 100, pow*20, 0, 0, "magic");
} /* set_power() */

int query_power() { return power_level; }

void set_spell_type(string str) { spell_type = str; }
string query_spell_type() { return spell_type; }
