inherit BHNPC;

void create()
{
    set_name(HIY"巡查使"NOR,({"xun cha","xuncha","xun"}));
        set("gender", "男性" );
        set("age", 26);
        set("shen_type",1);
        set("attitude", "peaceful");
        set("long","他是一位铁血盟的巡查使，平时负责盟内的安全事务。\n");
        set("nickname", HIR "铁血盟" NOR);
        set("combat_exp",2000000);
        set("str", 30);
        set_skill("unarmed",500);
        set_skill("dodge",500);
        set_skill("parry",500);
        set("max_neili",1000);
        set("neili",1000);
        create_family("铁血盟",2,"弟子");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
   
}

