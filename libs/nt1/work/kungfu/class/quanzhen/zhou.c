// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhou.c 周伯通

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

#define ZHENJING    "/clone/book/jiuyin1"

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        object ob;
        set_name("周伯通", ({"zhou botong", "zhou"}));
        set("gender", "男性");
        set("age", 62);
        set("class", "taoist");
        set("nickname",HIY "老顽童" NOR);
        set("long", "他看上去须眉皆白，一副得道模样，然而眼神却透露出一股狡黠。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 31);
        set("int", 36);
        set("con", 32);
        set("dex", 29);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
        }));

        set("qi", 6200);
        set("max_qi", 6200);
        set("jing", 3100);
        set("max_jing", 3100);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 50);
        set("level", 60);
        set("combat_exp", 2800000);

        set_skill("force", 280);
        set_skill("quanzhen-xinfa", 280);
        set_skill("xiantian-gong", 280);
        set_skill("sword", 250);
        set_skill("quanzhen-jian",250);
        set_skill("dodge", 260);
        set_skill("jinyan-gong", 260);
        set_skill("parry", 270);
        set_skill("unarmed", 270);
        set_skill("kongming-quan", 270);
        set_skill("strike", 250);
        set_skill("chongyang-shenzhang", 250);
        set_skill("haotian-zhang", 250);
        set_skill("literate", 120);
        set_skill("finger", 250);
        set_skill("taoism", 220);
        set_skill("finger", 260);
        set_skill("zhongnan-zhi", 270);
        set_skill("zuoyou-hubo", 400);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "kongming-quan");
        map_skill("finger","zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        map_skill("unarmed", "kongming-quan");
        // prepare_skill("cuff", "kongming-quan");

        create_family("全真教", 1, "掌教");
        set("title", "全真教第一代弟子");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "九阴真经" : "嘿嘿嘿嘿...",
                "段皇爷" : "段... 段皇爷？人家是皇爷，我不认识！",
                "瑛姑"   : "你，你说啥？",
                "刘瑛"   : "嗯...嗯...嗯？",
                "空明若玄" : (: ask_skill1 :),
                "空空如也" : (: ask_skill2 :),
        ]));

        setup();

        if (clonep())
        {
                ob = find_object(ZHENJING);
                if (! ob) ob = load_object(ZHENJING);

                if (! environment(ob) && random(30) == 1)
                        ob->move(this_object());
        }
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query("combat_exp") < 400000)
        {
                command("say 你经验这么差，还是去找我那几个师侄教你吧。");
                return;
        }

        if ((int)ob->query("shen") < 50000)
        {
                command("say 你这人品行不好，跟你一起肯定做不了什么好事。");
                return;
        }

        command("smile");
        command("say 反正最近也没啥事干，就收下你玩玩吧。");
        command("recruit " + ob->query("id"));
}

/*
int recognize_apprentice(object ob, string skill)
{
        if (! ob->query("can_learn/zhou"))
        {
                message_vision("$N眨眨眼睛，看着$n，嘻嘻笑个不停。\n",
                               this_object(), ob);
                return -1;
        }

        if (skill != "kongming-quan" &&
            skill != "zuoyou-hubo")
        {
                command("say 我...这里可没有什么好教你的！");
                return -1;
        }

        return 1;
}
*/

int accept_fight(object ob)
{
        if (ob->query("combat_exp") < 500000)
        {
                message_vision("$N嘻嘻一笑，对$n道：“你还是"
                               "把功夫练好了再说吧！”\n",
                               this_object(), ob);
                return -1;
        }

        if (is_fighting())
        {
                message_vision("$N对$n叫道：“你先别急，我打完这"
                               "架就来领教你的！”\n",
                               this_object(), ob);
                return -1;
        }

        if (query("qi") < 4000 ||
            query("jing") < 2000 ||
            query("neili") < 4000)
        {
                message_vision("$N摇摇头对$n道：“我现在"
                               "太累了，等会儿再说吧！”\n",
                               this_object(), ob);
                return -1;
        }

        if (ob->query("can_learn/zhou"))
        {
                message_vision("$N对$n道：“好，那咱们就玩玩！”\n",
                               this_object(), ob);
                return 1;
        }

        message_vision("$N大喜道，好...好，我正手痒痒，咱们来比划比划！\n",
                       this_object(), ob);

        competition_with(ob);
        return -1;
}

void win()
{
        object ob;
        if (! objectp(ob = query_competitor()))
                return;

        message_vision("$N看了看$n，嘿嘿笑道：“你的水平还算"
                       "是马马虎虎，要好好练功，好好练功。”\n",
                       this_object(), ob);
        ::win();
}

void lost()
{
        object ob;
        if (! objectp(ob = query_competitor()))
                return;

        message_vision("$N哎呀一声，抹了抹头上的汗，喜道：“这位" +
                       RANK_D->query_respect(ob) + "，你的武功真厉害，\n"
                       "这样吧，我拜你为师好了，你教我点功夫，我这里有一套"
                       "空明拳法和左右互博\n的小伎俩，你有兴趣也可以学学，怎么样。”\n",
                       this_object(), ob);
        ob->set("can_learn/zhou", 1);
        ::lost();
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kongming-quan/ruo"))
                return "还问这个干嘛？不如来陪我玩玩。";

        if (me->query("family/family_name") != query("family/family_name"))
                return "你是谁，我怎么不认识你？";

        if (me->query_skill("kongming-quan", 1) < 1)
                return "嘿嘿，你连我的空明拳都没学，又怎么学绝招？";

        if (me->query("contribution") < 200)
                return "你投入我全真教，却不努力做事，我为什么要教你？";

        if (me->query("shen") < 50000)
                return "你这人心地还不够好，暂时我还不能教你。";

        if (me->query_skill("kongming-quan", 1) < 100)
                return "你的空明拳还练得不够好，下次再说吧。";

        if (me->query("max_neili") < 1000)
                return "你的内力差成这样，真不知道你是怎么练功的。";

        message_sort(HIY "\n$n" HIY "抓了抓头，满不情愿的嘀咕了两句，这"
                     "才说道：“小子，我把口诀说给你听，然后你就自己下去"
                     "练，别再来烦我了。”说完便一把将$N" HIY "楸到身边"
                     "，在$N" HIY "耳旁唧唧咕咕说了半天。\n\n" NOR, me,
                     this_object()); 

        command("bite");
        command("say 好了，好了，你快走吧。");
        tell_object(me, HIC "你学会了「空明若玄」。\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("kongming-quan"))
                me->improve_skill("kongming-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kongming-quan/ruo", 1);
        me->add("contribution", -200);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kongming-quan/kong"))
                return "快滚，快滚。";

        if (me->query("family/family_name") != query("family/family_name"))
                return "你是谁，我怎么不认识你？";

        if (me->query_skill("kongming-quan", 1) < 1)
                return "嘿嘿，你连我的空明拳都没学，又怎么学绝招？";

        if (me->query("contribution") < 500)
                return "你投入我全真教，却不努力做事，我为什么要教你？";

        if (me->query("shen") < 60000)
                return "你这人心地还不够好，暂时我还不能教你。";

        if (me->query_skill("kongming-quan", 1) < 150)
                return "你的空明拳还练得不够好，下次再说吧。";

        if (me->query("max_neili") < 2000)
                return "你的内力差成这样，真不知道你是怎么练功的。";

        message_sort(HIY "\n$n" HIY "双目一瞪，对$N" HIY "说道：“你怎么"
                     "这么烦，没看见我正在玩吗？”接着$n" HIY "摇了摇头，"
                     "又道：“真是后悔当初收了你，看好了！”说话间右手一"
                     "陡，轻飘飘挥出一拳，拳劲虚实难测，周围登时被激得尘"
                     "土飞扬。\n\n" NOR, me, this_object()); 

        command("angry");
        command("say 快走，快走，以后别再来烦我了。");
        tell_object(me, HIC "你学会了「空空如也」。\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("kongming-quan"))
                me->improve_skill("kongming-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kongming-quan/kong", 1);
        me->add("contribution", -500);

        return 1;
}
