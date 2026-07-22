// sha.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("沙通天", ({ "sha tongtian", "sha", "tongtian" }));
        set("gender", "男性");
        set("title", HIY"黄河帮帮主"NOR);
        set("nickname", HIC"鬼门龙王"NOR);
        set("age", 43);
        set("str", 25);
        set("dex", 16);
        set("per", 12);
        set("long", "沙通天是个秃子，头上油光光地没半根头发，双目布满红丝，眼
珠突出，生就一副异相。性子暴躁，武功却是出奇地高，江湖上
无人不晓。\n");
        set("attitude", "peaceful");
        
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 50);
        set("combat_exp", 550000);
        set("shen", -5500);
 
        set_skill("force", 100);
        set_skill("hunyuan-yiqi", 120);
        set_skill("dodge", 100);

        set_skill("shaolin-shenfa", 120);
        set_skill("cuff", 100);
        set_skill("damo-jian", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("jingang-quan", 80);
        set_skill("literate", 30);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "damo-jian");
        map_skill("sword", "damo-jian");
        prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("gold", 1);
}
