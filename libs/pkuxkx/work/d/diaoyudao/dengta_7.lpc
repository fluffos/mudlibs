// Room: /d/quanzhou/dengta_7.c 灯塔顶层
// cgbii 96.10.4

inherit ROOM;

void init()
{
        add_action("do_wang", "wang");
}
void create()
{
        set("short", "灯塔顶层");
        set("long", @LONG
这里是灯塔的顶层，地上凌乱地堆满了的物品，有金银财宝、
钻石首饰，看来都是倭寇们掠夺来的。灯塔四壁上有四扇窗户，从
窗口往外望(wang)，几乎可以看到整个钓鱼岛，以及浩瀚的大海。
LONG
        );

        set("exits", ([
                "down" : __DIR__"dengta_6",
        ]));

        set("objects", ([
                __DIR__"npc/obj/manao" : 1,
                __DIR__"npc/obj/zhenzhu" : 1,
        ]));

        setup();
}

int do_wang(string arg)
{
	object me = this_player();
		
	if( !arg || arg=="out" ) return notify_fail("\n你向窗外望去，东边就是被倭寇侵占的钓鱼岛；南面是钓鱼岛的南沙滩；
西方就是蔚蓝的大海；向北有条小道通往北海滩。\n");
        if ( arg=="north" )  return notify_fail("\n你向北望去，除了大海就是钓鱼岛的北海滩，
从塔下向东北方向，顺着海滩可到达一块大礁石。\n"); 
	if (arg=="west") return notify_fail("\n你向西望去，远处是碧波荡漾的大海，海面上泛起层层波浪，
仿佛千军万马一样向海岸涌来，显得极为壮观。\n");
	if (arg=="south") return notify_fail("\n你向南望去，蔚蓝的天空与碧蓝的大海相接一线，
海鸟在海天之间自由的翱翔。\n");
	if (arg=="east") return notify_fail("\n你向东望去，钓鱼岛尽收眼底，从塔下往东是一片
树林及一片破旧的帐篷，再往东，临近东海岸是一座山崖(hill)。\n");
        if (arg=="hill") 
	{
	    tell_object(me,"\n那是一座不算很高的山崖，临海伫立着，山下是一片灌木丛包围着，
要想上崖，只有借助崖北的礁石才行；崖下好象有一处灌木生长得比较稀疏。\n");
	    me->set_temp("望",(random(3)+1));
	    return 1;
	}
}
