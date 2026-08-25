//      /bin/user/_yell.c
//      from the Nightmare mudlib
//      yells to adjacent rooms, good for muds who want to axe shout
//      created by Descartes of Borg 20 april 1993
 
#include <std.h>
 
inherit DAEMON;
 
void do_yell(object env, string prompt, string str);
 
int cmd_yell(string str) {
    string *primary, *secondary, *tmp_arr;
    string char_arr;
    int i, j, tmp, tmp2;
    object env;
 
    if(this_player()->query_ghost()) {
        write("You howl pitifully.\n");
        say("You hear the howling of a ghost.\n");
        return 1;
    }
 
    if((int)this_player()->query_sp()<5) {
        notify_fail("You are just too tired to yell now.\n");
        return 0;}
 
    if(!str) {
        notify_fail("Sore throat?\n");
        return 0;
    }
   
    this_player()->add_sp(-5);
    env = environment(this_player());
    if(env->query_property("no shout")) {
        notify_fail("Your voice does not travel far.\n");
        return 0;
    }
 
    
    log_file("shouts", this_player()->query_name()+" (yell): "+str+"\n");
    primary = (string *)env->query_destinations();
    message("my_action", "%^BLUE%^%^BOLD%^You yell: "+str, this_player());
    message("their_action", "%^BLUE%^%^BOLD%^"+this_player()->query_cap_name()+" yells: "+str, environment(this_player()), this_player());
    do_yell(env, "You hear a "+this_player()->query_gender()+" "+
      this_player()->query_race()+" yell: ", str);
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
        do_yell(env, "You hear a "+this_player()->query_gender()+" "+
          this_player()->query_race()+" yell: ", str);
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
        if(!(env = find_object(secondary[i]))) continue;
        do_yell(env, "You hear a voice yell from nearby.","");
    }
    return 1;
}
 
void do_yell(object env, string prompt, string str) {
    object *inv;
    int i, tmp;
 
    if(env == environment(this_player())) return;
    if(env->query_property("no shout")) return;
    for(i=0, tmp=(sizeof(inv=all_inventory(env))); i<tmp; i++) {
        if(!living(inv[i])) continue;
        if(inv[i] == this_player()) continue;
        if(inv[i]->query_ansi()) tell_object(inv[i], 
          (prompt)+str+"\n");
        else tell_object(inv[i], prompt+str+"\n");
    }
}
 
void help() {
    write("Syntax: <yell [message]>\n\n"
        "It yells a message to surrounding rooms.\n"
        "The sound does dissipate over distance, however.\n"
        "It also takes a bit of strength to do this.\n"
        "See also: say, whisper, emote, shout\n"
    );
}
