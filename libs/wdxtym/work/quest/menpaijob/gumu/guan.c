//snowman 28/02/98
#include <ansi.h>
inherit NPC;
int j=3;
int ask_rob();
void create()
{
        set_name(HIR"蒙古元师"NOR, ({ "yuanshuai"}));
       set("long",
                "一名蒙古元师。\n");
        set("attitude", "friendly");
        set("gender", "男性");
        set("age", 38);
        set("per", 40);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);
	 set_temp("no_kill",1);
        set("qi", 3500);
        set("no_kill", 1);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("env/wimpy", 40);
        set("chat_chance", 99);
	set("chat_msg_combat", ({
		(: command("get all") :),
		(: command("get skeleton") :),
                      }) );
        setup();
        carry_object("d/gumu/npc/obj/baipao")->wear();
}

void init()
{
  add_action("do_rob", "shayuanshuai");
  add_action("do_quit","exert");
  add_action("do_guard", "halt");
        remove_call_out("leave");
        call_out("leave",600);
//        call_out("leave",10);
}

int do_rob()
{
   object me, ob;   
   string arg;
   int stage, i;
   me = this_player();
   ob = this_object();
   stage = 0;
	if(environment(me)->query("no_fight"))
		return notify_fail("这里不许打斗！\n");
   if(!living(ob))
   return notify_fail("没有人你杀谁啊!!\n"); 
   if(objectp(present("fawang", environment(me))))
   return notify_fail("这几个蒙古护教法王看来武功不弱，你还是先打发了面前这个再说吧！\n");  
   if(objectp(present("weishi", environment(me))))
   return notify_fail("这几个蒙古兵看来武功不弱，你还是先打发了面前这个再说吧！\n");  
   message_vision(HIM"$N对着$n一声大叫："+me->name()+"在此！你这蒙古元师哪里走??\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   me->start_busy(2);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}

void make_bs(object me, object ob)
{
   object obj, obj1;
   int exp,pot;
	if (j>0){
 
        if (random(3) == 0)
        {
if (me->query("combat_exp") > 6000000)
{
	  obj = new(__DIR__"xueshan1");
	obj->set("title",HIR"蒙古护国法王"NOR);
}
	}
       else
        if (random(3) == 1)
        {
if (me->query("combat_exp") > 6000000)
{
	  obj = new(__DIR__"xueshan2");
	obj->set("title",HIR"蒙古护国法王"NOR);

}
	}
       else
        if (random(3) == 2)
        {
	  obj = new(__DIR__"xueshan3");
	obj->set("title",HIR"蒙古护国法王"NOR);
	}
else{
obj = new(__DIR__"mengubing");
obj->set("title",HIG"蒙古亲兵"NOR);
}
         obj->move(environment(me));
	 obj->do_copy(me);
if (me->query_skill("jiuyin-zhengong",1) > 300)
{
        obj->set_temp("apply/attack", 200);
        obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 800);
        obj->set_temp("apply/damage", 300);
}

	if ( obj->query("id")=="weishi")
	{
	obj->set("title",HIG"蒙古亲兵"NOR);
	}
	  obj->do_copy(me);
         obj1 = new(__DIR__"mengubing");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
	obj1->set("title",HIY"蒙古亲兵"NOR);
          j=j-1;     
          obj->do_copy(me);
if (me->query_skill("jiuyin-zhengong",1) > 300)
{

        obj->set_temp("apply/armor", 800);
        obj->set_temp("apply/damage", 300);
}

          obj1->do_copy(me);
if (me->query_skill("jiuyin-zhengong",1) > 300)
{
        obj1->set_temp("apply/armor", 800);
        obj1->set_temp("apply/damage", 300);
}

          me->start_busy(1);
          }
else {
        message_vision(HIW"$N见已经无人保护，把蒙古元师一刀杀了！\n"NOR, me);    
    if (me->query("kill_gumu") == 1) {
       message_vision(HIG"$N为国除害,武功有了进展！\n"NOR, me);    
exp=660 + random(900);
pot=440 + random(650);
       me->add("combat_exp",exp);
       me->add("potential",pot);
   tell_object(me, "你被奖励了"+chinese_number(exp)+"点修为值！\n"+chinese_number(pot)+"点潜能\n");
       me->set("kill_gumu",0);
       write(HIW"你完成了任务,大笑几声,该撤退了.\n");
       write(HIR"你终于逃出了蒙古军大营.\n"NOR);
       me->move("/d/xiangyang/southgate2");
       }
       ob->die();
    }
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        ob->remove_enemy(this_object());
        remove_killer(ob);
        remove_all_killer();
	remove_all_enemy();
        set("qi", 50000);
        set("eff_qi", 25000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("eff_qi", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("say 本师不会,武功打什么打??");
 message_vision(HIC "请用shayuanshuai来做。\n" NOR,ob);
}

void fight_ob(object ob)
{
        ob->remove_killer(this_object());
        ob->remove_enemy(this_object());
        remove_killer(ob);
        remove_all_killer();
	remove_all_enemy();
        set("qi", 50000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("say 本师不会,武功打什么打??");
        message_vision(HIC "请用shayuanshuai来做。\n" NOR,ob);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "蒙古元师逃了出去，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"，这里不能用roar吧！\n");
        return 1;
	}
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用halt！\n");
        return 1;
}
