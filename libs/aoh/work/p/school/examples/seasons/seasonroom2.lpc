/* This is a little example, how to add a detail to the 
** room, which has different descriptions depending on the
** current season.
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

/* This is a function, that is called by AddDetail().
** the function returns a string, that will be displayed
** to the player.
**
** By querying P_SEASON, you get the current season of the year and
** therefore are able to choose a message with a simple switch/case
** routine. This could make a room very interesting.
*/
string CheckFlowerbed()
{
   switch(Query(P_SEASON))
   {
      case S_SPRING:
         return
            "Around a nice bush in the center of the garden are some "
            "nicely arranged flowerbeds. Lots of young flowers "
            "are growing there.\n";
         break;
      case S_SUMMER:
         return
            "Around a bush in the center of the garden are some "
            "flowerbeds. They are full of different flowers at the "
            "moment. It looks really nice.\n";
         break;
      case S_AUTUMN:
         return
            "Around a bush with lots of dry leaves in the center of "
            "the garden are some nearly empty flowerbeds. You see "
            "some single flowers standing there, but that's all. "
            "It looks rather boring.\n";
         break;
      case S_WINTER:
         return
            "A small bush stands in the center of an empty area. "
            "The poor thing is totally naked, as there are no leaves "
            "left at the moment. All around it is lots of snow, putting "
            "everything under a thick layer of white.\n";
         break;
   }
}

create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"A small example room");
   Set(P_INT_LONG,
      "This is a small garden. @@SeasonMsg@@ @@DayMsg@@\n");

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

   Set(P_DAYMSG,
   ([ DEFAULT_DAY_MSG: "It is day and the sun shines down on you.",
      DEFAULT_NIGHT_MSG: "It is night and the moon is spending only "
                         "very few light.",
   ]) );

   AddDetail( ({"bed","flowerbed"}), SF(CheckFlowerbed));

   Set(P_REGION, REGION_MEADOW);
}
