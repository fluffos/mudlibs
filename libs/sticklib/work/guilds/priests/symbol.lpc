/*
 * New priest symbol, written by Chopin.
 *   4/2/97 -
 *   4/26/97 I changed this quite a bit. Compare it with the old symbol to 
 *        find out, what's new *grin*
 *   5/26/97 Another, hopefully final, version of priest symbol.
 *   6/9/97 Added faith.
 *   6/20/97 Opened the new guild.
 *   6/27/97 Made a new skill conversion, because high players got way
 *        too bad skills in the first conversion. There wasn't much
 *        difference between high level players and newbies.
 *   7/8/97 Added pexrate logging.
 *   10/8/97 Added inform_debugger function. Should reduce the amount of
 *        call_others (there had been zillions of calls to 
 *        this_player()->query_coder_level() before this)
 *   5/10/98 Cremate satiation is back! If you cremate too much, you get a 
 *        headache.
 */

#include <treasure.h>
#include <guild.h>
#include <tell_me.h>
#include <room_defs.h>
#include <player_defs.h>
#include <invis_levels.h>
#include <conditions.h>
#include <weapon_defs.h>

#include "priest.h"
#include "skills.h"

#define CURRENT_SYMBOL_VERSION 2 // second version, the first was 0
// DO NOT CHANGE, unless you're doing a new skill conversion or something
// like that.

object owner;
string owner_name, cap_name;
status banned;
int guild_rank;
object pretitle_obj;
object *healed;
int *healed_time;
status casting;
status mixing;
int light_level; // 'lux' and 'dark' use this
int sat_amount, sat_time;
status is_coder;
int metamorphosis_penalty;
status moved;

// Fucking XP-cheaters- Starks
status query_moved() {
    if(moved) {
	moved = 0;
	return 1;
    }
    return 0;
}

int order; // -1, 0 or 1
int faith; // -10..10
int version; // 0 = first conversion, 2 = second conversion
int *pexes; // skills

// for pexrate:
int last_save, last_coef;

object debugger, debuggee;


/**** SET & QUERY FUNS ****/

int query_light_level() { return light_level; }
int query_pex(int i) { return pexes[i]; }
int* query_pexes() { return pexes; }
status query_banned() { return banned; }
status query_casting() { return casting; }
status query_mixing() { return mixing; }
object query_pretitle_object(object ob) { return pretitle_obj; }
int query_rank() { return guild_rank; }
int query_order() { return order; }
string query_order_string() { return ORDERS[order+1]; }
object query_debugger() {return debugger; }
object query_debuggee() { return debuggee; }
int query_metam_penalty() { return metamorphosis_penalty; }

void set_light_level(int l) { set_light(l-light_level); light_level = l; }
void set_pex(int index, int pex) { pexes[index] = pex; }
void set_banned(int x) { banned = x; }
void set_casting(int x) { casting = x; }

void set_mixing(int x) { mixing = x; }
void set_pretitle_object(object ob) { pretitle_obj = ob; }
void set_order(int x) { order = x; }
void set_rank(int x) { guild_rank = x; }
void set_pexes(int *t) { pexes = ({}) + t; }
void set_debugger(object pl) {debugger = pl; }
void set_debuggee(object pl) { debuggee = pl; }
void set_metam_penalty(int x) { metamorphosis_penalty = x; }

void inc_pex(int i, int amount) { pexes[i] += amount; } 

/**** PROTOTYPES ****/

string query_guild_save();


/*** DO_ERROR ***/

// not very good error function, but...
void do_error(string fun, string err) {
    printf("Error in /guilds/priests/symbol:%s:\n%s\n", fun, err);
}


/*** FAITH ***/

void set_faith(int x) { faith = x; }

int query_faith() {
    int t;

    t = DELAY_D->query_delay(owner, DELAY_TYPE_FAITH_DECR);
    if(!t)
	DELAY_D->add_delay(owner, DELAY_TYPE_FAITH_DECR, FAITH_DECR_DELAY);
    else if(t>0) {
	faith -= t;
	if(faith<-10) faith = -10;
    }
    return faith;
}

void inc_faith(int x) {
    faith += x;
    if(faith>10) faith = 10;
    else if(faith<-10) faith = -10;
}


/*** CREMATE SATIATION ***/

void update_sat() {
    sat_amount -= 3 * (time() - sat_time);
    if(sat_amount < 0) sat_amount = 0;
    sat_time = time();
}

int query_satiation() {
    update_sat();
    return sat_amount;
}

void add_satiation(int amount) {
    update_sat();
    sat_amount += amount;
}


/*** Utility funcs: ***/

int query_coef() {
    int i, t;

    if(!(i = sizeof(pexes))) return 0;
    while(--i>=0) t += pexes[i];
    return t;
}


/**** HOOKS etc. ****/

void guild_mem_quit(object who) {
    catch(SHIELD_D->remove_pl(owner));
    catch(SLAVE_D->remove_all_slaves(owner));
    catch(DELAY_D->freeze_delays(owner));
    if(!is_coder) {
	write_file(PRIEST_DIR "log/SKILL_BACKUP", sprintf("%s %s: %s\n",
	    ctime(time()), cap_name, query_guild_save()));
    }
}

void guild_mem_ld(object who) {
    mixing = 0;
    casting = 0;
    DELAY_D->freeze_delays(owner);
    SLAVE_D->go_ld(owner);
    if(owner->query_invis() < IL_TOTALLY_INVISIBLE)
	INFORMER->inform(cap_name+" goes linkdead.");
}

void guild_mem_recover_from_ld(object who) {
    SLAVE_D->recover_from_ld(owner);
    DELAY_D->unfreeze_delays(owner);
    if(owner->query_invis() < IL_TOTALLY_INVISIBLE)
	INFORMER->inform(cap_name+" recovers from linkdeath.");
}

status prevent_attack() {
    return mixing || casting; // is this too cruel? mixing can last
    // for 6 seconds, and even Garathan can kill you in that time
}

void guild_mem_mort(object who, object hitter) {
    if(!environment(owner)->query(ROOM_ISOLATED))
	INFORMER->inform(sprintf("%s's faithful follower %s is mortally \
wounded!", ORDERS[order+1], cap_name));
}

void guild_mem_died(object who, object killer) {
    if(!environment(owner)->query(ROOM_ISOLATED))
	INFORMER->inform(sprintf("%s was killed by %s.",
	    cap_name,capitalize(killer->query_name())));
    // no, not telling killer's real name
    SLAVE_D->remove_all_slaves(owner);
    casting = mixing = 0;
}


/**** INITIALIZATION FUNS ****/

status
restore_skills(string str) {
    int index, i;
    string ps;

    pexes = allocate(N_SKILLS);
    if(!str || !stringp(str)) {
	order = faith = 0;
	version = CURRENT_SYMBOL_VERSION;
	return 1;
    }
    if(sscanf(str, "%d&%d&%d&%s", order, faith, version, ps)!=4) {
	order = faith = 0;
	version = CURRENT_SYMBOL_VERSION;
	return 0;
    }
    i = 0;
    while(sizeof(ps) && i<N_SKILLS) {
	sscanf(ps,"%d#%s", pexes[i++], ps);
    }
    return 1;
}


string
query_guild_save()
{
    string temp;
    mixed err;
    int i, t, c;

    if(!is_coder) {
	if(err = catch(BOOKKEEPER->update_me(owner)))
	    do_error("query_guild_save()", err);

	if((c = query_coef() - last_coef)>0) {
	    last_coef = query_coef();
	    t = time() - last_save;
	    last_save = time();
	    write_file(PEXLOG, sprintf("%s %d %d\n", cap_name, c, t));
	}
    }

    temp = sprintf("%d&%d&%d&", order, faith, version);

    for(i=0;i<sizeof(pexes);i++)
	temp = sprintf("%s%d#",temp,pexes[i]);

    return temp;
}


void
init_my_guild_info() {
    SPELL_LOADER->load_spells();
    EXCOM_D->am_i_excom(owner_name);
    banned = EXCOM_D->am_i_banned(owner_name);
    guild_rank = OFFICER_D->my_rank(owner_name);
    SKILL_SAVER->save_my_skills(owner, this_object());
    DELAY_D->unfreeze_delays(owner);
    if(file_size(NEWSFILE) > 0)
	owner->more(explode(read_file(NEWSFILE), "\n"));
    if(version != CURRENT_SYMBOL_VERSION) {
	// I knew I would have to do this... it just sucks to have
	// several kinds of skills in the game.
	SKILL_CONVERTER->convert_skills(owner, version, pexes, order);
	version = CURRENT_SYMBOL_VERSION;
    }
    if(owner->query_invis() < IL_TOTALLY_INVISIBLE)
	VOTING_D->check_voting();
}


void
initialize_guild(string arg) {
    if(environment() && interactive(environment())) {
	owner = environment();
	owner_name = owner->query_real_name();
	cap_name = capitalize(owner_name);
	is_coder = (owner->query_coder_level()!=0) ||
	(owner->query_testplayer()!=0);
	if(!restore_skills(arg))
	    owner->tell_me("Error in restoring your skills! Report this \
to a guild coder.");
	last_save = time();
	last_coef = query_coef();

	// I think these should not be needed
	owner->set_guild(GN_PRIEST);
	owner->set_guild_object(this_object());
	owner->set_guild_object_name(PRIEST_SYMBOL);
	owner->set_guild_save(query_guild_save());

	owner->set_guild_hook(([
	    G_HOOK_QUIT:#'guild_mem_quit,
	    G_HOOK_DEATH:#'guild_mem_died,
	    G_HOOK_GO_LD:#'guild_mem_ld,
	    G_HOOK_RECOVER_FROM_LD:#'guild_mem_recover_from_ld,
	    //          G_HOOK_GO_MORT:#'guild_mem_mort,
	    G_HOOK_PREVENT_ATTACK:#'prevent_attack,
	    G_HOOK_WIELD_WEAPON:symbol_function("wield_weapon", ATTACK_D),
	    G_HOOK_REMOVE_WEAPON:symbol_function("remove_weapon", ATTACK_D),
	  ]));

	call_out(#'init_my_guild_info,1);
    }
}

string my_long(string id, object who) {
    string str;

    if(!who) who = this_player();
    str = "This is the holy symbol of the almighty overgod \
" GOD_NAME ". It is the sign of your devotion, carry it with pride.";
    if(who && who->query_guild() == GN_PRIEST)
	str += "\n[Priest info: To seek enlightment, search for 'advice'.]";
    return str;
}


void
create_treasure() {
    int dum;

    set_name("symbol");
    set_short("The holy symbol of " GOD_NAME);
    set_long(#'my_long);
    set_id(({"mark",GUILD_ID,"guild_mark","symbol","holything"}));

    faith = 0;
    metamorphosis_penalty = 0;
    sat_time = time();
    sat_amount = 0;

    light_level = 0;
    healed = allocate(5);
    dum=time();
    healed_time = ({dum,dum,dum,dum,dum});
}

get() { return 1; }
drop() { return 1; }

extra_look(){
    return sprintf("%s is a faithful follower of %s.",
      capitalize(owner->query_name()), ORDERS[order+1]);
}


/**** COMMANDS ****/

status
priest_cmd(string arg)
{
    string v;

    v = query_verb();
    return (status)call_other(PRIEST_DIR + "bin/_" + v,
      v + "_cmd", owner, this_object(), arg);
}

mapping
query_guild_commands()
{
    return (([
	"pskills"       : #'priest_cmd,
	"askills"       : #'priest_cmd,
	"spells"        : #'priest_cmd,
	"potions"       : #'priest_cmd,

	"invoke"        : #'priest_cmd,
	"mix"           : #'priest_cmd,
	"sample"        : #'priest_cmd,
	"meditate"      : #'priest_cmd,
	"angel"         : #'priest_cmd,

	"comm"          : #'priest_cmd,
	"advice"        : #'priest_cmd,
	"pray"          : #'priest_cmd,
	"praise"        : #'priest_cmd,
	"absolve"       : #'priest_cmd,
	"priest"        : #'priest_cmd, // several commands starting with "priest"
	"target"        : #'priest_cmd,
	"exclude"       : #'priest_cmd,

	// staff commands:
	"store"         : #'priest_cmd,
	"absorb"        : #'priest_cmd,
	"rid"           : #'priest_cmd,
	"leave"         : #'priest_cmd,
	"zap"           : #'priest_cmd,

	// officer commands:
	"judge"         : #'priest_cmd,
	"frock"         : #'priest_cmd,
	"unfrock"       : #'priest_cmd,
	"excom"         : #'priest_cmd,

	// for coders only:
	"pcoder"          : #'priest_cmd,
      ]));
}



/**** FUNCTIONS THAT DONT FIT THE CATEGORIES ABOVE :) ****/


status
is_valid_heal(object who) {
    int i,counter;

    counter = 0;

    for(i=0;i<sizeof(healed);i++){
	if(time()-healed_time[i] > 120) healed[i]=0;        
	if(healed[i]==who) counter++; 
    }

    if(counter>=2) return 0;
    // there was a bug here, which prevented players from getting any
    // exp when they healed ppl. fixed it /Chopin

    for(i=sizeof(healed)-1;i>0;i--) {
	healed[i]=healed[i-1];
	healed_time[i]=healed_time[i-1];
    }

    healed[0]=who;
    healed_time[0]=time();

    return 1;

    /* Checks to see if player been healed 2 out of last
    5 times, if so, no exp for heal. Prevents going back and 
    forth between two players. Removes them from list after 2
    minutes. */
} 


// easy way to inform the debugger
void
inform_debugger(string str) {
    if(debugger) {
	if(debugger != owner)
	    debugger->tell_me(sprintf("&&%s: %s",cap_name,str));
	else
	    owner->tell_me("%% "+str);
    }
}

