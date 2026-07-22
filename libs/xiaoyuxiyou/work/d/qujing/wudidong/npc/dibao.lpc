#include <ansi.h>
inherit NPC;

mixed reply_about_monks()
{
	object me = this_player();
	tell_object(me,CYN+name()+CYN"说道：听说村里的小庙闹鬼了，也不知道怎么回事。"NOR"\n");
  	tell_object(me,CYN+name()+CYN"说道：唉，我早就说过不该弄那么个破庙。这不？连方丈都给抓去了。"NOR"\n");
  	return 1;
}

string ask_for_rumors()
{
	object me = this_player();
	tell_object(me,CYN+name()+CYN"说道：唉，近日老有些大老鼠跑来跑去，不知会不会糟蹋庄稼。"NOR"\n");
	tell_object(me,CYN+name()+CYN"说道：村里老张家又出了事，听说犁头被个铁骷髅碰断了。唉。"NOR"\n");
}

void create()
{
  set_name("张弟宝",({"zhang dibao","zhang","dibao"}));
  set("title","地保");
  set("gender", "男性");
  set("age", 40);
  set("long","张地保的爹娘似乎生他时就知他要当地保，给他取了这么个好名字。\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "friendly");
  set("inquiry", ([
		   "name" : "在下姓张，忝为本村地保。",
		   "here" : "这里是张村儿，都姓张。",
		   "rumors" : (: reply_about_monks :),
		   "方丈" : "也不知哪位大英雄有本事把他搭救出来。全村上下这两天都人心惶惶的。",
		   ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
