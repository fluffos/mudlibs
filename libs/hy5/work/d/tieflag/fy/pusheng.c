 inherit ROOM;
void create()
{
        set("short", "普生堂");
        set("long", @LONG
普生堂本是一云游高僧路经风云城逗留时所设，高僧童心未泯，有感此地风土
人情，一留就是三年。亲授一弟子。高僧慧眼识珠，此弟子乃人中之龙，不到三年
已尽学僧人医术。堂中悬匾一块： 
                            妙手回春
LONG
        );
        
        set("exits", ([
                "east"          : __DIR__"swind5",
                "north"         : __DIR__"yangsheng",
        ]) );
        set("objects", ([
                __DIR__"npc/hosowner" : 1, 
                        ]) );
        set("coor/x",-10);
        set("coor/y",-50);
        set("coor/z",0);
        set("coor/x",-10);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}
