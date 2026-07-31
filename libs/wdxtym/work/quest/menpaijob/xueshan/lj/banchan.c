//Cracked by Kafei
// /d/hangzhou/npc/kumu.c
// by aln  2 / 98
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_job();

void create()
{
	set_name(HIY"班禅活佛"NOR, ({
		"banchan huofo",
		"banchan",
		"huofo",
	}));
	set("long",
"班禅活佛是雪山寺有道的高僧，对佛法有精深的研究。 \n"+
"他身穿一件黄色袈裟，头带僧帽。慈眉善目他身材略高，\n"+
"太阳穴微凸，双目炯炯有神。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("qi", 26500);
set_temp("no_kill",1);
	set("max_qi", 26500);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 26000);
	set("max_neili", 26000);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 100);

	set_skill("lamaism", 270);
	set_skill("force", 270);
	set_skill("hunyuan-yiqi", 270);
	set_skill("dodge", 270);
	set_skill("shaolin-shenfa", 270);
	set_skill("finger", 270);
	set_skill("nianhua-zhi", 270);
	set_skill("parry", 270);
	set_skill("buddhism", 270);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");

        set("inquiry", ([
                "讲经" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

	setup();

        carry_object("/d/xueshan/obj/y-jiasha")->wear(); 
        carry_object("/d/xueshan/obj/sengmao")->wear(); 
 }

string ask_job()
{
        object obj, place, *inv, me = this_player();

        if( is_fighting() || is_busy() )
                return "我正忙着。";
        if( me->query("family/family_name") != "雪山寺")
                return "本寺，只请本寺高僧每天讲经说法。";
        if( (string)me->query("class") != "bonze" )
                return "阿弥陀佛！善哉！善哉！施主不是佛门弟子，还是请回吧。";

        if( (int)me->query_skill("lamaism", 1) < 50 )
                return "本寺只延请密宗心法高深的前来讲经说佛。";


        if( me->query_condition("xsjob") )
                return RANK_D->query_respect(me) + "已经在讲经说佛了。";
        if( me->query_temp("xsjob2") )
                return RANK_D->query_respect(me) + "已经在讲经说佛了。";

        if( me->query_condition("xsjob2") )
                return RANK_D->query_respect(me) + "刚刚进过经了，休息一会再来吧。";

        command("nod");
me->set_temp("xsjob2",1);
        me->apply_condition("xsjob", 3 + random(3));


        return "太好了，本寺正需一名外寺高僧前来讲经说佛。";
}

