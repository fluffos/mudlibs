/* Dildo - a "thieven Harry" V2.0 */

#include <npc.h>
#include <guild.h>
#include "dirs.h"

#define THIEF_CALL call_out("thieving",30,0)

object dagg,mark;
status busy_thieving;

void
create_monster()
{
    set_level(20);
    set_ep(100000);
    set_hp(6666);
    set_name("dildo");
    set_gender(G_MALE);
    set_id("dildo longnail");
    set_id("longnail");
    set_guild(GN_THIEF);
    set_race("thief");
    set_short("Dildo Longnail the burglar");
    // Was: set_wimpy(). Now what's that supposed to do?
    set_ac(150); /* !master in dodging attacks! */
    set_random_pick(2); /* Collect things */
    set_alignment(AL_VERY_NICE);
    set_money(10 + random(10));
    load_a_chat(20,
      ({"Dildo shouts: HELP!!! Dildo needs help!!!\n",
	"Dildo shouts: I'll tell to admins about you \
and then your guild will be downgraded!",
	"Dildo bursts into tears.\n",
      }));
    if(!dagg) {
	dagg = clone_object(GDIR + "obj/tdagger");
	move_object(dagg,this_object());
	wield(dagg);
    }
}

heart_beat() {
    string msg;

    ::heart_beat();

    if(!random(15)) {
	msg = cap_name + " " + rnd_act() + "\n";
	tell_room(environment(),msg);
	return;
    }
    if(!random(40)) my_random_move();
}

rnd_act() {
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

my_random_move() {
    int n;

    return 1;
    /* Do never leave the guild area... */
    if (object_name(environment()) == GDIR + "rooms/temple")
	command("east");

    n = random(6);
    if(n == 0)
	command("west");
    else if(n == 1)
	command("east");
    else if(n == 2)
	command("south");
    else if(n == 3)
	command("north");
    else if(n == 4)
	command("south");
    else if(n == 5)
	command("north");
}

status query_ctrl() { return 1; }

status catch_ask(object who, string what)
{
    if (what != "poison")
    {
	who->tell_me("Dildo whispers in your ear: Wanna come \
back to my place later?");
    }
    else
    {
	who->tell_me("Dildo whispers to you: Shh!  Don't let \
anyone know, but i have some extra special poison \
vials.  I'll give you a hot deal! 50000 coins!  Can't \
beat that!  Just give me the money and you can have it!\n\
Dildo pauses and adds: Hey you're lookin' pretty good, \
maybe we can go out some time!");
    }
    return 1;
}
void give_object_by(object who, mixed what)
{
    object vial;
    if (!what || !intp(what)) return 0;
    if (what < 50000)
    {
	environment(who)->tell_here("Dildo smirks and says: What \
is this? A tip?");
	return;
    }
    if (what > 50000)
    {
	environment(who)->tell_here("Wow, you gave \
me a little too much.  I'll use the extra for our \
date!");
    }
    if (present("save_pvial",who))
    {
	who->tell_me("Dildo notices you already have a \
special vial and whispers to you:  Another? \
No way!  But thanks for the cash babe!");
	return;
    }
    vial = clone_object(GDIR + "obj/p_vial");
    move_object(vial,who);
    who->tell_me("Dildo reachs into his pants \
and pulls out a vial.\nDildo tells you:  Here ya go. \
It's even a little warm!");
    environment(who)->tell_here("Dildo pulls a vial \
from his pants and says something to " + 
      who->query_name() + ".",who);
    add_money(-(what));
}
