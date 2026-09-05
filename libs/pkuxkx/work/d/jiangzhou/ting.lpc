// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "八角亭");
        set("long", "这里一座装饰精美的八角亭，夏天时候，坐在这里可是无比惬意。\n");
        set("ori-long", "这里一座装饰精美的八角亭，夏天时候，坐在这里可是无比惬意。\n");
        set("exits", ([
               
               "west" : __DIR__"neiyuan",
               
               
                
        ]));
        /*set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));*/
        
        setup();
        call_out("change_night_desc",1);
}

void init()
{
    add_action("do_tan", "探");
    add_action("do_tan", "tan");
}

int change_night_desc()
{
    object ob=this_object();
    
    if (NATURE_D->get_current_day_phase() =="晚上" || NATURE_D->get_current_day_phase() =="午夜")
    {
        ob->set("long",WHT"这里黑漆漆一片，如同鬼宅一样，还不时传来凄厉的惨叫声！\n"NOR);
        ob->set("quest",1);
    }
    else
    {
        ob->set("long",ob->query("ori-long"));
        ob->delete("quest");
    }
    remove_call_out("change_night_desc");
    call_out("change_night_desc",60);
    return 1;
}

int finish(object me)
{
    tell_object(me,"既然找到元凶，快去把这只米袋交给温老爷，让他放心吧。\n");
    return 1;
}

int do_tan()
{
    object ob=this_object();
    object me=this_player();
    object sword,midai;
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着呢！\n");
        }
    if (!me->query_temp("jn/step7c"))
    {
        tell_object(me,"人家家的庭院，你想干嘛？\n");
        return 1;
    }
    if (me->query_temp("jn/step7d"))
    {
        tell_object(me,"既然找到元凶，快去回报温老爷吧。\n");
        return 1;
    }
    if (!ob->query("quest"))
    {
        tell_object(me,"朗朗乾坤之下，鬼魅怎能横行？等稍晚点再来吧。\n");
        return 1;
    }
    if (!present("taomu jian",me))
    {
        tell_object(me,"没有桃木剑，你总觉得驱鬼缺了点气势。\n");
        return 1;
    }
    sword=present("taomu jian",me);
    if (!sword->query("equipped"))
    {
        tell_object(me,"桃木剑不只是驱鬼时候的摆设！\n");
        return 1;
    }
    message_vision("$N在仔细地观察着八角亭里的动静。",me);
    me->add_busy(1+random(2));
    if (random(10)>7)
    {
        tell_object(me,"你突然发现所谓人影竟是一只大老鼠在拖着一只米袋子。\n");
        tell_object(me,"所谓鬼音都是米袋和地面摩擦发出的声响。\n");
        message_vision("$N上前赶走了大老鼠，捡起了米袋。\n",me);
        midai=new("/d/jiangzhou/obj/bag");
        midai->set("owner",me->query("id"));
        midai->move(me);
        me->delete_temp("jn/step7c");
        me->set_temp("jn/step7d",1);
        call_out("finish",1,me);
        return 1;
    }
    else
    {
        tell_object(me,"似乎没有任何异常。\n");
        return 1;
    }
}

