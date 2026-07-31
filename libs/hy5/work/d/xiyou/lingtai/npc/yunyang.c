// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//yunyang.c
inherit NPC;
inherit F_MASTER;



void re_rank(object who);

void create()
{
        set_name("云阳真人", ({"master yunyang", "master", "yunyang"}));
        set("long", "云阳真人与菩提祖师实是半师半友，也是三星洞内外总管．
因其壮年时降魔除妖无数，人称「小天师」．\n");
        set("faith",4000);
        set("gender", "男性");
        set("title", "小天师");
        set("class", "taoist");
        set("age", 70);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("rank_info/respect", "老道长");
        set("per", 30);
        set("int", 30);
        set("str", 30);
        set("cps", 30);
        set("max_kee", 1100);
        set("max_gin", 1100);
        set("max_sen", 1100);
        set("force", 2300);
        set("max_force", 1200);
        set("force_factor", 80);
        set("max_mana", 1200);
        set("mana", 2300);
        set("mana_factor", 60);
        set("combat_exp", 800000);

     

        create_family("方寸山三星洞", 1, "蓝");
        setup();

        carry_object("/d/xiyou/lingtai/obj/bang")->wield();
}

