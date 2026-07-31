// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
        set_name("骷髅头骨", ({ "kulou tougu" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "白骨惨惨,每个头骨的顶上都有五个指孔..\n");
        }
}


