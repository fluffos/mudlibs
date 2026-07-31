 inherit ROOM;
void create()
{
        set("short", "紫霄宫");
        set("long", @LONG
殿顶由四根八丈高的红柱撑著，地板则是由白玉石铺成。左右墙
上挂著几幅字画，正面的墙上高高地挂著一块金匾，上书“紫霄宫”
三字。匾下是一张供台，一尊太上老君像正坐其中。像前摆著各式水
果和两具烛台。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"wudang1",
        ]));
        set("objects", ([ 
                __DIR__"npc/master" : 1,
                __DIR__"npc/taoist" : 1,
        ]));
        set("valid_startroom", 1);
    set("coor/x",115);
        set("coor/y",-140);
        set("coor/z",50);
        setup();
replace_program(ROOM); 
}      
