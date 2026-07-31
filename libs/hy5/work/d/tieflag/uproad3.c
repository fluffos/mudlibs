 // searoad.c
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
小路曲曲折折返向山峰，一路上但见青翠的山林中，种满了五彩缤纷的花朵。
林木间，花光间，不时可瞧见亭台楼阁，翩翩人影，当真犹如一群仙女倘徉在这世
外仙山中。
LONG
        );
        set("objects",([
                __DIR__"npc/qinggirl" : 1,
        ]) );
        set("exits", ([ 
                "east" : __DIR__"uproad0",
                "westdown" : __DIR__"uproad2",
        ]));
        set("outdoors", "tieflag");
        set("coor/x",2000);
        set("coor/y",-200);
        set("coor/z",15);
        setup();
}
int valid_leave(object who,string dir)
{
    object platform;
    if (!objectp(platform=find_object(__DIR__"platform")))
        platform=load_object(__DIR__"platform");
        if(userp(who) && !random(3) && dir=="east")
        {
                who->move(platform);
                return notify_fail(""); 
        }
        return 1;
}    
