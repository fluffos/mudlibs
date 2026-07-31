inherit NPC;
void create()
{
    set_name("éÔ·ò",({"qiao fu"}));
    set("age",54);
    set("wimpy",50);
    set("combat_exp",200);
    set_skill("unarmed",30);
    setup();
    add_money("silver",1);
    carry_object("/clone/misc/cloth")->wear();
}