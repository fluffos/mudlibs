#include <ansi.h>
inherit NPC;
void create()
{
	set_name("黑老板",({"hei laoban","boss","laoban","hei"}));
	set("nickname",BLK"专做人肉包子"NOR);
	set("title",MAG"星宿派弟子"NOR);
	set("gender","无性");
	set("str",25);
        set("shen_type", -1);
	set("long","他是一个黑黑的凶悍的人。"
	"看起来很骇人的。\n");
	set("max_qi",600);
	set("combat_exp",80000+random(2000));
	set_skill("strike",50);
	set_skill("xingxiu-duzhang",60);
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("force",50);
	set_skill("huagong-dafa",60);
	set_skill("zhaixinggong",50);
	map_skill("force","huagong-dafa");
	map_skill("strike","xingxiu-duzhang");
	map_skill("dodge","zhaixinggong");
	prepare_skill("strike","xingxiu-duzhang");
	create_family("星宿派",3,"弟子");
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
	if((string)this_player()->query("family/family_name")!="星宿派"&&!wizardp(this_player()))
	{
	this_object()->kill_ob(this_player());
	return;
	}
}


	
































