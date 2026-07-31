// penglianhu.c 彭连虎

inherit NPC;
 
void create()
{
        set_name("彭连虎", ({ "peng lianhu", "peng", "lianhu" }));
        set("nickname", "千手人屠");
        set("long", 
        "他就是杀人不不眨眼的大盗千手人屠彭连虎。\n"
        "一个一脸邪气，并且十分狡猾的家伙。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("str", 29);
        set("int", 20);
        set("con", 25);
        set("dex", 23);
        
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
           add_money("gold",2);
}
