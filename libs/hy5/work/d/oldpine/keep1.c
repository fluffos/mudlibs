 // Room: /d/oldpine/keep1.c
inherit ROOM; 
void create()
{
        set("short", "老云寨秘密入口");
        set("long", @LONG
这里只见一个木头搭成的大门，门框上挂著四、五的不知道是什麽
动物的头骨跟一些铁锈，外面再铺上一层乾枯的松枝，在这样一个森林
里还真不容易发觉。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pine2",
  "east" : __DIR__"keep15",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bandit_guard" : 4,
]));
        set("no_clean_up", 0); 
        set("coor/x",570);
        set("coor/y",2350);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
}   
