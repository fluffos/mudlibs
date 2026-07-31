// This program is a part of NT MudLIB

#include <ansi.h>

inherit BOSS;

void check_weapon();
void check_friend();

void create()
{
        set_name(HIM "胡一刀" NOR, ({ "hu yidao"}) );
        set("title", HIR "旷世绝刀" NOR);
        set("long", HIC "这是一个剽悍粗犷的北方大汉，双眼炯炯有神。\n"
                        "据说他的刀法当世无双。\n" NOR);

        set("gender", "男性");
        set("age", 39);

        set("str", 500);
        set("int", 500);
        set("con", 500);
        set("dex", 500);

        set("shen", 8000000);

        set_temp("apply/attack", 5000);
        set_temp("apply/unarmed_damage", 5000);
        set_temp("apply/damage", 5000);
        set_temp("apply/armor", 60000);
        set_temp("apply/qy", 50);  // 气运
        set_temp("apply/fy", 50);  // 福缘

        set("reborn/times", 1);

        set("max_qi", 21000000);
        set("eff_qi", 21000000);
        set("qi", 21000000);

        set("max_jing", 1000000000);
        set("jing", 1000000000);
        set("eff_jing", 1000000000);
        set("max_jingli", 1000000000);
        set("jingli", 1000000000);

        set("neili", 200000000);
        set("max_neili", 1000000);
        set("jiali", 50000);
        set("combat_exp", 2100000000);

        set_skill("unarmed", 1500);
        set_skill("finger", 1500);
        set_skill("claw", 1500);
        set_skill("strike", 1500);
        set_skill("hand", 1500);
        set_skill("cuff", 1500);
        set_skill("parry", 1500);
        set_skill("dodge", 1500);
        set_skill("force", 1500);
        set_skill("sword", 1500);
        set_skill("blade", 1500);
        set_skill("zuoyou-hubo", 1500);

        set_skill("daojian-guizhen", 1500);
        set_skill("jiuyang-shengong", 1500);
        set_skill("yinyang-shiertian", 1500);
        set_skill("qiankun-danuoyi", 1500);
        set_skill("martial-cognize", 1500);
        set_skill("qiankun-danuoyi", 1500);
        set_skill("lingbo-weibu", 1500);
        set_skill("literate", 1500);
        set_skill("huajia-su", 800);

        //set_skill("jingluo-xue", 1500);

        set("no_nuoyi", 1); // 不被挪移影响

        map_skill("parry", "qiankun-danuoyi");
        map_skill("force", "yinyang-shiertian");
        map_skill("dodge", "lingbo-weibu");
        map_skill("unarmed", "yinyang-shiertian");
        map_skill("finger", "yinyang-shiertian");
        map_skill("strike", "yinyang-shiertian");
        map_skill("hand", "yinyang-shiertian");
        map_skill("cuff", "yinyang-shiertian");
        map_skill("claw", "yinyang-shiertian");
       // map_skill("sword", "daojian-guizhen");
       // map_skill("blade", "daojian-guizhen");

        prepare_skill("finger", "yinyang-shiertian");
        prepare_skill("unarmed", "yinyang-shiertian");

        // yun perform
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
              //
              (: command("perform sword.ben twice") :),
              (: command("perform sword.ben and sword.tian") :),
              // 阴阳12t
              (: command("perform finger.tian twice") :),
              (: command("perform finger.zhen and finger.jiu") :),

              //(: exert_function, "roar" :),
              (: exert_function, "powerup" :),
              (: exert_function, "shield" :),
              (: exert_function, "recover" :),
              (: exert_function, "dispel" :),
              (: check_weapon :),

        }));

        set("my_life", 1); // 当气血低于10%的时候补满一次，设置该参数为0        

        setup();

        // 衣服
        carry_object("/clone/cloth/bupao")->wear();

        // 武器
        carry_object("/clone/weapon/anyue-dao")->wield();
}
void init()
{
	
	call_out("findPlayer",5); //寻敌
}
//函数：寻敌
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;
	
	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);
	
	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}
void heart_beat()
{
        object ob;

        if( !clonep(this_object()) ) return;
        // 解除不能perform yun的限制
        if (random(3) == 1)
        {
                delete_temp("no_perform");
                delete_temp("no_exert");
        }

        if (random(2) == 1)check_weapon();

        // 检查同伴的状态
        check_friend();

        return ::heart_beat();
}

void check_friend()
{
        string friend_id;
        object ob, *obs, me, env;
        int i;

        friend_id = "miao renfeng";
        me = this_object();

        if( !(env = environment(me)) ) return;

        ob = present(friend_id, env);
        if (! ob) return;

        me->clean_up_enemy();
        ob->clean_up_enemy();

        // 我和同伴不能自相残杀
        me->remove_enemy(ob);
        me->remove_killer(ob);
        ob->remove_enemy(me);
        ob->remove_killer(me);

        // 如果未在战斗中，查看同伴是否在战斗中，如果在的话，主动攻击同伴的敌人
        if (! me->is_fighting() && ob->is_fighting())
        {
                ob->clean_up_enemy();
                obs = ob->query_enemy();
                if (me->is_busy()) me->interrupt_busy(me, 1000);
                if (me->is_busy()) me->interrupt_busy(me);
                if (sizeof(obs))
                {
                        message_vision(HIG "\n$N" HIG "大叫一声：“苗兄，小心，一刀来也！”\n\n" NOR, me);
                        for(i = 0; i < sizeof(obs); i ++)
                        {
                                me->kill_ob(obs[i]);
                        }
                }
        }

        // 如果同伴的HP小于20%,且我的HP大于60%则保护对方
        if( ob->query("eff_qi" ) <= ob->query("max_qi")/10 &&
            me->query("eff_qi") >= me->query("max_qi")/5*3 )
        {
                if (me->query_temp("guardfor"))return;
                if (me->is_busy())me->interrupt_busy(me, 1000);
                if (me->is_busy())me->interrupt_busy(me);
                command("guard " + friend_id);
        }
}

// 检查武器
void check_weapon()
{
        object me, ob;

        me = this_object();

        // 同时补充内力
        set("neili", query("max_neili"));

        if (me->is_busy())me->interrupt_busy(me, 1000);

        if (me->is_busy())me->interrupt_me(me);

        if( !me->query_temp("weapon") )
        {
                if( !objectp(ob = present("anyue dao", environment(me))) )
                ob = new("/clone/weapon/anyue-dao");
                ob->move(me);
                "/cmds/std/wield"->main(me, "anyue dao");
        }
        if( !me->query_temp("secondary_weapon") )
        {
                if( !objectp(ob = present("fengshen jian", environment(me))) )
                ob = new("/clone/weapon/fengshen-jian");
                ob->move(me);
                "/cmds/std/wield"->main(me, "fengshen jian");
        }

        if (random(5) == 1)
        {
                me->delete_temp("no_perform");
                me->delete_temp("no_exert");

                me->add_temp("apply/damage", 5000);
                if (random(3) == 1)
                        command("perform sword.ben twice");
                else
                        command("perform sword.ben and sword.tian");
                me->add_temp("apply/damage", -5000);

                if (random(2))
                {
                        me->delete_temp("eff/jiuyin-shengong/xin");
                }
        }

        if (random(10) == 1)
        {
                me->clear_condition();
        }

        // 很小几率恢复气血
        if (random(1000) == 1)
        {
                if (query("eff_qi") < query("max_qi") / 3) add("eff_qi", query("max_qi") / 5);
                if (query("qi") < query("max_qi") / 3) add("qi", query("max_qi") / 5);
        }

        if (me->is_busy())me->interrupt_busy(me);

        if (! me->is_fighting() || random(5) == 1)
        {
                command("yun powerup");
        }

        return;
}

int accept_hit(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

void new_life()
{
        object me = this_object();

        // 补满气血
        me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("jing",me->query("max_jing"));
        me->set("jingli",me->query("max_jingli"));

        delete_temp("no_perform");
        delete_temp("no_exert");

        me->clear_condition();

        me->interrupt_me(this_object());

        set_temp("apply/attack", 1200000);
        set_temp("apply/unarmed_damage", 150000);
        set_temp("apply/damage", 150000);
        set_temp("apply/armor", 100000);
        set_temp("apply/qy", 70);  // 气运
        set_temp("apply/fy", 70);  // 福缘
        me->delete("my_life");

        message_vision(HIG "\n$N" HIG "大喝一声，目光顿时充满杀意！\n\n" NOR, me);

        return;
}

int receive_damage(string type, int damage, object who)
{
        object ob;

        object me = this_object();

        if( !me->query("my_life"))return ::receive_damage(type,damage,who);

        if( me->query("qi")<me->query("max_qi")/10 )
        {
                new_life(); // 重生一次
                return 0;
        }

        return ::receive_damage(type, damage, who);
}

// 检查生命
void check_life()
{
        object env;

        // 如果life<=1则死亡
        if (1)
        {
                message_vision(HIR "\n$N" HIR "长叹一声，消失在山林之中 ……\n\n" NOR, this_object());
                // 记录
                log_file("dongfang_die", "胡一刀于 " + ctime(time()) + " 被杀死！\n");

                destruct(this_object());
        }
}

void die(object killer)
{
        object dob;             // 打晕这个NPC的人
        int n;                  // 可以奖励的人的数目
        int exp;                // 需要瓜分的修为
        int pot;                // 需要瓜分的潜能
        int weiwang;            // 需要瓜分的威望
        int score;              // 需要瓜分的阅历
        object *t;              // 杀死我的人的队伍列表
        object tob;
        object ob;
        int mar;                //  需要瓜分的体会
        int i;

        // 定义奖励物品列表
        // 几率  X / 百分之
        mixed oblist = ([
"clone/armor/daojian/kuangfeng"         : 1,
"clone/armor/daojian/lengyue"           : 1,
"clone/armor/daojian/xingshi"           : 1,
"clone/armor/daojian/xingshi2"          : 1,
        ]);

        object gift_ob, gift_ob2, gift_ob3, gift_ob4,gift_ob5;
        string s_gift, *key_s_gift;
        int gift_point, ran;

        if( objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
              //  full_self();
                return;
        }

        // 如果还未重生，则重生一次
        if (query("my_life"))
        {
                new_life();
                return;
        }

        // 找到杀了我(NPC)或是打晕我的人
        if (! objectp(dob = killer))
                dob = query_last_damage_from();

        // 打败我的
        if (! objectp(dob))dob = query_defeated_by();

        if (! objectp(dob))
        {
                // 调用生命检查函数
                check_life();
                return;
        }

        t = dob->query_team();

        if (objectp(dob) && environment(dob) == environment(this_object()))
        {
                exp = 100000 + random(40000);
                pot = 100000 + random(40000);
                weiwang = 6000 + random(9000);
                score = 6000 + random(6000);
                mar = 12000 + random(12000);
                n = 0;

                n = sizeof(t);
                if (! n || n < 3)
                {
                       exp /= 5;
                       pot /= 5;
                       weiwang /= 3;
                       score /= 3;
                       mar /= 5;
                }

                if (n >= 3)
                {
                        exp /= n;
                        pot /= n;
                        weiwang /= n;
                        score /= n;
                        mar /= n;
                }

        }

        // 100%掉物品
        if (1)
        {

                key_s_gift = keys(oblist);

                // 100%至少爆一件
                if (1)
                {
                        s_gift = key_s_gift[random(sizeof(key_s_gift))];
                        gift_point = oblist[s_gift];
                        gift_ob = new(s_gift);
                        if (objectp(gift_ob))
                        {
                                message_vision(HIC "当~~一声，从$N" HIC "身上掉出" + gift_ob->name() + HIC "，落在地上。\n" NOR, this_object());
                                gift_ob->set("who_get/id", "NONE");
                                gift_ob->set("who_get/time", time()+30);//30秒内都不能捡取
                                gift_ob->move(environment(this_object()));
                        }
                        else // 纪录之
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }

                // 30%几率再追加一件物品
                if (random(10) < 3)
                {
                        s_gift = key_s_gift[random(sizeof(key_s_gift))];
                        gift_point = oblist[s_gift];
                        gift_ob2 = new(s_gift);
                        if (objectp(gift_ob2))
                        {
                                message_vision(HIC "当~~一声，从$N" HIC "身上掉出" + gift_ob2->name() + HIC "，落在地上。\n" NOR, this_object());
                                gift_ob2->set("who_get/id", "NONE");
                                gift_ob2->set("who_get/time", time()+10);//30秒内都不能捡取
                                gift_ob2->move(environment(this_object()));
                        }
                        else // 纪录之
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }
                // 10%几率再追加一件
                if (random(10) == 1)
                {
                        s_gift = key_s_gift[random(sizeof(key_s_gift))];
                        gift_point = oblist[s_gift];
                        gift_ob3 = new(s_gift);
                        if (objectp(gift_ob3))
                        {
                                message_vision(HIC "当~~一声，从$N" HIC "身上掉出" + gift_ob3->name() + HIC "，落在地上。\n" NOR, this_object());
                                //gift_ob3->set("who_get/id", "NONE");
                                //gift_ob3->set("who_get/time", time() + 30); // 30秒内都不能捡取
                                gift_ob3->move(environment(this_object()));
                        }
                        else // 纪录之
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }

                if (random(200) == 1)
                {
                        gift_ob5 = new("clone/vip/tianfu");
                        if (objectp(gift_ob5))
                        {
                                message_vision(HIC "当~~一声，从$N" HIC "身上掉出" + gift_ob5->name() + HIC "，落在地上。\n" NOR, this_object());
                                //gift_ob3->set("who_get/id", "NONE");
                                //gift_ob3->set("who_get/time", time() + 30); // 30秒内都不能捡取
                                gift_ob5->move(environment(this_object()));
                        }
                        else // 纪录之
                        {
                                log_file("gift-none", s_gift + " from " + __FILE__ + "\n");
                        }
                }

                // 30%的几率掉东西
                if (random(100) < 30)
                {
                        ran = random(100);
                        if(ran>0 && ran<=30)// 天降·醒世环,天降·冷月冠,天降·狂风靴, 30% 随机一件
                        {
                                switch(random(3))
                                {
                                        case 0:
                                                gift_ob = new("clone/armor/daojian/xingshi3");
                                        break;

                                        case 1:
                                                gift_ob = new("clone/armor/daojian/lengyue2");
                                        break;

                                        default:
                                                gift_ob = new("clone/armor/daojian/kuangfeng2");
                                        break;
                                }
                                if (objectp(gift_ob))
                                {
                                        message_vision(HIC "当~~一声，从$N" HIC "身上掉出" + gift_ob->name() + HIC "，落在地上。\n" NOR, this_object());
                                        gift_ob->set("who_get/id", "NONE");
                                        gift_ob->set("who_get/time", time()+30);//30秒内都不能捡取
                                        gift_ob->move(environment(this_object()));
                                }
                        }							
                        if(ran>30 && ran<=50)// 天降·醒世环,天降·冷月冠,天降·狂风靴, 20% 随机一件
                        {
                                switch(random(3))
                                {
                                        case 0:
                                                gift_ob2 = new("clone/armor/daojian/xingshi4");
                                        break;

                                        case 1:
                                                gift_ob2 = new("clone/armor/daojian/lengyue3");
                                        break;

                                        default:
                                                gift_ob2 = new("clone/armor/daojian/kuangfeng3");
                                        break;
                                }	
                                if (objectp(gift_ob2))
                                {
                                        message_vision(HIC "当~~一声，从$N" HIC "身上掉出" + gift_ob2->name() + HIC "，落在地上。\n" NOR, this_object());
                                        gift_ob2->set("who_get/id", "NONE");
                                        gift_ob2->set("who_get/time", time()+30);//30秒内都不能捡取
                                        gift_ob2->move(environment(this_object()));
                                }
                        }								
                        if(ran>50 && ran<=55)// 天降·人皮宝衣 5% 随机一件
                            {
                                gift_ob3 = new("/clone/armor/daojian/renpiyi");

                                if (objectp(gift_ob2))
                                {
                                        message_vision(HIC "当~~一声，从$N" HIC "身上掉出" + gift_ob3->name() + HIC "，落在地上。\n" NOR, this_object());
                                        gift_ob3->set("who_get/id", "NONE");
                                        gift_ob3->set("who_get/time", time()+30);//30秒内都不能捡取
                                        gift_ob3->move(environment(this_object()));
                                }
                            }
                        }
                }
        

        // 检查生命
        check_life();

        return ;
}
