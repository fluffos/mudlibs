//shufang.c 书房
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short",HIC"书房"NOR);
	  set("long",@LONG
房内整齐地排着几排书架，这里是公孙止的书房，左边的书架上排列着一
些基本武功的书籍。右边的书架上排列着一些诗词。东首放着一张桌子，走近
一看，桌上放着一些公孙谷主写的诗词。书房出去是东厢长廊。
LONG
           );

	  set("exits",([
              "west": __DIR__"lang3",
          ]));
                  
          set("item_desc",([
               "jia":"这个书架上摆放着不少书籍。\n",
          ]));
	  setup();
          replace_program(ROOM);
}
