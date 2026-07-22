
inherit ROOM;

void create()
{
        set("short", "水井");
	set("long", @LONG
有一眼清澈见底的水井，井旁搭着小土房。有几个妇人在这
里边洗衣，一边说说笑笑，还有个老人，挑着溜满的两桶清水，
颤颤悠悠地朝外走去。你可以在这喝口水。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
                "south" : __DIR__"dongjie3",
	]));

	setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->max_water_capacity();
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在溪边，掬了一口井水喝下，只觉一阵清凉，直透心肺。\n"
            , environment(me), ({me}) );
            write("你掬了一口井水喝下，只觉一阵清凉，直透心肺。\n");
        }
        else write("不怕涨破肚子啊！！！\n");
        return 1;
}

