// /d/hmy/shifang.c
// modified by Numa 19991108

inherit ROOM;

void create()
{
        set("short", "膳食房");
        set("long", @LONG
只见以经有十数名教徒分别围着几张八仙桌在进食，墙角有一张桌子是空
着的，周围摆着几张椅子，要填饱肚皮可以在那坐下。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"changlang4",
        ]));
        set("objects",([
                FOOD_D("tang") : 2,
                FOOD_D("zongzi") : 1,
                __DIR__"npc/chuzi" : 1,
        ]));
        set("no_fight", 1);

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i;
        
        i = sizeof(ob);
        if((dir == "west")){
                while (i--)
                if(ob[i]->id("suanmei tang") || ob[i]->id("zongzi"))
                        return notify_fail("厨子哼了一声，说道：吃饱喝足了还要带走呀！\n");
        }
        return ::valid_leave(me, dir);
}
