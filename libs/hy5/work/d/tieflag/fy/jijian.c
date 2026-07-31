 inherit ROOM;
#include <ansi.h>
int check_legal_name(string arg);
void create()
{
        set("short", "祭剑亭");
        set("long", @LONG
祭剑是每个习武之人必做之事。每逢一年一度的风云城比武大赛，凡是参赛的
人都会到这儿来祭一次兵刃，以求好运。亭子间不大，四面通风，一道长长的木柜
把房间隔成了两部分，里面石板地正当中是一个冶剑炉，通红的炉火把亭内一切都
染上一层红色。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ecloud2",
]));
        set("objects", ([
            __DIR__"npc/wangfuren" : 1,
                        ]) );
        set("coor/x",20);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}
