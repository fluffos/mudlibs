/*    /daemon/chat.c
 *    from the Nightmare 3.2 Mudlib
 *    daemon to handle all mud chat channels
 *    created by Descartes of Borg 931220
 */
#define DEBUG(x) tell_object(find_player("descartes"), x)

#include <std.h>
#include <network.h>
#include <daemons.h>
#include <objects.h>

inherit DAEMON;

#define MAGENTA "%^MAGENTA%^"
#define RESET "%^RESET%^"

nosave private mapping channels;

int list_channel(string str);

void create() {
    string *chans;
    object *who;
    int i, j;

    daemon::create();
    set_no_clean(1);
    channels = ([]);
    i = sizeof(who = users());
    while(i--) {
        j = sizeof(chans = (string *)who[i]->query_channels());
        while(j--) {
            if(!channels[chans[j]]) channels[chans[j]] = ({});
            channels[chans[j]] = distinct_array(channels[chans[j]]+({who[i]}));
        }
    }
}

void add_user(string *chans) {
    object ob;
    int i;

    if(!userp(ob = previous_object())) return;
    i = sizeof(chans);
    while(i--) {
        if(!channels[chans[i]]) channels[chans[i]] = ({});
         channels[chans[i]] = distinct_array(channels[chans[i]]+({ob}));
    }
}

void remove_user(string *chans) {
    object ob;
    int i;

    if(!userp(ob = previous_object())) return;
    i = sizeof(chans);
    while(i--) {
        if(!channels[chans[i]]) continue;
        else channels[chans[i]] -= ({ ob });
        if(!sizeof(channels[chans[i]])) map_delete(channels, chans[i]);
    }
}

int do_chat(string verb, string str) {
    string msg;
    int emote;
    string name;

    if(verb == "list") return list_channel(str);
    if(!channels[verb]) {
        if(sscanf(verb, "%semote", verb)) emote = 1;
        else return 0;
        if(!channels[verb]) return 0;
    }
    if(member_array(this_player(), channels[verb]) == -1) return 0;
    if(!str) {
        this_player()->set_blocked(verb);
        return 1;
    }
    if((int)this_player()->query_blocked(verb)) {
        if((int)this_player()->query_blocked("all")) {
            message(verb, "You cannot chat while totally blocked.", this_player());
            return 1;
        }
        this_player()->set_blocked(verb);
    }
    if(verb == "admin" || verb=="cre") {
        if(!(name = (string)this_player()->query_CapName()))
          name = capitalize((string)this_player()->query_name());
    }
    else name=this_player()->query_cap_name();
    if(emote) msg = sprintf("%s<%s>%s %s %s", MAGENTA, verb, RESET,
      name, str);
    else msg = sprintf("%s %s<%s>%s %s", name, MAGENTA, verb, RESET, str);
    message(verb, msg, channels[verb]);
    if(member_array(verb, INTERMUD_CHANNELS) != -1){
      //SERVICES_D->send_gwizmsg(str, emote);
      SERVICES_D-> eventSendChannel(name, "imud_code", str, 0);
    }
    return 1;
}

void inter_channels(string who, string verb, string str, int emote) {
    string msg;

    if(!channels[verb] || base_name(previous_object()) != SERVICES_D) return;
    if(emote)
    msg = sprintf("%s<%s>%s %s %s", MAGENTA, verb, RESET, who, str);
    else msg = sprintf("%s %s<%s>%s %s", who, MAGENTA, verb, RESET, str);
    message(verb, msg, channels[verb]);
}

int list_channel(string str) {
    string list;
    int i;

    if(!channels[str]) return 0;
    if(member_array(this_player(), channels[str]) == -1) return 0;
    list = "";
    list = "Online: ";
    i =sizeof(channels[str]);
    while(i--) {
        if(!channels[str][i]) continue;
        if(hiddenp(channels[str][i]) || (int)channels[str][i]->query_invis() ||
          (int)channels[str][i]->query_blocked(str)) continue;
        list += "    "+(string)channels[str][i]->query_cap_name();
    }
    message("info", list, this_player());
    return 1;
}

