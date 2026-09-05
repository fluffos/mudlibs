//dongxiang.c
//by zoom
//2004.3.29

inherit ROOM;

int do_tuna(string arg);
int do_dazuo(string arg);

void create()
{
    set("short", "东厢房");
    set("long", @LONG
新手学堂的东厢房，房间里极为安静，仅能听到或悠长，或粗重的
呼吸声。洞里零零落落地摆着几个蒲团，并无其他陈设。几个人正
坐在上面打坐(dazuo)，吐纳(tuna)。
LONG
    );

    set("exits", ([
                "south" : __DIR__"dongceting",
                "west" : __DIR__"yuan2",
    ]));
    
	set("objects", ([
		__DIR__ +"npc/shaonian" : 1, 
		]));

        set("indoors", "train");

    setup();

}
void init()
{
	add_action("do_dazuo", "dazuo");
	add_action("do_tuna", "tuna");
}

int do_dazuo(string arg)
{	if (!arg)
	{	write("打坐(dazuo)是用气提高你的内力。每次打坐最少要花十点气。\n");
		write("如果你打坐把你的内力提高到你永久内力的一倍，你永久内\n");
		write("力就会加一点。你和人比拼功夫时可以增加内力(jiali)伤\n");
		write("人，但你只能加到你内功有效等级的一半。\n");
	}
	return 0;
}

int do_tuna(string arg)
{	if (!arg)
	{	write("吐纳(tuna)化精为精力。每次吐纳最少要花十点精。\n");
		write("如果你吐纳把你的精力提高到你永久精力的一倍，你永久精\n");
		write("力就会加一点。\n");
	}
	return 0;
}
