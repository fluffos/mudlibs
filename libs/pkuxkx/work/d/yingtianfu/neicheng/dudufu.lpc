//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"五军都督府"NOR);
        set("long", 
"这里五军都督府的衙门。\n"

        );
        set("exits", ([
                
              
                
                "enter" : __DIR__"dadudufu",
                "east" : __DIR__"yoududufu",
                "west" : __DIR__"zuodudufu",
                "northwest" : __DIR__"d_jianshi",
                "southwest" : __DIR__"d_zhihui",
                "northeast" : __DIR__"d_zhihui2",
                "southeast" : __DIR__"shuishi",
                "south" : __DIR__"changanjie2",
               
                
                
                
        ]));
        
        set("objects", ([
		__DIR__"npc/wujun-dudu" : 1,
	    ]));  
        setup();
   
}

void init()
{
    add_action("do_sign","sign");
}

int do_sign()
{
    object me=this_player();
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你根本不是大明官员，签名干嘛？\n");
        me->add_busy(2);
        return 1;
    }
    if (me->query("mingpin")>4)
    {
        tell_object(me,"四品以下大明官员，不须签名。\n");
        me->add_busy(2);
        return 1;
    }
    if (me->query("ming/pro"))
    {
        tell_object(me,"大人早先已决定从事"+me->query("ming/pro")+"职，无法再改变了。\n");
        me->add_busy(2);
        return 1;
    }
    else
    {
        me->set("ming/pro","武");
        tell_object(me,"都督府书记人员在一本花名册上记下你的大名，你正式成为大明武将一员。\n");
        me->add_busy(2);
        return 1;
    }
}
