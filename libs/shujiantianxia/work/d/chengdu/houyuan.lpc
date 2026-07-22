// houyuan.c 后院
// 2001.10.04 update by Lklv

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是关帝庙的后院，院子很大，以前在院墙北面的方向有一个后门可以
通到别处，现在已经给人堵死了。诺大的院子里长满了杂草，西角有一小块菜
地，地边放着一个水桶(tong)。
LONG);
        set("resource/water", 1);
	set("drink_msg","$N趴在水桶边喝了一口凉水。\n");
        set("sleep_room",1);
        set("no_fight", 1);

        set("item_desc", ([
                "tong" : "里面有半桶水，渴了可以喝几口。(drink tong)\n",
                "shuitong" : "里面有半桶水，渴了可以喝几口。(drink tong)\n"
        ]));

        set("exits", ([
                "south" : __DIR__"guandm",
        ]));

        set("objects", ([
                FOOD_D("mantou") : 4
        ]));

        setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        object me = this_player();
        object ob;

        if ( arg && (ob = present(arg)) && ob->id("man tou")){
                if ( !wizardp(me) && (present("man tou", me) || me->query("family/family_name")!="丐帮"
                 || me->query("food") > me->query("str")*10 )){
                        write("角落里有个老叫化哼了一声，你不由的缩回了手。\n");
                        return 1;
                }
        }
        return 0;
}