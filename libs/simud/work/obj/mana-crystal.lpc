#include <magic.h>
#include <object.h>
#include <desc.h>
#include <item.h>
#include <saveload.h>

void init() {
  ::init();
  add_action("on_touch","touch");
  set_heart_beat(1);
}

// grin, fancy paint in stead of boring ;)
void on_paint( object painter ) {
   painter->paint( query_x(), query_y(), '*', 9+random(7), 5 );
}

TASTE( "Mmm! Energy!" )

void create() {
  ::create();
  set_distant("a large shimmering crystal");
  set_specific("the crystal");
  set_name("crystal");
  set_alt_name( ({"mana crystal", "mana battery", "shimmering crystal"}) );
  set_look("This crystal flickers with an ethereal light. You can feel the "+
           "energy radiate from it. Perhaps if you touch it, you might feel "+
           "a bit more, eh?");
  set_gettable(0);
  set_heart_beat(1);
}

void heart_beat() {
  object who;
  int livings;

  // test is so that the blueprint doesn't complain
  if (environment(this_object())) foreach ( who : all_inventory(environment(this_object())) ) {
    if (!who->query_is_living())
      continue;
    livings++;
    who->add_mana(1);
    if (time() % 30 == 0) {
      who->add_endurance(5);
      if (random(15) == 0)
        msg_object(who,"~CBRTYou feel a wave of heat issue from the crystal.~CDEF");
    }
  }
  if (!livings)
    set_heart_beat(0);
}

/* This used to be the automatic method for giving base magic skills to
 * people, but now they just have the 'skillme' command for that. This
 * function should really be deprecated out of existence if anyone ever
 * revives these objects.
 */
void learn_skills() {
  if (query_verb() == "lick") {
    mapping skills = this_player()->query_skills();
    mapping spells = this_player()->query_known_spells();
    int learned;
    // requisite skills
    if (!member(skills,"magic.concentration")) {
      this_player()->set_skill("magic.concentration",1);
      learned = 1;
    }
    if (!member(skills,"magic.mana.spirit")) {
      this_player()->set_skill("magic.mana.spirit",1);
      learned = 1;
    }
    if (!member(skills,"magic.mana.earth")) {
      this_player()->set_skill("magic.mana.earth",1);
      learned = 1;
    }
    // requisite spells
    if (!member(spells,"heal")) {
      this_player()->add_known_spell("heal",1);
      learned = 1;
    }
    if (!member(spells,"channel")) {
      this_player()->add_known_spell("channel",1);
      learned = 1;
    }
    if (!member(spells,"mana bolt")) {
      this_player()->add_known_spell("mana bolt",1);
      learned = 1;
    }
    if (!member(spells,"haste")) {
      this_player()->add_known_spell("haste",1);
      learned = 1;
    }

    if (learned) {
      msg("~CEMOYou feel new knowledge pour into your mind...\n"+
          "As your mana is drained back into the crystal.~CDEF");
      this_player()->set_mana(0);
    }
  }
}

int on_touch(string arg) {
  int hp, end, mana;

  if (arg != "crystal")
    return 0;

  set_actor(this_player());
  if (query_verb() == "touch")
    this_player()->msg_local("~CACT~Name ~verbtouch the mana crystal.~CDEF");

  mana = this_player()->query_max_mana() - this_player()->query_mana();
  if (!mana) {
    msg("~CBRTYou feel a tingling sensation.~CDEF");
    learn_skills();
    return 1;
  }

  // message
  end = this_player()->query_endurance();
  if (end > 5)
    msg("~CBRTRaw magical energy pours from the crystal into your body.~CDEF");
  else {
    msg("~CWRNYou don't have enough energy to use the crystal right now!~CDEF");
    this_player()->msg_local("~CACT~Name ~verbis knocked to the ground!~CDEF");
    this_player()->set_stance(ST_LYING);
    return 1;
  }

  // take endurance, heal the bugger's mana -- lots of energy cost for licking
  end -= mana / (query_verb() == "touch"?5:2);
  if (end > 0) {
    this_player()->set_endurance(end);
  } else {
    msg("~CWRNYou are completely exhausted.~CDEF");
    this_player()->set_endurance(0);
  }

  this_player()->add_mana(mana);
  return 1;
}

// grin, now -this- is fun ;)
int on_lick() {
   return on_touch("crystal");
}
