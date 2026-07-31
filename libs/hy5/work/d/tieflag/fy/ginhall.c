 inherit ROOM;
void create()
{
        set("short", "镖局内院");
        set("long", @LONG
这里是镖局伙计们辛苦之余，休息放松的院子。院子的中央横七竖八的架着几
根竹竿，想必是用来晾晒衣服的。院子的周围有几间小房，是供没有家的年青伙计
们住的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                  "west" : __DIR__"ghall",
                  "east"  : __DIR__"gke1", 
                  "north" : __DIR__"gke2",
                  "south" : __DIR__"gke3",
]));
        set("item_desc", ([
                "bamboo": "这些竹竿好象可以挪动（ｍｏｖｅ）。\n",
                "竹竿" : "这些竹竿好象可以挪动（ｍｏｖｅ）。\n",
                "几根竹竿" : "这些竹竿好象可以挪动（ｍｏｖｅ）。\n"
        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",30);
        set("coor/y",40);
        set("coor/z",0);
        setup();
} 
void init()
{ 
        add_action("do_move", "move");
} 
int do_move(string arg)
{
        object cock;
        if ( !arg || (arg != "bamboo" && arg != "竹竿" && arg != "几根竹竿")) {
                return notify_fail("你要搬动什么？\n");
        }
        if( query("amount") > 10 ) 
                return notify_fail("还挪？！蟑螂都被你吓的跑光了。\n" );
        cock = new(__DIR__"npc/cockroach");
   if(cock) cock->move(this_object());
        message_vision("$N挪了下竹竿，一只"+cock->name()+"飞快地爬了出来．\n", this_player());
        add("amount",1);
        return 1;
} 
void reset()
{
        ::reset();
        set("amount",0);
}      
