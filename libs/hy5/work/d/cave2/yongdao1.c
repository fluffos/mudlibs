 inherit ROOM;
void create()
{
        set("short", "甬道入口");
        set("long",  @LONG
再走几步，便是隧道的入口，烛火暗了许多，往下看，每过十多尺有
几盏照明的灯烛。洞壁上有两行血红的字。
        
        一失足成千古恨，再回首已百年身。
        
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
