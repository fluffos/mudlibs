// xiaohe1.c

inherit ROOM;

void create()
{
        set("short","小河岸边");
        set("long",@LONG                                   
你前面就是一条几丈宽的小河。铜山村之所以比较富饶就
是因为有了这条小河的水可以灌溉农田。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "southup" : __DIR__"tulu2",
        ]) );

        set("outdoors", "huayin");
        setup();
}

void init()
{
	add_action("do_fill","fill");
}

int do_fill(string arg)
{
	object me = this_player(),ob;

	if(!objectp(ob = present("shui piao",me)) || !ob->id(arg))
                return notify_fail("你要用什么打水？\n");

	if(ob->is_full())
                return notify_fail("水瓢已经是满的了。\n");

	message_vision("$N拿起水瓢在小河里舀了一瓢清水。\n",me);

	ob->do_fill();
        return 1;
}
