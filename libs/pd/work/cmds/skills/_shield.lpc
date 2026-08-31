// a dungeonware.net production 10:27 AM 9/4/2002
// coded for Primal Darkness by Stormbringer
 
#include <std.h>
inherit DAEMON;

string *subs = ({ "cleric", "blue", "white", "black" });
mapping waiting;
int spell();

void create()
{
    waiting = ([]);
}

int query_waiting(object ob) { return waiting[ob]; } 
int check_alignment(object ob);
 
string type() { return "defense"; }

int cmd_shield(string str) {
    object ob;
    int defense, def;
    int cost, amount, time;
 
    if (!spell()) {
        write("What?\n");
        return 1;
    }
    if (this_player()->query_busy()) return notify_fail("You are busy.");

    if(!str) {
        notify_fail("Shield whom?\n");
        return 0;
    }
    if(str == "me" || str == "myself") ob = this_player();
    else ob = present(str, environment(this_player()));
    if(!ob) {
        notify_fail("Where is "+capitalize(str)+"?\n");
        return 0;
    }
    if (waiting[ob]){
        if( ob == this_player() )
            write("You are already shielded.\n");
        else
            write(ob->query_cap_name() + " is already shielded.");
        return 1;
    }
    if(!living(ob)) {
        notify_fail("That is not alive!\n");
        return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("Something is blocking your concentration.\n");
        return 0;
    }
    if( (string)this_player()->query_class() == "cleric") {
        if(!check_alignment(this_player())) {
            notify_fail("You have betrayed the source of your powers.\n");
            return 0;
        }
    }
    defense = (int)this_player()->query_skill("magic defense");
    cost = defense*2/3 + random(defense/3);
    write("You mutter a prayer of protection.");
    say(this_player()->query_cap_name()+" mutters a spell of protection.", this_player());
    
    message("info", ob->query_cap_name() + " is briefly surrounded by " +
            "a %^YELLOW%^yellow glow%^RESET%^.", environment(this_player()), ob);
    message("info", "You are briefly surrounded by a %^YELLOW%^yellow glow%^RESET%^.", ob);
    
    
    if (defense < 40) def = 1; else
    if (defense < 80) def = 2; else
    if (defense < 120) def = 3; else
    if (defense < 160) def = 4; else
    if (defense >= 160) def = 5; 
    amount = (def)+(random(def))+1;
    time = (def*25)+random(def*3/2);
    waiting[ob] = time;
    ob->add_magic_protection( ({ 0, amount , time }));
    call_out("shield_off", time, ob);
    this_player()->set_magic_round(1);
    this_player()->add_skill_points("magic defense", random(defense/30));
    this_player()->add_skill_points("faith", random(defense/30));
    this_player()->add_alignment(random(defense/20));
    this_player()->add_mp(-cost);
    return 1;
}

void shield_off(object ob) {
    if( !ob || !waiting[ob] )
        return;
    
    message("info", "%^YELLOW%^Your magical shield wears off.%^RESET%^\n", ob);
    if( ob != this_player() )
        write("%^YELLOW%^Your magical shield around " + ob->query_cap_name() +
                " wore off.%^RESET%^\n");
    map_delete(waiting, ob);
}
 
int check_alignment(object ob) {
    if( (int)ob->query_alignment() > 200)
        return 1;
    if( (string)ob->query_class() == "cleric" && (int)ob->query_alignment() > 0)
        return 1;
    return 0;
}
 
void help() {
    write("Syntax: <shield [whom]>\n\nCreates a shield of magic around the target's body.\n");
}
int spell() {
  object tp = this_player();
  if (member_array(tp->query_subclass(), subs) != -1 && tp->query_skill("magic defense") >= 25)
    return 1;
  return 0;
}

