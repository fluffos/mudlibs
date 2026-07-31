//bianxingdan.c 变性丹

#include <ansi.h>

inherit ITEM;

int do_eat_2(string arg);

void create()
{
	set_name(HIR"变性丹" NOR, ({ "bianxing dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一颗红红的丹药，据说使用后能够改变自己的性别。\n");
		set("value", 10000);
		set("no_sell",1);
		set("yuanbao", 400);
		set("only_do_effect", 1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat_2","bianxing");
}

int do_eat_2(string arg)
{
	object ob,me=this_player();		
	string gender, id, family;
	string *skill=({});
	int i;
	
	if (!arg||sscanf(arg,"%s %s", gender, id) != 2)
	{
		tell_object(me, ZJOBLONG + "你确定要变性为："NOR+"\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+
					CYN"男性"NOR":bianxing 男性 bianxing dan"ZJSEP+
					CYN"女性"NOR":bianxing 女性 bianxing dan"ZJSEP+
					CYN"无性"NOR":bianxing 无性 bianxing dan\n");
		return 1;
	}

	if( !objectp(ob = present(id, me)) )
		return 0;	
	
	family = me->query("family/family_name");

	if (	family == "少林派" 
	|| family == "峨嵋派" 
	|| family == "灵鹫宫"
	|| family == "雪山寺"
	|| family == "天龙寺" ) {
		tell_object(me, "你无法使用" + name() +"。\n");
		return 0;
	}
	if (gender !="男性" && gender !="女性" && gender !="无性") {
		tell_object(me, "没有这种性别！\n");
		return 1;
	}
		
	if(me->query("gender") == gender)
	{
		tell_object(me,sprintf("你已本来就是%s！\n", gender));
		return 1;
	}
	
	tell_object(me, "你一仰脖，吞下了一颗" + name() +"。\n");

	me->set("gender", gender);
	tell_object(me,"你成功变为"+gender+"！\n");
	
	if (gender != "男性") {
		skill += ({"anran-zhang",});
	}
	if (gender != "无性") {
		skill += ({"pixie-jian",});
	}
	if (gender != "女性") {
		skill += ({"yuenv-jian",});
	}
	if (gender == "无性") {
		skill += ({"yijinjing",});
	}

	if (sizeof(skill) > 0) {
		for (i = 0; i < sizeof(skill); i++) {
			if (me->query_skill(skill[i], 1)) {
				tell_object(me, "由于性别不符，你忍痛放弃了 "+me->query_skill(skill[i], 1)+" 级 "+to_chinese(skill[i])+" 。\n");
				me->delete_skill(skill[i]);

			}
		}
	}
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"服用了一颗"+name()+""HIM"，变成了"+gender+"！");
	me->save();
	log_file("static/using", sprintf("%s(%s) eat 变性丹 at %s 时间：%s.\n",
				me->name(1), me->query("id"), gender, ctime(time())));
	destruct(this_object());

	return 1;
}

int do_effect(object me)
{
	do_eat_2("");
	return 1;
}

int query_autoload() { return 1; }
