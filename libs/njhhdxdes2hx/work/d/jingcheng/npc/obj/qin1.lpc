// qin1.c
// Made by ysgl (1997.10.23)

#include <ansi.h>

inherit ITEM;

mapping music = ([
        "maiden lake": ({
                "$N的琴声铮铮淙淙，有如流水一般 ....\n",
                0, 0,
                "琴声越来越急，像山泉从百丈高的山壁充激而下 ....\n",
                "水花四溅，山壁上的树木因为这种律动而颤抖著 ....\n",
                0,
                "山泉继续在陡峭的深谷中奔流，轰轰的巨响掩盖\了一切的天籁 ....\n",
                0, 0,
                "忽然，「叮」地一声，琴声和缓了下来，开始有一种平和中正的感觉 ...\n",
                0,
                "有如河流在一片水草中缓缓流入一个布满雾气的湖泊 ...\n",
                0,
                "湖边是一片柔绿色的草地，好静，好诗意 ...\n",
                0,
                "$N的琴声渐渐低得听不见了 ...\n"
		}),
]);

int play_qin(object me, mixed *melody, int phase);

void create()
{
        set_name("焦尾琴", ({ "jiaowei qin" , "qin" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "具");
                set("long", "一具深褐色的焦尾琴，看起来相当名贵。\n");
                set("value", 1300);
                set("weight", 8000);
        }
}

void init()
{
        add_action("do_play", "play");
}

int do_play(string arg)
{
        string name, instrument;

        if( !arg || sscanf(arg, "%s with %s", name, instrument )!= 2 )
                return notify_fail("指令格式：play <曲目> with <乐器>\n");

        if( !id(instrument) ) return 0;
	if( this_player()->query_skill("music",1) < 30 ){
	message_vision("$N取出焦尾琴，盘膝坐下，但是却琴音晦涩，显然技艺不高。\n",this_player());
	return 1;
	}
        message_vision("$N取出一具焦尾琴，盘膝而坐，弹了起来。\n", this_player());
        this_player()->start_busy( (: play_qin, this_player(), music[name], 0 :), 1 );
        return 1;
}

int play_qin(object me, mixed *melody, int phase)
{
        if( phase >= sizeof(melody) ) return 0;

        if( stringp(melody[phase]) )
                message_vision( HIG + melody[phase] + NOR, me);
        else if( functionp(melody[phase]) )
                evaluate(melody[phase], me);
        me->start_busy( (: play_qin, me, melody, phase+1 :), 1);

        return 1;
