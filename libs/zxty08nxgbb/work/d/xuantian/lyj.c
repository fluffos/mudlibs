// 凌云居  by:pipip
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "凌云居");
    set("long", @LONG
你一进的门来就闻到一股香气，只见一为面貌清
雅的老人正背对着你弹琴，琴音时浊时清，清如春林
鸟语，浊如黄河波涛，你直听的入迷了。
LONG
    );
    set("exits", ([
        "south" : __DIR__"door",
        "east" : "d/xuantian/room1",
    ]));
    set("objects", ([
        "d/xuantian/npc/wuming" : 1 ]));
    setup();
    replace_program(ROOM);
}

int do_check(object me)
{
    object where=this_object();
    object *obj;
    int i;
    obj=deep_inventory(where);
    if (!sizeof(obj))   return 0;
    for (i=0;i<sizeof(obj);i++){
        if (obj[i]==me) continue;
        if (userp(obj[i]))
            return 1;
    }
    return 0;
    
}

void init()
{
    object ob=this_player();
    if(userp(ob) && (int)do_check(ob)){
        message_vision("无名老人一把抓住$N丢了出来，说道：我一次只教一个徒弟。\n",ob);
        ob->move("d/xuantian/dadao");
    }
}

