// zhihuan.c
// 指环
#include <ansi.h>
#include <armor.h>
inherit FINGER;
inherit F_UNIQUE;
void create()
{
       set_name(HIW"铁指环"NOR, ({ "zhi huan" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "支");
               set("long", "这是一支铁指环，是峨嵋派掌门的信物。\n");
               set("value", 100000);
               set("unique", 1);
               set("material", "steel");
               set("armor_prop/armor", 5);
               set("armor_prop/parry", 5);
}
       setup();
}

void init()
{
        add_action("do_stop", "stop");
}

int do_stop(string arg)
{
        object me = this_player();
        object ob;
        if (!arg) return notify_fail("你要劝解谁？\n");
        ob = present(arg, environment(me));
        if (!ob) return notify_fail("你要劝解谁？\n");
        if(ob==me) return notify_fail("。。。直接用 halt 指令不就好了？\n");
        if(!userp(ob) || !ob->is_fighting(me)) return notify_fail("你就别多管闲事了。\n");
        if (!ob) return notify_fail("找不到这个人。\n");
message_vision(HIY"$N亮出峨嵋掌门铁指环，向$n道：“我手下留情，难道你不知道麽？”\n",me,ob);
        message_vision(HIW"$N说完便向後退开，留下$n愣在那边。\n"NOR,me,ob);
        me->remove_all_enemy();
        ob->remove_all_enemy();
        return 1;
}
