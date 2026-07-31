// senlin7.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "百木园");
        set("long", @LONG
这里是梅庄的百木园，你一走到这里，就象走到了一个连绵无尽
的小森林一样，这里无数的松树，柏树，白杨，还有很多叫不出来名
字的异种苗木，你走在其中，只想把这片树林尽情的欣赏一遍，永不
出去才好。
LONG
        );

        set("exits", ([
                "east" : __DIR__"senlin"+(random(8)+1),
                "south" : __DIR__"senlin"+(random(8)+1),
                "west" : __DIR__"senlin"+(random(8)+1),
                "north" : __DIR__"senlin"+(random(8)+1),
        ]));
        set("outdoors", "meizhuang");
        setup();
}

void init()
{

        object ob, room;
        mapping fam;

        int i = random(2);
        if( i == 0) return;

        ob = this_player();
        room = this_object();

        if (ob->query("id") == "jia ding" || !living(ob)) return;

        room->delete("exits");

        if ( (fam = ob->query("family"))
        && fam["family_name"] == "梅庄"
        && ob->query("guilty") != 1 )
        ob->set("guilty",3);

//        ob->set("startroom", "/u/lovelygirl/meizhuang/jianyu");

        message_vision(HIR "\n$N脚下一滑，全身都埋进了厚厚的松针中！
$N只觉得天旋地转，呼吸也开始困难起来。\n\n" NOR, ob);

        message_vision(HIR "\n$N几乎就晕了过去......\n\n" NOR, ob);

        call_out("trapping", 20, ob, room);

}

void trapping(object ob, object room)
{
        if (!ob) return;
        if ( !living(ob) ) return;

        message_vision(HIY "\n家丁们把$N一把抓住，捆了个结实，扔进了监狱。\n\n\n" NOR, ob);
        ob->move(__DIR__"jianyu");

        room->set("exits/south", __DIR__"shulin"+(random(8)+6));
        room->set("exits/north", __DIR__"shulin"+(random(8)+6));
        room->set("exits/east", __DIR__"shulin"+(random(8)+6));
        room->set("exits/west", __DIR__"shulin"+(random(8)+6));
}

