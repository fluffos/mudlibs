inherit "/lib/shop";
#include "/areas/tristeza/DEFS.h"

#define ROOM_NO_INHERIT
#include <room.h>

#include <gender.h>
#include <properties.h>

#include "dirs.h"

#define VALUE_HIDE  2000
#define VALUE_MAX   1000

object shopkeeper;

int shop_open() {
    if(!present("shopkeeper",this_object())) {
	notify_fail("The shopkeeper is not here.\n");
	return 0;
    }
    return 1;
}

void reset_shop() {

    if(!shopkeeper) {
	shopkeeper = clone_object(GDIR+"npc/dildo");
	shopkeeper->set_name("Dildo");
	shopkeeper->set_gender(G_MALE);
	shopkeeper->set_race("bobbit");
	shopkeeper->set_short("Dildo the shopkeeper");
	shopkeeper->set_id(({
	    "shopkeeper", "dildo", "thief_shopkeeper", "longnail", "dildo longnail",
	    "guild_guard" }));
	shopkeeper->set_long(
	  "Dildo Longnail used to be a thief, but he was so successful that "+
	  "he built this shop room and storage.");
	shopkeeper->set_dead_ob(this_object());
	move_object(shopkeeper,this_object());
	call_out("do_funny", 10 + random(10));
    }
}

void create_shop() {
    set_store(GDIR + "rooms/tstore");
    set_short("Fence (Thieves' Guild Shop)");
    set_long(
      "You are in the Fence of Thieves' Guild. On the wall is a plaque "+
      "which contains some writing. Perhaps you should read it?");
    add_exit("north", GDIR + "rooms/guild");
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(ROOM_GUILD);
    reset_shop();
}

/* Make shopkeeper return if away, alive and not in a fight */
void
init_shop()
{
    if (shopkeeper &&
      !present(shopkeeper, this_object()) &&
      !shopkeeper->query_dead() &&
      !shopkeeper->query_attack() &&
      !shopkeeper->query_alt_attack())
	shopkeeper->move_player("back to shop#" +
	  GDIR2 + "rooms/tshop");
}

/* Reward killing of shopkeeper: he returns with more money. */
int
monster_died(mixed hilipati)
{
    int m;

    m = (int)call_other(GDIR + "rooms/tstore", "query_money");

    call_other(GDIR + "rooms/tstore", "set_money", m + 10000);

    return 0;
}

string
rnd_act()
{
    int i;
    string his;

    his = "his";
    i = random(50);

    /* Do it a bit faster */
    if(i<10) {
	if(i==0) return "falls and hurts "+his+" lip.";
	if(i==1) return "wets "+his+" pants.";
	if(i==2) return "bursts into tears.";
	if(i==3) return "tortures a squirrel.";
	if(i==4) return "searches "+his+" pockets.";
	if(i==5) return "watches some TV.";
	if(i==6) return "eats some potato salad.";
	if(i==7) return "whistles a small tune.";
	if(i==8) return "chews "+his+" toenails.";
	if(i==9) return "says: 'I am tired of this game.'";
    }
    if(i<20) {
	if(i==10) return "tells an indecent joke.";
	if(i==11) return "is singing 'hey-ho'.";
	if(i==12) return "picks "+his+" nose.";
	if(i==13) return "examines a tourist map of this area.";
	if(i==14) return "sinks into catatonia.";
	if(i==15) return "pukes noisily.";
	if(i==16) return "hides behind you.";
	if(i==17) return "dances a small round game.";
	if(i==18) return "is still here.";
	if(i==19) return "scratches "+his+" head.";
    }
    if(i<30) {
	if(i==20) return "blows "+his+" nose.";
	if(i==21) return "has lost "+his+" handkerchief.";
	if(i==22) return "falls asleep.";
	if(i==23) return "sharpens "+his+" teeth.";
	if(i==24) return "waves "+his+" tail happily.";
	if(i==25) return "combs "+his+" face.";
	if(i==26) return "is searching for a toilet.";
	if(i==27) return "whines: 'I got to get into a toilet!'";
	if(i==28) return "swears loudly.";
	if(i==29) return "examines the source code and says: 'How boring!'";
    }
    if(i<40) {
	if(i==30) return "reads a book: 'Orc girl's newbie years'.";
	if(i==31) return "lends some toilet paper from you.";
	if(i==32) return "sees a dream about fillet steak.";
	if(i==33) return "counts "+his+" money.";
	if(i==34) return "has lost "+his+" wallet.";
	if(i==35) return "faints.";
	if(i==36) return "makes some coffee.";
	if(i==37) return "is searching for the creator of this area.";
	if(i==38) return "plays some pocket billiard.";
	if(i==39) return "eats some pancake.";
    }
    if(i==40) return "is making pancakes.";
    if(i==41) return "eats some nettles.";
    if(i==42) return "waves "+his+" hand happily.";
    if(i==43) return "wants to go home!";
    if(i==44) return "sees a mosquito and is scared to death.";
    if(i==45) return "lends 10 gp from you.";
    if(i==46) return "accidentally crashes to a wall.";
    if(i==47) return "sneezes.";
    if(i==48) return "coughes.";
    if(i==49) return "sniffs.";
    if(i==50) return "runs in circles, screams and shouts.";

    return "does something peculiar.";
}

/* Check our lockpick storage here too */
void
do_funny()
{
    if (shopkeeper && present(shopkeeper, this_object())) {
	/*
	       tell_room(this_object(), "Dildo " + rnd_act() + "\n");
	*/
	call_out("do_funny", 100 + random(500));

	call_other(GDIR + "rooms/tstore", "lockpick_check");
	call_other(GDIR + "rooms/tstore", "vial_check");
    }
}
