// yanjiumei.c Ñà¾ÅÃÃ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"Ñà¾ÅÃÃ"NOR, ({"yan jiumei", "yan"}));
       set("long", "ÉíÇáËÆÑà£¬Çá¹¦¶À²½ÎäÁÖ¡£\n");
       set("title", HIC"ÌìÑı¹¬"NOR);
       set("per", 30);
       set("gender", "Å®ĞÔ");
       set("age", 18);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "µÜ×Ó");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 400);
       set("max_force", 400);
       set("force_factor", 20);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("sword", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "ÎÒÊÇÑıË§÷âÏÂ¾Å´ó¸ßÊÖÖ®Ò»¡£\n",
	"here"     : "ÕâÀïÊÇÌìÑı¹¬¡£\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}

ÿ
