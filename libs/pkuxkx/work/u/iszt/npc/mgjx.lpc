#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("蒙古奸细", ({ "mgjx"}));
        set("gender", "女性");
        set("per", 30);
        set("age", 18);
        set("shen_type",0);
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 30);
        set("con", 25);
        set("dex", 25);
        set("kar", 32);
        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 50);
        set("combat_exp", 2787355);
        set("score", 2000);

        set_skill("force", 300);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("hand",300);
        set_skill("strike", 280);
        set_skill("throwing",300);
        set_skill("sword",300);

        set_skill("literate",400);

        set_skill("zhemei-shou",300);
        set_skill("liuyang-zhang",280);
        set_skill("changhen-jian",190);
        set_skill("lingbo-weibu",290);
        set_skill("bahuang-gong", 300);
        set_skill("tianyu-qijian",300);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "lingbo-weibu");
        map_skill("throwing", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "zhemei-shou");
        map_skill("sword","tianyu-qijian");

        prepare_skill("strike","liuyang-zhang");
        prepare_skill("hand","zhemei-shou");

        create_family("灵鹫宫",2,"少主人");

        setup();
        carry_object("/u/iszt/obj/biyuxiao")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");
        carry_object("/d/lingjiu/obj/jiudai");

        add_money("gold",100);

}

void attempt_apprentice(object ob)
{
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("recruit " + ob->query("id"));
        command("trip " + ob->query("id"));
        command("patx " + ob->query("id"));
        return;
}
