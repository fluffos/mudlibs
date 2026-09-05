 // houhuayuan3.c.c
// by airy
inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是光明顶的后花园，种满了花草。几个小童正在浇花
北边有一个幽雅的小屋。地上长了许多覆盆子(zi)。
LONG
        );
        set("item_desc", ([
		"zi" : "覆盆子可以入药，你可以摘(zhai)下来。\n", 
	    ]));
        set("exits", ([ /* sizeof() == 1 */
  "west":__DIR__"houhuayuan1",
 "northdown":__DIR__"suishilu1",
]));
        set("outdoors", "mingjiao" );
        setup();
        replace_program(ROOM);
}

void init()
{ 
	add_action("do_zhai","zhai"); 
}

int do_zhai()
{
    object me=this_player();
    object gc;
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("覆盆子"))
    {
        return notify_fail("覆盆子已经被摘完了。\n");
    }
    me->set_temp("覆盆子",1);
    gc=new("/d/taishan/obj/fupengzi");
    gc->move(me);
    message_vision("$N摘下了一片覆盆子。\n",me);
    return 1;
}