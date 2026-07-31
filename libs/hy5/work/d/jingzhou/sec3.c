// Room: sec2
// congw 980830 

inherit ROOM;
void create()
{
	set("short", "坟墓内部");
	set("long", @LONG
这里放着一具棺材，大概就是墓碑上所写“林霜华”的棺材了。奇怪的是棺材已被打开
，旁边放着棺盖(cover)。
LONG
	);

	set("exits", ([
		"out" : __DIR__"houyuan",
		"northup" : __DIR__"sec2",
		]));


	set("item_desc", ([
		"cover" : "你抹去上面的灰尘，只看见上面写着些奇奇怪怪的数字：“三十三、五十七、一十八、二十六、四十一” \n",
	]));

        set("no_clean_up", 0);
       

        setup();
        replace_program(ROOM);
}

