//Cracked by Kafei

int auto_perform();
#include "mingjiao_npc.c"
#include <ansi.h>

void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;
        set_name("殷天正",({"yin tianzheng","yin"}));
        set("title", "明教护教法王");
        set("nickname", HIW"白眉鹰王"NOR);
        set("long", "
一个身材魁伟的秃顶老者，长眉胜雪，垂下眼角，鼻子钩曲，
有若鹰嘴。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen", 2000000);
        create_family("明教",35,"法王");
		
		I_inquiry["name"]="在下就是明教白眉鹰王，不知阁下有何指教。";

	Skill_name=({"shenghuo-xuanming","tianying-aoxiang","baihong-jianfa",
		     "yingzhua-qinna","dafeng-yunfei","riyue-shenzhang","shenghuo-quan","guangming-xinfa"});
		Set_Inquiry(I_inquiry,Skill_name);

		Set_Npcattrib(27,5,3000,300,5000,400,6000,300,4000,1000,2000000,100000);

	S_skills["dodge"]="tianying-aoxiang";
	S_skills["sword"]="baihong-jianfa";
	S_skills["parry"]="baihong-jianfa";
	S_skills["force"]="shenghuo-xuanming";
	S_skills["cuff"]="shenghuo-quan";
	S_skills["strike"]="xiaoyao-zhangfa";
	S_skills["hand"]="dafeng-yunfei";
//	S_skills["claw"]="yingzhua-qinna";
	set_skill("guangming-xinfa",280+random(20));
	set_skill("yingzhua-qinna",320+random(20));
	set_skill("literate",200+random(20));

	map_skill("claw", "yingzhua-qinna");

	Set_Npcskills(250,20,S_skills);
	
	prepare_skill("claw","yingzhua-qinna");
	prepare_skill("hand","dafeng-yunfei");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
        setup();

        carry_object(OBJ_PATH"/changpao")->wear();
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.jingtian");
		  }
		  else return perform_action("claw.sougu");
}
