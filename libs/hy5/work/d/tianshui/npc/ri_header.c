// ri_header.c

inherit NPC;

void create()
{
        set_name("雷开远", ({ "lei kaiyuan", "lei", "kaiyuan" }) );
        set("title", "日月镖局总镖头");
        set("gender", "男性" );
        set("age", 45);
        set("str", 30);
        set("cor", 27);
        set("int", 23);
	set("max_kee",1300);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 20);

        set("long",@LONG
日月镖局是由雷开远一手创立的，凭着不错的武功
和江湖上广泛的人缘，日月镖局的生意越来越好。
LONG);

        set("combat_exp", 100000);
        set_skill("unarmed", 100);
        set_skill("parry", 150);
        set_skill("dodge", 100);
        set_skill("blade", 120);
        set_skill("force", 100);

        setup();
	carry_object(__DIR__"obj/key1");
        carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
