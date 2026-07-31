// 上古十大神器之 轩辕剑
// Create by Rcwiz for Hero.cn 2003/09

#include <ansi.h>

#include <armor.h>

inherit ARMOR;
string do_wear();
int is_magic_item() { return 1; }


void create()
{
        set_name(HIG "玄武甲" NOR, ({ "xuanwu jia", "xuanwu", "jia" }) );
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "件");
                set("long", HIG "此乃上古神器玄武甲，拥有这件宝衣之人，\n"
                                "不入天，地，人，神，鬼。\n"
                                "天地万法，皆不可侵。\n"NOR);
                set("material", "armor");
				set("suit_point",2500);
			set("armor_prop/armor", 2500);
				set("wear_msg", (: do_wear :));
				set("gongxian",14999);
				set("no_give",1);
			set("no_steal",1);
			 set("no_sell", 1);
			set("no_get",1);
		//	 set("no_put",1);
		set("armor_prop/parry",500);
			set("wear_msg",HIC "$N" HIC "轻轻将一件$n" HIC "穿在身上，神态曼妙之极。\n");
			set("remove_msg", HIC "$N" HIC "轻轻脱下$n" HIC "只见$n消散于虚空之中。\n");
        }
   //     init_sword(21000000);
        setup();
}

string do_wear()
{
	object me;
	string msg;
	int per;

	me = this_player();
	per = me->query("per");
	if (me->query("gender") == "女性")
	{
		if (per >= 30)
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "穿在身上，神态曼妙之极。\n";
		
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "穿在身上，姿势潇洒之极。\n";
		
	}
	return msg;
}

int query_autoload()
{
	return 1;
}


