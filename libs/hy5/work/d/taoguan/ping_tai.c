 inherit ROOM;
void create()
{
        set("short", "平台");
        set("long", @LONG
在这里有一个小小的平台，你可以在这稍作休息。
LONG
        );
        set("item_desc", ([
                "up": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
                "mountain": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
                "山": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
        ]) );
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2040);
        set("coor/z",70);
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
        me = this_player();
        if( arg == "up" || arg == "山" || arg == "mountain")
        {
                message_vision("$N慢慢地往山上爬去。\n", me);
                me->move(__DIR__"hole.c");
                return 1;
        }
        else if( arg == "down") {
           message_vision("$N慢慢地往山下爬去。\n", me);
                me->move(__DIR__"road5.c");
                return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}       
