//      /bin/user/_yell.c
//      from the Nightmare mudlib
//      yells to adjacent rooms, good for muds who want to axe shout
//      created by Descartes of Borg 20 april 1993

#include <std.h>

inherit DAEMON;

void do_yell(object env, string who, string str, string lang);
mapping *yell_msg(object *who_l, string who, string str, string lang);

int cmd_yell(string str) {
    string *primary, *secondary, *tmp_arr;
    string char_arr, lang, temp;
    int i, j, tmp, tmp2, prof;
    object env;

    if(this_player()->query_ghost()) {
        write("You howl pitifully.\n");
        say("You hear the howling of a ghost.\n");
        return 1;
    }
    if(!str) {
        notify_fail("Sore throat?\n");
        return 0;
    }
    if(sscanf(str,"in %s %s",lang, temp) == 2)
	str = temp;
    else
	lang = (string)this_player()->query_primary_lang();
    if(!this_player()->query_lang_prof(lang))
	return notify_fail("You do not know how to speak " + capitalize(lang) + ".\n");
    env = environment(this_player());
    if(env->query_property("no shout")) {
        notify_fail("Your voice does not travel far.\n");
        return 0;
    }


    log_file("shouts", this_player()->query_name()+" (yell): "+str+"\n");
    primary = (string *)env->query_destinations();
    if(this_player()->query_ansi()) write(magenta("You yell in "
	+capitalize(lang)+": ")+str+"\n");
    else write("You yell in "+capitalize(lang)+": "+str+"\n");
    do_yell(env,(string)this_player()->query_cap_name(), str, lang);
    for(i=0, tmp_arr = ({}), secondary=({}), tmp=sizeof(primary);i<tmp;i++){
        char_arr = (string)env->query_direction(primary[i]);
        if(char_arr) {
            if(env->query_door(char_arr)) secondary += ({primary[i]});
            else tmp_arr += ({ primary[i] });
        }
    }
    primary = tmp_arr;
    for(i=0, tmp=sizeof(primary); i<tmp; i++) {
        call_other(primary[i], "???");
        if(!(env = find_object(primary[i]))) continue;
        do_yell(env, (string)this_player()->query_cap_name(), str, lang);
        tmp_arr = (string *)env->query_destinations();
        for(j=0, tmp2 = sizeof(tmp_arr); j<tmp2; j++) {
            if(!(char_arr = (string)env->query_direction(tmp_arr[j])))
                continue;
            if(env->query_door(char_arr)) continue;
            secondary += ({ tmp_arr[j] });
        }
    }
    secondary = distinct_array(secondary);
    for(i=0, tmp=sizeof(secondary); i<tmp; i++) {
        if(member_array(secondary[i], primary) != -1) continue;
        call_other(secondary[i], "???");
        if(!(env = find_object(secondary[i])) || env ==
		environment(this_player())) continue;
        do_yell(env, "You hear a voice yell from nearby.","", lang);
    }
    return 1;
}

void do_yell(object env, string who, string str, string lang) {
    object *inv;
    int i, j, tmp;
    mapping *yell_map;

    if(env->query_property("no shout")) return;
    inv = filter_array(all_inventory(env), "is_living", this_object());
    if(!str || str == "")
	yell_map = ({ ([ "msg" : "%^MAGENTA%^"+who,
	    "who" : inv ]) });
    else yell_map = yell_msg(inv, who, str, lang);
    i = sizeof(yell_map);
    while(i--) {
	if(!yell_map[i] || !mapp(yell_map[i])) continue;
	message("shout",yell_map[i]["msg"],yell_map[i]["who"]);
    }
    return;
}

int is_living(object ob) { return living(ob) && ob != this_player(); }

mapping *yell_msg(object *who_l, string who, string str, string lang) {
    int prof, i;
    mapping *ret;

    ret = allocate(11);
    i = sizeof(who_l);
    while(i--) {
	prof = who_l[i]->query_lang_prof(lang);
	if(!ret[prof]) {
	    ret[prof] = ([]);
	    switch(prof) {
	    case 0:
		ret[prof]["msg"] = "%^MAGENTA%^"+who+" yells something in "
		    +capitalize(lang)+".";
		break;
	    case 1..9:
		ret[prof]["msg"] = "%^MAGENTA%^"+who+" yells "
		    "in "+capitalize(lang)+": %^RESET%^"+
		    translate(str, prof);
		break;
	    case 10:
		ret[prof]["msg"] = "%^MAGENTA%^"+who+" yells "
		    "in "+capitalize(lang)+": %^RESET%^"+
		    str;
		break;
	    }
	}
	if(!ret[prof]["who"]) ret[prof]["who"] = ({});
	    ret[prof]["who"] += ({ who_l[i] });
    }
    return ret;
}

void help() {
    write("Syntax: <yell (in [language]) [message]>\n\n"
        "It yells a message to surrounding rooms.\n"
        "The sound does dissipate over distance, however.\n"
        "It also takes a bit of strength to do this.\n"
        "See also: say, whisper, emote, shout\n"
    );
}
