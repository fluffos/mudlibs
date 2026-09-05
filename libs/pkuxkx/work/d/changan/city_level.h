
//通行令牌，皇城令相当于1级爵位通行权利，皇宫令相当于3级爵位通行权利
  mapping ling=
  (["huangcheng ling":1,
  	"huanggong ling":3]);

int get_usrlvl(object ob);
//检核长安城不同级别区域之间可通行性
//0表示拒绝通行，1表示可通行
//长安城爵位分为10级，爵位字段保存在query("changan/level")
//0～9，其中0为无爵位，0～3的时候对于通行有严格要求，4～9级对通行没有任何要求
//1级爵位（开国县男）可以进入皇城，2级爵位开国县子可以进入西内和南内，
//3级爵位（开国县伯）可以进入大明宫
//4级及以上爵位可以进入城防城墙
int check_obj_enter(object ob, string dir)
{
  object op, me=this_object(),*inv;
  string opfile;
  int level, loclvl, usrlvl, lp;
//当该方向不存在对象的时候不检查通行性
  if ( dir=="local" )
  	opfile=base_name(me);
  else 
  {  
    opfile=me->query("exits/"+dir);
    if ( !stringp(opfile) )
  	  return 1;
  }
//当送入的物品不存在的时候不检查通行性  
  if ( !objectp(ob) )
  	return 1;
  
  if ( dir == "local" )
  	op=me;
  else if ( !objectp(op=find_object(opfile)) )
  {
  	if ( !objectp(op=load_object(opfile)) )
  		return 1;
  }
//长袖善舞特技可以通行无阻  
  if ( ob->query("special_skill/sociability") )
  	return 1;
//长安城爵位大于等于4（开国县侯）的时候可以通行无阻
  usrlvl=get_usrlvl(ob);
  if ( usrlvl> 4 )
  	return 1;
  level=op->query("locate_level");
  loclvl=me->query("locate_level");
  if ( wizardp(ob) )
    tell_object(ob,sprintf("user:%d , target:%d, local:%d\n", usrlvl, level, loclvl));
//如果本地区域级别高于或者等于将要通行的区域级别，则无条件放行
  if ( dir!="local" && loclvl>=level )
  	return 1;
//玩家爵位大于区域级别则无条件放行  
  if ( usrlvl>=level )
    return 1;
  
//当玩家爵位小于区域级别的时候，如果该房间存在长安城官兵的时候，不让通行  
  inv=all_inventory(me);  
  for(lp=0;lp<sizeof(inv);lp++)
  {
  	if ( !userp(inv[lp]) &&
  		   living(inv[lp]) &&
  		   inv[lp]->query("changan_bing") )
  	  return 0;
  }
  return 1;
}

//检查物品在本房间的合法性，相当于调用方向为local的检查通行性函数
int check_obj(object ob)
{
	return check_obj_enter(ob,"local");
}

//获取玩家通行权利对应的爵位等级，获取身上通行令牌和自身爵位等级的最大值
int get_usrlvl(object ob)
{
	int linglevel;
	string s_ling;
	
	foreach( s_ling in keys(ling) )
	{
		if ( present(s_ling, ob) && 
			   linglevel<ling[s_ling] )
		{
			linglevel=ling[s_ling];
		}
	}
	
	if ( linglevel<ob->query("changan/level") )
		return ob->query("changan/level");
	else
		return linglevel;
}