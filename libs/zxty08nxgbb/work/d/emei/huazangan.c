// Room: /d/emei/huazangan.c 峨嵋派 华藏庵
// create by host dec,20 1997
inherit ROOM;


void create()
{
	set("short", "华藏庵");
	set("long", @LONG
这里是峨嵋的藏经阁。虽然并不太大，但屋中摆放了许多的竹架，
上面陈列着密密麻麻的各种书籍，在靠窗边有一张桌子，上面有一盏
油灯(lamp)，在灯旁好象是放了一本书，但当要拿它时，却发现拿了
一个空。
LONG
	);

	set("exits", ([
                "west": __DIR__"duguangtai",
//               "up": __DIR__"huazangan1",
	]));
        set("item_desc", ([
           "lamp" : "一盏装满灯油的油灯\n",  
             ])) ;

	set("objects",([
//		CLASS_D("shaolin") + "/dao-zheng" : 1,
	]));

	setup();

}
void init()
{

   add_action("do_light","light");
}
int do_light(string arg)
{

    object me,obj,obn;
    me=this_player();
    if (this_player()->query_temp("marks/light"))
		return notify_fail("佛经已经被你拿走了，还要做什么？\n");	
    if ( !arg || (arg != "lamp") )
       return notify_fail("你要点什么？\n");
    
   if (!(obj = present("fire stone", this_player())))
       return notify_fail("你想拿什么点啊！？\n");

   obn = new("/d/emei/obj/dachengjing");
   obn->move(me);
   me->set_temp("marks/light", 1);
   message_vision("$N拿出火石点着了油灯。\n",me);
   message_vision("只见油灯旁边放了一本『大乘佛经』。\n$N走到近前拿起了佛经。\n",me);
 
   return 1;
  
}

