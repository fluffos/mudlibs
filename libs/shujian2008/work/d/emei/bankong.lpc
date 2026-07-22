// bankong.c
// 半空中

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "半空中");
	set("long", 
HIW"你从一团团云雾中穿过，急速向下坠落。\n"NOR
);
	setup();
}
void init()
{ 
//    object me = this_player();
      add_action("do_action", "");                             
}
int do_action(string arg)
{
       string action = query_verb();

       switch (action) {
               case "look":
               case "exercise": 
               case "lian":
               case "tuna":       
               case "quit":
	       case "l" :
	       case "dazuo" : 
               case "practice":
               write(HIW"你从一团团云雾中穿过，急速向下坠落。\n\n"NOR);
                       return 1;
       }
       return 0;
}
