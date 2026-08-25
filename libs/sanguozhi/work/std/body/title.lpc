// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** title.c -- title handling for the player
**
** Designed to be removed from the player object if necessary.
**
** 95-May-01. Deathblade. Created.
*/
#include <ansi.h>
private string title; 		// this is be not used any more
private string title2; 		// created by fire
string query_userid();		/* in /std/player */
string query_chinese_name();/* in naming.c */
string query_title()
{
        string ret;
        string p_tmp;
        string p_id;
        p_id=query_userid();
		//printf("进了query_title()函数, p_id = %s\n", p_id); DEBUG
//        ret="【"+CHAR_D->get_char(p_id,"reputationstr")+NOR+"】";
        ret="";
        p_tmp=COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name");
		//printf("nation name为: %s\n", p_tmp); DEBUG
        if(p_tmp)
                ret+=p_tmp;
        p_tmp=OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranknation"));
		//printf("ranknation为: %s\n", p_tmp); DEBUG
        if(p_tmp!="━━")
        {
                ret+=p_tmp;
        }
        else
        {
                p_tmp=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name");
				//printf("area name为: %s\n", p_tmp); DEBUG
                if(p_tmp)
                    ret+=p_tmp;
                else
					ret = ret[0..<2];
                p_tmp=OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranklocal"));
				//printf("ranklocal为: %s\n", p_tmp); DEBUG
                if(p_tmp=="━━")
					p_tmp=" 隐士 ";//"隐居贤人";
                ret+=p_tmp;
        }
        if(title2&&(title2!=""))
                ret+="「"+title2+NOR+"」";
        ret+=query_chinese_name();
//        p_tmp=CHAR_D->get_char(p_id,"zi");
         p_tmp=this_object()->query_sg_zi();
        if(p_tmp)
                ret+="，字"+p_tmp;
        ret+="("+p_id+")";
        return ret;
}

void set_title(string str)
{
    if ( !str ) str = "";
    title2 = str;
}
