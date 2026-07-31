#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "冰山");
        set("long",@LONG
你正处在一座冰山之上。你极目远望，只见海天一线，周围一座坐冰山,
耳边只有海浪的拍打声,不知自己会飘向何处.
LONG);   
        set("no_clean_up", 0);
        setup();
     
}
int init ()
{
object ob=this_player();
ob->add("qi",-40);
ob->add("jing",-40);
}
