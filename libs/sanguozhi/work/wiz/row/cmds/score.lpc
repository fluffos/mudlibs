//******************************************************************* 
// score.c *******************************************************
// by fire on Dec 30 1997
// last modified by tset Feb 7 1998
#include <ansi.h>
#define p_sep "%%^H_YELLOW%%^◎%%^H_CYAN%%^＝＝＝＝＝＝＝＝%%^B_RED%%^%%^H_YELLOW%%^〖个  人  档  案〗%%^RESET%%^%%^H_CYAN%%^＝＝＝＝＝＝＝＝%%^H_YELLOW%%^◎%%^RESET%%^"
inherit VERB_OB;
inherit M_OUT;
inherit CHINESE_DA;
mixed can_score_liv(object liv)
{
        return 1;
}
private void score_print(object who)
{
        string p_name;  
        int p_age, p_gender;
        int p_zhimou,p_meili,p_wuli,p_rongmao;
        string p_tmp;
	string p_id;
	int i_tmp;
	p_id=who->query_id()[0];
        p_name=who->query_title();
        if(!p_name)
                p_name=who->query_name();
        if(!p_name)
                p_name=who->query_in_room_desc();
//        printf("%s\n",p_name);
        printf("%s\n",p_sep);
	printf("%%^H_CYAN%%^‖                                                  ‖\n");
        
        p_age=who->query_age();
        p_gender=who->query_gender();
p_tmp="你是一位"+chinese_number(p_age)+"岁的"+NORMAL_D->get_dis1(p_age,p_gender);
        printf("%s。\n",p_tmp);
        p_wuli=who->query_wuli_pure();
        p_zhimou=who->query_zhimou_pure();
        p_meili=who->query_meili_pure();
        p_rongmao=who->query_sg_rongmao();
        printf("武力：[%3d] 智谋：[%3d] 魅力：[%3d] 容貌：[%3d]\n",
                p_wuli,p_zhimou,p_meili,p_rongmao);
        printf("单挑武功：%3d[%+2d] 杀伤力：%2d[%+2d] 抵抗力：%2d[%+2d] \n",
		FIGHT_D->get_pure_att_abi(who),FIGHT_D->get_add_att_abi(who),
		FIGHT_D->get_pure_att_pow(who),FIGHT_D->get_add_att_pow(who),
		FIGHT_D->get_pure_def_pow(who),FIGHT_D->get_add_def_pow(who));
        p_tmp=sprintf("所属国：%6s  所在地：%6s  忠诚：%d\n",
                COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name"),
                AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name"),
                CHAR_D->get_char(p_id,"loyalty"));
        p_tmp+=sprintf("朝廷官职：%s  地方官职：%s%s  俸禄：%d\n",
                OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranknation")),
                AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name"),
                OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranklocal")),
                CHAR_D->get_char(p_id,"salary"),
                );
        p_tmp+=sprintf("声望：%s(%d)  文学修养：%s(%d)\n",
                CHAR_D->get_char(p_id,"reputationstr"),
                CHAR_D->get_char(p_id,"reputation"),
                who->query_literate_str(),
		who->query_literate()
                );
	printf("%s",p_tmp);
  
        printf("%s\n",p_sep);
	return;
}
void do_score()
{
        object who;
        who=this_body();
        score_print(who);
}
void do_score_str(string liv)
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
                        write("你要察看谁的状况？\n"); 
                        return;
                }
		if (!ob->is_living()) {
			write("察看物件的成绩？\n"); 
			return;
		}
                score_print(ob);
        }
}
mixed * query_verb_info()
{
    return ({ ({ "", "STR", }), ({  }) });
}
