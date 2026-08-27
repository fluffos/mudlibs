inherit "std/object";
 
#include "climate.h"
#define FILE_NAME "/save/environ/weather"
#define HOME "/obj/handlers/weather_room"
#define MAX_DIST 100
#define YEAR 60
#define DAY 60
#define SPEED 40
 
/*
 * hmmmmm. ok well cloud cover...
 *                   wind speed...
 * hmmm. what would be a nice way of doing that? and climate...
 *
 * well we could do something like having the cloud cover sort of follow the low
 * or we could change the low scheme. I dont belive in global patterns, ie the
 * whole mud having the same weather. but nearby rooms should have very similar
 * weather.
 */
 
mixed *coldarr,
      *cloudarr,
      *rainarr;
 
int timeofyear,
    mooncycle,
    moonoff,
    timeofday,
    intensity;
 
int distance(mixed *co_ord1,mixed *co_ord);
int cloud_index(object env);
int rain_index(object env);
int temperature_index(object env);
string cloud_string(object env);
string rain_string(object env);
string temperature_string(object env);
 
void setup() {
  set_name("weather");
  set_short("weather controller extrodinare");
  set_long("The weather controller, at least this one is always right!\n");
  cloudarr = ({ ({ 0,0 }), ({ 50,50 }), ({ -50,-50 }) });
  rainarr = ({ ({ 0,0 }), ({ 50,50 }), ({ -50,-50 }) });
  coldarr = ({ ({ 0,0 }), ({ 50,50 }), ({ -50,-50 }) });
 
  intensity = 100;
  restore_object(FILE_NAME);
  call_out("update_low",SPEED);
  move("bing");
}
 
/* have this move here to get it to my weather room ;) */
move(arg) {
  ::move(HOME);
}
 
mixed *query_cold() { return coldarr; }
mixed *query_rain() { return rainarr; }
mixed *query_cloud() { return cloudarr; }
int query_moon() { return mooncycle; }
string query_moon_string(object env) {
  int bing;
 
  bing = timeofday - (DAY/4) -
         (distance((mixed *)env->query_co_ord(), ({ 0, 0, 0, }))/100);
  if (bing<0) bing += DAY;
  if ((moonoff+(DAY/2)<bing) && (bing<DAY-moonoff))
    return 0; /* the moon is not up... */
  return ({ "luna llena",
            "cuarto de luna menguante",
            "media luna en menguante",
            "luna en tres cuartos menguante",
            "luna casi imperceptible en menguante", /* from here */
            "luna nueva",
            "luna casi imperceptible en creciente", /* to here you cannot see at night... ! */
            "cuarto de luna creciente",
            "media luna en creciente",
            "tres cuartos de luna en creciente" })[mooncycle];
}
 
int distance(mixed *co_ord1, mixed *co_ord2) {
  int off;
  if (!pointerp(co_ord1) || !pointerp(co_ord2))
    return 0;
  if (co_ord1[0]>co_ord2[0])
    off = co_ord1[0] - co_ord2[0];
  else
    off = co_ord2[0] - co_ord1[0];
  if (co_ord1[1]>co_ord2[1])
    off += co_ord1[1] - co_ord2[1];
  else
    off += co_ord2[1] - co_ord1[1];
  return off;
}
 
int query_season() { return timeofyear/15; }
int query_time_of_year() { return timeofyear; }
int query_time_of_day() { return timeofday; }
int query_day(object env) {
  int bing, bit;
 
  if (!env) {
    env = find_object("/d/am/am/mendedrum");
    if (!env)
      call_other("/d/am/am/mendeddrum", "??");
    env = find_object("/d/am/am/mendeddrum");
  }
/* make it change... but not very quickly... */
  bing = timeofday - (DAY/4) -
         (distance((mixed *)env->query_co_ord(), ({ 0, 0, 0, }))/100);
  if (bing<0) bing += DAY;
  bit = (DAY/2)-(timeofyear-(YEAR/2))/(YEAR/10);
  if (bing>bit)
    return 0;
  if (bit < 10)
    return bit;
  return -(bing - bit);
}
 
/*
 * returns a percentage of light.... 100 being full sunlight...
 * down
 */
int query_darkness(object env) {
  int bing, per, i;
 
/* so thats the day.... we should make the light fade towards night
 * though.... Hmmm.
 */
  per = -cloud_index(env);
  if (per <-100)
    per = -100;
  if (per > 100)
    per = 100;
  if ((i=query_day(env))) {
    i *= 20;
    if (i>100)
      i = 100;
    return 50+(per+100)*150*i/20000;
  }
  bing = timeofday - (DAY/4) -
         (distance((mixed *)env->query_co_ord(), ({ 0, 0, 0, }))/100);
  if (bing<0) bing += DAY;
  if ((moonoff+(DAY/2)<bing) && (bing<DAY-moonoff))
    return 15+(per+100)*30/200;
  if (timeofday<0) timeofday += DAY;
  i = mooncycle -5;
  if (i<0)
    i = -i;
  return 30+(per+100)*14*i/200; /* lit up by the light of the moon... tell them about it? */
}
 
string weather_string(object env) {
  return temperature_string(env)+" con "+cloud_string(env)+
         rain_string(env);
}
 
int query_raining(object env) {
  int cloud,rain;
  if (temperature_index(env)/(100/7)<2) {
    cloud = cloud_index(env);
    if (cloud<=0)
      return 0;
    rain = rain_index(env);
    if (cloud-rain<=0)
      return 0;
    return cloud-rain;
  }
  return 0;
}
 
int query_hailing(object env) {
  int cloud, rain;
 
  if (temperature_index(env)/(100/7)==2) {
    cloud = cloud_index(env);
    if (cloud <=0)
      return 0;
    rain = rain_index(env);
    if (cloud-rain <=0)
      return 0;
    return cloud-rain;
  }
  return 0;
}
 
int query_snowing(object env) {
  int cloud,rain;
  if ((temperature_index(env)/(100/7))>=3) {
    cloud = cloud_index(env);
    if (cloud<=0)
      return 0;
    rain = cloud_index(env);
    if (cloud-rain<=0)
      return 0;
    return cloud-rain;
  }
  return 0;
}
 
string rain_string(object env) {
  int cloud, rain, temp;
  string tempstr1,tempstr2;
 
  cloud = cloud_index(env);
  rain = rain_index(env);
  if (cloud<=0) return "";
  if (cloud-rain<=0) return "";
  temp = temperature_index(env)/(100/7);
  if (temp>3) temp = 3;
  if (temp<-3) temp = -3;
  tempstr1 = ({ "muy caliente ",
                "caliente ",
                "templado ",
                "agradable ",
                "frio ",
                "",
                "" })[temp+3];
  tempstr2 = ({ " lluvia",
                " lluvia",
                " lluvia",
                " lluvia",
                " lluvia",
                " granizo",
                " nieve" })[temp+3];
  cloud = (cloud-rain) / 20;
  if (cloud>5) cloud = 5;
  return "\n"+capitalize(tempstr1 + ({ "muy suave",
                      "suave",
                      "medio",
                      "fuerte",
                      "muy fuerte" }) [cloud]+tempstr2);
}
 
string temperature_string(object env) {
  int inten;
  inten = temperature_index(env);
  inten /= 10;
  if (inten>10)
    inten = 10;
  if (inten<-10)
    inten = -10;
  return ({ "Tan caluroso que podrias freir huevos sobre una roca", /* -10 */
            "Tanto calor que parece que el sol este al lado", /* -9 */
            "Extremadamente caluroso", /* -8 */
            "Muy caluroso", /* -7 */
            "Caluroso", /* -6 */
            "Caluroso", /* -5 */
            "Razonablemente caluroso", /* -4 */
            "Muy templado", /* -3 */
            "Templado", /* -2 */
            "Agradablemente templado", /* -1 */
            "Temperatura media", /* 0 */
            "Un poco fresco", /* 1 */
            "Brisa fresca", /* 2 */
            "Fresco", /* 3 */
            "Muy fresco", /* 4 */
            "Frio", /* 5 */
            "Frio", /* 6 */
            "Muy frio", /* 7 */
            "Extremadamente frio", /* 8 */
            "Increiblemente frio", /* 9 */
            "Tan frio que si escupieses se congelaria tu saliva"})[inten+10]; /* 10 */
}
 
string cloud_string(object env) {
  int off;
 
  off = cloud_index(env) / 20;
  if (off>5) off = 5;
  if (off<-5) off = -5;
  return ({ "un limpio y despejado cielo", /* -5 */
            "alguna nube en el horizonte", /* -4 */
            "poca nube y muy altas", /* -3 */
            "una fina capa de nubes", /* -2 */
            "una capa de nubes ligera", /* -1 */
            "cielo cubierto", /* 0 */
            "una capa de nubes que no deja ver el sol", /* 1 */
            "una gruesa capa de nubes", /* 2 */
            "una gruesa capa de nubes", /* 3 */
            "nubarrones negros", /* 4 */
            "una capa extremadamente espesa de negros nubarrones", /* 5 */
         })[off+5];
}
 
int temperature_index(object env) {
  int off,i;
  mixed clim, *co_ord;
 
  for (i=0;i<sizeof(coldarr);i++)
    off += (distance((mixed *)env->query_co_ord(), coldarr[i]) % (MAX_DIST*2));
  off = off / sizeof(coldarr);
  if ((clim = (mixed *)env->query_property("climate")))
    off += clim[C_TEMP];
  if (off>MAX_DIST) off = (MAX_DIST*2) - off;
  off -= (MAX_DIST/2);
  off = 0 - off;
  co_ord = (mixed *)env->query_co_ord();
  if (!co_ord)
    co_ord = ({ 0, 0, 0 });
  return (off + (timeofyear - (YEAR/2)) + (timeofday - (DAY/2)) + co_ord[2]);
}
 
int cloud_index(object env) {
  int off;
  mixed *clim;
  int i;
 
  for (i=0;i<sizeof(cloudarr);i++)
    off += (distance((mixed *)env->query_co_ord(), cloudarr[i]) % (MAX_DIST*2));
  off = off / sizeof(cloudarr);
  if ((clim = (mixed *)env->query_property("climate")))
    off += clim[C_CLOUD];
  if (off>MAX_DIST) off = (MAX_DIST*2) - off;
  off -= (MAX_DIST/2);
  off = 0-off;
  return (off + (timeofyear - (YEAR/2)));
}
 
int rain_index(object env) {
  int off;
  mixed *clim;
  int i;
 
  for (i=0;i<sizeof(rainarr);i++)
    off += (distance((mixed *)env->query_co_ord(), rainarr[i]) % (MAX_DIST*2));
  off = off / sizeof(rainarr);
  if ((clim = (mixed *)env->query_property("climate")))
    off += clim[C_RAIN];
  if (off>MAX_DIST) off = (MAX_DIST*2) - off;
  off -= MAX_DIST/2;
  off = 0-off;
  return off;
}
 
void update_low() {
  int i;
 
  timeofday++;
  if (timeofday>DAY) {
    timeofday = 0;
    timeofyear++;
    mooncycle++;
    if (mooncycle %2) {
      moonoff += 1;
      moonoff = moonoff % (DAY/2);
    }
    timeofyear = timeofyear % YEAR;
    mooncycle = mooncycle % 10;
    save_object(FILE_NAME);
  }
  for (i=0;i<sizeof(rainarr);i++) {
    rainarr[i][0] += random(3)-1;
    rainarr[i][0] = rainarr[i][0] % (MAX_DIST*2);
    rainarr[i][1] += random(3)-1;
    rainarr[i][1] = rainarr[i][1] % (MAX_DIST*2);
  }
  for (i=0;i<sizeof(cloudarr);i++) {
    cloudarr[i][0] += random(3)-1;
    cloudarr[i][0] = cloudarr[i][0] % (MAX_DIST*2);
    cloudarr[i][1] += random(3)-1;
    cloudarr[i][1] = cloudarr[i][1] % (MAX_DIST*2);
  }
  for (i=0;i<sizeof(coldarr);i++) {
    coldarr[i][0] += random(3)-1;
    coldarr[i][0] = coldarr[i][0] % (MAX_DIST*2);
    coldarr[i][1] += random(3)-1;
    coldarr[i][1] = coldarr[i][1] % (MAX_DIST*2);
  }
  intensity += random(3)-1;
  if (intensity<50)
    intensity=50;
  if (intensity>300)
    intensity=300;
  call_out("update_low",SPEED);
}
 
void dest_me() {
  save_object(FILE_NAME);
  ::dest_me();
}
