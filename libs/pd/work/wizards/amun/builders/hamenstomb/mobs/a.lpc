#include <std.h>
#include <daemons.h>
#include <amun.h>
#include <amun_riddles.h>
#define QUESTION 0
#define ANSWER 1
inherit MONSTER;
string* riddles;
mapping players;
void give_riddle(string);
void check_riddle(string);
void create() {
    ::create();
    set_name("Criosphinx");
    set("id", ({ "criosphinx", "sphinx", "monster" }) );
    set_level( 65 );
    set("short", "Criosphinx" );
    set("long", "The Sphinx stands proud as if all-knowing. She seems to be staring at the floor." );
    set("race", "Sphinx" ); 
    set_gender( "female" );
    set_body_type("centaur");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"The sphinx mutters something about loose flooring."}), 0);
    new(WEP+"sphinx_claws")->move(this_object());
    new(WEP+"sphinx_claws")->move(this_object());
    force_me("wield claw");
    force_me("wield claw 2");
    riddles = RIDDLES;
    players = ([]);
}
void init() {
    ::init();
    if( !this_player()->is_player() )
	return;
    call_out("give_riddle", 0, this_player()->query_name());
}
void give_riddle(string name) {
    object tp;
    if( !name || name == "" || !find_player(name) )
	return;
    if( !present(name, environment()) )
	return;
    if( !players[name] ) {
	int i =  random(sizeof(riddles));
	force_me("say " + capitalize(name) + ", In order to pass an answer to the unknown must be stated. Intelligence is a virtue to us Sphinx's, so riddle me this:\n" + riddles[i][QUESTION]);
	players[name] = i + 1;
    }
    else {
	force_me("say " + capitalize(name) + ", have you solved my riddle yet?\n" + riddles[players[name]-1][QUESTION]);
    }
}
void catch_tell(string str) {
    string pname, answer;
    if( this_player() == this_object() )
	return;
    str = TERMINAL_D->no_colours(str);
    if( sscanf(str, "%s says: %s\n", pname, answer) == 2 || sscanf(str, "%s says: %s", pname, answer) == 2 ) {
	pname = lower_case(pname);
	if( find_player(pname) && present(pname, environment()) ) {  
	    if( players[pname] ) {
		if( answer != (string)(riddles[players[pname]-1][ANSWER]) ) {
		    force_me("say No, " + capitalize(pname) + " That is incorrect. Please try again."); 
		}
		else {
		    force_me("say Yes, " + capitalize(pname) + ", that is correct!");
		    map_delete(players, pname); find_player(pname)->move_player(HELLROOM+"eye_of_hell_1", "into the eye of hell");
		}
	    }
	}
    } 
}
