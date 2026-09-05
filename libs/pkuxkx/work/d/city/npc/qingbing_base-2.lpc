// 清军模板

#include <ansi.h>
inherit NPC;
int do_copy(object ob);

string *title = ({
	"正黄旗", "正白旗", "正蓝旗", "正红旗", "镶黄旗", "镶白旗", "镶蓝旗", "镶红旗",
});

string * surname=({"瓜尔佳","钮钴禄","舒穆禄","纳兰","董鄂","马佳","富察","萨克达",});
string * givenname=({"明珠","索尔图","玄烨","弘历","福临","济尔哈朗","胤祯","旻宁","永琰",});
	
void selfcheck()
{
	object ob = this_object();
	object lord=find_player(ob->query("lord"));
    if (!lord||base_name(environment(lord))!=base_name(environment(ob)))
    {
        destruct(ob);
        return;
    }
    else
    {
        remove_call_out("selfcheck");
        call_out("selfcheck",25);
	    return;
    }
}

int kill2()
{
	int i;
	object me=this_object();
	object* allob;
	if (environment(me))
	{

		allob=all_inventory(environment(me));
		for (i=0;i<sizeof(allob);i++)
			{
				if(allob[i]->query("superhero"))
				{
					kill_ob(allob[i]);
				}
                if (allob[i]->query("refugee"))
                {
                    kill_ob(allob[i]);
                }
                else
                {
                    continue;
                }
			}
	}
    remove_call_out("kill2");
    call_out("kill2",30);
    return 1;
}