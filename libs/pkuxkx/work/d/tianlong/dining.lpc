// /d/dalicheng/dining.c
#include <ansi.h>
inherit ROOM;
string* names=({
	"/d/shaolin/obj/mala-doufu",
	"/d/shaolin/obj/bocai-fentiao",
	"/d/shaolin/obj/shanhu-baicai",
	"/d/shaolin/obj/liuli-qiezi",
        }); 

void create()
{
        set("short", "饭厅");
        set("long", @LONG
这里是招待客人的饭厅，桌子上有一些素菜，要是饿了就坐下来吃点吧？
LONG);
        set("exits", ([ /* sizeof() == 2*/
"west" : __DIR__"yuan",
]) );
	set("objects",([
"/d/pker/npc/sunquan":1,
		"/d/shaolin/obj/qingshui-hulu":2,
		names[random(sizeof(names))]:1,
		names[random(sizeof(names))]:1,
		]));
	setup();
}

void init()
{
    add_action("do_bangchu","bangchu");
}

int finish(object me)
{
    me->delete_temp("帮厨");
    message_vision(HIG"$N擦擦手，厨房的杂务全做完了。\n"NOR,me);
    return 1;
}

int do_bangchu()
{
    object me=this_player();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("family/family_name")!="天龙寺")
    {
        tell_object(me,"本寺不需要外人帮手。\n");
        return 1;
    }
    if (NATURE_D->get_current_day_phase()!="晌午"&&NATURE_D->get_current_day_phase()!="傍晚")
    {
        tell_object(me,"现在不是饭点，厨房不需要人帮忙。\n");
        return 1;
    }
    if (me->query_temp("帮厨"))
    {
        tell_object(me,"你正在厨房帮忙啊。\n");
        return 1;
    }
	if (me->query_temp("tlnewbiejob/newbie/bangchu")==2)
	{
		tell_object(me,"你已经完成了帮厨的工作。\n");
		return 1;
	}
    if (NATURE_D->get_current_day_phase()=="晌午"&&me->query("combat_exp")<10000)
    {
        if (me->query_temp("tlnewbiejob/newbie/bangchu")=="傍晚")
        {
            me->set_temp("tlnewbiejob/newbie/bangchu",2);
        }
        else
        {
            me->set_temp("tlnewbiejob/newbie/bangchu","晌午");
        }
        
    }
    if (NATURE_D->get_current_day_phase()=="傍晚"&&me->query("combat_exp")<10000)
    {
        if (me->query_temp("tlnewbiejob/newbie/bangchu")=="晌午")
        {
            me->set_temp("tlnewbiejob/newbie/bangchu",2);
        }
        else
        {
            me->set_temp("tlnewbiejob/newbie/bangchu","傍晚");
        }
        
    }
    message_vision("$N卷起袖子，开始在厨房帮忙。\n",me);
    me->add_busy(4);
    me->set_temp("帮厨",1);
    call_out("finish",4,me);
    return 1;
}