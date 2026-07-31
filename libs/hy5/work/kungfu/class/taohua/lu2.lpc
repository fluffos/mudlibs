//yan.c
#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();


void create()
{
        object ob;

        set_name("陆无双", ({ "lu wushuang","wushuang" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
陆无双本该是陆家庄的千金小姐，享尽荣华富贵。父母却遭李莫愁屠杀
，她侥幸得命，跛了左足。被仇人李莫愁收为徒弟。
TEXT );
        set("per", 30);
        set("nickname", HIG "陆家千金" NOR);
        set("class", "scholar");
set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 1200000);
	set("score", 50000);

	set_skill("blade",200);
	set_skill("ruyi-dao",200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("lingboweibu", 200);
	set_skill("beiming-shengong",200);
	set_skill("liuyang-zhang", 200);
	set("chat_chance_combat", 30);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
           
	}) );
	map_skill("unarmed", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");

        set("force", 500);
        set("max_force", 500);
        set("force_factor",0);

        set("inquiry", ([
        "护送" : (:ask_huijia:) ,
        "到了" : (:ask_daojia:) ,
         ]) );
        //create_family("桃花岛", 3, "弟子");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}



void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("lingjiujob") )
	this_player()->start_busy(1);

}

void leave()
{
        object ob = this_object();
        if (ob->query("lingsong") == 0) {
                message_vision(HIG "陆无双见无人来接应,自己离开了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(((int)me->query("jinyong/book10")!=1))
return "我不认识你啊。。。\n";

me->set_temp("lingsong",1);
set_leader(me);
ob->set("lingsong",10);
return "这位朋友，如果能送我回嘉兴南湖。我会好好感谢你的。\n";
}

string ask_daojia()
{
 object ob,me;
int exp,pot,base_exp;
	int i;
	object fang,who,where;
ob = this_object();
me = this_player();
	who=me;
	where = environment(who);


if(me->query_temp("lingsong") == 0 )
return "我不认识你啊。。。\n";

if(((int)me->query("jinyong/book10")!=1))
return "我不认识你啊。。。\n";

 if( environment(ob)->query("short")=="嘉兴南湖")
         {




        fang = present("li mochou",where);
	if(fang)
	{
		who->start_busy(3);
return "我师父在，能帮我对付她吗? \n";
	}



          set_leader(0);
          write("终于到嘉兴南湖了，多谢你的帮忙。听说襄阳要举行武林大会了。我会去看看的。\n");

  	if(((int)me->query("jinyong/book10")==1))
	{
		
 	i = 900+random(2900);
	me->set("jinyong/book10",2);
	me->add("combat_exp",i+11880);
	me->add("potential",i*18);
	me->add("mpgx",10);
	me->add("expmax",2);

	tell_object (me,"你赢得了"+chinese_number(i+11880)+"点经验"+
	           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");

		
         }		

             me->set_temp("lingjiujob",0);
me->set_temp("lingsong",0);
             me->apply_condition("lingjiu_song",0);
        call_out("leavet",1);
	  
           return "我去找我表姐去了.....\n";  
      }
        else {
                return "还没到呢!你想不管了吗?\n";
        }
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用guard！\n");
        return 1;
}

void leavet()
{
        object ob = this_object();
        destruct(this_object());
}

void unconcious()
{            
	::die();       
}	