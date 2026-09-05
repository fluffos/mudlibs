//equip.h 装备共同信息

mapping armor_info=
(["lv1_armor":
	(["name":CYN"劣质明光甲〖身体〗"NOR, "id":({ "mingguang jia", "armor" }),
		"suit":"dt_level1", "armor_prop/armor":50, "no_give":1,
    "no_get":1, "no_put":1, "no_sell":1, "no_drop":1, "no_store":1,
    "no_sell_in_playershop":1, "long":"这是普通官兵的标准装备。\n", 
    "type": TYPE_ARMOR ]),
  "lv1_boots":
	(["name":CYN"劣质明光甲〖脚部〗"NOR, "id":({ "mingguang jia", "boots" }),
		"suit":"dt_level1", "armor_prop/armor":25, "no_give":1,
    "no_get":1, "no_put":1, "no_sell":1, "no_drop":1, "no_store":1,
    "no_sell_in_playershop":1, "long":"这是普通官兵的标准装备。\n", 
    "type": TYPE_BOOTS ]),
  "lv1_head":
	(["name":CYN"劣质明光甲〖头部〗"NOR, "id":({ "mingguang jia", "head" }),
		"suit":"dt_level1", "armor_prop/armor":25, "no_give":1,
    "no_get":1, "no_put":1, "no_sell":1, "no_drop":1, "no_store":1,
    "no_sell_in_playershop":1, "long":"这是普通官兵的标准装备。\n", 
    "type": TYPE_HEAD ]), ]);

//设置藏经阁装备的特殊属性
void set_dtang_armor(string key)
{
	mapping armor_det;
	string *attr;
	int flag,lp;
	
	if ( !(armor_det=armor_info[key]) )
		return;
	
	set("armor_type", armor_det["type"]);
	switch(armor_det["type"])
	{
    case TYPE_ARMOR:
	    set_weight(6000);
	    set("unit", "件");
	    break;
    case TYPE_BOOTS:
	    set_weight(2500);
	    set("unit", "双");
	    break;
    case TYPE_CLOTH:
	    set_weight(2500);
	    set("unit", "件");
	    break;
    case TYPE_HANDS:
	    set_weight(2000);
	    set("unit", "对");
	    break;
    case TYPE_HEAD:
	    set_weight(2500);
	    set("unit", "件");
	    break;
    case TYPE_NECK:
	    set_weight(1200);
	    set("unit", "条");
	    break;
    case TYPE_FINGER:
	    set_weight(1200);
	    set("unit", "只");
	    break;
    case TYPE_SHIELD:
	    set_weight(9000);
	    set("unit", "件");
	    break;
    case TYPE_SURCOAT:
	    set_weight(2500);
	    set("unit", "件");
	    break;
    case TYPE_WAIST:
	    set_weight(2500);
	    set("unit", "根");
	    break;
    case TYPE_WRISTS:
	    set_weight(2000);
	    set("unit", "对");
	    break;
	}
	
	set_name(armor_det["name"], armor_det["id"]);
	attr=keys(armor_det);
	for( lp=0;lp<sizeof(attr);lp++)
	{
		if ( attr[lp]=="name" ||
			   attr[lp]=="id" ||
			   attr[lp]=="type" )
		  continue;
		
		set(attr[lp], armor_det[attr[lp]]);
	}
	
	if ( query("suit")=="dt_level1" )
	{
		set("suit_name", CYN"劣质明光甲"NOR );
		set("suit_prop", 
		  ({ (["limit":3,
		  	   "armor":100,
		  	   "magic":200,
		  	   "defense_attack":100,
		  	   "max_qi":200,
		  	   "max_jing":200,
		  	   "defense":50,
		  	   "kf_def_wound":1]) }) );
	}
		  	   
	setup();
}