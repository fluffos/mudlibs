#include <std.h>
inherit OBJECT;


void create () {
    ::create();
    set_id( ({ "rose" }) );
    set_name("rose");
    set_short("a black rose");
     set_long("A delicate, dew covered black rose which was picked specifically for Dred by Aurora.  You may smell it's delicate scent but beware of the thorns!");
    set_weight(50);
    set("value", 25);
}
void init() {
   ::init();
     add_action("smell","smell");
}
int smell(){
   write("You close your eyes and smell the black rose.  This is a very beautiful rose and it was surely picked with a loved one in mind.");
   say(this_player()->query_cap_name()+" smells the beautiful black rose.",this_player());
return 1;
}
