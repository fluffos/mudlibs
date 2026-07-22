// practice.c
inherit ROOM;
void create()
{
        set("short", "打坐室");
        set("long", @LONG
这里是天后日常打坐之处。四壁萧然，绝无干碍心思的杂物。
    进入本室需诚心正意，不得有任何私念，树立为本泥塘服务之
宗旨。阿门。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west"  : __DIR__"happy",
        ]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_tiaoshi", "tiaoshi");
}
int do_tiaoshi(string arg)
{
        object me,ob;
        me = this_player();
        me->set_skill("axe",200);
        me->set_skill("bashi-shentong",200);
        me->set_skill("buddhism",200);
        me->set_skill("club",200);
        me->set_skill("cuff",200);
        me->set_skill("dodge",200);
        me->set_skill("duanyun-fu",200);
        me->set_skill("feiyan-huixiang",200);
        me->set_skill("finger",200);
        me->set_skill("force",200);
        me->set_skill("hammer",200);
        me->set_skill("hand",200);
        me->set_skill("huashan-sword",200);
        me->set_skill("king-of-dragon",200);
        me->set_skill("liangyi-jian",200);
        me->set_skill("literate",200);
        me->set_skill("lonely-sword",200);
        me->set_skill("magic",200);
        me->set_skill("mahayana",200);
        me->set_skill("mantian-xing",200);
        me->set_skill("nianhua-zhi",200);
        me->set_skill("parry",200);
        me->set_skill("staff",200);
        me->set_skill("stealing",200);
        me->set_skill("stick",200);
        me->set_skill("strike",200);
        me->set_skill("swimming",200);
        me->set_skill("sword",200);
        me->set_skill("taiji-jian",200);
        me->set_skill("taiji-quan",200);
        me->set_skill("taiji-shengong",200);
        me->set_skill("taoism",200);
        me->set_skill("throwing",200);
        me->set_skill("unarmed",200);
        me->set_skill("whip",200);
        me->set_skill("wudang-jian",200);
        me->set_skill("zuoyou-boji",200);

        me->map_skill("force", "king-fo-dragon");
        me->map_skill("dodge", "tiyunzong");
        me->map_skill("unarmed", "taiji-quan");
        me->map_skill("parry", "taiji-jian");
        me->map_skill("sword", "liangyi-jian");
        return 1;
}
