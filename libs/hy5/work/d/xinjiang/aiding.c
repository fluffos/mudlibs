 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "艾丁湖");
        set("long", @LONG
艾丁湖，意为月光湖。因湖大部分是皱褶如波的干涸湖底，
触目皆是银白晶莹的盐巴，在阳光下闪闪发光，酷似寒夜睛空
的月光，故名艾丁湖。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"tulufan",
  "westdown" : __DIR__"pubu",
]));
        set("objects", ([
        __DIR__"npc/saltboss" : 1,
                        ]) );
        set("item_desc", ([
           "盐巴": "厚厚的一层盐巴铺盖在已经干涸的湖底。\n",
           "yanba": "厚厚的一层盐巴铺盖在已经干涸的湖底。\n",
           "salt rock": "厚厚的一层盐巴铺盖在已经干涸的湖底。\n",
        ]));
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1070);
        set("coor/y",2020);
        set("coor/z",10);
        setup();
} 
void dig_notify()
{
     object me, salt;
     if(query("already")) return 0;
     me = this_player();
     message_vision("锵．．得一声，再看地上的盐巴以被$N砸下一小块。\n", me);
     salt = present("salt rock", this_object());
     if(!objectp(salt)) {
        salt = new(__DIR__"obj/salt");
        salt->move(this_object());
     }
        set("already",1); 
}    
