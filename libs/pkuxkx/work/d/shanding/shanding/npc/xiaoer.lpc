// xiaoer2.c 酒店小二
// Rewrote by iszt@pkuxkx, 2007-02-11
//modified by zhx
//2009.8.25

inherit NPC;
inherit F_DEALER;

void create()
{
    set_name("迷糊张", ({ "mihu zhang", "mihu", "zhang" }) );
    set("nickname", "老迷糊");
    set("gender", "男性" );
    set("age", 53);
    set("str", 30);
    set("int", 24);
    set("con", 30);
    set("dex", 24);
    set("leiting", 1);
    
        set("qi", 20000);
        set("max_qi", 20000);
        set("per", 38);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 60000);
        set("max_neili", 60000);
        set("jiali", 850);
        set("no_nuoyi",1);
        
        set("combat_exp",91000000);
        set("score", 200000);
         
        set("chat_chance_combat", 50);
        set_skill("force", 2000);             // 基本内功
        set_skill("huntian-qigong", 2000);    // 混天气功
        set_skill("parry",2000);
        set_skill("strike", 2000);
        set_skill("xianglong-zhang", 2000);   // 降龙十八掌
        set_skill("dodge", 2000);             // 基本躲闪

        set_skill("xiaoyaoyou", 2000);        // 逍遥游
        set_skill("staff", 2000);             // 基本棍杖
        set_skill("dagou-bang", 2000);        // 打狗棒法
        set_skill("checking", 2000);          // 道听途说
        set_skill("begging", 250);
        set_skill("stealing", 1500);
        
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");

        prepare_skill("strike", "xianglong-zhang");
        
     //   create_family("丐帮", 17, "帮主");
     //   setup();
        
    //    carry_object(__DIR__"yuzhu_zhang");
      //  carry_object(__DIR__"jiaohuaji");
//}
    set("long", 
    "他本是武林中赫赫有名的丐帮长老大人物,最近不知因何来此开起了小酒馆。\n"
    "他正举着酒杯，邀客人痛饮。\n");
    set("attitude", "friendly");
    set("rank_info/respect", "小二哥");
    set("vendor_goods", ({
        "/clone/food/jitui",
        "/clone/food/jiudai",
        "/clone/food/baozi",
        "/d/riyuejiao/obj/niurou",
    }));
    setup();
}

void init()
{
    object ob; 
    mapping myfam; 

    ob = this_player();

    ::init();
    if( interactive(ob) && !is_fighting() ) {
        if ( (myfam = ob->query("family"))
            && myfam["family_name"] == "丐帮" 
            && environment(this_object())->query("short") == "酒店"
            && ob->query_skill("begging",1) > 10 )
        {
            remove_call_out("saying");
            call_out("saying", 0, ob);
        }
        else
        { 
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
        }
    }

    add_action("do_buy", "buy");
    add_action("do_list", "list");
}

void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    if( !this_object()->visible(ob)) return;
    switch( random(2) ) {
        case 0:
            say( "酒神张笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                + "，进来喝杯酒，歇歇腿吧。\n");
            break;
        case 1:
            say( "酒神张举起杯中酒一饮而尽，说道：这位" + RANK_D->query_respect(ob)
                + "，请了请了。\n");
            break;
    }
}

void saying(object ob)
{
    if (!ob || environment(ob) != environment()) return;

    say("\n酒神张见"+ob->name()+"进来，劝道：「您还是换个地方要饭吧，小店伺候不起。」\n\n");
    remove_call_out("kicking");
    call_out("kicking", 1, ob);
    
}

void kicking(object ob)
{
    if (!ob || environment(ob) != environment()) return;

    ob->move("/d/qilincun/xiaolu1");
    message("vision","只听「乒」地一声，" +  ob->query("name") +
        "被人从酒店里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
