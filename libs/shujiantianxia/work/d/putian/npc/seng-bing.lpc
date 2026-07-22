// Npc: /d/putian/npc/seng-bing.c
// Lklv 2001.9.10

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("守寺僧兵", ({
                "seng bing",
                "seng",
                "bing",
        }));
        set("long",
                "他是一位身材高大的壮年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
                "刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
        );

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 20+random(20));
        set("shen_type", 1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiaji", 50);
        set("combat_exp", 10000+random(5000));
        set("score", 1);

        set_skill("force", 50);
        set_skill("yijin-jing", 50);
        set_skill("dodge", 50);
        set_skill("shaolin-shenfa", 50);
        set_skill("unarmed", 50);
        set_skill("banruo-zhang", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);
        set_skill("cibei-dao", 50);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("unarmed", "banruo-zhang");
        map_skill("parry", "cibei-dao");
        map_skill("blade", "cibei-dao");

        setup();

        carry_object(BINGQI_D("blade/jiedao"))->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object(__DIR__"obj/huwan")->wear();
        carry_object(__DIR__"obj/huyao")->wear();
}

void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob)
        && !environment(ob)->query("no_fight")
        && !ob->query("luohan_winner")
        && !present("yingxiong ling", ob)
        && ( (fam = ob->query("family")) && fam["family_name"] != "少林派" ) )
        {
                if( !ob->query_temp("warned") ) {
                        command("say 你是谁？  怎么闯到少林寺里来了？！");
                        command("say 快给我速速离开，下次看到决不轻饶！");
                        ob->set_temp("warned", 1);
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        command("say 大胆狂徒，竟敢闯到少林寺里来撒野！！！");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
        }

}
