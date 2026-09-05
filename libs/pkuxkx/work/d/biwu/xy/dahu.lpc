// Room: /clone/misc/dahu.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "大户人家");
	set("long", @LONG
这里一看就曾经是富贵人家，虽然已经破败，但格局非常气派。地上散落着
很多红线(xian)，也许当年这里的小姐是女红高手。
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"northstreet",
	    "east" : __DIR__"backyard2",
	]));
	set("item_desc", ([
		"xian" : "一团团女红用的线，虽然不知道有什么用处，你可以先捡(jian)一些。\n", 
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_na", ({ "na", "jian" }));
	::init();
}

int found(object me)
{
	object ob;
	if (random(10)>6)
		    {
                ob = new("/biwu/xy/obj/string");
                if (ob)
                {
                    ob->move(me);
                    message_vision("$N拾起一根长长的线。\n", me);
                }
		    }
	else
            {
                message_vision("$N把线捡起来，放在眼前一看，不到五寸，毫无用处。\n", me);
            }
	return 1;
}

int do_na()
{
	object me = this_player();
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
    found(me);    
    return 1; 
}