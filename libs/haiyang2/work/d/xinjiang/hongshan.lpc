 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "红山");
        set("long", @LONG
红山因山呈红褐色得名，山不是很高，也不是很雄伟，但还是很有名。
山顶有一塔，称“镇龙塔”。从这里可以看到远处的城门和城里的炊烟。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhenlong",
  "southdown" : __DIR__"tulu",
  "southup" : "/d/zangbei/echu",
   
])); 
        set("objects", ([
        "/clone/npc/man" : 1,
        ]) ); 
        
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
        set("coor/y",2130);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}      
