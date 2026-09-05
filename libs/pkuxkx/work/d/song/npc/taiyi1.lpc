#include <ansi.h>
inherit __DIR__"song_officer";
int ask_drug(int flag)
{
	if (flag==10)
	command("say 荆芥本是常用药，但近年战火纷飞，居然只有在北疆小镇才能买到。");
	if (flag==9)
	command("say 合欢长在张家口通往塞外的路上。");
	if (flag==8)
	command("say 覆盆子极难找到，据说只有关外长白山才有。");
	if (flag==7)
	command("say 按我的记忆，茯苓生长在昆明，江州附近马尾松下。");
	if (flag==6)
	command("say 按我的记忆，丁香在苏州，镇江的园子一般都可以找到。");
	if (flag==5)
	command("say 当归在苏州，扬州，晋阳的药铺一般都可以买到。");
	if (flag==4)
	command("say 常山一般长在福建、四川一带的山间坡旁。");
	if (flag==3)
	command("say 鱼腥草生长在江南，有水的地方一般能找到。");
	if (flag==2)
	command("say 薄荷在很多地方都能找到，一般有山的地方就有薄荷。");
	if (flag==1)
	command("say 鸡血藤一般长在云南、四川一带的山间坡旁。");
	return 1;
}

void create()
{
	call_out("npc_to_player",1,"翰林医官",70,-1);
	set("inquiry", ([
	
     "鸡血藤": (: ask_drug(1) :),
     "薄荷": (: ask_drug(2) :),
     "鱼腥草": (: ask_drug(3) :),
     "常山": (: ask_drug(4) :),
     "当归": (: ask_drug(5) :),
     "丁香": (: ask_drug(6) :),
     "茯苓": (: ask_drug(7) :),
     "覆盆子": (: ask_drug(8) :),
     "合欢": (: ask_drug(9) :),
     "荆芥": (: ask_drug(10) :),
	]));
	::create();
}

