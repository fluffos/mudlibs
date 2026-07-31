 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白石道");
        set("long", @LONG
再走数十步後，向右一转，这黑暗狭窄的洞穴，竟豁然开朗起来。石
道两旁，都砌着白玉般晶莹光滑的石块，顶上隐隐有灯光透出却瞧不见灯
是嵌在那里的。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao5",
                "westup" : __DIR__"yongdao3",
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
