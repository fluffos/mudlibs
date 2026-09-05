// Modified By  : iszt, 2006-08-16
// moved call_out("dest") to init(), added the prompt in dest()

//add by advent
//取走时有颜色提示
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( "少林英雄令", ({ "yingxiong ling", "ling", "iron" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块用于通行少林寺的铁铸令牌。 由方丈签发，邀各路英雄入寺观礼。\n");
                set("value", 100);
                set("material", "iron");
        }
        setup();
}

void init()
{
	if (!this_object()->query("desting"))
	{
        call_out("dest", 1800);
		set("desting",1);
	}
}

void dest()
{
        tell_object(environment(), HIR"一名僧兵走了过来，取走了你的少林英雄令。\n"NOR);
        destruct(this_object());
}
