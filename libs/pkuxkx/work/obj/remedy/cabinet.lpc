inherit ITEM;
#include <ansi.h>
inherit F_SAVE;
#define CellStart 0
#define CellEnd 50
string query_save_file()
{
	return "/data/business/DrugCrudeStore";
}
void create()
{
	set_name("药柜", ({"yao gui", "gui", "cabinet"}));
	set("long","这是一架装药的柜子。\n");
	set("unit", "具");
	set("no_get", "药柜太重了，一个人根本拿不起来。\n");
	set("material", "wood");
	setup();
	restore();
}

void init()
{
	if (time()>=this_player()->query("RentCabinet/time"))
	{
		tell_object(this_player(),"你的租期到了，要再使用"+this_object()->query("name")+"，就要续租了。\n");
		return;
	}
	if (this_player()->is_busy())
	{
		tell_object(this_player(),"你正忙着呢。\n");
		return;
	}
	if (this_player()->query("RentCabinet/Cabinet")!=this_object())
	return;
	add_action("do_pick","pickdrug");
	add_action("do_store","storedrug");
	add_action("do_check","checkdrug");
}
int AmountLimit(object me)
{
	mapping amount=(["small":99,"medium":999,"large":2000]);
	if (amount[me->query("RentCabinet/size")]>0)
	return amount[me->query("RentCabinet/size")];
	return 10;
}
//(["id":1,"code":1,"name":"药","amount":99])
int do_check()
{
	object me=this_player();
	mapping *stores;
	string msg="你的药柜里存储的药材有：\n",line="_________________________________________________________________________________________________________________________\n";
	restore();
	if (!arrayp(stores=query(me->query("id")))||sizeof(stores)<1)
	{
		tell_object(me,"你没有存放任何药材。\n");
		return 1;
	}
	msg+=line;
	for (int i=0;i<CellEnd;i++)
	{
		if (stores[i]["amount"]>0)
		msg+=U+sprintf("%6s%2d%2s%-10s%2s%2d","|【NO.",(i+1),"】",stores[i]["name"],"：",stores[i]["amount"])+NOR;
		else
		msg+=U+sprintf("%6s%2d%2s%|14s","|【NO.",(i+1),"】","空")+NOR;
		if ((i+1)%5==0&&i!=0)
		msg+=U+"|\n"+NOR;
	}
	write(msg+"\n");
	return 1;
}
int do_pick(mixed arg)
{
	object obj,me=this_player();
	mapping *stores;
	int Pick_No;
	if (!arg)
	{
		tell_object(me,"你要取出什么？\n");
		return 1;
	}
	if (!intp(arg)&&!stringp(arg))
	{
		tell_object(me,"你要取出"+arg+"？你可以输入pickdrug <药格编号>或者<药材名称>。\n");
		return 1;
	}
	restore();
	if (!arrayp(stores=query(me->query("id")))||sizeof(stores)<1)
	{
		tell_object(me,"你没有存放任何药材。\n");
		return 1;
	}
	if (sscanf(arg,"%d",Pick_No)==1)
	{
		if (Pick_No<0||Pick_No>CellEnd)
		{
			tell_object(me,"没有"+Pick_No+"号药格。\n");
			return 1;
		}
		if (!stores[Pick_No-1]||stores[Pick_No-1]["amount"]<1)
		{
			tell_object(me,"你编号为"+Pick_No+"的药格里是空的。\n");
			return 1;
		}
		stores[Pick_No-1]["amount"]-=1;
		obj="/obj/remedy/reference"->ObtainDrug(stores[Pick_No-1]["name"]);
		message_vision("$N从"+this_object()->query("name")+"里取出了一份$n。\n",me,obj);
		obj->move(me);
		if (stores[Pick_No-1]["amount"]<1)
		{
			stores[Pick_No-1]["code"]="";
			stores[Pick_No-1]["name"]="";
		}
		set(me->query("id"),stores);
		save();
		return 1;
	}
	if (stringp(arg))
	{
		for (int i=0;i<sizeof(stores);i++)
		{
			if (stores[i]["name"]==arg&&stores[i]["amount"]>=1)
			{
				stores[i]["amount"]-=1;
				if (stores[i]["amount"]<1)
				{	
					stores[i]["code"]="";
					stores[i]["name"]="";
				}
				obj="/obj/remedy/reference"->ObtainDrug(arg);
				message_vision("$N从"+this_object()->query("name")+"里取出了一份$n。\n",me,obj);
				obj->move(me);
				set(me->query("id"),stores);
				save();
				return 1;
			}
		}
	}
	tell_object(me,"你的药柜里没有这样东西了。\n");
	return 1;
}
int do_store(string arg)
{
	object obj,me=this_player();
	string drugcode;
	mapping* stores=({});
	int Null_No=-1,Same_No=-1;
	if (!arg)
	{
		tell_object(me,"你要存什么？\n");
		return 1;
	}
	if (!obj=present(arg,me))
	{
		tell_object(me,"你身上没有"+arg+"呀。\n");
		return 1;
	}
	if (!obj->query("drugcode"))
	{
		tell_object(me,"药柜里只能存放药材。\n");
		return 1;
	}
	restore();
	drugcode=obj->query("drugcode");
	if (arrayp(query(me->query("id"))))
	stores=query(me->query("id"));
	else
	{
		for (int i=0;i<CellEnd;i++)
		stores+=({(["id":i+1,"code":"","name":"","amount":0])});
	}
	for (int i=0;i<sizeof(stores);i++)
	{
		if (stores[i]["amount"]<1&&Null_No==-1)
		Null_No=i;
		if (stores[i]["code"]==drugcode)
		Same_No=i;
		if (stores[i]["amount"]>AmountLimit(me))
		stores[i]["amount"]=AmountLimit(me);
	}
	if (Same_No>=0&&strwidth(stores[Same_No]["name"])>1&&stores[Same_No]["amount"]<AmountLimit(me))
	stores[Same_No]["amount"]+=1;
	else if (Null_No>=0)
	{
		stores[Null_No]["id"]=Null_No+1;
		stores[Null_No]["code"]=drugcode;
		stores[Null_No]["name"]=obj->query("name");
		stores[Null_No]["amount"]=1;
	}
	else
	{	
		set(me->query("id"),stores);
		save();
		tell_object(me,"你的药柜已经彻底装满了，清一清吧。\n");
		return 1;
	}
	message_vision(HIG+"$N"+HIG+"将一份$n"+HIG+"小心翼翼地放进"+query("name")+HIG+"。\n"+NOR,me,obj);
	set(me->query("id"),stores);
	save();
	destruct(obj);
	return 1;
}

