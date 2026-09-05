// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"北面山"NOR);
        set("long", @LONG
北面山枕江而卧，由前、中、后三峰组成，形势险固。辛弃疾任镇江知府时，
曾作《永遇乐·京口北固亭怀古》及《南乡子·登京口北固亭有怀》等不朽诗篇。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "southdown" : __DIR__"northgate",  
                "northeast" : __DIR__"xiaosha",
                
]));
     
       
   setup();
}

int valid_leave(object me,string dir)
{  
	if (dir=="northeast")
    {
           return notify_fail("你只能远远看到一座小沙堆，可惜没有路过去。\n");
        
    }
	return ::valid_leave(me, dir);
}

void init()
{
    add_action("do_hua","hua");
}

int do_hua()
{
    object me=this_player();
    object pic,paper;
    if (!present("hu bi",me))
    {
        tell_object(me,"没有笔，你要怎么挥毫啊？\n");
        return 1;
    }
	if (!paper=present("xuan zhi",me))
	{
        tell_object(me,"没有纸，你总不能在风景区胡乱涂鸦吧？\n");
        return 1;
    }
    else
    {
        if (!me->query_temp("jn/step5b"))
        {
		
            pic=new(__DIR__"npc/obj/pic");
            pic->move(me);
			destruct(paper);
            tell_object(me,"你三笔两笔勾勒出了北面山的神韵，不由暗叹：我真是个天才！\n");
            return 1;
        }
        else
        {
            if (random(10)>3)
            {
                tell_object(me,"你三笔两笔勾勒出了北面山的神韵，却不太满意，这样的画好像不好去糊弄看守。\n");
                return 1;
            }
            else
            {
                pic=new(__DIR__"npc/obj/pic");
                pic->set("owner",me->query("id"));
                pic->move(me);
				destruct(paper);
                tell_object(me,"你认真挥毫，一气呵成，终于画出一幅满意的作品！\n");
                return 1;
            }
        }
    }
}