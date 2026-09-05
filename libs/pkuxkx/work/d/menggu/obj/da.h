#include <ansi.h>

void init()
{
	object ob=this_object();
    add_action("do_da","da");
	add_action("do_zha","zha");
	return;
}

int do_zha(string arg)
{
	object me,*obs,arrow,arrows;
	int i,j=0;
	me=this_player();
	obs=all_inventory(me);
	if (!arg)
	{
		tell_object(me,"你要把哪些箭捆扎起来。\n");
		return 1;
	}
	if (!arrow=present(arg,me))
	{
		tell_object(me,"你身上有"+arg+"吗？\n");
		return 1;
	}
	if (!arrow->query("arrow_serial")||!arrow->query("is_arrow"))
	{
		if (arrow->query("arrow_set"))
		{
			tell_object(me,arrow->query("name")+"是已经扎好的箭支，如果你要把它们分开，请用拆开(chai)命令。\n");
			return 1;
		}
		tell_object(me,arg+"不是箭支，你不能把他们扎起来。\n");
		return 1;
	}
	for (i=0;i<sizeof(obs);i++)
	{
		if (obs[i]->query("arrow_serial")==arrow->query("arrow_serial"))
		{
			j+=1;
		}
		else
		{
			obs-=({obs[i]});
		}
	}
	if (j<5)
	{
		tell_object(me,arg+"不足五支，你就自己拿着吧。\n");
		return 1;
	}
	message_vision("$N动手把$n扎了起来。\n",me,arrow);
	arrows=new(__DIR__"arrow_set");
	arrows->copy(arrow);
	arrows->move(me);
	arrows->dest(me);
	return 1;
}
int do_da(string arg)
{
    object me=this_player(),bow;
    object ob=this_object();
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要把"+ob->query("name")+"搭在哪张弓上？\n");
        return 1;
    }
    if (!present(arg,me))
    {
        tell_object(me,"你要把"+ob->query("name")+"搭在哪张弓上？\n");
        return 1;
    }
    if (!present(arg,me)->query("is__bow"))
    {
        tell_object(me,"你只能把"+ob->query("name")+"搭在“弓”上！\n");
        return 1;
    }
	bow=present(arg,me);
	if (!bow->query("equipped"))
	{
		tell_object(me,"你必须先装备起这张"+bow->query("name")+"，再来搭箭。\n");
		return 1;
	}
    if (bow->query("arrow"))
    {
        tell_object(me,bow->query("name")+"上已经有一只箭了！\n");
        return 1;
    }
	if (bow->query("str_require")>me->query_str())
	{
		tell_object(me,"以你的臂力，并不能将"+bow->query("name")+"拉满，箭上弦。\n");
		return 1;
	}
	if (bow->query("xt_str_require")>me->query("str"))
	{
		tell_object(me,"以你的臂力，并不能将"+bow->query("name")+"拉满，箭上弦。\n");
		return 1;
	}
    message_vision("$N将一支"+ob->query("name")+"搭在"+bow->query("name")+"上。\n",me);
    bow->add("arrow_assist",ob->query("arrow_assist"));
    bow->set("extra_assist",ob->query("arrow_assist"));
    bow->set("arrow",1);
    bow->set("arrow_file",base_name(ob));
    destruct(ob);
    return 1;
}

