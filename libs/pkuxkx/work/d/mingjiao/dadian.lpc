#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "明教大殿");
        set("long", @LONG 
这里是光明顶大殿，是明教会客的地点。
    走进这里，突感一阵肃穆之意，大殿中十分空旷，殿顶高悬八盏
金灯，两旁是精壮佩剑武士剑气森严逼人。正中设一宝座，前有一雕
花檀木案，案头供明教圣火令(ling)六枚。宝座后立有一扇玉屏，屏
中所画正是明教圣火图，烈焰直逼日月。宝座上端坐一人，着布衣而
显高贵，含笑不怒而自威，正是明教教主张无忌。
LONG );
        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"zoulang",
                "north" : __DIR__"houhuayuan1",
 ]));
        set("objects", ([
                CLASS_D("mingjiao") + "/zhang" : 1,
 ]));
        setup();
//      replace_program(ROOM);
   "/clone/board/mj_b"->foo();
}

void init()
{
    add_action("do_enter","enter");
}

int do_enter()
{
    object me=this_player();
    object ob=this_object();
    object nextdoor=load_object(__DIR__"fireroom");
    if (me->query_temp("mingjiao/tasks/taskno")!=1)
    {
        return notify_fail(RED"非狮王许可，圣火坛不得进入！\n"NOR);
    }
    if (me->is_busy()||me->is_fighting())
    {
        return notify_fail("你正忙着呢。\n");
    }
    else
    {
        if (nextdoor)
        {
        
            tell_room(ob,me->query("name")+"闪身进入了圣火坛。\n");
            me->move(nextdoor);
            tell_room(nextdoor,me->query("name")+"走了进来。\n");
            return 1;
        }
        else
        {
            tell_object(me,"似乎什么东西挡住了你。\n");
            return 1;
        }
    }
}