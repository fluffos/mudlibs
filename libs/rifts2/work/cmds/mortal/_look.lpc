//      /bin/user/_look.c
//      from the Nightmare mudlib
//      the command to look at stuff so that you might see!
//      written by Descartes of Borg 16 january 1993
//      based on the _look.c from the TMI mudlib
 
#include <daemons.h>

#include <std.h>

inherit DAEMON;
 
int examine_object(string str);
void sky(string str);
void look_msg(object ob, string str);
 
int cmd_look(string str) {
        string tmp;
 
        if( stringp(str) ) {
            if(sscanf(str, "in %s", tmp) ==1 || sscanf(str, "at %s", tmp) == 1)
                return examine_object(tmp);
            else return examine_object(str);
        }
        this_player()->describe_current_room(1);
        return 1;
}
 
int examine_object(string str) {
    object ob;
 
    if(!str) return 0;
    ob = environment(this_player());
   if(functionp(ob->id(str))) {
    (*(function)ob->id(str))(str);
    return 1;
   }
    if(!ob->id(str) && (str == "sky" || str == "moon" || str == "sun")) {
      if(environment(this_player())->query_property("indoors")) {
        write("You cannot see that inside.");
        return 1;
      }
      else {
        sky(str);
        return 1;
      }
    }
    if(effective_light(this_player()) < 1) {
        write("It is too dark.");
        return 1;
    }
    if(total_light(this_player()) < 1) write("It is dark.");
    if(ob->id(str) && stringp(ob->query_long(str))) {
        look_msg(ob, str);
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
            write((string)ob->query_long(str));
        return 1;
    }
    ob = present(str, ob);
    if(ob) {
        look_msg(ob, str);
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
          write((string)ob->query_long(str));
          return 1;
    }
    ob = present(str, this_player());
    if(ob) {
        look_msg(ob, str);
        if(this_player()->query_ansi())
            write(ansi_str( (string)ob->query_long(str) ));
        else
          write((string)ob->query_long(str));
          return 1;
    }
    write("You do not notice that here.");
    return 1;
}
 
void look_msg(object ob, string str) {
    if((int)this_player()->query_invis()) return;
    if((int)this_player()->query_hiding() > 0) return;
    if( ob != this_player() )
    if(living(ob)) {
       say(this_player()->query_cap_name()+" looks over "+ob->query_cap_name()+
          "", ob);
        tell_object(ob, this_player()->query_cap_name() + " looks you over.");
    }
    else
       say(this_player()->query_cap_name() + " looks over the " + str + ".");
}
 
int help() {
  write("Command: look\nSyntax: look [at object]\n"+
        "If no object is specified this command makes you look "
        "around the room.  If an object is specified it lets you "
        "examine the object more closely.\n"
        "See also: describe, lines, ansi, autowrap, brief\n"
  );
  return 1;
}

void sky(string str) {
    string borg;
    int night, tmp;

    night = query_night();
    switch(str) {
        case "sky":
            if(night) {
                switch((int)EVENTS_D->query_week(time())) {
                    case 0:  borg = "You see a moonless night sky."; break;
                    case 1: borg = "The crescent moon hovers in the night sky."; break;
                    case 2: borg = "A full moon lights up the night sky."; break;
                    case 3: borg = "You see the sliver of a cresent moon in the sky."; break;
//                    default: "You see the edge of one moon and a second tiny satellite hovering in the sky."; break;
                }
            }
            else borg = "You see the sun up in the sky.";
            break;
        case "sun":
          if(!night) {
            tmp = (int)EVENTS_D->query_hour(time());
             if(tmp < 10) borg = "The sun hangs low in the eastern sky.";
            else if(tmp < 10) borg = "The sun is midway up in the eastern sky.";
            else if(tmp < 14) borg = "The sun is high up in the noon sky.";
            else if(tmp < 16) borg = "The sun is midway up in the western sky.";
            else borg = "The sun hangs low in the western sky.";
          }
          else borg = "What sun?";
          break;
        case "moon":
            switch((int)EVENTS_D->query_week(time())) {
            case 0: borg = "What moon?"; break;
            case 1: borg = "A crescent moon."; break;
            case 2: borg = "It is a full moon."; break;
            case 3: borg = "A tiny sliver of a crescent moon."; break;
            default: borg = "It looks like death!"; break;
            }
           break;
    }
    write(borg);
}
