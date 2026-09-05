#pragma save_binary

inherit ITEM;
#include "ansi.h";
int des();
void create()
{
        set_name(WHT"通天镜"NOR, ({"tongtian jing", "jing"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long", "一个亮闪闪的铜镜，是一个预测宝物位置的神奇东西，似乎可以（detect）探察宝物位置。\n");
                set("value", 0);
          }
        setup();
		
}

void init()
{
        add_action("do_detect", "detect");
		add_action("do_dig", "dig");
		call_out("des",600);
}

int do_detect()
{
    string  detect,filename,describe;
	object room;
	object* baowu;
	int i,j;
	baowu=children(__DIR__"baowu");
	if (i=sizeof(baowu)<2)
		return notify_fail("宝物还没有出世呢！\n");
	if (wizardp(this_player()))
	{
		tell_object(this_player(),HIR"巫师严禁自己或帮助玩家挖宝，如有发现，立即无条件开除！\n"NOR);		
	}
	room = environment(baowu[0]);
	filename = file_name(room);
	if (living(room))
	{
		tell_object(this_player(),sprintf("宝物现在在%s(%s)的身上。\n",room->query("name"),room->query("id")));
		if (wizardp(this_player()) && environment(room))
		tell_object(this_player(),HIR"巫师严禁自己或帮助玩家挖宝，如有发现，立即无条件开除！\n"NOR+"现在宝物所在位置："+file_name(environment(room))+"\n");
		return 1;
	}
	if (filename!=baowu[0]->query("filepath"))
	{
		describe = room->query("long");
		i = strwidth(describe);
		while (j<i)
		{
			if (is_chinese(describe[j..j]))
			{
				if (random(100)<50)
					describe[j..j+1] = "□";
				j++;
			}
			j++;
		}
		baowu[0]->set("detect",describe);
		baowu[0]->set("filepath",filename);
	}
	tell_object(this_player(),baowu[0]->query("detect")+"\n");
	if (wizardp(this_player()))
		tell_object(this_player(),HIR"巫师严禁自己或帮助玩家挖宝，如有发现，立即无条件开除！\n"NOR+"现在宝物现在位置："+baowu[0]->query("filepath")+"\n");
	
	return 1;
}
int do_dig()
{
	object ob;
        if (this_player()->query("qi")<30)
		return notify_fail("你太累了，休息一下再挖吧！\n");
        if (this_player()->query("jing")<20)
		return notify_fail("你太累了，休息一下再挖吧！\n");
        if (this_player()->query("neili")<20)
		return notify_fail("你太累了，休息一下再挖吧！\n");
        this_player()->add("qi",-20);
        this_player()->add("jing",-10);
        this_player()->add("neili",-10);
	message_vision(HIG"$N挥舞着锄头疯狂的挖着什么！\n"NOR,this_player());
	if (ob=present("bao wu",environment(this_player())))
	{
		if (random(5)<3)
		{
          if (ob->query("no_show"))
		{
                        ob->delete("no_show");
                        ob->delete("no_get");
			ob->move(this_player());
			tell_object(this_player(),HIY"你挖到了宝物！\n"NOR);
		}
		else
			tell_object(this_player(),HIR"乱挖什么，宝物不就摆在你眼前吗！\n"NOR);
	}
	}
	return 1;
}
int des()
{
	message_vision(HIW"忽然一道白光，$N身上的通天镜消失的无影无踪。\n"NOR,this_player());
	destruct(this_object());
	return 1;
}

