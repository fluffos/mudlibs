 inherit ROOM;
void create()
{
        set("short", "山道");
        set("long", @LONG
这是一条用石板铺成的山道，两旁是茂密的树木。但前面白雾
朦朦，路已经看不到了。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road5",
  "southdown" : __DIR__"road3",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2030);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}  
