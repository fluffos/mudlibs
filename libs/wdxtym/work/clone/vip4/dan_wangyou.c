//bianxingdan.c 变性丹

#include <ansi.h>

inherit ITEM;

int do_eat_2(string arg);

void create()
{
	set_name(HIR"忘忧丹" NOR, ({ "wangyou dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一颗雪白的丹药，据说使用后能够改变自己的性格。\n");
		set("value", 10000);
		set("no_sell",1);
		set("no_shop",1);
		set("yuanbao", 600);
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
		tell_object(me, ZJOBLONG + "你确定要把性格变为："NOR+"\n"ZJOBACTS2+ZJMENUF(2,2,10,30)+
					CYN"光明磊落"NOR":bianxing 光明磊落 wangyou dan"ZJSEP+
					CYN"狡黠多变"NOR":bianxing 狡黠多变 wangyou dan"ZJSEP+
					CYN"心狠手辣"NOR":bianxing 心狠手辣 wangyou dan"ZJSEP+
					CYN"阴险奸诈"NOR":bianxing 阴险奸诈 wangyou dan\n");
		return 1;
	}

	if( !objectp(ob = present(id, me)) )
		return 0;	
	
	family = me->query("family/family_name");
/*
	if (	family == "少林派" 
	|| family == "峨嵋派" 
	|| family == "灵鹫宫"
	|| family == "雪山寺"
	|| family == "天龙寺" ) {
		tell_object(me, "你还没有成为大宗师，无法使用" + name() +"。\n");
		return 0;
	}
*/
	if (gender !="光明磊落" && gender !="狡黠多变" && gender !="心狠手辣" && gender !="阴险奸诈") {
		tell_object(me, "没有这种性格！\n");
		return 1;
	}
		
	if(me->query("character") == gender)
	{
		tell_object(me,sprintf("你的性格本来就是%s！\n", gender));
		return 1;
	}
	
	tell_object(me, "你一仰脖，吞下了一颗" + name() +"。\n");

	me->set("character", gender);
	tell_object(me,"你的性格成功变为"+gender+"！\n");
	
	if (gender != "光明磊落") {
		skill += ({"jiuyin-shengong",});
	}
	if (gender != "狡黠多变") {
		skill += ({"never-defeated",});
	}
	if (gender != "心狠手辣") {
		skill += ({"bluesea-force",});
	}
	if (gender != "阴险奸诈") {
		skill += ({"kuihua-mogong",});
	}

	if (sizeof(skill) > 0) {
		for (i = 0; i < sizeof(skill); i++) {
			if (me->query_skill(skill[i], 1)) {
				tell_object(me, "由于性格不符，你忍痛放弃了 "+me->query_skill(skill[i], 1)+" 级 "+to_chinese(skill[i])+" 。\n");
				me->delete_skill(skill[i]);

			}
		}
	}
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"服用了一颗"+name()+""HIM"，性格大变，行为逐渐"+gender+"！");
	me->save();
	log_file("static/using", sprintf("%s(%s) eat 忘忧丹 变为 %s 时间：%s.\n",
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
