/* Monolith
**
**  04-Feb-93 [Mateese]
**  13-May-95 [Mateese] Seeing the monolith hiding is worth an explorer point.
*/

#include <properties.h>
#include <secure/wizlevels.h>

#define PL this_player()

inherit "/std/thing";

object behind;
object *watchers;

create () {
  thing::create();
  if (member(file_name(this_object()), '#') == -1) return;
  AddId ("monolith");
  SetValue (0);
  SetWeight (250000);
  watchers = ({});
}

reset() {
  if (watchers)
    watchers -= ({ 0 });
}

init() {
  int i;
  thing::init();
  watchers -= ({ 0 });
  if (member(watchers, PL) != -1) watchers -= ({ PL });
  if (PL == behind) behind = 0;
}

id (str) {
  if (member(watchers, PL) == -1 || IS_IMMORTAL(PL)) 
    return thing::id(str);
  return 0;
}

QueryShort(string str) {
  if (behind && !present(behind, environment())) behind = 0;
  if (member(watchers, PL) != -1 || PL == behind) return 0;
  if (!this_player() || str || !behind || !(behind->QueryShort())) 
    return "a monolith";
  this_player()->SetExplored();
  return "a monolith, hiding behind "+capitalize(behind->QueryName());
}

QueryLong() {
  if (behind && !present(behind, environment())) behind = 0;
  if ((!behind || !(behind->QueryShort())) && (PL->QueryShort())) {
    behind = PL;
    say ("You hear a rough shuffling sound, as if a large stone moves.\n");
  }
  if (member(watchers, PL) == -1) watchers += ({ PL });
  return "What monolith? You see none.\n";
}

