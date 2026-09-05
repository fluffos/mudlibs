//树林
//for xiakedao
//modified by aiai 98/10/27
#include <ansi.h>

inherit ROOM;

string look_path();

void create()
{
	set ("short", "树林");
	set ("long", @LONG

    树林中草木繁多，遍树叶繁茂，密密麻麻把天都遮住了。
在密林深处，隐约现出一条小路(path)，似乎极不引人注意。
LONG );

        set("outdoors", "xiakedao");

	set("no_sleep_room",1);

	set("exits", ([
                "north" : __DIR__"shulin4",
		"south" : __DIR__"shulin5",
		"east"  : __DIR__"shulin5",
		"west"  : __DIR__"shulin6",
	]));
	set("item_desc",([
		"path" : ( : look_path : ),
	]));

	setup();
}
void init()
{
//         add_action("do_southeast", "southeast");
}

string look_path()
{
    object me;
    me = this_player();
    me->set_temp("小路/看",1);
    return "这是一条通往东南方向的小路，不过已经被封死，过不去了。\n";

}

int do_southeast()
{
        object me;
        me = this_player();
        if( me->query_temp("小路/看") ) {
                message("vision",me->name() + "向东南的小路走去。\n",
                environment(me), ({me}) );
                me->move(__DIR__"hillpath1");
                message("vision",me->name() + "走向东南的小路。\n",
                environment(me), ({me}) );
                return 1;
        }
        else {
                write("那条小路似乎没有尽头。\n");
                return 1;
        }

}
int valid_leave(object me, string dir)
{
        if( me->query_temp("小路/看") && dir == "southeast") {
        message_vision("$N向东南的小路走去。\n", me);
                me->move(__DIR__"hillpath1");
              tell_object(me,"你走向东南的小路。\n");
       return ::valid_leave(me, dir);
             }
    return ::valid_leave(me, dir);
} 
