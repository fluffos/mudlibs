//dizi.c
//by 诸葛不亮
//2009.8.15

#include <ansi.h>
inherit NPC;

void do_check();
void greeting(object);
void init();
void create()
{
        set_name("武馆弟子", ({ "wuguan dizi", "dizi" }) );
	    set("title",HIC"太乙武馆弟子"NOR);
        set("gender", "男性" );
        set("age", 24);
        set("long","这是一个太乙武馆的弟子，虽然入门不久，却俨然已有一番武林人士的气度。\n");
        set("attitude", "peaceful");
        set("con", 20);
        set("str", 20);
        set("int", 20);
        set("dex", 20);
    	set("per",26);
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 0);
        set("shen_type", 1);
        set("combat_exp", 50000);
        set_skill("force", 60);
        set_skill("strike", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 100);
	set_skill("taiyi-shengong",60);
	set_skill("taiyi-zhang",60);
	set_skill("taiyi-jian",60);
	set_skill("taiyi-you",60);
	map_skill("force", "taiyi-shengong");
	map_skill("strike", "taiyi-zhang");
	map_skill("sword", "taiyi-jian");
	map_skill("dodge", "taiyi-you");
	map_skill("parry", "taiyi-jian");
	prepare_skill("strike", "taiyi-zhang");
	set("chat_chance", 1);
	set("chat_msg", ({
	name()+"自豪地说：“虽说我太乙武馆不开山不立派，可这武功可不是江湖杂耍的人能比的。”\n",
	name()+"说道：“太乙武馆无门无派，只求混口江湖饭，不参与门派纷争。”\n",
 	}));
setup();
carry_object("/d/city/obj/cloth")->wear();
carry_object("/clone/weapon/changjian")->wield();
}

