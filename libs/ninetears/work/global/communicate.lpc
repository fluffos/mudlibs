#include "drinks.h"
#include "inet.h"
#include "player.h"
#include <network.h>
int social_points, max_social_points;
int guild_flag;
nosave string my_file_name;
string *languages,cur_lang;

string drunk_speech(string str);

void communicate_commands() {
    add_action("do_say","decir");
    add_action("do_say","say");
    add_action("do_say","'",10);
    add_action("do_loud_say", "lsay");
    add_action("do_loud_say","\"",10);
    add_action("do_tell","tell");
    add_action("do_tell","t");
    add_action("do_tell","decir a");
    add_action("do_whisper", "whisper");
    add_action("do_whisper", "susurrar");
    add_action("set_language", "speak");
    add_action("set_language", "hablar");
    add_action("set_language", "speak");
    add_action("do_emote",":",10);
    add_action("do_emote","emote");
// Removed by Radix - Jan 1996
//  add_action("do_channels", "000");
    add_action("do_channels", "emergencia");
    add_action("do_channels", "guild");
    add_action("do_channels", "gremio");
//Added by Quark, May 96.
    add_action("do_channels", "group");
    add_action("do_channels", "clan");
    add_action("do_channels", "race");
    add_action("do_channels", "raza");
    add_action("do_channels", "chat");
    add_action("do_channels", "ciudad");

/* Testing something, baldrick, may '96
 * and it works.. next dimension, here we come.
 */

#ifndef STRICT_MUD
      add_action("do_echo","echo");
      add_action("do_emote_all", "emoteall");
      add_action("do_echo_to", "echoto");
      add_action("do_shout", "shout");
      add_action("do_shout", "gritar");
#endif

   // Who did this?  goobers!
  /*
    if( this_player()->query_creator() )
    {
	add_action("do_channels", "cre");
	if( this_player()->query_lord() )
	    add_action("do_channels", "demi");
    }
   */
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
    case '!' : return "exclama";
    case '?' : return "pregunta";
    default:   if (def)
	    return def;
	else
	    return "dice";
    }
} /* query_word_type() */

string query_shout_word_type(string str)
{
    int i;

    for (i=strlen(str)-1;str[i] == ' ';i--);
    switch (str[i]) {
    case '!' : return "berrea";
    case '?' : return " preguntando";
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
	notify_fail("Syntax: lsay <algo>\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" no es un lenguaje hablado.\n");
	return 0;
    }
    word = query_word_type(arg);
    if (this_object()->query_volume(D_ALCOHOL))
	arg = drunk_speech(arg);
    environment()->event_person_say(TO, this_object()->query_cap_name()+" " + word + " fuertemente: ",arg, cur_lang);
    if (cur_lang != "common" && cur_lang != "comun") {
    	//word += " en "+cur_lang;
    	my_mess(CAP(word)+"s fuertemente en "+cur_lang+": ", arg);
    }
    else
    	my_mess(capitalize(word) + "s fuertemente: ", arg);
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_loud_say() */

int do_say(string arg, int no_echo)
{
    string word;

// Taniwha, sanity/ no debug errors
   if(!environment(this_object()))
   {
      tell_object(this_object(),"En el Limbo, nadie puede oirte decir nada.\n");
      return 0;
   }
    if (!arg)
	arg = "";
    if (arg == "" || arg == " ") {
	notify_fail("Syntax: decir <algo>\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" no es un lenguaje hablado.\n");
	return 0;
    }
    word = query_word_type(arg);
    if (this_object()->query_volume(D_ALCOHOL))
	arg = drunk_speech(arg);
    environment()->event_person_say(TO, this_object()->query_cap_name()+" " + word +": ", arg, cur_lang, this_object()->query_int());
    if (!no_echo) {
	if (cur_lang != "common" && cur_lang != "comun") {
	    my_mess(CAP(word)+"s en "+cur_lang+": ", arg);
	    //word += " en "+cur_lang;
	}
	else
	  my_mess(capitalize(word) + "s: ", arg);
    }
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_say() */

int do_tell(string arg, object ob, int silent)
{
    string str, rest, word;
    string person, mud;

    if ((!arg || arg == "") && !ob) {
	notify_fail("Sintaxis: tell persona <mensaje>\n");
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
	notify_fail(capitalize(cur_lang)+" no es un lenguaje hablado.\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_distance(cur_lang)) {
	notify_fail("El "+ cur_lang +" no se puede hablar a "+
	  "distancia.\n");
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
	    notify_fail(capitalize(str) + " no esta conectado.\n");
	    return 0;
	}
    }
    if (ob == this_player()) {
	notify_fail("Hablando contigo mismo otra vez? No se, no se...\n");
	return 0;
    }
    if (ob->query_property("player") && !interactive(ob)) {
	notify_fail(ob->query_cap_name()+" esta en forma de estatua lageada.\n");
	return 0;
    }
    if(adjust_social_points(-TELL_COST) < 0) {
	notify_fail(NO_POWER);
	return 0;
    }
    word = query_word_type(rest, "");
    if (word != "") {
	word = " " + word + "ndo";
	if (word == "dice") // te dice diciendo? :)
		word = " diciendo";
	}
    if (this_object()->query_volume(D_ALCOHOL))
	arg = drunk_speech(arg);
    if (word != " preguntando") {
	ob->event_person_tell(this_object(), this_object()->query_cap_name()+
	  " te dice" + word + ": ", rest, cur_lang);
	if (cur_lang != "common" && cur_lang != "comun")
		word += " en "+cur_lang;
	if (!silent)
	    my_mess("Dices a " + ob->query_cap_name() + word + ": ", rest);
    } else {
	ob->event_person_tell(this_object(), this_object()->query_cap_name()+
	  " te pregunta: ", rest, cur_lang);
	if (cur_lang != "common" && cur_lang != "comun") word += " en "+cur_lang;
	if (!silent)
	    my_mess("Preguntas a " + ob->query_cap_name()+": ", rest);
    }
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_tell() */

int do_emote(string arg) 
{
    string str;

    if(my_file_name=="/global/player"&&!this_player()->query_property("emote")) {
	notify_fail(NOT_ALLOWED);
	return 0;
    }
    if (!arg)
	arg = "";

    str = query_verb();

    if (arg == "" || arg == " ") {
	notify_fail("Sintaxis: emote <accion>\n");
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
	notify_fail("Sintaxis: gritar <algo>\n");
	return 0;
    }
    if (this_object()->query_property("noshout_lock")) {
        notify_fail("Aun estas intentando coger aire para poder volver "
                    "a gritar.\n");
        return 0;
    }
    if (this_object()->query_earmuffs()) {
	notify_fail("Para que gritar si no puedes oir las repuestas?\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" no es un lenguaje hablado.\n");
	return 0;
    }
    if (!LANGUAGE_HAND->query_language_distance(cur_lang)) {
	notify_fail("El "+ cur_lang +" no se puede hablar a "+
	  "distancia.\n");
	return 0;
    }
    if(adjust_social_points(-SHOUT_COST*((strlen(str)/10)+1)) < 0) {
	notify_fail(NO_POWER);
	return 0;
    }
    s1 = query_shout_word_type(str);
    if (s1!="berrea")
	s = "grita"+s1;
    else
	s = s1;

      str = "/obj/handlers/profanity"->clean_language(str);

    if (this_object()->query_volume(D_ALCOHOL))
	str = drunk_speech(str);
    event(users(), "person_shout", this_object()->query_cap_name()+" "+s+": ", str, cur_lang);
    if (s1 != "berrea") {
	if (cur_lang != "common" && cur_lang != "comun") s1 += " en "+cur_lang;
	my_mess("Gritas" + s1 + ": ", str);
    } else {
	if (cur_lang != "common" && cur_lang != "comun") s1 += "s en "+cur_lang;
	else s1=s1+"s";
	my_mess(CAP(s1) + ": ", str);
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

    notify_fail("Sintaxis: susurrar [a] <persona> <algo>\n");
    if (!str)
	return 0;
    if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
	notify_fail(capitalize(cur_lang)+" no es un lenguaje hablado.\n");
	return 0;
    }
    sscanf(str, "a %s", str);
    bits = explode(str, " ");
    obs = ({ });
    for (i=0;i<sizeof(bits);i++)
	if (sizeof(obs = find_match(implode(bits[0..i], " "), environment())))
	    break;
    s2 = implode(bits[i+1..100], " ");
    if (sizeof(obs) == 1 && obs[0] == this_player()) {
	say(this_player()->query_cap_name()+" se susurra algo a "+
	  this_player()->query_objective()+" mismo.\n");
	write("Susurrandote cosas a ti mismo!? Hmm, se te va la olla.\n");
	return 1;
    }
    obs = obs - ({ this_player() });
    for (i=0;i<sizeof(obs);i++)
	if (!living(obs[i]) || obs[i]->query_hidden())
	    obs = delete(obs, i--, 1);
    if (!sizeof(obs)) {
	notify_fail("No has podido encontrar a quien susurrar.\n");
	return 0;
    }
    if (this_object()->query_volume(D_ALCOHOL))
	s2 = drunk_speech(s2);
    s2 += "%^RESET%^";
    s = query_whisper_word_type(s2);
    event(environment(), "whisper", this_object()->query_cap_name() +" susurra a " +s,s2,obs,cur_lang);
    /*  " whispers " + s, s2, obs, cur_lang); */
    my_mess("Susurras " + s + "a " + query_multiple_short(obs) + ": ", s2);
    this_player()->adjust_time_left(-5);
    return 1;
} /* do_whisper() */

int do_channels( string str )
{
    "global/do_chat"->do_chat( str );
    return 1;
}  /* do_channels */

string drunk_speech(string str) 
{
    return replace(str, ({ "s", "sh", "r", "rr", "ing", "in'", "x", "xsh",
      "S", "SH", "R", "RR", "ci", "chi", "ce", "che", "za", "cha", "ze",
"che", "zi", "chi", "zo", "cho", "zu", "chu" }));
} /* drunk_speech() */

// Flode, 080997. Hopefully my fix will make sure that people won't learn
// fifteen dwarfs or similar anymore
void add_language(string lang) 
{
  int i;

  if (!LANGUAGE_HAND->test_language(lang))
    return ;
  if(!i=(member_array(lang, languages)+1))
    languages += ({ lang });
  else
    while(i < sizeof(languages))
      if(languages[i] == lang)
        languages = delete(languages, i, 1);
      else
        ++i;
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
	tell_object(this_object(), "Acabas de olvidar el lenguaje "+
	  "que hablabas.  Ahora hablas "+cur_lang+".\n");
    }
} /* remove_language() */

int set_language(string str) 
{
    if (!str) {
	notify_fail("Ahora estas hablando "+cur_lang+" y puedes hablar "+
	  query_multiple_short(languages+({ "grunt" }))+".\n");
	return 0;
    }
    if (member_array(str, languages+({ "grunt" })) == -1) {
	notify_fail("No sabes hablar "+str+".\n");
	return 0;
    }
    cur_lang = str;
    tell_object(this_object(),"Ahora usas "+str+" para hablar y escribir.\n");
    return 1;
} /* set_language() */

string query_current_language() { return cur_lang; }

string *query_languages() { return languages; }

// Needed to be here - Radix Jan 1996
int query_known_language(string lang)
{
   if(!lang) return(0);
   if(member_array(lang,languages) != -1) return(1);
   return(0);
}
