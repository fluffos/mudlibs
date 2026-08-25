//	/std/user.c
//	from the Nightmare mudlib
//	the user object
//	based on the user.c created by Sulam and Buddha @TMI
//	rewritten by Descartes of Borg september 1992
//      Pallando (93-05-27) Added multiple character handling.
//      Pallando (93-06-17) Removed call to living::setup()
//	Pallando (94-09-20) Changed harassment to new system


#include <std.h>
#include <config.h>
#include <rooms.h>
#include <security.h>
#include <daemons.h>
#include <move.h>
#include <objects.h>
#include <money.h>
#include <flags.h>
#include <dirs.h>
#include <council.h>

inherit AUTOSAVE;
inherit EDITOR;
inherit FILES;
inherit NMSH;
inherit MORE;
inherit REFS;
inherit LIVING;


nosave string *__IgnoreMsgClass;
#define DEATH_MSGS ({\
sprintf("A cold wind sweeps across %s, grieving the loss of %s.", mud_name(), query_cap_name()),\
sprintf("You hear the faint howl of %s death from far away.", possessive_noun(query_cap_name())),\
sprintf("%s mourns the tragic death of %s.", mud_name(), query_cap_name()),\
sprintf("The bells of %s toll for the death of %s.", mud_name(), query_cap_name()),\
sprintf("The world about you darkens a moment at the death of %s.", query_cap_name()),\
})

int platinum, gold, electrum, silver, copper;

int player_age;
int __NoQuit;
int level, ghost, rolls, verbose_moves;
int birth;
nosave int disable, time_of_login;
nosave int __LogHarass;
nosave mixed *__MessageCue;
nosave string __Client;
nosave int __LastAged;
mapping blocked, news;
nosave mapping __LastError;
nosave int snoop, earmuffs;
string	char_name, real_name, email, ip, last_on, password, race, original_site;
private string position, primary_start, *__RestrictedChannels;
private int __WhereBlock;
private  nosave string *channels;
mapping mini_quests;
string *quests;
string *mysites;
string guild;
string	*message;
nosave string *__UserId;
string married;
mixed *current_marriage, *divorced;
nosave string net_died_here;
nosave mapping term_info;
nosave object died_here;

int query_where_block();
int set_where_block();
int query_blocked(string str);
int set_mini_quest(string str, int x, string desc);
int set_quest(string str);
string *query_mini_quests();
int query_log_harass();
void reset_terminal();
mapping get_mini_quest_map();
string *query_quests();
private  register_channels();
string *query_mysites();
void set_mysites(string *str);
void set_guild(string str);
void set_position(string pos);
void set_id(string *bogus);
void set_level(int x);
void set_race(string res);
string query_race();
nomask int query_level();
string query_guild();
void get_email(string e);
int query_ghost();
void add_message(string str);
void write_messages();
string query_email();
nomask string query_position();

void get_email(string e) {
    string who, where;

    write("\n");
    if( sscanf(e, "%s@%s", who, where) != 2 ) {
	write("Sorry, email must be in the form of user@host");
	message("prompt", "Please reenter your email address: ", this_player());
	input_to("get_email");
	return;
    }
    email = e;
}

int query_where_block() {
    return __WhereBlock;
}

int set_where_block() {
    __WhereBlock = __WhereBlock ? 0 : 1;
    return __WhereBlock;
}

void describe_current_room(int verbose) {
    object env;
    string borg;
    mixed tmp;
    int light;

    env = environment(this_object());
    if(!env){
    move_object(ROOM_START);
    env = environment(this_object());
    }
    if(creatorp(this_object())) borg = file_name(env)+"\n";
    else borg = "";
    if((light=effective_light(this_object())) > 6 || light < 1) {
	if(light > 6) borg += "It is too bright to see.";
	else if(light > -2) borg += "It is dark.";
	else if(light > -4) borg += "It is quite dark.";
	else if(light > -6) borg += "It is very dark.";
	else borg += "It is completely dark.";
	message("room_description", borg, this_object());
	if(stringp(tmp=(string)env->query_smell("default")))
	    message("smell", tmp, this_object());
	else if(functionp(tmp))
	    message("smell",(string)((*tmp)("default")), this_object());
	if(stringp(tmp=(mixed)env->query_listen("default")))
	    message("sound", tmp, this_object());
	else if(functionp(tmp)) message("sound", (string)((*tmp)("default")), this_object());
	return;
    }
    else if(light > 3) borg += "It is really bright.\n";
    borg += (verbose ? (string)env->query_long(0)+" " :
      (string)env->query_short());
    message("room_description", borg, this_object());
    if(verbose && stringp(tmp=(mixed)env->query_smell("default")))
	message("smell", tmp, this_object());
    else if(verbose && functionp(tmp))
	message("smell",(string)((*tmp)("default")), this_object());
    if(verbose && stringp(tmp=(mixed)env->query_listen("default")))
	message("sound", tmp, this_object());
    else if(verbose && functionp(tmp))
	message("sound", (string)((*tmp)("default")), this_object());
    if((tmp=(string)env->describe_living_contents(({this_object()})))!="")
	message("living_item", tmp, this_object());
    if((tmp=(string)env->describe_item_contents(({})))!="")
	message("inanimate_item", tmp, this_object());
}

void basic_commands() {
    add_action("quit", "quit");
}

int query_verbose() { return verbose_moves; }

int set_brief() {
    verbose_moves = !verbose_moves;
    return 1;
}

varargs void move_player(mixed dest, string msg) {
    object prev;
    object *inv;
    string here,going,temp1,temp2,temp3;
    int i, illum, bzbd, adj, tmp;

    prev = environment( this_object() );
    here = file_name(prev);
    if(stringp(dest) && dest[0] != '/') dest = "/"+dest;
    if(move(dest) != MOVE_OK) {
	message("system","You remain where you are.", this_object());
	return;
    }
    if(query_property("stealth"))
	set_property("stealth", (int)query_property("stealth")-1);
    if(adj = query_property("stealth")) {
	add_skill_points("stealth", adj);
	adj += query_stats("dexterity");
	add_sp(-1);
    }
    if(!query_invis() && !hiddenp(this_object())) {
	inv = all_inventory(prev);
	for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
	    if(!living(inv[i]) || inv[i] == this_object()) continue;
	    if(adj) tmp = (adj-(int)inv[i]->query_stats("wisdom"));
	    else tmp = 0;
	    if(tmp > random(101)) continue;
	    if(effective_light(inv[i])-(query_skill("stealth")/17) < 0) continue;
	    if(!msg || msg == "") message("mmout", query_mmout(),inv[i]);
	    else message("mout", query_mout(msg), inv[i]);
	}
	inv = all_inventory(environment(this_object()));
	for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
	    if(!living(inv[i])) continue;
	    if(inv[i] == this_object()) continue;
	    if(adj) tmp = (adj-(int)inv[i]->query_stats("wisdom"));
	    else tmp = 0;
	    if(tmp > random(101)) continue;
	    if(effective_light(inv[i])-(query_skill("stealth")/17) < 0) continue;
	    if(!msg || msg == "") message("mmin",query_mmin(),inv[i]);
	    else message("min", query_min(), inv[i]);
	}
	if(query_followers())
	    move_followers(prev);
    }
    add_sp(-1);
    describe_current_room(verbose_moves);
}

void create() {
    autosave::create();
    editor::create();
    nmsh::create();
    more::create();
    living::create();
    __IgnoreMsgClass = ({ "broadcast", "info", "more", "room_description", "room_exits","smell","sound","write","say", "system", "prompt", "inanimate_item", "living_item"});
    position = "player";
    wielded = ([]);
    level = 1;
    set_mass(500);
    set_max_encumbrance(5000);
    __LastAged = time();
    verbose_moves = 1;
    enable_commands();
}

int remove() {
    autosave::remove();
    CHAT_D->remove_user(channels - __RestrictedChannels);
    MULTI_D->quit(query_name());
    return living::remove();
}

int quit(string str) {
    if(__NoQuit && !query_forced()) return notify_fail("Stinking cheater.\n");
    if (str) {
	notify_fail("Quit what ?\n");
	return 0;
    }
    if(query_followers()) clear_followers();
    message("environment",
      "Reality suspended.  See you another time!", this_object());
    save_player( query_name() );
    say(query_cap_name() + " is gone from our reality.");
    log_file("enter", query_name()+" (quit): "+ctime(time())+"\n");
    PLAYER_D->add_player_info();
    remove();
    return 1;
}

void new_body() {
    mapping borg;
    string *zippo;
    int i, max;
    string tmp;

    init_limb_data();
    if(!race) return;
    tmp = race;
    set_max_hp(50 + stats["constitution"] * 10);
    set_hp( (50 + stats["constitution"]*8)/2 );
    set_max_mp( (50 + stats["intelligence"]*10) );
    set_mp( 0 );
    set_max_sp(7*query_stats("dexterity"));
    set_sp(query_stats("dexterity"));
    set_heal_rate(2);
    borg = (mapping)RACE_D->body(this_object());
    for(i=0, max=sizeof(zippo=keys(borg)); i<max; i++)
	add_limb(zippo[i], borg[zippo[i]]["limb_ref"],borg[zippo[i]]["max_dam"], 0, 0);
    set_wielding_limbs((string *)RACE_D->query_wielding_limbs(tmp));
    set_fingers((int)RACE_D->query_fingers(tmp));
    set_max_encumbrance(stats["strength"] * 200);
}

void setup() {
    string tmp, *start_temp;

    set_living_name(query_name());
    set_heart_beat(1);
    if(!stats) init_stats();
    if(!skills) init_skills(0);
    if(!__PlayerAge) __PlayerAge = player_age;
    init_living();
    basic_commands();
    ip = query_ip_name(this_object());
    last_on = ctime(time());
    time_of_login = time();
    if(!body) new_body();
    if(!birth) birth = time();
    fix_limbs();
    register_channels();
    set_id( ({}) );
    set_max_encumbrance(200*query_stats("strength"));
    nmsh::setup();
    if(!query_race()) move(ROOM_SETTER);
    else {
	sight_bonus = (int)RACE_D->query_sight_bonus(query_race());
	if(!primary_start) primary_start = getenv("start");
	if(primary_start)
	{
	    start_temp = explode(primary_start, "/");
	    if(start_temp && sizeof(start_temp) >= 2)
	    {
		if(start_temp[0] == "d")
		{
		    start_temp[0] = "domains";
		    primary_start = implode(start_temp, "/");
		}
		else if(start_temp[0] == "wizards")
		{
		    start_temp[0] = "realms";
		    primary_start = implode(start_temp, "/");
		}
	    }
	}
	if(!(primary_start && stringp(primary_start) && move(primary_start) == MOVE_OK))
	    move(ROOM_START);
	setenv("start", primary_start);
    }
    if(!stringp(tmp = getenv("TERM"))) setenv("TERM", tmp = "unknown");
    term_info = (mapping)TERMINAL_D->query_term_info(tmp);
    write_messages();
    autosave::setup();
    call_out("save_player", 2, query_name());
    PLAYER_D->add_player_info();
    log_file("enter", query_name()+" (enter): "+ctime(time())+" from "+
      query_ip_name()+" with\n"+
      query_exp()+" exp, "+
      query_money("platinum")+" pl, "+
      query_money("gold")+" gd, "+
      query_money("electrum")+" el, "+
      query_money("silver")+" sl, "+
      query_money("copper")+" cp\n");
    NEWS_D->read_news();
    set_max_sp(query_stats("dexterity")*7);
}

void heart_beat() {
    object *inv;
    string *cns;
    int i;

    if(!interactive(this_object())) {
	set_heart_beat(0);
	return;
    }
    autosave::heart_beat();
    living::heart_beat();
    ok_to_heal ++;
    if(disable) disable--;
    if(!disable) continue_attack();
    magic_round = 0;
    if(query_age() > ok_to_heal) do_healing(calculate_healing());
    else calculate_healing();
    if(query_idle(this_object()) >= 3600 &&
      !creatorp(this_object()) ) {
	this_object()->move_player(ROOM_IDLE_SHOP);
	this_object()->force_me("sell all");
	this_object()->force_me("quit");
    }
    if(query_invis() && query_sp()<0 && !creatorp(this_player()) ) set_invis(0);
}

void net_dead() {
    CHAT_D->remove_user(channels - __RestrictedChannels);
    channels = ({});
    save_player(query_name());
    net_died_here = file_name( environment(this_object()) );
    message("other_action", sprintf("%s suddenly disappears into a sea of "
	"irreality.", query_cap_name()), environment(this_object()), ({ this_object() }));
    this_object()->move_player(ROOM_FREEZER);
    if(query_snoop(this_object()))
	tell_object(query_snoop(this_object()), capitalize(query_name())+
	  " has gone net-dead.");
    set_heart_beat(0);
}

void restart_heart() {
    string dead_ed;

    message("write", (creatorp(this_object()) &&
	file_size(dead_ed = user_path(query_name())+"dead.edit") > -1 ?
	"\nYour edit file was saved as: "+dead_ed+"\n" :
	"Reconnected."), this_object());
    set_heart_beat(1);
    if(net_died_here) this_object()->move_player(net_died_here);
    else this_object()->move_player(ROOM_START);
    net_died_here = 0;
    say(query_cap_name()+" has rejoined our reality.");
    register_channels();
}

nomask void die() {
    object ob;
    object corpse;
    object money_ob;
    object *stuff;
    string *currs;
    int tmp;
    int i;

    message("environment", "%^RED%^"+DEATH_MSGS[random(sizeof(DEATH_MSGS))], users(),
      ({ this_object() }) );
    if(creatorp(this_object())) {
	message("death", "You are immortal and cannot die.", this_object());
	return;
    }
    ob = this_object();
    died_here = environment(ob);
    message("death", "You die.\nYou feel the sensations of nothingness " +
      "as you rise above your corpse.\nYou arrive at a destination in a reality " +
      "not like your own.", this_object());
    //  tell_object(this_object(), "You die.\nYou feel the sensations of nothingness
    // as you rise above your corpse.\nYou arrive at a destination in a reality not
    // like your own.\n");
    message("death", query_cap_name()+ " dies a horrible death.",
      environment());
    //  tell_room(environment(this_object()), query_cap_name()+" dies a horrible death.\n", ob);
    if((int)this_object()->query_level() > 1) {
	this_object()->add_exp(-((int)this_object()->query_exp()/4));
	this_object()->reduce_stats();
	reduce_skills();
	while((int)ADVANCE_D->get_exp(query_level()) > query_exp())
	    set_level(query_level()-1);
	setenv("TITLE", (string)ADVANCE_D->get_new_title(this_object()));
    }
    corpse = new(OB_CORPSE);
    corpse->set_name(query_cap_name());
    corpse->copy_body(this_object()); // Added for necromancy - Manny
    corpse->move(environment(this_object()));
    money_ob = new("/std/obj/coins");
    currs = query_currencies();
    for(i=0, tmp= sizeof(currs); i<tmp; i++) {
	money_ob->set_money(currs[i], query_money(currs[i]));
	add_money(currs[i], -query_money(currs[i]));
    }
    money_ob->move(corpse);
    i = sizeof(stuff = all_inventory(this_object()));
    while(i--) {
	if((int)stuff[i]->is_germ()) stuff[i]->remove();
	else if((mixed *)stuff[i]->query_auto_load()) continue;
	else if((int)stuff[i]->allow_drop(this_object()))
	    stuff[i]->move(corpse);
    }
    this_object()->move("/domains/Praxis/death/death_room");
    cease_all_attacks();
    ghost = 1;
    save_player( query_name() );
    PLAYER_D->add_player_info();
}

void set_rname(string rname) {
    if(!((int)master()->valid_apply(({ query_name()})))) return;
    real_name = rname;
}

int is_player() { return 1; }

string query_ip() { return ip; }

string query_email() { if (email) return email; return "???@" + ip; }

string query_rname() { return real_name ? real_name : "???"; }

string query_password() { return password; }

void set_password(string pass) {
    if(!((int)master()->valid_apply(({ query_name()})))) return 0;
    password = pass;
    save_player( query_name() );
}

void set_email(string e) {
    if(!((int)master()->valid_apply(({ query_name()})))) return 0;
    if (this_player(1) != this_player()) return 0;
    email = e;
    save_player( query_name() );
}

int set_snoop() {
    if(!((int)master()->valid_apply(({ query_name()})))) return 0;
    if(snoop) {
	message("my_action", "You are now secure from being snooped.",
	  this_object());
	snoop = 0;
	return 1;
    }
    else {
	message("my_action", "You can now be snooped by anyone.",
	  this_object());
	snoop = 1;
	return 1;
    }
}

int query_snoop() { return snoop; }


void write_messages() {
    mapping mail_stat;
    int i;

    message("system", sprintf("\n        >>> Terminal currently set to %s <<<",
	getenv("TERM")), this_object());
    mail_stat = (mapping)FOLDERS_D->mail_status(query_name());
    if(mail_stat["unread"]) {
	message("login", sprintf("\n        >>> %d of your %d %s are "
	    "unread! <<<", mail_stat["unread"], mail_stat["total"],
	    (mail_stat["total"]>1 ? "letters" : "letter")), this_object());
    }
    if(query_invis()) message("login", "\n        You are currently "
	  "invisible.", this_object());
    if(creatorp(this_object())) {
	if(file_exists("/log/errors/"+query_name()))
	    message("login", "\n        >>> You have errors in /log/errors/"+
	      query_name()+" <<<", this_object());
	if(file_exists("/log/reports/"+query_name()))
	    message("login", "\n        >>> You have reports in "
	      "/log/reports/"+query_name()+" <<<", this_object());
    }
    if( !message ) return;
    for( i=0; i<sizeof(message); i++ )
	tell_object(this_object(), message[i]);
    message = ({ });
}

string query_title() {
    string str;
    string foo,fii;

    if(query_ghost()) return "A ghost";
    if(invis) return 0;
    str = getenv( "TITLE" );
    if( !str ) str = query_cap_name();
    else if( !sscanf(str, "%s$N%s", foo,fii) )
	str = query_cap_name() + " " + str;
    else
	str = substr( str, "$N", query_cap_name() );
    return str;
}

string query_short() {
    if (interactive(this_object()))
	return query_title();
    else
	return (query_title() + " (link-dead)");
}

mixed *local_commands() {
    if(!((int)master()->valid_apply(({ query_name()})))) {
	message("my_action", "You aren't authorized to check this information.",
	  this_object());
	return ({});
    }
    return commands();
}

nomask string query_position() { return position; }

nomask int query_level() { return level; }

void set_position(string pos) {
    if(!creatorp(this_object()) && !((int)master()->valid_apply(({ query_name()})))) return;
    if(member_array(position, MORTAL_POSITIONS) != -1)
    if(position == "high mortal" && pos != "high mortal")
	init_path();
    position = pos;
    return;
}

void set_level(int lev) {
    level = lev;
    PLAYER_D->add_player_info();
    log_file("advance", this_object()->query_name()+" advanced to level "+lev+": "+ctime(time())+"\n");
    if(position == "high mortal" && level < 20) {
	position = "player";
	search_path -= ({ DIR_HM_CMDS });
	set_env("start", ROOM_START);
	set_env("TITLE", "Mortal $N the fallen high mortal");
    }
    return;
}


int set_earmuffs() {
    if( earmuffs )
    {
	earmuffs = 0;
	message("my_action", "Your earmuffs are now off.",
	  this_object());
    }
    else
    {
	message("my_action", "Your earmuffs are now on.", this_object());
	earmuffs = 1;
    }
    return earmuffs;
}

void receive_message(string msg_class, string msg) {
    string *words;
    int i, max;
    string str, pre, post;
    int x, do_wrap;

    if(query_log_harass())
        log_file(DIR_LOGS "/harass/"+query_name(), strip_colours(msg)+"\n");
    if(query_locked() && msg_class != "prompt") {
	if(!__MessageCue) __MessageCue = ({});
	__MessageCue += ({ ({ msg_class, msg }) });
	return;
    }
    if(__Client) {
	receive("<"+msg_class+">"+msg+"\n");
	return;
    }
    if(!stringp(str=getenv("SCREEN"))) str = "75";
    x = to_int(str);
    if(msg_class[0] == 'N') msg_class = msg_class[1..sizeof(msg_class)-1];
    else if(msg_class != "prompt") msg = wrap(msg, x);  // prompt fix -Val
    if(msg_class == "system" || msg_class == "help" || msg_class == "more"){
	receive(msg);
	return;
    }
    if(query_blocked(msg_class) &&
      member_array(msg_class, __IgnoreMsgClass) == -1) return;
    switch(msg_class) {
    case "room_exits": msg = "%^GREEN%^"+msg; break;
    case "snoop": msg = "%^CYAN%^"+msg; break;
    case "smell": msg = "%^ORANGE%^"+msg; break;
    case "sound": msg = "%^CYAN%^"+msg; break;
    case "tell":
	if(sscanf(msg, "%s:%s", pre, post) == 2)
	    msg = "%^BOLD%^RED%^"+pre+":%^RESET%^"+post;
	break;
    case "shout":
	if(sscanf(msg, "%s:%s", pre, post) == 2)
	    msg = "%^BOLD%^BLUE%^"+pre+":%^RESET%^"+post;
	break;
    case "mmin": case "min": case "mmout": case "mout":
	msg = "%^BOLD%^GREEN%^"+msg; break;
    case "living_item": msg = "%^BOLD%^RED%^"+msg; break;
    case "inanimate_item": msg = "%^BOLD%^MAGENTA%^"+msg; break;
    }
    if(!term_info) reset_terminal();
    for(i=0, max=sizeof(words=explode(msg, "%^")); i<max; i++)
	if(term_info[words[i]]) words[i] = term_info[words[i]];
    receive(implode(words, "")+term_info["RESET"]);
}

void catch_tell(string str) {
    if(query_log_harass()) {
        log_file(DIR_LOGS "/harass/" + query_name(), str+"\n");
    }
    receive(str);
}

void set_guild(string str) {
    guild = str;
    if(!guild) guild = str;
}

string query_guild() { return guild; }

void set_rolls(int x) { rolls = x; }

int query_rolls() { return rolls; }

void set_blocked(string str) {
    if(!blocked) blocked = ([]);
    blocked[str] = !blocked[str];
    if(blocked[str]) message("info", "You are now blocking "+str+".",
	  this_object());
    else message("info", "You are no longer blocking "+str+".",this_object());
}

int query_blocked(string str) {
    if(!blocked) blocked = ([]);
    if(blocked["all"]) return blocked["all"];
    else return blocked[str];
}

string *query_mysites() {
    if(!mysites) mysites = ({});
    return mysites;
}

void set_mysites(string *borg) {
    if(!borg) return;
    if(!((int)master()->valid_apply(({ query_name()})))) return;
    mysites = borg;
    return;
}

string *query_quests() {
    if(!quests) quests = ({});
    return quests;
}

int set_quest(string str) {
    if(!quests) quests = ({});
    if(member_array(str, quests) != -1) return 0;
    player_data["general"]["quest points"] += (int)call_other(ROOM_QUEST, "query_quest_points", str);
    quests += ({ str });
    log_file("quests", query_name()+" completed "+str+": "+ctime(time())+"\n");
    return 1;
}

void return_to_death_site() {
    if(!died_here) this_object()->move("/domains/Praxis/square");
    else this_object()->move(died_here);
}

void revive() {
    message("my_action", "You return from the dead!", this_object());
    message("other_action", query_cap_name()+ " returns from the dead.",
      environment());
    //  tell_room(environment(this_object()), query_cap_name()+" returns from the dead.\n", this_object());
    new_body();
    ghost = 0;
}

int query_ghost() { return ghost; }

int query_quest_points() {
    if(!player_data["general"]["quest points"]) return 0;
    else return player_data["general"]["quest points"];
}

void set_disable(int x) {
    if(x) disable = x;
    else disable = 1;
}

int query_disable() { return disable; }

void set_married(string str) {
    if(current_marriage) return;
    current_marriage = ({ lower_case(str), time() });
}

void divorce_me() {
    if(!current_marriage) return;
    if(!divorced) divorced = ({ ({ current_marriage[0], current_marriage[1], time() }) });
    else divorced += ({ ({current_marriage[0], current_marriage[1], time() }) });
    current_marriage = 0;
}

string query_married() {
    return (current_marriage && sizeof(current_marriage) ?
      current_marriage[0] : 0);
}

mixed *query_current_marriage() { return current_marriage; }

mixed *query_divorced() { return divorced; }


int query_birthday() { return birth; }


void set_news(string which, int size) {
    if(!news) news = ([]);
    news[which] = size;
}

int query_news(string which) {
    if(!news) news = ([]);
    return news[which];
}


void hide(int x) {
    object *inv;
    int i;

    i = sizeof(inv = all_inventory(this_object()));
    if(x) {
	set_hide(x);
	while(i--) inv[i]->hide(x);
    }
    else {
	while(i--) inv[i]->hide(x);
	set_hide(x);
    }
}

void set_race(string str) {
    race = str;
    LANG_D->init_languages(this_object());
}

string query_race() { return race; }

int set_mini_quest(string str, int x, string desc) {
    if(!mini_quests) mini_quests = ([]);
    if(mini_quests[str]) return 0;
    else mini_quests[str] = ({ time(), desc });
    add_exp(x);
    log_file("quests", query_name()+" completed mini-quest "+str+" "+ctime(time())+" for "+x+" exp.\n");
    return 1;
}

string *query_mini_quests() {
    if(!mini_quests) return ({});
    else return keys(mini_quests);
}

mapping query_mini_quest_map() { return (mini_quests ? mini_quests : ([])); }

int query_login_time() { return time_of_login; }

void reset_terminal() {
    term_info = (mapping)TERMINAL_D->query_term_info(getenv("TERM"));
}

void set_name(string str) {
    if(!((int)master()->valid_apply(({ str })))){
//debug_message("tried to set_name(\""+str+"\") in user, got invalid apply");
 return;
}
    char_name = str;
    ::set_name(str);
}

void restrict_channel(string channel) {
    if(base_name(previous_object()) != "/cmds/adm/_channel") return;
    if(!__RestrictedChannels) __RestrictedChannels = ({});
    __RestrictedChannels += ({ channel });
    CHAT_D->remove_user( ({ channel }) );
}

void unrestrict_channel(string str) {
    if(base_name(previous_object()) != "/cmds/adm/_channel") return;
    __RestrictedChannels -= ({ str });
    CHAT_D->add_user( ({ str }) );
}

nomask string *query_channels() { return channels - __RestrictedChannels; }

 private register_channels() {
    if(creatorp(this_object()))
	channels = ({ "cleric","fighter","kataan","mage","monk","rogue"});
    else channels = (query_class() ? ({ query_class() }) : ({}));
    if(query_guild()) channels += ({ query_guild() });
    if(creatorp(this_object()) || high_mortalp(this_object())) channels += ({ "hm", "newbie" });
    else if(query_level() < 6) channels += ({ "newbie" });
    if(creatorp(this_object())) channels += ({ "cre", "gossip", "intercre"});
    if(ambassadorp(this_object())) channels += ({ "gossip" });
    if(archp(this_object())) channels += ({ "admin" });
    if(creatorp(this_object()) || ambassadorp(this_object())) channels += ({ "gossip" });
    if(creatorp(this_object()) || leaderp(this_object()))
	channels += ({ "council" });
    if(!__RestrictedChannels) __RestrictedChannels = ({});
    CHAT_D->add_user(channels - __RestrictedChannels);
}

string query_first_site() { return original_site; }

void set_primary_start(string str) {
    object ob;

    if(!(ob = load_object(str))) return;
    if(clonep(ob) || virtualp(ob)) return;
    setenv("start", primary_start = str);
}

string query_primary_start() { return primary_start; }

void clean_net_dead() {
    if(base_name(previous_object()) != ROOM_FREEZER) return;
    this_object()->remove();
}

void set_id(string *bogus) {
    int i;

    if(__UserId) return;
    if(!query_CapName()) {
	__UserId = ({ query_name() });
	return;
    }
    __UserId = ({ query_name(), lower_case(query_CapName()) });
    if((i=sizeof(bogus = explode(lower_case(query_CapName()), " "))) == 1)
	return;
    while(i--)
	if(!user_exists(bogus[i])) __UserId += ({ bogus[i] });
}

string *query_id() { return __UserId; }

int id(string str) {
    if(!str) return 0;
    else return member_array(str, __UserId) != -1;
}

void set_cap_name(string str) {
    if(query_name() != convert_name(str) &&
      base_name(previous_object()) != OB_LOGIN) return;
    living::set_cap_name(capitalize(str));
}

int query_undead() { return query_ghost(); }

void set_last_on(int x) {
    if(!archp(this_object())) return;
    last_on = ctime(x);
    save_player(query_name());
}

void empty_cue() {
    int i, maxi;

    if(previous_object() != this_object()) return;
    for(i=0, maxi = sizeof(__MessageCue); i < maxi; i++)
	message(__MessageCue[i][0], __MessageCue[i][1], this_object());
    __MessageCue = 0;
}

void set_log_harass(int x) {
    string txt;

    if(this_player() != this_object()) return;
    if( __LogHarass == x ) return;
    if( x )
    {
	txt = "**************** Start of Log *****************\n"+
	    "Time: " + ctime( time() ) + "\n";
	if( environment( this_object() ) ) txt += "Place: " +
	    file_name( environment( this_object() ) ) + "\n";
    } else {
	txt = "**************** End of Log *****************\n"+
	    "Time: " + ctime( time() ) + "\n";
    }
    log_file(DIR_LOGS "/harass/" + query_name(), txt);
    __LogHarass = x;
}

int query_log_harass() { return __LogHarass; }

void set_client(string str) {
    if(base_name(previous_object()) != OB_LOGIN) return;
    __Client = str;
}

string query_client() { return __Client; }

int query_hp() { return living::query_hp(); }

int query_max_hp() { return living::query_max_hp(); }

int query_mp() { return living::query_mp(); }

int query_max_mp() { return living::query_max_mp(); }

int query_sp() { return living::query_sp(); }

int query_max_sp() { return living::query_max_sp(); }

string get_path() { return nmsh::query_cwd(); }

string query_cwd() { return nmsh::query_cwd(); }

string query_prompt() {
    string str;

    if(stringp(str = getenv("PROMPT"))) return str;
    else return nmsh::query_prompt();
}

string getenv(string key) {
    return living::getenv(key);
}

string query_name() {
string tmp;

//tmp =  living::query_name();
tmp = __TrueName;
////debug_message("I am "+identify(this_object())+", and my name is: "+tmp);
//debug_message("My name is: "+tmp);
return tmp;
}

varargs int query_invis(object ob) { return living::query_invis(ob); }

void receive_snoop(string str) { receive_message("snoop", "%"+str); }

void set_backstab(int x) {
    if(file_name(previous_object(0)) != "/cmds/skills/_backstab") return;
    __NoQuit = 1;
    call_out("remove_backstab", x);
}

void remove_backstab() { __NoQuit = 0; }

void set_error(mapping mp) {
    if(previous_object() != master()) return;
    __LastError = mp;
}

mapping query_error() {
    if(file_name(previous_object(0))[0..24] != "/secure/cmds/creator/_dbx") return ([]);
    else return __LastError;
}
