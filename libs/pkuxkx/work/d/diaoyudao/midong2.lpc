// Room: /d/diaoyudao/midong2.c 密洞
// hongdou 98.09.20

#include <ansi.h>
inherit ROOM;

void init()
{
	add_action("do_search", "search");
}

void create()
{
	set("short", "密洞");
	set("long", @LONG
你继续向洞里走，里面豁然开朗，东边洞壁有许多小孔透进亮
光，洞里显得不是那么昏暗了。这里的地上垫着厚厚的稻草，上面
铺着各种兽皮，看来是睡觉的床铺(bed) 。旁边有一个大箱子，不
知里面有什么。
LONG
);

	set("exits", ([
                 "south" : __DIR__"midong1",
//		 "out" : __DIR__"dongkou",
            ]));
	set("item_desc", ([
             "bed": "床铺是由稻草和兽皮铺成，搜寻(search)一下看看还有什么？\n"
	]) );
	set("objects", ([
                __DIR__"npc/obj/largebox" : 1,
        ]));
		
	setup();
}

int do_search(string arg)
{
        object me = this_player();
	object ob;
	if( !arg || arg!="bed" ) 
	{
	     if ( !arg ) return notify_fail("你要搜索什么？\n");
             if ( arg!="bed" )  return notify_fail("那里不能搜索!\n"); 
        }
	
	if (arg=="bed")
	{
	    if (me->query_temp("衣"))
		return notify_fail("床铺上已经没什么了，你还想找一件女人衣服吗？真变态！\n");
	    message_vision("\n$N在床铺上一通乱翻，除了一些兽皮，小儿衣服，
还有一件花花绿绿的女人衣服，你将女人衣服收了起来。\n",me);
	    ob=new("d/diaoyudao/npc/obj/girlcloth");
	    ob->move(me);
	    me->set_temp("衣",1);
	    return 1;
	}
}