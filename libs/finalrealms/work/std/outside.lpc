//#define TESTING 1
#include "weather.h"
inherit "/std/room";
inherit "/std/basic/extra_look";

/* ok this is the out side room standard, It includes weather and
 * all that jazz
 */

/*
 * The night long is for rooms where you want the describe to change at
 * night.
 */
nosave string night_long;

/*
 * This is the string it will display instead of it is dark.
 */
nosave string dark_long;

/*
 * It will call this function on the room when it changes from dark to
 * light.  ie...  changes from day to night.
 */
nosave string light_change;
nosave int current_day;

void set_dark_long(string s) { dark_long = s; }
string query_dark_long() { return dark_long; }

void set_night_long(string s) { night_long = s; }
string query_night_long() { return night_long; }
#ifdef 0
mixed *query_init_data()
{
   return extra_look::query_init_data()+room::query_init_data();
}
#endif

void create() {
   dark_long = "It is dark.\n";
  room::create();
  extra_look::create();
  add_property("location", "outside");
} /* create() */

string short(int dark) {
  if (dark)
    return query_dark_mess(dark);
  else
    return ::short();
} /* short() */

string long(string str, int dark) {
int i;
string s, ret;

   ret = "";
  if ((int)WEATHER->query_day(this_object()) != current_day)
  {
    if (light_change)
        call_other(this_object(), light_change, current_day);
  }
  if(this_player()) dark = (int)this_player()->check_dark(query_light());
  if (!str)
  {
      ret = "It's daytime.\n";
    if( pointerp(co_ord) && !WEATHER->query_day(this_object()))
    {
    /* night... */
      ret = "It's night.\n";
          s = (string) WEATHER->query_moon_string(this_object());
      if (!s)
      {
         ret =  "It is night and the moon is not up.\n";
      }
      else
      {
        if ((int)WEATHER->cloud_index(this_object()) > 20)
            ret = "It is night and the "+s+" is hidden by the clouds.\n";

        else if(!dark || dark > 3) /* if its that dark it ain't lit up */
            ret = "The land is lit up by the eerie light of the "+s+".\n";
      }
      switch(dark) /* O.K. how much can we see at night */
      {
        default: /* can see anyway */
          if( night_long )
            ret += night_long;
          else
            ret += query_long();
        break;
        case 1..3:  /* too dark */
      if(dark_long) return ret + dark_long;
           return ret + ::query_dark_mess(dark)+ ".\n";
        case 4..6:  /* too bright */
           return ret + ::query_dark_mess(dark)+ "\nStrange... it seems to be night though.\n";
      }
   }
   else
   {
      switch(dark) /* O.K. how much can we see daytime */
      {
        default: /* can see anyway */
            ret = query_long();
        break;
        case 1..3:  /* too dark */
            return ::query_dark_mess(dark)+"\nHowever it seems to be daytime, strange...\n";
        case 4..6:  /* too bright */
            return ::query_dark_mess(dark)+".\n";
      }
    } /* if we got here we can see */
    s = calc_extra_look();
    if (s && s != "")
      ret += s;
    if (pointerp(co_ord))
      ret += (string)WEATHER->weather_string(this_object())+".\n";
   if(!exit_string) query_dirs_string();
   ret+= exit_string+"\n";
/* Return the long + the contents of the room. */
    return ret+query_contents("");
  }
  str = expand_alias(str);
  return items[str];
} /* long() */

/* percentage system */
int query_light() {
  int i;
#ifdef TESTING
  i = 100;
#else
  i = (int)WEATHER->query_darkness(this_object());
#endif

  return ::query_light()*i/100;
} /* query_light() */
int query_outside()
{
  return 1;
}


