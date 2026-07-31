// shiyao.c 石窟
// By River 99.5.25
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short",HIW"石窟"NOR);
        set("long",@LONG
你转过二个弯后，眼前突然亮光耀目。这是一个天然生成的石窟，深不见
尽头，顶上有个圆径丈许的大孔，日光从孔中透射进来，只是那大孔离地一百
馀丈，这石窟深处地底，纵在窟中大声呼叫，上面有人经过也未必听见。抬头
可以看见高处石壁上凹凹凸凸，不似底下的滑溜。石窟中日光所及处生长了不
少大枣树(tree)。
LONG
);

        set("item_desc",([
             "tree":"这是一颗枣树，树上枝叶茂盛，长满了枣子。\n",
             "zao":"枣子一颗颗挂在树上，看上去很诱人，使人忍不住想去摘下来。\n",
        ]));

        set("outdoors","绝情谷");

        set("exits",([
             "east":__DIR__"cave3",
        ]));

        set("objects",([
                __DIR__"npc/qqchi":1,
        ]));
          
        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_climb", "pa");
        add_action("do_zhai","zhai");
        add_action("do_cut", "bo");
        add_action("do_cuo", "cuo");
        add_action("do_zhe","zhe");
}

int do_zhai(string arg)
{
        object me = this_player();
        if (arg != "zao" || !arg) return 0;
        tell_object(me,"你伸手去摘树上的枣子，发现手臂需要再长几十尺才行！\n");
        return 1;
}

int do_climb(string arg)
{
        object me,*ob;
        int i;
        me = this_player();
        if (! arg || arg != "shibi")
                return notify_fail("你要往哪里爬？\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        ob = deep_inventory(me);
        i = sizeof(ob);
        while (i--)
        if (ob[i]->is_character())
                return notify_fail("你身上背负一个人，无法轻松爬上去。\n");
        message("vison", me->name() + "屏住呼吸，纵上石壁，一路向上攀援。\n",environment(me), ({me}));
        tell_object(me,HIW"\n你屏住呼吸，纵上石壁，一路向上攀援。\n\n"NOR);
        me->move(__DIR__"shibi");
        tell_room(environment(me), me->name() + "从下面的"HIW"石窟"NOR"攀爬上来。\n", ({ me }));
        return 1;
}

int do_cut(string arg)
{
        object me = this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if (!arg || arg != "shupi")
                return notify_fail("你要剥什么？\n");
        if (present("shupi suo", me))
                return notify_fail("你已经有树皮索了，不需要再剥树皮了。\n");
        if(me->query_temp("jqg/fu"))
                return notify_fail("你已经将绳索一端缚在树干中间，不再需要树皮了。\n");
        message("vison", me->name() + "费劲地从枣树上剥下树皮。\n",environment(me), ({me}));
        tell_object(me,"你费劲地从枣树上剥下树皮。\n");
        me->add_temp("jqg/bo", 1);
        return 1;
}

int do_cuo(string arg)
{
        object me = this_player();
        if(!me->query_temp("jqg/bo")) return 0;
        if (me->is_busy() || me->is_fighting())
                  return notify_fail("你正忙着哪！\n");
        if(! arg || arg != "shupi")
                  return notify_fail("你要搓什么? \n");
        if((int)me->query_temp("jqg/bo") < 8)
                  return notify_fail("这点树皮还不够搓成足够长的索子能攀上去。\n");       
        message("vision", me->name() + "费尽了力气，才把树皮搓成一条极长的索子。\n", environment(me),({me}));
        tell_object(me,"你把树皮搓绞成索，费尽了力气，才把树皮搓成一条极长的索子。\n");
        me->delete_temp("jqg/bo");
        new(__DIR__"obj/changsuo")->move(me);
        me->start_busy(1);
        return 1;
}

int do_zhe(string arg)
{
        object me = this_player();
        if(! arg || arg !="shugan")
                return notify_fail("你要折什么？\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if (present("zao shugan", me))
                return notify_fail("你不是已经有树干了么？\n");
        message("vision", me->name() + "折下一根枣树干。\n",environment(me), ({me}));
        tell_object(me,"你折下一根枣树的枝干，长约一丈五尺。\n");
        new(__DIR__"obj/shuzhi")->move(me);
        me->start_busy(1);
        return 1;
}
