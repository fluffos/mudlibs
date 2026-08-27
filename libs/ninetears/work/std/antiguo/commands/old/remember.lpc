#include "language.h"
/*
 * For remembering spells....
 */
#define WIZARD_SPELL "/std/spells/wizard/controller"
#define SPELL_ESCAPE "/std/spells/wizard/escaped"
#define SKILL "magic.spells.special"

int power;
object spell_b,
       spell_page;
mixed *spell_o;

/* Can only memorise spells that are on the open page. */
int check_book(object ob, string spell) {
  object page;
  int i;
  mixed *writing;

/* Only handling one spell per page.  Hmmm..... */
  if ((writing = (mixed *)ob->query_read_mess())) {
/*
 * Spells are done in a magic language.  Definately need size of page...
 * so you can only fit so much on a page.
 */
    for (i=0;i<sizeof(writing);i++) {
      if (LANGUAGE_HAND->query_language_magic(writing[i][READ_LANG])) {
        if (writing[i][READ_STR][1] == spell) {
          spell_b = ob;
          spell_o = ({ writing[i][READ_STR][0], "cast_spell" });
          if ((page = (object)ob->query_current_page()))
            spell_page = page;
          else
            spell_page = ob;
          return !!spell_o;
        }
      }
    }
    return 1;
  }
  return 0;
} /* check_book() */

int wizard_spell(object *ob) {
  if (ob[0]->query_wizard_spell()) {
    power += (int)ob[0]->query_power_level();
    return 1;
  }
  return 0;
} /* wizard_spell() */

int remember(string str) {
  int pow;
  string spell, book;
  object *obs, *oobs;
  mapping spells;
  int chance;

  if (!str) {
    notify_fail("remember <spell> from <book>\n");
    return 0;
  }
  if (sscanf(str, "%s from %s", spell, book) != 2) {
    notify_fail("remember <spell> from <book>\n");
    return 0;
  }
  oobs = obs = find_match(book, ({ this_player(), environment(this_player()) }));
  if (!sizeof(obs)) {
    notify_fail("Cannot find "+book+" to get any spells off.\n");
    return 0;
  }
  obs = filter_array(obs, "check_book", this_object(), spell);
  if (!sizeof(obs)) {
    notify_fail(query_multiple_short(oobs)+(sizeof(oobs) == 1?
                " is not a magic book or does ":" are not magic books or do ")+
                "not have the spell "+spell+" in it.\n");
    return 0;
  }
  spells = (mapping)this_player()->query_spells();
  if (spells[spell]) {
    notify_fail("You have already remembered the rituals for "+spell+".\n");
    return 0;
  }
  power = 0;
  spells = filter_mapping(spells, "wizard_spell", this_object());
  if (power + (int)spell_o[0]->query_power_level() >
      (int)this_player()->query_skill_bonus(SKILL)+30) {
    notify_fail("This spell is too powerful for you to remember currently.\n");
    return 0;
  }
/*
 * Ok... so they can remember it... Now time to remember is proportional
 * To its power...
 *
 * The spell has a chance (dependant on level) of escaping.
 * The book can also be good or bad at leting spells escape.  A sort
 * of binding force.
 *
 * Escaped spells will be fun. Heheheh :)
 */
  chance = (((int)spell_o[0]->query_power_level())*
            ((int)spell_o[0]->query_power_level()))/
           (((int)spell_b->query_binding_force())*
           (((int)this_player()->query_skill_bonus(SKILL))/10)+1);
  if (random(500) < chance) {
/*
 * Spell escape!  But don't do it right away...  Let em remember it for
 * a while first :)
 */
    this_player()->add_spell_effect(100, "spell", "remembering",
                                    this_object(), "heart_beat_rem");
    this_player()->set_interupt_command("remember_interupt", this_object(),
                                ({ spell, 1, spell_o, spell_b }));
    this_player()->adjust_time_left(-chance/10);
    return 1;
  }
  this_player()->add_spell_effect(100, "spell", "remembering", 
                                  this_object(), "heart_beat_rem");
  this_player()->set_interupt_command("remember_interupt", this_object(),
                              ({ spell, 0, spell_o }));
  this_player()->adjust_time_left(-chance/10);
  return 1;
} /* remember() */

void remember_interupt(int left, mixed args) {
  this_player()->remove_spell_effect("remembering", "spell");
  if (!left)
    if (args[1]) {
      write("You successfuly remember "+args[0]+".\n");
      this_player()->add_spell(args[0], args[2][0], args[2][1]);
      return ;
    } else {
/* Lose the spell....  */
      spell_page->remove_writing(args[0]);
      args[2][0]->create_lost_spell()->move(environment(this_player()));
      write("Oh no!  The spell slips through your mind and zips off into "
            "space.  I hope you had another copy.\n");
      say(this_player()->query_cap_name()+" finishes the cermony, when "
          "suddenly "+this_player()->query_pronoun()+" is rocked from "
          "side to side, steam comes out of "+this_player()->query_possesive()+
          "ears and a small ball of energy darts out from behind "+
          this_player()->query_possesive()+" ears.\n");
      return ;
    }
/* Ok... so we were interupted remembering our spell.  Do we lose it anyway? */
/* Ahhh forget it :) */
  return ;
} /* remember_interupt() */
