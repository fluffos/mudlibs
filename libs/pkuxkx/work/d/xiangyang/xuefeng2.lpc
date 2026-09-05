#include <room.h>
inherit ROOM;
void create()
{
	set("short", "雪峰山腰");
set("outdoors","xiangyang");
	set("long", @LONG
这里雪峰的半山腰,面前是陡峭的岩石,连手攀的地方都没,一阵寒风吹来,
你查点没掉下去!好险好险!忽然你发现石缝里似乎有一个小洞(dong).
LONG
	);
	set("exits", ([
		"down" : __DIR__"xuefeng1",
		"up" : __DIR__"xuefeng3",
	])); 
        set("item_desc", ([
                "dong" : 
        "这是一黑黝黝的小洞,向里望去,隐约有点点荧光。你\n" 
        "好奇心起,禁不住想钻进去。\n"
        ]) );
	setup();
	

}

void init()
{
        add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="dong") {
                message("vision",
		me->name() + "乍着胆子往一个小洞里钻去。\n",
                environment(me), ({me}) );
                  me->move("/d/xiangyang/bingdong");
                message("vision",
                me->name() + "从外面胆战心惊地钻了进来.\n",
                environment(me), me );
                return 1;
        }
}

