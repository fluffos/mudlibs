// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "寺间小路");
        set("long", @LONG
你踏实着寺院中落叶，走在院内的石路上，眼见庭中一株公孙树上一片黄
叶缓缓飞落。　
LONG
        );
        set("outdoors", "大理");
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"dadian",
            "south" : __DIR__"nianhuasi",
        ]));
       
        set("no_clean_up", 0);

        set("coor/x",-200);
  set("coor/y",-420);
   set("coor/z",10);
   setup();
}

void init()
{
        add_action("do_shoot", ({"shoot", "she"}));
}
int do_shoot(string arg)
{
        object me = this_player();
        int level, jinglicost;

        level = me->query_skill("finger", 1);
        if (arg == "leaf" || arg == "ye" || arg == "huangye"|| arg == "luoye") {
                jinglicost = level / 3 + random(level / 3);
                if (me->query("jingli") <= jinglicost) {
                        write("你太累了，先歇歇吧！\n");
                        return 1;
                }
		if (me->is_busy()) return notify_fail("你现在很忙。\n");
                if (level < 30) {
                        write("你看着缓缓落下的黄叶，运气于指向落叶射去，却怎么也挤不出指风来。\n");
                        return 1;
                }
                me->receive_damage("jingli", jinglicost);
                if (level <= 100) {
                        write("你运气于指，一缕指风对准一片落叶射去，");
                        if (level < 40) write("落叶似乎微微动了一下。\n");
                        else if (level < 50) write("落叶似乎动了一下。\n");
                        else if (level < 60) write("落叶轻轻动了一下。\n");
                        else if (level < 70) write("落叶被射的晃了一下。\n");
                        else if (level < 80) write("落叶被射得东飘西散，顿了一下又继续飘落。\n");
                        else if (level < 90) write("落叶被射的弹起来，反向上升起好多，然后继续飘落。\n");
                        else write("“嗤”地一声轻响，一片树叶被你指风击向天空，然后继续缓缓飘落。\n");
                        me->improve_skill("finger", me->query("int"));
                        if (!random(5)) message("vision", "$N对着空中指指点点，不知在做什么。\n", me, ({ me }));
                }
                else {
                        write("只见漫天黄叶，片片飞舞，你不由的痴了！\n");
                                        }
                return 1;
        }
        return notify_fail("你要谋杀谁？\n");
}
