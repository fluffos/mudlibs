// Room: /d/putian/road06.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "石阶");
        set("long", @LONG
向上的山路继续变窄，一行古旧的石阶出现在你脚下。石块平整均匀，有些已
经长了青苔。脚踏在上面很柔软，但是很滑。不远处可以看见一个小凉亭。
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"road05",
                "southup" : __DIR__"road07",
        ]));

        set("objects",([
                NPC_D("youke") : 2,
        ]));

        set("outdoors", "福州");
        setup();
}

int valid_leave(object me, string dir)
{
        if ((me->query("id") == "wu seng" || me->query("id") == "seng bing")
         && dir == "westdown") {
			return notify_fail("");
		}
        return ::valid_leave(me, dir);
}

