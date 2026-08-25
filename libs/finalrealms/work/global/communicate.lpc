#include "drinks.h"
#include "inet.h"
#include "player.h"
#include <network.h>
int social_points, max_social_points;
int guild_flag;
nosave string my_file_name;
string *languages,
cur_lang;

string drunk_speech(string str);
string *query_languages();

void communicate_commands() {
    add_action("do_say","say");
    add_action("do_loud_say", "lsay");
    add_action("do_tell","tell");
    add_action("do_tell","t");
    add_action("do_whisper", "whisper");
    add_action("set_language", "speak");
    add_action("do_emote","emote");
 
/* Testing something, baldrick, may '96
 * and it works.. next dimension, here we come.
 */

#ifndef STRICT_MUD
      add_action("do_echo","echo");
      add_action("do_emote_all", "emoteall");
      add_action("do_echo_to", "echoto");
      add_action("do_shout", "shout");
#endif

} /* communicate_commands() */

void set_max_social_points(int num) {
    max_social_points = num;
} /* set_max_social_points() */

int query_max_social_points() {
    return max_social_points;
} /* query_max_social_points() */

void set_social_points(int num) {
    social_points = num;
} /* set_social_points() */

int query_social_points() {
    return social_points;
} /* query_social_points() */

int adjust_social_points(int num) 
{
    int temp;

    temp = social_points + num;
    if(temp >= 0) {
	social_points = temp;
	if(social_points > max_social_points)
	    social_points = max_social_points;
	return 1;
    }
    return -1;
} /* adjust_social_points() */

int hard_adjust_social_points(int num) {
    social_points += num;
} /* hard_adjust_social_points() */

varargs string query_word_type(string str, string def) 
{
    int i;

    for (i=strlen(str)-1;str[i] == ' ';i--);
    switch (str[i]) {
    case '!' : return "exclaim";
    case '?' : return "ask";
    default:   if (def)
	    return def;
	else
	    return "say";
    }
} /* query_word_type() */

string query_shout_word_type(string str) 
{
    int i;

    for (i=strlen(str)-1;str[i] == ' ';i--);
    switch (str[i]) {
    case '!' : return "yell";
    case '?' : return " asking";
    default:   return "";
    }
} /* query_shout_word_type() */

string query_whisper_word_type(string str) {
    int i;

    for (i=strlen(str)-1;str[i] == ' ';i--);
    switch (str[i]) {
    case '!' : return "urgently ";
    case '?' : return "questioningly ";
    default:   return "";
    }
} /* query_whisper_word_type() */

/* to properly columnate word_typed things */
void my_mess(string fish, string erk)
{
    if(!interactive()) return;
    efun::tell_object(this_object(), this_object()->fix_string(fish + erk,strlen(fish))+"\n");
} /* my_mess() */

int do_loud_say(string arg) 
{
    string word;

    if (!arg) 
	arg = "";
    if (arg == "" || arg == " ") {
	notify_fail("Syntax: lsay <something>\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" is not a spoken language.\n");
	return 0;
    }
    word = query_word_type(arg); 
    if (this_object()->query_volume(D_ALCOHOL))
	arg = drunk_speech(arg);
    event(environment(), "person_say", this_object()->query_cap_name()+
      " " + word + "s loudly: ", 
      arg, cur_lang);
    if (cur_lang != "common") word += " in "+cur_lang;
    my_mess("You " + word + " loudly: ", arg);
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_loud_say() */

int do_say(string arg, int no_echo) 
{
    string word;

// Taniwha, sanity/ no debug errors
   if(!environment(this_object()))
   {
      tell_object(this_object(),"In Limbo, noone can hear say anything.\n");
      return 0;
   }
    if (!arg) 
	arg = "";
    if (arg == "" || arg == " ") {
	notify_fail("Syntax: say <something>\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" is not a spoken language.\n");
	return 0;
    }
    word = query_word_type(arg);
    if (this_object()->query_volume(D_ALCOHOL))
	arg = drunk_speech(arg);
    event(environment(this_object()), "person_say", this_object()->query_cap_name()+
      " " + word +"s: ", arg, cur_lang, this_object()->query_int());
    if (!no_echo) {
	if (cur_lang != "common")
	    word += " in "+cur_lang;
	my_mess("You " + word + ": ", arg);
    }
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_say() */

int do_tell(string arg, object ob, int silent) 
{
    string str, rest, word;
    string person, mud;

    if ((!arg || arg == "") && !ob) {
	notify_fail("Syntax: tell person <message>\n");
	return 0;
    }
    if (!ob) {
	if (sscanf(arg,"%s %s",str,rest)!=2) {
	    notify_fail("Syntax: tell <name> something\n");
	    return 0;
	}
    } else
	rest = arg;

    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" is not a spoken language.\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_distance(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" is not able to spoken at a "+
	  "distance.\n");
	return 0;
    }
    if (!ob) {
	str = lower_case(str);
	str = (string)this_object()->expand_nickname(str);
	ob = find_player(str);
	if (!ob)
	    ob = find_living(str);
	if (!ob) {
	    /* Might be intermud... */
            if (this_object()->query_creator() && sscanf(str, "%s@%s", person, mud) == 2) {
                SERVICES_D->eventSendTell(person, mud, rest);
		return 1;
	    }
	    notify_fail(capitalize(str) + " is not logged in.\n");
	    return 0;
	}
    }
    if (ob == this_player()) {
	notify_fail("Talking to yourself again.  I don't know.\n");
	return 0;
    }
    if (ob->query_property("player") && !interactive(ob)) {
	notify_fail(ob->query_cap_name()+" is net dead.\n");
	return 0;
    }
    if(adjust_social_points(-TELL_COST) < 0) {
	notify_fail(NO_POWER);
	return 0;
    }
    word = query_word_type(rest, "");
    if (word != "")
	word = " " + word + "ing";
    if (this_object()->query_volume(D_ALCOHOL))
	arg = drunk_speech(arg);
    if (word != " asking") {
	ob->event_person_tell(this_object(), this_object()->query_cap_name()+
	  " tells you" + word + ": ", rest, cur_lang);
	if (cur_lang != "common") word += " in "+cur_lang;
	if (!silent)
	    my_mess("You tell " +  ob->query_cap_name() + word + ": ", rest );
    } else {
	ob->event_person_tell(this_object(), this_object()->query_cap_name()+
	  " asks you: ", rest, cur_lang);
	if (cur_lang != "common") word += " in "+cur_lang;
	if (!silent)
	    my_mess("You ask " + ob->query_cap_name()+": ", rest);
    }
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_tell() */

int do_emote(string arg) 
{
    string str;

    if(my_file_name=="/global/mortal" && !this_player()->query_property("emote")) {
	notify_fail(NOT_ALLOWED);
	return 0;
    }
    if (!arg)
	arg = "";

    str = query_verb();

    if (arg == "" || arg == " ") {
	notify_fail("Syntax: emote <womble>\n");
	return 0;
    }

    if(adjust_social_points(-EMOTE_COST) < 0) {
	notify_fail(NO_POWER);
	return 0;
    }
    this_player()->adjust_time_left(-5);
    str = (string)this_object()->query_cap_name()+" "+arg+"%^RESET%^\n";

    say(str);
    write(str);
    return 1;
} /* do_emote() */

/* ok... the shout cost is charged for every 10 letters, plus a bonus
 * one for the start charge..  SO a shout of yes will cost 1 social
 * point... where as a shout of lots a letters will cost lots
 */
// Flode added 2-round lockout  -  211197
int do_shout(string str) 
{
    string s1, s;

    if(!str || str == "") {
	notify_fail("Syntax : shout <text>\n");
	return 0;
    }
    if (this_object()->query_property("noshout_lock")) {
        notify_fail("You better clear your throat before you attempt to "
                    "shout again.\n");
        return 0;
    }
    if (this_object()->query_earmuffs()) {
	notify_fail("Why shout when you can't hear people shout back?\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" is not a spoken language.\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_distance(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" is not able to spoken at a "+
	  "distance.\n");
	return 0;
    }
    if(adjust_social_points(-SHOUT_COST*((strlen(str)/10)+1)) < 0) {    
	notify_fail(NO_POWER);
	return 0;
    }
    s1 = query_shout_word_type(str);
    if (s1 != "yell")
	s = "shouts"+s1;
    else
	s = s1+"s";
    if (this_object()->query_volume(D_ALCOHOL))
	str = drunk_speech(str);
    str += "\n";
    event(users(), "person_shout", this_object()->query_cap_name()+
      " "+s+": ", str, cur_lang);
    if (s1 != "yell") {
	if (cur_lang != "common") s1 += " in "+cur_lang;
	my_mess("You shout" + s1 + ": ", str);
    } else {
	if (cur_lang != "common") s1 += " in "+cur_lang;
	my_mess("You " + s1 + ": ", str);
    }
    str = " "+lower_case(str);
    this_object()->add_timed_property("noshout_lock", 1, 2);
    return 1;
} /* do_shout() */

int do_whisper(string str) 
{
    object *obs;
    string s, s2, *bits;
    int i;

    notify_fail("Syntax: whisper [to] <person> <string>\n");
    if (!str)
	return 0;
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" is not a spoken language.\n");
	return 0;
    }
    sscanf(str, "to %s", str);
    bits = explode(str, " ");
    obs = ({ });
    for (i=0;i<sizeof(bits);i++)
	if (sizeof(obs = find_match(implode(bits[0..i], " "), environment())))
	    break;
    s2 = implode(bits[i+1..100], " ");
    if (sizeof(obs) == 1 && obs[0] == this_player()) {
	say(this_player()->query_cap_name()+" whispers to "+
	  this_player()->query_objective()+"self.\n");
	write("Whispering to your self!?\n");
	return 1;
    }
    obs = obs - ({ this_player() });
    for (i=0;i<sizeof(obs);i++)
	if (!living(obs[i]))
	    obs = delete(obs, i--, 1);
    if (!sizeof(obs)) {
	notify_fail("Could not find anyone to whisper to.\n");
	return 0;
    }
    if (this_object()->query_volume(D_ALCOHOL))
	s2 = drunk_speech(s2);
    s2 += "%^RESET%^";
    s = query_whisper_word_type(s2);
    event(environment(), "whisper", this_object()->query_cap_name() +
      " whispers to " +s,s2,obs,cur_lang);
    /*  " whispers " + s, s2, obs, cur_lang); */ 
    my_mess("You whisper " + s + "to " + query_multiple_short(obs) + ": ", s2);
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_whisper() */

int do_channels( string str )
{
    "global/do_chat"->do_chat( str, query_verb() );
    return 1;
}  /* do_channels */

string drunk_speech(string str) 
{
    return replace(str, ({ "s", "sh", "r", "rr", "ing", "in'", "x", "xsh",
      "S", "SH", "R", "RR" }));
} /* drunk_speech() */

void add_language(string lang) 
{
    if (!LANGUAGE_HAND->test_language(lang))
	return ;
    // Flode added the 'if' - 150997
    if(member_array(lang, languages) == -1)
        languages += ({ lang });
} /* add_language() */

void remove_language(string lang) 
{
    int i;

    if ((i = member_array(lang, languages)) == -1)
	return ;
    languages = delete(languages, i, 1);
    if (lang == cur_lang) {
	if (!sizeof(languages))
	    cur_lang = "grunt";
	else
	    cur_lang = languages[0];
	tell_object(this_object(), "You just forgot the language you were "+
	  "speaking.  You are now speaking "+cur_lang+".\n");
    }
} /* remove_language() */

int set_language(string str) 
{
    if (!str) {
	notify_fail("You are now speaking "+cur_lang+" and can speak any of "+
	  query_multiple_short(this_object()->query_languages()+
           ({ "grunt"}))+".\n");
	return 0;
    }
    if (member_array(str, this_object()->query_languages()+
           ({ "grunt" }))== -1) {
	notify_fail("You do not know "+str+".\n");
	return 0;
    }
    cur_lang = str;
    tell_object(this_object(),"Now using "+str+" for speaking and writing.\n");
    return 1;
} /* set_language() */

string query_current_language() { return cur_lang; }

string *query_languages()
 {
   string *race_lang = this_object()->query_race_ob()->query_race_lang();
     if(!arrayp(race_lang))
       return languages;
    return languages + race_lang; 
 }

// Needed to be here - Radix Jan 1996
int query_known_language(string lang)
{
   if(!lang) return(0);
   if(member_array(lang,this_object()->query_languages()) != -1)
       return(1);
   return(0);
}
