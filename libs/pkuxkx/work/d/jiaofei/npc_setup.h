#include <ansi.h>

string npc_type = "xingxiu";

string* npc_colors = ({
	WHT,
	HIW,
	GRN,
	HIG,
	BLU,
	HIB,
	YEL,
	HIY,
	RED,
	HIR
});

int set_xingxiu(object me, int level, int armed);
int set_baituo(object me, int level, int armed);
int set_shenlongjiao(object me, int level, int armed);
int set_riyuejiao(object me, int level, int armed);
int set_dalunsi(object me, int level, int armed);

mapping npc_family_setup = ([
"xingxiu":(:set_xingxiu:),
"baituo":(:set_baituo:),
"shenlongjiao":(:set_shenlongjiao:),
"riyuejiao":(:set_riyuejiao:),
"dalunsi":(:set_dalunsi:)
]);



int set_xingxiu(object me, int level, int armed)
{
	me->set("title","星宿派");
	return me->set_xingxiu(me,level,armed);
}
int set_baituo(object me, int level, int armed)
{
	me->set("title","白陀派");
	return me->set_baituo(me,level,armed);
}
int set_shenlongjiao(object me, int level, int armed)
{
	me->set("title","神龙教");
	return me->set_shenlongjiao(me,level,armed);
}

int set_riyuejiao(object me, int level, int armed)
{
	me->set("title","日月教");
	return me->set_riyuejiao(me,level,armed);
}

int set_dalunsi(object me, int level, int armed)
{
	me->set("title","大轮寺");
	return me->set_dalunsi(me,level,armed);
}