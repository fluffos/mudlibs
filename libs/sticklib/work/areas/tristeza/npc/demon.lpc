#include <conditions.h>
#include <npc.h>
#include <city_name.h>

#define SHOW environment()->tell_here
#define TELL enemy[i]->tell_me

void
create_monster()
{
    set_name("ba\'alzamon");
    set_short("Ba\'alzamon, the Forsaken");
    set_id(({ "daemon", "demon", "forsaken" }));
    set_long(
      "This is the ancient daemon Ba\'alzamon, trapped here ages ago\
 by powerful wizards when the city was young. Awesome and terrible\
 to behold, he waits, brooding, hating, awaiting the day of his escape.");
    set_alignment(AL_SATANIC);
    set_gender(G_MALE);
    set_level(80);
    set_ep(5000000);
    set_ac(75);
    set_wc(75);
    set_hp(5000);
    load_chat(8,({
	"Ba\'alzamon says: I will not be tricked a second time!", 
	"Ba\'alzamon says: I was tricked by those feeble wizards!",
	"Ba\'alzamon says: For ages I have waited, but my revenge is drawing nigh.",
	"Ba\'alzamon says: Woe to " CITY_NAME " when I escape!",
	"Ba\'alzamon roars: I will grind my enemies to dust!",
	"Ba\'alzamon laughs!",
	"Ba\'alzamon's eyes gleam red.",
	"Ba\'alzamon growls.",
	"Ba\'alzamon mutters an incantation."
      }));
    load_a_chat(30, ({
	"Ba\'alzamon screams with maniacal laughter!",
	"Ba\'alzamon bellows: Puny mortal! I will grind you to dust!",
	"Ba\'alzamon's eyes flash with fire!",
	"Ba\'alzamon roars: Let my revenge begin!"
      }));
    set_follow(1,0,2,2);
    set(NPC_MOVE_AREA,"rooms");
}


attack() 
{
    int i;
    object *enemy;

    if (!::attack()) return 0;
    if (!query_attack()
      || !present(query_attack(),environment())) return 0;

    enemy = all_inventory(environment());

    if (!random(3))
    {
	SHOW(query_name()+" mutters an incantation.");
	switch(random(2))
	{
	case 0: 
	    for ( i=0; i< sizeof(enemy); i++ )
		if ( living(enemy[i]) && enemy[i]!=this_object())
		    if ( random(10)>5 || enemy[i]->is_npc() )
		    {
			TELL("You are engulfed in flames!");
			SHOW(enemy[i]->query_name()+" is engulfed in flames!",enemy[i]);
			enemy[i]->hit_player(50+random(100));
		    }
	    break;
	case 1:
	    for ( i=0; i< sizeof(enemy); i++ )
		if ( living(enemy[i]) && enemy[i]!=this_object())
		    if ( random(10)>5 || enemy[i]->is_npc() )
		    {
			TELL("Your muscles stiffen! You cannot move!");
			SHOW(enemy[i]->query_name()
			  +" stands rigid, staring in terror!",enemy[i]);
			enemy[i]->set_condition(C_STUNNED, 3 + random(5));
		    }
	    break;
	}
    }
    return 1;
}
