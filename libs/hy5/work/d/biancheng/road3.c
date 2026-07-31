 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "西街");
        set("long", @long
太阳照在街上，路面闪着金光。西街通向小镇的中心，两旁是店铺，酒家。街的
北侧是陈大倌的绸缎庄，开面有几间屋子，外面招牌上写着“清水锦绸细缎，工夫作
针”。这是小镇上很少几家上档次的店铺之一。
long

        );
        set("exits", ([ 
        "east" : __DIR__"road2",
        "west" : __DIR__"road4",
        "north": __DIR__"silkshop",
        "south": __DIR__"endeyuan",
        ]));
        set("objects", ([
//         __DIR__"npc/mahuihui":     1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1120);
        set("coor/y",180);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
