//*******************************************************************
// skills.c *******************************************************
// by fire on Dec 29 1997
// updated by tset Feb 7 1998
// updated by flee@sgz Dec 10 1999
#include <ansi.h>
#include <sanguo.h>

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
        string s_tmp, *self_skills;
        int p_wuli, p_zhimou, p_meili, p_tmp, i, j;

        p_wuli=who->query_sk_level("sk_wuli");
        p_zhimou=who->query_sk_level("sk_zhimou");
        p_meili=who->query_sk_level("sk_meili");

        if( !p_wuli ){
                p_wuli=who->query_wuli_pure();
                who->set_sg_skill("sk_wuli",p_wuli,0);
        }
        if( !p_zhimou ){
                p_zhimou=who->query_zhimou_pure();
                who->set_sg_skill("sk_zhimou",p_zhimou,0);
        }
        if( !p_meili ){
                p_meili=who->query_meili_pure();
                who->set_sg_skill("sk_meili",p_meili,0);
        }

printf(
"%%^CYAN%%^〓〓〓〓〓〓〓〓〓%%^H_YELLOW%%^技%%^RESET%%^%%^CYAN%%^〓〓〓〓〓〓%%^H_YELLOW%%^能%%^RESET%%^%%^CYAN%%^〓〓〓〓〓〓〓〓〓%%^RESET%%^\n\n");
printf("              %%^H_CYAN%%^〖名称〗 〖ＩＤ〗    〖等级〗〖经验〗%%^RESET%%^\n");
printf("%%^H_MAGENTA%%^〖基本修养〗%%^RESET%%^\n");
out_skill("sk_wuli",who);
out_skill("sk_zhimou",who);
out_skill("sk_meili",who);
printf("%%^H_GREEN%%^〖所学阵法〗%%^RESET%%^\n");
        self_skills=who->query_self_skills();
        i=sizeof(self_skills);
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_ZHENG)
                        out_skill(s_tmp , who);
        }
printf("%%^H_RED%%^〖所学计谋〗%%^RESET%%^\n");
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_JI)
                	out_skill(s_tmp , who);
        }


printf("%%^H_YELLOW%%^〖基本武功〗%%^RESET%%^\n");
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_WEAPON)
                	out_skill(s_tmp , who);
        }

printf("%%^H_WHITE%%^〖特殊招法〗%%^RESET%%^\n");
        for(j=0 ; j<i ; ++j)
        {
                s_tmp=self_skills[j];
                if((SG_SKILL_D->query_type(s_tmp))==SK_FIGHT)
                	out_skill(s_tmp , who);
        }

printf(
"\n%%^CYAN%%^〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓%%^B_YELLOW%%^%%^H_GREEN%%^三国志%%^RESET%%^%%^CYAN%%^〓〓〓%%^RESET%%^\n");
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
                printf("只有巫师才可以透视别人的状况。\n");
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
