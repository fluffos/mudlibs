
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"光之幻境"NOR);
	set("long", HIG @LONG
伟大的众神的力量耀在这个森林中，整个森林闪耀在
一片金黄色的光辉中。在高大树林附近充满著荆棘与矮
灌木,  你发觉你已经迷路了。 高大的树木档住了阳光，你什么也看不见了。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_use", "use");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire",me)) return 0;
        if( arg=="fire" ) {
        remove_call_out("close");
        call_out("close", 15, this_object());
        message("vision","在火光下，你看清周围的情况了!!\n", me);
        set("long", @LONG
伟大的众神的力量耀在这个森林中，整个森林闪耀在
一片金黄色的光辉中。在高大树林附近充满著荆棘与矮
灌木,  你发觉你已经迷路了。 在火光下你看清了出路。
LONG
        );
	set("exits", ([
                "west" : __DIR__"dong1"+(random(5)+5),
		"east" : __DIR__"dong1"+(random(5)+5),
		"south" : __DIR__"dong1"+(random(5)+5),
                "north" : __DIR__"dong1"+(random(5)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong19",
                "west" : __DIR__"dong1"+(random(5)+5),
	]));
if (random(3)==1)
	set("exits", ([
		"eastnorth" : __DIR__"dong1"+(random(5)+5),
                "westsouth" : __DIR__"dong1"+(random(9)+1),
	]));




           if ( objectp(ob=present("fire", this_player())) )     {
            destruct(ob);
        return 1;
       }
        return notify_fail("你想用什么看情况？\n");
        }
}

void close(object room)
{
        message("vision","不一会儿，火熄灭了。\n", room);
        set("long", @LONG
伟大的众神的力量耀在这个森林中，整个森林闪耀在
一片金黄色的光辉中。在高大树林附近充满著荆棘与矮
灌木,  你发觉你已经迷路了。 
LONG
);
        room->delete("exits");
}