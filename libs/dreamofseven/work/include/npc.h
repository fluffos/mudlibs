// npc.h -- Aug tmr reaction macros + compat on this lib's NPC (KB 04 6.16 Also, 2026-10-27)
// The archive never shipped this header; tmr NPCs #include <npc.h> and call set_race/set_attr.

#ifndef __NPC_H__
#define __NPC_H__

#define F_BANDIT                "/feature/npc/bandit.lpc"
#define F_FIGHTER               "/feature/npc/fighter.lpc"
#define F_SOLDIER               "/feature/npc/soldier.lpc"
#define F_VILLAGER              "/feature/npc/villager.lpc"

#undef F_VENDOR
#define F_VENDOR                "/feature/npc/vendor.lpc"

#ifndef SKILL_MAX_POINT
#define SKILL_MAX_POINT         100
#endif

inherit NPC;
inherit "/feature/npc/aug_compat.lpc";

#endif
