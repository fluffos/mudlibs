// m_out.c by fire on Dec 22, 1997
#include <sanguo.h>
#include <ansi.h>
string  get_disp_color(int p_tmp)
{
	if(p_tmp<10)
		return RED;
	if(p_tmp<33)
		return HIR;
	if(p_tmp<66)
		return HIY;
	if(p_tmp<101)
		return HIG;
	return HIC;
}
// this function is used to test if the exp is good enough to increase one level
int get_exp_lev(string p_sk,int p_lev,int p_exp,object who)
{
        string gft;
        int p_gift;
        int exp_need;
        gft="/daemons/sg_skilllearn_d"->get_need_gift(p_sk);
       switch (gft) {
        case "zhimou":
          p_gift=who->query_zhimou_pure();
          break;
       case "meili":
          p_gift=who->query_meili_pure();
          break;
       case "wuli":
          p_gift=who->query_wuli_pure();
          break;
       }
        exp_need="/daemons/sg_skilllearn_d"->get_exp_need(p_lev,p_gift) ;
        if(exp_need==0) return 101;

	return 100*p_exp/exp_need;
}
void out_skill(string p_sk, object who)
{
	string s_tmp, ss;
	int p_lev,p_exp;

	s_tmp=SG_SKILL_D->query_name(p_sk);
	if( SG_SKILL_D->query_type(p_sk)!=1 ) ss="("+p_sk+")";
	p_lev=who->query_sk_level(p_sk);
	p_exp=who->query_sk_exp(p_sk);
//modify by suicide in 20011230 for add □ for enable high skills
printf("            %s%s%-14s%s%4d    %d%s\n",
((member_array(p_sk,values(who->query_skill_map()))!=-1)?BLU+"□"+NOR:"  "),        
s_tmp, (stringp(ss)?ss:""), 
get_disp_color(get_exp_lev(p_sk,p_lev,p_exp,who)),p_lev,p_exp,NOR);
	return;
}
//end
string fight_result(object who)
{
    int p_tmp,p_tmp2;
    p_tmp=who->query_sg_max_hp();
    if(p_tmp<=0)
	p_tmp=1;
    p_tmp2=who->query_cur_hp();
    if(p_tmp2<=0)
	p_tmp=-1;
    else	
   p_tmp=p_tmp2*100 / p_tmp;
    switch (p_tmp) {
    case -1:
	return get_disp_color(p_tmp)+ "$N伤势过重，看来已经没救了。\n";
    case 0..10:
        return get_disp_color(p_tmp)+  "$N已经奄奄一息了。"+NOR+"\n";   
    case 11..25:
        return get_disp_color(p_tmp)+ "$N受了相当重的伤，只怕有生命危险。"+NOR+"\n";   
    case 26..50:
        return get_disp_color(p_tmp)+
                     "$N已经伤痕累累，正在勉力支撑着不倒。"+NOR+"\n";   
    case 51..75:
        return get_disp_color(p_tmp)+
                     "$N受了几处伤，看起来状况不太好。"+NOR+"\n";   
    case 76..85:
        return get_disp_color(p_tmp)+
                     "$N看起来可能受了些轻伤。"+NOR+"\n";   
    case 86..95:
        return get_disp_color(p_tmp)+
                     "$N似乎受了点轻伤，不过从表面看不出来。"+NOR+"\n";   
    case 96..99:
        return get_disp_color(p_tmp)+
                     "$N似乎有些疲惫，但仍然十分有活力。"+NOR+"\n";   
    case 100:
        return get_disp_color(p_tmp)+
                     "$N气色很好，毫发无伤。"+NOR+"\n";
                     break;
    default:
       printf("the p_tmp is %d\n",p_tmp);
//         error("query_hp() out of bounds\n");
 }
}
