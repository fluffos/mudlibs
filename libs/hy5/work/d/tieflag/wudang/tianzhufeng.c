 inherit ROOM;
void create()
{
        set("short", "天柱峰");
        set("long", @LONG
过了金殿阁，就已来到真武最高峰--天柱峰。你仿似置身于仙境
之中。山风拂来，仿佛要乘风而去一般。这里云雾缭绕，有如陆海奔
潮。众峰争奇，千壑幽深的真武群山被浩淼千里的云海淹没，云随阳
光、风向变化，忽而狂涛翻腾，忽而巨浪奔涌，气象万千，惊人心魄。
LONG
        );
        set("exits", ([
        "eastdown" : __DIR__"feishengya",
        "westdown" : __DIR__"yinxuanyan",
                "northdown" : __DIR__"jindian",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",110);
        set("coor/y",-180);
    set("coor/z",100);
        set("objects", ([
        __DIR__"npc/tianfeng14": 1,
        ]) );
        setup();
        
        
        
}       
