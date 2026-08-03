// Room: /d/xingxiu/jiayuguan.c
// June 97
// by pishou

inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", "嘉峪关西城门");
        set("long", @LONG
这是长城最西的关隘嘉峪关西城门。再往西就称西域了，因此这儿有军队驻
扎，不时盘问来往行人。你小心翼翼，急步离开这是非之地。出关向西，便是著
名的“丝绸之路”。你一踏上西域荒道，忍不住回过头来再望一下嘉峪关。发觉
岁月沧桑，仍掩不住它的风采。群山环抱之下，更显它的雄浑。城门的墙上张贴
着一纸告示(gaoshi)。
LONG);

        set("outdoors", "yili");
        set("exits", ([
                "east" : __DIR__"jyg",
                "west" : __DIR__"silk",
        ]));

         set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("objects", ([
                __DIR__"npc/bing1" : 2,
                __DIR__"npc/wujiang1" : 1,               
        ]));
        set("coor/x",-220);
  set("coor/y",70);
   set("coor/z",-10);
   set("coor/x",-220);
  set("coor/y",70);
   set("coor/z",-10);
   set("coor/x",-220);
 set("coor/y",70);
   set("coor/z",-10);
   setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n全国通缉。\n";
}

#include "/d/xingxiu/job2.h";