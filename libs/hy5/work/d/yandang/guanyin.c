// Room: /d/yandang/guanyin
inherit ROOM;

void create ()
{
  set ("short", "观音洞");
  set ("long", @LONG
初名灵峰洞,又名罗汉洞.藏于合掌峰内,洞高113米,宽14米,依岩构
筑九层楼阁.为雁荡山第一洞天.据说以前有个高僧独自居于洞中,日夜诵
'法华经'.你现在站立的地方就是第一层了.
LONG);

  set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/shami.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"shanlu6",
  "up" : __DIR__"guanyin1",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
ob=present("qing ji",this_object());
 if (objectp(ob)&&dir=="up")     {
        if (ob->query("banghui")!=me->query("banghui"))
    return notify_fail("小沙弥跳到台阶上拦住你:你不是我本帮兄弟吧!\n");
        }
 return ::valid_leave(me,dir);
}
      
