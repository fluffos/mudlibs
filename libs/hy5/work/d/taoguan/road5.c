 inherit ROOM;
void create()
{
        set("short", "雾中");
        set("long", @LONG
四周白朦朦的，你隐约发现山道已到了尽头。如果再想往
上就要爬山了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"road4",
]));
        set("item_desc", ([
                "mountain": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
                "山": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
                "up": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
        ]) );
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2040);
        set("coor/z",60);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "山" || arg == "mountain" || arg == "up")
        {
        me = this_player();
        message_vision("$N慢慢地往山上爬去。\n", me);
        me->move(__DIR__"ping_tai.c");
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}  
