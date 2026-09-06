/*
 * PRIEST TRANCE OBJECT
 * 
 * Converts HP -> SP
 */

// hmm... what's the point in this? there's heart_beat and call_outs
// running simultaneously every round. (To be more precise: there's
// two call outs every round)
// Chopin

#include "../priest.h"
#include <race.h>

object master;
int amount;
int master_sp_rate;

#define TME(x) master->tell_me(x)
#define TH(x) environment(master)->tell_here(x,0,0,master,master,0,0)

get() { return 0; }
drop() { return 1; }

id(str) { return str=="tranz_ob"; }

init() 
{ 
    add_action("filter","",1); 
    add_action("stop_medit","cancel");
}

heart_beat()
{
    if(!interactive(master)) {
	destruct(this_object());
	return 1;
    }
    if(master->query_attack()) {
	remove_call_out("meditate");
	TME("You have been attacked! Your meditating \
interrupts violently! A terrible pain hits through your body!");

	TH(":%<me.capname>% screams in pain as %<me.possessive>% \
meditating is interrupted!");
	master->add_hp(-amount/4);
	destruct(this_object());
	return 1;
    }
}

filter(str)
{
    string cmd;

    cmd = query_verb();
    switch(cmd) {
    case "cancel": case "who":
    case "score": case "session":
    case "help" : case "advice":
    case "cash":
	return 0;

    case "quit":
	destruct(this_object());
	return 0;

    default :
	TME("You can't do that while meditating.");
	return 1;
    }
}


stop_medit()
{
    remove_call_out("meditate");
    TME("You struggle to regain the total control of \
your mind. A terrible pain hits your whole body.");
    TH(":%<me.capname>% opens %<me.possessive>% eyes wide open, \
struggling to regain the control of %<me.possessive>% mind");
    /*
	Unsuccessful meditaing results in minor hp loss. //Hawthorn
    */    
    master->add_hp(-amount/4);
    destruct(this_object());
    return 1;
}

start_medit(arg)
{
    amount = arg;
    master = environment(this_object());
    // should be RACE_SP_HEAL_RATE??
    master_sp_rate = master->query_race_stat(RACE_SP_RATE);
    set_heart_beat(1);
    if(master && living(master)) {
	TME("You relax, forcing your physical energy to \
flow into your mind...");
	call_out("meditate",1,arg);
    }
    return 1;
}

meditate(arg)
{
    object here;
    int t;

    if(!random(10)) {
	TME("You feel great pain, as the converted energy \
flows in your body.");
	TH(":%<me.capname>% seems to be in great pain, yet somehow relaxed.");
    }
    //    arg -= 10; // still too slow?
    if(master->query_coder_level()) TME("arg: " + arg);
#ifdef USE_MASTER_SP_RATE
    arg -= master_sp_rate;
#else
    arg -= 100;
#endif /* USE_MASTER_SP_RATE */
    if(arg<=0) {
	TME("You scream in agony as a pulse of pure energy \
invades your mind, your body withering.");
	TH(":%<me.capname>% screams horribly, %<me.possessive>% body \
quivering with pain.");
	/*
	    No pain no gain.. restoration of sp and losing of hp only if the
	    meditation was successful.. //Hawthorn
	*/
	here = environment(master);
	if(here->query_priest_moonwell()){
	    t = here->query_sp();
	    if(t<amount)
		amount -= t;
	    else {
		t = amount;
		amount = 0;
	    }
	    master->add_sp(t);
	    here->add_sp(-t);
	    write_file(PRIEST_DIR "log/moonwell",sprintf("%s: %s -%d sps.\n",
		ctime(time()), capitalize(master->query_real_name()), t));
	}
	if(amount) {
	    master->add_hp(-amount);
	    master->add_sp(amount/2 + random(amount/3+1));
	}

	TME("Your meditation was successful.");
	destruct(this_object());
	return 1;
    }
    call_out("meditate",1,arg);
    return 1;
}

