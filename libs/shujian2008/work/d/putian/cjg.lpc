// Room: /d/putian/cjg.c 藏经阁
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "藏经阁");
        set("long", @LONG
这里是少林莆田别院的藏经阁，虽然不如嵩山本院的藏书数量多，也没有
本院藏经楼的名气响亮，但是也不愧为南方佛法的宝藏，莆田少林寺此处藏经
多以佛经典籍为主，间或藏有一些少林不传之绝技图谱。虽无本院广博，但占
其精练概要。这里到处都是密密麻麻，高及顶棚的大书架。
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"mf-dian",
        ]));

        set("objects",([
                CLASS_D("putian") + "/da-chi" : 1,
                __DIR__"npc/shami" : 2,
		"/d/shaolin/obj/wuji1" : 1,
		"/d/shaolin/obj/wuji2" : 1,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
        object ob;

        if ((ob = present("dachi dashi", this_object())) && living(ob))
                if (dir == "northdown" ) {
                        foreach(ob in deep_inventory(me))
                                if (ob->id("shaolin wuji"))
                                        return notify_fail("大痴大师说道：武功秘籍只许在藏经阁内研习，不得携带外出！\n");
                }
        if ((ob = present("xiao shami", this_object())) && living(ob))
                if (dir == "northdown" ) {
                        foreach(ob in deep_inventory(me))
                                if (ob->id("shaolin wuji")){
                                	me->set_temp("target_putian",1);
                                	me->start_busy(1);
                                	message_vision(HIY"小沙弥大喊道：快来人啊！有人偷经书啦！！\n"NOR,me);
                                	}
                }
        return ::valid_leave(me, dir);
}
