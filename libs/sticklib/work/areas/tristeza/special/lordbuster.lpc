#include <equipped_npc.h>
#include <areas.h>

void
create_monster()
{
    object ob;
    set_name("lordbuster");
    set_id(({ "buster", "man" }));
    set_short("Lordbuster, the ANGRY monster");
    set_level(50);
    set_hp(4000);
    set_ep(1500000);
    set_money(3000 + random(1001));
    set_long("He likes to smash lords. And he is EXTREMELY good at it!");
    set_gender(G_MALE);
    set_spell_chance(30);
    set_spell_mess2("Lordbuster fractures your bones.");
    set_alignment(AL_NEUTRAL);
    set_spell_mess1("Lordbuster fractures some bones of his opponent.");
    set_spell_dam(160);
    load_a_chat(33, ({
	"Lordbuster roars: MY MASTER IS SO PROUD OF ME BECAUSE I HAVE KILLED SEVERAL"+
	"LORDS BEFORE YOU!",
	"Lordbuster roars: WAS THAT YOUR BEST PUNCH?????? HAR, HAR!! MY LITTLE BROTHER"+
	"HITS HARDER!!!!!",
	"Lordbuster roars: I DIDN'T EVEN FEEL THAT ONE!",
	"Lordbuster roars: NOW I KILL YOU, LITTLE LADY!",
	"Lordbuster shouts: MASTER FROBOZZ, I WILL KILL THIS ONE EASILY!",
	"Lordbuster laughs at your puny efforts.",
	"Lordbuster says: Go get some help! You can't kill me by yourself!",
	"Lordbuster looks around and says: Where're the others???",
	"Lordbuster looks bored.",
	"Lordbuster says: Are you trying to kill me or what?",
	"Lordbuster looks frustrated and says: Aren't there any tuffer ladies out there?",
	"Lordbuster says: Beat it, little one, you bother me.",
	"Lordbuster roars: I AM GONNA RIP YOU APART!",
	"Lordbuster roars: YOU WILL DIE! ALL OF YOU!",
      }));
    add_weapon( AREA_TRISTEZA+"special/cheap_lordduster",
      "lordduster", 0, 3,
      "Lordbuster takes the lordduster." );
    add_object( AREA_TRISTEZA "special/wand_of_cold",
      "wand of cold", 0, 4,
      "Lordbuster takes the wand of cold." );
    add_object( AREA_TRISTEZA+"special/buster_bag", "bag", 0, 5,
      "Lordbuster takes the bag." ); 
    set_wc(60,1);
    set_ac(60,1);
}

init() {
    if(!this_player()->query_npc() && this_player()->query_level()<20) {
	this_player()->tell_me("Lordbuster throws you out.");
	this_player()->run_away();
	return;
    }
    ::init();
}
