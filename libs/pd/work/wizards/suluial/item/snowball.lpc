#include <std.h>


#define FREEZER "/d/standard/freezer"
 
inherit OBJECT;
 
void init() {
    ::init();
    add_action("throw", "throw");
}
 
void create() {
    ::create();
    set_short("a snowball");
    set_name("a snowball");
    set_id(({"snowball"}));
    set_long("This snowball is made from tightly packed snow.  "
      "You can throw it fellow adventurers if you wish.");
    set_weight(1);
    set_value(0);
}
 
int throw(string str) {
    string person;
    object ob;
    if(!str) return notify_fail("Throw snowball at who?\n");
    if(!sscanf(str, "snowball at %s", person)) 
	return notify_fail("Throw snowball at who?\n");
    if(!present(this_object(), this_player())) 
	return notify_fail("You arn't holding the snowball.\n");
    ob=find_living(person);
    if(!ob) return notify_fail("Throw snowball at who?\n");
    message("info", "You throw your snowball at "+
	capitalize(person)+".", this_player());
    tell_room(environment(this_player()), this_player()->query_cap_name()+
	" throws "+this_player()->query_possessive()+" snowball at "+
	capitalize(person)+".", ({this_player(), ob}));
        this_object()->move(FREEZER);
    call_out("hit", 3, ob, this_player());
    return 1;
}
 
void hit(object ob, object tp) {
    int i;

    if(!tp || !ob) return;
    i=random(20);
    if(i<3) {
        message("info", "You miss "+ob->query_cap_name()+" by a mile.", tp);
        message("info", "A snowball just wizzes by your ear.", ob);
        tell_room(environment(ob), "A snowball comes flying in the room.", 
	    ({tp, ob}));
        this_object()->move(environment(ob));
        return;
    }
    message("info", "You hit "+ob->query_cap_name()+" in the back of the head.",
	tp);
    message("info", "A snowball nails you in the head.", ob);
    tell_room(environment(ob), "A snowball wizzes into the room and hits "+
	ob->query_cap_name()+" in the back of the head.", ({tp, ob}));
    this_object()->move(ob);
    return;
}

