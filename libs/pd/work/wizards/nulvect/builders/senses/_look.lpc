//      /bin/user/_look.c
//      from the Nightmare mudlib
//      the command to look at stuff so that you might see!
//      written by Descartes of Borg 16 january 1993
//      based on the _look.c from the TMI mudlib

#include <daemons.h>
#include <std.h>

#define TOO_DARK_ROOM -2
#define TOO_DARK_ITEM -6

inherit SENSE_CMD;

string sky(string str);

int cmd_look(string str) {
    object tp=this_player();
    object env=environment(tp);
    object ob;
    string tmp, ll;
    string mymsg, yourmsg, theirmsg;
    int mine;
    int flag = 0;

    // these are only used when looking at details
    set_sense("item");
    set_verb("look at");
    set_default("");
    set_msg_failnotgt("You do not notice that here.");
    set_msg_failenvdef("You do not see anything here.");
    set_msg_failenv("You do not notice that here.");
    set_msg_failobdef("There are no special details on $O.");
    set_msg_failob("You do not see that on $O.");
    set_msg_totgt("$N looks you over.");
    set_msg_toenvdef("$N looks around.");
    set_msg_toenv("$N looks over $I.");
    set_msg_toenvown("$N looks over $P $R.");
    set_msg_toenvob("$N looks over $O.");

    if (stringp(str)) {
      if (str[0..2] == "at ") str = str[3..<1];
      if (sscanf(str, "%s of %s", tmp, tmp) == 2 || sscanf(str, "%s on %s", tmp, tmp) == 2 || sscanf(str, "%s's %s", tmp, tmp))
        return ::cmd(str);
      if (sscanf(str, "in %s", tmp))
        str = tmp;
      if (sscanf(str, "my %s", tmp)) {
        str = tmp;
        mine = 1;
      }
    }

/*
    if (tp->query_blind())
      mymsg = "You cannot see.";
*/
        
    // just looking in the room itself
    /* else */ if (!str || !sizeof(str)) {
      flag = 1;
      if (effective_light(tp) < TOO_DARK_ROOM)
        mymsg = "It is far too dark to see anything.";
      else
        tp->describe_current_room(1);
    }

    // something in the sky
    else if ((tmp = sky(str)) != "") {
      if (env->query_property("indoors")) {
        mymsg = "You cannot see that inside.";
      }
      else {
        mymsg = tmp;
        theirmsg = tp->query_cap_name()+" looks at "+definite_article(str)+".";
      }
    }

    // an object or living thing in player's inv or the room
    else if (ob = present(str, env) || ob = present(str, tp)) {

      // "look (at/in) my bag" prioritizes objects in your inventory,
      // otherwise objects in the room have priority
      if (mine && environment(ob) != tp && !(ob = present(str, tp)))
        mymsg = "You do not have that.";
      
      else if (effective_light(tp) < TOO_DARK_ITEM)
        mymsg = "It is too dark.";

      // objects
      else if (!living(ob)) {
        tmp = ob->query_long();
        if (ll = ob->query_long_more())
          tmp += "\n"+ll;
        if (ob->is_board()) {
          tp->more(explode(tmp, "\n"));
          theirmsg = tp->query_cap_name()+" looks over the "+ob->query_name()+".";
        }
        else {
          mymsg = tmp;
          theirmsg = tp->query_cap_name()+" looks over "+definite_article(ob->query_short())+".";
        }
      }

      // living things
      else {
        tmp = ob->query_long();
        if (ll = ob->query_long_more())
          tmp += "\n"+ll;
        mymsg = tmp;
        if (ob != tp)
          yourmsg = tp->query_cap_name()+" looks you over.";
        theirmsg = tp->query_cap_name()+" looks over "+ob->query_cap_name()+".";
      }

    }

    // something in room's set_items()
    else if (env->query_item(str) && !mine) {
      if (effective_light(tp) < TOO_DARK_ITEM)
        mymsg = "It is too dark.";
      else {
        /*
        mymsg = env->query_item(str);
        theirmsg = tp->query_cap_name()+" looks over "+definite_article(str)+".";
        */
        return ::cmd(str);
      }
    }


    // defaults
    else if (mine)
      mymsg = "You do not have that.";

    else
      mymsg = "You do not notice that here.";
        

    // send the messages
    
    if (sizeof(mymsg))
      message("look", mymsg, tp);

    if (!flag) {
      if (!tp->use_stealth("look")) {
        if (sizeof(yourmsg))
          message("look", yourmsg, ob);
        if (sizeof(theirmsg))
          message("look", theirmsg, env, ({ tp, ob }) );
      }
    }
    
    return 1;
}

void help() {
  message("help",
    "Syntax: look\n"
    "        look at [what]\n"
    "        look at [object]\n"
    "        look in [object]\n"
    "        look (at|in) my [object]\n"
    "        look at [person]\n"
    "        look at [what] (on|of) [object]\n"
    "        look at [what] (on|of) [person]\n"
    "        look at [person]'s [object]\n\n"
    "This command lets you look around the room or examine things more closely. "
    "Using 'my' looks only at objects you are carrying, otherwise "
    "things in the room take priority.\n\n"
    "See also: describe, lines, ansi, autowrap, brief",
    this_player() );
}

string sky(string str) {
    string borg;
    int night, tmp;

    night = query_night();
    switch(str) {
    case "sky":
        if(night) {
            switch((int)EVENTS_D->query_week(time())) {
            case 0:  borg = "%^BOLD%^%^BLACK%^You see a moonless night sky."; break;
            case 1: borg = "%^BLUE%^The crescent moon hovers in the night sky."; break;
            case 2: borg = "%^BOLD%^%^WHITE%^A full moon lights up the night sky."; break;
            case 3: borg = "%^BLUE%^You see the sliver of a cresent moon in the sky."; break;
            default: borg = "%^BOLD%^%^BLACK%^You see the edge of one moon and a "
                     "second tiny satellite hovering in the sky.";
            }
        }
        else borg = "%^YELLOW%^You see the sun up in the sky.";
        break;
    case "sun":
        if(!night) {
            tmp = (int)EVENTS_D->query_hour(time());
            if(tmp < 10) borg = "%^ORANGE%^The sun hangs low in the eastern sky.";
            else if(tmp < 10) borg = "%^YELLOW%^The sun is midway up in the eastern sky.";
            else if(tmp < 14) borg = "%^YELLOW%^The sun is high up in the noon sky.";
            else if(tmp < 16) borg = "%^YELLOW%^The sun is midway up in the western sky.";
            else borg = "%^ORANGE%^The sun hangs low in the western sky.";
        }
        else borg = "What sun?";
        break;
    case "moon":
      if (night) {
        switch((int)EVENTS_D->query_week(time())) {
        case 0: borg = "What moon?"; break;
        case 1: borg = "%^BLUE%^A crescent moon."; break;
        case 2: borg = "%^BOLD%^%^WHITE%^It is a full moon."; break;
        case 3: borg = "%^BLUE%^A tiny sliver of a crescent moon."; break;
        default: borg = "%^BOLD%^%^BLACK%^It looks like death!"; break;
        }
      }
      else borg = "What moon?";
      break;
    default:
        borg = "";
    }
    if (borg != "") borg += "%^RESET%^";

    return borg;
}

