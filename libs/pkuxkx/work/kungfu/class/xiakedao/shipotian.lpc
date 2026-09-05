// Xiakedao NPC
// modified by aiai on 6/28/1999
// 侠客岛之 "石破天"

#include <ansi.h>

inherit NPC;

void consider();
int ask_me();
void heal();
int do_answer(string arg);

void create()
{
        set_name(YEL"石破天"NOR, ({"shi potian", "shi", "potian"}));
        seteuid( getuid());
        set("nickname", RED"侠客岛怪杰"NOR);
        set("title",GRN "长乐帮帮主"NOR );
        set("gender", "男性");
        set("age", 30);
        set("long", @LONG
    此人出生苦命，后由于种种机缘巧合，当得长乐帮的帮主。其人
虽不通文墨，但性直老实，心肠及好。屡经磨难后，终能在侠客岛上习得
一身本领。 
LONG );
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 80);
        set("int", 80);
        set("con", 80);
        set("dex", 80);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: heal :),
        }));

       
        set("max_qi", 5000);
        set("max_jing",5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
        
        set("combat_exp", 8000000);
        set("score", 500000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        
        set("inquiry", ([
                "key" : (: ask_me :),
                "侠客行" : "你去闭关室找找吧。\n",
                "钥匙" : (: ask_me :),
                "自创武功" : (: ask_me :),
                "闭关室钥匙" : (: ask_me :),
        ]) );
        
        set_skill("force", 600);
        set_skill("strike", 600);
        set_skill("xiake-strike", 600);
        set_skill("dodge", 600);
        set_skill("xiake-shenfa", 600);
        set_skill("xiake-shengong",600);
        set_skill("xiake-jianfa",600);
        set_skill("sword",600);
        set_skill("throwing",600);
        map_skill("strike", "xiake-strike");
        map_skill("dodge", "xiake-shenfa");
        map_skill("force","xiake-shengong");
        map_skill("sword","xiake-jianfa");
        map_skill("parry","xiake-jianfa");
        prepare_skill("strike", "xiake-strike");

        setup();
        carry_object("/d/xiakedao/npc/obj/xguang")->wield();
        carry_object("/d/xiakedao/npc/obj/xgjia")->wear();
}

void init()
{
	add_action("do_answer", "answer");
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(2) )
        {
            case 0:
                command("perform feijian " + target->query("id"));
                break;
            case 1:
                command("yun qiankun " + target->query("id"));
                break;
        }
}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 200");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

int ask_me()
{
	object me = this_player();
	if (!me->query("createskill/long"))
	{
		command("say 进入闭关室需要先征得龙岛主的同意，否则我不能把钥匙给你。");
		return 1;
	}
	else
	{
		me->set_temp("shi/asked", 1);
                command("say 你给我1000两黄金，我就把钥匙给你，你决定了回答我。(answer)");
		return 1;
	}
}

int do_answer(string arg)
{
	object me=this_player();
	object key, mbx;
	mapping mail;

	if (!me->query_temp("shi/asked")) return 0;
	if (!arg || (arg != "yes" && arg != "好" && arg != "行"))
        	command("say 你既然不愿意给钱，那就算了。");
	else
	{
                if(me->query("balance") < 10000000)
		{
			command("say 你的存款不够了，等你有钱了再来吧。\n");
			me->delete_temp("shi/asked");
			return 1;
		}
		else 
		{
                        me->add("balance", - 10000000);
			command("say 好吧，这把钥匙你拿去。\n");
			key = new("/d/xiakedao/npc/obj/yaoshi");
			key->move(me);

			mail = ([
					"from":	"钱眼开(qian yankai)",
					"title": "转帐成功！！！",
					"to": me->query("id"),
					"time": time(),
                                        "text": "阁下的一千两黄金已经成功汇入石破天大侠的账户。\n\n" + 
							"                   扬州钱庄钱眼开(qian yankai)敬上"
				]);
			mbx = me->query_temp("mbox_ob");
			if( !mbx ) 
			{
				mbx = new(MAILBOX_OB);
				mbx->set_owner(me->query("id"));
				mbx->move(me);
			}
			mbx->receive_mail(mail);
			me->save();
			message_vision("忽然一个驿站伙计急匆匆地走过来，交给$N一个邮箱，说道：您的信！然后头也不回的走掉了。\n",me);

		}
	}
	me->delete_temp("shi/asked");
	return 1;
}
