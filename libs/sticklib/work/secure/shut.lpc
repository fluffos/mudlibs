//
// This is a better shut down daemon, that will take care of shutdown.
//
// call /secure/shut shut <number of minutes>
//
// Don't clone this object.
//
// Rewrite: 23-Jul-96 Graah
//
// Added abort_shutdown()  21-Nov-98 Kieve
//

#include <npc.h>
#include <coder_levels.h>
#include <areas.h>
#include <generic_rooms.h>

// In case of Armageddon add money for shop 20.5.1992 //Frobozz
#define ADD_MONEY_FOR_SHOP 30000
#define	STORE	GENERIC_ROOM_SHOP_STORE
#define	STORE1	(AREA_TRISTEZA+"shops/weaponer_store")
#define	STORE2	(AREA_TRISTEZA+"shops/armourer_store")

status added; // Is the money added to STORE yet?
int orig_seconds;  // Amount of seconds to shutdown
int seconds; // How much seconds to shutdown
int shout_counter, yell;

void
Shout(string str)
{
    object *ob;
    int i;

    ob = users();
    for (i = sizeof(ob)-1; i >= 0; i--)
	if(ob[i]) ob[i] -> tell_me(str);
}

void
create()
{
    ::reset();
    set_name("armageddon");
    set_level(40);
    set_wc(50);
    set_ac(50);
    set_short("Armageddon the game crasher");
    set_long("He looks like he enjoys to stop the game.");
    set_id("shut");
    set_keep_hb(-2000000000);
    set_ep(1);
    added = 0;
    seconds = -1;
    call_out("move_to_church",1);
}

move_to_church() { move_player("X", GENERIC_ROOM_CHURCH); }

string
desc_time(int s)
{
    string d;

    d = "";

    if (s > 59)
    {
	d = s / 60 + " minutes ";
	s = s % 60;
    }

    if (s != 0)
	d += s + " seconds";

    if (d == "") d = "infinite time";

    return d;
}

void abort_shutdown()
{
    // This assumes it was just compiled to start the count down,
    // so we'll destruct ourselves to remove it.

    if (this_interactive() &&
      (int)this_interactive()->query_coder_level() < LVL_CODER)
    {
	if (this_interactive())
	    this_interactive()->tell_me(
	      "Not allowed for coders under level 75.");
	return;
    }

    Shout(cap_name+" shouts: I will come back for you all - Later!");
    destruct(this_object());
    return;
}

void
shut(int m)
{
    int i;

    // Hmm. Let's not prevent this if it's master object calling us.
    // -+ Doomdark +-

    if (previous_object() && (
	(i = strstr(object_name(previous_object()), "secure/master")) == 0
	|| i == 1))
    {
	//shutdown() needs this_player()
	disable_commands();
	enable_commands();
    }
    else
    if (this_interactive() &&
      (int)this_interactive()->query_coder_level() < LVL_CODER)
    {
	if (this_interactive())
	    this_interactive()->tell_me(
	      "Not allowed for coders under level 75.");
	return;
    }

    if (!intp(m))
    {
	write("Bad argument\n");
	return;
    }

    if (m < 1)
    {
	write("No time given\n");
	return;
    }

    set_long("He is firmly concentrated on counting.");

    if (seconds > 0)
    {
	write("There is already a shutdown in process, " +
	  desc_time(seconds) + ".\n");
	if (m * 60 < seconds)
	    return;
	else
	    write("Ok, getting the new (longer) time...\n");
    }

    while (remove_call_out("cont_shouting") >= 0);

    if (!added)
    {
	STORE->set_money(STORE->query_money()+ADD_MONEY_FOR_SHOP);
	STORE1->set_money(STORE1->query_money()+ADD_MONEY_FOR_SHOP);
	STORE2->set_money(STORE2->query_money()+ADD_MONEY_FOR_SHOP);
	Shout("Armageddon shouts: Shops just got their tax refund!\n");
	added = 1;
    }

    if (this_interactive())
	log_file("SHUT",
	  this_interactive()->query_real_name()+" at "+ctime(time())+"\n");

    orig_seconds = seconds = m * 60;
    shout_counter = 0;

    call_out("cont_shouting", 2);
}

status
query_shutdown_in_process()
{
    return (seconds > 0);
}

int
query_seconds()
{
    return seconds;
}

int transport_offer;

void
heart_beat()
{
    object *u;
    int new_delay, i;

    ::heart_beat();

    // seconds -1 or lower: no shutdown in process.
    if (seconds < 0) return;

    seconds -= 2;

    if (seconds <= 0)
    {
	Shout(cap_name + " shouts: I will reboot now.\n\
Game Driver shouts: Yes! Do it! Now!\n\
With a deafening boom, reality finally shatters under the pressure. \
You spin through the holocaust of the crumbling world, until there is \
nothing left but a silent void.");

	// First force link-deaders to sell their stuff and quit //Rincewind
	catch(call_other(GENERIC_ROOM_PURGATORY, "bail_out"));

	// And then let's force save on others.
	u = users();
	i = 0;
	while (i < sizeof(u)) {
	    if (interactive(u[i])) u[i]->save_me(0);
	    i++;
	}

	shutdown();
	return;
    }

    // Transport offer came at 240, too late...
    if (seconds <= 480 && !transport_offer)
    {
	Shout(cap_name + " shouts: Tell me if you want a trip to the shop!");
	transport_offer = 1;
    }

    set_long("He is firmly concentrated on counting. \
He says: Shutdown in " + desc_time(seconds) + ".");

    if (--yell <= 0)
    {
	Shout(sprintf("%s shouts: Game reboot in %s.",
	    cap_name, desc_time(seconds)));
	if ((yell = (seconds / 10)) < 2) yell = 2;
    }
}

void
cont_shouting()
{ 
    // New messages by Dolandar
    Shout(({
	"You hear dogs howling in the distance.",
	"The horizon starts to glow with a fiery red glow.",
	"The red glow spreads higher into the sky. The birds have stopped\
 singing and an unnatural silence has spread over the land.",
	"The magnificent red glare covers the whole sky, making everything\
 appear somehow unreal in the bright red light.",
	"The sky flares in all shades of red and yellow as if the flames\
 of the sun were burning the world. You feel the temperature rising.",
	"There is a sudden drop in temperature and you feel an unnatural chill\
 descending upon you. Frost forms on pools and a wind starts to blow.",
	"The wind increases in force as the temperature continues to lower.\
 The sky still flares unnaturally, but the light is vanishing, as if sucked\
 by the ground itself.", 
	"A low rumble, like distant thunder shakes your bones. Unlike thunder\
 it does not end, however, but continues to grow in volume.",
	"You see the scenery around you stretch, as if torn by some great force.\
 The low rumble still continues.",
	"With a terrifying scream, a large rift opens in the air beside you.\
 It seems to suck all the remaining light, and as you turn to escape you\
 see the whole world being stretched into unnatural forms.",
	"The rumbling noise gradually increases to the point where you can't\
 help shielding your ears against the unearthly screaming. Raw energy\
 fluctuates around you, tearing matter and destroying reality.",
      })[shout_counter++]);
    if (shout_counter<=10)
	call_out("cont_shouting", orig_seconds / 12);
}

catch_tell(str)
{
    string who, what;
    object ob;

    if(!transport_offer) return;
    if(sscanf(str,"%s tells you: %s", who, what) != 2) return;
    this_player()->move_player("X", AREA_TRISTEZA+"shops/shop");
}

/* Taken from new death by Graah */
/* Armageddon cannot die. So redefine hit_player(). */
int
hit_player(int dam, int dtype, int hc, object enemy)
{
    return ::hit_player(0, dtype, hc, enemy);
}

int
death(int mode, object who)
{
    return 0;
}
