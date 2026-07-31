// Room: shanmen.c

inherit ROOM;
#include <wanted.h>
#include <ansi.h>

void create()
{
	set("short", "大轮寺山门");
	set("long", @LONG
阶梯尽处是座高大华美的建筑，两扇朱红嵌铜钉的大门(gate)，门上的包
金铜钉被擦的亮闪闪的。高约十几丈的门楼及山门两侧均为白玉砌成，上有精
美的浮雕，中间横匾黑底金字漆着
                        ※※※※※※※※※
                        ※  大  轮  寺  ※
                        ※※※※※※※※※                
三个字，显得气派非凡。门两旁各有一只神兽镇门。远处隐约传来山寺钟
鸣，惊起几只寒鸦在树梢间纷飞，方有脱离世俗的感觉。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"shanlu7",
	]));
        set("item_desc", ([
                "gate": "一扇红漆大门上有两个金环在阳光照耀下格外耀眼。似乎可以(knock)敲门。\n",
                "门": "一扇红漆大门上有两个金环在阳光照耀下格外耀眼。似乎可以(knock)敲门。\n",
        ]) );

        set("outdoors", "雪山");

	set("coor/x",-280);
  set("coor/y",170);
   set("coor/z",30);
   setup();	

}
void init()
{
       	add_action("do_knock", "knock");
}

void wantopen(object me)
{
	object	waiter;
	object	room;

	seteuid(geteuid());
	room = find_object(__DIR__"guangchang");
	waiter = new(__DIR__"npc/fanseng");
	message_vision(HIY"吱的一声，门向里开了。\n\n"NOR,me);
       	message_vision(HIY+waiter->query("name")+ "走了出来。\n"NOR,me);
	if( room )  tell_room(room,HIY+waiter->query("name")+"赶忙上前吱的一声把门打开，迎了出去。\n"NOR);
	waiter->move(this_object());
	message_vision(HIY+waiter->query("name")+"说道：这位"+RANK_D->query_respect(me) + "光临大轮寺,请入内礼佛。\n"NOR,me);
	call_out("closedoor", 10, me);
}



int do_knock(string arg)
{
	object room, me, troom ,obj;
	troom = this_object();
	obj = present("hufa lama", troom);
	me = this_player();        

	if( arg=="gate" || arg == "门") {
		if(query("exits/northup")) {
		if(obj) {
			message_vision(HIY+obj->query("name")+"白了你一眼道：“门已经开着你还敲？\n"NOR, me);
			return 1;
		}
		else {	message_vision(HIY"你突然发现原来门是开着的，直接进去就行了。\n"NOR, me);
			return 1;
		}
	}
		message_vision(HIY "$N走到门前，轻轻地扣了两下门环。\n" NOR, me);
		set("long", @LONG
阶梯尽处是座高大华美的山门，一扇朱红嵌铜钉的大门敞开着，门上的包
金铜钉被擦的亮闪闪的。高约十几丈的门楼及山门两侧均为白玉砌成，上有精
美的浮雕，中间横匾上金漆着


                        ※※※※※※※※※
                        ※  大  轮  寺  ※
                        ※※※※※※※※※                

三个字，显得气派非凡。门两旁各有一只神兽镇门。远处隐约传来山寺钟
鸣，惊起几只寒鸦在树梢间纷飞，方有脱离世俗的感觉。
LONG
	);
		set("exits/northup", __DIR__"guangchang");
	        if( room = find_object(__DIR__"guangchang") ) {
			tell_room(room,HIY "你听到当当两声，有人在门外敲门。\n" NOR);
			room->set("exits/southdown", __FILE__);
			room->set("item_desc", ([
                		"gate": "两扇红漆的大门向两侧敞开着。\n",
                		"门": "两扇红漆的大门向两侧敞开着。\n",
        		]) );
		}
		me->start_busy(1);
		call_out("wantopen", 2, me);
		
        }
	else {
		write("你要敲什么？\n");
	}
                return 1;
}

void closedoor(object me)
{
	object obj, room, troom;

	troom = this_object();
if(!me) return;
	if(environment(me) != troom) {
	        room = find_object(__DIR__"guangchang");
		obj = present("hufa lama", troom);
		if(obj) {
			tell_room(troom,HIY+obj->name() + "走进大轮寺，轻轻地把门关上了。\n"NOR);
			destruct(obj);
			delete("exits/northup");
			if(room) {
				room->delete("exits/southdown");
				room->set("item_desc", ([
                	"gate": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                	"门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
        			]) );
			}
	set("long", @LONG
阶梯尽处是座高大华美的山门，一扇朱红嵌铜钉的大门敞开着，门上的包
金铜钉被擦的亮闪闪的。高约十几丈的门楼及山门两侧均为白玉砌成，上有精
美的浮雕，中间横匾上金漆着


                        ※※※※※※※※※
                        ※  大  轮  寺  ※
                        ※※※※※※※※※                

三个字，显得气派非凡。门两旁各有一只神兽镇门。远处隐约传来山寺钟
鸣，惊起几只寒鸦在树梢间纷飞，方有脱离世俗的感觉。
LONG
	);
		}
	}
	else
		call_out("closedoor", 15, me);
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
