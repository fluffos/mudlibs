#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_AUTOLOAD;
inherit F_SAVE;
void setup()
{}
void create()
{
           set_name(HIY"手术刀"NOR, ({"dao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIW"一把磨的很锋利的手术刀。\n"NOR);
                set("value", 800000);
                set("no_get", 1);
                set("no_drop", 1);
                set("no_steal", 1);
                set("unit", "柄");
                set("material", "steel");
                set("rigidity", 300);
                set("auto_load", 1);
                set("wield_msg", HIG"$N拿出一把亮晃晃$n，好像要给人做手术的样！\n"NOR);
                set("unwield_msg", HIR"$N将$n瘪在腰间。\n"NOR);
        }
        init_blade(100);
        seteuid(getuid());
        setup();
}
void init()
{
       add_action("do_ge", "ge");
}

int do_ge(string arg)
{
    object me;
    string gender;
    int i;
    object *ob,obj;

    me = this_player();
     if ( !obj = present(arg,environment(me)))
        return notify_fail("在这里没有对象: 找不到"+arg+"\n");
      
    message_vision(HIW"$N决定给"+obj->query("name")+"做变性手术，你心里有一种说不出的感觉 !\n" NOR, me);
    obj->start_busy(5);
    if (obj->query("gender")=="男性")
    {
    obj->set("gender","女性");
    }
    else {
    obj->set("gender","男性");
    }
    ob = all_inventory(environment(me));
    for(i=0; i<sizeof(ob); i++) {
           if( !living(ob[i]) || ob[i]==me ) continue;                                
           message_vision(ob[i]->query("name")+"心头一荡，脸上露出羡慕微笑。\n",me);
		}
          message_vision(obj->query("name")+"心头一荡，脸上不自禁的露出微笑，终于可以过正常人的生活。\n",me);
	  return 1;
}

string query_autoload()
{
     return query("name");
}
void autoload()
{}
