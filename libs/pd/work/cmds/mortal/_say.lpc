//      /bin/user/_say.c
//      from the Nightmare Mudlib
//      the say command
//      created by Descartes of Borg 930818

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_say(string str) {
  object *ob, *ignoring;
  string type;
  int i;

    if(this_player()->query_ghost()) {
        message("emote", "You howl pitifully.\n", this_player());
        message("emote", "You hear a pitiful howl.\n", environment(this_player()),
          ({ this_player() }));
        return 1;

    }
    if(!str || str == "") {
        notify_fail("You mutter to yourself.\n");
        return 0;
    }
    if(this_player()->query("bear") && !wizardp(this_player())) {
        message("emote", "You growl like a bear.", this_player() );
        message("emote", this_player()->query_cap_name()+" growls like a bear.",
        environment(this_player()), this_player() );
        return 1;
    }
    if(str[sizeof(str)-1] == '!')
        type = "exclaims";
    else if(str[sizeof(str)-1] == '?')
        type = "asks";
    else
        type = "says";
  str = CENSOR_D->censor(this_player(), "say", str);

    LAST_D->add_say(this_player()->query_name(),  "%^RESET%^%^CYAN%^You "+type[0..(sizeof(type)-2)]+":%^RESET%^ "+str);
    if(this_player()->is_player())
      "/cmds/system/_intercept"->global("say", "%^RESET%^%^CYAN%^"+ (string)previous_object()->query_cap_name()+" "+type+":%^RESET%^ "+str);

    ob = all_inventory(environment(this_player()));
    i = sizeof(ob);
    ignoring = ({});
    while(i--)
     {
     if (ob[i]!= this_player() ) {
      if(ob[i]->query_ignoring(this_player()->query_name()))
        ignoring += ({ob[i]});
      else
        LAST_D->add_say(ob[i]->query_name(), "%^RESET%^%^CYAN%^"+ (string)previous_object()->query_cap_name()+" "+type+":%^RESET%^ "+str);
       }
     }

    ignoring += ({ this_player() });

    message("say", "%^RESET%^%^CYAN%^"
                    "You "+type[0..(sizeof(type)-2)]+":%^RESET%^ "+str+"", this_player());

    message("say", "%^RESET%^%^CYAN%^" + (string)previous_object()->query_cap_name()+" "+type+":%^RESET%^ "+str+"", environment(this_player()), ignoring);

    return 1;
}

void help() {
    write("Syntax: <say [message]>\n\n"
      "Sends out a message to everyone in the room notifying them that "
      "you said it."
      "\n\nSee also: tell, whisper, shout, yell, class, emote"
    );
}
