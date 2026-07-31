//jinling  wuyigang.c
inherit ROOM;

void create()
{
        set("short", "乌衣巷");
        set("long", @LONG
这里是一条幽静狭小的巷子.相传说旧时王谢子弟善著乌衣，因而得名。
有道是:“朱雀桥边野草花，乌衣巷口夕阳斜，旧时王谢堂前燕，飞入寻常
百姓家。乌衣巷也因此而名扬四海。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "south" : __DIR__"dongjie1",
          "east" : __DIR__"yantang",


]));
        set("objects", ([
//"/u/poor/beggar/npc/beggar" : 4,
              __DIR__"npc/armorseller" : 1,
			]) );

     set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
