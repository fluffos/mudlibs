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
int get_exp_lev(int p_lev, int p_exp)
{
	int p_tmp;
	p_tmp=100*p_exp;
	p_tmp=p_tmp/(p_lev+1)/(p_lev+1);
	return p_tmp;
}
void out_skill(string p_sk, object who)
{
	string s_tmp;
	int p_lev,p_exp;
	s_tmp=SG_SKILL_D->query_name(p_sk);
	p_lev=who->query_sk_level(p_sk);
	p_exp=who->query_sk_exp(p_sk);
printf("            %s     %s  %4d%s\n",s_tmp, 
get_disp_color(get_exp_lev(p_lev,p_exp)),p_lev,NOR);
	return;
}
