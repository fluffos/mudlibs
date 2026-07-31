 inherit ROOM;
void create()
{
        set("short", "海岸边");
        set("long", @LONG
日已西斜，但阳光还是灿烂，海浪拍打着礁石，激起一连串银
白色的泡沫。五七只海鸥在蔚蓝色的天空下，蔚蓝色的海洋上低回。
刚从黑暗中走出来的人，骤然见到阳光，都不禁闭起眼睛，让眼帘
先接受阳光温暖的轻抚，然后才能接受这令人心跳的光明！ 
LONG
        );
    set("exits", ([ 
        "east" : __DIR__"anbian2",
    ]));
        set("objects", ([
        __DIR__"npc/wang"   : 1, 
    ]));
        set("coor/x",3310);
        set("coor/y",10);
        set("coor/z",10);
            set("outdoors", "bat");
        setup();
        replace_program(ROOM);
}    
