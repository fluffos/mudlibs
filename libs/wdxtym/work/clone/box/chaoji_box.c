// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIY"超级宝箱"NOR,({"boxno4"}));
	set_weight(5000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是系统奖励的"+this_object()->query("name")+",\n"ZJURL("cmds:openbox boxno4")ZJSIZE(15)"打开"NOR"看看，有好东西哦!\n");
	    set("unit","个");
	    set("win_box",1);
	    
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno4",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj=""; 
   object ob;
   /*
   * 银票,退烧药,膏药,伤寒愁,糖果,新手套装,酒袋,鸡腿,秘籍秘要,百家姓,
  */
   string *box=
({
"/clone/money/gold","/clone/misc/fashao","/clone/misc/gaoyao","/clone/misc/shanghan","/clone/gift/tang","/clone/food/jiudai","/clone/food/jitui","/clone/book/advance-blade",
"/clone/book/expert-club","/clone/book/expert-dagger","/clone/book/expert-dodge","/clone/book/expert-force","/clone/book/expert-parry","/clone/book/expert-unarmed","/clone/book/expert-sword","/clone/book/expert-staff","/clone/book/expert-throwing",
"/clone/book/expert-whip","/clone/book/lbook3",
"/clone/gift/agate","/clone/gift/cagate","/clone/gift/ccrystal","/clone/gift/cdiamond",
"/clone/gift/cjade","/clone/gift/crystal","/clone/gift/diamond","/clone/gift/jade",
"/clone/gift/jinkuai",
});
  
    object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
    message_vision(HIG"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一阵金色光华！"NOR"\n",me);
    i=random((int)sizeof(box));
    
    ob = new(box[i]); 
    if(ob->query("base_value"))
    {
       num=random(3)+1;
       ob->set_amount(num);
    }
   tell_object(me,""HIY"*****************************************************\n");
  tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIY+"<< "+ob->query("name")+HIY+" >>"+NOR+"\n");
 tell_object(me,""HIY"*****************************************************"NOR"\n");
    ob->move(me); 
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}