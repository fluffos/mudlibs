//Yanqi 10/04/2k

inherit NPC;
#include <ansi.h>

int do_clone(object me, object ob);

void create()
{
        set_name("蛇", ({ "du she" }) );
        set("race", "野兽");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }));
        set("shen", -15000);
        set("attitude", "killer");
        set("age", 3+random(10));
        set("combat_exp", 9999999);
        set("shen_type", -1);
        set("max_qi",9999);
        set("eff_qi",9999);
        set("qi",9999);
        set("max_jing",9999);
        set("eff_jing",9999);
        set("jing",9999);
        set("max_jingli",9999);
        set("eff_jingli",9999);
        set("jingli",9999);
        set("neili",9999);
        set("jiali", 99);
        set("max_neili",9999);
        set("score", 10000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "一条蛇在草丛中盘成一团。\n",
                "蛇爬过来，在你的腿边爬来爬去。\n",
                "蛇向着你，慢慢爬了过来。\n",
                }) );
        
        call_out("dest",500+random(200));
        setup();
}

void kill_ob(object me)
{
        object ob = this_object();
        
        if (!me->query_temp("gb_snake/start")
             && ob->query_temp("name1")!=me->query("id"))
        {
                me->remove_killer(ob);
                remove_killer(me);
                message_vision("$N发现$n根本不理$P！\n",me,ob);
                return;
        }
      	::kill_ob(me);
}

void init()
{
        object ob = this_player();
        object me = this_object();
        string name1;

	::init();

        name1 = ob->query("id");
        if (me->query_temp("name1")==name1
	&& ob->query_temp("gb_snake/start")
	&& !ob->query_temp("gb_snake/over"))
        {
                message_vision("突然$n发现草丛中有一条$N。\n",me,ob);
                me->set_leader(ob);
                if (!me->query_temp("skillset")) do_clone(me, ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
                ob->start_busy(2+random(3));
        }
}       

int do_clone(object me, object ob)
{
        int number,k_qi,k_neili,k_jing,k_jingli;
        
        switch (random(11))
        {
                case 0: me->set("name","小青蛇");break;
                case 1: me->set("name","菜花蛇");break;
                case 2: me->set("name","眼镜蛇");break;
                case 3: me->set("name","腹蛇");break;
                case 4: me->set("name","五步蛇");break;
                case 5: me->set("name","银环蛇");break;
                case 6: me->set("name","响尾蛇");break;
                case 7: me->set("name","四脚蛇");break;
                case 8: me->set("name","金环蛇");break;
                case 9: me->set("name","赤练蛇");break;
                case 10: me->set("name","野鸡脖子");break;
        }

        number = (int)ob->query("max_pot");
        k_qi = (int)ob->query("max_qi");
        k_jing = (int)ob->query("max_jing");
        k_jingli = (int)ob->query("eff_jingli");
        k_neili = (int)ob->query("max_neili");

        me->set("max_qi",k_qi*3/2 +random(100));
        me->set("eff_qi",k_qi*3/2 +random(100));
        me->set("qi",k_qi*3/2 +random(100));
        me->set("max_jing",k_jing);
        me->set("eff_jing",k_jing);
        me->set("eff_jingli",k_jingli);
        me->set("max_jingli",k_jingli);
        me->set("jingli",k_jingli);
        me->set("jing",k_jing);
        me->set("max_neili",k_neili);
        me->set("neili",k_neili*2-1);
        me->set("neili",k_neili);
        me->set("jiali", 50);
        me->set("dex",ob->query("dex")+
        	(int)ob->query_skill("dodge",1)/10+random(10));
        me->set("combat_exp",ob->query("combat_exp"));

        me->add_temp("apply/attack",  100);
        me->add_temp("apply/damage",  100);
        me->add_temp("apply/dodge", 200);

        me->set_temp("skillset",1);
        remove_call_out("dest");
        call_out("dest",500);
        return 1;
}

void dest()
{
        if (!living(this_object())) {
                call_out("dest", 20);
                return;
        }
        message_vision("$N甩了一下尾巴，钻进草丛里面不见了。\n",this_object());
        destruct(this_object());
}


void unconcious()
{
        object me,snake2,ob;

        me = this_object();
        ob = me->query_temp("last_damage_from");
	        
        if(objectp(ob) && ob->query_temp("gb_snake/start"))
	{
		ob->set_temp("gb_snake/over",1);
		snake2 = new ("/clone/animal/snake2");
		snake2->move(ob);
		snake2->set("name",me->query("name"));
		snake2->set_temp("name1",me->query_temp("name1"));
		message_vision ("\n$N缩成一团，不动了。$n伸手抓了起来。\n",me,ob);
	}
        destruct(me);
}
 
void die()
{
        object me, ob;
        me = this_object();
        ob = me->query_temp("last_damage_from");
        if(objectp(ob) && ob->query_temp("gb_snake/start"))
		ob->set_temp("gb_snake/failed",1);
        ::die();
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 6+random(5));
        return 0;
}
