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
        set_name(HIC "神龙教叛徒首领" NOR, ({ me->query("id")+"-pantu"}));
        set("title",me->query("name")+"定下的");
        set("gender", "男性");
        set("age", 28);
        set("long", "他是一个神龙教叛徒。\n");
        
        set("attitude", "peaceful");
        set("qi", me->query("qi"));
        set("max_qi", me->query("max_qi"));
        set("jing", me->query("jing"));
        set("neili", me->query("neili"));
        set("max_neili", me->query("max_neili"));
        set("max_jing", me->query("max_jing"));
        set("str", me->query("str"));
        set("dex", me->query("dex"));
        set("per", me->query("per"));
        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp"));
// 加下面5句是让强盗自动走，增添玩家做机器人的困难！-糖圆SMILE
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "strike.hua" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.yingxiong" :),                
                (: exert_function, "recover" :),
                      }) );
             set("chat_chance", 30);
             set("chat_msg", ({
              (: random_move :)
        }) );


        set_skill("hand", myskill * 4 / 5);
        set_skill("staff", myskill * 4 / 5);
        set_skill("dodge", myskill * 4 / 5);
        set_skill("unarmed", myskill* 4 / 5);
        set_skill("parry", myskill* 4 / 5);
        set_skill("force", myskill* 4 / 5);
        set_skill("blade", myskill* 4 / 5);
        set_skill("strike", myskill* 4 / 5);
        set_skill("zhaosheshu", myskill* 4 / 5);
        set_skill("yangsheshu", myskill* 4 / 5);
        set_skill("shenlong-xinfa", myskill* 4 / 5);
        set_skill("yixingbu", myskill* 4 / 5);
        set_skill("shenlong-bashi", myskill* 4 / 5);
        set_skill("huagu-mianzhang", myskill* 4 / 5);
        set_skill("shedao-qigong", myskill* 4 / 5);
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-bashi");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
}

void init()
{
        remove_call_out("leave");
        call_out("leave",60);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "神龙教叛徒首领钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;      

        message_vision(HIR "\n神龙教叛徒倒在地上，挣扎了几下就死了。\n" NOR,me);
        message_vision(HIG "\n你从叛徒的身上找到了42章经一部。\n" NOR,me);
        if (me->query("kill_shenlong") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
               zhi=new(__DIR__"zhi");
               zhi->move(me);
                me->add("score",2);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "神龙教叛徒的尸体" NOR);
        corpse->set("long","他是一个曾经无恶不做的神龙教叛徒，\n然而，他已经死了，剩下一具丑陋的尸体。\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);

        destruct(this_object());
}


