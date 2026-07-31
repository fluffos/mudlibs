// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIB"中级宝箱"NOR,({"boxno2"}));
	set_weight(5000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是系统奖励的"+this_object()->query("name")+",使用(openbox boxno2)"ZJURL("cmds:openbox boxno2")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	   set("win_box",1);  //是否是奖励的箱子
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno2",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj=""; 
   object ob;
  /*
   * 银子,退烧药,膏药,伤寒愁,糖果,新手套装,酒袋,鸡腿,基本入门密集,三字经,,凝碧剑
  */
   string *box=
({
"/clone/money/silver","/clone/misc/fashao","/clone/misc/gaoyao","/clone/misc/shanghan","/clone/gift/tang","/clone/suit/new/new_boots","/clone/suit/new/new_pants", "/clone/suit/new/new_cloth","/clone/food/jiudai","/clone/food/jitui","/clone/book/basic-blade",
"/clone/book/basic-club","/clone/book/basic-dagger","/clone/book/basic-dodge","/clone/book/basic-force","/clone/book/basic-parry","/clone/book/basic-unarmed","/clone/book/basic-sword","/clone/book/basic-staff","/clone/book/basic-throwing",
"/clone/book/basic-whip","/clone/book/lbook1","/clone/weapon/green_sword",
"/clone/misc/xiaoshu","/clone/gift/icecream-chocolate","/clone/gift/icecream-vanilla",
"/clone/cloth/tiejia",
});
  
    object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
    message_vision(HIB"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一道蓝色光华！"NOR"\n",me);
    i=random((int)sizeof(box));
    
    ob = new(box[i]); 
     if(ob->query("base_value"))
    {
       num=random(15)+1;
       ob->set_amount(num);
    }
  tell_object(me,""HIB"*****************************************************\n");
  tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIB+"<< "+ob->query("name")+HIB+" >>"+NOR+"\n");
 tell_object(me,""HIB"*****************************************************"NOR"\n");
    ob->move(me); 
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}