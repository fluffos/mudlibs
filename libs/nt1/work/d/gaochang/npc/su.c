// Jay 3/17/96
inherit NPC;
void create()
{
        set_name("苏普", ({ "su pu", "su"}));
        set("gender", "男性");
        set("age", 23);
        set("long", "一个年轻的哈萨克牧羊人, 哈萨克第一勇士苏鲁克的儿子。\n");
        set("attitude", "friendly");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("shen", 3000);
        set("str", 36);
        set("int", 20);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 600);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 20);
        set_skill("unarmed", 60);
        set_skill("blade", 80);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 30);
        set("inquiry", ([
            "阿曼" : "她是我老婆! 怎么着? 不服? 咱们摔摔跤。\n",
            "李文秀" : "叹,不知她上哪儿去了。这么多年我一直没法忘了她。\n",
            "计老人" : "计老人会酿又香又烈的美酒，会医牛羊马匹的疾病。\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"苏普自豪地嚷道: 我爹是哈萨克第一勇士。\n",
"苏普自言自语: 从哪儿去弄一张上等的狼皮, 送给阿秀呢? \n",
        }) );
        carry_object(__DIR__"obj/duandao")->wield();
        carry_object(__DIR__"obj/ycloth")->wear();
}
int accept_object(object who, object ob)
{
        object maotan;
         maotan = new(__DIR__"obj/maotan");
        if ((string)ob->query("name")=="灰狼皮")
           {
             say(
"苏普说道：谢谢! 谢谢! 这张毛毯是我摔跤胜桑斯儿得的奖品, 送给你略表心意。\n"
"苏普把" + maotan->query("name") + "交给了" + who->query("name") + "。\n");
             maotan->move(who);
        call_out("destroy", 1, ob);
        return 1;
        }
        return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
