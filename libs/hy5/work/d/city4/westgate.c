//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "长安城西门");
        set  ("long",  @LONG
这里便是长安西门----安定门。长安为多朝古都，果然不同凡响，
城墙以石灰、糯米和土夯成，固若金汤。出城往西门便可直通兰州，几
名官兵正在守门。
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("exits",  ([  //sizeof()  ==  4
            //"north"  :  "/d/changan/ca34",
            //"west"  :  "/d/xingxiu/xxroad1",
            "south"  :  __DIR__"apanggong",
            "west"  :  "/d/lanzhou/caroad8",
            "east"  :  "/d/changan/ca34",
        ]));

        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
  	     "/d/city/npc/xunbu" : 1,
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
        setup();
        replace_program(ROOM);
}



