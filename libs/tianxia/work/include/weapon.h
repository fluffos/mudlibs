// weapon.h

#ifndef __WEAPON__
#define __WEAPON__

#define DEFAULT_WEAPON_LIMB "右手"

#define TWO_HANDED	1	// 必须双手用的兵器
#define SECONDARY	2	// 左右手均可用的兵器
				// 其它为必须右手使用的兵器。

#define EDGED		4	// 锋利的
#define POINTED		8	// 尖锐的
#define LONG		16	// 长的

#define AXE			"/std/weapon/axe"
#define BLADE			"/std/weapon/blade"
#define DAGGER			"/std/weapon/dagger"
#define DHAMMER			"/std/weapon/dhammer" // by Find. 双手锤。
#define HAMMER 			"/std/weapon/hammer"
#define SPEAR			"/std/weapon/spear" // Modified by Find
#define SWORD			"/std/weapon/sword"
#define STAFF			"/std/weapon/staff"  // by dicky
#define STICK                   "/std/weapon/stick"  // by dicky
#define THROWING		"/std/weapon/throwing"  // by dicky
#define WHIP			"/std/weapon/whip"      // by dicky

#define F_AXE			"/std/weapon/_axe"
#define F_BLADE			"/std/weapon/_blade"
#define F_DAGGER		"/std/weapon/_dagger"
#define F_SPEAR			"/std/weapon/_spear"
#define F_HAMMER 		"/std/weapon/_hammer"
#define F_SWORD			"/std/weapon/_sword"
#define F_ZHEN			"/std/weapon/_zhen"
#define F_STAFF			"/std/weapon/_staff"
#define F_STICK                 "/std/weapon/_stick"
//#define F_THROWING		"/std/weapon/_throwing"
#define F_WHIP			"/std/weapon/_whip"

#endif
