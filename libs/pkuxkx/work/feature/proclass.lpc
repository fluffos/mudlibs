// proclass.c
// 返回非武者其他职业的一些参数 Zine@pkuxkx 2014/7/9

#include <dbase.h>
#include <ansi.h>
mapping title=(["alchemy":"药师","herbalism":"采药师","smithing":"锻造师","mining":"采矿师"]);
mapping allowed_sk_limit=(["alchemy":99,"herbalism":61,"smithing":99,"mining":61]);
string *class_alchemy=({"alchemy","herbalism"}),*class_smith=({"smithing","mining"});
void register_me(object me,string my_class)
{
	int i;
	if (member_array(my_class,class_alchemy)!=-1)
	{
		for (i=0;i<sizeof(class_smith);i++)
		if (me->query("ProfessionalClass/"+class_smith[i]))
		{
			tell_object(me,RED+"你是一名"+title[class_smith[i]]+"，无法在药师领域继续前进了。\n"+NOR);
			return;
		}
	}
	if (member_array(my_class,class_smith)!=-1)
	{
		for (i=0;i<sizeof(class_alchemy);i++)
		if (me->query("ProfessionalClass/"+class_alchemy[i]))
		{
			tell_object(me,RED+"你是一名"+title[class_alchemy[i]]+"，无法在锻造领域继续前进了。\n"+NOR);
			return;
		}
	}
	me->set("ProfessionalClass/"+my_class,1);
	tell_object(me,HIW+"恭喜你！成为了一名"+title[my_class]+"，可以在这个领域里继续探索。\n"+NOR);
}
//如果有2种以上非武者职业，返回用最高核心技能的职业
void unregister_me(object me,string my_class)
{
	string msg="\n";
	if (me->query_skill(my_class,1)>allowed_sk_limit[my_class])
	{
		me->set_skill(my_class,allowed_sk_limit[my_class]);
		msg="因此，你的"+to_chinese(my_class)+"被恢复到"+HIR+allowed_sk_limit[my_class]+NOR+"级。\n";
	}
	tell_object(me,"你放弃了"+title[my_class]+"的身份。");
	tell_object(me,msg);
}
string pro_class(object me)
{
	string my_pro,*my_pros;
	int apex;
	if (!me->query("ProfessionalClass")||!mapp(me->query("ProfessionalClass")))
	return "fighter";
	else
	{
		my_pros=keys(me->query("ProfessionalClass"));
		for (int i=0;i<sizeof(my_pros);i++)
		if (me->query_skill(my_pros[i],1)>=apex)
		{
			apex=me->query_skill(my_pros[i],1);
			my_pro=my_pros[i];
		}
	}
	return my_pro;
}