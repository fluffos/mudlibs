// stat_me.c by fire on Dec 1998
// for area to inherit
string stat_me(string a_id,int priority)
{
   string p_ret="";
   mixed c,p_tmp;
   int *list_title;
   string *list_char,s_tmp,a_nation;
   mixed * a_tmp;
   int i,j,v_left;
   mapping troop;

   if(!AREA_D->area_exist(a_id))
       return "没有这个地区。\n";
   c=AREA_D->get_area(a_id,"");
   p_ret+=sprintf("地区代号：%-14s名称：%s\n",a_id, c["name"]);
   p_ret+="〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
   p_ret+=sprintf("等级：%d 天气：%4s  人口：%d\n",
      c["level"], DAY_D->get_weather_short(c["weather"]),
      c["population"]);
   if(priority<1)
     p_ret+=sprintf("安定：%3d 工业：%3d 农业：%3d 商业：%3d 重点：%s\n",
        c["safe"],c["industry"],c["agriculture"],c["business"],
                AREA_D->get_area(a_id,"importancestr"));
   if(priority<2)
      p_ret+=sprintf("物资：%d 粮草：%d 金：%d\n",
           c["stuff"],c["food"],c["gold"]);
   p_ret+=sprintf("国君：%s 太守：%s 国税：%d 地税：%d\n",
       CHAR_D->get_char(c["nation"],"name"),
       CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name"),
       c["taxnation"],c["taxlocal"]);
   if(priority<2)
   {
     p_ret+=sprintf("预计金月收入：%d 粮年收入：%d 物月收入：%d\n",
       AREA_D->get_area(a_id,"goldin"),AREA_D->get_area(a_id,"foodin"),
       AREA_D->get_area(a_id,"stuffin"));
     p_ret+=sprintf(
        "金月支出（士兵：%d 官员：%d ）粮月支出：%d 物月支出：%d\n",
         AREA_D->get_area(a_id,"goldout"),
         AREA_D->get_area(a_id,"salary"),
         AREA_D->get_area(a_id,"foodout"),
         AREA_D->get_area(a_id,"stuffout"));
     p_ret+=sprintf(
       "士兵：%d 训练：%d 士气：%d 马匹：%d 弓箭：%d 匪人：%d\n",
       AREA_D->get_area(a_id,"soldier"),c["train"],c["morale"],c["horse"],
       c["bow"],c["bandit"]);
       if(sizeof(c["st"])) {
           foreach(string st_it in keys(c["st"])) {
           p_ret+=sprintf("%s：%d  ",(EV_MERCHANT)->query_goods(st_it,"name"),
		c["st"][st_it]);
           }
	   p_ret+="\n";
       }

	troop = c["troop"];
	if( mapp(troop) ){
		i = 0;
		foreach(string tt in keys(troop)){
			i++;
			if( i >= 3 ){
				i = 0;
				p_ret+="\n";
			}
			p_ret+=sprintf("%-20s:%-7d%3s", WARAI_D->query_type(tt, "name")+"("+tt+")", troop[tt], "");
		}
		p_ret+="\n";
	}
    }
    p_ret+="官员：\n";
    list_title=OFFICER_D->query_area_officer_title_all(c["level"]);
    list_char=CHAR_D->check_char("area",a_id);
    for(i=0;i<sizeof(list_title);++i)
    {  p_ret+=OFFICER_D->query_rank_name(list_title[i])+"：";
       a_tmp=filter_array(list_char,
            (:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
       for(j=0;j<sizeof(a_tmp);++j)
       {   p_ret+=CHAR_D->get_char(a_tmp[j],"name");
           p_ret+=" ";
       }
       v_left=OFFICER_D->query_max_officer_number(list_title[i]);
       v_left-=sizeof(a_tmp);
       for(j=0;j<v_left;++j)
           p_ret+="━━ ";
       p_ret+="\n";
    }
    p_ret+="闲职和国家官员：";
    a_nation=AREA_D->get_area(a_id,"nation");
    for(j=0;j<sizeof(list_char);++j)
    {   p_tmp=CHAR_D->get_char(list_char[j],"nation");
        if(p_tmp==a_nation) {
		if(!CHAR_D->get_char(list_char[j],"ranklocal")) {
			CHAR_D->set_char(list_char[j],"ranklocal",R_SG);
		}
		if(CHAR_D->get_char(list_char[j],"ranklocal")==R_SG)
	            p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
	}
    }
    p_ret+="\n";
    p_ret+="相邻地区：";
    if(sizeof(c["neighbor"]))
    { foreach(string a in c["neighbor"])
      {   p_ret+=(AREA_D->get_area(a,"name")+" ");
      }
    }
    p_ret+="\n";
    p_ret+="本地隐居贤人：";
    for(j=0;j<sizeof(list_char);++j)
    {   p_tmp=CHAR_D->get_char(list_char[j],"nation");
        if((!p_tmp)||(p_tmp==""))
            p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
    }
    p_ret+="\n";
    return p_ret;
}
