// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"剑徒宝箱"NOR,({"boxs4a2"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是系统奖励的"+this_object()->query("name")+",\n使用(openbox boxs4a2)"ZJURL("cmds:openbox boxs4a2")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxs4a2",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj="";
   object ob;
 /*
   * 金块,D1套装，打造材料,九转
  */
   string *box=
({
"/HELL4/GuaiWu2/JL/bg1",
"/HELL4/GuaiWu2/JL/bg2",
"/HELL4/GuaiWu2/JL/bg3",
"/HELL4/GuaiWu2/JL/bg4",
"/HELL4/GuaiWu2/JL/bg6",
"/HELL4/GuaiWu2/JL/bg7",
"/HELL4/GuaiWu2/JL/bg8",
"/HELL4/GuaiWu2/JL/bg11",
"/HELL4/GuaiWu2/JL/bg12",
"/HELL4/GuaiWu2/JL/xwk1",
"/HELL4/GuaiWu2/JL/xwk2",
"/HELL4/GuaiWu2/JL/xwk3",
"/HELL4/GuaiWu2/JL/xwk4",
"/HCSP/sp18",
"/HELL4/GuaiWu2/JL/xwk5",
"/HELL4/GuaiWu2/JL/dqk1",
"/HELL4/GuaiWu2/JL/dqk2",
"/HELL4/GuaiWu2/JL/dqk3",
"/HELL4/GuaiWu2/JL/dqk4",
"/HELL4/GuaiWu2/JL/dqk5",
"/HELL4/GuaiWu2/JL/xwk1",
"/HELL4/GuaiWu2/JL/xwk2",
"/HELL4/GuaiWu2/JL/xwk3",
"/HELL4/GuaiWu2/JL/xwk4",
"/HELL4/GuaiWu2/JL/xwk5",
"/HELL4/GuaiWu2/JL/dqk1",
"/HELL4/GuaiWu2/JL/dqk2",
"/HELL4/GuaiWu2/JL/dqk3",
"/HELL4/GuaiWu2/JL/dqk4",
"/HELL4/GuaiWu2/JL/dqk5",
"/HELL4/GuaiWu2/JL/xwk1",
"/HELL4/GuaiWu2/JL/xwk2",
"/HELL4/GuaiWu2/JL/xwk3",
"/HELL4/GuaiWu2/JL/xwk4",
"/HELL4/GuaiWu2/JL/xwk5",
"/HELL4/GuaiWu2/JL/dqk1",
"/HELL4/GuaiWu2/JL/dqk2",
"/HELL4/GuaiWu2/JL/dqk3",
"/HELL4/GuaiWu2/JL/dqk4",
"/HELL4/GuaiWu2/JL/dqk5",
});

	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}

	message_vision(HIC"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一阵紫色光华！"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(1)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIC"*****************************************************\n");
  tell_object(me,""HIC"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIC"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}