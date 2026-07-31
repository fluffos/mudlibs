 // Room: /d/oldpine/tree2.c
inherit ROOM; 
void create()
{
        set("short", "大松树上");
        set("long", @LONG
你现在正攀附在一株大松树的树干上，这里离地面已经有七、八丈
高，如果不小心跌了下去，不断条腿也得去半条命，松树上结了许多松
果，不过大部分都离树干很远，你够不到。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tree3",
  "down" : __DIR__"tree1",
])); 
        set("coor/x",520);
        set("coor/y",2370);
        set("coor/z",120);
        setup();
        replace_program(ROOM);
}  
