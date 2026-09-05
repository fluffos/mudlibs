// Room: /d/gumu/shishi.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "石室");
        set("long", @LONG
        这是一间很大的石室，靠西边墙上有一个大石桌，桌
旁坐着个很美丽的女子，冰冷地看着你进来。靠里拴着根绳子
，不知是用来干什么的。
LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  
  "east"  : __DIR__"mudao9",
//"northeast" : __DIR__"midao3",
]));
  set("objects",([CLASS_D("gumu")+"/binger":1,]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
