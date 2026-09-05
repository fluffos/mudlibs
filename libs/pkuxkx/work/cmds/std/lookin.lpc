// lookin.c
// Made by jason@pkuxkx
// Avoid mask 

int main(object me,string arg)
{
	object *ob,target;
    int i,flag=0;
	if(!arg||arg=="") 
		return notify_fail("你要看谁？\n");
	if(me->is_busy()) return notify_fail("你正忙着呢。\n");
	if(!objectp(target=present(arg,environment(me))))
		return notify_fail("这里没有这个人。\n");
    if (me->query_temp("gbnewbiejob")&&target==me->query_temp("gbnewbiejob/target"))
    {
        ob=all_inventory(target);
        for (i=0;i<sizeof(ob);i++)
        {
            if (ob[i]==me->query_temp("gbnewbiejob/theitem"))
            {
                flag=1;
                break;
            }
        }
        if (flag==1&&me->query_temp("gbnewbiejob/item"))
        {
            tell_object(me,me->query_temp("gbnewbiejob/item")+"似乎正在"+target->query("name")+"身上，赶紧动手吧。\n");
        }
        else
        {
            tell_object(me,me->query_temp("gbnewbiejob/item")+"似乎已经不在"+target->query("name")+"身上了。\n");
        }
    }
	if(me->query("combat_exp")>random(2*target->query("combat_exp"))&&
	target->query_temp("apply/name"))
	{
		message_vision("$N盯着$n的脸细细的看去，觉得$n脸上的神色似乎不对，\n"
		+"再仔细一看，原来是"+target->query("name")+"("+target->query("id")+")"+
		"假扮的。\n",me,target);
		target->delete_temp("apply/name");
                target->delete_temp("apply/id");
                target->delete_temp("apply/short");
                target->delete_temp("apply/long");
                target->delete_temp("apply/age");
                target->delete_temp("apply/gender");
                target->delete_temp("apply/shen");
		target->delete_temp("apply/class");		
		target->delete_temp("apply/mud_age");
		message_vision("$N被人识破，只好取下了面具。\n",target);
		target->start_busy(2);
	}
	else
	{
		message_vision("$N盯着 $n看了半天，觉得$n气色还不错。\n",me,target);
	}
	me->start_busy(1);
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: lookin userid
 
这个指令使你可能看清楚带面具玩家的真面目。
 
HELP
);
return 1;
}