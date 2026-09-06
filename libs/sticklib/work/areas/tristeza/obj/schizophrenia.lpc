/*
 * schizophrenia.c
 *
 * Awful! A very sick disease for the mud. It causes one to:
 *
 *	-	give away items and money
 *	-	insult others and talk sickly
 *	-	drop items
 *	-	rarely go catatonic
 *	-	rarely attack other players
 *	-	hallucinate
 *	-	panic
 *
 */

#include "/sys/configuration.h"
#include "/sys/interactive_info.h"

#include <conditions.h>

#define LOG_SCHIZOPHRENIA

#define notify(xx) tell_object(victim,xx)
#define NAME victim->query_name()
#define HIS victim->query_possessive()

/* Prototypes */
void xsay(string str);
void sick_feeling();
void sick_talk();
void hallucinate();

object victim;
int symptom,counter;

string
query_auto_load() {
    string s, tmp;
    int i;
    tmp = object_name(this_object());
    if (sscanf(tmp, "%s#%d", s, i) == 2) tmp = s;
    return
    tmp + ":"+symptom+"#"+counter;
}

string query_name() { return "schizophrenia"; }

void
init_arg(string arg) {
    sscanf(arg,"%d#%d",symptom,counter);
}

void
create() {
    configure_object(this_object(), OC_HEART_BEAT, 1);

    if(!counter) {
	counter = 300 + random(150) + random(150) + random(150);
	symptom = 10 + random(35);
    }
}

void
init() {
    if(!this_player()) return;
    if(!living(this_player())) return;
    if(environment() != this_player()) return;
    victim = this_player();

    /* No sick Guest */
    /* No plague epidemic in /room/purgatory 30.3.1992 //Frobozz */
    /* But NPCs can still have it */

    if( (string)victim->query_real_name()=="guest" ||
      (int)victim->query_level() < 6 ||
      (!interactive_info(victim, II_IP_NUMBER) && !victim->query_npc()) ) {
	destruct(this_object());
	return;
    }

    if(victim->query_coder_level())
	add_action("depukki","db");
}

status id(string str) {
    return str == "schizophrenia" || str == "mental_disease" ||
    str == "schizo";
}

int drop() { return 1; }
int get() { return 1; }

string short() { return 0; }

varargs int
long(string arg) {
    write("No...\n"); /* A sick long description, isn't it? :-D */
    return 1;
}

int query_value() { return 0; }
int query_weight() { return 0; }
string query_info() {
    return "It's the schizophrenia...\n";
}

void
heart_beat()
{
    /* If we are dead, then self-destruct */
    if(!environment() || victim->query_ghost()) {
	destruct(this_object()); return; }
    symptom--; counter--;

    /* It doesn't last forever. */
    if(counter <= 0) {
	tell_object(victim,
	  "\nWas it a dream? A nightmare? All you know that you are all right,\n"+
	  "once again! The sun shines and your mind is as it used to be.\n");
	tell_object(victim,"You feel more experienced.\n");
	if(!victim->query_npc())
	    victim->add_exp((int)victim->query_level() * 25);
	destruct(this_object());
	return;
    }

    if(symptom > 0) return;

    symptom = 10 + random(35);

    switch(random(4)) {
    case 0: sick_feeling(); break;
    case 1: sick_talk(); break;
    case 2: hallucinate(); break;
    case 3:
	victim->run_away();
	if(!random(6)) {
	    notify("Everything goes dark.\n");
	    victim->set_condition(C_UNCONSCIOUS,5+random(5));
	}
	break;
    default: break;
    }

    return;
}

int
depukki() {
    write("Schizophrenia debug:\n"+
      "Symptom in " + symptom + " beats,\n" +
      counter + " beats of the madness remaining.\n");
    return 1;
}

/* The only way to do this properly... *SIGH* */
void
xsay(string str) {
    object *inv;
    int i;

    inv = all_inventory(environment(victim));
    for(i=0;i<sizeof(inv);i++)
	if(living(inv[i]) && inv[i] != victim)
	    tell_object(inv[i],str);
}

/* Symptoms */
/* The player doesn't notice most of them. */

void sick_feeling() {
    switch(random(4)) {
    case 0:
	xsay(NAME + " grins very evilly.\n");
	break;
    case 1:
	xsay(NAME + " sucks " + HIS + " thumb.\n");
	break;
    case 2:
	xsay(NAME + " bites " + HIS +
	  " lip so hard that it is wounded.\n");
	break;
    case 3:
	xsay(NAME + " starts to laugh madly.\n");
	break;
    default: break;
    }
}

/* Simulate typos and such also. */
/* Just sick, not offensive... */
string sick_message() {
    string msg;

    msg = ({
      "says: you are dead","says: i kill you!",
      "yells: I died!","shouts: this isn't fair!!!",
      "yells: don't take that!!! it's mine!!!",
      "says: I kill the g8iants! they're mine",
      "asks: can you lend me 10k?","says: idiot!",
      "says: I'll start killing all the newbies. it's fun",
      "asks: have you been in the moon?","yells: haha! I killed him!",
      "asks: do youy know this quest?","says: shit",
      "yells: I need weapons and armour  now!!!",
      "says: my head hurts","says: i found it finally...",
      "yells: hooray! I killed the dragon!",
      "says: they're trying to kill me",
      "says: I got 900k gold, how much u have?\n",
      "yells: Lords try to kill me!","says: i will lead the party",
      "says: I'm< the best player","says: come with me to bed",
      "drops 4367 coins."
    })[random(24)] + "\n";

    return msg;
}

void sick_talk() {
    xsay(NAME + " " + sick_message());
}

string random_thing() {
    return ({"dragon","orc","hobgoblin","a bag","a torch","a bottle of beer",
      "a firebreather","Lord's Crown","red dragon","an octopus",
      "sea hag","gray ooze","troll","black troll","beggar",
      "Harry the affectionate","skeleton","zombie","vampire lord",
      "Skert the God of Thieves","Dildo Longnail the burglar",
      "Shopkeeper","Guard","Guard Captain","Guard General",
      "Game Driver","ghost","City Dump","Tappaa the swordsman",
      "Ancient Gold Dragon","Armageddon","Someone"
    })[random(32)];
}

void
hallucinate() {
    string msg,thing;
    int i;
    object *us;

    switch(random(4)) {
    case 0:
	notify(({"You are sent somewhere!\n",
	    "You drop 10000 coins.\n",
	    "You remove your wielded weapon.\nOk.\n",
	    "You drop your worn armour.\nOk.\n"
	  })[random(4)]);
	break;
    case 1:
	notify(capitalize(random_thing()) + 
	  ({" is now hunting you.\n",
	    " arrives.\n"," arrives in a puff of smoke.\n",
	    " dies.\n"," massacres you into small fragments.\n",
	    " hits you very hard.\n"," disappears in a puff of smoke.\n",
	    " leaves north.\n" })[random(8)]);
	break;
    case 2:
	notify(capitalize(random_thing()) + " " + sick_message());
	break;

	/* The others keep saying those sick things... */
    case 3:
	us = users();
	for(i=0;i<sizeof(us);i++)
	    if(!us[i]->query_invis() &&
	      !us[i]->query_coder_level() &&
	      us[i] != victim &&
	      !random(3)) {
		notify(capitalize((string)us[i]->query_real_name()) + " " +
		  sick_message());
		break;
	    }
	break;

    default: break;
    }
}
