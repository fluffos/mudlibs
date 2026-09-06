/**
 * This daemon handles sending sounds to players.
 *
 * Right now, I am only supporting MSP codes, but will eventually add Portal
 * and possibly other systems to the list.
 */

#define BASE_URL	"http://mud.simud.org:8080/audio/"

void create() {
	debug("audio daemon initialized","audio");
}

string destructor() {
	debug("audio daemon destructed","audio");
	return 0;
}

string query_battle_music() {
	string *list = ({ "bgm/verdi_dies_irae.mp3",
				      "bach/bach_847.mid",
					  "bjorn/bjorn_lynne-trailblazer.mid",
					  "bjorn/bjorn_lynne-zombie_chase.mid",
					  "bjorn/bjorn_lynne-the_chaos_warrior.mid",
				   });
	return list[random(sizeof(list))];
}

void start_the_music(object who) {
	object area;
	string bgm;
	for( area = environment(who); area; area = environment(area) ) {
		if( bgm = area->query_bgm() )
			break;
	}
	if( bgm ) {
		debug("Playing "+bgm+" for "+who->query_name(),"audio");
		this_object()->bgm( who, bgm, -1 );
	} else {
		debug("No BGM for "+who->query_name()+"'s location","audio");
		this_object()->bgm( who, "Off" );
	}
}

varargs void sfx(object who, string fname, int repeat) {
	if( !who || !who->query_env_var("Tmsp") )
		return;
	if( !repeat )
		repeat = 1;
	msg_object(who,"!!SOUND("+fname+" L="+repeat+")");
}

varargs void bgm(object who, string fname, int repeat) {
	if( !who || !who->query_env_var("Tmsp") )
		return;
	if( !repeat )
		repeat = 1;
	msg_object(who,"!!MUSIC("+fname+" L="+repeat+")");
}

void sfx_off(object who) {
	if( !who || !who->query_env_var("Tmsp") )
		return;
	msg_object(who,"!!SOUND(Off U="+BASE_URL+")");
}

void bgm_off(object who) {
	if( !who || !who->query_env_var("Tmsp") )
		return;
	msg_object(who,"!!MUSIC(Off U="+BASE_URL+")");
}

varargs void sfx_room(object room, string fname, int repeat) {
	object ob;
	if( !room || !room->query_is_room() )
		return;
	foreach( ob : all_inventory(room) )
		sfx(ob, fname, repeat);
}

varargs void sfx_mud(string fname, int repeat) {
	object ob;
	foreach( ob : users() )
		sfx(ob, fname, repeat);
}
