//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "长安乐坊平安分店");
        set  ("long",  @LONG
这里是长安城一家有名的娱乐场所的分店。当夜幕降临后，这
里就格外热闹。进进出出的客人有达官贵人，南来北往的商旅，浪
迹天涯的游子，三五成群的兵士，有时也能看见一些作俗客打扮的
僧人或道士。
LONG);
       //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
       set("exits",  ([  //sizeof()  ==  4
              "up"    :  __DIR__"clubup",
              "east" :  "d/pingan/nan2",
       ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"obj/tables"  :  1,
                __DIR__"obj/chairs"  :  2,
       ]));
//                set("outdoors",  "changan");
	set("no_clean_up",  0);
        setup();
	replace_program(ROOM);
}

