#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "海天一线");
        set("long", @LONG
海洋中的一块圣地。武林人士通常都来此处进行切磋比武，寻找知己。
只见上首有些诗句，也不知是哪位人物留下的手笔。在傍边有一块石
头，上刻：
[34m
                       笑问叶落看风云，
                       回首化月望秋水。
                                       
[37m
你可以试试在这个有灵气的地方提升(levelup)武器的等级。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"wudao4",
]));
       
  set("objects", ([ /* sizeof() == 4 */
  "/d/city/npc/xunbu" : 1,
  "/clone/npc/testnpc" : 1,
  "/d/migong/obj/testnpc2" : 1,
]));
	set("citybiwu",1);
	set("no_death_penalty",1);
	set("no_dazuo",1);
	       
	setup();
}
void init()
{
	add_action("do_levelup","levelup");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","respirate");
        add_action("do_quit2","tuna"); 
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
}
int  do_levelup(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if( !arg ) return notify_fail("你要提升什麽武器？\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("你身上没有金子。\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if( ob->query("equipped") )
        return notify_fail("你不可祭装备著了的武器。\n");
        if( !ob->query("ownmake") )
        return notify_fail("你只可祭自己打造的武器。\n");
        if( ob->query("armor_type"))
        return notify_fail("提升盔甲请去别的地方用jijia来做。\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("你的气不够，无法锻炼兵器！\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("你现在的体力太弱，无法锻炼兵器！\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("你现在的精力无法集中，不能锻炼兵器！\n");
	if( (int)me->query("score") < 100 )
		return notify_fail("你现在的江湖阅历不够，不能锻炼兵器！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 20 )
		return notify_fail("你的潜能不够，无法锻炼兵器！\n");
	j = (int)me->query("weapon/lv");

	if(j<6) cost = 20*j;
	else if(j<11) cost = 30*j;
	else if(j<16) cost = 40*j;
	else if(j>500) cost = 200*j;
	else cost = 60*j;
        if((int) gold->query_amount() < 100)
        return notify_fail("你身上没带够100两金子。\n");

        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d",cost)+ "两金子。\n");
        gold->add_amount(-cost);
        me->start_busy(2);
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("score",-100);
	me->add("learned_points", 20);
	me->set("weapon/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "鞭身忽的一亮，一道金光隐入$N的"+ob->name()+HIY"，不见了！\n" NOR,me);
	message_vision(HIG "$N的"+ob->name()+HIG"的等级提高了！\n" NOR, me);
        seteuid(getuid());
	return 1;
}

int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"，安心的比武吧！\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"，安心的比武吧！\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"，安心的比武吧！\n");
        return 1;
}
