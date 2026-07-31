//snowman 28/02/98
#include <ansi.h>
inherit NPC;
int j=2;
int ask_rob();
void create()
{
        set_name(HIM"大富商"NOR, ({ "fu shang"}));
       set("long",
                "一名当代富商，长的肥头大耳，但他富可敌国。\n");
        set("attitude", "friendly");
        set("gender", "男性");
        set("age", 58);
        set("per", 24);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);
	 set_temp("no_kill",1);
        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("env/wimpy", 40);
        setup();
        carry_object("d/gumu/npc/obj/baipao")->wear();
}

void init()
{
  add_action("do_rob", "qiangjie");
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
if (ob->query_temp("owner/id")!=me->query("id"))
return notify_fail("这种事你也做的出来！\n");
	if(environment(me)->query("no_fight"))
		return notify_fail("这里不许打斗！\n");
   if(objectp(present("baobiao", environment(me))))
       return notify_fail("这几个保镖看来武功不弱，你还是先打发了面前这个再说吧！\n");  
        ob->start_busy(60);
   message_vision(HIM"$N对着$n一声大笑："+me->name()+"在此！你这死猪哪里走??\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
          me->start_busy(3);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}

void make_bs(object me, object ob)
{
   object obj, obj1;
	if (j>0){
	  obj = new(__DIR__"xiake");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"xiake");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          j=j-1;     
        ob->start_busy(60);          
          }
else {
       message_vision(HIW"$N见已经无人保护，把富商打昏了！\n"NOR, me);    
       ob->unconcious();
//       me->add("combat_exp",100);
//       me->add("potential",50);
       message_vision(HIR"$N好像变强了一些！\n"NOR, me);    
       me->delete_temp("rob_start");
       me->delete_temp("xx_rob");
       me->delete_temp("rob_job");
       me->delete_temp("j");       
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
        set("max_qi", 25000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("peace " + ob->query("id"));
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
        command("peace " + ob->query("id"));
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "富商向一处人家逃走了，不见了。\n" NOR,this_object());
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
