// xian-dan.c 仙丹

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY"仙丹"NOR, ({"xiandan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", HIY"这是一粒通体朱红色的鲜果。此果生于长白山老林中，几千年才能结实。\n"+
                             "相传为一名万年老仙未得灵徒，每日悲伤呕血于此草之上养育而成。\n"NOR);
                set("value", 900000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();


       me->set_skill("unarmed",80);
       me->set_skill("force",80);
       me->set_skill("dodge",80);
       me->set_skill("sword",80);
       me->set_skill("blade",80);
       me->set_skill("parry",80);
      
      me->set("neili_max", 1200);  me->set("per", 30);
      me->set("neili", 1200);      me->set("kar", 30);
      me->set("con", 30);          me->set("int", 30);
      me->set("str", 30);          me->set("potential", 10000);
      me->set("dex", 30);          me->set("combat_exp",30000);        message_vision(HIW"$N喜极若狂，一口吞下了仙丹。骨骼“喀喇”作响。
\n" NOR, me,);
        

       destruct(this_object());
        return 1;
}


