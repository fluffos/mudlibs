// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// ouyangfeng.c

#include <ansi.h>
#include "ouyang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed  ask_me();
string ask_lingshe();
mixed  ask_music_book();

void create()
{
        set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "他就是白驼山庄主，号称“西毒”的欧阳锋。脸型瘦削，\n"
                    "身形剽悍，虽然受到郭靖欺骗误学习了「九阴真经」而走\n"
                    "火入魔，一度变得精神错乱，但是现在已然恢复，功力犹\n"
                    "胜往昔。\n");
        set("title", "西域白驼山庄主");
        set("gender", "男性");
        set("age", 53);
        set("nickname", HIR "西毒" NOR);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set("str", 32);
        set("int", 34);
        set("con", 34);
        set("dex", 32);

        set("qi", 6000);
        set("max_qi", 6000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 200);
        set("level", 50);
        set("combat_exp", 4000000);

        set_skill("force", 450);
        set_skill("strike", 450);
        set_skill("dodge",450);
        set_skill("parry", 450);
        set_skill("cuff", 450);
        set_skill("finger", 450);
        set_skill("staff", 450);
        set_skill("training", 450);
        set_skill("poison", 450);
        set_skill("shedu-qiqiao", 450);
        set_skill("hamagong", 450);
        set_skill("chanchu-bufa", 450);
        set_skill("lingshe-quan", 450);
        set_skill("lingshe-zhangfa", 450);
        set_skill("baibian-daxue", 450);
        set_skill("shentuo-zhang", 450);
        set_skill("guzheng-jifa", 450);
        set_skill("xiyu-tiezheng", 450);
        set_skill("wushe-qu", 450);
        set_skill("literate", 400);
        set_skill("medical", 460);
        set_skill("baituo-michuan", 450);
        set_skill("martial-cognize", 400);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("cuff", "lingshe-quan");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("staff", "lingshe-zhangfa");
        map_skill("strike", "hamagong");
        map_skill("finger", "shedu-qiqiao");
        map_skill("poison", "shedu-qiqiao");
        map_skill("medical", "baituo-michuan");
        map_skill("guzheng-jifa", "xiyu-tiezheng");

        prepare_skill("finger", "shedu-qiqiao");
        prepare_skill("cuff", "lingshe-quan");

        create_family("欧阳世家", 5, "掌门");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.qianshe" :),
                (: perform_action, "staff.wuji" :),
                (: perform_action, "cuff.rou" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "绝招"     : (: ask_me :),
                "绝技"     : (: ask_me :),
		"灵蛇"     : (: ask_lingshe :),
                "千蛇出洞" : (: ask_me :),
                "筝谱"     : (: ask_music_book :),
                "古筝技法" : (: ask_music_book :),
        ]));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("music_book", 1);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/baituo/obj/lingshezhang")->wield();
        carry_object("d/baituo/obj/tiezheng");
        add_money("silver", 50);
}

int recognize_apprentice(object me, string skill)
{
        if (skill != "guzheng-jifa")
                return 0;

        if (me->query_temp("can_learn/ouyang/guzheng-jifa"))
                return 1;

        command("say 好吧，你愿意学我就传你一点古筝之道。");
        me->set_temp("can_learn/ouyang/guzheng-jifa", 1);
        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("combat_exp") < 200000)
        {
                if (random(2))
                        command("smile");
                else
                        command("pat " + ob->query("id"));

                command("say 你的经验还不够，先和我的侄儿欧阳克学习武功吧。");
                return ;
        }

        if ((int)ob->query_skill("training", 1) < 100) 
        {
                command("say 我们白驼山庄经常要训驭毒虫，"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "的驭兽术还不够好。");
                return;
        }
        
        if ((int)ob->query_skill("poison",1) < 100) 
        {
                command("say 你的基本毒技太低了。");
                return;
        }

        command("sigh");
        command("pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        command("say 不错，不错！我欧阳真是后继有人。");
        return;
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/lingshe-zhangfa/qianshe"))
                return "你还不快去练功去？好好把我们欧阳家发扬光大！";

        if (me->query("family/family_name") != query("family/family_name"))
                return "你是哪儿来的？找死么？";

        if (me->query("shen") > -40000)
                return "你这人手段不够狠毒，我现在还不能传你绝招！";

        if (me->query_skill("lingshe-zhangfa", 1) < 120)
                return "你先好好把灵蛇杖法练好了再说！";

        if (me->query("contribution") < 600)
                return "你在我欧阳世家中无所作为，还想让我传功给你？。";
                
        message_vision(HIY "$n" HIY "喝道：看仔细了！说把荡"
                       "臂横扫，伸伸缩缩，当真是变幻无穷！把$N"
                       HIY "的眼睛都看直了。\n" NOR,
                       me, this_object());
        command("heihei");
        command("say 我演示的这么清楚，你看懂了没有？");
        tell_object(me, HIG "你学会了千蛇出洞。\n" NOR);
        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 90000);
        me->add("contribution", -600);
        me->set("can_perform/lingshe-zhangfa/qianshe", 1);
        return 1;
}

string ask_lingshe()
{
        mapping fam;
        object obj, me;

        me = this_player();
        
        if (me->query("family/master_name") != "欧阳锋") 
        {
                return ("娃娃功力不够，还是别要为妙！");
        }
        
        if (present("ling she", me))
        {
                return ("你不是已经有了灵蛇了吗？");
        }
        
        message_vision(CYN "$N撮唇作啸，袖中缓缓游出一条银色小蛇，对着$n摇头摆尾，似在示意问好。\n" NOR,
                       this_object(), me);
        obj = new("/d/baituo/npc/lingshe.c");
        obj->move(environment());
        return ("灵蛇已显，娃娃不妨试试是否有缘成为它的主人。");
}

mixed ask_music_book()
{
        object me;
        object ob;

        me = this_player();
        if (query("music_book") < 1)
                return "我的筝谱已经借出去了。\n";

        ob = new("/clone/book/zhengpu");
        ob->move(me, 1);
        message_vision("$n把筝谱给了$N，道：你拿去自己好好琢磨吧。\n",
                       me, this_object());
        set("music_book", 0);
        return 1;
}

void reset()
{
        set("music_book", 1);
}

void unconcious()
{
        die();
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "历练" :
        case "历炼" :
        case "锻炼" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "quest" :
                return DEFEND_D->ask_quest(this_object(), me); 
                break;
        
        case "finish" : 
                return DEFEND_D->ask_reward(this_object(), me); 
                break;

        case "蟾震九天" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hamagong/hama",
                           "name"    : "蟾震九天",
                           "sk1"     : "hamagong",
                           "lv1"     : 100,
                           "sk2"     : "force",
                           "lv2"     : 140,
                           "neili"   : 2000,
                           "gongxian": 1000,
                           "shen"    : -24000, ]));
                break;

        case "蛤蟆扑击" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hamagong/puji",
                           "name"    : "蛤蟆扑击",
                           "sk1"     : "hamagong",
                           "lv1"     : 120,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "gongxian": 600,
                           "neili"   : 1400,
                           "shen"    : -28000, ]));
                break;

        case "推天式" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/hamagong/tui",
                           "name"    : "推天式",
                           "sk1"     : "hamagong",
                           "lv1"     : 60,
                           "force"   : 150,
                           "gongxian": 400,
                           "shen"    : -20000, ]));
                break;

        case "雪锁千山" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shentuo-zhang/suo",
                           "name"    : "雪锁千山",
                           "sk1"     : "shentuo-zhang",
                           "lv1"     : 120,
                           "gongxian": 400,
                           "shen"    : -10000, ]));
                break;

        case "柔字诀" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/lingshe-quan/rou",
                           "name"    : "柔字诀",
                           "sk1"     : "lingshe-quan",
                           "lv1"     : 120,
                           "gongxian": 400,
                           "shen"    : -10000, ]));
                break;

        case "点字诀" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/baibian-daxue/dian",
                           "name"    : "点字诀",
                           "sk1"     : "baibian-daxue",
                           "lv1"     : 140,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "gongxian": 600,
                           "shen"    : -10000, ]));
                break;

        case "灵蛇缠身" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/lingshe-zhangfa/chan",
                           "name"    : "灵蛇缠身",
                           "sk1"     : "lingshe-zhangfa",
                           "lv1"     : 140,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "gongxian": 600,
                           "shen"    : -30000, ]));
                break;
                
        case "横行无忌" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/lingshe-zhangfa/wuji",
                           "name"    : "横行无忌",
                           "sk1"     : "lingshe-zhangfa",
                           "lv1"     : 140,
                           "sk2"     : "force",
                           "lv2"     : 120,
                           "gongxian": 600,
                           "shen"    : -60000, ]));
                break;

        default:
                return 0;
        }
}
