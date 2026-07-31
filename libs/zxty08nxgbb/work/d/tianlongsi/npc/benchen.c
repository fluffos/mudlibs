inherit NPC;
void create()
{
    set_name("±¾³¾", ({ "ben chen","chen"}) );
    set("gender", "ÄĞĞÔ" );
    set("class", "bonze");
    set("age", 70);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("qi", 3500);
    set("max_qi", 3500);
    set("jing", 1500);
    set("max_jing", 1500);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 150);
    set("combat_exp", 800000);
    set_skill("force", 120);
    set_skill("yiyang-zhi", 120);
    set_skill("dodge", 180);
    set_skill("parry", 120);
    set_skill("unarmed", 185);
    set_skill("kumu-shengong", 180);
    set_skill("buddhism", 120);
    set_skill("literate", 120);
    map_skill("force", "kumu-shengong");
    map_skill("unarmed", "yiyang-zhi");
    
    setup();
    carry_object(__DIR__"obj/y-jiasha")->wear();
}
