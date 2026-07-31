// peng.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("彭连虎", ({ "peng lianhu", "peng", "lianhu" }));
        set("gender", "男性");
        set("nickname", HIR"千手人屠"NOR);
        set("age", 43);
        set("str", 25);
        set("dex", 16);
        set("per", 20);
        set("long", "彭连虎五短身材，满眼红丝，目光如电，上唇短须翘起。他生性
残暴，和沙通天有深厚的交情。\n");
        set("combat_exp", 200000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set("max_qi", 1100);
        set("max_jing", 800);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 50);
        set("combat_exp", 600000);
        set("shen", -6000);

    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 120);
    set_skill("dodge", 100);

    set_skill("shaolin-shenfa", 120);
    set_skill("hand", 100);
    set_skill("weituo-zhang", 120);
    set_skill("parry", 100);
    set_skill("staff", 100);
    set_skill("qianye-shou", 120);
    set_skill("literate", 50);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("hand", "qianye-shou");
    map_skill("parry", "weituo-zhang");
    map_skill("staff", "weituo-zhang");
    prepare_skill("hand", "qianye-shou");

         set("inquiry", ([
                "郭靖" : "嘿嘿, 怎麽你有他的消息吗。",
                "穆颜萍" : "那可是个美人啊。",
                "沙通天" : "是我的结拜兄弟！",
                "侯通海" : "也是我的兄弟啊！",
                "钱青健" : "你问这麽多干什麽？",
        ]) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
        add_money("silver", 30);
}
