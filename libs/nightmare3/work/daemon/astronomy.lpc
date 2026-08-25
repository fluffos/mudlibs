#include <daemons.h>
#include <clock.h>
#include <astronomy.h>

#define DEFAULT_MSG "You do not see that here."

private  nosave int moon_light;
private  nosave mapping moons;

void init_sky();
void set_moon_light();
string query_phase_name(int x);
int query_phase(string moon);

void create() {
    moons = ([]);
    init_sky();
    set_moon_light();
}

void init_sky() {
    int x;

    moons[MOONS[0]] = CURRENT_WEEK(time()) + 1;
    x = date(time())+(20*(CURRENT_MONTH(time())));
    moons[MOONS[1]] = 1+((to_int(to_float(x)/2.5))%4);
    moons[MOONS[2]] = 1+((x/10)%4);
}

int query_phase(string moon) {
    if(member_array(moon, MOONS) == -1) return 0;
    else return moons[moon];
}

string query_phase_name(int phase) {
    if(phase > sizeof(PHASES)) return "Error";
    else return PHASES[phase-1];
}

void set_moon_light() {
    int i;

    i = sizeof(MOONS);
    moon_light = 0;
    while(i--) {
        switch(moons[MOONS[i]]) {
            case 1: break;
            case 2: moon_light += 1; break;
            case 3: moon_light += 2; break;
            case 4: moon_light += 1; break;
        }
    }
    moon_light = moon_light/2;
}

int query_moon_light() { return moon_light; }

void la_sky(string str) {
    string tod;
    string *phase;
    int i;

    if(environment(this_player())->query_property("indoors")) {
      write(DEFAULT_MSG);
      return;
    }
    tod = (string)EVENTS_D->query_time_of_day();
    phase = allocate(i=sizeof(MOONS));
    while(i--)
    phase[i] = (query_phase_name(query_phase(MOONS[i])) || "");
    switch(str) {
        case "sun":
          switch(tod) {
            case "dawn":
              write("The sun is hanging low in the dawning eastern sky.");
              break;
            case "day":
              write("The sun is shining brightly in the daytime sky.");
              break;
            case "twilight":
                write("The sun is falling into the twilight sky.");
              break;
            case "night":
              write(DEFAULT_MSG);
              break;
          }
          break;
        case "moon":
          if(tod != "night")
            write(DEFAULT_MSG);
          else {
              write("The sky is dark with night.");
            if(phase[0] != "new") write("There is a "+MOON_DESC[0]+".");
            if(phase[1] != "new") write("There is a "+MOON_DESC[1]+".");
            if(phase[2] != "new") write("There is a "+MOON_DESC[2]+".");
          }
          break;
        case "sky":
          switch(tod) {
            case "dawn":
              write("%^ORANGE%^It is lit with the colours of a brand "
		    "new day.");
              break;
            case "day":
              write("%^BOLD%^%^YELLOW%^The sun lights up the "
		    "daytime sky.");
              break;
            case "twilight":
              write("%^BOLD%^%^MAGENTA%^The sun is fading over the "
		    "western horizon.");
              break;
            case "night":
              //if(phase[0] == phase[1] == phase[2] == "new")
              if(true())
                write("The night time sky is moonless and dark.");
              else {
                write("The sky is darkened with night.");
                if(phase[0] != "new")
                  write("There is a "+MOON_DESC[0]+" in the sky.");
                if(phase[1] != "new")
                  write("There is a "+MOON_DESC[1]+" in the sky.");
                if(phase[2] != "new")
                  write("There is a "+MOON_DESC[2]+" in the sky.");
              }
              break;
          }
          break;
        case "moons":
          if(tod != "night") write(DEFAULT_MSG);
          else {
            if(phase[0] != "new") write("There is a "+MOON_DESC[0]+".");
            if(phase[1] != "new") write("There is a "+MOON_DESC[1]+".");
            if(phase[2] != "new") write("There is a "+MOON_DESC[2]+".");
            //if(phase[0] == phase[1] == phase[2] == "new")
              write(DEFAULT_MSG);
          }
          break;
        case "laros": case "red moon":
          if(tod != "night" || phase[0] == "new") write(DEFAULT_MSG);
          else write("The "+phase[0]+" %^RED%^"+MOON_DESC[0]+"%^RESET%^"
		     " is hovering in the night time sky.");
          break;
        case "spyefel": case "blue moon":
          if(tod != "night" || phase[1] == "new") write(DEFAULT_MSG);
          else write("The "+phase[1]+" %^BLUE%^"+MOON_DESC[1]+"%^RESET%^"
		     " is hovering in the night sky.");
          break;
        case "slayar": case "green moon":
          if(tod != "night" || phase[2] == "new") write(DEFAULT_MSG);
          else write("The "+phase[2]+" %^GREEN%^"+MOON_DESC[2]+" %^RESET%^"
		     "is hovering in the night sky.");
          break;
    }
}
