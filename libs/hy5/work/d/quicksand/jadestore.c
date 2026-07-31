 inherit ROOM;
void create()
{
        set("short", "珠宝店");
        set("long", @LONG
这是一家破旧的小店。专门经营玉器，这里虽是穷乡僻壤，这家小店的
生意却特别好。也许是出塞的人都知到塞外险恶，想必凶多吉少，都想买
块玉来消消灾。
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"saikou",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/jadeowner" : 1,
        ]) ); 
        set("coor/x",-1030);
        set("coor/y",10);
        set("coor/z",0);
        setup(); 
}   
