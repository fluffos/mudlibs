//snowman 28/02/98
#include <ansi.h>
inherit NPC;
int j=3;
int ask_rob();
void create()
{
        set_name(HIR"贪官"NOR, ({ "guan"}));
       set("long",
                "一名贪官。\n");
        set("attitude", "friendly");
        set("gender", "男性");
        set("age", 38);
        set("per", 40);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);
	 set_temp("no_kill",1);
        set("no_kill", 1);
        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("env/wimpy", 40);
        setup();
        carry_object("d/gumu/npc/obj/baipao")->wear();
}

void init()
{
  add_action("do_rob", "shaguan");
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
   if(objectp(present("weishi", environment(me))))
       return notify_fail("这几个大内高手看来武功不弱，你还是先打发了面前这个再说吧！\n");
        ob->start_busy(60);
   message_vision(HIM"$N对着$n一声大叫："+me->name()+"在此！你这贪官哪里走??\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   me->start_busy(3);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob);
   return 1;
}

void make_bs(object me, object ob)
{
   object obj, obj1;
int exp,pot;
	if (j>0){
	  obj = new(__DIR__"xiake");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"xiake");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          me->start_busy(2);
          j=j-1;
          }
else {
        message_vision(HIW"$N见已经无人保护，把贪官一刀杀了！\n"NOR, me);
    if (me->query("taohuajob") == 1) {
       message_vision(HIG"$N为明除害,武功有了进展！\n"NOR, me);
exp=480 + random(700);
pot=350 + random(400);
       me->add("combat_exp",exp);
       me->add("potential",pot);
       me->set("taohuajob",0);
tell_object(me,"你被奖励了\n"+chinese_number(exp)+"点实战修为\n"
		+chinese_number(pot)+"点潜能\n");
       message_vision(HIW"$N见已经无人保护，把贪官一刀杀了！\n"NOR, me);
       message_vision(HIR"$N一下子跳回了自己的船，回归云庄报喜去了!\n"NOR, me);
       me->move("/d/guiyun/matou");
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
		//remove_all_enemy();
        set("qi", 50000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("say 本官不会,武功打什么打??");
        message_vision(HIC "请用shaguan来抢船。\n" NOR,ob);
}

void fight_ob(object ob)
{
        ob->remove_killer(this_object());
        ob->remove_enemy(this_object());
        remove_killer(ob);
        remove_all_killer();
		//remove_all_enemy();
        set("qi", 50000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("say 本官不会,武功打什么打??");
        message_vision(HIC "请用shaguan来抢船。\n" NOR,ob);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "贪官逃下了船，不见了。\n" NOR,this_object());
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
