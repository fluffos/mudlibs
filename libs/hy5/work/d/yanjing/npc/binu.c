inherit NPC;
void create()
{
    set_name("婢女",({"bi nu"}));
    set("gender","女性");
    set("combat_exp",1000);
    set("attitude","friendly");
       set("per",25);
    set("age",15);
    set("long","一个挽双丫髻的丫鬟.\n");
    set_skill("unarmed",10);
    setup();
add_money("coin",30);
carry_object(__DIR__"obj/cloth")->wear();
}
