// wusangui.c 吴三桂
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("吴三桂", ({ "wu sangui", "wu" }));
	set("age", 58);
	set("title", HIR"平西王"NOR);
	set("gender", "男性");
	set("long", "这就是大名鼎鼎的引清兵入关的平西王---吴三桂\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("dex", 30);
	set("combat_exp", 8000000);
	set("shen_type", -100);

	set_skill("unarmed", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("blade", 280);
	set_skill("force", 280);
	set_temp("apply/attack", 180);
	set_temp("apply/defense", 180);
	set_temp("apply/damage", 1180);
	set_temp("apply/armor", 1180);
 set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 32000);
        set("eff_qi", 32000);
        set("max_qi", 32000);
        set("max_jingli", 32000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");

         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 1500);
        set_temp("apply/damage", 1200);
        set_temp("apply/attack", 200);

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/guanfu")->wear();
}



void die()
{
			int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
message_vision("\n$N奇道：“咦,我的关宁铁骑 我的天下,....”说完睁着两眼倒地死了。\n", this_object());

if((int)who->query("jinyong/book7")==5 && who->query_temp("book761"))
{	
	i = 500+random(800);
	who->set("jinyong/book7",6);
	who->add("combat_exp",i+15880);
	who->add("potential",i*18);
	who->add("mpgx",10);
	who->add("expmax",2);
message_vision("\n$N说道：“桑结活佛，关外的老毛子不会放过你的....。\n", this_object());
	tell_object (who,"你赢得了"+chinese_number(i+15880)+"点经验"+
	           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
}

	::die();
}