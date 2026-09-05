//tang.c
//by hehe
//2003.3.18

#include <ansi.h>
inherit NPC;
int ask_hua();
int accept_object (object ob,object obj);

void create()
{

	set_name("唐光雄", ({ "tang guangxiong", "tang" }));
	set("title",HIG"无量剑派"NOR);
    set("gender", "男性");
    set("age", 20);      
	set("str", 25);
    set("int", 26);
    set("con", 26);
    set("dex", 26);
    set("combat_exp", 30000);
    set("shen_type", 1);
    set("attitude", "peaceful");
	set("max_qi",2000);
    set("max_jing",2000);
    set("neili",2000);
    set("max_neili",2000);
	set("jiali",0);
	set("score", 8000);

    set_skill("cuff", 60);
	set_skill("parry",60);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);

	map_skill("force","shenyuan-gong");
	        
    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    setup();
    set("inquiry", 
		([
			"秘密" : "给我点金创药，我就告诉你!\n",
			"茶花" : ( : ask_hua : ),

		]));
	set("chat_chance",20);
    set("chat_msg",({
		"唐光雄道：“快救我出去，我告诉你一个秘密！！！\n",
	}) );        
	carry_object(__DIR__"obj/shoes1")->wear();
    carry_object(__DIR__"obj/cloth")->wear(); 
}                          


int accept_object(object me, object ob)
{
	me=this_player();
	if(ob->query("name")=="金创药")
	{	
		remove_call_out("destory");
		command("eat jinchuang yao\n");
		call_out("destroy",1,me,ob);
		command("say 好吧，既然你救了我，我就告诉你这个秘密!\n");
		command("say 只有拿了茶花才能去见王夫人，否则会连小命都没了，切记!\n");
		me->set_temp("murong/jinchuang",1);
	}
	return 1;
}

int ask_hua()
{
	object me;
	me=this_player();
	object obj=this_object();
	if(!(me->query_temp("murong/jinchuang")))
		return" 不救我就想知道秘密，过分......!";
	me->delete_temp("murong/jinchuang");
	me->set_temp("murong/gongju");
	command("say 不过工具房的门是锁着的，钥匙在严妈妈那里！\n");
	command("say 茶花需要自己种，工具和种子都放在工具房!\n");
	message_vision("$n说完话，就匆匆忙忙得离开了......\n",me,obj);
	destruct(obj);
	return 1;
}