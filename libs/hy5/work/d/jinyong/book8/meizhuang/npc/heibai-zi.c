// heibai.c
inherit NPC;
#include <ansi.h>;

void create()
{
        set_name("黑白子", ({ "heibai zi", "zi" }));
        set("title", "梅庄二庄主");
        set("long",
                "他就是梅庄四位庄主排行第二的秃笔翁。\n"
                "身穿一件干干净净的黑色长袍。\n"
                "他已年愈五旬，身材高大，双眼神光内敛, 一望便知是一位内家的高手。\n");
        set("gender", "男性");
        set("age", 52);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 100000);
        set("max_jing", 100000);
        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 50);
        set("combat_exp", 6000000);
        set("shen", 15000);
        set("score", 60000);

	set_skill("goplaying", 300);
        set_skill("force", 400);
        set_skill("wuzheng-xinfa", 400);
        set_skill("dodge", 400);
        set_skill("piaoyibu", 400);
        set_skill("parry", 400);
        set_skill("finger", 400);
        set_skill("staff", 400);
        set_skill("jiangjun-zhang", 400);
        set_skill("xuantian-zhi", 400);
        set_skill("literate", 130);
	set_skill("kuihua-xinfa", 400);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "xuantian-zhi");
        map_skill("staff", "jiangjun-zhang");
        map_skill("finger", "xuantian-zhi");
        prepare_skill("finger", "xuantian-zhi");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        create_family("梅庄", 1, "庄主");

        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object(__DIR__"obj/heiyi")->wear();

}

void unconcious()
{
	die();
}
void die()
{
        object who = this_object()->query_temp("last_damage_from");
        if(who) {
		message_vision("$N叹道：江湖上真是长江后浪推前浪，我老了，老了，江湖中的事我也不再插手了。\n" NOR,this_object());
	}
	destruct(this_object());
}