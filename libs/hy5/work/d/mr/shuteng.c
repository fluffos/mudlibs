// /u/beyond/mr/shuteng.c
// this is made by beyond
// update 1997.7.2
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",GRN"树藤"NOR);
         set("long",@long
这里长满了树藤，一枝一枝的树藤(teng)遮住了阳光，树藤盘根错节,你
只能在树藤上爬上爬下。
long);
         set("item_desc",([
         "teng" : "树藤遮住了阳光，几乎没有一点光线，使你极力的拨开藤枝(zhi)。\n",
         "zhi" : "树藤的枝条上好象有人的手指插进去的痕迹。\n",
         ]));
         setup();
}           
 void init()
 {
        add_action("do_move", "pa");
        add_action("do_move", "move");
        add_action("do_leave", "leave");
        add_action("do_leave", "down");                                   
        add_action("do_bo", "bo");    
add_action("do_insert","insert");
add_action("do_insert","cha");
 }                                    
 int do_move(string arg)
{
        object me = this_player();
        if (arg !="down")
        return notify_fail("你要往那里爬？\n");
        if (arg == "down")
        message_vision("$N小心地攀住树藤，向下爬去。\n" , me);
        me->move(__DIR__"hhyuan");
        return 1; 
}                                     
int do_leave(string arg)
{
        object me;
        me = this_player();
        message_vision(HIR "$N松开双手，身子立即急速向下坠去，耳边风声呼呼。\n" NOR, me);
        me->move(__DIR__"hhyuan");
        me->unconcious();
        return 1;
}                                
int do_bo(string arg)
{
        object me;
        me = this_player();
        if (arg !="teng")
        return notify_fail("你要干什么？\n");
        if (arg =="teng")
        message_vision(
		"$N拨开树藤，勉强露出一丝阳光，这时你看到一片盛开的樱桃花。\n",
	me);
        return 1;
}
int do_insert(string arg)
{
	object me;
	me = this_player();
if ( !living(this_player()) || arg != "shuteng" )
        	return 0;
        if (me->query("family/family_name")!="姑苏慕容")
	        return 0;
        if ((int)me->query_skill("finger", 1) >101 )
        return notify_fail("你用手插进树藤，但是已经无法提高你的基本指法了！\n");
        if ( (int)me->query("jing")<30) {
                me->receive_damage("jing", 10);
                write("你太累了，已经没有力气用手来插进树藤了！\n");
                message_vision(HIR "$N太累了没有力气扒住树藤，身子立即急速向下坠去，耳边风声呼呼，啊......\n" NOR, me);
                me->move(__DIR__"hhyuan"); 
                message_vision(HIR"$N从树藤上掉了下来，跌在了地上。\n" NOR, me);
       		me->unconcious();              
	        return 1;
	}
me->receive_damage("jing", random(15)+15);
        write("你不时地用手指插进树藤，你的手上有些轻微的挫伤。\n");
        message_vision("$N正在不时地用手指插进树藤。\n", me);  
	me->improve_skill("finger", me->query("int"));       
	return 1;
}
