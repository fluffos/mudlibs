//shufang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/suzhou/npc/lchj.h";//连城诀
void create()
{
        set("short", "书房");
        set("long", @LONG
这里是老馆主的书房，但馆主已经很久没来这里了。到是五弟子卜垣经常
来这里，顺便指导一些喜欢读书的小孩们。书房周围的书架上整整齐齐地堆放
着很多书籍。正对大门的那边墙上写了几个醒目的大字（dazi）。
LONG
        );
        set("item_desc", ([
		"dazi" : "
    ※※※※※※※※※※※※※※※※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※　                    ※※※※
    ※※※※ 　 　少壮不努力，　　※※※※
    ※※※※　                    ※※※※
    ※※※※　　　　　　　　　　  ※※※※
    ※※※※　                    ※※※※
    ※※※※ 　 　老大徒悲伤。  　※※※※
    ※※※※　                    ※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※※※※※※※※※※※※※※※※\n" ,
 
	]));

        set("exits", ([
                "south" : __DIR__"zoulang6",
        ]));

        set("objects", ([
                __DIR__"npc/dizi5" : 1,
        ]) );
        
        setup();

}
void init()
{
	add_action("do_search", ({"search","xunzhao"}));
}
int do_search(string arg)
{
	object me = this_player();
	object book;
	if(!me->query_temp(QUESTDIR2+"askxieyang" ))
		return 0;	
	if( arg == "book" || arg == "tangshi xuanji" || arg=="唐诗选辑")
  {       
		message_vision(HIY"\n$N从书架开始寻找唐诗选辑.....\n"NOR, me);
                book=new("/d/wuguan/obj/tangshixuanji");
 
			message_vision(HIC"$N随手拨开书架上的一堆乱书。\n$N发现唐诗选辑竟然很明显混在其中。\n"NOR, me);
			book->set("owner",me->query("id"));
			book->move(me);
			me->delete_temp("quest/busy");//
			me->delete_temp(QUESTDIR);
			me->start_busy(1);
			me->set(QUESTDIR2+"over",1);
			me->set(QUESTDIR+"time",time());
			me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 
			message_vision(HIC"$N急忙收拾好书籍，偷偷离开武馆。\n"NOR, me);
			me->move("/d/xiangyang/damen");
		return 1;
	}
	return 0;
}
int valid_leave(object me, string dir)
{
        me->set_temp("mark/literate", 0);
        return 1;
}
