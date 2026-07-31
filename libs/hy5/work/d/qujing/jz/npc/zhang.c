inherit NPC;inherit F_DEALER;


void create()
{
//   ("zhangshengshou");
        set_name("张圣手", ({"zhang shengshou", "zhang", "boss"}));
        set("title", "妙手回春");
        set("gender", "男性");
        set("age", 37);
        set("long",
"张圣手长年从事中药材的贩卖，医术也是了得。\n");
        set("qi", 300); 
        set("max_qi", 300);
        set("jing", 200);
        set("max_jing", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
      

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
      setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}






