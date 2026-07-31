// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit ITEM;

string *valid_types = ({
        "sword",
        "blade",
        "staff",
        "hammer",
        "club",
        "whip",
        "throwing",
});

int do_washto(string arg);

void create()
{
        set_name(HIR "大·洗点丹" NOR, ({"wash wan", "wash"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("win_box",1);
		     	set("no_give", 1);
			    set("no_drop", 1);
			    set("no_sell", 1);
			    set("no_get", 1);
			    set("no_steal", 1);
                set("long", @LONG
这是提供给那些洗属性点错误的人一次重新分配先天属性的丹药。
格式为 washto <膂力> <悟性> <根骨> <身法> 例如：washto 50 50 50 50
不可低于30 大于 200
LONG );
                set("yuanbao", 500);
                set("no_sell", 1);
        }
        setup();
}

void init()
{
        object me = this_player();

        if (me == environment())
                add_action("do_washto", "washto");
}


int do_washto(string arg)
{
        int i, j, points;
        int tmpstr, tmpint, tmpcon, tmpdex;
        int str, wux, con, dex;
        object me, weapon;
        mapping my;
        string *sname;
        mixed skill_status;

        me = this_player();

        if (! arg || sscanf(arg, "%d %d %d %d", tmpstr, tmpint, tmpcon, tmpdex) != 4)
                return notify_fail("指令格式：washto <膂力> <悟性> <根骨> <身法>\n" +
                                   "例    如：washto 20 20 20 20\n");

        if (tmpstr > 50 || tmpstr < 30)
                return notify_fail("你所选择的膂力数值要求必须在13和1000之间。\n");

        if (tmpint > 50 || tmpint < 30)
                return notify_fail("你所选择的悟性数值要求必须在13和1000之间。\n");

        if (tmpcon > 50 || tmpcon < 30)
                return notify_fail("你所选择的根骨数值要求必须在13和1000之间。\n");

        if (tmpdex > 50 || tmpdex < 30)
                return notify_fail("你所选择的身法数值要求必须在13和1000之间。\n");

        my = me->query_entire_dbase();
        str = copy(my["str"]);
        wux = copy(my["int"]);
        con = copy(my["con"]);
        dex = copy(my["dex"]);

        points = str + wux + con + dex;
        if (tmpstr + tmpint + tmpcon + tmpdex != points)
                return notify_fail("你所重新选择的属性数值和自己属性的" + points + "总值不一致。\n");
        write("你重新分配的天赋为\n"
              "膂力[" + tmpstr + "]\n"
              "悟性[" + tmpint + "]\n"
              "根骨[" + tmpcon + "]\n"
              "身法[" + tmpdex + "]。\n");

        my["str"] = tmpstr;
        my["int"] = tmpint;
        my["con"] = tmpcon;
        my["dex"] = tmpdex;

        me->set("gift/washed", 1);

        write("你重新分配你的属性成功，请输入指令(score)查看。\n");
        destruct(this_object());
        return 1;
}

