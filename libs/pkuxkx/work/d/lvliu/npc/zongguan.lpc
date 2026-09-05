#include <ansi.h>
inherit NPC;

void create()
{
        set_name("大总管", ({ "da zongguan", "zongguan" }));
		set("title",HIG"绿柳" HIY "山庄"NOR);
        set("long","他大约60多岁年纪，是这绿柳山庄的大总管，负责总管山庄内外一切事务。\n");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 66);
		set("combat_exp", 1000000000);
		set("str", 60);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("max_qi", 30000);
        set("max_jing", 30000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 400);
        set("score", 500000);
		set_skill("force", 2000);
        set_skill("jiuyin-zhengong", 2000);
        set_skill("xuanming-zhangfa", 2000);
        set_skill("dodge", 2000);
        set_skill("jiuyin-shenfa", 2000);
        set_skill("strike", 2000);  
        set_skill("parry", 2000);
        map_skill("force","jiuyin-zhengong");
        map_skill("dodge","jiuyin-shenfa");
        map_skill("strike","xuanming-zhangfa");
        map_skill("parry","xuanming-zhangfa");
		set_temp("apply/armor", 900);
		set_temp("apply/damage", 400);
        prepare_skill("strike", "xuanming-zhangfa");
		set("inquiry",([
			"赵敏":"那是我们郡主，她现在就在庄内招待各路英雄。",
			]));
        setup();
}

void init()
{
}

void unconcious()
{
	die();
}

void die()
{
	object ob=this_object();
	message_vision("$N眼见不对，急忙从怀里掏出一颗丹药咽下，脸色逐渐又恢复了正常。\n", ob);
	ob->set("eff_qi",ob->query("max_qi"));
	ob->set("qi",ob->query("max_qi"));
	ob->set("eff_jing",ob->query("max_jing"));
	ob->set("jing",ob->query("max_jing"));
	ob->clear_condition();
	ob->remove_all_killer();
	return;
}
