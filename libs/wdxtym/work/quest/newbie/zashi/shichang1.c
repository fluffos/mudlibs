// shichang 1
inherit ROOM;
#include <ansi.h>;
int potential_lv(int exp);

void create()
{
        set("short", "采石场");
        set("long",
"这里是个很大的采石场，可以清楚的看见许许多多的已经采下的大大
小小的岩石垒在山旁，几个采石工人站在巨石上用铁锤敲打着石头，还有
很多的人将石块扛在肩膀上往里面运送。据说这些石头都是用来在建造防
外敌的"+HIR+"“城墙”"+NOR+"所需的。\n ");
        set("no_clean_up", 0);
        set("valid_startroom", 1);
 set("no_fight",1);
        set("exits", ([
//  "eastup" : __DIR__"shanlu1",
 "south" : "/d/xiangyang/caodi5",
//  "west" : __DIR__"shanlu",
        ]));
	set("item_desc",([
		"【采石】" : ZJOBACTS2"砸石头:砸 石头\n",
	]));
        set("objects", ([
                __DIR__"cao" : 1,
                __DIR__"jushi" : 2,
        ]));
        setup();
}

void init()
{
         add_action("do_za","砸");
}

int do_za(string arg)
{
        object me;
        int i, bonus;

        me=this_player();
        if( !arg && arg !="石头" && arg !="ju shi" && arg !="shi" ) return notify_fail("你要砸什么？\n");

        if (me->is_busy())
                return notify_fail("你现在正忙不过来呢。\n");

         if (me->query("combat_exp") >= 1000000)
                  return notify_fail("你已经不能通过砸石来增加修为了。\n");
        if( !present("hammer", this_player()) ) {
 tell_object(me,"\n只见你抡起巴掌狠狠的向巨石上击去，只听“喀嚓”一声，竟是骨碎的声音，这时你发现周围的人好象都在偷偷的乐！\n");
                me -> receive_damage ("qi",10) ;
                me->start_busy(5);
                return notify_fail("还是赶紧找个工具来吧！\n");
                }

        if(me->query_temp("stonework")<6) {
                message_vision(HIY"$N举起铁锤，抡圆了胳膊对准石头狠狠地砸了起来。\n"NOR,me);
                i = (int)this_player()->query("str", 1) + random(1000);
                    if(i<250) {
                        tell_object(me,"铁锤一下子被反震起来，在空中划了一道美丽的弧线，然后结实的砸在了你的屁股上！\n");
                        me -> receive_damage ("qi",10 + random(5));
                        return 1;
                        }
                me->start_busy(5);
                tell_object(me,"啪嗒一声，一块小碎石从巨石上掉了下来，看来你的工夫还是没有白费嘛！\n");
me->add_temp("stonework",1);
                me -> receive_damage ("qi",15 + random(10)) ;
          if (me->query("combat_exp") <= 500000)
{
                me->add("potential",  300+random(400));
}
else  me->add("potential",  100);
if( me->query("combat_exp") > 500000 )
{
me->add("combat_exp",  100);
}
                if( me->query("combat_exp") <500000 ){
                 me->add("combat_exp",random(600)+600);}
                return 1;
                }
                me->add_temp("stonework",1);
        return notify_fail(HIW"你一定很累了吧，该歇歇了，快去找监工交工了吧。\n"NOR);
}

int valid_leave(object me, string dir)
{
        if ( me->query_temp("stonework") && (dir == "east" || dir == "eastup"|| dir == "west") && present("cao liu", environment(me)) && living(present("cao liu", environment(me))) ) {                                                    message_vision(HIM"曹六大叫一声：“你给我站住，要想走就把你的工作先交了，当我不存
在呀！”\n"NOR,this_player());
                return notify_fail("");
                }
        return ::valid_leave(me, dir);
}


int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
}


