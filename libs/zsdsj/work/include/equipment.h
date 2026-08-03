/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : /include/equipment.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#define PART_ID			0	// 部位代號
#define PART_AMOUNT		1	// 此部位可裝備的裝備數量
#define PART_USER_AMOUNT	2	// 此裝備同時可以被多少人裝備
#define PART_OUTSIDE		3	// 此裝備是否為身體外之裝備
#define	PART_CONFLICT		4	// 部位的衝突資料(例如 "鋼彈裝甲" 不能和 "座騎"/"左右手" 同時裝備


// 裝備部位定義			({ 代號, 	可裝備數量, 	可同時裝備人數,	是否為外部裝備,	裝備部位衝突 })

#define EQ_FINGER		({ "finger", 	2, 		1, 		0,		({})		})
#define EQ_MOUNT		({ "mount",	1,		1, 		0,		({})		})
#define	EQ_BROOCH		({ "brooch",	1,		1, 		0,		({})		})
#define EQ_EYE			({ "eye",	1,		1,		0,		({})		})
#define EQ_NOSE			({ "nose",	1,		1,		0,		({})		})
#define EQ_HAND			({ "hand",	2,		1,		0,		({ "twohand" }) })
#define EQ_TWOHAND		({ "twohand",	1,		1,		0,		({ "hand" })	})
#define EQ_BODY			({ "body",	1,		1,		0,		({})		})
#define EQ_HEAD                 ({ "head",      1,              1,              0,              ({})            })

