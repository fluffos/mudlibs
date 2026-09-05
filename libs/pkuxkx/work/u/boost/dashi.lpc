// File         : dashi.c
// Created By   : iszt@pkuxkx, 2006-12-07

inherit NPC;
#include <ansi.h>
#define FACTOR_HS 1

#include "dashi.h"
void auto_perform();
string ask_job();


string *name = ({"远",   "济",   "恒",   "妙",   "禅",   "证",
                "鸣",   "素",   "悟",   "谛",   "竹",   "性",
});
string *id = ({ "yuan", "ji",   "heng", "miao", "chan", "zheng",
                "ming", "su",   "wu",   "di",   "zhu",  "xing",
});
string *long = ({
        "他是一位身材矮小的老年僧人，容颜瘦削，神色慈和，也瞧不出有多少年纪。\n",
                "他白眉下垂，直覆到眼上，便似长眉罗汉一般。\n",
                "他身披一件护法袈裟，貌相威武。\n",
                "他一脸的苦相，嘴角下垂，仿佛遇到了什么难以处理的事情。\n",
});

void create()
{
        string weapon;
        int index = random(sizeof(name));

        set_name("玄" + name[index] + "大师", ({"xuan" + id[index] + " dashi", "dashi"}));
        set("gender", "男性");
        set("long", long[random(sizeof(long))]);

        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 70);
        set("shen_type", 1);
        set("str", 18);
        set("int", 25);
        set("con", 21);
        set("dex", 16);
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 150);
        set("combat_exp", 1000000);
        set("score", 100000);

        set_skill("force", 140);
        set_skill("hunyuan-yiqi", 140);
        set_skill("dodge", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("strike", 140);
        set_skill("parry", 140);
        set_skill("sanhua-zhang", 140);
        set_skill("staff", 140);
        set_skill("pudu-zhang", 140);
        set_skill("buddhism", 150);
        set_skill("literate", 150);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("strike", "sanhua-zhang");
        map_skill("parry", "sanhua-zhang");
        map_skill("staff", "pudu-zhang");

        prepare_skill("strike", "sanhua-zhang");

        set("inquiry", ([
                "武当" : "近日本寺接到飞鸽传书，说道武当有难，老衲正要前往共商对策。\n",
                        "护送" : (: ask_job :),
        ]));

        create_family("少林派", 36, "弟子");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }));
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        weapon = random(2) ? "/clone/weapon/staff/budd_staff" : 0;
        setup();

        if(weapon)
                carry_object(weapon)->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
        if (clonep())
                call_out("leave",600);   
}

void leave()
{
        object ob = this_object();
        if(!ob)
                return;
        message_vision(HIY"$N长叹一声：罢了！罢了！老衲这就去了，阿弥陀佛！\n"NOR, ob);
        message_vision(HIC"$N一转身，远远离开了这是非之地。\n" NOR, ob);
        destruct(ob);
        return;
}

void init()
{
        object me = this_player();
        add_action("do_none", "guard");
        add_action("do_none", "follow");

        ::init();

}

int follow_me(object me, string dir)
{        
        int result = ::follow_me(me, dir);

        if (me == query("jobleader") && me->query_temp("sljob/asked") >= 2)
        {
                me->start_busy( 1 + random(2));
                call_out("step", 2, me);
        }
        return result;


}

string ask_job()
{
        object me = this_player();
        object ob = this_object();
        string respect = RANK_D->query_respect(me);

        if(query("jobleader") != me)
                return respect + "一片好意老衲心领了，方丈已安排了高手前来护送。";
        if(!me->query_temp("sljob/asked"))
                return "咦？你不是传言被暗算了么，怎么又出现在这里？善哉！";
        if(me->query_temp("sljob/asked") >= 2)
        {
                set_leader(me);
                return "快走罢。";
        }
        message_vision(WHT"$N决定跟随$n一起行动。\n"NOR, ob, me);
        me->set_temp("sljob/asked", 2);
        set_leader(me);
        delete("chat_msg");
        return "好的，就请这位" + respect + "在前面带路，前去武当。";
}

void auto_perform()
{
        command("exert powerup");
        command("exert recover");
}

int do_copy(object me)
{
        set("combat_exp", me->query("combat_exp") / 5 + 200000);

        set("max_jing", me->query("max_jing")/3);
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("max_jingli", me->query("max_jingli")/3);
        set("jingli", query("max_jingli"));
        set("max_qi", me->query("max_qi")/3);
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("max_neili", me->query("max_neili")/3);
        set("neili", query("max_neili"));
        set("food", 200);
        set("water", 200);

        return 1;
}

void unconcious()
{
        message_vision(HIY"$N长叹一声：罢了！罢了！老衲这就去了，阿弥陀佛！\n"NOR, this_object());
        die();
}

void die()
{
        object ob = this_object();
        object killer = query_temp("last_damage_from");

        if(killer)
                CHANNEL_D->do_channel(killer, "rumor", ob->query("name")+
                "在援救武当的途中被"+killer->query("name")+"杀死了。\n");
        else
                CHANNEL_D->do_channel(ob, "rumor", ob->query("name")+"在援救武当的途中圆寂了。\n");
        ::die();
}

void attempt_apprentice(object ob)
{
        message_vision(WHT""+this_object()->query("name") +
                "摇了摇头，对$N说道：大敌当前，老衲暂不收徒。\n"NOR, ob);
        return;
}

int do_none()
{
        return 1;
}


