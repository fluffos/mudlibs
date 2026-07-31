// guofu.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_huijia();
string ask_daojia();
void create()
{
    set_name("郭襄", ({"guo xiang", "guo", "xiang"}));
    set("gender", "女性");
    set("age", 15);
    set("long", "她是郭靖黄蓉的小女儿，东邪黄药师的小外孙女，长得什么可爱。\n");

    set("attitude", "peaceful");
       
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 0);
       
    set("combat_exp", 80000);
    set("score", 0);
       
    set_skill("force", 80);
    set_skill("bibo-shengong", 80);
    set_skill("unarmed", 80);
    set_skill("luoying-zhang", 80);
    set_skill("dodge", 80);
    set_skill("anying-fuxiang", 80);
    set_skill("parry", 80);
    set_skill("sword", 80);
    set_skill("luoying-shenjian", 80);
    set_skill("qimen-wuxing", 80);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
         set("inquiry", ([
        "营救" : (:ask_huijia:) ,
        "到了" : (:ask_daojia:) ,
         ]) );      
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query_temp("lingjiujob") )
	this_player()->start_busy(1);

}


string ask_huijia()
{
	int i;
	object who,where,fang;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(((int)me->query("jinyong/book10")!=7))
return "我不认识你啊。。。\n";

        fang = present("jinlun fawang",where);
	if(fang)
	{
		who->start_busy(3);
return "金轮法王在，能帮我对付她吗? \n";
	}
if (!ob->query("killfw"))
{
      	fang = load_object(__DIR__"fawang");
	fang->move(environment(who));	
	fang->kill_ob(who);
ob->set("killfw",1);
set("killfw",1);
}

if(!me->query_temp("book10101"))
return "我只相信打败金轮法王的大英雄。\n";

me->set_temp("lingsong",1);
set_leader(me);
ob->set("lingsong",10);
return "如果能送我回襄阳大街口。我父母会好好感谢你的。\n";
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

if(((int)me->query("jinyong/book10")!=7))
return "我不认识你啊。。。\n";

 if( environment(ob)->query("short")=="大街口")
         {




          set_leader(0);
          write("终于到襄阳了，多谢你的帮忙。\n");

  	if(((int)me->query("jinyong/book10")==7))
	{
		
 	i = 2000+random(3900);
	me->set("jinyong/book10",8);
	me->add("combat_exp",i+31880);
	me->add("potential",i*28);
	me->add("mpgx",20);
	me->add("expmax",2);

	tell_object (me,"你赢得了"+chinese_number(i+31880)+"点经验"+
	           chinese_number(i*28)+"点潜能"+"二十点门派贡献 二点成长上限！！\n");
message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了神雕侠侣的所有任务!"NOR"\n", users());
		
         }		

             me->set_temp("lingjiujob",0);
me->set_temp("lingsong",0);
             me->apply_condition("lingjiu_song",0);
        call_out("leavet",1);
	  
           return "我去找我二姐去了.....\n";  
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