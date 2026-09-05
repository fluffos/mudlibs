// Room: /d/diaoyudao/diaoyutai.c 钓鱼台
// hongdou 98.09.20
// modified by iszt@pkuxkx, 2007-01-30, 钓鱼效率修改

#include <ansi.h>
inherit ROOM;

void init()
{
        add_action("do_diao", "diao");
}

void create()
{
        set("short", "钓鱼台");
        set("long", @LONG
这里就是钓鱼台，当年韦小宝落难此岛，烦闷时常来这里钓鱼(diao)。你站
在礁石上，远眺碧蓝的大海(hai)，迎着海风，感到心旷神怡。从台上向下看，
也就三人多高，跳下去应该没问题。
LONG
        );

        set("item_desc", ([
               "hai" : "你望着海面，有点昏昏欲睡，不犹得胡思乱想：“海龙王的女儿到底美不美丽？”\n",
         ]));


        set("exits", ([
                "down" : __DIR__"jiaoshi",
                ]));

        set("outdoors", "diaoyudao");
        setup();
}

int do_diao(string arg)
{
        object me = this_player();
        object ob;
        int i;
        int times;
        if (!(ob = present("yu gan", this_player())))
                return notify_fail("你没有好用的渔竿，拿什么钓鱼？\n");

	if(!arg || !sscanf(arg, "%d", times))
                return notify_fail("你要用多少精神来钓鱼？diao <数值>\n");

        if(!times)
                times = 1;

        if ((int)me->query("jing") < times)
                return notify_fail("你现在腰酸腿疼，怎么还能静下心来钓鱼呢？\n");

        i = me->query_skill("force");
//      if(!(me->query_temp("钓"))) me->set_temp("钓",i);

	message_vision(CYN"$N坐在石上静下心来，开始钓鱼。\n"NOR, me);

        if ((int)me->query_skill("force", 1) >= 50
                && (int)me->query_skill("force", 1) <= 180)
        {
                me->receive_damage("jing", times);
//              me->receive_damage("qi",15);
//              me->add_temp("钓",-1);
                if ( random(2) == 0 )
                {
                        me->improve_skill("force", (me->query_int()+10) * times / 30);
                        tell_object(me, HIC"你只觉得体内的气息不断地翻滚，似乎内功修为有所增加。\n"NOR);
                }
                if ( random(14) == 1 )
                {
                        me->add("max_jingli", times/100);
                        tell_object(me,HIM"你感到精气不断上涌直至膻中，似乎精力修为有所增加。\n"NOR);
                }
//              if (me->query_temp("钓")==0)
//              {
//                      tell_object(me,HIY"\n由于你用力过猛，渔竿断为两截，掉进了大海。\n"NOR);
//                      destruct(ob);
//                      return 1;
//              }
        }

	me->start_busy(random(2));

        return 1;
}

