// shibi.c writen by cry 10.1.98

#include <ansi.h>
private int gain_points( object me );
private int gain_xiuwei( object me );
inherit ITEM;
int look_item(string arg);


void create()
{
	set_name(HIC"石壁"NOR, ({ "shibi" }) );
        set_weight(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一块石壁，表面光亮如镜，刻着写挥舞着刀法的小人. \n");
		set("unit", "块");
		set("no_get",1);
		set("value",1000);
		set("material", "stone");
	}
	setup();
}

void init()
{
    add_action("can_xiu", "canxiu");
}

int can_xiu( string arg )
{
    object me;
    me = this_player();
    if ( me->query("marks/kongdong/dao")!=2)
      return notify_fail(HIB"你是怎么进来的？去死吧！呵呵，吓唬你的！下次按照规矩进来！\n"NOR);
    if( !me->can_act() || me->is_fighting() )
        return notify_fail(HIB"你现在哪儿有心思去研究这快石壁上的东西。\n"NOR); 
    tell_object( me, WHT"你对着石壁，潜心的研究起来。\n"NOR);
    me->disable_command("verb", HIB"一心岂能二用！? ！\n"NOR);
    call_out("start_canxiu", 10, me );
    return 1;
}

void start_canxiu( object me )
{
    int time;
    if( !me ) return;
    if( me->query_xiuwei_by_type("blade") < 5300 )
    {
        me->enable_path();
        me->receive_damage("gin", 50 );
        tell_object( me, YEL"你莫名其妙看着石壁上那些招式，只觉心里空荡荡的。\n"NOR);
        return;
    }
    if (!me->query_jibie("huoyan-dao"))
    {           me->enable_path();      
        me->improve_jibie("huoyan-dao", 1);
            tell_object( me, WHT"你居然领悟出一套以掌御刀的奇妙刀法。\n"NOR
                             HIM"你的『火焰刀』进步了！\n" NOR);
             return;
        }
    tell_object( me, WHT"你慢慢的比划着那墙上的小人儿图形，心中突然灵光一闪\n"
                    WHT"你沉思其中，久久不醒......\n"NOR);
    me->set_temp("block_msg/all", 1);
    time = 30 ;
    call_out("get_gain", time, me );
}

void get_gain( object me )
{
    string msg;
    int point;

    if( !me ) return;

    me->delete_temp("block_msg/all");

    msg = CYN"不知道过了许久，你才从沉思中醒来，发现这门功夫很是奇妙。\n"NOR;
    if ( me->query_lingwu_ratio( "huoyan-dao" )<90)
    {       point=0;
            msg += WHT"只感到石壁上的图案真是是玄妙万分。\n" NOR;
     }
    else if ( me->query_jibie( "huoyan-dao" )>149)
    {       point=0;
            msg += WHT"只觉得石壁上的一招仪式都已经了熟于心了。\n" NOR;
     }     
    else {
    point = me->query_xiuwei("blade")/1500;
    msg += HIM"只觉石壁上这套以掌御刀的功夫招式奇妙，威力一定也非同小可。\n" NOR; 
        if( !me->query_jibie("huoyan-dao") )
            msg += HIM"你终于学会了绝世的的刀法。\n"NOR;
     
        msg += HIG "你的『火焰刀』进步了！\n" NOR;
        me->improve_jibie("huoyan-dao", 1);
        me->improve_xiuwei("blade",  point); 
        msg += HIW"你的〖 刀 术 〗的修为有所提高。"NOR;
        me->improve_xiuwei("zonggang", random(point) );        
        msg += HIW"在〖 武 学 〗上的造诣也更深了。\n"NOR;
    }
    
    tell_object( me, msg );
    me->receive_damage("gin", 100);
    me->enable_path();
}