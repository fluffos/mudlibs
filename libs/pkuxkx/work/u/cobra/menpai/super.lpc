//////////////////////////////////////////
//	super.c by cobra
//////////////////////////////////////////
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIC"武林至尊"NOR,({"wulin zhizun","zhizun"}));
	set("gender","男性");
	set("age",1250);
	set("qi",100000);
	set("max_qi",100000);
	set("jing",100000);
	set("max_jing",100000);
	set("neili",100000);
	set("max_neili",100000);
	set("jingli",100000);
	set("max_jingli",100000);
	
	setup();	
}
void init()
{
	add_action("do_create","create");
	add_action("do_dismiss","dismiss");
}
int do_create(string arg)
{
	string name,*menpai=({});
	object me;
	int i ,size;
	me=this_player();
	if(wizardp(me)&&me->query("id",1)!="cobra")
		return notify_fail("巫师不要来搀和，小心我踢你ｐｐ！\n");
	if(!arg) return notify_fail(HIW"你要创立什么门派？\n"NOR);
	if( CREATE_D->is_exist_menpai(arg) )
		return notify_fail(HIW"已经有这个门派了！\n"NOR);
	name=CREATE_D->use_color(arg);
	if(me->query("repute")<2000000) return notify_fail(HIW"你一个无名小卒，还想什么开宗立派啊？\n"NOR);
	if(me->query("balance")<500000000) return notify_fail(HIW"你的家底太小了，不足以在江湖上维持门面。\n"NOR);
	if(me->query("自创门派/generation",1)==1)
		return notify_fail(HIW"你以为你有多大本事，可以独自统领两大帮派？\n"NOR);
	if(me->query("family",1))
	{
		write(HIW"你真的要脱离原来的门派并创立"+name+HIW"吗？(y/n):"NOR);
		write(HIW"你真的要脱离原来的门派并创立"+CREATE_D->remove_color(name)+"吗？(y/n):"NOR);
	}
	else
		write(HIW"你真的要创立"+name+"吗？(y/n):"NOR);
	me->set("自创门派/门派名称",name);
	me->set("自创门派/generation",1);
	input_to("confirm_create",me);
	return 1;
}
protected void confirm_create(string arg, object me)
{
	string file;
	if( arg=="")
	{
		write(HIW"你真的要脱离原来的门派并创立"+arg+"吗？(y/n):"NOR);
		input_to("confirm_create", me);
		return;
	}
	if( arg[0]!='y' && arg[0]!='Y' ) {
		write(HIW"这位"+RANK_D->query_respect(me)+HIW+"还是下次再来吧。\n"NOR);
		me->delete("自创门派");
		return;
	}
	if( ! CREATE_D->add_menpai(me->query("自创门派/门派名称",1)) )
		return notify_fail(HIW"创建门派失败！\n"NOR);
	me->set("family/generation",1);
	me->set("family/family_name",me->query("自创门派/门派名称",1));
	me->set("family/master_name",me->query("name",1) );
	me->set("family/master_id",me->query("id",1) );
	me->set("family/enter_time",time() );
	me->set("generation",1);
	write(HIW"你可以自己设置你的title(<颜色> <字符> ...):\n"NOR);
	input_to("get_title",me);
}
protected void get_title(string arg, object me)
{
	if(arg=="") 
	{
		write(HIW"你可以自己设置你的title(<颜色><字符> ...):\n"NOR);
		input_to("get_title",me);
		return;
	}
	if( !CREATE_D->is_legal_Chinese(arg) ) 
	{
		write(HIW"你的输入有误，请重试。\n"NOR);
		write(HIW"\n请重新设置你的title(<颜色><字符> ...):\n"NOR);
		input_to("get_title",me);
	}
	else
	{
		me->set("title",CREATE_D->use_color(arg));
		write("\n");
		message( "channel:" + "chat",HIW + "【公告天下】：『" + me->query("title",1)+HIW+"』"+me->query("name") + "于今日创立了"+me->query("自创门派/门派名称",1)+HIW+"，真是可喜可贺!\n"NOR,users());
	}
	return;
}
int do_dismiss()
{
	object me;
	int nSuccess;
	me=this_player();
	if(me->query("自创门派/generation",1)==1)
	{
		if(CREATE_D->remove_menpai(me->query("自创门派/门派名称",1) ))
		{
			message( "channel:" + "chat",HIW + "【公告天下】：『" + me->query("title",1)+HIW+"』"+me->query("name") + "于今日宣布解散"+me->query("自创门派/门派名称",1)+HIW+"，可惜啊可惜!\n"NOR,users());
			me->delete("family");
			me->delete("自创门派");
			me->set("title","普通百姓");
		}
		else
			write("解散门派失败！\n");
	}
	else
		write(HIW"哈哈，你还没有自立门户就想吵人鱿鱼？\n"NOR);
	return 1;
}
