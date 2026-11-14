/*   Example Room 8  (Mateese, 14-Aug-94)
**
** This is an indoors room, fully lighted, but through the windows the
** changing of the day time can be seen.
** Additionally the sunlight has a minimal effect on the internal light.
** The tricky part is: keeping track of the daytime while suppressing the
** announcements.
*/

#include <config.h>
#include <properties.h>
#include <weather.h>
#include <daemons.h>

inherit "/std/room";

string fwindows(); // forward

/*-------------------------------------------------------------------------*/
void create() 
{

  ::create();

  Set(P_INT_SHORT, "The 'indoors' example room with windows");

  Set(P_INT_LONG,
"You are in another 'indoors' exm. room (/d/archwiz/common/lpc/exm/xroom8.c).\n"
"This one is fully lighted, but through the windows the changing of the "
"daylight is percepted.\n"
"You are in a small hut with some big windows.\n"
"The exit is to the south, the hut extends to the north.\n"
     );

  AddExit("south", "/d/archwiz/common/lpc/exm/xroom6");
  AddExit("north", "/d/archwiz/common/lpc/exm/xroom10");

  AddDetail(({"window", "windows"}), #'fwindows);

    /* Set the details for 'sky' and 'heaven' since this room is not
    ** really outside.
    */
  AddDetail(({ "sky", "heaven" }), "You can't see it here.\n");

    /* Though this room is indoors, we must mark it as being outdoors,
    ** else it wouldn't be notified about the daylight changings.
    */
  Set(P_INDOORS);

    /* Set the background illumination.
    ** The illumination is 90% of the normal sunlight.
    */
  Set(P_BRIGHT, (9 * MAX_SUNBRIGHT) / 10);

    /* Set the maximal sunbright to 20% of the normal value.
    ** The actual sunbrightness will vary between 0 and this value.
    */
  Set(P_SUNBRIGHT, (2 * MAX_SUNBRIGHT) / 10);

}

/*-------------------------------------------------------------------------
** When the player looks at a window, he shall see the sky outside.
*/

string fwindows() {
  return "Through the window you see the land outside.\n"
         +QueryDayDesc();
}

/*-------------------------------------------------------------------------
** This function is called by the nightday-Server when it notifies
** the players here.
** We intercept it to change the WD_CDESC.
*/

varargs mixed * FilterWeatherData(object client, mixed *data, int newstate) {
  data[WD_CDESC] = "The light outside changes.\n";
  return ::FilterWeatherData(client, data, newstate);
}

/***************************************************************************/

