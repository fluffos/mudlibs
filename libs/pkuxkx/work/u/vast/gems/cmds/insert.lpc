// insert.c
// by Vast@pkuxkx
// all comments added by Vast

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_GEMS;

void generate_newweapon(object ob, string material, int lev);
void generate_newarmor(object ob, string material, int lev);
void generate_newring(object ob, string material, int lev);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int index;
        string gem_name, item_name;
        object gem, ob;

        if( !arg || arg == "") return notify_fail("指令格式：insert <宝石> into <物品> \n");
	if (sscanf(arg, "%s into %s", gem_name, item_name) != 2)
		return notify_fail("指令格式：insert <宝石> into <物品> \n");

        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

        if( !objectp(gem = present(gem_name, me)) )
                return notify_fail("你身上没有这颗宝石。\n");

        if( !objectp(ob = present(item_name, me)) )
                return notify_fail("你想把它镶嵌在什么东西上？\n");

	//此处还需要增加一些判断语句?
	if (!mapp(ob->query("sockets")))
		return notify_fail(ob->name() + "上没有可供镶嵌的凹槽！\n");
        if((index = ob->query("sockets/filled")) >= ob->query("sockets/max"))
                return notify_fail(ob->name() + "上的凹槽已经镶满宝石了！\n");
	if (ob->query("equipped"))
		return notify_fail(ob->name() + "正装备着呢！\n");
	if (me->query("max_neili") < 1000 || me->query("neili") < 1500)
		return notify_fail("以你现在的内力修为，还无法运功镶嵌宝石！\n");

	if (me->query("max_jingli") < 100 || me->query("jingli") < 100)
		return notify_fail("你现在精力不足，无法运功镶嵌宝石！\n");

	message_vision(HIG"$N小心翼翼地把" + gem->name() + HIG"镶入了" + ob->name() + HIG"中，力求精益求精。
刹那间，只觉" + ob->name() + HIG"上泛出一道奇异的光芒，似乎有一股神奇的力量附在其中！
$N长吁了一口气，擦了擦头上的汗水，仔细端详着自己的杰作，露出了得意地微笑。\n"NOR, me);
	me->add("max_jingli", - gem->query("level"));
	me->add("neili", - 1000);
	me->start_busy(2);

	//此处改变ob的公有属性
	//1.设置镶嵌信息
	ob->set(sprintf("sockets/socket%d", 1 + index), gem->query("material"));
	ob->set(sprintf("sockets/socket%d_level", 1 + index), gem->query("level"));
	ob->add("sockets/filled", 1);
	//2.改变物品重量
	ob->add("item/weight", gem->query_weight());
	//3.改变物品的价值
	ob->add("item/value", gem->query("value") / 2);

	//以下分不同类的物品，分别进行更新
	if(mapp(ob->query("weapon_prop")))
	generate_newweapon(ob, gem->query("material"), gem->query("level"));
	else if(ob->query("armor_type") != "finger")
	generate_newarmor(ob, gem->query("material"), gem->query("level"));
	else
	generate_newring(ob, gem->query("material"), gem->query("level"));

	destruct(gem);

	return 1;
}

void generate_newweapon(object ob, string material, int lev)
{
	string prefix;
	int level, i;
	if(stringp(ob->query("weapon/name")))
	prefix = ob->query("weapon/name");
	else prefix = " " + ob->query("name");

	if (valid_gem(material, lev))
	switch (material)
	{
		case "ruby":
		//1.前缀(未判断重名前缀的情况，可以加上)
		prefix = HIR + ruby_prefix[random(sizeof(ruby_prefix))] + NOR + prefix;
		//2.特效
		//a.改变wield,unwield描述，以最后一次镶嵌的宝石为标准
        	ob->set("wield_msg", HIR + ruby_wield_msg[random(sizeof(ruby_wield_msg))] + NOR);
        	ob->set("unwield_msg", HIR + ruby_unwield_msg[random(sizeof(ruby_unwield_msg))] + NOR);
        	//b.对应的特效
        	ob->add("weapon/strength", ruby_weapon_effect[lev - 1]);
		break;
		case "topaz":
		prefix = HIY + topaz_prefix[random(sizeof(topaz_prefix))] + NOR + prefix;
        	ob->set("wield_msg", HIY + topaz_wield_msg[random(sizeof(topaz_wield_msg))] + NOR);
        	ob->set("unwield_msg", HIY + topaz_unwield_msg[random(sizeof(topaz_unwield_msg))] + NOR);
        	ob->add("weapon/attack", topaz_weapon_effect[lev - 1]);
		break;
		case "sapphire":
		prefix = HIB + sapphire_prefix[random(sizeof(sapphire_prefix))] + NOR + prefix;
        	ob->set("wield_msg", HIC + sapphire_wield_msg[random(sizeof(sapphire_wield_msg))] + NOR);
        	ob->set("unwield_msg", HIC + sapphire_unwield_msg[random(sizeof(sapphire_unwield_msg))] + NOR);
        	ob->add("weapon_effect/jing", sapphire_weapon_effect[lev - 1]);
		break;
		case "emerald":
		prefix = HIG + emerald_prefix[random(sizeof(emerald_prefix))] + NOR + prefix;
        	ob->set("wield_msg", HIG + emerald_wield_msg[random(sizeof(emerald_wield_msg))] + NOR);
        	ob->set("unwield_msg", HIG + emerald_unwield_msg[random(sizeof(emerald_unwield_msg))] + NOR);
        	ob->add("weapon_effect/poison", emerald_weapon_effect[lev - 1]);
		break;
		case "amethyst":
		prefix = MAG + amethyst_prefix[random(sizeof(amethyst_prefix))] + NOR + prefix;
       		ob->set("wield_msg", HIM + amethyst_wield_msg[random(sizeof(amethyst_wield_msg))] + NOR);
       		ob->set("unwield_msg", HIM + amethyst_unwield_msg[random(sizeof(amethyst_unwield_msg))] + NOR);
       		break;
		case "diamond":
		prefix = HIW + diamond_prefix[random(sizeof(diamond_prefix))] + NOR + prefix;
       		ob->set("wield_msg", HIW + diamond_wield_msg[random(sizeof(diamond_wield_msg))] + NOR);
       		ob->set("unwield_msg", HIW + diamond_unwield_msg[random(sizeof(diamond_unwield_msg))] + NOR);
       		ob->add("rigidity", diamond_weapon_effect[lev - 1]);
       		ob->add("max_rigidity", diamond_weapon_effect[lev - 1]);
       		break;
		case "skull":
		prefix = WHT + skull_prefix[random(sizeof(skull_prefix))] + NOR + prefix;
        	ob->set("wield_msg", WHT + skull_wield_msg[random(sizeof(skull_wield_msg))] + NOR);
        	ob->set("unwield_msg", WHT + skull_unwield_msg[random(sizeof(skull_unwield_msg))] + NOR);
        	ob->add("weapon_effect/suck", skull_weapon_effect[lev - 1]);
		break;
		default:
		error("gems: undefined type " + material + ".\n");
	}

	//有一定几率在镶满三个宝石后增加一个前缀
	if(ob->query("sockets/filled") == 3 && random(2) == 0)
	{
		for(i = 1; i <= 3; i++)
		level += ob->query(sprintf("sockets/socket%d_level", i));
		level /= 4;
		prefix = all_colors[random(sizeof(all_colors))] + prefix_level[level][random(sizeof(prefix_level[level]))] + NOR + prefix;
	}
	ob->set("weapon/name", prefix);
	ob->init_sockets();
}
void generate_newring(object ob, string material, int lev)
{
	string prefix;
	int level, i;
	if(stringp(ob->query("ring/name")))
	prefix = ob->query("ring/name");
	else prefix = " " + ob->query("name");

	if (valid_gem(material, lev))
	switch (material)
	{
		case "ruby":
		//1.前缀(未判断重名前缀的情况，可以加上)
		prefix = HIR + ruby_prefix[random(sizeof(ruby_prefix))] + NOR + prefix;
		//2.特效
		//a.改变wield,unwield描述，以最后一次镶嵌的宝石为标准
        	//ob->set("wield_msg", HIR + ruby_wield_msg[random(sizeof(ruby_wield_msg))] + NOR);
        	//ob->set("unwield_msg", HIR + ruby_unwield_msg[random(sizeof(ruby_unwield_msg))] + NOR);
        	//b.对应的特效
        	ob->add("ring/strength", ruby_ring_effect[lev - 1]);
		break;
		case "topaz":
		prefix = HIY + topaz_prefix[random(sizeof(topaz_prefix))] + NOR + prefix;
        	//ob->set("wield_msg", HIY + topaz_wield_msg[random(sizeof(topaz_wield_msg))] + NOR);
        	//ob->set("unwield_msg", HIY + topaz_unwield_msg[random(sizeof(topaz_unwield_msg))] + NOR);
        	ob->add("ring/attack", topaz_ring_effect[lev - 1]);
		break;
		case "sapphire":
		prefix = HIB + sapphire_prefix[random(sizeof(sapphire_prefix))] + NOR + prefix;
        	//ob->set("wield_msg", HIC + sapphire_wield_msg[random(sizeof(sapphire_wield_msg))] + NOR);
        	//ob->set("unwield_msg", HIC + sapphire_unwield_msg[random(sizeof(sapphire_unwield_msg))] + NOR);
        	ob->add("ring/unarmed", sapphire_ring_effect[lev - 1]);
        	ob->add("ring/hand", sapphire_ring_effect[lev - 1]);
        	ob->add("ring/finger", sapphire_ring_effect[lev - 1]);
        	ob->add("ring/strike", sapphire_ring_effect[lev - 1]);
        	ob->add("ring/cuff", sapphire_ring_effect[lev - 1]);
        	ob->add("ring/claw", sapphire_ring_effect[lev - 1]);
		break;
		case "emerald":
		prefix = HIG + emerald_prefix[random(sizeof(emerald_prefix))] + NOR + prefix;
        	//ob->set("wield_msg", HIG + emerald_wield_msg[random(sizeof(emerald_wield_msg))] + NOR);
        	//ob->set("unwield_msg", HIG + emerald_unwield_msg[random(sizeof(emerald_unwield_msg))] + NOR);
        	ob->add("ring/dodge", emerald_ring_effect[lev - 1]);
		break;
		case "amethyst":
		prefix = MAG + amethyst_prefix[random(sizeof(amethyst_prefix))] + NOR + prefix;
       		//ob->set("wield_msg", HIM + amethyst_wield_msg[random(sizeof(amethyst_wield_msg))] + NOR);
       		//ob->set("unwield_msg", HIM + amethyst_unwield_msg[random(sizeof(amethyst_unwield_msg))] + NOR);
       		ob->add("ring/armor", amethyst_ring_effect[lev - 1]);
       		break;
		case "diamond":
		prefix = HIW + diamond_prefix[random(sizeof(diamond_prefix))] + NOR + prefix;
       		//ob->set("wield_msg", HIW + diamond_wield_msg[random(sizeof(diamond_wield_msg))] + NOR);
       		//ob->set("unwield_msg", HIW + diamond_unwield_msg[random(sizeof(diamond_unwield_msg))] + NOR);
       		ob->add("ring/parry", diamond_ring_effect[lev - 1]);
       		break;
		case "skull":
		prefix = WHT + skull_prefix[random(sizeof(skull_prefix))] + NOR + prefix;
        	//ob->set("wield_msg", WHT + skull_wield_msg[random(sizeof(skull_wield_msg))] + NOR);
        	//ob->set("unwield_msg", WHT + skull_unwield_msg[random(sizeof(skull_unwield_msg))] + NOR);
        	ob->add("ring/magic", skull_ring_effect[lev - 1]);
		break;
		default:
		error("gems: undefined type " + material + ".\n");
	}

	ob->set("ring/name", prefix);
	ob->setup_ring();
}
void generate_newarmor(object ob, string material, int lev)
{
	string prefix;
	int level, i;
	if(stringp(ob->query("armor/name")))
	prefix = ob->query("armor/name");
	else prefix = " " + ob->query("name");

	if (valid_gem(material, lev))
	switch (material)
	{
		case "ruby":
		//1.前缀(未判断重名前缀的情况，可以加上)
		prefix = HIR + ruby_prefix[random(sizeof(ruby_prefix))] + NOR + prefix;
		//2.特效
		//a.改变wear,unequip描述，以最后一次镶嵌的宝石为标准
        	//ob->set("wear_msg", HIR + ruby_wear_msg[random(sizeof(ruby_wear_msg))] + NOR);
        	//ob->set("unequip_msg", HIR + ruby_unequip_msg[random(sizeof(ruby_unequip_msg))] + NOR);
        	//b.对应的特效
        	ob->add("armor_effect/rebound", ruby_armor_effect[lev - 1]);
		break;
		case "topaz":
		prefix = HIY + topaz_prefix[random(sizeof(topaz_prefix))] + NOR + prefix;
        	//ob->set("wear_msg", HIY + topaz_wear_msg[random(sizeof(topaz_wear_msg))] + NOR);
        	//ob->set("unequip_msg", HIY + topaz_unequip_msg[random(sizeof(topaz_unequip_msg))] + NOR);
        	ob->add("armor/dodge", topaz_armor_effect[lev - 1]);
		break;
		case "sapphire":
		prefix = HIB + sapphire_prefix[random(sizeof(sapphire_prefix))] + NOR + prefix;
        	//ob->set("wear_msg", HIC + sapphire_wear_msg[random(sizeof(sapphire_wear_msg))] + NOR);
        	//ob->set("unequip_msg", HIC + sapphire_unequip_msg[random(sizeof(sapphire_unequip_msg))] + NOR);
        	ob->add("armor/magic", sapphire_armor_effect[lev - 1]);
		break;
		case "emerald":
		prefix = HIG + emerald_prefix[random(sizeof(emerald_prefix))] + NOR + prefix;
        	//ob->set("wear_msg", HIG + emerald_wear_msg[random(sizeof(emerald_wear_msg))] + NOR);
        	//ob->set("unequip_msg", HIG + emerald_unequip_msg[random(sizeof(emerald_unequip_msg))] + NOR);
        	ob->add("armor_effect/poison", emerald_armor_effect[lev - 1]);
		break;
		case "amethyst":
		prefix = MAG + amethyst_prefix[random(sizeof(amethyst_prefix))] + NOR + prefix;
       		//ob->set("wear_msg", HIM + amethyst_wear_msg[random(sizeof(amethyst_wear_msg))] + NOR);
       		//ob->set("unequip_msg", HIM + amethyst_unequip_msg[random(sizeof(amethyst_unequip_msg))] + NOR);
       		break;
		case "diamond":
		prefix = HIW + diamond_prefix[random(sizeof(diamond_prefix))] + NOR + prefix;
       		//ob->set("wear_msg", HIW + diamond_wear_msg[random(sizeof(diamond_wear_msg))] + NOR);
       		//ob->set("unequip_msg", HIW + diamond_unequip_msg[random(sizeof(diamond_unequip_msg))] + NOR);
       		ob->add("armor/armor_vs_force", diamond_armor_effect[lev - 1]);
       		ob->add("armor/armor_vs_weapon", diamond_armor_effect[lev - 1] * 2);
       		break;
		case "skull":
		prefix = WHT + skull_prefix[random(sizeof(skull_prefix))] + NOR + prefix;
        	//ob->set("wear_msg", WHT + skull_wear_msg[random(sizeof(skull_wear_msg))] + NOR);
        	//ob->set("unequip_msg", WHT + skull_unequip_msg[random(sizeof(skull_unequip_msg))] + NOR);
        	ob->add("armor/healup", skull_armor_effect[lev - 1]);
		break;
		default:
		error("gems: undefined type " + material + ".\n");
	}

	ob->set("armor/name", prefix);
	ob->setup_armor();
}
int help(object me)
{
        write(@HELP
指令格式：insert <宝石> into <物品>

这个指令可以让你将宝石镶嵌入某个物品。
镶嵌宝石要消耗玩家的大量内力，并且会降低最大精力。

HELP
    );
    return 1;
}
