// Room: /d/emei/qingyinge.c 峨嵋派 清音阁外小道


inherit ROOM;


void create()
{
        set("short", "清音阁外");
	set("long", @LONG
这里有一条上山小路，路旁有一石碑(shibei)。在南面有一座在大山环抱
中的小阁楼，此阁位于牛心岭下。这里环境清幽，万籁聚静，偶尔也有几声鸟
叫，不时在山谷中回荡。在阁外种植了许多的杜鹃花，十分的艳丽。在正面有
一个小木门(men)，却紧紧的关闭着。由此向东上有一座六脚亭，左路至白龙
洞。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "northdown": __DIR__"shenshuige",
                "southwest":__DIR__"bailongdong",
                "eastup":__DIR__"niuxinting",
	]));
       set("item_desc", ([
                "shibei" : @SHIBEI
石碑刻有一诗曰：

　　　　　　　杰 然 高 阁 出 清 音，

              仿 佛 仙 人 下 抚 琴。

　　　　　　　试 向 双 溪 一 倾 耳，

              无 情 两 水 漱 牛 心。

这就是“峨嵋十景诗”中专咏这“双桥清音”的诗。
SHIBEI
        ]));
	setup();
}
void init()
{
    add_action("do_knock", "knock");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"qingyinge1")) )
        room = load_object(__DIR__"qingyinge1");

    if(objectp(room))
    {
        delete("exits/south");
        message("vision", "里面有人悄悄的把木门关上了。\n",
            this_object());
        room->delete("exits/north");
        if (objectp(room))
           message("vision", "静和悄悄的合上了木门。\n", room);
     }
}
int do_knock(string arg)
{
    object room;

    if (query("exits/south"))
        return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "men" && arg != "south"))
        return notify_fail("你要敲什么？\n");

    if(!( room = find_object(__DIR__"qingyinge1")) )
        room = load_object(__DIR__"qingyinge1");
    
    if(objectp(room))
    {
        set("exits/south",__DIR__"qingyinge1");
        message_vision("$N轻轻地敲了敲门，只听吱地一声，"
            "一位师太应声打开大门，\n",this_player());
        room->set("exits/north", __FILE__);
        message("vision", "外面传来一阵敲门声，静和应声上前把大门开。\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    if ( dir != "south" )
        return ::valid_leave(me, dir);

    if (!::valid_leave(me, dir))
        return 0;

    if ( (!(myfam = me->query("family")) || myfam["family_name"] != "峨嵋派") )
          return notify_fail("静和双掌合十说道：阿弥陀佛！本门弟子在里静修，外人不得打扰。\n施主请回吧。\n");
    else 
          write("静和双手合十，侧身让开。\n");
          return 1;
 }


