#define WEATHER_PERIOD 600 /* Time to chance weather */
#define TIMER_OB "/obj/timer"
/*    1, midday
      2, evening
      3, midnight
      4, night
      5, morning
*/
string day_type;
string * types = ({ "rainy", "foggy", "snowy" });
string * type_nouns = ({ "rain", "fog", "snow" });
int day_state;
int weather_state;
int light_state;

string get_weather(int i) {
	switch(i) {
		case 0: return "rain falling down from the sky";
		case 1: return "fog floating above ground";
		case 2: return "snow falling down from the sky";
	}
	return "Hmm";
}

string show_weather_change(int last_state) {
    string buf;
    buf = "";
    if (last_state == 0) buf+="Thick clouds form in the sky.\n";
    switch(random(3)){
    case 0:
	buf+="The "+type_nouns[last_state]+" vanishes. ";
    case 1:
	buf+="The "+types[last_state]+" weather slowly changes. ";
	break;
    case 2:
	buf+="The "+type_nouns[last_state]+" disappears. ";
    case 3:
	buf+="The "+types[last_state]+" weather comes to a end. ";
	break;
    default:
	buf+="The weather suddenly changes. ";
    }

    switch(random(3)){
    case 0:
	buf+= "It becomes very "+types[weather_state]+".\n";
	break;
    default:
	buf+= "The "+day_type+" becomes "+types[weather_state]+".\n";
	break;
    }

    return buf;
}
void change_weather() {
    int last_state;
    int i;
    object *obs;
    obs = users();
    remove_call_out("change_weather");
    day_state=TIMER_OB->query_time_of_day();
    switch(day_state) {
		case 1: day_type = "midday"; break;
		case 2: day_type = "evening"; break;
		case 3: day_type = "midnight"; break;
		case 4: day_type = "night"; break;
		case 5: day_type = "morning"; break;
}
    last_state = weather_state;
    weather_state = random(sizeof(types));
    if ( weather_state != last_state )    {
	}
	for(i=0;i<sizeof(obs);i++) {
		if(environment(obs[i])->query_weather()) {
		tell_object(obs[i], show_weather_change(weather_state)+"\n");
    }
}
    call_out("change_weather", WEATHER_PERIOD);
}

string query_current_weather(){
	string str;
	str = "";
	str += "It is a "+day_type+" and there is a "+get_weather(weather_state)+".\n";
   return str;
}
string query_time_of_day() {
	return day_type;
}
int query_light_state() {
	return light_state;
}
void create() {
  change_weather();
}
