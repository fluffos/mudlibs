// Created By Jingxue 2007/06/16 For 幻想群英 The Fantasy of the Hero

// Last modified By Jingxue 2007/06/26
// 重新规划防具，减少了冗余的防具，统一了防具的属性限制

#include "ansi.h"

#ifndef __ARMOR__
#define __ARMOR__


#define ARMOR_DEFAULT_DUR	50	//防具缺省耐久

/* 幻想群英 ********************** 无敌分隔线 ********************** 幻想群英 */
// 共12类，其中CLOTH和SKIRT为普通的衣服，基本没有防御力，主要是装饰作用
// CLOTH一般为男用，SKIRT为女用，防御都为5

// 其余10类为常用装备，10件最低防御力合计为100。
/******************************************************************************/
#define CLOTH			"/std/armor/cloth"		//衣服
#define SKIRT			"/std/armor/skirt"		//长裙

#define HEAD			"/std/armor/head"		//头盔
#define NECK			"/std/armor/neck"		//项链
#define ARMOR			"/std/armor/armor"		//护甲
#define SURCOAT			"/std/armor/surcoat"		//披风
#define WAIST			"/std/armor/waist"		//护腰
#define WRISTS			"/std/armor/wrists"		//护腕
#define SHIELD			"/std/armor/shield"		//盾牌
#define FINGER			"/std/armor/finger"		//戒指
#define HANDS			"/std/armor/hands"		//手套
#define BOOTS			"/std/armor/boots"		//鞋子
/******************************************************************************/
#define TYPE_CLOTH		"cloth"
#define TYPE_SKIRT      	"skirt"

#define TYPE_HEAD		"head"
#define TYPE_NECK		"neck"
#define TYPE_ARMOR		"armor"
#define TYPE_SURCOAT	       	"surcoat"
#define TYPE_WAIST		"waist"
#define TYPE_WRISTS		"wrists"
#define TYPE_SHIELD		"shield"
#define TYPE_FINGER		"finger"
#define TYPE_HANDS		"hands"
#define TYPE_BOOTS		"boots"

#endif
