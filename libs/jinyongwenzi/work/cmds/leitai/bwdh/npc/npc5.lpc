// yaoshi.c

#include <ansi.h>
inherit NPC;
void create()
{       
        set_name("小黄药师", ({ "huang yaoshi", "huang", "yaoshi" }) );
        set("title",HIW"桃花岛开山祖师"NOR);
        set("nickname", HIY"桃花岛主"NOR);
        set("long", 
                "他就是桃花岛的岛主，江湖上人人闻名变色的东邪黄药师。\n" 
                "他身穿一件青色长袍，腰带上斜插着一只玉箫。\n"
                "他形相清癯，丰姿隽爽，萧疏轩举，湛然若神。\n");
        set("gender", "男性" );
        set("age", 50);
        set("attitude", "peaceful");
        set("apprentice",1);
        set("str",30);
        set("int",50);
        set("con",26);
        set("dex",30);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000);
        set("unique", 1);

        set_skill("force", 100);
        set_skill("bihai-chaosheng", 100);
        set_skill("dodge", 100);
        set_skill("suibo-zhuliu", 100);
        set_skill("parry", 100);
        set_skill("strike", 100);
        set_skill("luoying-zhang", 100);
        set_skill("leg", 100);
        set_skill("xuanfeng-tui", 100);
        set_skill("hand", 100);
        set_skill("lanhua-shou", 100);
        set_skill("finger", 100);
        set_skill("throwing", 100);
        set_skill("tanzhi-shentong", 100);
        set_skill("sword", 100);
        set_skill("yuxiao-jian", 100);
        set_skill("taoism", 100);
        set_skill("literate", 100);
        set_skill("qimen-bagua", 100);

        map_skill("force", "bihai-chaosheng");
        map_skill("dodge", "suibo-zhuliu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
        map_skill("finger", "tanzhi-shentong");
        map_skill("throwing", "tanzhi-shentong");
        map_skill("leg", "xuanfeng-tui");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        prepare_skill("strike", "luoying-zhang");
        prepare_skill("leg", "xuanfeng-tui");

        set("rank_info/respect", "桃花岛主");
        set("class", "fighter"); 

        setup();
        carry_object(__DIR__"obj/byx")->wield();
        carry_object(__DIR__"obj/rwj")->wear();        
        carry_object("/clone/medicine/jinchuang");
        carry_object("/clone/medicine/jinchuang");        
}
