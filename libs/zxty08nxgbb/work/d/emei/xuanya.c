// Room: /d/emei/xuanya.c 峨嵋派 悬崖

inherit ROOM;

void create()
{
	set("short", "悬崖");
	set("long", @LONG
这里是一处悬崖，四周峭壁嶙峋。在悬崖上生长了一颗苍松，枝叶茂密，
遮天闭日。在树上蜿蜒缠绕了一条巨大的蟒蛇。
LONG
	);

	set("exits", ([
                 "down":__DIR__"shierpan4",
	]));
        set("objects",([
//                 "/d/emei/npc/snake": 1,
        ]));

        set("outdoors", "emei");
	setup();
}
void init()
{
       object me=this_player();
       object obn,room;
       obn = new("/d/emei/npc/snake");
       room= load_object(__DIR__"xuanya");
       if(!objectp(present("snake")))
       {
       obn->move(room);
       return ;
         }
} 
