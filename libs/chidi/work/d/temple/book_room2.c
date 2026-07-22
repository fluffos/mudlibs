#pragma save_binary
// Room: /d/temple/broom2.c

inherit ROOM;

void create()
{
	set("coor",({1210,5000,40}));
	set("short", "经楼");
	set("long",
"上了楼来,首先你看到一幅张天师的画像挂在对面的墙上,画像的\n"
"下方摆著一张覆著红布的桌子,桌上整齐地放著茅山的镇教秘籍。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/temple/book_room1",
]));
        set("objects", ([ 
            __DIR__"obj/s_spells_book" : 1,
           ]) );

    set("no_magic",1);
    set("no_arrest",1);
	setup();
}
int valid_leave(object me, string dir)
{
    int flag;
    object ob;
    mixed *obj;
    obj=values(query_temp("objects"));
    if(objectp(obj[0])&&environment(obj[0])==this_object())
        flag=0;
    else    flag=1;
     if ( dir=="down" && flag)      
          return notify_fail("\n一道无形的墙挡住了门口, 差点把你的鼻子给撞扁了。\n心底响起一个声音：“不放好镇派秘籍，谁也不能走！”\n");
return 1;
}
void init()
{
    add_action("do_noout",({"dancing","pray","tie","home","use"}));
}
int do_noout()
{
return 1;
}
