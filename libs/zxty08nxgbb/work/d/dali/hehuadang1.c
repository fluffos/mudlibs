inherit ROOM;
void create()
{
        set("short", "昆明湖");
        set("long", @LONG
花园对面，正对一个大湖，俗名昆明湖。每至春时，红绿间发，宛似西湖胜景。
沿湖遍插芙蓉，湖中种五色莲花。盛开之日，满湖锦云烂熳，香气袭人，小舟荡桨
采菱，歌声泠泠。遇斜风微起，依船竟渡，纵横如飞。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hehuadang2",
  "west" : __DIR__"hehuadang",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/dayan" : 2,
]));
        set("outdoors","dali");

        setup();
}
