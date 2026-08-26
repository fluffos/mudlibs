#include <mudlib.h>

inherit OBJECT ;
void init(){
add_action("eat","eat");
}

int eat(string str){
if(!str || str != "mushrooms") return 0;
write("You plop the shrooms in your mouth.\n");
say(this_player()->query("cap_name") + " nibbles on some purple mushrooms.\n");
this_object()->remove();
call_out("doeffect",3);
}
void doeffect(){
write("You feel strange and light on your feet...\n");
call_out("do2",2);
}
void do2(){
write("%^RED%^*%^YELLOW%^*%^BLUE%^*%^GREEN%^*%^RED%^*%^YELLOW%^*%^BLUE%^*%^GREEN%^*%^RESET%^");
write("You begin to see funky colors!\n");
}

void create() {
set("id", ({ "shrooms", "mushrooms", "purple mushrooms" }) );
set("short","a cluster of purple mushrooms");
set("long","A small cluster of purple colored shrooms. I wonder what\n"+
"happends when you eat them...\n");
set ("name", "shrooms");
}
