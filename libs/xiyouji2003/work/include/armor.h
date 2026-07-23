/******************************************/
/* MUDLIB：Biographies         〓悟空传〓  */
/* Created Admin By Waiwai@2001/02/18     */
/* Admin Email：wkzstory@21cn.com         */
/******************************************/
// Last modified by waiwai@2002/12/20

#include "ansi.h"

#ifndef __ARMOR__
#define __ARMOR__

// Added by waiwai@2002/12/20
#define HEAD			"/std/armor/head"		//头盔
#define NECK			"/std/armor/neck"		//护颈
#define CAPE            	"/std/armor/cape"		//背甲
#define CLOTH			"/std/armor/cloth"		//上衣
#define ARMOR			"/std/armor/armor"		//护甲
#define ARMBANDS		"/std/armor/armbands"	//护臂
#define SURCOAT		"/std/armor/surcoat"		//大氅
#define WAIST			"/std/armor/waist"		//护腰或者短裙
#define WRISTS		"/std/armor/wrists"		//护腕
#define SHIELD		"/std/armor/shield"		//盾牌
#define FINGER		"/std/armor/finger"		//戒指
#define HANDS			"/std/armor/hands"		//手套
#define BOOTS			"/std/armor/boots"		//鞋子
#define PANTS			"/std/armor/pants"		//裤子
#define FLOWER		"/std/armor/flower"		//胸饰
#define LEGGINGS		"/std/armor/leggings"	//护膝
#define SHOULDER		"/std/armor/shoulder"	//护肩
#define SKIRTS		"/std/armor/skirts"		//长裙(女性)
#define OTHERS		"/std/armor/others"		//另类

// Standard armor types
#define TYPE_HEAD		"head"
#define TYPE_NECK		"neck"
#define TYPE_CLOTH		"cloth"
#define TYPE_ARMOR		"armor"
#define TYPE_SURCOAT	       "surcoat"
#define TYPE_WAIST		"waist"
#define TYPE_WRISTS		"wrists"
#define TYPE_SHIELD		"shield"
#define TYPE_FINGER		"finger"
#define TYPE_HANDS		"hands"
#define TYPE_BOOTS		"boots"
#define TYPE_PANTS		"pants"
#define TYPE_FLOWER		"flower"
#define TYPE_ARMBANDS	"armbands"
#define TYPE_CAPE          "cape"
#define TYPE_LEGGINGS      "leggings"
#define TYPE_SHOULDER      "shoulder"
#define TYPE_SKIRTS      "skirts"
#define TYPE_OTHERS      	"others"

// Added by waiwai@2002/12/20
// 将一般性护具属性定义上限，以突出灵性及
// 高级镶嵌组合护具的优势 全部装备穿齐后
// 综合防御等于 230
// 组合以及特殊的物件不再此限制之列，有
// combine标志的物件类似死亡将会被系统dis，
// 也就是一般的飞掉
#define PROP_ARMOR              30  //盔甲
#define PROP_HEAD               15  //头盔
#define PROP_NECK               10  //护颈
#define PROP_CLOTH              15  //上衣
#define PROP_ARMBANDS           10  //护臂
#define PROP_PANTS              15  //裤子
#define PROP_WAIST              10  //护腰
#define PROP_WRISTS             10  //护腕
#define PROP_SHIELD             25  //盾牌
#define PROP_FINGER             10  //戒指
#define PROP_HANDS              10  //手套
#define PROP_BOOTS              10  //鞋子
#define PROP_CAPE               15  //背甲
#define PROP_LEGGINGS           10  //护膝
#define PROP_SHOULDER           15  //护肩
#define PROP_FLOWER             10  //胸饰
#define PROP_SURCOAT            10  //大氅
#define PROP_SKIRTS             10  //长裙
#define PROP_OTHERS              0  //另类

#endif
