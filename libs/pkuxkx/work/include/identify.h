//title.h
#define IDF_CANT 0 //不能鉴定的物品
#define IDF_SIMPLE 1 //存在鉴定信息但是不需要任何鉴定技能的简单物品，存在identify()函数
#define IDF_EQUIP 2 //需要鉴定的武器装备
#define IDF_ANTIQUE 3 //需要鉴定的古玩字画

#define IL_INIT 0 //初始状态，未鉴定出任何信息
#define IL_SIMPLE 1 //仅鉴定出最基本的信息
#define IL_FULL 2 //鉴定出物品的所有信息

//提供物品本身的鉴定信息
//idf_level为鉴定级别，同IL_系列define定义的取值范围
//player为鉴定者，鉴定者不一定需要有
varargs string identify(int idf_level, object player);
//提供物品的鉴定类型，具体返回值见前面的IDF_系列define，取值范围仅限于上述设定范围
int is_identify();
//提供鉴定者能否鉴定该物品的判定逻辑
//注意鉴定者不是必须要有的
varargs int valid_identify(object player);
//设定物品的鉴定级别
//被鉴定者鉴定以后设定对物品的鉴定程度
varargs int set_idflevel(object player);
//显示物品的鉴定级别
//所有鉴定级别定义采用标准定义，具体见IL_系列define，不管内部如何定义，外部统一采用该返回值定义
varargs int get_idflevel(object item);

//装备属性的鉴定信息设定，鉴定信息字符串数组中第一个元素是鉴定基本信息，第二个元素是计量单位
protected mapping identify_effect_set = ([
       "armor"       :  ({HIC"【基础】"NOR"护甲","点"}),
       "defense"     :  ({HIC"【基础】"NOR"防御力","级"}),
       "attack"      :  ({HIC"【基础】"NOR"攻击力","级"}),
       "damage"      :  ({HIC"【基础】"NOR"伤害力","点"}),
       "dmg_map"     :  ({HIC"【基础】"NOR"$sk$伤害","点"}),           //特定武器攻击力，值为mapping结构，比如剑法伤害提高100，则设置成(["dmg_map":(["sword":"100])]);
                                                                       //    效果就是当你的武器是剑的时候，攻击伤害提高100，否则不提高。
                                                                       //这里空手统一使用unarmed来表示。描述中通配符$sk$到时候根据技能id代替成对应的剑法、刀法、空手等等。
       "magic"       :  ({HIC"【基础】"NOR"幸运值","点"}),
       "attack_speed":  ({HIC"【基础】"NOR"攻击速度","%"}),  
       "attack_factor": ({HIR"【基础】"NOR"攻击命中","%"}),  
       "parry_factor":  ({HIY"【基础】"NOR"招架命中","%"}), 
       "dodge_factor":  ({HIY"【基础】"NOR"躲闪命中","%"}), 
       "deep_injure" :  ({HIR"【伤害】"NOR"普通伤害增益","%"}),  
       "week_injure" :  ({HIY"【防御】"NOR"普通伤害抗性","%"}),
       "abs_week_injure" :  ({HIY"【防御】"HIC"普通伤害绝对抗性"NOR,"%"}),
       "defense_attack":({HIY"【防御】"NOR"普通伤害削弱","点"}),
       "armor_vs_force":({HIY"【防御】"NOR"加力伤害抵抗","点"}),
       "armor_effect_armor_vs_force"
                     :  ({HIM"【防御】"NOR"内力吸收伤害","%"}),
       "armor_effect_healup"
                     :  ({HIM"【宝石】"NOR"恢  复","%"}),
       "armor_effect_poison"
                     :  ({HIM"【宝石】"NOR"淬  毒"," "}),
       "armor_effect_rebound"
                     :  ({HIM"【宝石】"NOR"回  伤","%"}),
       "weapon_effect_jing"
                     :  ({HIM"【宝石】"NOR"吸精神","点"}),
       "weapon_effect_poison"
                     :  ({HIM"【宝石】"NOR"淬  毒"," "}),
       "weapon_effect_suck"
                     :  ({HIM"【宝石】"NOR"吸  血","%"}),
       "kf_hit_rate" :  ({HIM"【特效】"NOR"技能命中提升","级"}),
       "kf_anti_hr"  :  ({HIM"【特效】"NOR"技能命中抗性","级"}),
       "kf_def_wound":  ({HIM"【特效】"NOR"技能伤害抗性","%"}),
       "kf_abs_def":  ({HIM"【特效】"HIC"技能伤害绝对抗性"NOR,"%"}),
       "kf_wound":  ({HIM"【特效】"NOR"技能伤害增益","%"}),
       "cant_all_busy":  ({HIM"【特效】"NOR"免疫所有行为限制效果",""}),
       "cant_busy_dianxue":  ({HIM"【特效】"NOR"免疫点穴效果",""}),
       "cant_busy_jiemai":  ({HIM"【特效】"NOR"免疫截脉效果",""}),
       "cant_busy_fenjin":  ({HIM"【特效】"NOR"免疫分筋错骨效果",""}),
       "cant_busy_confuse":  ({HIM"【特效】"NOR"免疫压制效果",""}),
       "cant_busy_body":  ({HIM"【特效】"NOR"免疫缠绕效果",""}),
       "max_all_busy":  ({HIM"【特效】"NOR"所有行为限制效果最多","秒"}),
       "max_busy_dianxue":  ({HIM"【特效】"NOR"点穴效果最多","秒"}),
       "max_busy_jiemai":  ({HIM"【特效】"NOR"截脉效果最多","秒"}),
       "max_busy_fenjin":  ({HIM"【特效】"NOR"分筋错骨效果最多","秒"}),
       "max_busy_confuse":  ({HIM"【特效】"NOR"压制效果最多","秒"}),
       "max_busy_body":  ({HIM"【特效】"NOR"缠绕效果最多","秒"}),
	   "AllPoisonsImmune": ({HIM"【特效】"NOR"毒性攻击抗性","%"}),
	   "PoisonAttack": ({HIM"【特效】"NOR"普通攻击带毒",""}),
       "strength"    :  ({HIC"【属性】"NOR"膂  力","点"}),
       "intelligence":  ({HIC"【属性】"NOR"悟  性","点"}),
       "constitution":  ({HIC"【属性】"NOR"跟  骨","点"}),
       "dexerity"    :  ({HIC"【属性】"NOR"身  法","点"}),
       "personality" :  ({HIC"【属性】"NOR"容  貌","点"}),
       "spirituality":  ({HIC"【属性】"NOR"灵  性","点"}),
       "max_qi"      :  ({HIC"【属性】"NOR"气  血","点"}),
       "max_jing"    :  ({HIC"【属性】"NOR"精  神","点"}),
       "qi_recover"  :  ({HIG"【恢复】"NOR"气  血","点/秒"}),
       "jing_recover":  ({HIG"【恢复】"NOR"精  神","点/秒"}),
       "neili_recover": ({HIG"【恢复】"NOR"内  力","点/秒"}),
       "jingli_recover":({HIG"【恢复】"NOR"精  力","点/秒"}),
       "qi_cure"     :  ({HIG"【治疗】"NOR"气  血","点/秒"}),
       "jing_cure"   :  ({HIG"【治疗】"NOR"精  神","点/秒"}),
       "claw"        :  ({HIM"【技能】"NOR"爪  法","级"}),
       "cuff"        :  ({HIM"【技能】"NOR"拳  法","级"}),
       "dodge"       :  ({HIM"【技能】"NOR"轻  功","级"}),
       "finger"      :  ({HIM"【技能】"NOR"指  法","级"}),
       "hand"        :  ({HIM"【技能】"NOR"手  法","级"}),
       "parry"       :  ({HIM"【技能】"NOR"招  架","级"}),
       "strike"      :  ({HIM"【技能】"NOR"掌  法","级"}),
       "unarmed"     :  ({HIM"【技能】"NOR"拳  脚","级"}),
       "sword"       :  ({HIM"【技能】"NOR"剑  法","级"}),
       "blade"       :  ({HIM"【技能】"NOR"刀  法","级"}),
       "whip"        :  ({HIM"【技能】"NOR"鞭  法","级"}),
       "staff"       :  ({HIM"【技能】"NOR"杖  法","级"}),
       "force"       :  ({HIM"【技能】"NOR"内  功","级"}),
       "dagge"       :  ({HIM"【技能】"NOR"匕  首","级"}),
       "hammer"      :  ({HIM"【技能】"NOR"锤  法","级"}),
       "spear"       :  ({HIM"【技能】"NOR"枪  法","级"}),
       "throwing"    :  ({HIM"【技能】"NOR"暗  器","级"}),
]);

//提供来源于宝石的属性限制设定
protected mapping gem_equip_limit = ([
  "week_injure" : 50,
  "kf_def_wound" : 50 ]);