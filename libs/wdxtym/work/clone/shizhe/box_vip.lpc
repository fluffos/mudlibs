// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"VIP宝箱"NOR,({"vipbox"}));
	set_weight(5000);
  
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long","这是系统奖励的"+this_object()->query("name")+",使用(openbox vipbox)"ZJURL("cmds:openbox vipbox")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("win_box",1);
	}
}
void init()
{
	if (environment()==this_player())
		add_action("do_openbox","openbox vipbox",1);
}
//打开宝箱的函数
int do_openbox()
{
	int i;
	int num=1;
	string obj=""; 
	object ob;

	//基本都是超级宝物.比如稀世宝石,神之宝石.
	string *box= ({
		"/clone/money/cash","/clone/gift/fjade","/clone/gift/fushougao","/clone/gift/god_eyes",
		"/clone/gift/feimao","/clone/gift/feidan","/clone/gift/fdiamond","/clone/gift/fcrystal",
		"/clone/gift/fagate","/clone/gift/shenliwan","/clone/gift/tianxiang",
		"/clone/gift/unknowdan","/clone/gift/xiandan","/clone/gift/xianxing","/clone/gift/xisuidan",
		"/clone/gift/jiuzhuan","/clone/gift/magate","/clone/gift/mcrystal","/clone/gift/mdiamond","/clone/gift/mjade",
	});
  
	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
	message_vision(HIM"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一道血色光华！"NOR"\n",me);
	i=random((int)sizeof(box));
    
	ob = new(box[i]); 
	if(ob->query("base_value"))
	{
		num=random(1)+1;
		ob->set_amount(num);
	}
	tell_object(me,""HIR"******************************************************\n");
	tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIR+"<< "+ob->query("name")+HIR+" >>"+NOR+"\n");
	tell_object(me,""HIR"*****************************************************"NOR"\n");
	ob->move(me); 
	destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}