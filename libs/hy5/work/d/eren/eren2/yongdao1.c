 inherit ROOM;
void create()
{
        set("short", "甬道入口");
        set("long",  @LONG
再走几步，便是甬道的入口，往下看，每过十多尺便有一转折之处。不知哪里
来的阴风吹得一旁的烛火忽明忽暗，依稀照出洞顶上三个血红的大字。
                恶       人      窟
        
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao2",
                "southup" : __DIR__"cavein",
        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
