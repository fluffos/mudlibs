#pragma save_binary

inherit ITEM;

void create()
{
        set_name("鸡蛋", ({ "ji dan", "dan","egg" }));
        set_weight(600);
        set("unit", "个");

        set("long","这是一颗普通的鸡蛋，你可以试着孵化它。(fu)\n");
				set("time",0);
				set("value",1);
                
}
void init()
{
	add_action("do_fu","fu");
}

int do_fu(string arg)
{
	if(arg == "egg" || arg == "dan" || arg == "ji dan")
	{
		if(this_player()->is_busy()) return notify_fail("你正忙着呢。\n");
		if(random(10) == 0)
		{
			message_vision("$N蹲下来，小心的用屁股捂住鸡蛋，嘴里发出咯咯咯咯咯的声音。看起来鸡蛋热乎起来了。\n",this_player());
			add("time",1);
			set("long","这是一颗普通的鸡蛋，你可以试着孵化它。(fu)\n看起来这颗鸡蛋已经孵化了"+chinese_number(query("time")/10+1)+"成了。\n");
		}
		else
		{
			message_vision("$N蹲下来，小心的用屁股捂住鸡蛋。但是鸡蛋毫无反应。\n",this_player());
		}
		this_player()->add_busy(5);
		return 1;
	}
	return 0;
}