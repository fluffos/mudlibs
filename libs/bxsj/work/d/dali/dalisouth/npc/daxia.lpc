// NPC daxia.c 岭南大侠

inherit NPC;
void create()
{
       set_name("岭南大侠", ({"lingnan daxia", "daxia", "xia"}));
       set("long", "这是一个身材魁梧的大侠。\n");
       set("gender", "男性");
       set("attitude", "heroism");

       set("age", 35 + random(10));
       set("shen_type", 1);
       set("shen", 50000);
       set("str", 32);
       set("int", 24);
       set("con", 30);
       set("dex", 30);
       set("unique", 1);
       set("max_qi", 2700);
       set("max_jing", 2000);
       set("neili", 3500);
       set("max_neili", 3500);
       set("jiaji", 50+random(50));
       set("combat_exp", 600000);

       set_skill("force", 170);
       set_skill("dodge", 160);
       set_skill("unarmed", 160);
       set_skill("parry", 165);

       setup();
       add_money("silver", random(50));
       carry_object("/clone/misc/cloth")->wear();
}
