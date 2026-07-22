inherit ROOM;

void create()
{
  set ("short", "长安武馆");
  set ("long", @LONG

长安武馆的内堂，一切都安安静静，屋里没有点烛，什么也看不清楚。
隐约看到两排长椅，正面墙上挂一大旗(qi)。
LONG);
set("item_desc",(["qi":"
        ＊＊＊＊＊＊＊＊
        ＊＊拳盖三省＊＊
        ＊＊无人能敌＊＊
        ＊＊＊＊＊＊＊＊\n"
]));
        set("objects", ([
                __DIR__"npc/fan": 1, 
//                __DIR__"npc/dizi2": 4+random(5), 
//        "/quest/biao/npc" : 1,
                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"wuguan",
]));
      set("no_fight",1);
  setup();
}

void init()
{
add_action("do_none","get");
add_action("do_none","drop");
add_action("do_none","bian");
add_action("do_none","steal");
add_action("do_none","shoot");
}

int do_none(string verb)
{
if ( verb && ( sscanf(verb,"%s from fan",verb)==1 
     || sscanf(verb,"%s from corpse",verb)==1 ) )
    {
    if ( verb=="all" || verb=="book" )  
              return 0;
    }
write(">ok。\n");
return 1;
}
