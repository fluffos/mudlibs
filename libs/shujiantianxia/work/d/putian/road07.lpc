// Room: /d/putian/road07.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
这里的山路平整了些，旁边出现了一块不大不小的空地，空地正中间修有一座
凉亭。偶尔可见个把僧人挑着担水，从旁边的小路走过来，行上山去。僧人的脚步
看上去很是扎实沉稳。
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"road06",
                "southup" : __DIR__"road08",
                "enter" : __DIR__"liangt",
        ]));

        set("objects",([
                NPC_D("youke") : 2,
                __DIR__"npc/wuseng" : 1,
        ]));

        set("outdoors", "福州");
        setup();
}

