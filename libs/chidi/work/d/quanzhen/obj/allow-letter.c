// allow-letter.c 手谕

inherit ITEM;

void create()
{
        set_name("手谕", ({"shou yu", "yu", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","这是一封由掌教签发的手谕，凭此可自由进入藏经阁二楼研习上乘武功。\n");
		set("no_drop", "这样东西不能离开你。\n");
             	set("no_give", "这样东西不能随便给人。\n");
              set("material", "paper");
        }
}

