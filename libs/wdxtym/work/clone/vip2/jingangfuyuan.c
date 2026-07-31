// jingangfuyuan.c

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIW"金钢复原石"NOR, ({"jingangfuyuan shi", "shi"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "可以清除已经鉴定过的装备属性，慎用！\n");
		set("base_unit", "颗");
		set("base_value", 10000);
		set("no_lose",1);
		set("yuanbao", 500);
		set("base_weight", 1);
	}
	set("action_list", ([
		"使用" : "updurable2",
	]));
	set_amount(1);
	setup();
}

void init()
{
    if ( environment() == this_player() )
		add_action("do_updurable", "updurable2");
}

int do_updurable(string arg)
{
	object me, ob, obj;
	
	object *inv; 
	string str, type, yns, obname;
	mapping list;
	string *list_sx,qb;
	int i;
	
	me = this_player();
	ob = this_object();

	if ( environment(ob) != me )
		return 0;

	if (!arg || sscanf(arg, "%s %s", type, obname) != 2)
	{
		inv = all_inventory(me);
		if (sizeof(inv) > 0) {
			str = "";
			for(i = 0; i < sizeof(inv); i++)
			{
				if (inv[i]->query("id") == "mengmian yi")
					continue;
				if ( inv[i]->query("jianding")) 
				{
					str += sprintf("%s", 
								inv[i]->query("name") + ":updurable2 " + file_name(this_object()) 
																	+ " " + file_name(inv[i]) ) + ZJSEP;
				}
			}
			 if (str!="")
				tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
			 else
				tell_object(me, ZJOBLONG+"找不到已经鉴定的装备。\n");
		}
		return 1;
	} else if (sscanf(arg, "%s %s %s", type, obname, yns) != 3){		
		if (!objectp(obj = present(obname, me)))
			return notify_fail("你身上没有这件装备。\n");	
		
		if (obj->query("id") == "mengmian yi")
			return notify_fail("不能为这件装备去掉鉴定属性。\n");	
		
		if (!present(type, me))
			return notify_fail("你身上没有这样东西。\n");	
		
		if ( !obj->query("jianding") ) //只能是鉴定过的装备
			return notify_fail("这件装备上没有鉴定的属性。\n");	
		
		if (!yns) {
			str = sprintf("%s", "确定清除:updurable2 " + type + " " + obname + " yes" + ZJSEP);
			str += sprintf("%s", "取消操作:updurable2 " + type + " " + obname + " no");
			tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
			return 1;
		}
	} else {		
		if (yns == "no")
		{
			tell_object(me, "你取消了操作。\n");
			return 1;
		}	
		if (!objectp(obj = present(obname, me)))
			return notify_fail("你身上没有这件装备。\n");	
		
		if (obj->query("id") == "mengmian yi")
			return notify_fail("不能为这件装备去掉鉴定属性。\n");	
		
		if (!present(type, me))
			return notify_fail("你身上没有这样东西。\n");	
		
		if ( !list=obj->query("jianding") ) //只能是鉴定过的装备
			return notify_fail("这件装备上没有鉴定的属性。\n");	
			
		if (sizeof(list)>0)
		{
			obj->unequip();
			
			if (obj->query("weapon_prop")) {
				qb = "weapon_prop";
			} else {
				qb = "armor_prop";
			}
			list_sx = keys(list);
			str ="";
			for(i=0;i<sizeof(list_sx);i++)
			{
				if (obj->query(qb+"/"+list_sx[i])) {
					obj->add(qb+"/"+list_sx[i], -list[list_sx[i]]);
					str +=qb+"/"+list_sx[i]+","+list[list_sx[i]] +"  ";
				}
			}
			obj->delete("jianding");
			obj->set("ok_jianding", 1);
			
			tell_object(me, sprintf("恭喜你为%s去掉了所有鉴定属性。\n", obj->name()));
			
			log_file( "cut_jianding", sprintf("%s -->%s 去掉鉴定属性成功。(%s)%s\n",
											me->name() + "(" + geteuid(me) + ")", obj->name(), str, ctime(time())) );
			
			ob->add_amount(-1);
		}
		return 1;
	} 
}