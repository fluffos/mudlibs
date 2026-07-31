#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY "皇太后" NOR, ({ "empress","queen"}));
        set("shen_type", 0);
        set("age",43);
        set("gender", "女性");
        set("per",24);
        set("long",
                "她生得矮矮胖胖，也许是终年不见阳光，所以她的脸色显得很苍白。\n");
        set("max_neili",5000);
        set("max_jingli",4000);
        set("jingli",4000);
        set_skill("unarmed",200);
        set_skill("parry",200);
        set_skill("sword",200);
        set_skill("force",200);
        set_skill("throwing",200);
        set_skill("taoism",200);
        set_skill("literate",200);
        set("chat_chance", 5);
        set("chat_msg", ({
"皇太后说道：小桂子知道的事太多了，不堵住他的嘴，我睡也睡不着．\n",
        }) );

        set("combat_exp", 800000);
        set("attitude", "friendly");
        set("inquiry", ([
                "陷害" : "你什么意思......。\n",
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}

int accept_object(object me, object obj)
{
	object pai;
        if( (string) obj->query("name") == "小桂子"
        || obj->query("id") =="xiao guizi")
	{
        message_vision("$N向$n点了点头：\n",this_object(),me);
        command("heihei");
	command("say 做得好，除去我的心病！\n");
	command("say 这本42章经，就交给你保管了！\n");
	pai = new("/d/city2/obj/book14_2");
	if(pai)
	pai->move(me);
        message_vision("$N拿出一本42章经给了$n。\n",this_object(),me);
        call_out("destroying", 0, obj,me);                       
	return 1;	
	}
else       return 0;
}

void destroying(object obj, object ob, object me)
{   

   if(obj) destruct(obj);
}
