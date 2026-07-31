//snowman 28/02/98
#include <ansi.h>
inherit NPC;
int j=2;
int ask_rob();
string * name1 = ({ "王","张","李","薛","齐","任","黄","郭","欧阳","南宫"}); 
string * name2 = ({ "格格", "公主","小姐","姑娘","夫人","郡主" }); 

void create()
{
	string name = name1[random(sizeof(name1))] + name2[random(sizeof(name2))];
	set_name(name, ({ "mei nu" }));
        set("title",HIM"绝世美女"NOR);
	set("long", "这是位有闭月羞花之貌的绝色美女，在保镖的保护下悠闲的游山玩水。\n");        set("attitude", "friendly");
        set("gender", "女性");
        set("age", 18);
        set("per", 40);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);
        set("qi", 3500);
	 set_temp("no_kill",1);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("env/wimpy", 40);
        setup();
        carry_object("d/gumu/npc/obj/baipao")->wear();
}

void init()
{
  add_action("do_rob", "qiangmeinu");
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
//   arg = query("arg");

//   if(!(arg||arg=="ok")) return 0;
//   if(!living(me)) return 0;
//   if(!me->query_temp("rob_start")) 
//       return notify_fail("美女大叫一声,救命!!\n");
if (ob->query_temp("owner/id")!=me->query("id"))
return notify_fail("这种事你也做的出来！\n");
	if(environment(me)->query("no_fight"))
		return notify_fail("这里不许打斗！\n");
   if(objectp(present("xiake", environment(me))))
       return notify_fail("这几个侠客看来武功不弱，你还是先打发了面前这个再说吧！\n");  
        ob->start_busy(100);
   message_vision(HIM"$N对着$n一声淫笑："+me->name()+"在此！小娘子哪里走??\n"NOR, me, ob);
          me->start_busy(3);
   me->set_temp("xx_rob", 1);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}

void make_bs(object me, object ob)
{
   object obj, obj1;
	if (j>0){
//          me->start_busy(2);
        ob->start_busy(60);          
	  obj = new(__DIR__"xiake");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"xiake");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          j=j-1;     }
else {
       message_vision(HIW"$N见已经无人保护，把美女吓昏了！\n"NOR, me);    
       ob->unconcious();
//       me->add("combat_exp",100);
//       me->add("potential",50);
       message_vision(HIR"$N口水流了一地,好像变强了一些！\n"NOR, me);    
       me->delete_temp("rob_start");
       me->delete_temp("xx_rob");
       me->delete_temp("rob_job");
       me->delete_temp("j");       
//       message_vision("$N转过几个小山丘就不见了。\n",ob);
//       destruct(ob);
    }
}

void kill_ob(object ob)
{
	command("fear");
	command("!!!");

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
	command("fear");
	command("shake");
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
                message_vision(HIC "美女向一处人家逃走了，不见了。\n" NOR,this_object());
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
