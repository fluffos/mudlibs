// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "阎罗殿");
        set("long", @LONG
经过一路走来的黑暗，乍进门来，牛油巨烛耀眼的光芒让你一阵炫晕，
定下神来，鎏金镶玉的王座上端坐着一位黑面君王，正是掌握六道轮回，
万物来世的阎罗王。两侧四名判官，各捧生死簿册，牛头，马面，各拿武
器，横眉怒目，当堂责罚人犯。世上一切蠃虫，羽虫，毛虫，鳞介无不由此受判。
LONG
        );
        set("objects", ([
                __DIR__"npc/yanwang":1,
		__DIR__"npc/panguan2" : 4,
		__DIR__"npc/niutou" : 3,
		__DIR__"npc/mamian" : 3,
        ]) );
	set("coor/x",-1020);
	set("coor/y",-30);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
}
void init()
{
	
	remove_call_out("letgo");
	call_out("letgo",15,this_player());	
}

void letgo(object me)
{
	object room;
me=this_player();
	if(!me || environment(me) != this_object()) return;
	message_vision("\n\n\n阎王爷长叹一口气：＂算了，算了，让$N四处逛逛，
知道这里是赏罚分明，只要$N来世再也不敢胡作非为就可以了！＂\n\n",me);
	message_vision("\n\n一阵冷风吹散了$N的阴魂．．．\n\n",me);
	room = load_object(__DIR__"dizang");
	if(objectp(room))  me->move(room);	
} 
