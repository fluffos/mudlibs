// by fire on Dec 31 1997
// chenghu_d.c the 称呼系统
#include <ansi.h>
inherit M_ANSI;
string *lvs=({ "目不识丁","粗通文字","断文识字","小有文采",
"下笔千言","落笔有神","辅国茂才","贤良方正","盖世孝廉","千古文豪",});
string *cls=({RED,GRN ,ORG, BLU ,MAG ,CYN ,WHT ,HIR ,HIG ,HIY ,HIB ,HIM ,HIC ,HIW ,});
string *ju_name=({"白身","关内侯","亭侯","乡侯","县侯","男爵","子爵","伯","侯","公","王"});
string *ju_color=({WHT,ORG,RED,GRN,BLU,MAG,HIR,HIG,HIB,HIC,HIY,});
int *ju_rep=({10000,20000,50000,70000,100000,120000,140000,160000,180000,1000000});
int *ju_lit=({50,100,200,500,700,1000,1500,2000,2500,3000});

string stat_me_ju() {
	string ret;
	int i,sum;
	sum=sizeof(ju_name);
	ret="等级  爵位    声望要求    文学要求\n";
	for(i=1;i<sum;++i) 
		ret+=sprintf("%2d    %-6s   %7d    %d\n",
			i,ju_name[i],ju_rep[i-1],ju_lit[i-1]);
	return ret;

}
int query_ju_lit(int i) {	return ju_lit[i];
}
int query_ju_rep(int i) {	return ju_rep[i];
}
string query_ju_str (int i) {
	if(i>=sizeof(ju_name)) i=sizeof(ju_name)-1;
	return ju_color[i]+ju_name[i];
}
string query_char_jun (string p_id) {	int j, n;
	string ss, s="";
	j=CHAR_D->get_char(p_id,"ju");
	if(j) {		
		s=CHAR_D->get_char(p_id,"ju_n");
		if(!sizeof(s))
			s=AREA_D->get_area(
				CHAR_D->get_char(p_id,"area"),"name");
			}
	s = s+query_ju_str(j);
	ss = colour_truncate(s,8);
	if( (n=10-strlen(ss))<=0 ) return s;
	j = n>>1;
	if( n%2&&10%2) j++;
	return power_str(" ",j) + s + power_str(" ",n-j);
}
string query_char_jun_who(string p_id) {
	return ju_color[CHAR_D->get_char(p_id,"ju")]+"【"+query_char_jun(p_id)+"】"+NOR;
	}
string query_chenghu_C(object w1, object w2) //表示亲近的自我称呼，通常在对话中
{	int p_gender;
	int p_age1,p_age2;
	string p_id1,p_id2;
	if(!w2->is_living()) return "主人";
	p_age1=w1->query_age();
	p_age2=w2->query_age();
	p_gender=w1->query_gender();
	p_id1=w1->query_primary_id();
	p_id2=w2->query_primary_id();
	if(p_gender==1)  // male
	{
		if(CHAR_D->get_char(p_id1,"mar")==p_id2)
			return "为夫";
		if((p_age1-p_age2)>50)			return "爷爷";
		if((p_age1-p_age2)>15)			return "叔叔";
		if((p_age1-p_age2)>=0)			return "兄长";
		if((p_age2-p_age1)>50)			return "孙儿";
		if((p_age2-p_age1)>15)			return "侄儿";
		return "小弟";
	}
	else  // female
	{
		if(CHAR_D->get_char(p_id1,"mar")==p_id2) return "妾身";
		if((p_age1-p_age2)>50)			return "奶奶";
		if((p_age1-p_age2)>15)			return "婶婶";
		if((p_age1-p_age2)>=0)			return "姐姐";
		if((p_age2-p_age1)>50)			return "孙女";
		if((p_age2-p_age1)>15)			return "侄女";
		return "小妹";
	}
}
string query_chenghu_c(object w1,object w2)  //表示亲近的对方称呼，通常在对话中
{	int p_gender;
	int p_age1,p_age2;
	string p_id1,p_id2;
	if(!w2->is_living()) return "宝贝";
	p_age2=w1->query_age();
	p_age1=w2->query_age();
	p_gender=w2->query_gender();
	p_id1=w1->query_primary_id();
	p_id2=w2->query_primary_id();
	if(p_gender==1)  // male	
	{	if(CHAR_D->get_char(p_id1,"mar")==p_id2) return "夫君";
		if((p_age1-p_age2)>=50)			return "老身";
		if((p_age1-p_age2)>=15)			return "叔叔";
		if((p_age1-p_age2)>0)			return "兄长";
		if((p_age2-p_age1)>=50)			return "孙儿";
		if((p_age2-p_age1)>=15)			return "贤侄";
		return "贤弟";
	}	else  //	female
	{	if(CHAR_D->get_char(p_id1,"mar")==p_id2) return "贤妻";
		if((p_age1-p_age2)>=50)			return "老身";
		if((p_age1-p_age2)>=15)			return "婶婶";
		if((p_age1-p_age2)>0)			return "姐姐";
		if((p_age2-p_age1)>=50)			return "孙女";
		if((p_age2-p_age1)>=15)			return "侄女";
		return "贤妹";
	}
}
string query_chenghu_S(object who) //正常的自我称呼，通常在对话中
{	if(who->query_is_junzhu())  // 是否君主
return "朕";
	if(who->query_is_jiangjun()) // 是否将军
		return "本将军";
	if(who->query_is_guan())  // 是否为官
		return "本官";
	if((who->query_gender())!=1)
		return "民女";
	return "草民";
}
string query_chenghu_s(object who)  //谦卑的自我称呼，通常在对话中
{	if(who->query_is_junzhu())  // 是否君主
		return "寡人";
	if(who->query_is_jiangjun()) // 是否将军
		return "末将";
	if(who->query_is_guan())  // 是否为官
                return "卑职";
	if((who->query_gender())!=1)
		return "小女子";
	return "小人";
}
string query_chenghu_R(object me, object who)  //正常的对方称呼
{	int p_age;
	string p_id,t_id;
	if(!objectp(me)) me=who;
	if(!objectp(who)) who=me;
	p_id=me->query_primary_id();
	t_id=who->query_primary_id();
	if(!who->is_living()) return "宝贝";
	p_age=who->query_age();
	if((who->query_gender())==1)	{
		if(CHAR_D->get_char(p_id,"mar")==t_id)	return "夫君";
		if(who->query_is_junzhu())  // 是否君主
			return "陛下";
		if(who->query_is_jiangjun()) // 是否将军
		{
			if(p_age>60)	return "老将军";
			if(p_age>20)
				return "将军";
			return "小将军";
		}		if(who->query_is_guan())  // 是否为官
			return "大人";
		if(p_age>50)			return "老先生";
		if(p_age>20)			return "先生";
		return "小兄弟";
	}
	else //female
	{	if(CHAR_D->get_char(p_id,"mar")==t_id)	return "爱妻";
		if(who->query_is_junzhu())  // 是否君主	
		return "女王陛下";
		if(who->query_is_jiangjun()) // 是否将军
		{	if(p_age>60)	return "老将军";
			if(p_age>20)	return "女将军";
			return "小将军";
		}
		if(who->query_is_guan())  // 是否为官
			return "大人";
		if(p_age>50)	return "老婆婆";
		if(p_age>30)	return "大婶";
		if(p_age>20)	return "姑娘";
		return "小姑娘";
	}
}
string query_chenghu_r(object me, object who)  //辱骂的对方称呼。
{	int p_age;
	string p_id,t_id;

	if(!objectp(me)) me=who;
	if(!objectp(who)) who=me;

	if(!who->is_living()) return "废物";
	p_id=me->query_primary_id();
	t_id=who->query_primary_id();
	p_age=who->query_age();
;
	if((who->query_gender())==1)	{
		if(CHAR_D->get_char(p_id,"mar")==t_id)	return "混帐";
		if(who->query_is_junzhu())  // 是否君主	
			return "昏君";
		if(who->query_is_jiangjun()) // 是否将军	
		{	if(p_age>60)	return "老贼";
			if(p_age>20)	return "贼将";
			return "小贼";
		}
		if(who->query_is_guan())  // 是否为官
			return "昏官";
		if(p_age>50)	return "老不死的";
		if(p_age>20)	return "蠢才";
		return "小混蛋";
	}	else //female
	{
		if(CHAR_D->get_char(p_id,"mar")==t_id)	return "浪货";
		if(who->query_is_junzhu())  // 是否君主
			return "妖后";
		if(who->query_is_jiangjun()) // 是否将军	
		{ if(p_age>60)	return "老女贼";
			if(p_age>20) return "女贼";
			return "小贼";
		}
		if(who->query_is_guan())  // 是否为官
			return "昏官";
		if(p_age>50)
			return "贼婆子";
		if(p_age>30)
			return "老贱人";
		if(p_age>20)	return "贱人";
		return "小贱人";
	}	
}
string literate_str(int i) {
      if(i<10) return cls[0]+lvs[0]+NOR;
      if(i<50) return cls[1]+lvs[1]+NOR;
      if(i<100) return cls[2]+lvs[2]+NOR;
      if(i<200) return cls[3]+lvs[3]+NOR;
      if(i<500)  return cls[4]+lvs[4]+NOR;
      if(i<1000) return cls[5]+lvs[5]+NOR;
      if(i<1500) return cls[6]+lvs[6]+NOR;
      if(i<2000) return cls[7]+lvs[7]+NOR;
      if(i<3000) return cls[8]+lvs[8]+NOR;
      return cls[9]+lvs[9]+NOR;
 }
