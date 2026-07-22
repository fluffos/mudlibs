/*段正淳的高级任务 writen by cry 9.20.98
           
【取水晶簪】：1,
【抓金甲护卫】：2,
【取金刚经】：3,
【取玻璃】：4,
【指南针】：5,
【取灵芝】：6,
*/
            
int give_quest()
{
    object me = this_player();
    object ob = this_object();

    if( me->query("class") != "duanshi" ){return 0;}
    if( me->query("title") != CYN"大理国"RED"武官"NOR
     && me->query("title") != CYN"大理国"GRN"武官"NOR
     && me->query("title") != CYN"大理国"WHT"武官"NOR ) {
        message_vision("$N疑惑的看着$n：“你是谁？要任务去找段总管吧。”\n", ob, me);
        return 1;
    } if( me->query("quest") ) {
        if( me->query("oldquest/task_time")<time() ) {
            fail_duan_quest(me);
            return 1;
        }
        message_vision("$N一皱眉：“你怎么还不快去？！”\n", ob);
        return 1;
    } switch ( random(7) ) {
        case 0:
            message_vision("$N轻轻摇了摇头：“你也辛苦啦，先回去休息吧。”\n", ob);
            break;
        case 1:
            remove_call_out( "give_quest_1" );
            call_out( "give_quest_1", 1, me );
            break;
        case 2:
            remove_call_out( "give_quest_2" );
            call_out( "give_quest_2", 1, me );
            break;
        case 3:
            remove_call_out( "give_quest_3" );
            call_out( "give_quest_3", 1, me );
            break;
        case 4:
            remove_call_out( "give_quest_4" );
            call_out( "give_quest_4", 1, me );
            break;
        case 5:
            remove_call_out( "give_quest_5" );
            call_out( "give_quest_5", 1, me );
            break;
        case 6:
            remove_call_out( "give_quest_6" );
            call_out( "give_quest_6", 1, me );
            break;
    }
    return 1;
}

void give_quest_1( object me )
{
    int time = 2000+random(1500);

    me->set( "oldquest/task_time",time()+time );
    me->set( "quest",([
		"quest" : "取"+HIC"水晶簪"NOR,
		"bonus" : 65+random(30),
	]) );
    tell_object( me,
HIW"段正淳说道：“再过半个月就是王妃的生日了，我正想找件礼物。\n"
+"听说世上有一枚用水晶石雕成的发簪，你去打听一下吧。\n"NOR );
}

void give_quest_2( object me )
{
    int time = 2500+random(1500);

    me->set( "oldquest/task_time",time()+time );
    me->set( "quest",([
		"quest" : "抓"+YEL"金甲护卫"NOR,
		"bonus" : 85+random(25),
		"positive_score" : 100,
	]) );
    tell_object( me,
HIW"段正淳说道：“西夏有一个秘密组织叫一品堂，对大理窥探已久，\n"
+"不知有何企图，你去抓个"NOR+YEL"金甲护卫"+HIW"来，我要亲自拷问。\n"NOR );
}

void give_quest_3( object me )
{
    int time = 1000+random(500);

    me->set( "oldquest/task_time",time()+time );
    me->set( "quest",([
		"quest" : "取金刚经",
		"bonus" : 45+random(25),
	]) );
    tell_object( me,
HIW"段正淳叹道：“这儿两天我有点心烦气燥，你去取本金刚经来，我要静修几日。”\n"NOR );
}

void give_quest_4( object me )
{
    int time = 7200+random(3600);

    me->set( "oldquest/task_time",time()+time );
    me->set( "quest",([
		"quest" : "取"+HIY"玻璃"NOR,
		"bonus" : 100+random(30),
	]) );
    tell_object( me,
HIW"段正淳笑道：“听说有波斯商人那里有"+HIY"玻璃"HIW+"，你去买点回来吧。”\n"NOR );
}

void give_quest_5( object me )
{
    int time = 2000+random(1000);

    me->set( "oldquest/task_time",time()+time );
    me->set( "quest",([
		"quest" : "取指南针",
		"bonus" : 60+random(20),
	]) );
    tell_object( me,
HIW"段正淳说道：“过两天我要出远门，你去给我找一个指南针来。”\n"NOR );
}
    
void give_quest_6( object me )
{
    int time = 1000+random(1000);

    me->set( "oldquest/task_time",time()+time );
    me->set( "quest",([
		"quest" : "取"+HIM"灵芝"NOR,
		"bonus" : 50+random(20),
	]) );
    tell_object( me,
HIW"段正淳叹道：“昨夜王妃受了些风寒，你去买颗"+HIM"灵芝"NOR+"来，给王妃补补气。”\n"NOR );
}

int accept_object( object me, object obj)
{
    object ob=this_object();
    int bonus, p_score, n_score;
//p_score is positive_score, n_score is negative_score.

    if ( me->query("class") != "duanshi" ) {
        command("? "+me->query("id"));
        return 0;
    } if ( !(me->query("quest")) || 
	"抓"+obj->name() !=me->query("quest/quest") &&
	"取"+obj->name() !=me->query("quest/quest") ) {
        tell_object(me,ob->query("name")+"疑惑的看着你说：想送我礼呀！我可不缺这个。\n");
        return 0;
    } if ( me->query("oldquest/task_time") && ( me->query("oldquest/task_time")<time()) ) {
        delay_duan_quest(me,0);
    } else {
	bonus=me->query("quest/bonus");
        me->add( "class_score/镇南王府",bonus);
        printf(HIR"->你对镇南王府的忠诚度升高 %s 点\n"NOR,
            chinese_number(bonus) );
        if ( p_score=me->query("quest/positive_score") ) {
            p_score *= (1+random(me->query_kar())/15);
            me->add("positive_score",p_score);
            printf(HIG"->正评价升高 %s 点\n"NOR, chinese_number(p_score) );
        } if( n_score=me->query("quest/negative_score") ) {
            n_score *= (1+random(me->query_kar())/15);
            me->add("negative_score",n_score);
            printf(HIC"->负评价升高 %s 点\n"NOR,chinese_number(n_score) );
        }
	me->set_marks( "last_quest", me->query("quest/quest") );
	me->set_marks( "quest_result", "reward" );
        me->delete("quest");
    }
    call_out("destruct_quest_object",1,obj);
    return 1;
}

void destruct_quest_object(object obj)
{
	destruct(obj);
}

void delay_duan_quest(object me,int num)
{
    object ob=this_object();

    num+=60-me->query_kar()-me->query_per();
    if (num<1) num=1;
    message_vision(
"$N对$n一甩袍袖：“真没用，这么久才回来！我真是看错了人。”\n",ob,me);
    tell_object( me, HIW
"->你对镇南王府的忠诚度下降了 " + chinese_number(num) + " 点！\n"NOR);
    me->add("class_score/镇南王府", -num);
    me->set("oldquest/task_time",time() );
    me->set_marks( "last_quest",me->query("quest/quest") );
    me->set_marks( "quest_result", "delay" );
    me->delete("quest");
}

void fail_duan_quest(object me)
{
	delay_duan_quest(me,10);
	me->set_marks( "quest_result", "fail" );
}