 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "恩德元");
        set("long", @long
“恩德元”的门面并不大，装潢也不考究，但腰上扎着宽皮带、秃着脑袋、
挺着胸站在门口的马回回，就是块活招牌。经过这里的江湖豪杰若没有到“恩
德元”来跟马回回喝两杯，就好像觉得有点不大够意思。
long

        );
        set("exits", ([ 
        
        "north": __DIR__"road3",
        
        ]));
        set("objects", ([
         __DIR__"npc/mahuihui":     1,
        ]) );
        set("indoors", "biancheng");
        set("coor/x",-1120);
        set("coor/y",175);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
