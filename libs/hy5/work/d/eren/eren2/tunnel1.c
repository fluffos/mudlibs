 inherit ROOM;
void create()
{
        set("short", "暗道");
        set("long", @LONG
洞穴越往里面越是窄隘，爬进十余丈后，已仅能容身。此地主人开出
这一通道，不知是为谁而设。但既已到此，无路可退，唯有费力前行。
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"tunnel2",
                "down" : __DIR__"mouseroom4",
        ]));
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
