// chufang.c 厨房

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是铁掌帮的厨房。正面是一个大炉灶，几乎占去了一半的房间。灶上
留有很多火眼，可同时做很多种菜。几位帮中高薪聘来的厨子正在来回忙碌着。
整间屋内弥漫着各种饭菜的香味，闻了让人垂涎欲滴。
LONG
        );

        set("exits", ([ 
"south" : __DIR__"zoulang-3",
]));

        set("objects", ([ 
__DIR__"npc/TZ_chuzi" : 1,
])); 

        set("no_clean_up", 0);
        set("no_fight", 1);

        set("coor/x",-350);
  set("coor/y",-240);
   set("coor/z",10);
   setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if((dir == "south")){
          while (i--)
          if(ob[i]->id("mi fan") || ob[i]->id("hongshao niurou") || ob[i]->id("ruzhu"))
             return notify_fail("厨子连忙跑出来拉住你：吃饱了还要打包吗？留给其它弟子们吧！\n");      
        }
        return ::valid_leave(me, dir);
}
