/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : material.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#define MATERIAL_CHINESE	([ \
METAL	:	"[1;37m金屬[0m",	\
STONE	:	"[0;1;30m原石[0m",	\
WATER	:	"[1;36m清水[0m", 	\
WOOD	:	"[0;33m原木[0m", 	\
FUEL	:	"[1;34m燃料[0m", 	\
GOLD	:	"[1;33m金[0m", 	\
IRON	:	"[1;37m鐵[0m",	\
])

/* 基本原料 */
#define METAL		"metal"		//金屬
#define WATER		"water"		//水
#define WOOD		"wood"		//原木
#define STONE		"stone"		//原石
#define FUEL		"fuel"		//化石燃料

#define GOLD		"gold"		//黃金
#define IRON		"iron"		//鐵

#define MATERIAL(x)	("/obj/materials/"+x)

// 一級原料
#define M_METAL		"metal"		//金屬
#define M_STONE		"stone"		//石材
#define M_WOOD		"wood"		//原木
#define M_WATER		"water"		//水
#define M_FUEL		"fuel"		//燃料

// 二級原料
// 金屬
#define M_GOLD		"gold"		//金
#define M_COPPER	"copper"	//銅
#define M_SILVER	"silver"	//銀
#define M_TIN		"tinmine"	//錫
#define M_ALUMINUM	"aluminum"	//鋁
#define M_IRON		"iron"		//鐵
#define M_URANIUM	"uranium"	//鈾
// 石材
#define M_QUARTZ	"quartz"	//石英
#define M_SILICON	"silicon"	//矽砂
#define M_POTTER	"potter"	//陶土
#define M_MARBLE	"marble"	//大理石
#define M_GRANITE	"granite"	//花崗岩
#define M_SERPENTINE 	"serpentine"	//蛇紋岩
#define M_DIAMOND	"diamond"	//鑽石
#define M_LIME		"lime"		//石灰岩
// 原木
#define M_FIR		"fir"		//杉木
#define M_JUNIPER	"juniper"	//檜木
#define M_SANDAL	"sandal"	//檀木
#define M_TEAK		"teak"		//柚木
// 燃料
#define M_OIL		"oil"		//原油
#define M_GAS		"ngas"		//天然氣
#define M_COAL		"coal"		//煤礦
// 水
#define M_ROWATER	"rowater"	//逆滲透水
#define M_DIWATER	"diwater"	//去離子水
#define M_DTWATER	"dtwater"	//蒸餾水

// 三級原料
#define M_STEEL		"steel"		//鋼
#define M_PLASTICS	"plastics"	//塑膠
#define M_RUBBER	"rubber"	//橡膠
#define M_GLASS		"glass"		//玻璃
