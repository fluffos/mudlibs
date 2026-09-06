/* -------------------------------------------------------------------------
 * basic room for the Silvere domain
 * -------------------------------------------------------------------------
 * 26-May-97 [MagicTcs]  Creation
 * 29-May-97 [Mica]      Added P_INT_WIZMSG, removed search-command
 * ??-Jun-97 [Sonic]     Moved P_MAP to /std/room.c
 * 16-Jun-97 [Tune]      Added TimeMsg()
 * 10-Jul-97 [Sonic]     Added handling of Windows
 * 13-Jul-97 [Sonic]     Added transparency and cleaning to the windows
 * 14-Apr-98 [Sonic]     Added some basic Season Stuff
 * -------------------------------------------------------------------------
 */

#include <properties.h>
#include <msgclass.h>
#include <moving.h>
#include <macros.h>
#include <nightday.h>
#include <silvere.h>

inherit "/std/room";

/* -------------------------------------------------------------------------
 * IntLong handles P_INT_WIZMSG property
 * -------------------------------------------------------------------------
 */

public varargs string IntLong(string what)  {
  string s, w;

  if ( ! ( s = ::IntLong(what) ) )
    return s;

  if ( ( TP ) &&
       ( query_user_level( TP ) ) &&
       ( ! ({int})TP->Query( P_NOWIZ ) ) &&
       ( w = Query( P_INT_WIZMSG ) ) )
    return s + "\n" + w;
  else
   return s;
}

/* -----------------------------------------------------------------
 * TimeMsg - This allows you to add extra text to rooms which is
 * time-based. To use it, embed this into your long description:
 * @@TimeMsg@@. Then add a property P_TIME_MSG which is a mapping
 * of strings.
 * -----------------------------------------------------------------
 */

public string TimeMsg() {
  int state;
  string s;

  state = ({int})NIGHTDAY->QueryState();

  if(s = Query(P_TIME_MSG)[state])
    return s;
  else if(({int})NIGHTDAY->IsDay() && (s = Query(P_TIME_MSG)[DAY_DEFAULT_MSG]))
    return s;
  else if(s = Query(P_TIME_MSG)[NIGHT_DEFAULT_MSG])
    return s;
  return "";
}

/* -----------------------------------------------------------------
 * SeasonMsg - This allows you to add extra text to rooms which is
 * season-based. To use it, embed this into your long description:
 * @@SeasonMsg@@. Then add a property P_SEASON_MSG which is a mapping
 * of strings.
 * -----------------------------------------------------------------
 */

public string SeasonMsg()
{
   int season;
   string s;

   season = ({int})NIGHTDAY->QuerySeason();

   if(s = Query(P_SEASON_MSG)[season])
      return s;
   return "";
}

/* -----------------------------------------------------------------
 *  SeasonDetail - This allows you to add details to rooms which are
 *  season dependent.
 *
 *  To use them, add the following in create():
 *
 *     AddSeasonDetail( "tree",            // or ({"tree","bush"})
 *      ([ WINTER : "The winter ....\n",
 *         SPRING : "The spring.....\n",
 *         SUMMER : "The summer.....\n",
 *         AUTUMN : "The autumn.....\n"
 *      ]) );
 * -----------------------------------------------------------------
 */

public string AddSeasonDetail(mixed det, mapping desc)
{
  int season;
  string s;

  season = ({int})NIGHTDAY->QuerySeason();

  if(s = desc[season])
  {
    AddDetail(det, desc[season]);  // <-- added this line
    return s;
  }
  else
    return "Unknown";
}

/* -----------------------------------------------------------------
 *  SeasonDetail - This allows you to add details to rooms which are
 *  season dependent.
 *
 *  To use them, add the following in create():
 *
 *     SetSeasonNoise(
 *      ([ WINTER : "The winter ....\n",
 *         SPRING : "The spring.....\n",
 *         SUMMER : "The summer.....\n",
 *         AUTUMN : "The autumn.....\n"
 *      ]) );
 * -----------------------------------------------------------------
 */

public string SetSeasonNoise(mapping desc)
{
   int season;
   string s;

   season = ({int})NIGHTDAY->QuerySeason();

   if(s = desc[season])
   {
     SetIntNoise(desc[season]);
     return s;
   }
   else
    return "Unknown";
}

/* ********************************************************************** */

