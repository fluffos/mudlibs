// taohuadao/shufang 书房

inherit ROOM;

void create()
{
        set("short", "书房");
       set("long", @LONG
这屋子全是以不刨皮的松树搭成，屋外攀满了
青藤，让人一种清凉的感觉。屋里有一个书架
(shelf),上面摆着一些书(book)，可以拿下来
看一看。
LONG);
         set("exits", ([ /* sizeof() == 1 */
         "west" : __DIR__"hetang",
         ]));
	set("objects",([
	__DIR__"npc/fu":1,
	]));
	set("item_desc",([
"shelf" : "这是一个木制的书架，摆放着一些书.",
"book" : "这是一本医药书，上面记载着一些药品的材料及功能。",
	]));
	setup();
	
}
void init()
{
	add_action("do_read","read");
}
int do_read(string arg)
{
	if(!arg||arg!="book")
	return notify_fail("你要读什么？\n");
	else
	{
	write("九花玉露丸:集九种花的花芯，用雨后的露水及若干草药配制。能补气壮身。\n");
	write("无常丹:乃多年炼制而成。可以滋长内力。\n");
	write("田七鲨胆散:以田七及鲨鱼内脏为主要原料。可补内力。\n");
	write("天王保命丹:为多年炼制而成。可以治疗内外伤。\n");
	write("通犀地龙丸:根据当年欧阳锋留下的药丸复制而得。可以用来解毒。\n");
	}
}

