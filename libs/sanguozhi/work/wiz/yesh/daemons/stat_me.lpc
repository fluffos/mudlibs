// stat_me.c by fire on Dec 1998 
// for area to inherit
string get_zhoumu_name(string a_id) {
	string ret;
	string p_id;
	string zhou,zhouhd;

	zhou=AREA_D->get_area(a_id,"zhou");
	zhouhd=AREA_D->get_zhou_head(zhou);
	p_id=AREA_D->get_area(zhouhd,"zm");
	if(!p_id) return "";
	if(CHAR_D->get_char(p_id,"nation")!=AREA_D->get_area(zhouhd,"nation")) {
		AREA_D->set_area(zhouhd,"zm",0);
		return "";
	}
	if(AREA_D->get_area(a_id,"nation")!=AREA_D->get_area(zhouhd,"nation"))
		return "";
	return "%^H_MAGENTA%^【州    牧】"+CHAR_D->get_char(p_id,"name");
}
string product_estimate(string a_id) {
	string *bs;
	object ob;
	string ret="";
//	string ret="%^H_CYAN%^【生产能力】（估计月产量）%^RESET%^\n";
	mapping pd=([]);
	mapping tmp;
	bs=AREA_D->get_area(a_id,"base");
	if(!sizeof(bs)) return "";
	foreach(string b in bs) {
		ob=SGBASE(a_id,b);
		if(!objectp(ob)) continue;
		tmp=ob->get_base_product_estimate();
		if(!sizeof(tmp)) continue;
		foreach(string st,int val in tmp)
			pd[st]+=val;
	}
	if(!sizeof(pd)) return "";
	foreach(string stf, int v in pd) {
		if(!BASE_D->stuff_exist(stf)) continue;
		ret+=BASE_D->get_stuff(stf,"name")+"："+chinese_number(v)+
			BASE_D->get_stuff(stf,"unit")+"  ";
	}
	ret+="\n";
	return ret;

}
string stat_me(string a_id,string para,int priority)
{
	string p_ret="";
	mixed c,p_tmp;
	int *list_title;
	string *list_char,s_tmp,a_nation;
	mixed * a_tmp;
	int i,j,v_left;
	string p_id;
	mapping troop,home; //2001.11.6 yesh add home
	p_id=this_body()->query_id()[0];
if(!AREA_D->area_exist(a_id))
	return "没有这个地区。\n";
	c=AREA_D->get_area(a_id,"");
if(para=="")
{     
	p_ret+="\n\n%^H_CYAN%^info aa %^H_YELLOW%^<area_id>%^RESET%^：显示目标地区所有信息；\n";
	p_ret+="%^H_CYAN%^info ag %^H_YELLOW%^<area_id>%^RESET%^：显示目标地区基本信息；\n";
	p_ret+="%^H_CYAN%^info am %^H_YELLOW%^<area_id>%^RESET%^：显示目标地区军事及储备信息；\n";
	p_ret+="%^H_CYAN%^info af %^H_YELLOW%^<area_id>%^RESET%^：显示目标地区财政信息；\n";
	p_ret+="%^H_CYAN%^info ao %^H_YELLOW%^<area_id>%^RESET%^：显示目标地区人事信息；\n";
	p_ret+="%^H_CYAN%^info a%^RESET%^           ：显示本信息。\n\n";
	p_ret+="注：若%^H_YELLOW%^<area_id>%^RESET%^为%^H_YELLOW%^here%^RESET%^，则显示所在地相关信息。\n\n";
	return p_ret;
}
	p_ret+="%^MAGENTA%^〓〓〓〓〓〓%^H_GREEN%^地%^RESET%^%^MAGENTA%^〓〓〓〓〓%^H_GREEN%^区%^RESET%^%^MAGENTA%^〓〓〓〓〓%^H_GREEN%^资%^RESET%^%^MAGENTA%^〓〓〓〓〓%^H_GREEN%^讯%^RESET%^%^MAGENTA%^〓〓〓〓〓〓%^RESET%^\n";
if(para=="g")
	p_ret+="\n%^B_WHITE%^%^BLACK%^◆分类显示◆%^RESET%^%^H_YELLOW%^之%^H_RED%^基本信息%^H_YELLOW%^：%^RESET%^\n\n";
if(para=="m")
	p_ret+="\n%^B_WHITE%^%^BLACK%^◆分类显示◆%^RESET%^%^H_YELLOW%^之%^H_RED%^军事及储备信息%^H_YELLOW%^：%^RESET%^\n\n";
if(para=="f")
	p_ret+="\n%^B_WHITE%^%^BLACK%^◆分类显示◆%^RESET%^%^H_YELLOW%^之%^H_RED%^财政信息%^H_YELLOW%^：%^RESET%^\n\n";
if(para=="o")
	p_ret+="\n%^B_WHITE%^%^BLACK%^◆分类显示◆%^RESET%^%^H_YELLOW%^之%^H_RED%^人事信息%^H_YELLOW%^：%^RESET%^\n\n";
if(para=="a"||para=="g")
	p_ret+="%^H_CYAN%^★"+AREA_D->get_area(a_id,"zhou")+"★ %^RESET%^\n";
if(para=="g"||para=="a"||para=="s")
	p_ret+="%^H_GREEN%^■一般资讯：%^RESET%^\n";
	p_ret+=sprintf("%%^H_YELLOW%%^【地区代号】%-8s【名    称】%-8s【 所属国 】%s%%^RESET%%^\n",a_id, c["name"],COUNTRY_D->get_country(AREA_D->get_area(a_id,"nation"),"name"));
if(para=="g"||para=="a")
	p_ret+=sprintf("%%^H_YELLOW%%^【等    级】%-8d【天    气】%-8s【人    口】%-8d%%^RESET%%^\n",
      c["level"], DAY_D->get_weather_short(c["weather"]),c["population"]);
if(para=="g"||para=="a"||para=="s")
{
	if(priority<2)
	p_ret+=sprintf("%%^H_YELLOW%%^【安    定】%-8d【发展重点】%s%%^RESET%%^\n",
	c["safe"],AREA_D->get_area(a_id,"importancestr"));
}
if(para=="f"||para=="a"||para=="s")
{
	if(priority<1)
	p_ret+=sprintf("%%^H_YELLOW%%^【工    业】%-8d【农    业】%-8d【商    业】%d%%^RESET%%^\n",
	c["industry"],c["agriculture"],c["business"]);
}
if(para=="g"||para=="a"||para=="s")
{
	if(priority<2)
	p_ret+=sprintf("%%^H_RED%%^【主    公】%-8s%%^H_RED%%^【太    守】%-8s%%^RESET%%^%s\n",
	CHAR_D->get_char(c["nation"],"name"), CHAR_D->get_char(AREA_D->get_area(a_id,"leader"),"name"),get_zhoumu_name(a_id));
}
if(para=="f"||para=="a"||para=="s")
{
	if(priority<1)
	p_ret+=sprintf("%%^H_YELLOW%%^【   金   】%-8d%%^H_RED%%^【国    税】%-8d【地    税】%d%%^RESET%%^\n", c["gold"],c["taxnation"],c["taxlocal"]);
}
if(para=="f"||para=="a"||para=="s")
{
	if(priority<1)
	{
	p_ret+="%^H_BLUE%^■基地生产及收支状况：%^RESET%^\n";
	p_ret+="%^H_CYAN%^【生产能力】（估计月产量）%^RESET%^\n";
	p_ret+="%^H_GREEN%^───────────────────────────────\n";
	p_ret+=product_estimate(a_id);
	p_ret+="%^H_GREEN%^───────────────────────────────\n";
	p_ret+=sprintf("%%^H_CYAN%%^【金月收入】%-8d%%^RESET%%^\n",
	AREA_D->get_area(a_id,"goldin"));
	p_ret+=sprintf("%%^H_CYAN%%^【金月支出】（士兵：%d 官员：%d）%%^RESET%%^\n",
	AREA_D->get_area(a_id,"goldout"),
	AREA_D->get_area(a_id,"salary"));
	p_ret+=sprintf("%%^H_CYAN%%^【粮月支出】%-8d【物月支出】%d%%^RESET%%^\n",
	AREA_D->get_area(a_id,"foodout"),AREA_D->get_area(a_id,"stuffout"));
	}
}
if(para=="m"||para=="a"||para=="s")
{
	if(priority<1)
	{
	p_ret+="%^H_WHITE%^■地区防卫及物资储备：%^RESET%^\n";
      p_ret+=sprintf("%%^H_YELLOW%%^【士    兵】%-8d【训    练】%-8d【士    气】%-8d%%^RESET%%^\n",
	AREA_D->get_area(a_id,"soldier"),c["train"],c["morale"]);
	if(sizeof(c["st"]))
		{
		p_ret+="%^H_CYAN%^───────────────────────────────\n";
		foreach(string st_it in keys(c["st"]))
			{
			p_ret+=sprintf("%s：%d  ",(EV_MERCHANT)->query_goods(st_it,"name"),
			c["st"][st_it]["num"]);  //suicide 2000.02.26
			} 
		p_ret+="\n";
		}
	troop = c["troop"];
	if( mapp(troop) )
	{
	i = 0;
	foreach(string tt in keys(troop))
		{
		i++;
		if( i >= 3 )
			{
			i = 0;
 			p_ret+="\n";
			}
		p_ret+=sprintf("%-20s:%-7d%3s", WARAI_D->query_type(tt,"name")+"("+tt+")", troop[tt], "");
		}
	p_ret+="\n%^H_CYAN%^───────────────────────────────%^RESET%^\n";
	}
	}
}
if(para=="o"||para=="a")
{
	p_ret+="%^H_MAGENTA%^■地区官员：%^RESET%^\n";
	list_title=OFFICER_D->query_area_officer_title_all(c["level"]);
	list_char=CHAR_D->check_char("area",a_id);
	for(i=0;i<sizeof(list_title);++i)
	{
	p_ret+="%^H_WHITE%^□"+OFFICER_D->query_rank_name(list_title[i])+"：%^RESET%^";
	a_tmp=filter_array(list_char,
		(:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
		for(j=0;j<sizeof(a_tmp);++j)
		{
		p_ret+=CHAR_D->get_char(a_tmp[j],"name");
		p_ret+=" ";
		}
	v_left=OFFICER_D->query_max_officer_number(list_title[i]);
	v_left-=sizeof(a_tmp);
	for(j=0;j<v_left;++j)
	p_ret+="━━ ";
	p_ret+="\n";
	}
	p_ret+="%^H_RED%^■闲职及国家官员：%^RESET%^\n";
	a_nation=AREA_D->get_area(a_id,"nation");
	for(j=0;j<sizeof(list_char);++j)
	{
	p_tmp=CHAR_D->get_char(list_char[j],"nation");
		if(p_tmp==a_nation)
		{
			if(!CHAR_D->get_char(list_char[j],"ranklocal"))
			{
			CHAR_D->set_char(list_char[j],"ranklocal",R_SG);
			}
			if(CHAR_D->get_char(list_char[j],"ranklocal")==R_SG)
			p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
		}
	}
	p_ret+="\n";
}
if(para=="g"||para=="a")
{	p_ret+="%^H_YELLOW%^■相邻地区：%^RESET%^\n";
	p_ret+="%^H_RED%^───────────────────────────────\n";
	if(sizeof(c["neighbor"]))
	{
	foreach(string a in c["neighbor"])
		{
		p_ret+=(AREA_D->get_area(a,"name")+" ");
		}
	}
	p_ret+="\n";
	p_ret+="%^H_RED%^───────────────────────────────\n";

	if(sizeof(c["base"]))
	{
		p_ret+="%^H_YELLOW%^■生产基地：%^RESET%^\n";
		p_ret+="%^H_RED%^───────────────────────────────\n";
		foreach(string a in c["base"])
		{
			p_ret+=(BASE_D->get_base(a,"name")+"("+SGBASE(a_id,a)->get_level()+") ");
		}
	}
	p_ret+="\n";
	p_ret+="%^H_RED%^───────────────────────────────\n";

}
if (para=="o"||para=="a")
{
//2001.11.6 added by yesh
	p_ret+="%^H_WHITE%^■地方豪强：%^RESET%^\n";
	p_ret+="%^H_YELLOW%^───────────────────────────────\n";
	for(j=0;j<sizeof(list_char);++j)
	{
	p_tmp=CHAR_D->get_char(list_char[j],"nation");
	home=CHAR_D->get_char(list_char[j],"h"); 
		if((!p_tmp)||(p_tmp=="")||(mapp(home)))
		p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
	}
	p_ret+="\n";
	p_ret+="%^H_YELLOW%^───────────────────────────────\n";
//2001.11.6 until here added by yesh
	p_ret+="%^H_WHITE%^■本地隐居贤人：%^RESET%^\n";
	p_ret+="%^H_YELLOW%^───────────────────────────────\n";
	for(j=0;j<sizeof(list_char);++j)
	{
	p_tmp=CHAR_D->get_char(list_char[j],"nation");
	home=CHAR_D->get_char(list_char[j],"h"); //2001.11.6 added by yesh
		if((!p_tmp)||(p_tmp=="")||(!mapp(home))) //2001.11.6 modified by yesh
		p_ret+=(CHAR_D->get_char(list_char[j],"name")+" ");
	}
	p_ret+="\n";
	p_ret+="%^H_YELLOW%^───────────────────────────────\n";
}
	p_ret+="\n%^MAGENTA%^〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓%^B_WHITE%^%^BLACK%^三国志%^RESET%^%^MAGENTA%^〓〓〓%^RESET%^\n";
	return p_ret;
}