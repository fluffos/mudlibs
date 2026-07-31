
// room_guard.c
inherit NPC;


void create()
{
        set_name("士兵", ({ "guard" }) );
        set("title", "宁远 边军");
        set("gender", "男性" );
        set("age", 25);
        set("long", "你看到一个剽悍的边军。\n");
     set("shen_type",-1);
          set("str", 15);
          set("con", 30);
          set("cor", 30);
          set("max_kee", 600);
          set("kee", 600);
        set("int", 14);
        set("combat_exp", 10000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);


        setup();
        add_money("silver", 12);
        add_money("coin", 500);
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

