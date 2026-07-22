// shisong.c

inherit NPC;

void create()
{
	set_name("史松", ({ "shi song","shi","song"}) );
        set("long","他是朝廷命官，一身戎装威风凛凛\n");
        set("nickname", "黑龙鞭");
        set("gender", "男性");
        set("age", 30);
        set("shen_type", -1);
        set("str", 24);
        set("int", 18);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 1200);
        set("max_neili", 1200);
        set("combat_exp", 220000);
        set_skill("force", 130);
        set_skill("qiantian-yiyang", 130);
        set_skill("dodge", 130);
        set_skill("xiaoyaoyou", 130);
        set_skill("parry", 130);
        set_skill("cihang-bian", 130);
        set_skill("whip", 130);
        set_skill("cuff", 130);
        set_skill("luohan-quan", 120);
        map_skill("cuff","luohan-quan");
        map_skill("force","qiantian-yiyang");
        map_skill("dodge","xiaoyaoyou");
        map_skill("whip","cihang-bian");
        map_skill("parry","cihang-bian");
        prepare_skill("cuff","luohan-quan");
	set_temp("apply/attack", 50);
        set_temp("apply/defense", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
	"史松大声喝到：“咱们奉命捉拿江洋大盗茅十八，跟旁人并不相干，都退开了 ！”。\n",
	"史松眼露凶光，说道：“鳌少保派我们从北京到南方来，为的就是捉拿天地会反贼”。\n",
	"史松在腰间一条黑黝黝的软鞭上一拍，说道：“在下「黑龙鞭」史松，奉了鳌少保将令，擒拿天地会反贼”。\n",
       (: random_move :)
        }) );
        setup();
	carry_object(__DIR__"obj/armor")->wear();
	carry_object(__DIR__"obj/wbian")->wield();
}
