/* This one comes usually from sauna. You should really wash yourself
   after it! */

#include "/sys/configuration.h"
#include "/sys/interactive_info.h"

#include <conditions.h>

#define notify(xx) tell_object(victim,xx)
#define NAME victim->query_name()
#define HIS victim->query_possessive()

/* Prototypes */
void hurt();

object victim;
int incubation, symptom, disease_counter;

string
query_auto_load() {
    string s, tmp;
    int i;
    tmp = object_name(this_object());
    if (sscanf(tmp, "%s#%d", s, i) == 2) tmp = s;
    return
    tmp + ":"+incubation+"#"+symptom+"#"+disease_counter;
}

string query_name() { return "feet rash"; }

string query_nickname() { return "feet rot"; }

void
init_arg(string arg) {
    sscanf(arg,"%d#%d#%d",incubation,symptom,disease_counter);
}

void
create() {
    configure_object(this_object(), OC_HEART_BEAT, 1);

    if(!disease_counter) {
	incubation = 250 + random(250);
	disease_counter = 50 + random(75) + random(150);
	symptom = 20 + random(10);
    }
}

void
init() {
    if(!this_player()) return;
    if(!living(this_player())) return;
    if(environment() != this_player()) return;
    victim = this_player();

    if ((string)victim->query_race() == "elf") {
	destruct(this_object());
	return;
    }

    /* No sick Guest */
    /* No plague epidemic in /room/purgatory 30.3.1992 //Frobozz */
    /* But NPCs can still have it */

    if ((string)victim->query_real_name()=="guest" ||
      (int)victim->query_level() < 4 ||
      (!interactive_info(victim, II_IP_NUMBER) && !victim->query_npc()) ) {
	destruct(this_object());
	return;
    }

    if(environment()->query_coder_level())
	add_action("depukki","db");
}

status id(string str) {
    return str == "feet rash" || str == "rash" || str == "feet_rash" ||
    str == "foot rot" ||
    str == "disease";
}

int drop() { return 1; }
int get() { return 1; }

string short() { return 0; }

varargs int
long(string arg) {
    if (incubation) return 0;

    write("Your feet are covered with a disgusting, suppurating rash.\n");
    return 1;
}

int query_value() { return 0; }
int query_weight() { return 0; }
string query_info() {
    return "Feet rash is a nasty but not usually fatal disease.\n";
}

string
extra_look() {
    if(incubation) return 0;
    return (string)environment()->query_name() +
    "'s feet are covered by disgusting, suppurating rash";
}

void
heart_beat()
{
    int x;

    /* If we are dead, then self-destruct */
    if (!environment() || environment()->query_ghost()) {
	destruct(this_object()); return; }
    if(incubation < 1) { symptom--; disease_counter--; }
    else incubation--;

    if(disease_counter <= 0) {
	tell_object(environment(),"Your feet feel better. The rash is gone.\n");
	if(!environment()->query_npc())
	    environment()->add_exp((int)environment()->query_level()*2);
	destruct(this_object());
	return;
    }

    if(symptom > 0 || incubation > 0) return;

    symptom = 10 + random(10);

    hurt();

    /* Takes 4% of hp all the time, does not kill */

    x = (int)victim->query_hp() / 25;

    if (x > 1) victim -> add_hp(-x);

    return;
}

int
depukki() {
    write("Feet rash debug:\n"+
      "Symptom in " + symptom + " beats,\n" +
      "incubation counter " + incubation + " and\n" +
      disease_counter + " beats remaining.\n");
    return 1;
}

void hurt() {
    if (random(100) < 51) return;

    tell_object(victim, ({
	"Your legs hurt.\n",
	"You feel sick as you notice small bits of flesh dropping off\n"+
	"your inflamed feet.\n",
	"Your feet look sickly green and red and smell rotten.\n",
	"Your swollen, inflamed feet ache.\n",
      })[random(4)]);
}

void
set_incubation(int arg)
{
    incubation = arg;
}

void
remove(){
    destruct(this_object());
}

int query_incubation() { return incubation; }
