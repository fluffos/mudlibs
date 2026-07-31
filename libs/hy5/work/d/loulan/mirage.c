 inherit ROOM;
void create()
{
        set("short", "海市蜃楼");
        set("long", @LONG
突然远远望去，天边的云霞中，隐隐现出城廓的影子，河流潺潺，湖泊如碧，
街道房屋佛塔城墙，依稀可辨，霎那之间，云彩变幻，这些幻像又归於无有。一切
仿佛在梦幻之中。
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"sandlin",
                "northwest" : __DIR__"yangguan",
                "west" : "/d/quicksand/desert5",
                "east" : "/d/quicksand/desert6",
        ]));
        set("outdoors", "loulan");
        set("coor/x",-900);
        set("coor/y",100);
        set("coor/z",0);
        setup();
}   
