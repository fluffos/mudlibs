// Room: /d/yandang/luoyan28.c

inherit ROOM;

void create()
{
	set("short", "听萧居");
	set("long", @LONG
听萧居是小姐的书房,也是她平常散心的地方,据说她的萧师法自然,
已达鬼惊神泣,凡人不可想象的地步.四壁摆满了书架,房间西壁下的书桌
(table)上,摆了一些笔墨什么的,旁边有一张古琴,色泽暗晕,却看不到萧
的影子.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/table.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"luoyan27",
  "north" : __DIR__"luoyan30",
]));

	setup();
}
void init()
{
        add_action("do_get", "get");
}

void reset()
{
        object 		*inv;
        object 		con, item;
	int		i;	

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 3) {
	        for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
        	item = new(__DIR__"obj/hubi");
        	item->move(con);
        	item = new(__DIR__"obj/duanyan");
        	item->move(con);
        	item = new(__DIR__"obj/songmo");
        	item->move(con);
        }
}

int do_get(string arg)
{
	string 		obj, from;
	object		me, table, target, taro;

	if(sscanf(arg, "%s from %s", obj, from)==2 ) {
		if(obj == "all") {
			write("一次拿太多东西会太明显。\n");
			return 1;
		}
		table =  present("table",this_object());
		target =  present(from,this_object());
		me = this_player();
		if(target == table) {
			taro =  present(obj, target);
			if(taro && random(10) > 4) {
				message_vision("$N四面看了看,没人,从桌子上拿了些东西藏起来！\n", me);
			}
		}
	}
	return 0;
}