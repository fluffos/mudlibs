/***********************************
 * SMOKING PIPE - Coded By MacLeod *
 ***********************************/

#include <treasure.h>
#include <daemons.h>
#include <pipe_defs.h>

#define MY_NAME         capitalize((string)smoker->query_name())
#define HIS             smoker->Possessive()
#define TELLM(x)        smoker->tell_me(x)
#define TELLH(x)        environment(smoker)->tell_here(x,smoker)

object smoker;

int addiction, sweat;

init_arg(arg) {
    if (!arg) {
	if(!find_object(SMOKE_D)) call_other(SMOKE_D, "???");
	SMOKE_D->add_smoker(smoker,0,0);
	return;
    }
    if(!find_object(SMOKE_D)) call_other(SMOKE_D, "???");
    if(sscanf(arg, "%d#%d",addiction,sweat) == 2) {
	if(!SMOKE_D->add_smoker(smoker,addiction,sweat))
	    TELLM("Server error! Please tell MacLeod or some (co-)admin.");
    }
    else TELLM("Init failure! Please tell MacLeod or some (co-)admin.");
}

status drop() { return 1; }
status get() { return 1; }

void create_treasure() {
    set_name("pipe");
    set_short("A pipe");
    set_id(({"pipe","smoking pipe"}));
    set_value(0);
    smoker=this_player();
    init_arg();
}

void init_treasure() {
    add_action("pipe_help", "help");
    add_action("puff_cmd", "puff");
    add_action("puff_cmd", "smoke");
    add_action("light_cmd", "light");
    add_action("empty_cmd", "empty");
    add_action("fill_cmd", "fill");
    add_action("spit_cmd", "spit");
    add_action("throw_cmd", "throw");
    add_action("fixpipe", "fixpipe");
}

pipe_help(string str) {
    if (str != "pipe") return 0;
    TELLM("How to smoke a pipe... Beginners guide to smoking:\n");
    TELLM(
      "First, take out your pipe, and fill it with your favourite tobacco (or what\
 ever you are about to smoke in it). Next you must light the stuff, and start\
 sucking the smoke into your lungs. You can puff it while you smoke, and show\
 your coolness to everyone in the room. When your pipe goes out, or you just\
 want to extinguish it, all you need to do is to empty your pipe, and then\
 it's ready to be used again. In case you want to quit smoking, you can ease\
 the withdrawlas by chewing a gum. It might help you know. When you feel that\
 you are ready to quit... just throw the pipe away.\nIf you come accross any\
 problems with the pipe, try <fixpipe> before you report a bug.\n\nMacLeod.");
    return 1;
}

string query_long() {
    string desc;
    desc = "This is your favourite pipe. Never leave home without it!\n";
    if((status)SMOKE_D->query_smoking(smoker) == YES)
	desc += "You're currently puffing it contentedly.";
    else
	desc += "There is something wrong with it -- it's not lit!!!";
    desc += "\nType \"help pipe\" for some info on smoking.";
    return desc;
}

string extra_look() {
    if((status)SMOKE_D->query_smoking(smoker) == YES)
	return MY_NAME+" really enjoys smoking "+HIS+" pipe.";
    if((int)SMOKE_D->query_addiction(smoker) > 0)
	return MY_NAME + " has nicotine stained teeth.";
    else return 0;
}

fill_cmd(string what) {
    object tobacco;
    string brand;
    int strength, fuel;
    if(!what) return 0;
    brand = 0;
    sscanf(what, "%s with %s", what, brand);
    if(what != "pipe" && what != "smoking pipe") return 0;
    if((status)SMOKE_D->query_filled(smoker) == YES) {
	notify_fail("It is already filled.\n");
	return 0;
    }
    if(!brand) brand = "tobacco";

    tobacco = present(brand, smoker);
    if (!tobacco) {
	notify_fail("You don't have any " + brand +".\n");
	return 0;
    }

    strength = tobacco->query_strength();
    if (!strength) {
	notify_fail("Hmm.. maybe " + brand + " is not to be smoked.\n");
	return 0;
    }

    fuel = tobacco->query_fuel();
    if (!fuel) {
	notify_fail("There's nothing left to smoke in " + brand +".\n");
	return 0;
    }

    if (!smoker->query_can_move()) {
	notify_fail("You are unable to move.\n");
	return 0;
    }

    brand = tobacco->query_brand();
    SMOKE_D->fill_pipe(smoker, strength, DURATION); 
    tobacco->took_some();
    TELLM("Aaah! You can hardly wait!");
    TELLH(MY_NAME+" fills "+HIS+" pipe with \""+brand+"\".");
    return 1;
}

light_cmd(string what) {
    object ob;
    int strength;
    if(what != "pipe" && what != "smoking pipe") return 0;

    if((status)SMOKE_D->query_filled(smoker) == NO) {
	notify_fail("You must fill the pipe first.\n");
	return 0;
    }
    if((status)SMOKE_D->query_smoking(smoker) == YES) {
	notify_fail("It is already lit.\n");
	return 0;
    }
    if((status)SMOKE_D->query_chewing(smoker) == YES) {
	notify_fail("What? While chewing that disgusting slime???\n");
	return 0;
    }
    if (!smoker->query_can_move()) {
	notify_fail("You are unable to move.\n");
	return 0;
    }
    SMOKE_D->light_pipe(smoker);
    TELLM("You light the pipe and start to smoke.");
    TELLH(MY_NAME+" lights "+HIS+" pipe and starts smoking.");
    addiction = (int)SMOKE_D->query_addiction(smoker);
    strength = (int)SMOKE_D->query_strength(smoker);

    if(addiction < (strength - 2) * 1440 + 30) {
	TELLM("You double over in a violent burst of coughing, scattering\
  tobacco all over the place!");
	TELLH(MY_NAME+ " doubles over in a violent burst of coughing,\
  scattering tobacco all over the place.");
	SMOKE_D->add_addiction(smoker,20);
	SMOKE_D->set(smoker,SMOKING,NO);
	SMOKE_D->set(smoker,FILLED,NO);
    }
    else {
	TELLM("You puff vigorously on your pipe and sigh contentedly.");
	TELLH(MY_NAME+" puffs contentedly on "+HIS+" pipe.");
    }
    return 1;
}

puff_cmd() {
    if ((status)SMOKE_D->query_smoking(smoker) == YES) {
	TELLM("You puff your pipe with great enjoyment.");
	TELLH(MY_NAME+" puffs "+HIS+" pipe with great enjoyment.");
    }
    else {
	TELLM("You absentmindedly puff your unlit pipe.");
	TELLH(MY_NAME+" absentmindedly puffs "+HIS+" unlit pipe.");
    }
    return 1;
}

empty_cmd(string what) {
    if(what != "pipe" && what != "smoking pipe") return 0;
    if (!smoker->query_can_move()) {
	notify_fail("You are unable to move.\n");
	return 0;
    }
    TELLM("You empty your pipe.");
    TELLH(MY_NAME+" empties "+HIS+" pipe.");
    SMOKE_D->empty_pipe(smoker);
    return 1;
}

throw_cmd(string what) {
    if (what != "pipe" && what != "smoking pipe") return 0;
    if ((int)SMOKE_D->query_addiction(smoker) > 0) {
	TELLM("You are too attached to the pipe just to throw it away.");
	TELLH(MY_NAME+" hesitates.");
	SMOKE_D->add_addiction(smoker, 5); /* Am I evil? YES I AM!!! */
    }    
    else {   
	TELLM("You throw the pipe away... and quit smoking... permanently.");
	TELLH(MY_NAME+" quits smoking... permanently.");
	SMOKE_D->remove_smoker(smoker);
	destruct(this_object());
    }
    return 1;
}    

spit_cmd(string what) {
    if (what != "gum") return 0;
    if ((status) SMOKE_D->query_chewing(smoker) == YES) {
	TELLM("You spit the disgusting gum out.");
	TELLH(MY_NAME+" spits out "+HIS+" chewing gum.");
	SMOKE_D->stop_chewing(smoker);
    }
    else TELLM("You are not chewing any... Thank heavens.");
    return 1;
}    

status fixpipe() {
    object *ppl;
    ppl = SMOKE_D->query_smokers();
    if (member(ppl, smoker) == -1) {
	SMOKE_D->add_smoker(smoker,addiction,sweat);
	TELLM("Pipe Updated and Added to Server.");
	return 1;
    }
    TELLM("Your pipe is fine, no need to update.");
    return 1;
}

query_auto_load() {
    addiction = (int)SMOKE_D->query_addiction(smoker);
    sweat = (int)SMOKE_D->query_sweat(smoker);
    if(addiction < 0) addiction == 0;
    if(sweat < 0) sweat == 0;
    return PIPE_FILE+":"+addiction+"#"+sweat;
}

string query_stats() {
    string text;
    int i;
    text = "\n" + capitalize(smoker->query_real_name()) + ":";
    text += "\nADDICTION: " + SMOKE_D->query_addiction(smoker);
    text += "\nSTRENGHT : " + SMOKE_D->query_strength(smoker);
    text += "\nFUEL     : " + SMOKE_D->query_fuel(smoker);
    text += "\nFILLED   : " + SMOKE_D->query_filled(smoker);
    text += "\nSMOKING  : " + SMOKE_D->query_smoking(smoker);
    text += "\nCHEWING  : " + SMOKE_D->query_chewing(smoker);
    text += "\nFIT      : " + SMOKE_D->query_fit(smoker);
    text += "\nSWEAT    : " + SMOKE_D->query_sweat(smoker);
    text += "\n";
    return text;
}
