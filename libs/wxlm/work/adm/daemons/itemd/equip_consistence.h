// 降低耐久度
void reduce_consistence(object item)
{
	int st;
	int con;
	object me;

	st = item->query("stable");
	if (st < 2) return;

	con = item->query("consistence");

	if (random(st) > (100 - con) / 12)
		return;

	//如果耐久度低于10,自动修理装备
	if (con < 10 && me = environment(item))
	{
		item->set("consistence", 100);
		tell_object(me,"你作为了【黎明会员】，已为您自动修理装备。\n");
	}

	
	if (item->add("consistence", -1) > 0)
		return;

	item->set("consistence", 0);
	if (environment(item))
		tell_object(environment(item), HIG "你的" + item->name() + "已经彻底损坏了。\n");
	item->unequip();
}

// 构造物品缺省的耐久度信息
void equip_setup(object item)
{
	int stable;
	mapping dbase;
	int i,k;
	string *attr_list = ({
		"damage",
		"unarmed_damage",
		"skills",
		"armor",
        "attack",
        "parry",
        "dodge",
        "strength",
        "intelligence",
        "constitution",
        "dexerity",
        "karma",
        "personality",
        "speed",
        "maxqi",
        "maxnei",
        "force",
        "max_qi",
        "max_neili",
        "max_jing",
	});

	for(i=0;i<sizeof(attr_list);i++)
	{
		if(k=item->query("armor_prop/"+attr_list[i]))
			item->set("armor_prop/"+attr_list[i], k);
		if(k=item->query("weapon_prop/"+attr_list[i]))
			item->set("weapon_prop/"+attr_list[i], k);
	}

	dbase = item->query_entire_dbase();
	if (undefinedp(dbase["consistence"]))
		dbase["consistence"] = 100;

	if (undefinedp(item->query("stable")))
	{
		switch (item->query("material"))
		{
		case "cloth":
			// 永远不会损坏
			stable = 0;
			break;

		case "paper":
			stable = 3;
			item->set("no_repair", "这东西我可没法修理。\n");
			break;

		case "bone":
			stable = 8;
			item->set("no_repear", "修理这个？可别拿我寻开心。\n");
			break;

		case "bamboo":
		case "wood":
			stable = 10;
			item->set("no_repair", "这东西我咋修理？\n");
			break;

		case "stone":
			stable = 20;
			item->set("no_repair", "这个坏了就坏了，可修不了。\n");
			break;

		case "copper":
			stable = 40;
			break;

		case "silver":
			stable = 40;
			break;

		case "iron":
			stable = 45;
			break;

		case "gold":
			stable = 50;
			break;

		case "steel":
			stable = 75;
			break;

		default:
			stable = 100;
			break;
		}

		if (! item->is_item_make())
			stable /= 2;

		item->set("stable", stable);
	}
}