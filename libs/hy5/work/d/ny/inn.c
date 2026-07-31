//inn.c
#include <room.h>

#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
	set("coor",({-20,4750,10}));
	set("short",CYN"有一间客栈"NOR);
	set("long",
"你现在正站在宁远南边的一家小客栈里，这家客栈虽小，却是方圆五百里内最负盛名的一家\n"
"，客栈的主人据说是一位云游四海的仙人，如果你的福缘深厚的话，也许可以在这里遇到他\n"
"。除此之外，来自各地的旅人都喜欢聚集在这里交换旅途上的见闻，你也可以在这里打听到\n"
"许多有趣的消息。靠近门口的地方有一块乌木雕成的招牌(sign)。西北边有一个红木门(doo\n"
"r)，门上泛著一层白色的光晕，一种令人感觉很有力量，又很柔和的光芒。\n"
);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);


	
	set("exits", ([
        	"east"      : __DIR__"square",
        	"up"        : __DIR__"inn_2f"
 ]) );

        set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/wt" : 1,
]));


	
	
	setup();

}

string look_sign(object me)
{
	if( wizardp(me) )
   return "招牌写著：有一间客栈。旁边一排小字：庄思哑题。\n";
	else
   return "招牌写著：有一间客栈。\n";
}
