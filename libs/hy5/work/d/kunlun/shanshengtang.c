// sanshengtang.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "昆仑三圣堂");
                  set("long",@long
昆仑三圣堂乃“昆仑三圣”何足道所建，原为了修身养性，读书练功。随
着昆仑派日益壮大，名声远播，这里便成了昆仑派聚众议事，接待各路江湖英
雄的地方。“昆仑三圣”也只好另觅安静所在了。
long);
                 set("exits",([
"west" : __DIR__"jiuqulang1",
"south" : __DIR__"shanmen",
"north" : __DIR__"liangong",
"northwest" : __DIR__"jiuqulang2",
]));

                 set("objects",([
                                "/kungfu/class/kunlun/banshuxian.c" :   1,
                                __DIR__"npc/kl-dizi1.c" :   1,
                                __DIR__"npc/kl-dizi3.c" :   1,
                ]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
        }

int valid_leave(object me, string dir)
{

        if (!me->query_temp("kl_pass") && dir == "north" &&
                objectp(present("ban shuxian", environment(me))))
        {
                return notify_fail("班淑娴拦住你，说道：除非你能过得了我这一关，否则还是请另觅佳处。\n");
        }
                  return ::valid_leave(me, dir);
}
