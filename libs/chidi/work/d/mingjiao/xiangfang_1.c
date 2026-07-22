// Room: xiangfang_1.c

inherit ROOM;

void create()
{
        set("short", "厢房");
        set("long", @LONG
这里是明教用来接待来访江湖人物的厢房，摆设简单，却布置得
干净整洁，一张大床又大又舒适。有几个小童正在仔细擦拭门椅、廊
窗。看样子又有贵客到访了。西面就是光明顶前厅。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guangming-ding",
]));
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
