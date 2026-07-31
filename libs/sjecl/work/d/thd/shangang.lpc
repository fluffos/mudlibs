// Room: /u/jpei/thd/xiaoyuan.c
// Modified by Numa 19980830

inherit ROOM;

void create()
{
        set("short", "山冈");
/*        set("long", @LONG
没有想到这里竟然会有这么幽雅的小院，假山回廊，花树盆景，无一不
是放置得极为合适，显然这里的主人非常熟悉布置，再联系到东、西、南三
面的桃花阵，足见主人熟通阴阳五行、变化生克之理。北面是一座小亭子。
LONG
        );*/
        set("long",@LONG
这里是一个光秃秃的山冈，岩石丛立，但似乎每一块石头都有人精心布置过
似的，和东、西和南三面的桃花阵组成了一个整体，足见岛上的主人熟通阴
阳五行、变化生克之理。北面是一片草地。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"bagua1",
                "west" : __DIR__"bagua0",
                "south" : __DIR__"taohua1",
                "north" : __DIR__"caodi",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","桃花岛");
        set("objects",([
                __DIR__"obj/shizi" : 1,
        ]));  

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob, *deep_ob;
        int i, j, drop_flag;

        if (dir == "west" || dir == "east") {
                if (!me->query_temp("bagua_1") && me->query_skill("qimen-bagua", 1) < 90)
                        return notify_fail("你感觉这个桃花阵中暗藏八卦，隐隐生出阻力，将你推了回来！\n");
                ob = all_inventory(me);
                drop_flag = 0;
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!drop_flag) {
                                        message_vision("$N看了看眼前这个复杂无比的八卦阵，决定丢下包袱，轻装上阵。\n", me);
                                        drop_flag = 1;
                                }
                                message_vision("$N将$n从背上放了下来，躺在地上。\n", me, ob[i]);
                                ob[i]->move(this_object());
                        }
                        else {
                                deep_ob = deep_inventory(ob[i]);
                                for(j = 0; j < sizeof(deep_ob); j++) {
                                        if (userp(deep_ob[j])) {
                                                if (!drop_flag) {
                                                        message_vision("$N看了看眼前这个复杂无比的八卦阵，决定丢下包袱，轻装上阵。\n", me);
                                                        drop_flag = 1;
                                                }
                                                message_vision(sprintf("$N丢下一%s$n。\n", ob[i]->query("unit")), me, ob[i]);
                                                ob[i]->move(this_object());
                                                break;
                                        }
                                }
                        }
                }
        }

        return ::valid_leave(me, dir);
}
