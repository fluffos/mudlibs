// stat_me.c by fire on Dec 1998
// 
#include <char.h>
string stat_me(string p_id,int priority)
{
   string p_ret="";
   mixed c;
   if(!char_exist(p_id))
       return "没有这个角色。\n";
   c=get_char(p_id,"");
   if(!c["gift"]) c["gift"]=([]);
   p_ret+=sprintf("角色代号：%-14s姓名：%s\n",p_id, c["name"]);
   p_ret+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
   p_ret+=sprintf("字：%4s  性别：%2s  年龄：%3d 容貌：%d\n",
       (sizeof(c["zi"]) ? c["zi"] : "━━" ),
       (c["gender"]==1 ? "男" :"女"),c["age"],c["gift"]["rongmao"]);
   p_ret+=sprintf("所属国：%-10s  所在地：%-8s\n",
     (sizeof(c["nation"]) ? COUNTRY_D->get_country(c["nation"],"name") : "━━"),
     (sizeof(c["area"]) ? AREA_D->get_area(c["area"],"name") : "━━" ));
   p_ret+=sprintf("朝廷官职：%-8s  地方官职：%-8s\n",
     OFFICER_D->query_rank_name(c["ranknation"]),
     OFFICER_D->query_rank_name(c["ranklocal"]));
   if(priority<2)
   {  if(!c["skills"]) c["skills"]=([]);
      p_ret+=sprintf("武力：%d  智谋：%d  魅力：%d  俸禄：%d\n",
       c["skills"]["sk_wuli"],c["skills"]["sk_zhimou"],
       c["skills"]["sk_meili"],get_char(p_id,"salary"));
      p_ret+=sprintf("声望：%s(%d) 地区贡献：%d  国家贡献：%d 忠诚：%d\n",
        get_char(p_id,"reputationstr"),c["reputation"],
        get_char(p_id,"localcontribution"),get_char(p_id,"nationcontribution"),get_char(p_id,"loyalty"));
      p_ret+=sprintf("类型：%s  状态：%s  事务：%s\n",
        (c["type"]==TYPE_NPC ? "NPC " :"玩家"),
        get_char(p_id,"statustr"),get_char(p_id,"taskstr"));
   }
   if(priority<1)
   {  string *list,*a_tmp;
      string s_tmp;
      p_ret+="与他国关系：\n";
      list=COUNTRY_D->list_countries();
      s_tmp=c["nation"];
      list-=({s_tmp});
      a_tmp=({});
      foreach(string n_id in list)
      {  s_tmp=sprintf("%6s：%3d ",
            COUNTRY_D->get_country(n_id,"name"),
            CHAR_D->get_char_loyalty(p_id,n_id));
         a_tmp+=({s_tmp});
      }
      p_ret+=sprintf("%-#50s\n",implode(a_tmp,"\n"));
      if(!c["myarmy"]) c["myarmy"]=([]);
      p_ret+=sprintf("亲兵数：%d  训练：%d  马匹：%d  弓箭：%d  粮食：%d\n",
        c["myarmy"]["qbnum"],c["myarmy"]["train"],
        c["myarmy"]["horse"],c["myarmy"]["bow"],c["myarmy"]["food"]);
   }
   return p_ret;
}
