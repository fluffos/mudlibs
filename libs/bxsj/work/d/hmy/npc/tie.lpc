#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("铁匠", ({ "tie jiang", "tie",}));
        set("long", "他满脸的汗水，正笑嘻嘻的看着你,还不时拿起挂在脖子上的抹布擦脸　n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        
        set("max_qi", 600);
        set("max_jing", 300);


        set_skill("parry", 60);
        set("vendor_goods", ({
           (["name": BINGQI_D("changjian"),"number":25]),
           (["name": BINGQI_D("sword"),"number":15]),
           (["name": ARMOR_D("armor"),"number":22]),
           (["name": BINGQI_D("blade"),"number":10]),
           (["name": BINGQI_D("duanjian"),"number":10]),
           (["name": BINGQI_D("panguanbi"),"number":20]),
           (["name": BINGQI_D("tiegun"),"number":10]),
           (["name": BINGQI_D("gangzhang"),"number":12])
        }));
        setup();
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "铁匠笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来挑几件兵器用吧。\n");
                        break;
                case 1:
                        say( "铁匠用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}