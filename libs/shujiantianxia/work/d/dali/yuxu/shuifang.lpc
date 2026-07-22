inherit ROOM;
string look_sign(object me);
void create()
{
set("short", "睡房");
	set("long", @LONG
这里就是玉虚观内的睡房。几张小床，床上挂着帐子，房间很是简朴，
没有什么多的东西，房间角落有一个柜子。靠墙挂了张很大的画。
LONG
	);
        set("indoors", "大理");
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"yuxuguan",

]));
set("item_desc", ([
		"image": (: look_sign :),
		"画": (: look_sign :),
		
	]) );
       
	setup();
}
string look_sign(object me)
{
	if(me->query_skill("whip",1)<30 ) {
    return " 这是一副古画,画上描绘的是洛神赋中的故事 。\n";
	} else {
	me->set_temp("yuxu_image",1);
	return "  这是一副古画,画上描绘的是洛神赋中的故事,画中美女挥舞长袖,
翩翩起舞, 身形飘飘,你定了定神，隐约感觉画里似乎隐藏着极为高明的鞭法\n";
}
}

void init()
{
        add_action("do_huiwu", "huiwu");  
}

int do_huiwu(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

    if (!me->query_temp("yuxu_image", 1)) return 0;

    if( !arg || arg!="image" ) {
                write("你要根据什么挥舞！\n");
                return 1;
        }
        if (!weapon || weapon->query("skill_type") != "whip" )
		return notify_fail("你手中无鞭，怎么领会？\n");

        if ((int)me->query_skill("whip", 1) >100 )
        return notify_fail("你已经竭尽全力去体会画上暗藏的鞭法精要，但是无法再增长你的基本鞭法了！\n");
    
	    me->receive_damage("jingli", 10+random(15));
	     me->receive_damage("jing",random(10));
        write("你对照着毯子上暗藏的鞭法精义，挥舞着，渐渐地悟出了一些有关基本鞭法的精要之所在。\n");
         me->improve_skill("whip", me->query("int"));       
         return 1;
}                                     
int valid_leave(object me, string dir)
{
	me->set_temp("yuxu_image", 0);
       return 1;
	 
}
