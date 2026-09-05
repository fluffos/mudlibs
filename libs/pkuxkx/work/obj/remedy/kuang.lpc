inherit ITEM;
#include <ansi.h>
inherit F_SAVE;
#define CellStart 0
#define CellEnd 50
string query_save_file()
{
	return "/data/business/DrugCrudeStore_Herb";
}
void create()
{
	set_name("药篓"NOR, ({"yao lou","lou","basket"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一只竹筐，采药人可以用来放置(putin)一些采集的药材。\n");
            set("unit", "只");
            set("value", 0);
			set("no_store",1);
			set("no_sell",1);
			set("no_pawn",1);
			set("no_sell_in_playershop",1);
    }
	setup();
	restore();
}
void init()
{
	if (!this_player()->query("ProfessionalClass/herbalism")) return;
	add_action("do_putin","putin");
	add_action("do_pick","takeout");
	add_action("do_check","checkdrug");
}
int AmountLimit(object me)
{
	int lv=me->query("Myherb/Container"),*amount=({5,20,40,80,120,160,220,300,400});
	if (lv>8) lv=8;
	return amount[lv];
}
//(["id":1,"code":1,"name":"药","amount":99])
int do_check()
{
	object me=this_player();
	mapping *stores=({});
	string msg="你的"+query("name")+"里存放的药材有(每格可存放"+AmountLimit(me)+"件)：\n",line="_________________________________________________________________________________________________________________________\n";
	if (!arrayp(query(me->query("id"))))
	{
		for (int i=0;i<CellEnd;i++)
		stores+=({(["id":i+1,"code":"","name":"","amount":0])});
	}
	else
	stores=query(me->query("id"));
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
		tell_object(me,"你要取出"+arg+"？你可以输入takeout <药格编号>或者<药材名称>。\n");
		return 1;
	}
	if (!arrayp(stores=query(me->query("id")))||sizeof(stores)<1)
	{
		tell_object(me,"你没有存放任何药材。\n");
		return 1;
	}
	restore();
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
		obj="/obj/remedy/reference"->ObtainDrug(stores[Pick_No-1]["code"]);
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
	tell_object(me,"你的"+query("name")+"里没有这样东西了。\n");
	return 1;
}
int do_putin(string arg)
{
	object me=this_player(),ob=this_object(),obj;
	string drugcode;
	mapping* stores=({});
	int Null_No=-1,Same_No=-1;
	if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!arg)
		return notify_fail("你要把什么放进"+ob->query("name")+"。\n");
	if (!obj=present(arg,me))
		return notify_fail("你身上并无"+arg+"这样东西。\n");
	if (!obj->query("drugcode"))
		return notify_fail("药篓！当然只能装药。\n");
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
		if (stores[i]["code"]==drugcode&&stores[i]["amount"]<AmountLimit(me)&&Same_No==-1)
		Same_No=i;
		if (stores[i]["amount"]>AmountLimit(me))
		stores[i]["amount"]=AmountLimit(me);
	}
	if (Same_No>=0&&strwidth(stores[Same_No]["name"])>1)
	stores[Same_No]["amount"]+=1;
	else if (Null_No>=0)
	{
		stores[Null_No]["id"]=Null_No+1;
		stores[Null_No]["code"]=drugcode;
		stores[Null_No]["name"]=COLOR_D->uncolor(obj->query("name"));
		stores[Null_No]["amount"]=1;
	}
	else
	{	
		set(me->query("id"),stores);
		save();
		tell_object(me,"你的"+query("name")+"已经彻底装满了，清一清吧。\n");
		return 1;
	}
	message_vision(HIG+"$N"+HIG+"将一份$n"+HIG+"小心翼翼地放进"+query("name")+HIG+"。\n"+NOR,me,obj);
	set(me->query("id"),stores);
	save();
	destruct(obj);
	return 1;
}