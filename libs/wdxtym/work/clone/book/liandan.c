#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
        set_name(WHT "「丹王神篇」" NOR, ({  "liandan book", "shu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", WHT "丹王把毕生的炼丹术技术写在了这本日记里。"NOR"\n");
                set("material", "paper");
                set("value", 1000);
				set("no_drop", "这样东西不能离开你。\n");
				set("no_put",1);
				set("no_sell",1);
				set("no_save",1);
				set("no_give",1);
				set("nopaimai",1);
              //  set("no_sell", "嘿，无价之宝你也丢？");
                set("skill", ([
                        "name" : "liandan-shu",
                        "jing_cost" : 40,
                        "difficulty" : 50,
                        "max_skill" : 500,
                        "min_skill" : 0,
                ]));

                set("can_make", ([
                        "liuhe"    : 80,         // 六合返精散
                        "qingxin"  : 100,        // 清心定神散
                        "zhending" : 150,        // 固元镇定散
                        "dieda"    : 80,         // 跌打伤愈膏
                        "huojin"   : 100,        // 活筋舒血丸
                        "tongmai"  : 150,        // 贯气通脉丹
                        "jiedu"    : 100,        // 牛黄解毒丸
			"zaohua"  : 230,		 // 造化丹
			"puti-zi"  : 250,		 // 菩提子
			"tianxiang"	:280,		 // 天香玉露
                ]));
        }
        setup();
}