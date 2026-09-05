// cloth3.c
//
// create by zine 30 Aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
int check();
void create()
{
        set_name("皮甲", ({ "pi jia", "jia" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 25);
        }
          set("paint/name", "十夫长");
          set("paint/id", "shifu zhang");
          set("paint/long", "他是桑坤帐下的一名斥候。\n");
          set("paint/age", 35);
          set("paint/shen", 1);
          set("paint/class", 0);
          set("paint/gender",  "男性");
          set("paint/title", NOR);
          set("paint/family", 0);

          setup();
          call_out("check",1);
}

int check()
{
    object me,ob=this_object();
	int complex;
	if (environment(ob))
	{
		me=environment(ob);
	}
    if (!me)
    {
        remove_call_out("check");
        call_out("check",2);
        return 1;
    }
    else if (!me->query_temp("shediaoquest/jdfm/lie_kouling"))
    {
        remove_call_out("check");
        call_out("check",2);
        return 1;
    }
	else if (!ob->query("equipped"))
	{
		remove_call_out("check");
        call_out("check",2);
        return 1;
	}
	else if (me->query("shediaoquest/jdfm"))
	{
		remove_call_out("check");
        call_out("check",2);
        return 1;
	}
    else
    {
		complex=DISGUISE_D->query_complex(this_object(), me);
        me->set_face("copy", query("paint/name"), "", complex,
                     (["long":query("paint/long"),
                         "age":query("paint/age"),
                         "title":query("paint/title"),
                         "family":query("paint/family"),
                         "gender":query("paint/gender")]));
        message_vision("穿上这件$N后，再有心模仿一下，活脱脱就是一个十夫长。\n",ob);
        return 1;
    }
}


