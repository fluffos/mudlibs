#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
        set_name( HIC"银令牌"NOR, ({ "silver ling", "ling" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", HIC"一块纯银打造的令牌，上面雕着一只凤凰，\n
凤凰的眼珠镶嵌着一颗"HIW"水晶石"HIC",似乎可以按(an)动!\n");
                set("material", "stone");
                set("armor_prop/armor", 10);
        }
        setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_an","an");
}
int do_an(string arg)
{
object jade,me;
        if( !living(this_player()))     return 0;
if ((!arg)||((arg!="水晶石")&&(arg!="眼珠"))) return notify_fail("你要按什么？\n");
me = this_player();
        jade = new(__DIR__"silver.c");
        jade->move(me);
message_vision(HIY"$N按动凤眼，只听嚓的一声,"+HIC+"银令牌"+HIY+"弹开，变成一柄"NOR WHT"银剑"HIY"。\n"NOR,this_player());
        destruct(this_object());

return 1;
}

