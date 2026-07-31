inherit NPC;
void create()
{
   set_name("梅超风",({"mei chaofeng","mei"}));
   set("gender","女性");
   set("mingwang",-5000);
   set("combat_exp",426000);
   set("title","黑风双煞之[铁尸]");
   
   set("age",46);
   set("qi",1080);
   set("max_qi",1080);
   set("food",250);
   set("water",250);
   set("neili",1080);
   set("max_neili",1080);
   set("force_factor",60);
   set("chat_chance",5);
   set("chat_msg",({
 "梅超风喃喃自语:贼汉子,你一个人去了,留下我一个人受苦.\n",
 "梅超风侧耳听了听,嘘了口气,把手指在头骨上比划了两下.\n",
 }));

   set_skill("dodge",120);
   set_skill("force",120);
   set_skill("parry",120);
   set_skill("unarmed",120);
   set_skill("spear",120);
   set_skill("sword",120);
 
   setup();
   add_money("silver",12);
carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
 object env;
 env=environment();
 if (ob->query("PKS")>40&&env->query("short")=="cave1")  {
	message_vision("$N哼了一声道：即然来了，就陪老娘练功吧！\n",
		this_object());
	command("guard south");
	kill_ob(ob);
	ob->fight_ob(this_object());
   }
 return;
}
