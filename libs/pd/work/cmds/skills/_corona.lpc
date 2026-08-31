//      based off _gate.c

#include <std.h>

#define CORONA_PROP "corona_spell_data"

inherit DAEMON;


void help() {
  message("help",
    "Syntax: <corona [location]>\n"
    "        <corona mark [name]>\n"
    "        <corona unmark [name]>\n"
    "        <corona list>\n\n"
    "An advanced pyromancer spell. The caster opens a portal to "
    "the edge of the elemental plane of fire. Once there, "
    "he must travel through the plane and find the exit leading back out "
    "to the physical plane.\n\n"
    "%^BOLD%^%^RED%^Warning%^RESET%^: This is an EXTREMELY dangerous "
    "spell, and has been known to cause the deaths of not only those "
    "who cast it, but also anyone who enters the corona. The elemental "
    "plane of fire is very inhospitable to most life.",
    this_player());
}

string type() { return "conjuring"; }

int spell() {
    object tp = this_player();
    if (tp && tp->query_subclass() == "pyromancer" &&
        tp->query_skill("conjuring") >= 26*4 &&
        tp->query_skill("pyromancy") >= 26*6)
          return 1;
    return 0;
}

int cmd_corona(string str) {
    object tp;
    int i, fail;
    int total, times;
    string tmpwhit;
    string wh, *key, loc;
    mapping gat, oldgat;

    if (!spell())
        return 0;

    if(!str)
        return notify_fail("Open the corona to where?\n");

    gat = this_player()->query_property(CORONA_PROP) || ([]);
    if (!sizeof(gat) && sizeof(oldgat = this_player()->query_gate())) {
      gat = oldgat;
      this_player()->set_property(CORONA_PROP, gat);
      this_player()->set_gate( ([]) );
    }

    if (str=="list")
    {
        if (!sizeof(gat)) { write("You have not marked any locations."); return 1; }
        i = sizeof(gat);
        key = keys(gat);
        write("You have the following locations burned into your mind:");
        while(i--)
        {
            write("[\""+key[i]+"\"] : "+gat[key[i]]->query_short());
        }
        return 1;
    }
    sscanf(str, "%s %s", wh, loc);
    if (wh=="mark" || str=="mark")
    {
        if (sizeof(gat) >= 7)
        { 
            write("Your mind can only remember so many places.");
            return 1; 
        }
        if (sscanf(str, "%s %s", wh, loc) != 2)
        { 
            write("You need to specify a key to remember this location."); 
            return 1;
        }
        if (gat[loc])
        {
            write("You already have something marked at \""+loc+"\"");
            return 1;
        } 
        if (environment(this_player())->query_property("no teleport"))
            return notify_fail("You cannot mark this spot.\n");
        gat[loc] = file_name(environment(this_player()));
        this_player()->set_property(CORONA_PROP, gat);
        write("You remember \""+loc+"\" for "+environment(this_player())->query_short());

        return 1;
    }
    if (wh == "unmark" || str == "unmark") {
        if (sscanf(str, "%s %s", wh, loc) != 2) { 
            write("You need to specify the name of the location you want to unmark."); 
            return 1;
        }
        if (gat[loc]) {
            map_delete(gat, loc);
            this_player()->set_property(CORONA_PROP, gat);
            write("You have forgotten "+loc+".");
            return 1;
        } else {
            write("You do not know of such a place.");
            return 1;
        }
    }

    if (sscanf(str, "to %s", wh) != 1)
        wh = str;

    if((int)this_player()->query_mp() < 700)
        return notify_fail("Too low on magic power.\n");

    gat = this_player()->query_property(CORONA_PROP);

    if (environment(this_player())->query_property("no teleport")) {
      message("info","You cannot open a corona here.", this_player());
      return 1;
    }

    if (!gat || !(gat[wh]) || (fail && !wizardp(this_player())))    
    {
        write("You do not know of such a place.");
        return 1;
    }

    if (gat[wh]) tp = get_object(gat[wh]);
    if(!tp) { write("That location is not in existance."); return 1; }

    if (tp->query_property("no teleport")) {
      message("info", "Your spell fails.", this_player());
      return 1;
    }
    this_player()->set_magic_round();
    this_player()->add_mp(-(600 + random(250)));
    this_player()->add_skill_points("conjuring", random(40));
    this_player()->add_skill_points("pyromancy", random(40));

    total = this_player()->query_skill("conjuring");
    total += this_player()->query_skill("pyromancy");

    times = 11-((total-300)/40)+random(2)-random(2);
    if (times < 7) times=7;
    
    write("You close your eyes and concentrate.");
    say(this_player()->query_cap_name()+" closes "+this_player()->query_possessive()+
        " eyes and seems to concentrate.");
    message("info", "%^ORANGE%^A scalding wind begins to blow.%^RESET%^", ({tp, environment(this_player())}) );
    call_out("openPortal", 4, this_player(), tp, times);

    return 1;
}

int openPortal(object ob, object tp, int times)
{
  object portal;

    if (!ob || !tp) return 1;
    message("info", "%^BOLD%^%^RED%^A huge gaping corona of flame comes into existance.%^RESET%^",
            environment(ob) );
    portal = new("/cmds/skills/obj/corona_ob");
    portal->setup(times, file_name(tp));
    portal->move(environment(ob));
    return 1;
}
