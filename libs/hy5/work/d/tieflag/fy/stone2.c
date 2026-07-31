 // Tie@fengyun
#include <room.h> 
inherit ROOM;
void create()
{
        set("short", "石巷尽头");
        set("long", @LONG
石巷不深，很快到了尽头，一堵高墙挡住去路。墙上有道窄门，墙角有一狗洞，
一条脏稀稀的小河沟从狗洞中流出，时而不时的，一条条浸满血水的绷带从狗洞中
流出，散发出腐臭的气味。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone1",
  "north" : __DIR__"sroom",
])); 
        set("objects", ([
                __DIR__"npc/newsman" : 1,
        ]));
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",20);
        set("coor/z",0);
        setup(); 
        create_door("north", "木门", "south", DOOR_CLOSED); 
} 
// this code work only if npc cannot be arrested.
int invalid_leave(object me)
{
        object ob;
        if(  me->query_temp("answer_questions") <= 3 ) 
        {
                me->delete_temp("score");
                me->delete_temp("answer_questions");
                me->delete_temp("num_question");
                me->delete_temp("in_ask");
                if(ob=present("news man", this_object()))
                {
                        ob->set("in_test",0);
                }
        }
        return 0;
}       
