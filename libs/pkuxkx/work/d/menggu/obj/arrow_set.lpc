
inherit ITEM;
void create()
{
    set_name("箭", ({ "jian","arrow" }));
	set_weight(25000);
	set("unit", "扎");
	set("long", "这是一扎箭。\n");
	set("arrow_set",1);
	setup();
}

int dest(object me)
{
	int i,count=0;
	object *obs=all_inventory(me);
	for (i=0;i<sizeof(obs);i++)
	{
		if (obs[i]->query("arrow_serial")==this_object()->query("prearrow_serial"))
		{
			destruct(obs[i]);
			count+=1;
		}
		if (count>=5)
		{
			return 1;
		}
	}
	return 1;
}

int copy(object ob)
{
	set("preid",ob->parse_command_id_list());
	set("long","这是一扎"+ob->query("name")+"。\n");
	set("prename",ob->query("name"));
	set("preunit", ob->query("unit"));
	set("prelong", ob->query("long"));
	set("prevalue", ob->query("value"));
	set("value",ob->query("value")*5);
	set("prearrow_serial",ob->query("arrow_serial"));
	set("prematerial", ob->query("material"));
	set("prearrow_assist",ob->query("arrow_assist"));
	return 1;
}

void init()
{
	add_action("do_chai","chai");
}

int do_chai()
{
	int i;
	object ob=this_object(),arrow,me=this_player();
	string ids=ob->query("preid");
	for (i=0;i<5;i++)
	{
		arrow=new(__DIR__"standard_arrow");
		arrow->set_name(ob->query("prename"),ids);
		arrow->set("unit",ob->query("preunit"));
		arrow->set("long", ob->query("prelong"));
		arrow->set("value", ob->query("prevalue"));
		arrow->set("arrow_serial",ob->query("prearrow_serial"));
		arrow->set("material", ob->query("prematerial"));
		arrow->set("arrow_assist",ob->query("prearrow_assist"));
		arrow->move(me);
	}
	message_vision("$N拆开一捆$n。\n",me,ob);
	destruct(ob);
	return 1;
}