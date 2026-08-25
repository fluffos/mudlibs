mixed get_base(string b_id,string wat);
string stat_me(string p_id)
{
	string p_ret="";
   	mixed c;
   	mixed * ks;
   	int i;

   	if( (!p_id)||(p_id=="") ) p_id="list";
   	if(p_id=="list") {
    	p_ret= "生产基地清单：\n";
      	p_ret+="─────────────────────────────────────\n";
      	c=get_base("list","");
      	ks=({});
      	for(i=0;i<sizeof(c);++i) ks+=({get_base(c[i],"name")+"("+c[i]+")"});
      	p_ret+=sprintf("%-#79s\n", implode(ks, "\n"));
   	} else {
		c=get_base(p_id,"");
       		if( !mapp(c) ){
          		p_ret="没有这种生产基地。\n";
       		} else {
          	p_ret="基地ID："+p_id+"   基地名称："+c["name"]+"\n";
			p_ret+="安定要求："+c["safe"]+"\n";
			p_ret+="人口要求："+c["pop"]+"\n";
			p_ret+="需金："+c["gold"]+"\n";
			p_ret+="生产房间名称："+c["roomname"]+"\n";
			p_ret+="工人名称："+c["workername"]+"\n";
			p_ret+="工头名称："+c["headname"]+"\n";
			p_ret+="生产系数：\n";
			p_ret+="工业："+c["si"]+" 农业："+c["sa"]+" 商业："+c["sb"]+"\n";
			p_ret+="力量："+c["ss"]+" 耐力："+c["sp"]+" 智慧："+c["sw"]+"\n";
			p_ret+="缺省产品："+BASE_D->get_stuff(c["defproduct"],"name")+"\n";
			if(sizeof(c["products"])) {
				p_ret+="升级产品列表：";
				foreach (string pn,int pl in c["products"]) {
					p_ret+=BASE_D->get_stuff(pn,"name")+"("+pl+") " ;
				}
				p_ret+="\n";
			}
			if(sizeof(c["area"])) {
				p_ret+="限定地区：\n";
				foreach(string a in c["area"]) {
					p_ret+=AREA_D->get_area(a,"name")+"  ";
				}
				p_ret+="\n";
			}
		}
   	}
	return p_ret;
}
string show_balance(int t) {
	string *list;
	string ret;
	list=BASE_D->get_stuff("list");
	list=filter_array(list,(: BASE_D->get_stuff($1, "type")==$(t) :));
	switch(t) {
	case 1:
		ret="基本原料物资类：------------------------------------------------------------\n";
		break;
	case 2:
		ret="半成品类：------------------------------------------------------------------\n";
		break;
	case 3:
		ret="兵种升级物资类：------------------------------------------------------------\n";
		break;
	case 4:
		ret="特殊物资类：----------------------------------------------------------------\n";
		break;
	case 0:
		ret="未分类物资：----------------------------------------------------------------\n";
		break;
	}
	if(sizeof(list)) {
		foreach(string l in list) {
			ret+=sprintf("%-25s %5d  %5d%s  %.2f\n",BASE_D->get_stuff(l,"name")+"("+l+") ",
				BASE_D->get_stuff(l,"work"),BASE_D->get_stuff(l,"quantity"),
				BASE_D->get_stuff(l,"unit"),BASE_D->get_stuff(l,"real_work")*1.0/BASE_D->get_stuff(l,"quantity"));
		}
		ret+="\n";

	}
	return ret;
}
string show_group_list(int t) {
	string *list;
	string ret;
	list=BASE_D->get_stuff("list");
	list=filter_array(list,(: BASE_D->get_stuff($1, "type")==$(t) :));
	switch(t) {
	case 1:
		ret="基本原料物资类：------------------------------------------------------------\n";
		break;
	case 2:
		ret="半成品类：------------------------------------------------------------------\n";
		break;
	case 3:
		ret="兵种升级物资类：------------------------------------------------------------\n";
		break;
	case 4:
		ret="特殊物资类：----------------------------------------------------------------\n";
		break;
	case 0:
		ret="未分类物资：----------------------------------------------------------------\n";
		break;
	}
	if(sizeof(list)) {
		int k=0;
		foreach(string l in list) {
			ret+=sprintf("%-25s",BASE_D->get_stuff(l,"name")+"("+l+") ");
			k++;
			if(k%3==0)
				ret+="\n";
		}
		ret+="\n";

	}
	return ret;
}
string show_stuff_list() {
	string ret;
	int i;
	ret="三国物资清单：\n";
	ret+=show_group_list(1);
	ret+=show_group_list(2);
	ret+=show_group_list(3);
	ret+=show_group_list(4);
	ret+=show_group_list(0);
	return ret;
}
string show_stuff(string stf) {
	string ret;
	mapping consume,bs;
	string *src;
	if(!BASE_D->stuff_exist(stf)) return "没有这种物资。\n";
	ret="ID: "+stf+"\n";
	ret+="名称："+BASE_D->get_stuff(stf,"name")+"\n";
	ret+="一个生产单位："+BASE_D->get_stuff(stf,"quantity")+
		BASE_D->get_stuff(stf,"unit")+"\n";
	ret+="直接生产力消耗："+BASE_D->get_stuff(stf,"work")+"\n";
	consume=BASE_D->get_stuff(stf,"consume");
	if(mapp(consume)&&sizeof(consume)) {
		ret+="需要原料：";
		foreach(string s,int v in consume)
			ret+=BASE_D->get_stuff(s,"name")+"("+v+") ";
		ret+="\n";
		ret+="总生产力消耗："+BASE_D->get_stuff(stf,"real_work")+"\n";
	}
	src=BASE_D->get_stuff(stf,"src");
	if(sizeof(src)) {
		ret+="是生产以下物资的原料：\n ";
		foreach(string s in src) {
			ret+=BASE_D->get_stuff(s,"name")+"("+s+") ";
		}
		ret+="\n";
	}
	bs=BASE_D->get_stuff(stf,"base");
	ret+="所需生产基地：\n";
	if(sizeof(bs)) {
		foreach(string b,int lv in bs)
			ret+=BASE_D->get_base(b,"name")+"("+b+") "+ "级别："+lv+"\n";
	}
	ret+="单位产品所需生产力："+sprintf("%.2f\n",
		BASE_D->get_stuff(stf,"real_work")*1.0/BASE_D->get_stuff(stf,"quantity"));
	ret+="备注："+BASE_D->get_stuff(stf,"comment");
	return ret;
}
