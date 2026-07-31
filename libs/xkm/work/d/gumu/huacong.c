// huacong.c by csy 98/12/29
#include <ansi.h>
inherit ROOM;

void delete_hexiu(object me, object arg);

void create()
{
          set("short",HIR"红花丛"NOR);
          set("long", @LONG
这丛红花排开来长达数丈，密密层层，奇香扑鼻，但见花丛有如一座大屏
风，红瓣绿枝，煞是好看，四下里树荫垂盖，便似天然结成的一座花房树屋。
四周都是一片清幽，只闻泉声鸟语，杳无人迹，确是个上好的练功所在。
LONG        );

          set("exits", ([
               "west" : __DIR__"guolin4",
               "south" : __DIR__"guolin5",
          ]));

          set("outdoors","古墓");
          set("no_fight", 1);
          setup();
}

void init()
{
        add_action("do_hexiu", "hexiu");
}

int do_hexiu(object arg)
{
        object me = this_player();
        object ob;
        mapping fam;
        int ynlvl;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
        if (!arg)
            return notify_fail("你要与谁和修内功？\n");
        if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
            return notify_fail("你不是古墓派传人，怎么能练古墓的内功？\n");
        if (!(ob = present(arg, this_object())))
            return notify_fail("这人现在不在这里！\n");
        if (me == ob)
            return notify_fail("你想玩双手互搏吗？\n");
        if (!living(ob))
            return notify_fail("你必须先把" + arg->name() + "弄醒。\n");
        if (!userp(ob))
            return notify_fail("你只能与玩家和修练功！\n");
         ynlvl = me->query_skill("yunu-xinjing",1);
         if ( ynlvl > 130 )
          return notify_fail("你已经不能从和修中得到帮助了！\n"); 
        if (ob->query_skill("yunu-xinjing", 1) < (ynlvl - 25) )
            return notify_fail("这人功夫与你相差太远，无法助你练功！\n");
        if (me->query("jing") < 30 || me->query("qi") < 30)
            return notify_fail("你太累了，还是先休息一会儿吧！\n");
        if (me->query_temp("gumu_hexiu") >= 1)
            return notify_fail("你现在正在与别人和修呢！\n");
         me->set_temp("gumu_hexiu", 1);
         tell_object(ob,me->name()+"端坐于你面前，欲与你和修玉女心经。\n");
         if (ob->query_temp("gumu_hexiu") < 1)
         return notify_fail("对方还没有要与你和修练功的意思！\n");
         message_vision(HIY"$N左臂透过花丛，与$n右掌相抵，二人各处花丛一边，解开衣衫，修习起来。\n"NOR,me, ob);
         me->start_busy(5);
         ob->start_busy(5);
         call_out("delete_hexiu",5, me, ob);
         return 1;
}

void delete_hexiu(object me, object ob)
{
        mapping my;
        if (!me || !ob) return;
        my = me->query_entire_dbase();

        me->delete_temp("gumu_hexiu");
        ob->delete_temp("gumu_hexiu");         
        if (my["potential"] < 1) {
         tell_object(me,"你的潜能消耗光了，结果什么也没有学到。\n");
         return;
         }

        my["potential"]--;
        message_vision(HIR"$N受到感应，立时运功为助，全身热气蒸腾，收获颇丰。\n"NOR,me);
        me->receive_damage("jing", 20+random(10));
        me->receive_damage("qi",  20+random(5) );
        me->improve_skill("yunu-xinjing", me->query_int()*( 2 + random(2)));        
        return;
}
