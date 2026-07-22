// he  何铁手

inherit NPC;
void create()
{
       set_name("何铁手", ({ "he tieshou", "he" }));
       set("title", "五毒教主");
       set("long", 
               "她就是五毒教主何铁手，却是一位年轻美貌的女子。\n"
               "一身中原女子的服饰，脸上流露出一丝冷傲。\n");
        set("gender", "女性");
       set("age", 29);
       set("attitude", "friendly");
       set("shen", -10000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       
       set("max_qi", 2000);
       set("max_jing", 1200);
       set("neili", 3000);
       set("max_neili", 3000);
       set("eff_jingli", 2500);
       set("jiali", 100);
       set("combat_exp", 1500000);
 
       set_skill("force", 160);
        set_skill("yinyun-ziqi", 160);
       set_skill("dodge", 160);
       set_skill("jinshe-zhangfa", 160);
       set_skill("tiyunzong", 160);
       set_skill("strike", 160);
       set_skill("jinshe-jianfa", 160);
       set_skill("parry", 160);
       set_skill("sword", 160);
       set_skill("poison", 120);
       set_skill("literate", 100);
        map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "jinshe-zhangfa");
       map_skill("parry", "jinshe-jianfa");
       map_skill("sword", "jinshe-jianfa");
       prepare_skill("strike", "jinshe-zhangfa");

       set("inquiry", ([
//               "秘籍" : (: ask_me :),
               "袁承志" : "他远赴渤泥岛，这些年来好久没有音信了。",
               "含沙射影" : "它是天下最毒辣的暗器。",
               "神行百变" : "天下最好的轻功，我也不过是学到一些皮毛而已。",
       ]));

       setup();
       carry_object("/clone/weapon/changjian1")->wield();
       carry_object(__DIR__"obj/shoe")->wear();
       carry_object(__DIR__"obj/red_silk")->wear();
       carry_object(__DIR__"obj/skirt")->wear();
}
