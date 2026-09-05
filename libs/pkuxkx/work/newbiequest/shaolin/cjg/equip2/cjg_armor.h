//equip.h 装备共同信息

mapping armor_info=
(["level1_armor":
	(["name":HIG"金翎甲"NOR, "id":({ "jinling armor", "jinling", "armor" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":500, 
		"armor_prop/magic":5, "armor/armor":500, "armor/magic":5, 
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_ARMOR ]),
  "level2_armor":
	(["name":HIB"雕磐甲"NOR, "id":({ "diaopan armor", "diaopan", "armor" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":550, 
		"armor_prop/magic":10, "armor/armor":550, "armor/magic":10, 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_ARMOR ]),
  "level3_armor":
	(["name":HIY"震夙甲"NOR, "id":({ "zhensu armor", "zhensu", "armor" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":600, 
		"armor_prop/magic":15, "armor/armor":600, "armor/magic":15, 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_ARMOR ]),
  "level1_boots":
	(["name":HIG"金翎靴"NOR, "id":({ "jinling boots", "jinling", "boots" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":100, 
		"armor_prop/magic":5, "armor/armor":100, "armor/magic":5, 
		"armor_prop/dodge":20, "armor/dodge":20, 
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_BOOTS ]),
  "level2_boots":
	(["name":HIB"雕磐靴"NOR, "id":({ "diaopan boots", "diaopan", "boots" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":120, 
		"armor_prop/magic":5, "armor/armor":120, "armor/magic":5, 
		"armor_prop/dodge":30, "armor/dodge":30, 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_BOOTS ]),
  "level3_boots":
	(["name":HIY"震夙靴"NOR, "id":({ "zhensu boots", "zhensu", "boots" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":150, 
		"armor_prop/magic":5, "armor/armor":150, "armor/magic":5, 
		"armor_prop/dodge":50, "armor/dodge":50, 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_BOOTS ]),
  "level1_cloth":
	(["name":HIG"金翎袍"NOR, "id":({ "jinling cloth", "jinling", "cloth" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":100, 
		"armor_prop/magic":5, "armor/armor":100, "armor/magic":5, 
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_CLOTH ]),
  "level2_cloth":
	(["name":HIB"雕磐服"NOR, "id":({ "diaopan cloth", "diaopan", "cloth" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":120, 
		"armor_prop/magic":10, "armor/armor":120, "armor/magic":10, 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_CLOTH ]),
  "level3_cloth":
	(["name":HIY"震夙衣"NOR, "id":({ "zhensu cloth", "zhensu", "cloth" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":150, 
		"armor_prop/magic":15, "armor/armor":150, "armor/magic":15, 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_CLOTH ]),
  "level1_hands":
	(["name":HIG"金翎护手"NOR, "id":({ "jinling hands", "jinling", "hands" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":100, 
		"armor_prop/magic":5, "armor/armor":100, "armor/magic":5, 
		"armor_prop/claw":20, "armor_prop/finger":20, "armor_prop/cuff":20,
		"armor_prop/strike":20, "armor_prop/hand":20, "armor/claw":20,
		"armor/finger":20, "armor/cuff":20, "armor/strike":20, "armor/hand":20,
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_HANDS ]),
  "level2_hands":
	(["name":HIB"雕磐护手"NOR, "id":({ "diaopan hands", "diaopan", "hands" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":120, 
		"armor_prop/magic":5, "armor/armor":120, "armor/magic":5, 
		"armor_prop/claw":30, "armor_prop/finger":30, "armor_prop/cuff":30,
		"armor_prop/strike":30, "armor_prop/hand":30, "armor/claw":30,
		"armor/finger":30, "armor/cuff":30, "armor/strike":30, "armor/hand":30,
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_HANDS ]),
  "level3_hands":
	(["name":HIY"震夙护手"NOR, "id":({ "zhensu hands", "zhensu", "hands" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":150, 
		"armor_prop/magic":5, "armor/armor":150, "armor/magic":5, 
		"armor_prop/claw":50, "armor_prop/finger":50, "armor_prop/cuff":50,
		"armor_prop/strike":50, "armor_prop/hand":50, "armor/claw":50,
		"armor/finger":50, "armor/cuff":50, "armor/strike":50, "armor/hand":50,
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_HANDS ]),
  "level1_head":
	(["name":HIG"金翎冠"NOR, "id":({ "jinling head", "jinling", "head" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":100, 
		"armor_prop/magic":5, "armor/armor":100, "armor/magic":5, 
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_HEAD ]),
  "level2_head":
	(["name":HIB"雕磐巾"NOR, "id":({ "diaopan head", "diaopan", "head" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":120, 
		"armor_prop/magic":10, "armor/armor":120, "armor/magic":10, 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_HEAD ]),
  "level3_head":
	(["name":HIY"震夙发结"NOR, "id":({ "zhensu head", "zhensu", "head" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":150, 
		"armor_prop/magic":15, "armor/armor":150, "armor/magic":15, 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_HEAD ]),
  "level1_neck":
	(["name":HIG"金翎项链"NOR, "id":({ "jinling necklace", "jinling", "necklace" }),
		"forge/max":2, "suit":"cjg_level1", "armor_prop/armor":50, 
		"armor_prop/magic":5, "armor/armor":50, "armor/magic":5, "material":"jade",
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_NECK ]),
  "level2_neck":
	(["name":HIB"雕磐项链"NOR, "id":({ "diaopan necklace", "diaopan", "necklace" }),
		"forge/max":2, "suit":"cjg_level2", "armor_prop/armor":60, 
		"armor_prop/magic":10, "armor/armor":60, "armor/magic":10, "material":"jade", 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_NECK ]),
  "level3_neck":
	(["name":HIY"震夙项链"NOR, "id":({ "zhensu necklace", "zhensu", "necklace" }),
		"forge/max":2, "suit":"cjg_level3", "armor_prop/armor":80, 
		"armor_prop/magic":15, "armor/armor":80, "armor/magic":15, "material":"jade", 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_NECK ]),
  "level1_finger":
	(["name":HIG"金翎戒"NOR, "id":({ "jinling ring", "jinling", "ring" }),
		"forge/max":2, "suit":"cjg_level1", "armor_prop/armor":50, 
		"armor_prop/magic":5, "armor/armor":50, "armor/magic":5, "material":"jade",
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_FINGER ]),
  "level2_finger":
	(["name":HIB"雕磐戒"NOR, "id":({ "diaopan ring", "diaopan", "ring" }),
		"forge/max":2, "suit":"cjg_level2", "armor_prop/armor":60, 
		"armor_prop/magic":10, "armor/armor":60, "armor/magic":10, "material":"jade", 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_FINGER ]),
  "level3_finger":
	(["name":HIY"震夙戒"NOR, "id":({ "zhensu ring", "zhensu", "ring" }),
		"forge/max":2, "suit":"cjg_level3", "armor_prop/armor":80, 
		"armor_prop/magic":15, "armor/armor":80, "armor/magic":15, "material":"jade", 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_FINGER ]),
  "level1_shield":
	(["name":HIG"金翎盾"NOR, "id":({ "jinling shield", "jinling", "shield" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":500, 
		"armor_prop/magic":5, "armor/armor":500, "armor/magic":5,
		"armor_prop/armor_effect_rebound":16, "armor/rebound":16, 
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_SHIELD ]),
  "level2_shield":
	(["name":HIB"雕磐盾"NOR, "id":({ "diaopan shield", "diaopan", "shield" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":550, 
		"armor_prop/magic":5, "armor/armor":550, "armor/magic":5, 
		"armor_prop/armor_effect_rebound":24, "armor/rebound":24, 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_SHIELD ]),
  "level3_shield":
	(["name":HIY"震夙盾"NOR, "id":({ "zhensu shield", "zhensu", "shield" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":600, 
		"armor_prop/magic":5, "armor/armor":600, "armor/magic":5, 
		"armor_prop/armor_effect_rebound":36, "armor/rebound":36, 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_SHIELD ]),
  "level1_surcoat":
	(["name":HIG"金翎披风"NOR, "id":({ "jinling surcoat", "jinling", "surcoat" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":100, 
		"armor_prop/magic":5, "armor/armor":100, "armor/magic":5, 
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_SURCOAT ]),
  "level2_surcoat":
	(["name":HIB"雕磐披风"NOR, "id":({ "diaopan surcoat", "diaopan", "surcoat" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":120, 
		"armor_prop/magic":10, "armor/armor":120, "armor/magic":10, 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_SURCOAT ]),
  "level3_surcoat":
	(["name":HIY"震夙披风"NOR, "id":({ "zhensu surcoat", "zhensu", "surcoat" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":150, 
		"armor_prop/magic":15, "armor/armor":150, "armor/magic":15, 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_SURCOAT ]),
  "level1_waist":
	(["name":HIG"金翎腰带"NOR, "id":({ "jinling waist", "jinling", "waist" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":100, 
		"armor_prop/magic":5, "armor/armor":100, "armor/magic":5, 
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_WAIST ]),
  "level2_waist":
	(["name":HIB"雕磐腰带"NOR, "id":({ "diaopan waist", "diaopan", "waist" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":120, 
		"armor_prop/magic":10, "armor/armor":120, "armor/magic":10, 
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_WAIST ]),
  "level3_waist":
	(["name":HIY"震夙腰带"NOR, "id":({ "zhensu waist", "zhensu", "waist" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":150, 
		"armor_prop/magic":15, "armor/armor":150, "armor/magic":15, 
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_WAIST ]),
  "level1_wrists":
	(["name":HIG"金翎护腕"NOR, "id":({ "jinling wrists", "jinling", "wrists" }),
		"forge/max":3, "suit":"cjg_level1", "armor_prop/armor":100, 
		"armor_prop/magic":5, "armor/armor":100, "armor/magic":5, 
		"armor_prop/parry":20, "armor/parry":20,
		"long":"萧韶九成，凤皇来仪\n", "type": TYPE_WRISTS ]),
  "level2_wrists":
	(["name":HIB"雕磐护腕"NOR, "id":({ "diaopan wrists", "diaopan", "wrists" }),
		"forge/max":3, "suit":"cjg_level2", "armor_prop/armor":120, 
		"armor_prop/magic":5, "armor/armor":120, "armor/magic":5, 
		"armor_prop/parry":30, "armor/parry":30,
		"long":"君当做磐石,妾当做蒲苇,蒲苇纫如丝,磐石无转移\n", "type": TYPE_WRISTS ]),
  "level3_wrists":
	(["name":HIY"震夙护腕"NOR, "id":({ "zhensu wrists", "zhensu", "wrists" }),
		"forge/max":3, "suit":"cjg_level3", "armor_prop/armor":150, 
		"armor_prop/magic":5, "armor/armor":150, "armor/magic":5, 
		"armor_prop/parry":50, "armor/parry":50,
		"long":"履帝武敏歆，攸介攸止，载震载夙\n", "type": TYPE_WRISTS ]) ]);

//设置藏经阁装备的特殊属性
void set_cjg_armor(string key)
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
        set("base_weight", 6000);
	    set_weight(6000);
	    set("unit", "件");
	    break;
    case TYPE_BOOTS:
        set("base_weight", 2500);
	    set_weight(2500);
	    set("unit", "双");
	    break;
    case TYPE_CLOTH:
        set("base_weight", 2500);
	    set_weight(2500);
	    set("unit", "件");
	    break;
    case TYPE_HANDS:
        set("base_weight", 2000);
	    set_weight(2000);
	    set("unit", "对");
	    break;
    case TYPE_HEAD:
        set("base_weight", 2500);
	    set_weight(2500);
	    set("unit", "件");
	    break;
    case TYPE_NECK:
        set("base_weight", 1200);
	    set_weight(1200);
	    set("unit", "条");
	    break;
    case TYPE_FINGER:
        set("base_weight", 1200);
	    set_weight(1200);
	    set("unit", "只");
	    break;
    case TYPE_SHIELD:
        set("base_weight", 9000);
	    set_weight(9000);
	    set("unit", "件");
	    break;
    case TYPE_SURCOAT:
        set("base_weight", 2500);
	    set_weight(2500);
	    set("unit", "件");
	    break;
    case TYPE_WAIST:
        set("base_weight", 2500);
	    set_weight(2500);
	    set("unit", "根");
	    break;
    case TYPE_WRISTS:
        set("base_weight", 2000);
	    set_weight(2000);
	    set("unit", "对");
	    break;
	}
	
	set_name(armor_det["name"], armor_det["id"]);
	set("cjg_armor", key);
	attr=keys(armor_det);
	for( lp=0;lp<sizeof(attr);lp++)
	{
		if ( attr[lp]=="name" ||
			   attr[lp]=="id" ||
			   attr[lp]=="type" )
		  continue;
		
		set(attr[lp], armor_det[attr[lp]]);
	}
	
	if ( query("suit")=="cjg_level1" )
	{
		set("suit_name", HIG"金翎套装"NOR );
		set("suit_prop", 
		  ({ (["limit":2,
		  	   "max_qi":1000,
		  	   "max_jing":1000]),
		  	 (["limit":4,
		  	 	 "qi_recover":40,
		  	 	 "jing_recover":40,
		  	 	 "neili_recover":20,
		  	 	 "jingli_recover":20]),
		  	 (["limit":8,
		  	 	 "magic":50,
		  	 	 "armor_effect_healup":10,
		  	 	 "qi_cure":20,
		  	 	 "jing_cure":20]) }) );
	}
	
	if ( query("suit")=="cjg_level2" )
	{
		set("suit_name", HIB"雕磐套装"NOR );
		set("suit_prop", 
		  ({ (["limit":2,
		  	   "max_qi":2000,
		  	   "max_jing":2000]),
		  	 (["limit":4,
		  	 	 "qi_recover":60,
		  	 	 "jing_recover":60,
		  	 	 "neili_recover":30,
		  	 	 "jingli_recover":30]),
		  	 (["limit":8,
		  	 	 "magic":100,
		  	 	 "armor_effect_healup":20,
		  	 	 "qi_cure":30,
		  	 	 "jing_cure":30]) }) );
	}
	
	if ( query("suit")=="cjg_level3" )
	{
		set("suit_name", HIY"震夙套装"NOR );
		set("suit_prop", 
		  ({ (["limit":2,
		  	   "max_qi":4000,
		  	   "max_jing":4000]),
		  	 (["limit":4,
		  	 	 "qi_recover":80,
		  	 	 "jing_recover":80,
		  	 	 "neili_recover":40,
		  	 	 "jingli_recover":40]),
		  	 (["limit":8,
		  	 	 "magic":150,
		  	 	 "armor_effect_healup":30,
		  	 	 "qi_cure":40,
		  	 	 "jing_cure":40]) }) );
	}
		  	   
	setup();
}