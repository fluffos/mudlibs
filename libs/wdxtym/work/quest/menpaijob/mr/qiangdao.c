// qiangdao.c 强盗
// lag.2000/3/17

inherit NPC;
#include <ansi.h>
void move();

void create()
{       object me;
        int myskill;
        me=this_player();
        myskill=me->query_skill("force");
        set_name(HIC "姑苏慕容叛徒" NOR, ({ me->query("id")+"-pantu"}));
        set("title",me->query("name")+"定下的");
        set("gender", "男性");
        set("age", 28);
        set("long", "他是一个姑苏慕容叛徒。\n");

        set("attitude", "peaceful");
        set("qi", me->query("qi")* 4 / 5);
        set("max_qi", me->query("max_qi")* 4 / 5);
        set("jing", me->query("jing")* 4 / 5);
        set("neili", me->query("neili")* 4 / 5);
        set("max_neili", me->query("max_neili")* 4 / 5);
        set("max_jing", me->query("max_jing")* 4 / 5);
        set("str", me->query("str")* 4 / 5);
        set("dex", me->query("dex")* 4 / 5);
        set("per", me->query("per")* 4 / 5);
        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp")* 4 / 5);
// 加下面5句是让强盗自动走，增添玩家做机器人的困难！-糖圆SMILE
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "dodge.yanling" :),
                (: perform_action, "dodge.yanling" :),
        }));
             set("chat_chance", 30);
             set("chat_msg", ({
              (: random_move :)
        }) );


        set_skill("hand", myskill * 2 / 3);
        set_skill("staff", myskill * 2 / 3);
        set_skill("dodge", myskill * 2 / 3);
        set_skill("finger", myskill * 2 / 3);
        set_skill("sword", myskill * 2 / 3);
        set_skill("unarmed", myskill* 2 / 3);
        set_skill("parry", myskill* 2 / 3);
        set_skill("force", myskill* 2 / 3);
        set_skill("blade", myskill* 2 / 3);
        set_skill("strike", myskill* 2 / 3);
        set_skill("xingyi-zhang", myskill* 2 / 3);
        set_skill("canhe-zhi", myskill* 2 / 3);
        set_skill("murong-jianfa", myskill* 2 / 3);
        set_skill("shenyuan-gong", myskill* 2 / 3);
        set_skill("yanling-shenfa", myskill* 2 / 3);
        set_skill("douzhuan-xingyi", myskill* 2 / 3);
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
	set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/armor", 10);
        set_temp("apply/damage", 50);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();

}

void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void unconcious()
{
    die();
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "姑苏慕容叛徒钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;

if (me)
{
        message_vision(HIR "\n姑苏慕容叛徒倒在地上，挣扎了几下就死了。\n" NOR,me);
        message_vision(HIG "\n你从叛徒的身上找到了大燕传国玉玺。\n" NOR,me);
        if (me->query("kill_mr") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
               zhi=new(__DIR__"zhi");
               zhi->set("byname",me->query("name"));
               zhi->move(me);
                me->add("score",2);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "姑苏慕容叛徒的尸体" NOR);
        corpse->set("long","他是一个曾经无恶不做的姑苏慕容叛徒，\n然而，他已经死了，剩下一具丑陋的尸体。\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);
        me->add("MKS", 1);
}
        destruct(this_object());
}

