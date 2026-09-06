// A sundial object for outdoor rooms
// created Tune [13-jun-97]

#include <properties.h>
#include <nightday.h>
#include <daemons.h>

inherit "/std/thing";

void create()
{
  ::create();
  SetShort("a sunclock");

  AddId( ({ "clock", "sunclock", "sundial", "dial"}) );
  AddAdjective("sun");

  SetReadMsg("The grooves are marked with words to indicate the "
   "time of day.\n");

  Set(P_NOGET, "It is far too heavy for you to carry.\n");
}

varargs string InvShort()
{
  return ""; // this makes it invis in room, but you can look at it
}

varargs string *QueryLong()
{
  string s, long;

  long =
   "The sunclock consists of a large, polished redstone circular "
   "face on a low pedestal. ";

  switch(({int})NIGHTDAY->QueryState())
  {
    case ND_TWILIGHT..ND_EVENING:
      //fall through

    case ND_NIGHT..ND_PREDAWN:
      s = "It is too dark, though, for the arm of the sunclock "
          "to cast a shadow.";
      break;

    case ND_DAWN:
      s = "It is still too dark to make out the time on the face "
          "of the sunclock.";
      break;

    case ND_SUNRISE:
      s = "The arm of the sunclock casts a long shadow over the "
          "groove marked 'First Hour'.";
      break;

    case ND_EARLY_MORNING:
      s = "The arm of the sunclock casts a semi-long shadow over the "
          "groove marked 'Low Morning'.";
      break;

    case ND_LATE_MORNING:
      s = "The arm of the sunclock casts a semi-short shadow over the "
          "groove marked 'High Morning'.";
      break;

    case ND_NOON:
      s = "The arm of the sunclock casts a short shadow over the "
          "groove marked 'Middle Day'.";
      break;

    case ND_EARLY_AFTERNOON:
      s = "The arm of the sunclock casts a semi-short shadow over the "
          "groove marked 'Low Afternoon'.";
      break;

    case ND_LATE_AFTERNOON:
      s = "The arm of the sunclock casts a semi-long shadow over the "
          "groove marked 'High Afternoon'.";
      break;

    case ND_SUNSET:
      s = "The arm of the sunclock casts a long shadow over the "
          "groove marked 'Long Shadows'.";
      break;
  }
  return ({
   (long + s + "\n"),  // l & exa
   "The sunclock consists of a large, polished redstone circular "
   "face on a low pedestal. A thin arm extends upwards from the "
   "center of the face. Grooves radiate out from the arm in a "
   "semi-circle around the bottom half of the circular slab, with "
   "markings to indicate the time of day. "+s+"\n"
  });
}

