// 清军模板

#include <ansi.h>
inherit NPC;
int do_copy(object ob);

string *title = ({
	"正黄旗", "正白旗", "正蓝旗", "正红旗", "镶黄旗", "镶白旗", "镶蓝旗", "镶红旗",
});

string * surname=({"瓜尔佳","钮钴禄","舒穆禄","纳兰","董鄂","马佳","富察","萨克达",});
string * givenname=({"明珠","索尔图","玄烨","弘历","福临","济尔哈朗","胤祯","旻宁","永琰",});
	

void die()
{
	tell_room(environment(),query("title")+query("name")+"一闪身，失去了踪迹。\n");
	if(this_object())
	destruct(this_object());
}


void dest()
{
	object ob = this_object();
	if (environment(ob)) 
	tell_room(environment(),query("title")+query("name")+"匆匆忙忙地离开了。\n");
	destruct(ob);
	return;
}

int kill()
{
	object me;
	int i;
	object* allob;
	if (environment())
	{
		allob=all_inventory(environment());
	}
	for (i=0;i<sizeof(allob);i++)
	{
		if (allob[i]->query("skfxiang")|| allob[i]->query("family/family_name")=="朝廷")
		{continue;}
		else
		{
			me=allob[i];
			if (me)
			{
				message_vision(query("title")+query("name")+HIR+"大喝一声，竟敢擅闯大帅行营！\n"NOR,me);
				this_object()->kill_ob(me);
			}
		}
	return 1;
	}
}

