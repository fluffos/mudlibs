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
        set("exits", ([ 
                "northeast" : __DIR__"uproad1",
                "west" : __DIR__"uproad3",
        ]));
        set("outdoors", "tieflag");
        set("coor/x",2010);
        set("coor/y",-200);
        set("coor/z",10);
        setup();
}
int valid_leave(object who,string dir)
{
    object island;
    if (!objectp(island=find_object(__DIR__"island")))
        island=load_object(__DIR__"island");
        if(userp(who) && !random(3) && dir=="west")
        {
                who->move(island);
                return notify_fail("");
        }
        return 1;
}       
