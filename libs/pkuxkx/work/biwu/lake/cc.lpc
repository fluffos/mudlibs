
inherit "/biwu/biwuroom";

#include <ansi.h>

void create()
{
	set("short", "湖心岛");
	set("long", @LONG
一座五层的高楼耸立在小岛上，这里戒备森严，气氛阴冷，寻常人等不能接近此处。即便是江湖豪客，
没有帖子，也不敢轻易涉足。这是著名的紫鲨帮的总舵。一杆巨大的旗杆上挂着一面大红旗帜，上绘
似龙非龙的图腾。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		  "west" : __DIR__"bw2",
		  "east" : __DIR__"be2",
		]));
	set("no_clean_up", 0);
	set("flag","紫鲨旗");
	set("default_flag_hp",10);
	set("flag_hp",10);
    set("objects", ([
        "/biwu/jieshuo" : 1,
        ]));		
    set("enter_person",0);
	setup();
}

void init()
{
    object pl=this_player();
    if(query("enter_person") < 1 && pl->query("id")!="jieshuo yuan")
    {
        write(HIB"暗地里忽然有人示警，显然你已经被发现了。一片蓝光向你袭来，想必是淬毒的暗器。\n"NOR);
        write(HIR"你暗道一声：不好！但是已经太迟了，你身受重伤。\n"NOR);
        add("enter_person",1);
        pl->set("eff_qi",pl->query("max_qi")/3);
        pl->set("qi",pl->query("max_qi")/3);
        pl->set("neili",0);
        pl->start_busy(10);
    }
    ::init();
}