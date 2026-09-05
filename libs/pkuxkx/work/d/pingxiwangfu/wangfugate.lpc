//made by goodtaste
//date 1998.12.11
inherit ROOM;
void create()
{
        set("short", "平西王府大门");
        set("long", @LONG这里是平西王吴三桂的大门，金碧辉煌，威武雄壮，普通百姓到
这里连话都不敢说，旁边站着几个亲兵。门上挂有一块大匾(bian).
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
  "north" : __DIR__"dadao1",
"south" : __DIR__"pxroad4",
      ]));
         set("objects", ([
    __DIR__"npc/qinbing":4,
    __DIR__"npc/qinbingtou":1,
       ]));

        set("item_desc", ([
"bian":"平西王府\n "
                        ]) );
  
      
        setup();
}



int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability"))
        return ::valid_leave(me, dir);  
    if ( dir != "north" || ( me->query_temp("qinbing_asked") && present("tongxingling",me) ) )
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++)
    {
        if( living(ob[i]) && ( ob[i]->query("id") == "qin bing" || ob[i]->query("id") == "qin bingtou" ))
            return notify_fail("王府亲兵大声喝道：「哪里来的刁民，胆敢擅闯王府？」\n");
    }
    return ::valid_leave(me, dir);
}


