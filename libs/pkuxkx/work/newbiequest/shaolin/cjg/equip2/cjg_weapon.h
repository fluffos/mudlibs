//equip.h 装备共同信息

mapping weapon_info=
(["level1_sword":
	(["name":HIG"尚贤剑"NOR, "id":({ "shangxian jian","shangxian","sword" }),
		"forge/max":2, "suit":"cjg_level1", "weapon_prop/strength":10, "level":6,
		"weapon_prop/attack":50, "weapon/strength":10, "weapon/attack":50,
		"long":"国有贤良之士众，则国家之治厚；贤良之士寡，则国家之治薄。\n", 
		"weapon/damage":230, "weapon_prop/damage":230, "type":"sword"]),
  "level2_sword":
	(["name":HIB"非命剑"NOR, "id":({ "feiming jian","feiming","sword" }),
		"forge/max":3, "suit":"cjg_level2", "weapon_prop/strength":15, "level":7,
		"weapon_prop/attack":60, "weapon/strength":15, "weapon/attack":60,
		"long":"同归殊涂，俱用灭亡，皆炕龙绝气，非命之运。\n", 
		"weapon/damage":190, "weapon_prop/damage":190, "type":"sword"]),
  "level3_sword":
	(["name":HIY"天志剑"NOR, "id":({ "tianzhi jian","tianzhi","sword" }),
		"forge/max":3, "suit":"cjg_level3", "weapon_prop/strength":20, "level":8,
		"weapon_prop/attack":80, "weapon/strength":20, "weapon/attack":80,
		"long":"我有天志，譬若轮人之有规，匠人之有矩。\n", 
		"weapon/damage":210, "weapon_prop/damage":210, "type":"sword"]),
	"level1_blade":
	(["name":HIG"悯农刀"NOR, "id":({ "minnong dao","minnong","blade" }),
		"forge/max":2, "suit":"cjg_level1", "weapon_prop/strength":15, "level":6, 
		"weapon_prop/attack":30, "weapon/strength":15, "weapon/attack":30,
		"long":"时人不识农家苦，将谓田中谷自生。\n", "weapon_prop/damage":230,
		"weapon/damage":230, "type":"blade"]),
  "level2_blade":
	(["name":HIB"循名刀"NOR, "id":({ "xunming dao","xunming","blade" }),
		"forge/max":3, "suit":"cjg_level2", "weapon_prop/strength":20, "level":7,
		"weapon_prop/attack":40, "weapon/strength":20, "weapon/attack":40,
		"long":"为人臣者陈而言，君以其言授之事，专以其事责其功。\n", 
		"weapon/damage":190, "weapon_prop/damage":190, "type":"blade"]),
  "level3_blade":
	(["name":HIY"韩非子刀"NOR, "id":({ "hanfei dao","hanfei","blade" }),
		"forge/max":3, "suit":"cjg_level3", "weapon_prop/strength":25, "level":8,
		"weapon_prop/attack":50, "weapon/strength":25, "weapon/attack":50,
		"long":"不可一无，皆帝王之具也。\n", "weapon_prop/damage":210,
		"weapon/damage":210, "type":"blade"]),
	"level1_hammer":
	(["name":HIG"棱威锤"NOR, "id":({ "lingwei hammer", "lingwei", "hammer" }),
		"forge/max":2, "suit":"cjg_level1", "weapon_prop/dexerity":-10, "level":7,
		"weapon/dexerity":-10, "weapon_prop/damage":230, "type":"hammer",
		"weapon/damage":230, "long":"棱威一代明成祖 ，骨鲠千秋方孝孺 。\n" ]),
	"level2_hammer":
	(["name":HIB"裂胆锤"NOR, "id":({ "liedan hammer", "liedan", "hammer" }),
		"forge/max":3, "suit":"cjg_level2", "weapon_prop/dexerity":-5, "level":8,
		"weapon/dexerity":-5, "weapon_prop/damage":190, "type":"hammer",
		"weapon/damage":190, "long":"肝胆两相照，生死一昆仑 。\n" ]),
	"level3_hammer":
	(["name":HIY"刑天锤"NOR, "id":({ "xingtian hammer", "xingtian", "hammer" }),
		"forge/max":3, "suit":"cjg_level3", "weapon_prop/dexerity":5, "level":9,
		"weapon/dexerity":5, "weapon_prop/damage":210, "type":"hammer",
		"weapon/damage":210, "long":"以乳为目，以脐为口，操干戚以舞。\n" ]),
	"level1_spear":
	(["name":HIG"五德枪"NOR, "id":({ "wude qiang", "wude", "spear" }),
		"forge/max":2, "suit":"cjg_level1", "weapon_prop/dexerity":-10, "level":7,
		"weapon/dexerity":-10, "weapon_prop/damage":230, "type":"spear",
		"weapon/damage":230, "long":"其法亦起五德终始，推其极则无不至。\n" ]),
	"level2_spear":
	(["name":HIB"六亲枪"NOR, "id":({ "liuqin qiang", "liuqin", "spear" }),
		"forge/max":3, "suit":"cjg_level2", "weapon_prop/dexerity":-10, "level":8, 
		"weapon/dexerity":-10, "weapon_prop/damage":190, "type":"spear",
		"weapon/damage":190, "long":"止乎仁义节俭，君臣上下六亲之施。\n" ]),
	"level3_spear":
	(["name":HIY"羲和枪"NOR, "id":({ "xihe qiang", "xihe", "spear" }),
		"forge/max":3, "suit":"cjg_level3", "weapon_prop/dexerity":-5, "level":9,
		"weapon/dexerity":-5, "weapon_prop/damage":210, "type":"spear",
		"weapon/damage":210, "long":"敬顺昊天，历象日月星辰，敬授民时，此其所长也。\n" ]),
  "level1_staff":
	(["name":HIG"耕桑棍"NOR, "id":({ "gengsang gun", "gengsang", "staff" }),
		"forge/max":2, "suit":"cjg_level1", "weapon_prop/strength":20, "level":7,
		"weapon_prop/dexerity":-10, "weapon/strength":20, "weapon/dexerity":-10,
		"long":"贤者与民并耕而食，饔飧而治。\n", "weapon_prop/damage":230,
		"weapon/damage":230, "type":"staff"]),
  "level2_staff":
	(["name":HIB"灵枢棍"NOR, "id":({ "lingshu gun", "lingshu", "staff" }),
		"forge/max":3, "suit":"cjg_level2", "weapon_prop/strength":30, "level":8,
		"weapon_prop/dexerity":-10, "weapon/strength":30, "weapon/dexerity":-10,
		"long":"空中之机，清静而微，其来不可送，其往不可追。\n", 
		"weapon/damage":190, "weapon_prop/damage":190, "type":"staff"]),
  "level3_staff":
	(["name":HIY"阴阳棍"NOR, "id":({ "yinyang gun", "yinyang", "staff" }),
		"forge/max":3, "suit":"cjg_level3", "weapon_prop/strength":40, "level":9,
		"weapon_prop/dexerity":-10, "weapon/strength":40, "weapon/dexerity":-10,
		"long":"深观阴阳消息，而作迂怪之变。\n", "weapon_prop/damage":210,
		"weapon/damage":210, "type":"staff"]),
  "level1_whip":
	(["name":HIG"梦云鞭"NOR, "id":({ "mengyun whip", "mengyun", "whip" }),
		"forge/max":2, "suit":"cjg_level1", "weapon_prop/dexerity":-5, "level":5,
		"weapon/dexerity":-5, "weapon_prop/damage":230, "type":"whip",
		"weapon/damage":230, "long":"妾在巫山之阳，高丘之阻。旦为朝云，暮为行雨。\n"]),
  "level2_whip":
	(["name":HIB"瑞霞鞭"NOR, "id":({ "ruixia whip", "ruixia", "whip" }),
		"forge/max":3, "suit":"cjg_level2", "weapon_prop/strength":5, "level":6,
	  "weapon_prop/dexerity":-5, "weapon/strength":5, 
		"weapon/dexerity":-5, "weapon_prop/damage":190, "type":"whip",
		"weapon/damage":190, "long":"日月星辰瑞历，是禹桀之所同也。\n"]),
  "level3_whip":
	(["name":HIY"行道鞭"NOR, "id":({ "xingdao whip", "xingdao", "whip" }),
		"forge/max":3, "suit":"cjg_level3", "weapon_prop/strength":10, "level":7,
	  "weapon_prop/dexerity":-5, "weapon/strength":10, 
		"weapon/dexerity":-5, "weapon_prop/damage":210, "type":"whip",
		"weapon/damage":210, "long":"啼猿何必近孤舟。行客自多愁。\n"]),
  "level1_dagger":
	(["name":HIG"百辟灵宝匕"NOR, "id":({ "lingbao bi", "lingbao", "dagger" }),
		"forge/max":2, "suit":"cjg_level1", "weapon_prop/dexerity":15, "level":5,
		"weapon_speed":110,"weapon/dexerity":15, "weapon_prop/damage":210, 
		"type":"dagger", "weapon/damage":210, 
		"long":"长四尺三寸六分，重三斤六两，文似灵龟。\n"]),
  "level2_dagger":
	(["name":HIB"百辟含章匕"NOR, "id":({ "hanzhang bi", "hanzhang", "dagger" }),
		"forge/max":3, "suit":"cjg_level2", "weapon_prop/dexerity":25, "level":6,
		"weapon_speed":115, "weapon/dexerity":25, "weapon_prop/damage":180, 
		"type":"dagger", "weapon/damage":180, 
		"long":"长四尺三寸三分，重三斤十两，采似丹霞。\n"]),
  "level3_dagger":
	(["name":HIY"百辟龙鳞匕"NOR, "id":({ "longlin bi", "longlin", "dagger" }),
		"forge/max":3, "suit":"cjg_level3", "weapon_prop/dexerity":40, "level":7,
		"weapon_speed":120, "weapon/dexerity":40, "weapon_prop/damage":200, 
		"type":"dagger", "weapon/damage":200, 
		"long":"于铄良刀，胡炼亶时，譬诸鳞角，靡所任兹。不逢不若，永世宝持。利用卫身，以威弗治。\n"]) ]);

//设置藏经阁兵器的特殊属性
void set_cjg_weapon(string key)
{
	mapping weapon_det;
	string *attr;
	int flag,lp;
	
	if ( !(weapon_det=weapon_info[key]) )
		return;
	
	set("skill_type", weapon_det["type"]);
  if(query("two_hand")) 
    flag = 1;
	switch(weapon_det["type"])
	{
		case "sword":
    	set("flag", 2 | (int)flag | EDGED);
	    if( !query("actions") ) 
	    {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
		    set("verbs", ({ "slash", "slice", "thrust" }) );
	    }
        set("base_weight", 4000);
	    set_weight(4000);
	    set("unit", "把");
	    break;
		case "blade":
    	set("flag", 2 | (int)flag | EDGED);
	    if( !query("actions") ) 
	    {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
		    set("verbs", ({ "slash", "slice", "hack" }) );
	    }
        set("base_weight", 4000);
	    set_weight(4000);
	    set("unit", "把");
	    break;
		case "hammer":
    	set("flag", flag );
	    if( !query("actions") ) 
	    {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
		    set("verbs", ({ "bash", "crush", "slam" }) );
	    }
        set("base_weight", 8000);
	    set_weight(8000);
	    set("unit", "对");
	    break;
		case "spear":
    	set("flag", (int)flag | EDGED);
	    if( !query("actions") ) 
	    {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
		    set("verbs", ({ "thrust", "pierce", "impale" }) );
	    }
        set("base_weight", 7000);
	    set_weight(7000);
	    set("unit", "柄");
	    break;
		case "staff":
    	set("flag", (int)flag | LONG);
	    if( !query("actions") ) 
	    {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
		    set("verbs", ({ "bash", "crush", "slam" }) );
	    }
        set("base_weight", 6000);
	    set_weight(6000);
	    set("unit", "根");
	    break;
		case "whip":
	    set("flag", 2 | (int)flag );
	    if( !query("actions") ) 
	    {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
		    set("verbs", ({ "whip" }) );
	    }
        set("base_weight", 4000);
	    set_weight(4000);
	    set("unit", "根");
	    break;
		case "dagger":
	    set("flag", flag | EDGED | SECONDARY );
	    if( !query("actions") ) {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
        set("verbs", ({ "slice", "pierce", "thrust" }) );
      }
      set("base_weight", 1500);
	    set_weight(1500);
	    set("unit", "把");
	    break;
	}
	
	set_name(weapon_det["name"], weapon_det["id"]);
	set("cjg_weapon", key);
	set("level",weapon_det["level"]);
	attr=keys(weapon_det);
	for( lp=0;lp<sizeof(attr);lp++)
	{
		if ( attr[lp]=="name" ||
			   attr[lp]=="id" ||
			   attr[lp]=="type" )
		  continue;
		
		set(attr[lp], weapon_det[attr[lp]]);
	}
	setup();
}