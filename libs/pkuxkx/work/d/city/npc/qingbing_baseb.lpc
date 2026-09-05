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
	tell_room(environment(),query("title")+query("name")+"嘿嘿奸笑两声，翻身上马，远远离去。\n");
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

int kill2()
{
	int i;
	object me;
	object* allob;
	if (environment())
	{

		allob=all_inventory(environment());
		for (i=0;i<sizeof(allob);i++)
			{
				if(allob[i]->query("skfleader")==this_object()->query("target"))
					{
						
						if (!allob[i])
						{
							return 1;
						}
						else
						{
							message_vision(HIR""+query("title")+query("name")+"纵马跑了出来，开始对"+allob[i]->query("name")+"下手了！\n"NOR,this_object());
							me=allob[i];
							this_object()->copy(me);
							kill_ob(me);
							break;
						}
					}
			}
	}
}