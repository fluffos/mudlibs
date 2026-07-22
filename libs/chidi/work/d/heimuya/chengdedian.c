//room: chengdedian.c
inherit ROOM;
void create()
{
  set("short","成德殿");
  set("long",
        "这就是日月神教教主平日发号施令的地方, 殿中无窗, 殿口点着\n"
        "明晃晃的蜡烛, 大殿彼端高设一座, 坐着一个英俊的中年人, 自是\n"
        "名震江湖的东方不败的姘头杨莲亭了!\n" 
     );
  set("exits",([
      "south" : __DIR__"huoting",
      "westdown":__DIR__"up4",
     ]));
  set("objects",([
                               __DIR__"npc/dizi" : 2,
                               __DIR__"npc/yang"    :1,
        ]));
  
 setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object ob=present("yang lianting", environment(me));
        if (ob && living(ob) ){
            myfam = (mapping)me->query("family");
            if ((!myfam || myfam["family_name"] != "日月神教") && dir == "south" ) {
                    say("杨莲亭对"+me->name()+"喝道：你不是本教教众，请留步。\n");
                    return notify_fail("杨莲亭喝道：后面是本教重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
            }
        }
        return ::valid_leave(me, dir);
}


