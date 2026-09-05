/* An example for the use of set_hit_func in a weapon */

#pragma strong_types

#include <message.h>
#include <alignment.h>

inherit "basic/message";
inherit "obj/weapon";

int ali_range(int value) {
  /* Give the alignment-group of a vlue: -1, 0, 1 for less that neutral,
     neutral and above neutral */
  if (value < AL_NEUTRAL)
    return -1;
  else if (AL_NICE <= value)
    return 1;
  else
    return 0;
}

int loyal_attack(object attacker) {
  /* This function influences the wc of the sword: The return-value is added
     to the original wc */
  int tp_align, at_align, wc_mod, ali_diff;

  tp_align = ali_range(this_player()->query_alignment());
  at_align = ali_range(attacker->query_alignment());

  /* Three cases: the weapon works normal, if this_player() or attacker is
   * neutral, better if attacker and this_player are of different alignments
   * (attacker > neutral && this_player < neutral, or vice versa), and worse
   * if attacker and this_player are of the same alignment (both less or
   * greater than neutral). The modification of the weapon class is calculated
   * from the alignments. The return value is added to the wc */
  if (tp_align == 0 || at_align == 0) {
    /* One of the fighters is of quite neutral alignment */
    message(({ ({ M_WRITE, "Your sword seems quite uninterested." }) }));
    return 0;
  }
  else if (tp_align == at_align) {
    /* Alignments are equal - decrease the wc */
    message(({ ({ M_WRITE, "The sword feels very heavy and hard to handle. "
                  "It seems as if it doesn't like to attack ", attacker, "."}),
               ({ M_SAY, M_NAME, " seems to have some problems handling ",
                  M_PL_POSSESSIVE, " weapon." }) }));
    ali_diff = abs(this_player()->query_alignment() -
                   attacker->query_alignment());
    wc_mod = (ali_diff > 1000 ? -1 : -(1000 - ali_diff)/100 );
    return wc_mod;
  }
  else {
    /* Alignments different - raise the wc */
    message(({ ({ M_WRITE, "It feels as if the sword wants to attack ",
                  attacker, "." }),
               ({ M_PLAYER_S, " sword glows in a magical light." }) }));
    ali_diff = abs(this_player()->query_alignment() -
                   attacker->query_alignment());
    wc_mod = (ali_diff > 1000 ? 10 : ali_diff / 100 );
    return wc_mod;
  }
}

void configure() {
  set_id("loyal sword");
  set_alias("sword");
  set_short("loyal sword");
  set_long(
    "The sword is well balanced and feels very comfortable in your hand.\n"
    "You notice a pair of eyes at the blade that look very friendly at you.\n"
  );
  set_weight(2);
  set_value(2000);
  set_class(14);
  set_items(({
    "eyes",
    "The eyes look friendly at you, but they seem to see right through you\n"
    "into your soul. You have a feeling that the sword has a will of its own.\n",
    "blade",
    "The blade is made of the finest steel and has a magical aura.\n",
  }));
  set_hit_func(this_object(), "loyal_attack");
}

void reset(int arg) {
  if (!arg)
    configure();
}

