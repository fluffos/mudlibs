#include <std.h>
#include <vampq.h>
inherit MONSTER;
int test_heart;
void create() {
    ::create();
    set_name("Drunken Villager");
    set("id", ({ "monster", "villager", "drunken", "drunken villager" }) );
    set_level( 20 );
    set("short", "Drunken Villager" );
    set("long", "The villager stands short in height and is very thin. He stumbles around tirun with his flask in his pocket, drinking any alcohol he can get his hands on." );
    set("race", "human" ); //
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 5); 
    set_fingers(5);
    set_class("fighter");
    set_moving(1); 
    set_speed(10);
    set_heart_beat(1);
    set_lang_prof("Selunian", 10);
    set_speech(4, "Selunian", ({"Hey you! Got any alcohol?",
	"I won't work for alcohol, but I will take some.",
	"Where did I put my flask?"}), 0);
    set_emotes(2, ({
	"The drunken villager rummages around for his flask.",
	"The drunken villager takes a sip from his flask.",
	"The drunken villager belches loudly."
      }), 0);
    new(VO"flask")->move(this_object());
}
int test_heart() { 
    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
    return 1; 
}
