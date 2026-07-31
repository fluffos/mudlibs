 inherit ROOM;
void create()
{
        set("short", "练功室");
        set("long", @LONG
干干净净的墙上挂着一幅字画，上面写到“知山有路勤为径，
学海无涯苦作舟。”地上打扫的一尘不染，墙角堆着很多竹刀剑。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"back_yard",
])); 
       set("objects", ([
                __DIR__"obj/bsword" : 3,
                __DIR__"obj/bblade" : 4,
//              __DIR__"obj/pieces" : 1,
//              __DIR__"obj/bqi"    : 1, 
        ]) ); 
        set("coor/x",-1240);
        set("coor/y",70);
        set("coor/z",-10);
        setup();
} 
void init()
{
        add_action("do_gets", "get");
} 
int do_gets(string arg)
{
        if(arg == "all")
        {
                write("你太贪心了。\n");
                return 1;       
        }
        else
                return 0;
} 
