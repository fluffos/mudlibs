#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "『峨嵋派入门指南』" NOR, ({ "rumen zhinan", "zhinan" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long",@LONG         
峨嵋派入门

武功:
    blade  yanxing-dao
    sword fuliu-jian
    finger tiangang-zhi
    strike jinding-mianzhang
    force linji-zhuang
    throwing pili-dan
    dodge zhutian
  perform 
    blade (正在做)
    strike (正在做)
    sword 灭剑 perform sword.miejian
              降敌人的攻防
    throwing 弹 perform throwing.tan sb.
              用霹雳弹伤人，耗霹雳弹一粒
  
拜师:
    在山门有文虚师太收非本派之徒,直接拜师即可.
收徒的五代峨嵋弟子有文字辈五人(出家),俗家数人.
升级条件: 
         ask miejue about 峨嵋令
         give ling to (师傅辈收徒的npc)
         fight npc (得到介绍信)
         give jieshao-xin1 to (师祖辈收徒的npc)
         bai this npc
下山条件:
         ask miejue about 下山
         进蛇窟发现有四条毒蛇,杀之,进入蛇窟尽头就可回去复命了.
         ask miejue about 下山    
         PS:蛇窟是每有人进入就clone出四条毒蛇.
其他指令:
         在伙房可以(work),一次耗50气,停5秒,得一两银子
         在膳房可以(yao),一次耗30精,停5秒,得到你要吃的和喝的.
         在神灯阁可以(fill sth),灌水.
         在后殿静和师台那可以(ling mudao,ling zhujian).
             PS:zhujian and mudao no value,但扔地上还在.
         在后山可以(search)到草药,人参什么的,草药拿到
             药王洞里可以交给静慈师太配药得到金疮药. 
         PS:有时会搜出一条毒蛇。
         caoyao恢复上限5，zhongyao恢复上限10，
         renshen加内力上限5，但每次编译最多search到两个
         可以在山洞里(search)到硫磺，交给静慈师太可以炼制霹雳弹
         在千佛庵大门有小贩可以买一些日常用品.
         在山门殿有小贩可以卖掉不用的东西.
         上金顶可以用静坐的方法提高自己的潜能.
             PS:上金顶要过云海,这是一个随机迷宫,每次路都不一样.
秘密:
         本派有四种perform,
         本派弟子(未叛师)还有几率加天资(正在做)
LONG );


		set("value", 50);
		set("material", "paper");
	}
	setup();
}
