// ev_merchant.c  
// this is used to handle merchant
// by fire on Nov, 1998
inherit __DIR__+"ev_merchant/base";
inherit __DIR__+"ev_merchant/disappear";
inherit __DIR__+"ev_merchant/appear";

private string m_area="";  // the area to merchant comes
private mapping m_merchants=([]); 
private mapping m_goods=([]);
private int start_time=0;

mapping query_npc_merchant_goods();

void market_over()
{
   string p_area,p_mess;
   p_area=AREA_D->get_area(m_area,"name");
   remove_call_out("market_choir");
   if(stringp(p_area))
   {
      p_mess=p_area+"集市结束，各地商人欢喜而归。";
      CHANNEL_D->deliver_tell("rumor","system",p_mess);
   }
	AREA_D->set_area(m_area,"run_market",0);
	AREA_D->set_area(m_area,"market_start_time",0);
   m_area="";
   start_time=0;
   disappear();
}
void market_choir()
{
   string p_area,p_mess;
	if((!sizeof(m_merchants))&&((time()-start_time)>3600)) {
		market_over();
		return;
	}
	if((time()-start_time)>108000) {
		market_over();
		return;
	}
		
   p_area=AREA_D->get_area(m_area,"name");
   if(stringp(p_area))
   {
      p_mess=p_area+"集市一片繁忙景象，各地商人争相叫卖。";
      CHANNEL_D->deliver_tell("rumor","system",p_mess);
   }
    remove_call_out("market_choir");
    call_out("market_choir",random(600)+60);
        
}
int has_market() {
	return AREA_D->area_exist(m_area);
}
mixed can_have_market(string p_area) {
	if(p_area==m_area)
		return "本地正在举行集市。\n";
	if(has_market())
		return AREA_D->get_area(m_area,"name")+"正在举行集市。\n";
	if(AREA_D->get_area(p_area,"gold")<1000)
		return "本地黄金不足，无法举办集市。\n";
	if(AREA_D->get_area(p_area,"safe")<100)
		return "本地安定不够，无法举办集市。\n";
	return 1;

}
mixed get_market(string what) {
	switch(what) {
	case "area":
		return m_area;
	case "start_time":
		return start_time;
	case "merchant_list":
		return keys(m_merchants);
	case "merchant_number":
		return sizeof(m_merchants);
	default:
		return 0;
	}
}

mixed get_merchant(string p_area, string what) {
        if(!mapp(m_merchants[p_area]))

		return 0;
	if((!what)||(what=="")) what="all";
	switch (what) {
	case "list":
		return keys(m_merchants[p_area]);
	case "all":
		return m_merchants[p_area];
	default:
		return m_merchants[p_area][what];
	}
}


mixed market(string p_area)
{
    string p_mess;
    mixed ret=can_have_market(p_area);
	if(stringp(ret)) return ret;
    m_area=p_area;
	start_time=time();
	AREA_D->set_area(p_area,"run_market",1);
	AREA_D->set_area(p_area,"gold",AREA_D->get_area(p_area,"gold")-1000);
	AREA_D->set_area(p_area,"market_start_time",start_time);
	AREA_D->set_area(p_area,"bn",0); // market time no bn

    p_mess=AREA_D->get_area(p_area,"name")+"举办集市，各地商人蜂拥而去。";
    remove_call_out("market_choir");
    call_out("market_choir",random(300)+60);
    CHANNEL_D->deliver_tell("rumor","system",p_mess);
    m_goods=init_good();
    m_goods+=query_npc_merchant_goods();
    create_merchant(p_area,keys(m_goods));
}
void restore_merchant() {
	string *ls;
        mapping tmp;

	ls=AREA_D->list_areas();
	foreach(string l in ls) {
		tmp=AREA_D->get_area(l,"merchant");
		if(mapp(tmp))
			m_merchants[l]=tmp;
	}
	return;
}
void create() {
	string *ls;
	
	ls=AREA_D->check_area("run_market",1);
	if(!sizeof(ls))
		return;
	m_area=ls[0];
	if(sizeof(ls)>1) {
		foreach(string l in ls) {
			if(l!=m_area)
				AREA_D->set_area(l,"run_market",0);
                 }
	}
	start_time=AREA_D->get_area(m_area,"market_start_time");
	call_out("restore_merchant",1);
    call_out("market_choir",random(300)+60);

}
/* this will be useless, now bussiness will be started by area
void auto_business()
{
   string *lis;
   string p_area;
   string *neighbor;
   int sum;
   neighbor=AREA_D->get_area(m_area,"neighbor");
   if(sizeof(neighbor))
	   p_area=neighbor[random(sizeof(neighbor))];
   else
   {
	   lis=AREA_D->list_areas();
	   p_area=lis[random(sizeof(lis))];
   }
   m_area=p_area;
   business(p_area);
}
*/
mixed query_m_goods(string p_id,string p_name,string p_para)
{
   mapping goods;
   if(!m_goods) return 0;
   if((!p_id)||(p_id==""))return m_goods;
   if(p_id=="list") return keys(m_goods);
   goods=m_goods[p_id];
   if(!goods)
       return 0;
   switch(p_name)
   {
        case "":
           return goods;
        case "list":
           return keys(goods);
   }
   if(!goods[p_name]) return 0;
   switch(p_para)
   {
       case "":
         return goods[p_name];
       default:
         return goods[p_name][p_para];
   }
}

mixed decrease_count(string p_id,string p_name,int p_val)
{
   mapping goods;
   goods=m_goods[p_id];
   if(!goods) return 0;
   if(!goods[p_name]) return 0;
   if(!goods[p_name]["quantity"]) return 0;
   goods[p_name]["quantity"]-=p_val;
   if(goods[p_name]["quantity"]<=0)
	   map_delete(goods,p_name);
   m_goods[p_id]=goods;
   return 1;
} 

mapping query_npc_merchant_goods()
{
return ([
         "bo si": ([
             "zhong jia":([
                 "quantity" :100,
                 "price"    :1000,
                 "name"     :"重甲",
                     ])
                    ]),
         "xiong nu":([
             "horse":([
                 "quantity" :100,
                 "price"    :1000,
                 "name"     :"马",
                     ])
                    ]),
         "gao li":([  
             "hard bow":([
                 "quantity" :100,
                 "price"    :1000,
                 "name"     :"强弩",
                     ])
                    ]),
         "jiao zhi":([
             "teng jia":([
                 "quantity" :100,
                 "price"    :1000,
                 "name"     :"藤甲",
                     ])
                    ]),
       ]);
}

/*mapping query_goods()
{
return m_goods;
}
int remove_merchant_goods(string n_id,string goods_name)
{
if (!n_id||!goods_name) return 0;
if (member_array(n_id,keys(m_goods))==-1) return 0;
map_delete(m_goods[n_id],goods_name);
return 1;
}*/