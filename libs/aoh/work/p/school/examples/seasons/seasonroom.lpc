/* This is an example, how to set up a room using DayMsg() and
** SeasonMsg() for different descriptions during the day/season
** of the year.
**
** created:  Sonic [ 13-Apr-1998]
**
** DO NOT CHANGE, EXCEPT FOR A REALLY GOOD REASON
**
*/

#include "/d/valhalla/sys/valhalla.h"
#include <properties.h>
#include <nightday.h>
#include <moving.h>
#include <regions.h>
#include <config.h>
#include <rooms.h>
inherit STDROOM;

create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"A small example room");
   Set(P_INT_LONG,
      "This is a small garden. @@SeasonMsg@@ @@DayMsg@@\n");
      /* All Valhalla rooms use a special P_INT_LONG, that uses 
      ** process_string() to parse some special strings like 
      ** @@SeasonMsg@@ or @@DayMsg@@. That means every room will
      ** execute the function SeasonMsg(), if the string is present.
      ** Of course you can add own Strings, but then you have to 
      ** make sure, that the function is present in the file.
      */

   /* The following function sets the messages, that are used for
   ** replacing @@SeasonMsg@@ in the LongDescription of the room.
   ** Depending on the time of the year, an appropriate message
   ** will be displayed. The seasons at Valhalla follow the seasons
   ** in real life.
   */
   Set(P_SEASONMSG,
   ([ S_SPRING:
         "Lots of flowerbeds can be seen here. Some bushes are "
         "growing next to them. A small bush is placed in the "
         "center of the flowerbed.",
      S_SUMMER:
         "Lots of flowerbeds are here. They are arranged around "
         "a small bush in the center of the room.",
      S_AUTUMN:
         "Some few flowers are growing in some flowerbeds here. "
         "A small bush with lots of dead leaves around it is "
         "growing in the center of the flowerbeds.",
      S_WINTER:
         "A small bush is growing in the center of the small "
         "garden. There is nothing special here except some "
         "small snowweaves.",
   ]) );

   /* As P_SEASONMSG above, P_DAYMSG strings are replacing
   ** @@DayMsg@@ in the LongDescription of the room. Depending on
   ** the time of the day you can give your room special descriptions.
   ** If you don't have defined a message for a certain state of the
   ** day, one of two default-messages will be used instead
   ** (DEFAULT_DAY_MSG or DEFAULT_NIGHT_MSG).
   */
   Set(P_DAYMSG,
   ([ DEFAULT_DAY_MSG: "It is day and the sun shines down on you.",
      DEFAULT_NIGHT_MSG: "It is night and the moon is spending only "
                         "very few light.",
   ]) );

   Set(P_REGION, REGION_MEADOW);
}
