/**
 * This handler helps control the fireworks used in the wizards spells.
 */
//#define BROADCASTER "/handlers/broadcaster"
#define MAX_RANGE 1600
#define SHIFT 30 /* needs to be more, once broadcaster is better */
#define TIME 15

class firework_running {
   string *messages;
   int index;
   string caster;
   string text;
   int *co_ord;
}

mixed *_effects;
class firework_running *_fireworks;

protected void do_effects();

void create() {
  _effects = ({
    ({
      "A small dot flashes up high into the sky.",
      "The dot suddenly bursts open revealing bright multicoloured streams "
          "of flame that pour down towards the ground.",
      "Just as you thought the streams had faded to nothing, they shoot back "
          "up into the air giving a final brilliant yellow colour before "
          "vanishing entirely.",
      "As it fades you think you see the letters \"$arg$\" in the gradually "
          "disappearing smoke.",
    }),
    ({
      "A brilliant trail of yellow sparks follows a small dot up into the "
          "sky.",
      "The dot slowly slows down until it has stopped moving, and hovers for "
          "a few seconds.",
      "Suddenly the dot explodes, sending out bright red streamers of light "
          "in all directions and lighting up the sky for a few seconds.",
      "The red light fades to nothingness, and the last colour left in the "
          "sky shows the letters \"$arg$\" which slowly disappear.",
    }),
    ({
      "A light flashes up high into the sky trailing grey smoke behind it.",
      "The light wizzes around in circles making a high pitched whizzing "
          "noise.",
      "The dot bursts open sending brilliant green streamers of light to "
          "all the corners of the sky.",
      "With a sudden resounding bang, the streamers rush back together to form "
          "\"$arg$\" which hangs in sky before slowly vanishing."
    }),
  });
  _fireworks = ({ });
} /* create() */

/**
 * This method creates a random firework at the casters location from the
 * current list of fireworks.  If the text field is not filled in then
 * the casters name is used.
 * @param caster the caster of the spell
 * @param text the text to print in the firework
 * @see do_effect()
 */
varargs void random_firework( object caster, string text ) {
  mixed *co_ord;
  class firework_running new_firework;

  co_ord = (mixed *)environment( caster )->query_co_ord();
  if ( sizeof( co_ord ) < 3 ) {
    co_ord = ({ 0, 0, 0 });
  }
  if ( !text || ( text == "" ) ) {
    text = (string)caster->query_name();
  }
  new_firework = new(class firework_running);
  new_firework->messages = _effects[random(sizeof(_effects))];
  new_firework->index = 0;
  new_firework->text = capitalize(text);
  new_firework->co_ord = ({ co_ord[ 0 ], co_ord[ 1 ], co_ord[ 2 ] + SHIFT });
  if ( !sizeof(_fireworks)) {
    call_out( (: do_effects :), TIME );
  }
  _fireworks += ({ new_firework });
} /* random_firework() */

/**
 * This method broadcasts the actual firework messages.
 * @see random_firework()
 */
protected void do_effects() {
  class firework_running firework;

  foreach (firework in _fireworks) {
    BROADCASTER->broadcast_event( users(), firework->co_ord, "you see:\n"+
        replace( firework->messages[firework->index] , "$arg$",
        firework->text ), MAX_RANGE, 0, 0 );
    firework->index++;
    if ( firework->index >= sizeof( firework->messages ) ) {
      _fireworks -= ({ firework });
    }
  }
  if ( sizeof( _fireworks ) ) {
    call_out( (: do_effects :), TIME );
  }
} /* do_effects() */

/**
 * This method returns the list of fireworks currently available.
 * The list constists of an array of firework effects.  Each effect
 * consists of a list of strings.  The strings are printed one by
 * one with a delay between each. <br>
 * ie:
 * <pre>
 * ({
 *   ({
 *      mess1,
 *      mess2,
 *      ...
 *    }),
 *   ({
 *      /\* Second effect *\/
 *    })
 * });
 * </pre>
 * @return the effects array
 */
mixed *query_effects() {
   return _effects;
} /* query_effects() */
