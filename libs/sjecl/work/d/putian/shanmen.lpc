// Room: /d/putian/shanmen.c
// Lklv 2001.9.11

#include <ansi.h>
inherit ROOM;
string look_gate();
void create()
{
        set("short", "山门");
        set("long", @LONG
上得石阶，眼前出现两扇高大的红门和高高的院墙。墙边松柏翠绿，门前有几
个身着青布僧衣的僧人在低着头扫地。仔细看，个个身材魁梧，体格健壮。原来这
里就是有名的少林别院，被世人称为南少林的福建莆田少林寺。山门上方高悬着一
块烫金木匾(bian)。
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"road08",
                "east" : __DIR__"xl3",
                "west" : __DIR__"xl2",

        ]));
        set("item_desc", ([
        	"gate" : (: look_gate :),
		"bian" :  HIY"
             ※※※※※※※※※※※※※※※※※※※※
             ※※※※　                      ※※※※
             ※※※※     莆  田  少  林     ※※※※
             ※※※※                        ※※※※
             ※※※※※※※※※※※※※※※※※※※※\n"NOR,
        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 2,
        ]));

        set("outdoors", "福州");
        setup();
}

void init()
{
        add_action("do_knock", "knock");
}

int close_gate()
{
        object room;

        if(!(room = find_object(__DIR__"qianyuan")))
                room = load_object(__DIR__"qianyuan");
        if(objectp(room)){
                delete("exits/south");
                message("vision", "乒地一声，里面有人把大门关上了。\n",this_object());
                room->delete("exits/north");
                message("vision", "壮年僧人上前把大门关了起来。\n", room);
        }
        else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("大门已经是开着了。\n");

        if (!arg || (arg != "gate" && arg != "south"))
                return notify_fail("你要敲什么？\n");

        if(!( room = find_object(__DIR__"qianyuan")) )
                room = load_object(__DIR__"qianyuan");
        if(objectp(room)){
                set("exits/south", __DIR__"qianyuan");
                message_vision("$N提起门环在门上轻轻叩了叩，吱地一声，一位僧人打开大门用锐利的目光上下打量着$N。\n",this_player());
                room->set("exits/north", __FILE__);
                message("vision", "外面传来一阵敲门声，壮年僧人应声上前把大门开。\n", room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }
        return 1;
}

int valid_leave(object me, string dir)
{
        if ( dir != "south" )
                return ::valid_leave(me, dir);

        if (me->query("gender") == "女性" && !me->query("luohan_winner")){
                return notify_fail("壮年僧人说道：这位女施主还是请回罢，本寺从不接待女客。\n");
        }

        if (me->query("family/family_name") == "少林派"){
                message_vision("壮年僧人侧身让开，说道：师兄辛苦了，请进。\n", me);
                return ::valid_leave(me, dir);
        }
        if (present("yingxiong ling", me)){
                message_vision("壮年僧人合十为礼，侧身让开，说道：原来是贵客驾到，请进请进！\n", me);
                return ::valid_leave(me, dir);
        }
        if (me->query("shen") <= -100000 && !me->query("luohan_winner")){
                return notify_fail("壮年僧人立时从身畔挚出一把雪亮的戒刀来，把明晃晃的\n"
                        "刀尖对准你的胸口，横眉怒目地说道：你等邪魔外道，还不给我滚开！\n"
                        "以后再敢走近少林一步，我立时就斩断你们的狗腿！\n");
        }
        return ::valid_leave(me, dir);
}

string look_gate()
{
        return "一道三丈来高的朱红杉木包铜大门。\n";
}
