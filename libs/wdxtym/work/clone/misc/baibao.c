// store.c
// by jjyy

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping baowus;

void create()
{
	set_name(HIW"储物袋"NOR, ({ "chuwu dai" }) );
	set("long",HIW"一个神奇的袋子，可以存取许多宝贝。"NOR"\n");
	set("unit", "个");
	set("no_lose", 1);
	set("no_save", 1);
	set("no_get", 1);
	set("no_put", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	seteuid(getuid());
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) || id != this_player()->query("id")) return 0;

	return sprintf(DATA_DIR"baibao/%c/%s", id[0], id);
}

int set_owner(string id)
{
	set("owner_id", id);
	return 1;
}

void init()
{
	if(!query("owner_id") || query("owner_id") != this_player()->query("id"))
	{
		set_owner(this_player()->query("id"));
	}

	if(this_player()->query("id")==query("owner_id"))
	{
		restore();
	}
}

varargs int do_store(string arg, int index)
{
	object me,ob;
	string *item_nb,nb;
	int i, snum;
	mapping info=([]);
	string type;

	me = this_player();
	if(!arg)
	{
		write("你要向袋子中存什么物品？\n");
		return 1;
	}

	if(!objectp(ob=present(arg,me)))
	{
		write("你身上没有这种物品吧？\n");
		return 1;
	}

//特殊物品不能保存
	if (ob->query("unique") || ! clonep(ob) )
	{
		tell_object(me, ob->name() + "不能储存在袋子里。\n");
		return 1;
	}

//装备中物品不能保存
	switch((string)ob->query("equipped")) 
	{
	case "worn":
		tell_object(me, ob->name() + "必须先脱下来才能存放。\n");
		return 1;
	case "wielded":
		tell_object(me, ob->name() + "必须先解除装备才能存放。\n");
		return 1;
	}

//内含物品的容器物品不能保存
	if (sizeof(all_inventory(ob))) 
	{
		tell_object(me, "请你先把" + ob->query("name") + "里面的东西先拿出来。\n");
		return 1;
	}

	if (ob->is_character()) 
	{
		tell_object(me, "你想把一个大活物硬塞到柜子里？\n");
		return 1;
	}

	if (ob->query("money_id"))
	{
		tell_object(me, "存钱的话还是到钱庄去吧！\n");
		return 1;
	}
	if (ob->query("no_cun"))
	{
		tell_object(me, "这属于特殊物品，袋子无法保存！\n");
		return 1;
	}
	if (ob->is_corpse()) 
	{
		tell_object(me, "这东西放里面会发臭的吧？\n");
		return 1;
	}
//这里可以加入更多不能保存物品的判断
//////尸体，活物，等等。。。

	if(!clonep(ob)
	||ob->query("unique")
	||ob->query("treasure")
	||ob->query("owner")
	||ob->query("no_put")
	||ob->query("u_times")
	||ob->query("quest")
	||ob->is_corpse()
	||ob->query("food_remaining")
	||ob->query("liquid")
	||ob->query("material")=="meat"
	||ob->query("money_id")
	||ob->is_character()
	||(stringp(ob->query("owner")) && ob->query("owner")!="0")
	||ob->query("credit")
	) {
		tell_object(me, "这个东西不能存入储物袋。\n");
		return 1;
	}
	snum = 20 + me->query("zjvip/all_pay")/10 + me->query("combat_exp")/50000;
	if (snum>100) snum=100;

	if (mapp(baowus)&&(sizeof(keys(baowus))>=snum)) {
		tell_object(me, "你的储物袋已经放不下更多物品了，赶紧整理一下吧。\n");
		return 1;
	}
	
	if (!index && ob->query_amount()) {
		write(INPUTTXT("请输入存放"+ob->name()+NOR"的数量：","mystore put "+file_name(ob)+" $txt# ")+"\n");
		return 1;
	}
	if (index && index > ob->query_amount()) {
		tell_object(me, "你身上没有这么数量。\n");
		return 1;
	}
	if (index && index < 1){
		tell_object(me, "你存入的数量不正确。\n");
		return 1;
	}
	
	if(ob->query("weapon_prop"))
		type="武器";
	else if(ob->query("armor_prop"))
		type="防具";
	else
		type="杂货";
	
	info["short"] = ob->query("name");
	
	if (index) {
		info["base_unit"] = ob->query("base_unit");
		info["amount"] = index;
	} 
	
	info["id"] = ob->parse_command_id_list();
	info["file"] = base_name(ob);
	info["type"] = type;
	info["data"] = save_variable(ob->query_entire_dbase());

	if( !mapp(baowus)) baowus = ([]);
	if( baowus == ([]))
	{
		baowus["1"] = info;
		if (index)
			ob->add_amount(-index);
		else
			destruct(ob);
		save();
	}
	else
	{
		item_nb = sort_array( keys(baowus), (: strcmp :) );
		for(i=1; i<(sizeof(item_nb)+2); i++) {
			nb = sprintf("%d",i);
			
			if (index && baowus[nb] && baowus[nb]["file"] == info["file"] && baowus[nb]["amount"] > 0) {
				baowus[nb]["amount"] += index;
				tell_object(me,"你把"+ob->query("name") + "，数量"+(index?index:1)+"，存进了袋子！\n");
				log_file("baibao/cun", sprintf("%-24s%-40s%s\n", 
							me->name() + "("+me->query("id")+")", 
								"存入"+filter_color(ob->name())+"("+ob->query("id")+")数量:"+(index?index:1), ctime(time())));
				if (index)
					ob->add_amount(-index);
				else
					destruct(ob);
				break;
			}
			else
			if(undefinedp(baowus[nb]))
			{
				baowus[nb] = info;
				tell_object(me,"你把"+ob->query("name") + "存进了袋子！\n");
				log_file("baibao/cun", sprintf("%-24s%-40s%s\n", 
							me->name() + "("+me->query("id")+")", 
								"存入"+filter_color(ob->name())+"("+ob->query("id")+")数量:"+(index?index:1), ctime(time())));
				if (index)
					ob->add_amount(-index);
				else
					destruct(ob);
				break;
			}
			/*
			baowus = ([]);
			*/
		}
		save();
	}
	me->save();
	if(!index && objectp(ob))
		tell_object(me,"物品存入失败！\n");
	else
		tell_object(me,"物品存入成功！\n");
	me->force_me("mystore put");
	return 1;
}
string long()
{
	object me = this_player();
	tell_object(me, ZJFORCECMD("mystore"));
	return "";
}

varargs int get_item(string arg, int index)
{
	object me,ob;
	string *item_nb;
	int i;

	me = this_player();

	if( !mapp(baowus) || baowus==([]))
	{
		write("你的袋子中没什么东西可取的。\n");
		return 1;
	}
	if(!arg)
	{
		write("你要从袋子中取出什么物品？\n");
		return 1;
	}

	if(undefinedp(baowus[arg]))
	{
		write("你的袋子中没没有这个编号的物品。\n");
		return 1;
	}

	if (!index && baowus[arg]["amount"] > 0) {
		write(INPUTTXT("请输入取出的数量：","mystore get "+arg+" $txt# ")+"\n");
		return 1;
	} 
		
	if (index && index < 1){
		tell_object(me, "你想取的数量不正确。\n");
		return 1;
	}
		
	if (index && baowus[arg]["amount"] < index)
	{
		tell_object(me, "你袋子里并没有存放这么多数量。\n");
		return 1;
	}
	
	ob = new(baowus[arg]["file"]);
	if (!ob)
	{
		tell_object(me, "你袋子里这件物品文件已经消失，请联系巫师。\n");
		return 1;
	}
	ob->set_dbase(restore_variable(baowus[arg]["data"]));
	ob->set_name(baowus[arg]["short"],baowus[arg]["id"]);
	if (index && baowus[arg]["amount"])
		ob->set_amount(index);
	tell_object(me,"你把"+ob->query("name")+"从袋子中取出！\n");

	if(ob->move(me))
	{
		if (index && baowus[arg]["amount"] > index)
		{
			baowus[arg]["amount"] -= index;
		} else
			map_delete(baowus, arg);
		me->save();
		save();
		tell_object(me,"物品取出成功！\n");
		log_file("baibao/qu", sprintf("%-24s%-40s%s\n", 
					me->name() + "("+me->query("id")+")", 
						"取出"+filter_color(ob->name())+"("+ob->query("id")+")数量:"+(index?index:1), ctime(time())));
	}
	else
		tell_object(me,"物品取出失败！\n");
	me->force_me("mystore");
	return 1;
}

int query_item(string arg)
{
	object me;
	string *item_nb;
	string *msg, ob_name, type, name;
	int ye, yeall, j, i;
	string str,line;

	me = this_player();

	if( !mapp(baowus) )
	{
		write("你目前没有存放任何物品在袋子里。\n");
		return 1;
	}

	item_nb = sort_array( keys(baowus), (: strcmp :) );

	if( sizeof(item_nb)<1 )
	{
		write("你目前没有存放任何物品在袋子里。\n");
		return 1;
	}
	msg = ({});
	if (!arg)
		arg = "全部 1";
	
	if( sscanf(arg, "%s %s %d", type, name, ye) != 3)
		if( sscanf(arg, "%s %d", type, ye) != 2) {
			write("你要查看什么？\n");
			return 1;
		}
		
	for (i = 0; i < sizeof(item_nb); i++) 
	{
		if (type == "全部" || type == baowus[item_nb[i]]["type"] 
			|| (type == "名称" && strsrch(baowus[item_nb[i]]["short"], name) != -1))
		{
			ob_name = baowus[item_nb[i]]["short"];
					
			if (baowus[item_nb[i]]["amount"] /*&& baowus[item_nb[i]]["base_unit"]*/)
				ob_name = baowus[item_nb[i]]["amount"] +"" + (baowus[item_nb[i]]["base_unit"] ? baowus[item_nb[i]]["base_unit"] : "件")+ ob_name;
			else
			if(baowus[item_nb[i]]["unit"])
				ob_name = baowus[item_nb[i]]["unit"] + ob_name;
			
			line = sprintf("%s:%s", ob_name,"mystore get "+item_nb[i]);
			msg += ({ line, });
		}
	}

	if(msg==({})) {
		write("没有你要找的物品！\n");
		return 1;
	}
	msg -=({0});
	str = ZJOBLONG+sprintf("袋子中【%s】的物品有(%d件)："+"\n", name ? name : type+"类型", sizeof(msg));
	str += ZJOBACTS2+ZJMENUF(2,2,9,30);

	yeall = sizeof(msg)/20;
	if(sizeof(msg)%20) yeall += 1;
	if(ye<1) ye = 1;
	if(ye>yeall) ye = yeall;
	j = (ye-1)*20;
	i = ye*20;
	if (i >= sizeof(msg)) i = sizeof(msg);
	i--;
	if(yeall>1)
		str += "上一页:mystore "+type+" "+(ye-1)+ZJSEP"下一页("+(ye)+"/"+(yeall)+"):mystore "+type+" "+(ye+1)+ZJSEP;
	str += implode(msg[j..i], ZJSEP);

	write(str+"\n");
	return 1;
}	
int query_autoload() { return 1; }
