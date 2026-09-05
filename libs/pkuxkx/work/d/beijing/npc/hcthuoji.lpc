//Cracked by Roath
// bankhuoji  回春堂伙计
// Ssy

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("张德福", ({ "zhang defu", "zhang", "defu", "huoji" }));
        set("title","一笑堂伙计");
        set("str", 20);
        set("gender", "男性");
        set("age", 25);
        set("long", "他是个勤劳的伙计，长的胖胖的很可爱。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/obj/jinchuang",
                "/d/city/obj/yangjing"
        }));

        set("shen_type",1);set("score",500);setup();
	carry_object("/clone/armor/cloth")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
