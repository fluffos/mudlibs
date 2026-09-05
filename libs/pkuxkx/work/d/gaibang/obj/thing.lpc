//newmap Zine Nov 11 2010
#include <ansi.h>
inherit ITEM;

void create()
{
    string* name=({"小碗","折扇","羽毛","马桶","肚兜","毛笔","包袱","布鞋","长袍","铁锅","蒸笼","枕头","马鞭","假牙","书本","锤子","玉蒲团"});
    string* color=({WHT,RED,YEL,GRN,BLU,MAG,CYN});
    set_name( color[random(sizeof(color))]+name[random(sizeof(name))]+NOR , ({"little thing","thing","case"}));
    set_weight(500);
    set("unit", "件");
    set("value", 10);
    set("long","这是一张"+this_object()->query("name")+"。\n");
  
    setup();
    call_out("dest",900);
}

int dest()
{
    object ob=this_object();
    if (ob)
    {
        destruct(ob);
    }
    return 1;
}

