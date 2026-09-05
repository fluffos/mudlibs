#include <ansi.h>
int tianlong(object me,int index)
{
	string name=me->query("name"),name1,name2,color;
	color=COLOR_D->get_color(name);
	name=COLOR_D->uncolor(name);
	name1=name[0..0];
	name2=name[strwidth(name)-2..strwidth(name)-1];
	me->set("class","monk");
	if (me->query("family/generation")==15)
	{
		name="本"+name2;
	}
	else
	{
		name="了"+name1;
	}
	name=color+name+NOR;
	if (index==1)
	{
		command("say 既然你愿意出家避位，那么从今以后你就叫做"+name+"吧。\n");
	}
	else if (index==2)
	{
		command("say 好吧，从今以后你就跟我学习吧。\n");
		return 1;
	}
	else
	{
		command("say 善哉，善哉，希望你今后能广大我派。");
		command("say 从次以后，你法号"+name+"。");
	}
	me->set("name",name);
	return 1;
}