#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();
string who;
int times;
void last (object ob);
int biggie(string str);
void next(object ob);
void second(object ob);

string type() { return "other"; }

int cmd_snowball(string str) {
/*    if(this_player()->query_name() == "nightshade")
        return biggie(str);
*/
    if( !spell() )
        return notify_fail("What?\n");
    if (this_player()->query_mp() < 300)
        return notify_fail("Too low on magic power.\n");
    if( present("snowball 3", this_player()) )
        return notify_fail("You have enough snowballs.\n");
    if(who == this_player()->query_cap_name())
        times++;
    else {
        who = this_player()->query_cap_name();
        times = 0;
    }
/*    if(times == 40) {
        write("You have been struck down for your abuse of snowballs!");
        say(this_player()->query_cap_name()+" is struck down for their abuse of snowballs!");
        this_player()->die();
    }
*/
    write("A snowball appears in your hands.");
    new("/std/obj/snowball")->move(this_player());
    this_player()->add_mp(-600);
    if (!str) return 1;
    this_player()->force_me("throw snowball at "+str);
    return 1;
}

int biggie(string str) {
    object ob;

    if (!str) return notify_fail("Throw a snowball at who?\n");
    write("You call upon your massive snowball to hit "+str);
    ob = find_player(str);
    message("info", "A large object can be seen falling high in the sky...", environment(ob));
    call_out("next", 3, ob);
    return 1;
}

void next(object ob) {
    message("info", "As the massive sphere gets closer, it looks like a gigantic snowball!", environment(ob));
    call_out("second", 3, ob);
}

void second(object ob) {
    message("info", "It looks like the snowball is heading right towards "+ob->query_cap_name()+"!", environment(ob));
    call_out("last", 3, ob);
}

void last (object ob) {
    message("info", "The HUGE snowball smashes down on "+ob->query_cap_name()+", covering them in snow!!!", environment(ob));
}

void help() {
    write("
Syntax: <snowball [player]> or <snowball>
This magic spell allows the caster to create a snowball from nothing.
[player] is the person that will be hit with the snowball. Without an
argument, however, a snowball appears in your hands, for you to throw.
Spamming snowballs has a severe punishment, be careful with this spell,
death may consume you.
");
}

int spell() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 20) return 1;
}

