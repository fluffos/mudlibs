//*******************************************************************
// skills.c *******************************************************
// by fire on Dec 29 1997
// updated by tset Feb 7 1998
#include <ansi.h>
#include "/wiz/fire/fire.h"
inherit VERB_OB;
inherit M_OUT;
inherit CHINESE_DA;
inherit CLASS_SG_SKILL;
mixed can_skills_liv(object liv)
{
        return 1;
}
private void skills_print(object who)
{
        string s_tmp;
        string * self_skills;
        int p_wuli,p_zhimou,p_meili;
        int p_tmp;
        int i,j;

        p_wuli=who->query_sk_level("sk_wuli");
        if (!p_wuli)
        {
                p_wuli=who->query_wuli_pure();
                who->set_sg_skill("sk_wuli",p_wuli,0);
        }
        p_zhimou=who->query_sk_level("sk_zhimou");
        if (!p_zhimou)
        {
                p_zhimou=who->query_zhimou_pure();
                who->set_sg_skill("sk_zhimou",p_zhimou,0);
        }
        p_meili=who->query_sk_level("sk_meili");
        if (!p_meili)
        {
                p_meili=who->query_meili_pure();
                who->set_sg_skill("sk_meili",p_meili,0);
        }
printf(
"-----------------------------------------------------\n");
printf("基本修养：    名称         等级    经验 \n");
out_skill("sk_wuli",who);
out_skill("sk_zhimou",who);
out_skill("sk_meili",who);
printf("所学阵法：\n");
        self_skills=who->query_self_skills();
        i=sizeof(self_skills);
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_ZHENG)
                        out_skill(s_tmp , who);
        }
printf("所学计谋：\n");
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_JI)
                        out_skill(s_tmp , who);
        }


printf("基本武功：\n");
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_WEAPON)
                        out_skill(s_tmp , who);
        }

printf("特殊招法：\n");
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_FIGHT)
                        out_skill(s_tmp , who);
        }

printf(
"-----------------------------------------------------\n");
return;  
}
void do_skills()
{
        object who;
        who=this_body();   
        skills_print(who);
}
void do_skills_str(string liv)
{
        object ob;
        if(!(wizardp(this_body()->query_userid())))
        {
                printf("只有巫师才可以透视别人的状况\n");
                return;
        }
        else
        {
                ob = present(liv, environment(this_body()));
                if (!ob) ob = find_body(liv);
                if (!ob) {
                        write("你要察看谁的技能？\n");
                        return;
                }
		if (!ob->is_living()) {
			write("你察不出物件能有什么技能。\n");
			return;
		}
                skills_print(ob);
        }
}
mixed * query_verb_info()
{
    return ({ ({ "", "STR", }),({  }) });
}
