// seeker 08/12/2000
#include <std.h>
mapping mudded, waiting; 
int abil();
void create()
{
    mudded = ([]);
    waiting = ([]);
}
int query_mudded(object ob) { return mudded[ob]; }
int cmd_mudarmor( string str )
{
    int i;
    object ob;
    if (!abil()) return notify_fail("What?\n");
    if (!str || str == "" )
	return notify_fail("Mudarmor who?\n");
    ob = present(str, environment(this_player()));
    if(!ob) {
	if(str == "me" || str == "myself") ob = this_player();
    }
    if  (!ob) return notify_fail("Mudarmor who?\n");
    if (waiting[ob] || mudded[ob]){
        write(capitalize(str)+" is already covered in mud.\n");
        return 1;
    }
    if (!present("mud", this_player()))
	return notify_fail("You need mud to do this task.\n");
    present("mud", this_player())->remove();
    i = (this_player()->query_skill("nature")/6)-(random(4)+ random(4));
    waiting[ob] = i;
    call_out("harden", 10, ob, i);
    this_player()->add_sp(-(i/10 + random(10)+ random(10)+ random(10)) );
    if (this_player()!=ob) {
	write("You cover "+ob->query_short()+" with wet mud.");
	message("info", this_player()->query_cap_name()+" covers "+ob->query_cap_name()+" with wet mud.", environment(ob), ({ ob, this_player() }) );  
	message("info", this_player()->query_cap_name()+" covers you in a layer of mud.", ob);
    } else
    {
	message("info", "You cover yourself with wet mud.", ob);
	message("info", this_player()->query_cap_name()+" covers "+this_player()->query_objective()+"self with wet mud.", environment(this_player()), this_player());
    }
    return 1;
}
int harden(object ob, int i, int def, int time)
{
    if (i < 50)  def = 2; else
    if (i < 100) def = 3; else
    if (i < 150) def = 4; else
    if (i < 200) def = 5; else
    if (i < 250) def = 6; else
    if (i < 300) def = 7; else
    if (i < 350) def = 8; else
    if (i < 400) def = 9; else
    if (i > 400) def = 10;
    time = (def*60)+random(def*5);
    mudded[ob] = waiting[ob];
    map_delete(waiting, ob);
    message("info", "\nThe mud hardens creating a thick layer of protection.", ob);
    message("info", "The mud on "+ob->query_cap_name()+" hardens.", environment(ob), ({ ob }) );
    ob->add_magic_protection( ({ 0, (def*3/2)+random(def), time}) );
    call_out("remove_prot", time, ob);
}
int remove_prot(object ob)
{
    message("info", "\nThe mud on you turns to dust and falls off.", ob);
    message("info", "The mud on "+ob->query_cap_name()+" turns to dust.", environment(ob), ob);
    map_delete(mudded, ob);
}
void help() {
    write("
Syntax: <mudarmor [living]>
A ranger can cover himself or another with mud creating a protective layer of mud.
");
}
int abil() {
 if (this_player()->query_level() < 10) return 0;
 if (this_player()->query_subclass()=="ranger") return 1; }
