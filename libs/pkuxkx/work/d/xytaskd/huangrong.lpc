#include <ansi.h>
inherit NPC;
int ask_mudi();
void create()
{
	set_name("黄蓉",({"huang rong","huang","rong"}));
	set("nickname",GRN"桃花"NOR+YEL"仙子"NOR);
        set("no_clean_up",1);
	set("title",HIC"郭夫人"NOR);
	set("long","她是一位美若天仙的女子,眉清目秀,笑容可掬.\n");
	set("gender","女性");
	set("age",32);
	set("per",100);
	set("shen_type",1);
	set("str",24);
	set("int",32);
	set("con",24);
	set("dex",24);
	set("max_qi",3000);
	set("max_jing",3000);
	set("neili",1800);
	set("max_neili",1800);
	set("jiali",100);
	set("combat_exp",1500000);
	set_skill("force",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("finger",150);	
	set_skill("staff",150);
	set_skill("bihai-shengong",150);
	set_skill("luoying-shenfa",150);
	set_skill("dagou-bang",150);
	set_skill("tanzhi-shengong",90);
	map_skill("dodge","luoying-shenfa");
	map_skill("staff","dagou-bang");
	map_skill("force","bihai-shengong");
	map_skill("finger","tanzhi-shengong");
      set_temp("jia_count",1);
	prepare_skill("finger","tanzhi-shengong");
	set("chat_chance_combat",100);
        set("inquiry",([
        
	]));
	setup();
	set("chat_chance",5);
        set("chat_msg",({
        "黄蓉道：靖哥哥，我们要与襄阳共存亡！\n",
        }));
	carry_object("/d/city/obj/cloth")->wear();
	
}
