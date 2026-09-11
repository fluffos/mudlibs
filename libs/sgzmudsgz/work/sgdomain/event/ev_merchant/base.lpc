// base.c  by fire on Nov 1998
// modified by suicide on 2000.3.6
// this is used for ev_mechant.c to inherit
// hold all the base informtion of the good

mixed query_goods(string p_name,string p_para)
{
	//write("在/event/中的base.c中query_goods函数里p_name = " + p_name + ", p_para = " + p_para + "\n");
	return BASE_D->get_stuff(p_name,p_para);
}
mixed init_good()
{
   string* lis;
   mapping ret=([]);
   int i,sum,item,j;
   lis=COUNTRY_D->list_countries();
   //sum=bmin(sizeof(lis),7);
   for(i=0;i<sizeof(lis);++i)
   {
      mapping goods;
      mapping m_tmp=([]);
      goods = COUNTRY_D->get_country(lis[i],"st");
      if (!mapp(goods)||!goods) continue;
      foreach(string s in keys(goods))
      {  
         m_tmp[s]=([]);
         m_tmp[s]["name"]=BASE_D->get_stuff(s,"name");
         if ((!goods[s]["price"])||(!intp(goods[s]["price"])))
	    m_tmp[s]["price"]=goods[s]["cost"]*2;
	 else
	    m_tmp[s]["price"]=goods[s]["price"];
	    
	 m_tmp[s]["quantity"]=goods[s]["num"];
      }
      ret[lis[i]]=m_tmp;
   }
   return ret;
}
