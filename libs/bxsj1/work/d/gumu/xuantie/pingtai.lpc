// pingtai.c
// By River 98/08/28

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"平台"NOR);
    set("long", @LONG
你置身平台上面，四周树木苍翠，山气清佳。环顾左右，只见许多石块堆
著一个大坟。这坟背向山谷，俯仰空阔，单是这座剑冢便已占尽形势。仔细一
看大石上「剑冢」两个大字之旁，尚有两行字体较小的石刻（zi）。 
LONG
        );

    set("item_desc", ([
       "zi": HIY"「剑魔独孤求败既无敌於天下，乃埋剑於斯。」\n" +
                "\n「呜呼！群雄束手，长剑空利，不亦悲夫！」\n"NOR,
    ]));

    set("outdoors", "襄阳");

    setup();
}

void init()
{
        add_action("do_move", "move");
        add_action("do_move", "yi");
        add_action("do_tiao", ({"tiao", "zong"}));
}

int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( arg == "stone" || arg == "shikuai"){
        if ( me->query("max_neili") < 1500 && me->query_str() < 30 )
          return notify_fail("你费劲地想移动石块，但它纹丝不动。\n");
        if ( me->query_temp("weapon"))
          return notify_fail("你拿着兵刃怎么移动石块？\n");
           message_vision(YEL"$N深深地吸了口气，缓缓推动石块。\n\n"NOR,me);
           write(HIG"只见石块慢慢地移动，你把石块移开了！露出了剑冢的入口。\n"NOR);
           set("exits/enter", __DIR__"jianzhong");
           me->receive_damage("neili", 200);
	   me->receive_damage("jingli", 200); 
           remove_call_out("close");
           call_out("close", 5, this_object());
           return 1;
           }
          return notify_fail("你要移动什么？\n");
}

void close(object room)
{
        message("vision",HIY"石块慢慢移回了原位，又挡住了入口。\n"NOR, room);
        room->delete("exits/enter");
}

int do_tiao(string arg)
{ 
        object me;
        me = this_player();
        if ( !arg || arg != "down")
         return notify_fail ("你往哪里跳？");
        if ( arg == "down")
         message_vision(HIG"$N身形陡转，点击突石借力，纵下峭壁。\n"NOR,me);
         me->move(__DIR__"qiaobi");
         me->receive_damage("qi", 200);
	 me->receive_damage("jingli", 200);
         tell_room(environment(me),HIG + me->name() + "身形陡转，点击突石借力，从平台上跳了下来。\n"NOR, ({ me }));
         return 1;
} 
