// stat_me.c by fire on Dec 1998
// 
#include <char.h>
#include <ansi.h>
inherit VERB_OB;
inherit M_OUT;
inherit CHINESE_DA;
inherit M_ANSI;
string space="                                        ";
void skill_check(string p_id) {
	mapping gift;
	if(CHAR_D->get_char(p_id,"is_tmp")) return;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return;
	gift=CHAR_D->get_char(p_id,"gift");
	if(!mapp(gift)) {
		SGSYS(p_id+"don't have gift !!!!!!");
	}
	if(CHAR_D->get_skill(p_id,"sk_zhimou")<31)
		CHAR_D->set_char(p_id,"zhimou",gift["zhimou"]);
	if(CHAR_D->get_skill(p_id,"sk_meili")<31)
		CHAR_D->set_char(p_id,"meili",gift["meili"]);
	if(CHAR_D->get_skill(p_id,"sk_wuli")<31)
		CHAR_D->set_char(p_id,"wuli",gift["wuli"]);

}
string stat_me(string p_id,int priority)
{
	string p_ret="";
    string tm1,tm2;
	mixed c;
	//write("运行到char_exist()函数前面了\n"); DEBUG
	if(!char_exist(p_id))
		return "没有这个角色。\n";
	c=get_char(p_id,"");
	if(!c["gift"]) c["gift"]=([]);
		skill_check(p_id);
   
	p_ret+=
      "%^MAGENTA%^〓〓〓〓〓%^H_GREEN%^人%^RESET%^%^MAGENTA%^〓〓〓〓〓%^H_GREEN%^"+
      "物%^RESET%^%^MAGENTA%^〓〓〓〓〓%^H_GREEN%^资%^RESET%^%^MAGENTA%^〓〓〓〓〓"+
      "%^H_GREEN%^讯%^RESET%^%^MAGENTA%^〓〓〓〓〓%^RESET%^\n\n";
    p_ret+="%^H_GREEN%^■一般资讯：%^RESET%^\n";
    p_ret+=sprintf("%%^H_YELLOW%%^【角色代号】%-8s【姓    名】%-8s%%^RESET%%^%%^H_RED%%^【   字   】%4s%%^RESET%%^  \n"
            ,p_id, c["name"],(sizeof(c["zi"]) ? c["zi"] : "━━" ));
	p_ret+=sprintf("%%^H_YELLOW%%^【性    别】%-8s【年    龄】%-8d【容    貌】%d%%^RESET%%^\n",
       (c["gender"]==1 ? "男" :"女"),c["age"],c["gift"]["rongmao"]);
        tm1="%^H_CYAN%^【 所属国 】"+(sizeof(c["nation"]) ? COUNTRY_D->get_country(c["nation"],
           "name") : "━━")+"("+
        (sizeof(c["nation"]) ? CHAR_D->get_char(p_id,"nation") : "━━")+")%^RESET%^";
        tm2="%^H_CYAN%^【忠    诚】"+CHAR_D->get_char(p_id,"loyalty")+"%^RESET%^";
        p_ret+=sprintf("%s%s%s\n",tm1,space[0..39-colour_strlen(tm1)],tm2);

    tm1=sprintf("%%^H_CYAN%%^【 所在地 】%s(%s)%%^RESET%%^",
   (sizeof(c["area"]) ? AREA_D->get_area(c["area"],"name") : "━━"),
   (sizeof(c["area"]) ? CHAR_D->get_char(p_id,"area") : "━━"));
   tm2="%^H_CYAN%^【勤 奋 度】"+CHAR_D->get_char(p_id,"tsx")+"%^RESET%^";
     p_ret+=sprintf("%s%s%s\n",tm1,space[0..39-colour_strlen(tm1)],tm2);
   p_ret+=sprintf("%%^H_CYAN%%^【国家官职】%-8s【地方官职】%-8s【宫廷官职】%s%%^RESET%%^\n",
     OFFICER_D->query_rank_name(c["ranknation"]),
     OFFICER_D->query_rank_name(c["ranklocal"]),
	OFFICER_D->query_rank_name(c["royalrank"]));
	p_ret+=sprintf("%%^H_YELLOW%%^【俸    禄】%d%%^RESET%%^\n",get_char(p_id,"salary"));

   if(priority<2)
   {  if(!c["skills"]) c["skills"]=([]);
      p_ret+=sprintf("%%^H_RED%%^【武    力】%-8d【智    谋】%-8d【魅    力】%d%%^RESET%%^\n",
       c["skills"]["sk_wuli"],c["skills"]["sk_zhimou"],
       c["skills"]["sk_meili"]);
      p_ret+=sprintf("%%^H_RED%%^【地区贡献】%-8d【国家贡献】%-8d\n",
        get_char(p_id,"localcontribution"),get_char(p_id,"nationcontribution"));
      p_ret+=sprintf("%%^H_GREEN%%^【声    望】%%^RESET%%^%s%%^H_WHITE%%^(%d)%%^RESET%%^\n",get_char(p_id,"reputationstr"),c["reputation"]);


      p_ret+=sprintf("%%^H_WHITE%%^【类    型】%-8s【状    态】%-8s【事    务】%-8s%%^RESET%%^\n",
        (c["type"]==TYPE_NPC ? "NPC " :"玩家"),
        get_char(p_id,"statustr"),get_char(p_id,"taskstr"));
   }
   if(priority<1)
   {  string *list,*a_tmp;
      string s_tmp;
      p_ret+="%^H_BLUE%^■与他国关系：%^RESET%^\n";
      list=COUNTRY_D->list_countries();
      s_tmp=c["nation"];
      list-=({s_tmp});
      a_tmp=({});
      foreach(string n_id in list)
      {  s_tmp=sprintf("【%8s】：%3d ",
            COUNTRY_D->get_country(n_id,"name"),
            CHAR_D->get_char_loyalty(p_id,n_id));
         a_tmp+=({s_tmp});
      }
      p_ret+=sprintf("%-#60s\n",implode(a_tmp,"\n"));
      if(!c["myarmy"]) c["myarmy"]=([]);
      p_ret+="%^H_CYAN%^■私人武装：%^RESET%^\n";
      p_ret+=sprintf("%%^H_YELLOW%%^【亲兵数量】%-28d【训    练】%d%%^RESET%%^\n",
        c["myarmy"]["qbnum"],c["myarmy"]["train"]);
        p_ret+=sprintf("%%^H_YELLOW%%^【马    匹】%-8d【弓    箭】%-8d【粮    食】%-8d%%^RESET%%^\n",
        c["myarmy"]["horse"],c["myarmy"]["bow"],c["myarmy"]["food"]);
	if(sizeof(c["wear"])){
      p_ret+=sprintf("%%^H_MAGENTA%%^【坐    骑】：%%^RESET%%^%s\n",
	(sizeof(c["wear"]["horse"]) ? OBJ_D->get_obj(c["wear"]["horse"],"name"): "无"));}
	if(!sizeof(c["wear"])){
	p_ret+=sprintf("%%^H_MAGENTA%%^【坐    骑】：%%^RESET%%^无\n"
);}
      p_ret+="%^H_CYAN%^※坐骑挨饿："+chinese_number(c["myarmy"]["h_nf"])+"个月。%^RESET%^\n";

   }
     p_ret+="\n%^B_RED%^%^H_YELLOW%^◎三国等级点◎%^RESET%^%^H_YELLOW%^：%^H_MAGENTA%^"+get_char(p_id,"sgrate")+"%^RESET%^\n";
   p_ret+="\n%^MAGENTA%^〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓%^B_WHITE%^%^BLACK%^三国志%^RESET%^%^MAGENTA%^〓〓%^RESET%^\n";
   return p_ret;
}
