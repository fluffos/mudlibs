
inherit NPC;
#include <ansi.h>
int do_cha(string arg);
mapping *name=({
(["name":"赵","id":"zhao",]),(["name":"钱","id":"qian",]),(["name":"孙","id":"sun",]),
(["name":"周","id":"zhou",]),(["name":"吴","id":"wu",]),(["name":"郑","id":"zheng",]),
(["name":"李","id":"li",]),(["name":"王","id":"wang",]),(["name":"刘","id":"liu",]),
(["name":"诸葛","id":"zhuge",]),(["name":"丁","id":"ding",]),(["name":"金","id":"jin",]),
});
void create()
{
   mapping newname;
   newname=name[random(sizeof(name))];
      set_name(newname["name"]+"老板",({ newname["id"]}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是[凤仪酒楼]的老板。\n");
       
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_neili",500);
   set("kee",800);
   set("max_jing",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
  
   setup();
   //carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
		add_action("do_cha","chazhang");
}
int do_cha(string arg)
{
	object me,ob,money;int exp,pot,sil;
	me=this_player();
	if(!arg||!present(arg,environment(me)))
		return notify_fail("你要向谁查帐？\n");
	if(!me->query_temp("chazhang_job/4"))
		return notify_fail("你没有来查帐的权利！\n");
	me->set_temp("busy_time",time());
	exp=me->query("max_pot")/3+random(10);
        pot=me->query("max_pot")/4;
	sil=pot/2;
	me->add("combat_exp",exp);
	me->add("potential",pot);
	if(me->query("potential")>me->query("max_pot"))
	me->set("potential",me->query("max_pot"));
	money=new("obj/money/silver");
	money->set_amount(sil);
	money->move(me);
	me->delete_temp("chazhang_job");
	me->delete_temp("dtsl_job");
	tell_object(me,"在这次行动中，你得到了："
               +""HIW""+chinese_number(exp)+""NOR""+"点经验值"
               +""HIW""+chinese_number(pot)+""NOR""+"点潜能"
               +""HIW""+chinese_number(sil)+""NOR""+"两白银\n");
	return 1;
}
