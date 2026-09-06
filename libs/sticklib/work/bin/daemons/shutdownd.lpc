/*
 * shutdownd.c - The shutdown daemon.
 *
 * Needs a lot of fixing..
 */

#include <npc.h>

#include <generic_rooms.h>

#define ADD_MONEY_FOR_SHOP 25000

status added;      // Is the money already added
int shout_counter,
orig_seconds;

Shout(str) {
    object *ob;
    int i;
    ob = users();
    for(i=sizeof(ob)-1;i>=0;i--)
	tell_object(ob[i],sprintf("%-=*s",77,str));
}

void
create_monster()
{
    set_name("armageddon");
    set_level(40);
    set_wc(50);
    set_ac(50);
    set_short("Armageddon the game crasher");
    set_long("He looks like he enjoys to stop the game.");
    set_id(({ "shut", "Armageddon" }));
    mmsgin = "arrives in a puff of smoke";
    call_out("move_to_church",1);
    added=0;
}

void move_to_church() { move_player("X", GENERIC_ROOM_CHURCH); }

shut(seconds)
{
    int i;

    if (!intp(seconds)) {
	write("Bad argument\n");
	return;
    }
    if (seconds == 0) {
	write("No time given\n");
	return;
    }
    set_long("He is firmly concentrated on counting.\n");
    i = remove_call_out("cont_shutting");
    if(find_call_out("cont_shouting")!=-1)
	remove_call_out("cont_shouting");
    if (i > 0) {
	i = (i + 10) * 4;
	if (i < seconds) {
	    write("There was already a shutdown in process, " + i +
	      " seconds.\n");
	    seconds = i;
	}
    }

    if(!added) {
	(GENERIC_ROOM_SHOP_STORE)->set_money(
	  ((GENERIC_ROOM_SHOP_STORE)->query_money())
	  +ADD_MONEY_FOR_SHOP);
	added=1;
    }
    log_file("SHUT",this_player()->query_real_name()+" at "+ctime(time())+"\n");

    call_out("cont_shutting", 0, seconds * 60);
    call_out("cont_shouting",2);
    orig_seconds=seconds*60;
    shout_counter=0;
}

status query_shutdown_in_process() {
    return (find_call_out("cont_shutting")) > 0;
}

int transport_offer;

cont_shutting(seconds) {
    string delay;
    int new_delay;

    if (seconds <= 0) {
	Shout(cap_name + " shouts: I will reboot now.\n");
	Shout("Game Driver shouts: Yes! Do it! Now!\n");
	Shout("With a deafening boom, reality finally shatters under the pressure. You spin through the holocaust of the crumbling world, until there is nothing left but a silent void.\n");
	/* First force link-deaders to sell their stuff and quit //Rincewind */
	catch(call_other(GENERIC_ROOM_PURGATORY, "bail_out"));
	shutdown();
	return;
    }
    /* Transport offer came at 240, too late... */
    if (seconds <= 480 && !transport_offer) {
	Shout(cap_name + " shouts: Tell me if you want a trip to the shop!\n");
	transport_offer = 1;
    }
    new_delay = seconds / 2; /* Was seconds * 3 / 4 - 10; */
    call_out("cont_shutting", seconds - new_delay, new_delay);
    delay = "";
    if (seconds > 59) {
	delay = seconds / 60 + " minutes ";
	seconds = seconds % 60;
    }
    if (seconds != 0)
	delay += seconds + " seconds";
    Shout(cap_name + " shouts: Game reboot in " + delay + ".\n");
}

cont_shouting() { 
    /* New messages by Dolandar */
    Shout(({
	"You hear dogs howling in the distance.\n",
	"The horizon starts to glow with a fiery red glow.\n",
	"The red glow spreads higher into the sky. The birds have stopped singing and an unnatural silence has spread over the land.\n",
	"The magnificent red glare covers the whole sky, making everything appear somehow unreal in the bright red light.\n",
	"The sky flares in all shades of red and yellow as if the flames of the sun were burning the world. You feel the temperature rising.\n",
	"There is a sudden drop in temperature and you feel an unnatural chill descending upon you. Frost forms on pools and a wind starts to blow.\n",
	"The wind increases in force as the temperature continues to lower. The sky still flares unnaturally, but the light is vanishing, as if sucked by the ground itself.\n", 
	"A low rumble, like distant thunder shakes your bones. Unlike thunder it does not end, however, but continues to grow in volume.\n",
	"You see the scenery around you stretch, as if torn by some great force. The low rumble still continues.\n",
	"With a terrifying scream, a large rift opens in the air beside you. It seems to suck all the remaining light, and as you turn to escape you see the whole world being stretched into unnatural forms.\n",
	"The rumbling noise gradually increases to the point where you can't help shielding your ears against the unearthly screaming. Raw energy fluctuates around you, tearing matter and destroying reality.\n",
      })[shout_counter++]);
    if(shout_counter<=10)
	call_out("cont_shouting",orig_seconds/12);
}

catch_tell(str) {
    string who, what;
    object ob;

    if(!transport_offer) return;
    if(sscanf(str,"%s tells you: %s", who, what) != 2) return;
    this_player()->move_player("X", GENERIC_ROOM_SHOP);
}

/* Taken from new death by Graah */

/* Armageddon cannot die. So redefine hit_player(). */
int
hit_player(int dam, int dtype, int hc, object enemy)
{
    return ::hit_player(0, dtype, hc, enemy);
}
