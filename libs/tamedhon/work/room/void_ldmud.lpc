// 2024/05/12 streng typisiert, nette Beschreibung gemacht - Aloy

#pragma strong_types

inherit "/std/room";
#include <properties.h>
#include <moving.h>

int welt();

void create()
{
  ::create();
  SetProp(P_ENVIRONMENT, ([ENV_TEMPERATURE: 15+random(3), ENV_TERRAIN:TT_FOREST]));
  SetProp(P_LIGHT, 1 );
  SetProp(P_INDOORS, 0 );
  SetProp(P_INT_SHORT, "Die Anderswelt" );
  SetProp(P_INT_LONG,break_string(
    "Du befindest dich hier in der mittleren Welt der Anderswelt. "
    "Du bist hier gelandet, weil die Welt, in der du dich befunden hast, zerstört wurde. "
    "Es sieht alles wie die echte Welt und auch wieder nicht wie die echte Welt aus. "
    "Diverse Geister beobachten dich und du siehst den Weltenbaum. "
    "Ein Naturgeist kommt auf dich zu, du fühlst, dass er nichts Böses möchte und dir helfen möchte. "
    "Er flüstert dir, dass du 'welt' sagen sollst und bringt dich dann zurück in die Welt der Sterblichen.")
  );

  AddCmd( "welt", "welt"); /* im Nichts gibt es keine 'exits' */
}

int welt()
{
    if(interactive(this_player()))
    {
        this_player()->move("/gilden/abenteurer", M_TPORT);
    }
  return 1;
}
