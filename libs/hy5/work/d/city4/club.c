//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "长安乐坊");
        set  ("long",  @LONG
这里是长安城一家有名的娱乐场所。当夜幕降临后，这里就格
外热闹。进进出出的客人有达官贵人，南来北往的商旅，浪迹天涯
的游子，三五成群的兵士，有时也能看见一些作俗客打扮的僧人或
道士。
LONG);
       //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
       set("exits",  ([  //sizeof()  ==  4
              "up"    :  __DIR__"clubup",
              "south" :  __DIR__"eastroad2",
              "north" :  __DIR__"qishi3",
              "west" :  __DIR__"qishi1",
              "east" :  __DIR__"qishi2",
       ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"obj/tables"  :  1,
                __DIR__"obj/chairs"  :  2,
       ]));
//                set("outdoors",  "changan");
	set("no_npc",  1);
	set("no_clean_up",  0);
        setup();
	replace_program(ROOM);
}

