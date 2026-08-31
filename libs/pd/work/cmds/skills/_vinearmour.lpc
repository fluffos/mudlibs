#include <std.h>
mapping vineed, waiting; 
int spell();
void create()
{
    vineed = ([]);
    waiting = ([]);
}
int query_vineed(object ob) { return vineed[ob]; }
string type() { return "defense"; }
int cmd_vinearmour( string str )
{
    int i;
    object ob;
    if (!spell()) return notify_fail("What?\n");
    if (this_player()->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if (this_player()->query_busy())
        return notify_fail("You are busy.\n");
    if (environment(this_player())->query_property("no magic")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if (this_player()->query_mp() < 50) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if (!str || str == "" || !(ob = present(str, environment(this_player())))
      || str == "me" || str == "myself")
        ob = this_player();
    if (!ob)
        return notify_fail("VineArmour whom?\n");
    if ((waiting[ob] || vineed[ob]) && str)
        return notify_fail(capitalize(str)+" already has vine armour.\n");
    if (waiting[ob] || vineed[ob])
        return notify_fail("You already have vine armour.\n");
    i = this_player()->query_skill("magic defense");
    waiting[ob] = i;
    call_out("form", 10, ob, i);
    this_player()->add_mp(-(i + random(40)) );
    this_player()->set_magic_round(1);
    if (this_player()!=ob) {
        write("%^BOLD%^%^GREEN%^You grin as vines grow from the earth, wrapping tightly around "+ob->query_cap_name()+"!");
        message("info", "%^BOLD%^%^GREEN%^"+this_player()->query_cap_name()+" grins as thick vines grow from the earth and wrap "+ob->query_cap_name()+" tightly!", environment(ob), ({ ob, this_player() }) );  
        message("info", "%^BOLD%^%^GREEN%^"+this_player()->query_cap_name()+" grins as thick vines grow from the earth and wrap you tightly!", ob);
    } else {
        write("%^BOLD%^%^GREEN%^You grin as vines grow from the earth wrapping tightly around you!");
        message("info","%^BOLD%^%^GREEN%^"+this_player()->query_cap_name()+" grins as thick vines grow from the earth and wrap "+this_player()->query_objective()+" tightly!", environment(this_player()), this_player());
    }
    return 1;
}
int form(object ob, int i, int def, int time)
{
    if (!ob) return 0;
    if (i < 50)  def = 2; else
    if (i < 100) def = 3; else
    if (i < 150) def = 4; else
    if (i < 200) def = 5; else
    if (i < 260) def = 5; else
    if (i >= 250) def = 7;
    time = (def*50)+random(def*5);
    vineed[ob] = waiting[ob];
    map_delete(waiting, ob);
    message("info", "\n%^BOLD%^%^GREEN%^The Vines cover your body protecting you.", ob);
    message("info", "%^BOLD%^%^GREEN%^The Vines cover "+ob->query_cap_name()+" protecting them.",
      environment(ob), ({ ob }) );
    ob->add_magic_protection( ({ 0, (def)+(random(def))+1, time}) );
    call_out("remove_prot", time, ob);
}
int remove_prot(object ob)
{
    if(!ob) return 1;
    message("info", "\n%^RESET%^%^GREEN%^The vines blacken and turn to dust.", ob);
    message("info", "%^RESET%^%^GREEN%^The vines covering "+ob->query_cap_name()+" blacken and turn to dust.",
      environment(ob), ob);
    map_delete(vineed, ob);
}
void help() {
    write("
Syntax: <vinearmour [living]>
The caster calls upon vines to protect from combat damage.
");
}
int spell() {
   	if (this_player()->query_skill("nature") < 162) return 0;
 if (this_player()->query_subclass()=="druid") return 1; }
