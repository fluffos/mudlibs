// Room: /u/boyi/workroom.c

inherit ROOM;

void create()
{
        set("short", "阿妙的小屋");
        set("long", @LONG
这里是阿妙的寝室，有一张红木雕花的小床，床紧紧的靠着小
窗。阿妙累的时候就会佚在窗前，看那稀呖呖的小雨，闻那清馨的
花香，听那悦耳的鸟鸣。
     
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/shendian/jianyian", 
  "down" : "/d/wizard/wizard_room",]));
        set("no_steal", "1");
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        set("sleep_room", 1);
         set("objects", ([
               "/u/amiao/npc/shutong" : 1, 
            //   "/u/seaking/shouji" : 1,
                    ]));


        setup();
        replace_program(ROOM);
}


