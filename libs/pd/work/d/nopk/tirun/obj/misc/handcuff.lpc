// - seeker -

#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({ "hand cuffs" }) );
   set_name("hand cuffs");
   set_short("Hand-cuffs");
    set_long("Keep you from going anywhere");
}
int free_me()
{
 write("You have served your sentence and are free to go.");
 this_player()->set_pk_flag(0);
 this_object()->remove();
 destruct(this_object());
 
}
void init()
{
 ::init();
 call_out("free_me", 480);
 add_action("filter", "");
}

int filter(string str)
{
/*
 if (query_verb()=="freemee") 
   {
    write("the cuffs dissapear");
    this_object()->remove();
    return 1;
   }
*/
 write("You are not able to move or do anything while imprisoned.");
 return 1;
}

int query_auto_load() { return 1; }
