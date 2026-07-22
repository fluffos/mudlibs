// /u/jpei/thd/kefang.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","客房");
        set("long",@LONG
这是招待客人住宿的房间。室内陈设精雅，两床相对，枕衾雅洁。
LONG
);
        set("exits",([
                "west" : __DIR__"jicui",
        ]) );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        setup();
}

void init()
{       
        object me = this_player();
        int lvl,lvl1,lvl2;
        lvl = me->query_skill("qimen-bagua", 1);
        lvl1 = me->query_skill("bihai-chaosheng", 1);
        if (lvl > 200 && !me->query("cut/thd")){
                lvl2 = (lvl - 200)/ 4;
                me->set_skill("qimen-bagua", 200);
                me->set_skill("bihai-chaosheng", lvl1 + lvl2);
                me->set("cut/thd", lvl2 * 4);
                write(HIG "系统已将您多余的「奇门八卦」转换为「碧海潮生功」。\n" NOR);
        }
}
