#include <ansi.h>

inherit ITEM;

int do_look(string);

void create()
{
        set_name(MAG"通天宝镜"NOR, ({"tongtian jing", "mirror", "tongtian"}));
        set("long",
WHT"    这是一面神奇的宝镜，传说是某位大神神游凡间的时候不\n"
"小心遗落下来的。\n\n"HIY"听说通过它能够查看(use)你的隐藏属性。\n\n"NOR
);
        set("unit","面");
        set("value",0);
        set_weight(10);

        setup();
}

void init()
{
        add_action("do_look", "use");
}
int query_autoload()
{
        return 1;
}

void owner_is_killed()
{
        destruct(this_object());
}

int do_look(string arg)
{
        object me=this_player();

        if( ! arg || ( arg != "mirror" && arg != "tongtian jing" && arg != "tongtian" ) )
                return notify_fail("你想做什么？\n");

        message_vision("$P战战兢兢地拿起"MAG"通天宝镜"NOR"，向里面看去...\n", me);
        tell_object(me, "宝镜里云雾缭绕，过了好一会才显现出：\n");
        write("你的容貌："HIY + me->query("per") + NOR"\n你的福缘："HIY + me->query("kar") + "\n\n"NOR);
        message_vision(HIY"\n天空中一阵声响，天神探出头来，收回了\n"
                + me->query("name") + "(" + me->query("id") +")的"
                + MAG"通天宝镜"NOR + "。\n\n", environment());
        destruct(this_object());
        return 1;
}

