#include <magic.h>

string query_action_name() { return "Meditate"; }

mapping subject_map;

void create() {
	subject_map = ([
		// faith
		"blessing": "magic.faith.blessing",
		"devotion": "magic.faith.devotion",
		"healing": "magic.faith.healing",
		"judgement": "magic.faith.judgement",
		"repentance": "magic.faith.repentance",
		"sacrifice": "magic.faith.sacrifice",
		// mana
		"chaos": "magic.mana.chaos",
		"dark": "magic.mana.dark",
		"earth": "magic.mana.earth",
		"lightning": "magic.mana.lightning",
		"fire": "magic.mana.fire",
		"ice": "magic.mana.ice",
		"order": "magic.mana.order",
		"spirit": "magic.mana.spirit",
		"water": "magic.mana.water",
		"wind": "magic.mana.wind",
		// techniques
		"abjuring": "magic.technique.abjuring",
		"binding": "magic.technique.binding",
		"charming": "magic.technique.charming",
		"conjuring": "magic.technique.conjuring",
		"cursing": "magic.technique.cursing",
		"divination": "magic.technique.divination",
		"enchanting": "magic.technique.enchanting",
		"evoking": "magic.technique.evoking",
		"necromancy": "magic.technique.necromancy",
		"warding": "magic.technique.warding",
		// knowledge
		"arcana": "knowledge.arcana",
		"alchemy": "knowledge.alchemy",
		"herbology": "knowledge.herbology",
		"astronomy": "knowledge.science.astronomy",
		"mathematics": "knowledge.science.mathematics",
	]);
}

int main(string str) {
  if ( str && str[0..2] == "on " ) {
    // check if they specified a valid skill
	str = str[3..];
	if( !member(subject_map, str) )
       return notify_fail("You cannot meditate on that subject.\n");
    if( !this_player()->query_skill(subject_map[str]) )
       return notify_fail("Sorry, but you do not know that subject well enough to meditate on it.\n");
  }

  // TODO: Eventually allow people to specify a topic for meditation

  this_player()->push_action( ({
                                1000,
                                this_object(),
                                this_player(),
                                ST_SITTING,
                                ({ subject_map[str], 0 })
                              }) );
  return 1;
}

void on_interrupt(mixed action) {
   mixed param = action[3];
   object player = action[2];
   if( player->query_mana() >= player->query_max_mana() ) {
      msg_object(player,"You would be stunned, but don't need to meditate anymore.");
   } else {
      AUDIO_DAEMON->sfx(action[B_TARGET], "gong.wav");
      AUDIO_DAEMON->start_the_music(player);
      msg_object(player,"You are stunned momentarily by the interruption.");
      player->add_held(3);
   }
}

string random_skill() {
  int x = random(100);
  string skill;
  if (x < 50)
    skill = "magic.concentration";
  else {
    string *skills = filter(m_values(subject_map), (: this_player()->query_skill($1) :) );
    skill = skills[random(sizeof(skills))];
  }
  return skill;
}

void on_action(object target, mixed param) {
  int heal = min(1 + random(2) + this_player()->query_skill("magic.concentration") / 8, 10);
  // special cases for just starting out
  if( !param[1] ) {
    int mana = this_player()->query_mana();
	int max_mana = this_player()->query_max_mana();
    if ( mana >= max_mana ) {
      msg("You do not need to meditate at this time.\n");
      return;
    }
    if (present("invigorate_object",this_player()) || present("haste_object",this_player())) {
      msg("You are too excited to meditate.\n");
  	  return;
    }
    if( param[0] )
      msg("~[030You will concentrate on ~CDEF"+param[0]+"~[030 as you meditate.~CDEF");
    else
      msg("~[030You will allow your thoughts to flow as you meditate.~CDEF");
  }
  // ok, try to med now
  if (this_player()->query_mana() < this_player()->query_max_mana()) {
    if (present("invigorate_object",this_player()) || present("haste_object",this_player())) {
      AUDIO_DAEMON->sfx(this_player(), "gong.wav");
	  AUDIO_DAEMON->start_the_music(this_player());
      msg("~CWRNYou have become too excited to meditate.~CDEF");
    } else {
	  string buf = "~[030~Name ~verb"+(param[1]?"continue":"begin")+
			       " to meditate.~CDEF";
	  AUDIO_DAEMON->sfx(this_player(), "triangle.wav");
	  AUDIO_DAEMON->bgm(this_player(), "bgm/prototype-b.mp3");
      this_player()->msg_local(buf);
      this_player()->set_action( -1, ({ 1000 - this_player()->query_skill("magic.meditation"),
                                        this_object(),
                                        this_player(),
                                        ST_SITTING,
                                        ({ param[0], 1 }) }) );
	  this_player()->add_readiness(2*this_player()->query_skill("magic.meditation")-1000);
	  this_player()->add_mana(heal);
	  if (random(100) < 30 - heal) {
        int end_cost = -2 * heal / max(1,this_player()->skill_check("magic.meditation",heal,heal*2,heal*3,heal*4,heal*5,heal*6));
	    msg("~[030The meditation tires you.~CDEF");
		this_player()->add_endurance(end_cost);
	  } else {
        // practice magic skills
		int cutoff = this_player()->query_skill("magic.meditation");
		string skill = param[0] ? param[0] : random_skill();
	    this_player()->practice_skill_conditional(skill,cutoff,1);
	  }
	  if (this_player()->query_autohp())
        "/bin/hp"->force(this_player());
	  // always give meditation pracs
	  this_player()->practice_skill("magic.meditation");
      return;
	}
  }
  set_actor(this_player());
  AUDIO_DAEMON->sfx(this_player(),"sparkle.wav");
  AUDIO_DAEMON->start_the_music(this_player());
  this_player()->msg_local("~[030~Name ~verbfinish ~poss meditation.~CDEF");
  this_player()->change_stance(ST_STANDING);
}

int query_is_interruptable() { return 1; }
