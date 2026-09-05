// Room: /clone/misc/litroom.c
// create by zine Aug 28 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "院落");
	set("long", @LONG
两进整齐的院落。两侧厢房中间的庭院里有一口井(well)，与周围房屋上斑
驳的红漆不同的是，这口井异常干净，似乎有人天天擦拭。
LONG
	);
	set("item_desc", ([
		"well" : "一口深井，但却丝毫感觉不到潮气上涌，似乎有些异常，你可以打探(datan)一下。\n", 
	]));
	set("exits", ([ 
		"east" : __DIR__"backyard",
	]));
	set("no_clean_up", 0);
	setup();
}


void init()
{ 
	add_action("do_datan","datan"); 
	::init();
}

int do_datan(string arg)
{
	object room;
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	if(!arg)
		{
			return notify_fail("你要打探什么？\n");
		}
    if(arg != "well")
		{
            return notify_fail("你要打探什么？\n");
		}
    if (query("exits/down"))
		{
			return notify_fail("你已经发现古井的秘密，还不赶紧下去？\n");
		}
    if(!( room = find_object(__DIR__"didao")) )
		{
			room = load_object(__DIR__"didao");
		}
    if(objectp(room))
        {
			set("exits/down", __DIR__"didao"); 
			message_vision("$N细细察看之下，井下竟似乎别有洞天。\n",me);
			remove_call_out("close_door");
			call_out("close_door",3); 
		}
    return 1;
}

int close_door()
{
	delete("exits/down",);
	return 1;
}