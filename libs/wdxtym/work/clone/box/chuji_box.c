// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"初级宝箱"NOR,({"box no1"}));
	set_weight(5000);
	set_max_encumbrance(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","这是系统奖励的"+this_object()->query("name")+",\n"ZJURL("cmds:openbox boxno1")ZJSIZE(15)"打开"NOR"看看，有好东西哦!\n");
		set("unit","个");
		set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno1",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj=""; 
   object ob;
/*
    铜钱,退烧药,膏药,伤寒愁,糖果,新手套装,酒袋,鸡腿,基本内功,基本拳脚,三字经,乱七八糟
*/
   string *box=
({
"/clone/money/silver",
"/clone/misc/shoeshine",
"/clone/food/jitui","/clone/food/jiudai",
"/clone/suit/new/new_sword","/clone/suit/new/new_blade","/clone/suit/new/new_cloth","/clone/suit/new/new_pants","/clone/suit/new/new_boots",
"/clone/book/basic-force","/clone/book/basic-unarmed","/clone/book/basic-dodge","/clone/book/lbook1","/clone/book/lbook2","/clone/book/lbook3",
"/clone/cloth/dao-xie","/clone/cloth/cuttonp",
"/clone/gift/icecream-vanilla","/clone/gift/icecream-chocolate","/clone/gift/tang",

});
  
    object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
    message_vision(HIW"$N轻轻打开["+this_object()->query("name")+HIW"]的盖子,宝箱发出一阵耀眼的光华！"NOR"\n",me);

    i=random((int)sizeof(box));
    
    ob = new(box[i]); 
      if(ob->query("base_value"))
    {
       num=random(30)+1;
       ob->set_amount(num);
    }
  tell_object(me,""HIG"*****************************************************\n");
  tell_object(me,""HIR"恭喜"NOR"：你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIG+"["+ob->query("name")+HIG"]"+NOR+"\n");
 	tell_object(me,""HIG"*****************************************************"NOR"\n");
    ob->move(me); 
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}