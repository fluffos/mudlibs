#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

#define MAX_OBS    100
#define TAX	10

void create()
{
	mapping data;
	
	seteuid(ROOT_UID);
	restore();
	data = query_entire_dbase();
	if( !mapp(data) || undefinedp(data["data"]) ) 
	{
		set("data", ([]));
		save();
	}
	set_heart_beat(10);
}

void remove()
{
	save();
}

public void mud_shutdown()
{
	save();
}

public string query_save_file() { return DATA_DIR "saled"; }

public string do_stock(object me, string arg)
{
	object *inv,gold,ob, obj;
	int i,n, value,now;
	string short_name, file, *dk, *text, id, key, str, db,money,type;
	mapping data;
	
	id = me->query("name");		
	if( !arg )
	{
		inv = all_inventory(me);
		if (! sizeof(inv))
		{
			return (ZJOBLONG+HIY"目前你身上没有任何东西可寄售。"NOR);
		}
		dk = ({});
		for (i = 0; i < sizeof(inv); i++)
		{
			if (inv[i]->query("equipped")||inv[i]->query("no_drop")||inv[i]->query("no_give")||inv[i]->query("money_id")) continue;

			short_name = inv[i]->query("name");
			if(inv[i]->query_amount())
				short_name = inv[i]->query_amount() + inv[i]->query("base_unit") + short_name;

			dk += ({ short_name + ":jishou " + file_name(inv[i]) });
		}
		text = sort_array(dk, 1);

		str = ZJOBLONG"请选择您想寄售的物品：\n";
		str += ZJOBACTS2+ZJMENUF(2,2,10,32);
		if (! sizeof(text))
		{
			return (ZJOBLONG+HIY"目前你身上没可以寄售的东西。"NOR);
		}
		str += implode(text, ZJSEP);
		return str;
	}

	if(objectp(ob = present(arg,me)))
	{
		return ZJOBLONG"如果售出成功，市场将收取您一成手续费。"ZJBR"请您选择寄售"+ob->query("name")+"的类型:\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+"金币寄售:jishou "+arg+" value 金币"ZJSEP"灵石寄售:jishou "+arg+" value 灵石";
	}

	if( sscanf(arg, "%s value %s", file,money) == 2 )
	{
		if(!objectp(ob = present(file,me)))
			return "你身上并没有这个物品啊！";
		
		if( sscanf(money, "%s %d", money,value) != 2 )
		{
			if( money!="金币"&&money!="灵石" )
				return "只能标价为金币或灵石。";

			return INPUTTXT("你想把"+ob->query("name")+"以多少"+money+"寄售？","jishou "+arg+" $txt#");
		}
	}
	else
		return "参数错误，请正确操作！！！";

	if( !value || value < 0 )
		return "价格标注错误！！！";

	if( value < 2 )
		return "最少标价为2 ！！！";

	if( value > 9999 )
		return "最多标价9999。";

	if( !objectp(ob=present(file,me)))
		return "你身上并没有这个物品啊！";

	if( ob->query("no_sell")&&!ob->query("yuanbao"))
		return "这个东西太招摇了，还是别拿出来贩卖。";

	if( ob->query("no_give"))
		return "这个东西太招摇了，还是别拿出来贩卖。";

	if( ob->query("owner")&&ob->query("owner")!=0)
		return "绑定物品，无法贩卖。";

	if( ob->query("unique") )
		return "如此无价宝，还是别轻易拿出来贩卖吧。";

	if( strsrch(file, "#") == -1 )
		return "对不起，该物品不可以寄售！";

	if( ob->is_character() ) 
		return "你不能贩卖活物。";

	key = "data/" + id;
	if( sizeof(query(key)) >= MAX_OBS )
		return "对不起，你不能再寄售更多的东西了。";

	if( !MONEY_D->player_pay(me,10000) ) 
		return "寄售物品需要一两"HIY"黄金"NOR"托管费。";

	db = save_variable(ob->query_entire_dbase()); 

	if(ob->query("weapon_prop"))
		type="武器";
	else if(ob->query("armor_prop"))
		type="防具";
	else
		type="杂货";

	data = ([
		"file" : file,
		"name" : ob->query("name"),
		"id" : ob->parse_command_id_list(),
		"num" : ob->query_amount()?ob->query_amount():1,
		"seller" : me->query("id"),
		"type" : type,
		"value" : value,
		"money" : money,
		"dbase" : db,
	]);
	now = time();
	set(key + "-"+now, data);
	log_file("saled/jishou",sprintf("%s：%s(%s)以%d%s寄售%s",ctime(time()),me->query("name"),me->query("id"),value,money,ob->short()));
	destruct(ob);
	
	if( objectp(ob) ) {		
		delete(key + "-"+ now);
		me->save();
		save();
		log_file("saled/jishou","失败。\n");
		return "错误！寄售失败，请联系管理员。";
	} else {
		me->save();
		save();  
		log_file("saled/jishou","成功。\n");
		return data["name"] + "已经寄售好了！";
	}
}

public string do_unstock(object me, string arg)
{
	string kid,*ks,id;
	string file="";
	object ob;
	mapping data;
	int i,flag=0;

	id = me->query("name");

	if( !arg || arg == "" )
		return "指令格式：unstock <物品编号>";

	arg = lower_case(arg);

	if( !(data=query("data/"+arg)) )
		return "你要取回什么东西？?";
	
	ks = explode(arg,"-");

	if( ks[0]!=id )
		return "你要取回什么东西？?";

	if( data["seller"]!=me->query("id") )
		return "你要取回什么东西？?";

	file = data["file"];
	if(!objectp(ob=find_object(file)))
	{
		sscanf(file, "%s#%*s", file);
		ob = new(file);
		if( data["dbase"] ) {
			ob->set_name(data["name"],data["id"]);
			ob->set_dbase(restore_variable(data["dbase"]));
		}
	}
	if(objectp(ob))
	{
		delete("data/"+arg);
		log_file("saled/quhui",sprintf("%s：%s(%s)取回寄售中的%s。\n",ctime(time()),me->query("name"),me->query("id"),ob->short()));
		ob->move(me);				
		me->save();
		save();
		me->start_busy(1);			
		return "物品取回成功 。";
	}
	return "没有这样货物。";
}

public string do_cha(object me, string arg)
{
	string str,kid,*ks,id;
	string file="";
	object ob;
	mapping data;
	int i,flag=0;

	id = me->query("name");

	if( !arg || arg == "" )
		return "指令格式：chakan <物品编号>";

	arg = lower_case(arg);

	if( !(data=query("data/"+arg)) )
		return "你要查看什么东西?";
	
	file = data["file"];
	if(!objectp(ob=find_object(file)))
	{
		sscanf(file, "%s#%*s", file);
		ob = new(file);
		if( data["dbase"] ) {
			ob->set_name(data["name"],data["id"]);
			ob->set_dbase(restore_variable(data["dbase"]));
			set("data/"+arg+"/file",file_name(ob));
			save();
		}
	}
	if(objectp(ob))
	{
		"/cmds/std/look"->look_item(me,ob);
		if(data["seller"]==me->query("id"))
			str = ZJOBACTS"撤销:quhui "+arg;
		else
			str = ZJOBACTS"购买:jybuy "+arg;
		return str;
	}
	return "没有这样货物。";
}

void heart_beat()
{
	string file,owner,*user,name;
	mapping data,om;
	int stime, i;
	object sob,obj,ob;

	data = query("data");
	if( !mapp(data) ) 
		return;
	user = keys(data);

	for( i = 0; i < sizeof(user); i++ )
	{
		if( mapp(om = data[user[i]]))
		{
			sscanf(user[i],"%s-%d",owner,stime);
			if((time()-stime)>86400)
			{
				if(!(obj=find_player(om["seller"])))
				{
					continue;
				}
				else
				{
					file = om["file"];
					if(!objectp(ob=find_object(file)))
					{
						sscanf(file, "%s#%*s", file);
						ob = new(file);
						if( om["dbase"] ) {
							ob->set_name(om["name"],om["id"]);
							ob->set_dbase(restore_variable(om["dbase"]));
						}
					}
					log_file("saled/time_over",sprintf("%s：%s(%s)寄售的%s超时返还背包。\n",ctime(time()),obj->query("name"),obj->query("id"),ob->short()));
					ob->move(obj);
					obj->save();
					tell_object(obj,HIM"你在黑市寄售的"+ob->query("name")+"超过24小时无人购买，已返回背包。"NOR"\n");
					delete("data/"+user[i]);
					save();
				}
			}
		}
	}
}

public string do_list(object me, string arg)
{
	string *owner, *msg, *user,type,name;
	string file;
	mapping data, m, om;
	int i,j,ye,yeall;
	string str,id;

	data = query("data");
	if( !mapp(data) ) 
		return "目前并没有出售任何货物。";
		
	msg = ({});
	user = keys(data);

	if( sscanf(arg, "%s %s %d",type,name,ye)!=3)
		if( sscanf(arg, "%s %d",type, ye)!=2)
			return "你要查看什么？";

	for( i = 0; i < sizeof(user); i++ ) {
		if( mapp(om = data[user[i]])) {
			owner = explode(user[i],"-");
			if((time()-atoi(owner[1]))>86400) continue;
			if(type=="全部"||type==om["type"]||(type=="名称"&&strsrch(om["name"], name) != -1)||(type=="mine"&&owner[0]==me->query("name")))
					msg+=({sprintf(" %s[%d]"+ZJBR+WHT" 价格：%d%s"NOR":jychakan %s",om["name"],om["num"],om["value"],om["money"],user[i])});
		}
	}

	if(msg==({}))
		return "没有你要找的货物！";

	str = ZJOBLONG+sprintf("黑市中的【%s类型】的物品有(%d件)：\n",type,sizeof(msg));

	str += ZJOBACTS2+ZJMENUF(2,2,8,30);

	yeall = sizeof(msg)/10;
	if(sizeof(msg)%10) yeall += 1;
	if(ye<1) ye = 1;
	if(ye>yeall) ye = yeall;
	j = (ye-1)*10;
	i = ye*10;
	if (i >= sizeof(msg)) i = sizeof(msg);
	i--;
	if(yeall>1)
		str += "上一页:jylist "+type+" "+(ye-1)+ZJSEP"下一页:jylist "+type+" "+(ye+1)+ZJSEP;
	str += implode(msg[j..i], ZJSEP);

	return str+"\n";
}       

public string do_buy(object me, string arg)
{
	string username,pay_type,*ks, id;
	string file;
	object sob,ob,obj,owner;
	mapping data;
	int value, money, fees;
	int i;
		
	if( me->is_busy() )
		return "你正忙着呢！";

	if( !arg )
		return "你要买什么东西？";
	arg = lower_case(arg);

	if( !(data=query("data/"+arg)) )
		return "你要买什么东西？";
	
	ks = explode(arg,"-");

	pay_type = data["money"];
	value = data["value"];
	fees = value - value * TAX / 100;
	if(fees<1) fees = 1;
	if(pay_type=="灵石")
	{
		money = me->query("yuanbao");
		if( money < value )
			return "你没那么多灵石！";
	}
	else if(pay_type=="金币")
	{
		if( !MONEY_D->player_pay(me,value*10000) )
			return "你没那么多现金和和银票！";
	}
	
	file = data["file"];
	if(!objectp(ob=find_object(file)))
	{
		sscanf(file, "%s#%*s", file);
		ob = new(file);
		if( data["dbase"] ) {
			ob->set_name(data["name"],data["id"]);
			ob->set_dbase(restore_variable(data["dbase"]));
		}
	}
	if(objectp(ob))
	{
		if(pay_type=="灵石")
			me->add("yuanbao",-value);
		ob->move(me,1);				
		delete("data/"+arg);
		save();
		me->start_busy(1);

		if(!(obj=find_player(data["seller"])))
		{
			sob = new(LOGIN_OB);
			sob->set("id",data["seller"]);
			sob->set("body", USER_OB);
			obj = LOGIN_D->make_body(sob);
			destruct(sob);
			if(obj->restore())
			{
				obj->setup();
				if(pay_type=="灵石")
					obj->add("yuanbao",value*(100-TAX)/100);
				else
					obj->add("balance",value*100*(100-TAX));
				obj->save();
				log_file("saled/buy",sprintf("%s：%s(%s)以%d%s购买%s(%s)的%s。\n",ctime(time()),me->query("name"),me->query("id"),value,pay_type,obj->query("name"),obj->query("id"),ob->short()));
				destruct(obj);
			}
		}
		else
		{
			if(pay_type=="灵石")
				obj->add("yuanbao",value*(100-TAX)/100);
			else
				obj->add("balance",value*100*(100-TAX));
			obj->save();
			log_file("saled/buy",sprintf("%s：%s(%s)以%d%s购买%s(%s)的%s。\n",ctime(time()),me->query("name"),me->query("id"),value,pay_type,obj->query("name"),obj->query("id"),ob->short()));
			tell_object(obj,HIM"你在黑市寄售的"+ob->query("name")+"已成功售出，收入"+(value*(100-TAX)/100)+pay_type+"。"NOR"\n");
		}
		me->save();
		return "购买成功 。";
	}
	return "没有这样货物。";
}

