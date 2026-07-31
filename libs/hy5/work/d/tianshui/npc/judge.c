// design by 发现号(find) . all right reserved.

// judge.c

inherit NPC;

void create()
{
        set_name("宝官", ({ "judge" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "他脸上的表情仿佛是看到了你口袋里的钱一般。\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        set("inquiry", ([
                "赌" : "客官您把钱给我就行了。\n",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "宝官喊道：“快来赌吧，赌全色可是一赔八！”\n");
                        break;
                case 1:
                        say( "宝官喊道：“快来赌吧，发了财畅春园的姑娘可任您选啦！”\n");
                        break;
        }
}
