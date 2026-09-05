// paper.c
//给韦小宝的信
inherit ITEM;

void create()
{
        set_name("书信",({"shu xin","letter"}));
        set_weight(100);
        set("recipients","韦小宝");
        set("sender","方怡");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long",
"这是一封给韦小宝写的信，信封发出淡淡的幽香。\n");
                set("material", "paper");
        }
}
