#include <magic.h>
#include <battle.h>

mapping message_map;	// for individual messages from each cantrip

string query_name() { return "cantrip"; }
int query_level() { return 0; }
int query_cost() { return 3; }
string query_type() { return "spirit"; }
int query_readiness_requirement() { return 1000; }
int query_num_steps() { return 4; }

void create() {
	message_map = ([
		// CHAOS
		"chaos": ({
				"A convoluted shape appears in front of ~name.",
				"An iridescent butterfly appears in front of ~name, flaps its wings once, and fades away.",
				"You hear many voices whispering but can't make out what they are saying.",
				"A puddle of light collects at ~npos feet and rubs up against ~poss ankles, purring.",
			}),
		// DARK
		"dark": ({
				"An opaque black cloud appears in front of ~name.",
				"~Name ~verbis momentarily overwhelmed as the stench of decay wraps itself around ~obje.",
				"A shadowy aparition flies around ~name, moaning, then sinks downward and dissapears.",
				"You hear moaning and screaming.",
			}),
		// EARTH
		"earth": ({
				"A solid cloud of dust appears in front of ~name.",
				"~Name ~verbsneeze as a cloud of dust rises off of ~pron and settles to the ground.",
				"A variety of flower petals float down onto ~name.",
				"A seed drops to the ground in front of ~name, sprouts, blooms, withers, and dies.",
			}),
		// FIRE
		"fire": ({
				"A flame emanates from ~npos fingers momentarily.",
				"A shower of sparks falls around ~name but winks out before touching anything.",
				"You feel a hot flash and your skin turns bright red.",
				"Smoke floats up from ~npos hands as all of the dead skin turns to ash and falls off.",
			}),
		// ICE
		"ice": ({
				"A snowball appears in ~npos hand.\nIt disappears as ~pron ~verbdrop it.",
				"You feel a momentary chill as your breath puffs out in a cloud.",
				"Frost crawls from ~npos feet across the ground.",
				"You think you hear the faint sound of sleigh bells and deep laughter.",
			}),
		// LIGHTNING
		"lightning": ({
				"~Name ~verbjump with a startle as ~pron ~verbis shocked.",
				"Your ears buzz and thoughts race through your mind too quickly for you to understand.",
				"Ozone floods the area and fades away, leaving a fresh clean smell.",
				"For a moment, the metal around ~name hums slightly, as though drawn toward ~obje.",
			}),
		// ORDER
		"order": ({
				"A circle appears in front of ~name.",
				"~Name ~verbis briefly surrounded by a complex matrix of light.",
				"The dust around ~name jumps and arrays itself into neat little rows.",
				"You feel a sensation of peaceful calm",
			}),
		// SPIRIT
		"spirit": ({
				"A bright white light appears in front of ~name.",
				"You feel the pulse of life within and around you.",
				"The faint sound of singing floats around you.",
				"The fatigue and cares of the world seem to drop away.",
			}),
		// WATER
		"water": ({
				"~Npos head gets soaked with water.",
				"Everything around ~name is blanketed in a light mist.",
				"You feel slightly refreshed.",
				"You smell rain.",
			}),
		// WIND
		"wind": ({
				"You hear a soft song playing in the wind.",
				"A sudden gust swirls around ~name.",
				"You hear a far off voice, but it drifts away.",
				"~Name ~verbbelch loudly.",
			}),
	]);
}

string query_step_skill(mixed param) {
	if( !param["option"] )
		param["option"] = "spirit";
	return "magic.mana."+param["option"];
}

string validate_params(mapping param) {
  if( param["target"] != param["caster"] )
    return "You shouldn't specify a target when casting this spell.";
  else if( param["caster"]->query_skill("magic.mana."+param["option"]) )
    return "ok";
  else if ( param["option"] )
    return "'"+param["option"]+"' is not a valid mana type.";
  else
    return "You must specify the mana type: 'cast cantrip as spirit', etc...";
}

int valid_target(mapping param) {
  return param["target"] == param["caster"];
}

varargs int on_cast(mapping param) {
  int amt, needed;
  string *msgs = message_map[param["option"]];

  param["caster"]->practice_skill_conditional("magic.mana."+param["option"], 25, 3);

  set_actor(param["caster"]);
  param["caster"]->msg_local( "~[030" + msgs[random(sizeof(msgs))] + "~CDEF" );

  return 1;
}
