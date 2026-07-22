#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(WHT"白玫瑰"NOR,({ "rose", "meigui" }) );
        set_weight(500);
        if( clonep() )
        	set_default_object(__FILE__);
        else {                            
        	set("unit","朵");
                set("material", "cloth");
          set("value",150);
              set("female_only", 1);
        	set("armor_prop/armor", 1);
            set("long", "这是一束白玫瑰,洁白芬芳,象征着纯洁的爱情。\n");
            set("wear_msg", "$N轻轻摘下一朵插在发鬓边，"WHT"白玫瑰"NOR"分外的纯净透明,映照出一张秀美绝伦的脸！\n");
            set("remove_msg", "$N摘下发边的"WHT"水晶玫瑰,小心翼翼的把它收好.\n"NOR);
	}
        setup();
}
