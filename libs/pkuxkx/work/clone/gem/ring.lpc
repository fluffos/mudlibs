// by Vast@pkuxkx
// all comments added by Vast
//edit by kiden@pkuxkx 2006-10-30

#include <ansi.h>
#include <armor.h>

inherit F_GEMS;
inherit EQUIP;

void setup_ring();
void create()
{
	int i, type;
	if(!random(3))
	set("sockets/max", 1);//指环最多镶嵌一个宝石
	set("unit", "只");

	set("no_store",1);
        set("no_sell",1);
        set("no_pawn",1);

	set("armor_type", "finger");//以后考虑生成项链（neck）类

	//此处还可做相应调整
	i = random(50);
	if (i < 1) type = 8;		   
	else if (i < 3) type = 7;	 
	else if (i < 6) type = 6;	 
	else if (i < 10) type = 5;	
	else if (i < 15) type = 4;	
	else if (i < 21) type = 3;	
	else if (i < 28) type = 2;	
  else if (i < 36) type = 1;	
	else type = 0;	

	
      	switch (type) {
      default:
			set_name(WHT"铁指环"NOR, ({"tie zhihuan", "zhihuan", "ring"}));
			set("ring/long", "一个普普通通的铁指环，不知道有什么用。\n"NOR);
			set("base_weight", 50 + random(200));
			set("material", "iron");
			set("ring/armor", 5);
			set("value", 5000);

			break;
       	case 1:
			set_name(HIR"铜指环"NOR, ({"tong zhihuan", "zhihuan", "ring"}));
			set("ring/long", "一个青铜铸造的指环，看上去并不起眼。\n");
			set("base_weight", 150 + random(250));
			set("material", "copper");
			set("ring/armor", 10);
			set("value", 10000);

			break;
       	case 2:
			set_name(HIW"银指环"NOR, ({"yin zhihuan", "zhihuan", "ring"}));
			set("ring/long", "白银制成的指环，做工用料都十足。\n");
			set("base_weight", 200 + random(200));
			set("material", "silver");
			set("ring/armor", 20);
			set("value", 18000);

			break;
        case 3:
			set_name(HIY"金指环"NOR, ({"jin zhihuan", "zhihuan", "ring"}));
			set("ring/long", "用纯金打造的华丽指环，不是一般人能够享受的。\n");
			set("base_weight", 200 + random(300));
			set("material", "gold");
			set("ring/armor", 50);
			set("value", 50000);

			break;
			  case 4:
			set_name(HIW"白玉扳指"NOR, ({"baiyu banzhi", "baizhi", "ring"}));
			set("ring/long", "以白玉精雕而成的扳指。\n");
			set("base_weight", 200 + random(300));
			set("material", "gold");
			set("ring/armor", 70);
			set("value", 60000);

			break;
			       	case 5:
			set_name(HIG"碧玉扳指"NOR, ({"biyu banzhi", "banzhi", "ring"}));
			set("ring/long", "以碧玉精雕而成的扳指。\n");
			set("base_weight", 200 + random(300));
			set("material", "gold");
			set("ring/armor", 80);
			set("value", 80000);

			break;
			       	case 6:
			set_name(HIR"翡翠扳指"NOR, ({"feicui banzhi", "banzhi", "ring"}));
			set("ring/long", "用纯金打造的华丽指环，不是一般人能够享受的。\n");
			set("base_weight", 200 + random(300));
			set("material", "gold");
			set("ring/armor", 100);
			set("value", 90000);

			break;
			case 7:
			set_name(HIC"魔法戒指"NOR, ({"magic banzhi", "banzhi", "ring"}));
			set("ring/long", HIC"这是一个从远古流传下来的戒指，上面刻着一些奇怪的咒语。\n"NOR);
			set("base_weight", 200 + random(300));
			set("material", "gold");
			set("ring/armor", 120);
			set("value", 100000);

			break;
			case 8:
			set_name(HIW"天地神戒"NOR, ({"tiandi banzhi", "banzhi", "ring"}));
			set("ring/long", HIC"这是一个从远古流传下来的戒指，上面刻着一些奇怪的咒语。\n"NOR);
			set("base_weight", 200 + random(300));
			set("material", "gold");
			set("ring/armor", 150);
			set("value", 150000);

			break;
      	 	
	}

	setup_ring();
	setup();
}

void setup_ring()
{
	int hole, i;
	string longdes;
	object ob = this_object();

	//基本信息
	if(stringp(ob->query("ring/name")))
	set_name(ob->query("ring/name"), ob->parse_command_id_list());

	//set long_desc
	if (!stringp(ob->query("ring/long")))
	longdes = "这是一只普通的指环。\n";
	else
	longdes = ob->query("ring/long");

	longdes += set_ring_desc(ob);

	set("long", longdes);

	//材料
	if (!ob->query("material")) ob->set("material", "iron");

	//wield,unwield msg
	if (!stringp(ob->query("wear_msg")))
	set("wear_msg", "$N戴上一只$n。\n");

	if (!stringp(ob->query("unequip_msg")))
	set("unequip_msg", "$N将$n从手指上摘了下来。\n");

}
