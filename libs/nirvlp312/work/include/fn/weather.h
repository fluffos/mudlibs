/************************************************************************/
/* weather */

/* I am not keen on this weather, but has to compat with dixies.... 
 * its a little simpler then the old one

   Weather: (How weather effects this room? controlled locally by room)
    0 : default weather (is not really used == 4) old was specific rooms
    1 : absolutely no weather (== 2)
    2 : inside (== 1)
    3 : shelter (is not as severe as full weather(-1 on weather strength))
    4 : full weather

   Weather strength is WEATHER_OBJ, 0 -> 6?, well good -> bad 

   Climate: (weather pattern of room, type set locally,
             pattern controlled by WEATHER_OBJ)

    0 : normal
    1 : bad
    2 : tropic 
    3 : jungle
    4 : desert
    5 : arctic
    6 : sea

    Day-Night cycle is controlled by WEATHER_OBJ 
*/
/* 
   Other Notes: To get the night-day cycles to work put fix_day(); into
   the rooms init() fn.
   adj_light() is a fn in base_obj if you are not using this

#define adj_light set_light
*/


#define WEATHER_OBJ "/obj/weather"

int weather;                  /* weather type of this room */
int climate;                  /* climate type of this room */
int daylight_adj;             /* current light adj, 1 == day, -1 == night */

string query_weather();
string  query_weather_forecast();
void  show_weather(object ob);
void set_weather(int l, int w, int c);
void fix_day();
status query_day();
string query_weather();
string  query_weather_forecast();
void  show_weather(object ob);
void set_weather(int l, int w, int c);
void fix_day();
status query_day();


string query_weather() {  /* returns current weather string */
  string str;
  int current_weather;

  if(weather == 1 || weather == 2) return "";
  current_weather = (int)WEATHER_OBJ->query_weather();
  if(weather == 3) current_weather -= 1; /* slightly less bad */
  return (string)WEATHER_OBJ->query_all_weather(climate,current_weather);
}

string  query_weather_forecast() { /* returns next weather string */
  string str;
  int current_weather;

  if(weather == 1 || weather == 2) return "";
  current_weather = (int)WEATHER_OBJ->query_next_weather();
  if(weather == 3) current_weather -= 1; /* slightly less bad */
  return (string)WEATHER_OBJ->query_all_weather(climate,current_weather);
}

void  show_weather(object ob) { /* called by weather ob to show weather */
  if(!ob) return;
  tell_object(ob, query_weather());
}

void set_weather(int l, int w, int c) { /* day-night cycles only when l = 1 */ 
  if(weather != 1) this_object()->adj_light(l);
  fix_day();
  weather = w; 
  climate = c;
}

void fix_day() { /* switches between night & day */
  int day;

  day = (int)WEATHER_OBJ->query_light_adjustment();
  if(weather == 1) return;   /* no weather, no adjusting light */
  if(!daylight_adj) { /* has not been set yet */
    daylight_adj = day;
    if(daylight_adj == -1) this_object()->adj_light(daylight_adj);
  }
  if(day != daylight_adj) {
    daylight_adj = day;
    this_object()->adj_light(day);
  }
}


string query_time() {
  return((string)WEATHER_OBJ->mud_time()+"");
}


status query_day() {
  if(!daylight_adj) fix_day();
  return (daylight_adj == 1);
}

