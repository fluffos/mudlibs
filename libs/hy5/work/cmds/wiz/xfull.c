#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	int i = 0;
int size,size2;
string wiz_status;
    object obj,riding;
	object ob, *inv;

    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("对象错误: 找不到"+str+"\n");
    
        size=sizeof(filter_array(all_inventory(me), (: ! $1->query("equipped") :)));
        size2=sizeof(filter_array(all_inventory(me), (: ! $1->query("equipped") :)));
//         printf(" 共有 %d 个 道具　\n", size);
//         printf(" 共有 %d 个 道具　\n", size2);

	inv = all_inventory(obj);
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("is_rided_by") == obj->query("id") )
		{
			ob = inv[i];
			i = -10;
		}
		i++;
	}

        if (ob)
        {
                message_vision("$N一头从$n上面栽了下来！\n",
                              obj, ob);
                obj->delete_temp("is_riding");
                ob->delete_temp("is_rided_by");
                ob->move(environment(me));
        }

wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" 
	&& userp(me) && wizardp(me) && obj!=me)
message("channel:chat", HIC"【玩家监督】"+me->name() + "完全恢复了" + 
                  obj->query("name")+HIC"的所有属性!"NOR"。\n", users());

    tell_object(obj,HIR + this_player()->query("name") + "(" + this_player()->query("id")+ ")为你的身体恢复到了最佳状态。\n"NOR);
    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili")*2);
    obj->set("food",obj->max_food_capacity()*2);
    obj->set("water",obj->max_water_capacity()*2);
if (!obj->query_condition("killer"))
    obj->clear_condition();
    write(HIR"恢复成功。!!!\n"NOR);
    return 1;
}

int help(object obj)
{
  write(@HELP
指令格式 : xfull <对象>

利用此指令可完全恢复生物的状态。
HELP
    );
    return 1;
}

