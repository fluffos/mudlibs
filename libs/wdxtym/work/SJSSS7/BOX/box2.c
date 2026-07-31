// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"合体宝箱"NOR,({"boxsv14"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是系统奖励的"+this_object()->query("name")+",\n使用(openbox boxsv14)"ZJURL("cmds:openbox boxsv14")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxsv14",1);
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
"/clone/good/enchase-symbol",
"/clone/good/enchant-scroll",
"/clone/good/forging-stone",
"/clone/good/hongmeng-lingqi",
"/clone/good/increase-stone",
"/clone/good/jiulonglu",
"/clone/good/practice-emblem",
"/clone/good/qianghua_crystal",
"/clone/good/research-emblem2",
"/clone/good/resolve-scroll",
"/clone/good/ring",
"/clone/good/ring0",
"/clone/good/ring1",
"/clone/good/ring2",
"/clone/good/ring3",
"/HCSP/XianFaSuiPian",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/clone/good/ring4",
"/clone/good/ring5",
"/clone/good/ring6",
"/clone/good/ring7",
"/clone/good/ring8",
"/clone/good/ring9",
"/clone/good/shengling_crystal",
"/clone/good/soul-stone",
"/clone/good/steady-stone",
"/clone/good/wangzhe-zhixin",
"/clone/good/wisdom_boots",
"/clone/good/wisdom_cloth",
"/clone/good/wisdom_head",
"/clone/good/wisdom_surcoat",
"/clone/good/wisdom_waist",
"/clone/good/wisdom_wrists",
"/clone/good/zhufu_armor",
"/clone/good/zhufu_blade",
"/clone/good/zhufu_boots",
"/clone/good/zhufu_cloth",
"/clone/good/zhufu_finger",
"/clone/good/zhufu_hammer",
"/clone/good/zhufu_hand",
"/clone/good/zhufu_head",
"/clone/good/zhufu_staff",
"/clone/good/zhufu_surcoat",
"/clone/good/zhufu_sword",
"/clone/good/zhufu_waist",
"/clone/good/zhufu_whip",
"/clone/good/zhufu_wrists",
"/clone/0/50jing",
"/clone/0/ouyezi-charm",
"/SJSSS7/GW1/JL/bg1",
"/SJSSS7/GW1/JL/bg2",
"/SJSSS7/GW1/JL/bg3",
"/SJSSS7/GW1/JL/bg4",
"/SJSSS7/GW1/JL/bg6",
"/SJSSS7/GW1/JL/bg7",
"/SJSSS7/GW1/JL/bg8",
"/SJSSS7/GW1/JL/bg11",
"/SJSSS7/GW1/JL/bg12",
"/SJSSS7/GW1/JL/bga1",
"/SJSSS7/GW1/JL/bga2",
"/SJSSS7/GW1/JL/bga3",
});

	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}

	message_vision(HIR"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一阵红色光华！"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(1)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIR"*****************************************************\n");
  tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIR"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}