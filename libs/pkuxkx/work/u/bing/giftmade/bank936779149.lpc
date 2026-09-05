// mirror.c	镜子
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG +"保险柜"+ NOR, ({ "box" }));
	set("long","这是银行专用的保险柜。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
		set("owner", "bank");
		set("auto_load", 1);
		set("material", "gold");
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
	add_action("do_zhao","zhao");
}

int do_zhao()
{
	int i,j,number,data;
	string msg;
	object me,user, *users;
	me = this_player();
	users = users();
	number = 1;
	data = 0;

	j = random(3);
	if (j == 0)
	{
		message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁最美？」\n",me);
		for(i=0; i<sizeof(users); i++) {
			if( users[i]->query("per")>data ) 
			{
				data = users[i]->query("per");
				user = users[i];
			}
			if( users[i]->query("per")>me->query("per") )
				number++;

		}
		if (user != me)
			msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "最美，你呀只能排第" + number + "。」\n";
		else msg = "镜子对$N说道：「这个世界上现在你最美，你就是这个世界上最美的人。」\n";
	}
	
	if (j == 1)
	{
		message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁最富有？」\n",me);
		for(i=0; i<sizeof(users); i++) {
			if( users[i]->query("balance")>data ) 
			{
				data = users[i]->query("balance");
				user = users[i];
			}
			if( users[i]->query("balance")>me->query("balance") )
				number++;

		}
		if (user != me)
			msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "最富有，你呀只能排第" + number + "。」\n";
		else msg = "镜子对$N说道：「这个世界上现在你最富有，你就是这个世界上最富有的人。」\n";
	}

	if (j == 2)
	{
		message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁最强？」\n",me);
		for(i=0; i<sizeof(users); i++) {
			if( users[i]->query("combat_exp")>data ) 
			{
				data = users[i]->query("combat_exp");
				user = users[i];
			}
			if( users[i]->query("combat_exp")>me->query("combat_exp") )
				number++;

		}
		if (user != me)
			msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "最强，你呀只能排第" + number + "。」\n";
		else msg = "镜子对$N说道：「这个世界上现在你最强，你就是这个世界上最强的人。」\n";
	}
	message_vision(msg,me);
 
	return 1;
}

