// allow-letter.c 手諭

inherit ITEM;

void create()
{
        set_name("手諭", ({"shou yu", "yu", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","這是一封由方丈簽發的手諭，憑此可自由進入藏經閣二樓研習上乘武功。\n");
		set("no_drop", "這樣東西不能離開你。\n");
                set("material", "paper");
        }
}

