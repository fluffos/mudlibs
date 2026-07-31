//ta.c.塔
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"承天寺塔"NOR);
    set("long",@LONG
“好高的塔!”你不禁赞道。这是承天寺的高塔，它是全西夏国最高的佛塔，
也是让全西夏国引以为自豪的一件工程。全塔采用砖木结构，外面铺以用上好粘
土烧成的彩瓷瓦窑贴面。实心的塔身，共分成十八层，每一层外面都刻有特殊的
图画，每一层的塔檐下都掉着数个风玲，风一吹，就听见满世界都是“丁零～丁
零～”的声音，让你乐而忘忧。塔一层有东，南，西，北四根柱子，似乎可以转
动(zhuan)。
LONG);
   
    set("exits",([
        "north"   : __DIR__"tianjing1",
    ])); 
    set("dan",1);
    setup();
}

void init()
{
    add_action("do_zhuan","zhuan");
}

int do_zhuan(string arg)
{
    object me,ob,room;
    string str;
    int i,j;
    me = this_player();
    if ( !room = load_object("/d/xibei/xingqing/ta") )
          room = find_object("/d/xibei/xingqing/ta");
    if ( !arg )
    return notify_fail("你瞎转些什么啊?....\n");
    if ( arg != "east" && arg != "south" && arg != "west"  && arg != "north" )
    return notify_fail("你瞎转些什么啊?....\n"); 
    if ( !objectp(ob = present("yang pi", me)) )
    return notify_fail("你转了一下柱子，莫名奇妙....\n");
    i = ob->query("dan");
    i += 1;
    if ( arg == "east" ) j =0;
    if ( arg == "south") j =1;
    if ( arg == "west" ) j =2;
    if ( arg == "north") j =3;
    str = "dan_bi_"+(string)i;
    if ( ob->query(str) != j ) i =0;
    if ( i < 9 )
    {
       ob->set("dan",i);
       write("柱子彘彘呀呀地转了一下.....\n");
       return 1;
    }
    ob->set("dan",0);
    write("塔壁移开，露出一个方洞..........\n");
    if ( room -> query("dan")== 0 )
    {
       write("里面空空荡荡,什么也没有......\n");
       return 1;
    }
    write("从洞里滑出一团用丝绢包着的东西，掉在地上，露出一块美玉\n");
    new("/d/xibei/xingqing/npc/obj/bi")->move(room);
    room -> set("dan",0);     
    return 1;
}

