// paper_seal.c

inherit COMBINED_ITEM;

void create()
{
	set_name("桃符纸", ({"paper seal", "seal", "paper"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
    set("long","这是张用来画符的符纸，具有封存法力的功用。
指令格式：scribe <符咒名称> on <物品名称>

在画符用的桃符纸(paper seal)上画符。在你画符之前，你必须
激发八卦咒

注：画符会消耗若干气(要咬破手指用鲜血画)与神。

目前你能画的符咒有：
              逃命符(escape)
              神霄电法符(light)
              休战符(peace)
              五瘟符(poison)
              神霄雨法符(rain)
              神霄雷法符(thunder)
              神霄风法符(wind)

");
	set("unit", "叠");
    set("base_unit", "张");
	set("value", 10);
	}
set_amount(1);
	setup();
}

