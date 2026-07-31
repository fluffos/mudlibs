inherit ITEM;
void create()
{
    set_name("骸骨", ({ "skeleton" }));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "具");
        set("long",
           "你发现这具骸骨下面好象有点什么东西。\n");
        set("value", 0);
        set("no_get","这东西一碰就散，还是别拣吧！\n");
    }
}
