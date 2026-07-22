// Room: ymdrk12.c

inherit ROOM;

void create()
{
        set("short", "密道");
        set("long", @LONG
密道内伸手不见五指，你触摸着墙壁，不知碰到什麽硬物，
“啪”的一声，灯光四亮，闪得你睁不开眼睛。再一次定睛观
看，原来碰到了机关！！
LONG
        );
        
        setup();
}

void reset()
{
        ::reset();
        set("exits", ([ /* sizeof() == 4 */
          "south" : __DIR__"ymdrk" + (random(12)+1),
          "north" : __DIR__"ymdrk" + (random(12)+1),
          "west" : __DIR__"ymdrk" + (random(12)+1),
          "east" : __DIR__"ymdrk" + (random(12)+1), 
          "enter" : __DIR__"heiwu"        ]));
}

int valid_leave(object me, string dir)
{
        write("你实在弄不清楚方向....");
        switch(dir) {
                case "north":   write("北边....北边是哪里呢？....");    break;
  break;
break;
                case "east":    write("东边....东边....");      break;
break;
                case "south":   write("南边....哪里是南边？....");      break;
  break;
break;
                case "west":    write("西边....嗯....");        break;
break;
                default:
                        write("该往哪里走呢....");
        }
        write("就是这个方向吧。\n");
        return 1;
}

