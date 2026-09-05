//

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("军舰操作指南", ({ "chaozuo zhinan", "zhinan" }));
	set("long", 
		HIG"驾驶室操作方法：\n"
+HIW"qimao"+HIB": 起锚出发;\n"
+HIW"paomao"+HIB":抛锚停船;\n" 
+HIW"movee"+HIB": 驾驶船只向东（右）行驶；\n"
+HIW"moves"+HIB": 驾驶船只向南（下）行驶；\n"
+HIW"movew"+HIB"：驾驶船只向西（左）行驶；\n"
+HIW"moven"+HIB"：驾驶船只向北（上）行驶．\n"
+HIW"jiuhuo"+HIB":救火.\n"
+HIW"view "+HIB"：浏览海域．\n"
+HIG"炮舱操作方法：\n"
+HIW"aime"+HIB": 将炮口瞄准点向东（右）移动；\n"
+HIW"aims"+HIB": 将炮口瞄准点向南（下）移动；\n"
+HIW"aimw"+HIB"：将炮口瞄准点向西（左）移动；\n"
+HIW"aimn"+HIB"：将炮口瞄准点向北（上）移动．\n"
+HIW"load"+HIB": 将炮弹放入炮膛．\n"
+HIW"fire"+HIB": 开炮．\n"
+HIW"reset"+HIB":炮口瞄准点复位（回到海域中心)\n"
+HIW"check"+HIB":得到船体损害情况．\n"
+HIW"jiuhuo"+HIB":救火\n"
+HIW"view "+HIB"：浏览海域．\n"
+HIG"图例：\n▲"+HIB"：中方船只(闪烁的是本船位置)；\n"
+HIG"■"HIB+"：日方船只\n"
+HIR"★"HIB+": 炮弹落下的位置（５秒种后会自动消失）\n"
+HIW"¤"HIB+": 炮口瞄准点(闪烁)\n"
+MAG"⊙"HIB+": 炮口瞄准点与目标物体重合\n"
+HIR"¤"HIB+": 炮口瞄准点超出海域范围\n"
HIG"船只由完好无损到沉没颜色分别表示为：\n"
+HIG"█"+HIY"█"+HIC"█"+HIW"█"+HIM"█"+HIR"█"+BLU"█\n"NOR,);
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "paper");
		set("unit", "本");
		set("value", 200);
	}
	setup();
}
