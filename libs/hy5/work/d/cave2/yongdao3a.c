 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小石洞");
        set("long",  @LONG
又是石壁上一块凹进的地方，约摸有两丈见方，点着一盏油灯，放着
几个木箱和一张床，地上胡乱丢着几柄长剑，看上去像个哨卡。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao3",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}       
