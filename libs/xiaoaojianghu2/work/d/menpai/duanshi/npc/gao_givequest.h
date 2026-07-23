//高升泰给的高级任务
           
/*
高升泰的任务分类：
【巡逻王府】：1；已经实现
【巡逻城市】：2；已经实现
【巡逻国土】：3；已经实现
【收回虎符】：4；
【信件传递】：5；
【守卫大门】：6；
【杀死玩家】：7；
*/
/*
玩家身上应该有的标志：
领有任务的标志：marks/段/have_gao_quest；
任务开始的时间：marks/段/start_gao_quest；
任务持续的时间：marks/段/have_gao_quest_time；
任务的类型标志：marks/段/have_gao_quest（这个标志是两用的）；
任务完成的时间：marks/段/finish_gao_quest；
任务失败的标志：marks/段/fail_gao_quest；
*/
            
int give_quest()
{
    object me = this_player();
    object ob = this_object();
    object obj;
    int num1;

    if( me->query("class") != "duanshi" )
    {
        message_vision("$N有些吃惊：“这位朋友不是取笑在下吧？”\n", ob);
        return 1;
    }
    if( me->query("title") != "大理国武官"
        && me->query("title") != YEL"镇南王府卫士"NOR )
    {
        message_vision("$N摇头道：“你资历和功夫尚浅，这些任务对你不合适。”\n", ob);
        return 1;
    }
    if( ob->query("quest_num") == 0 )
    {
        message_vision("$N笑着说：“你来晚啦，任务都分派下去了。”\n", ob);
        return 1;
    } 
    if( me->query("marks/段/have_gao_quest") != 0 )
    {
        if( ( me->query("marks/段/start_gao_quest") + 
          me->query("marks/段/have_gao_quest_time") ) 
          < time() )
        {
            num1 = random( 40 - me->query("kar") ) + 5;
            message_vision(
"$N对$n一甩袍袖：“真没用，这么半天才回来！我真是看错了人。”\n",
this_object(), me );
            tell_object( me, WHT
"->你对镇南王府的忠诚度下降了 " + CHINESE_D->chinese_num(num1) + " 点！\n"NOR);
            me->add("class_score/镇南王府", -num1);
            me->set("marks/段/fail_gao_quest", 1);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;  
        }
        message_vision("$N一皱眉：“你不是已经领了任务了吗？怎么不快去？！”\n", ob);
        return 1;
    }
    if( ( me->query("mud_age") - me->query("marks/段/finish_gao_quest") ) 
        < ( 900 - me->query("kar")*30 ) )
    {
        message_vision("$N轻轻摇了摇头：“你也辛苦啦，先回去休息吧。”\n", ob);
        return 1;
    }
    if( me->query("marks/段/fail_gao_quest") )
    {
        command( "say “嗯……好吧，我就再给你个将功补过的机会。”" );
        me->delete("marks/段/fail_gao_quest");
    }
    switch ( random( 3 ) )
    {
        case 0:
            remove_call_out( "give_quest_1" );
            call_out( "give_quest_1", 1, me );
            break;
        case 1:
            remove_call_out( "give_quest_2" );
            call_out( "give_quest_2", 1, me );
            break;
        case 2:
            remove_call_out( "give_quest_3" );
            call_out( "give_quest_3", 1, me );
            break;
        case 3:
            remove_call_out( "give_quest_4" );
            call_out( "give_quest_4", 1, me );
            break;
/*        case 4:
            give_quest_5( me );
            break;
        case 5:
            give_quest_6( me );
            break;
        case 6:
            give_quest_7( me );
            break;
*/    }
    return 1;
}

void give_quest_1( object me )
{
    object obj, ob = this_object();
    int time = random( 120 ) + 180;
    obj = new( __DIR__"obj/yaopai0");
    obj->move( me );
    me->set( "marks/段/have_gao_quest", 1 );
    ob->add( "quest_num", -1 );
    me->set( "marks/段/start_gao_quest", time() );
    me->set( "marks/段/have_gao_quest_time", time );
    tell_object( me, WHT"\n"+
"高升泰说道：“嗯，现在听说有四大恶人要来府中闹事，需要人手四处巡视，加强戒备\n" +
"你就凭此腰牌四处巡视一下吧；你快去快回。要在"
     + CHINESE_D->chinese_number( time/60 ) + "分"
     + CHINESE_D->chinese_number( time - time/60*60  ) + "秒"
     "内把腰牌缴回来。”\n然后交给你一块腰牌。\n" );
}

void give_quest_2( object me )
{
    object obj, ob = this_object();
    int time = random( 120 ) + 180;
    obj = new( __DIR__"obj/yaopai1");
    obj->move( me );
    me->set( "marks/段/have_gao_quest", 2 );
    ob->add( "quest_num", -1 );
    me->set( "marks/段/start_gao_quest", time() );
    me->set( "marks/段/have_gao_quest_time", time );
    tell_object( me, WHT"\n"+
"高升泰说道：“据说现在城里治安不是很好，请府里面出人帮忙治理，\n" +
"你就凭此腰牌四处巡视一下吧；你快去快回。要在"
     + CHINESE_D->chinese_number( time/60 ) + "分"
     + CHINESE_D->chinese_number( time - time/60*60  ) + "秒"
     "内把腰牌缴回来。”\n然后交给你一块腰牌。\n" );
}

void give_quest_3( object me )
{
    object obj, ob = this_object();
    int time = random( 120 ) + 180;
    obj = new( __DIR__"obj/yaopai2");
    obj->move( me );
    me->set( "marks/段/have_gao_quest", 3 );
    ob->add( "quest_num", -1 );
    me->set( "marks/段/start_gao_quest", time() );
    me->set( "marks/段/have_gao_quest_time", time );
    tell_object( me, WHT"\n"+
"高升泰说道：“现在我派你出去到我大理和大宋边境的大渡河边去\n" +
"巡视一趟，看看有没有什么异常情况，防人之心不可无啊。你快去\n" +
"快回，要在" + CHINESE_D->chinese_number( time/60 ) + "分"
    + CHINESE_D->chinese_number( time - time/60*60  ) + "秒"
    + "内把腰牌缴回来。”\n然后交给你一块腰牌。\n" );
}

void give_quest_4( object me )
{
    object obj, ob = this_object();
    string name;
    string *second_name = ({
"升", "晋", "添", "增", "和", "思", "全", "德","崇","保","有","佑","万","千","百","允","元","建",
                    });
    string *last_name = ({
"忠", "孝", "仁" ,"义", "信", "礼", "诚", "福","寿","禄","家","邦","吉","祥","宝","胜","文","武",
                    });
    int time = random( 300 ) + 300;
    obj = new( __DIR__"obj/half_hufu");
    name = "段" + 
        second_name[random(sizeof(second_name))] + 
        last_name[random(sizeof(last_name))];
    obj->set( "need_name", name );
    obj->move( me );
    me->set( "marks/段/have_gao_quest", 4 );
    ob->add( "quest_num", -1 );
    me->set( "marks/段/start_gao_quest", time() );
    me->set( "marks/段/have_gao_quest_time", time );
    tell_object( me, WHT"\n"+
"高升泰严肃地说：“现在情况有些紧张，你速凭这半块虎符找黄衣卫士\n"
+ name + "取回另外半块虎符，这样一旦出事我们可以调动军队。军情紧急，\n"
+ "你要在"
+ CHINESE_D->chinese_number( time/60 ) + "分"
+ CHINESE_D->chinese_number( time - time/60*60  ) + "秒"
+ "内把虎符缴回来。”" );
}
    
int accept_object( object me, object obj)
{
    int lost_score, i, room_num, num1, num2;
    string *map;
//下面是给几个比较大的任务
    if( obj->query("name") == RED"巡逻腰牌"NOR )
    {
        if( me->query("marks/段/have_gao_quest") != 1 )
        {
            command( "? " + me->query("id") );
            command( "say “你从哪里得来的这个腰牌啊？”");
            call_out( "accept2", 1, obj );
            return 1;
        }
        if( ( me->query("marks/段/start_gao_quest") + 
          me->query("marks/段/have_gao_quest_time") ) 
          < time() )
        {
            num1 = random( 40 - me->query("kar") + 5);
            message_vision(
"$N对$n一甩袍袖：“真没用，这么半天才回来！我真是看错了人。”\n",
this_object(), me );
            tell_object( me, WHT
"->你对镇南王府的忠诚度下降了 " + CHINESE_D->chinese_num(num1) + " 点！\n"NOR);
            me->add("class_score/镇南王府", -num1);
            me->set("marks/段/fail_gao_quest", 1);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            call_out( "accept2", 1, obj );
            return 1;  
        }
        me->set("marks/段/finish_gao_quest", time() );    
        map = obj->show_map();
        room_num = 0;
        for( i = 0; i<sizeof(map); i++ )
        {
            if( map[i] == YEL"$$"NOR )
                room_num++;
        }            
        if( room_num < 20 )
        {
            num1 = room_num/6 + random(3); 
            me->add("class_score/镇南王府", num1);
            tell_object( me, WHT
"高升泰有些惊奇：“你这么半天干什么去啦？就转了这么几个地方，\n"
"早知道就让别人去了……不过你也算辛苦一场，休息去吧。”\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 )
 + "点！\n"NOR);
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( room_num < 40 )
        {
            num1 = room_num/5 + random(3); 
            me->add("class_score/镇南王府", num1);
            tell_object( me, WHT
"高升泰略显不快：“哦，走了这么些地方，不知道有什么其他情况？……\n"
"嗯，还要派人去别的地方巡视一下，你休息去吧。”\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 )
 + "点！\n"NOR);
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( room_num < 60 )
        {
            num1 = room_num/4 + random(3); 
            me->add("class_score/镇南王府", num1);
            tell_object( me, WHT
"高升泰点点头：“噢，巡视的地方不少啊，还不错，有点用。”\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 )
 + "点！\n"NOR);
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( room_num < 80 )
        {
            num1 = room_num/3 + random(3); 
            me->add("class_score/镇南王府", num1);
            tell_object( me, WHT
"高升泰比较满意：“效率满高的嘛，走了这么多地方，要是府里\n"
"这样的干才多几个就好了。快休息去吧。”\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 )
 + "点！\n"NOR);
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( room_num < 100 )
        {
            num1 = room_num*5/2 + random(3); 
            me->add("class_score/镇南王府", num1);
            tell_object( me, WHT
"高升泰相当满意：“嗬，真不错啊，几乎都跑遍了，府里\n"
"这样的人才真是少见啊。快好好休息一下吧！\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 ) 
 + "点！\n"NOR);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            call_out( "accept2", 1, obj );
            return 1;
        }
        else
        {
            num1 = room_num*5/2 + random(3); 
            me->add("class_score/镇南王府", num1);
            tell_object( me, WHT
"高升泰相当满意：“嗬，真不错啊，几乎都跑遍了，府里\n"
"这样的人才真是少见啊。快好好休息一下吧！\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 )
 + "点！\n"NOR);
            if( !random(2) )
            {
                if( !random(2) )
                {
                    if( me->query_xiuwei_by_type("unarmed")<1800 )
                    {
                        num2 = me->query("spi")/5;
                        me->improve_xiuwei("unarmed", num2);
                        tell_object( me, WHT
"高升泰一时兴起：“我指点指点你的拳脚功夫吧！”\n"RED
"你的拳脚修为上升了！\n"NOR);
                    }
                }
                else
                {
                    if( me->query_xiuwei_by_type("dodge")<1800 )
                    {
                        num2 = me->query("spi")/5;
                        me->improve_xiuwei("dodge", num2);
                        tell_object( me, WHT
"高升泰一时兴起：“我指点指点你的轻功身法吧！”\n"RED
"你的轻功修为上升了！\n"NOR);
                    }       
                }        
            }
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
    }
    if( obj->query("name") == YEL"巡逻腰牌"NOR )
    {
        if( me->query("marks/段/have_gao_quest") != 2 )
        {
            command( "? " + me->query("id") );
            command( "say “你从哪里得来的这个腰牌啊？”");
            call_out( "accept2", 1, obj );
            return 1;
        }
        if( ( me->query("marks/段/start_gao_quest") + 
          me->query("marks/段/have_gao_quest_time") ) 
          < time() )
        {
            num1 = random( 40 - me->query("kar") ) + 5;
            message_vision(
"$N对$n一甩袍袖：“真没用，这么半天才回来！我真是看错了人。”\n",
this_object(), me );
            tell_object( me, WHT
"->你对镇南王府的忠诚度下降了 " + CHINESE_D->chinese_num(num1) + " 点！\n"NOR +
"->你的负声望增加了 " + CHINESE_D->chinese_num(num1*10) + " 点！\n"NOR +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_num(num1*5) + " 点！\n"NOR);
            me->add("class_score/镇南王府", -num1);
            me->add("negative_score", num1*10); 
            me->add("social_exp", num1*5);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;  
        }
        me->set("marks/段/finish_gao_quest", time() );    
        map = obj->show_map();
        room_num = 0;
        for( i = 0; i<sizeof(map); i++ )
        {
            if( map[i] == YEL"$$"NOR )
                room_num++;
        }            
        if( room_num < 10 )
        {
            num1 = room_num/2 + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("positive_score", num1*10); 
            me->add("social_exp", num1*5);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            tell_object( me, WHT
"高升泰有些惊奇：“你这么半天干什么去啦？就转了这么几个地方，\n"
"早知道就让别人去了……不过你也算辛苦一场，休息去吧。”\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 ) + "点！\n" +
"->你的正声望增加了 " + CHINESE_D->chinese_num(num1*10) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_num(num1*5) + " 点！\n"NOR);
            call_out( "accept2", 1, obj );
            return 1;
        }
        if( room_num < 19 )
        {
            num1 = room_num + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("positive_score", num1*10); 
            me->add("social_exp", num1*5);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            tell_object( me, WHT
"高升泰相当满意：“嗬，真不错啊，几乎都跑遍了，府里\n"
"这样的人才真是少见啊。快好好休息一下吧！\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 ) + "点！\n" +
"->你的正声望增加了 " + CHINESE_D->chinese_num(num1*10) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_num(num1*5) + " 点！\n"NOR);
            call_out( "accept2", 1, obj );
            return 1;
        }
        else
        {
            num1 = room_num + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("positive_score", num1*10); 
            me->add("social_exp", num1*5);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            tell_object( me, WHT
"高升泰相当满意：“嗬，真不错啊，几乎都跑遍了，府里\n"
"这样的人才真是少见啊。快好好休息一下吧！\n"YEL
"->你对镇南王府的忠诚度上升了" + CHINESE_D->chinese_number( num1 ) + "点！\n" +
"->你的正声望增加了 " + CHINESE_D->chinese_num(num1*10) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_num(num1*5) + " 点！\n"NOR);
            if( !random(10) )
            {
                if( !random(2) )
                {
                    if( me->query_xiuwei_by_type("unarmed")<1800 )
                    {
                        num2 = me->query("spi")/4;
                        me->improve_xiuwei("unarmed", num2);
                        tell_object( me, WHT
"高升泰一时兴起：“我指点指点你的拳脚功夫吧！”\n"RED
"你的拳脚修为上升了！\n"NOR);
                    }
                }
                else
                {
                    if( me->query_xiuwei_by_type("dodge")<1800 )
                    {
                        num2 = me->query("spi")/4;
                        me->improve_xiuwei("dodge", num2);
                        tell_object( me, WHT
"高升泰一时兴起：“我指点指点你的轻功身法吧！”\n"RED
"你的轻功修为上升了！\n"NOR);
                    }       
                }        
            }
            call_out( "accept2", 1, obj );
            return 1;
        }
    }
    if( obj->query("name") == CYN"巡逻腰牌"NOR )
    {
        if( me->query("marks/段/have_gao_quest") != 3 )
        {
            command( "? " + me->query("id") );
            command( "say “你从哪里得来的这个腰牌啊？”");
            call_out( "accept2", 1, obj );
            return 1;
        }
        if( ( me->query("marks/段/start_gao_quest") + 
          me->query("marks/段/have_gao_quest_time") ) 
          < time() )
        {
            num1 = random( 40 - me->query("kar") + 5);
            message_vision(
"$N对$n一甩袍袖：“真没用，这么半天才回来！我真是看错了人。”\n",
this_object(), me );
            tell_object( me, WHT
"->你对镇南王府的忠诚度下降了 " + CHINESE_D->chinese_num(num1) + " 点！\n" +
"->你的负声望增加了 " + CHINESE_D->chinese_num(num1*10) + " 点！\n"NOR);
            me->add("class_score/镇南王府", -num1);
            me->add("negative_score", num1*10); 
            me->set("marks/段/fail_gao_quest", 1);
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            call_out( "accept2", 1, obj );
            return 1;  
        }
        me->set("marks/段/finish_gao_quest", time() );    
        map = obj->show_map();
        room_num = 0;
        for( i = 0; i<sizeof(map); i++ )
        {
            if( map[i] == YEL"$$"NOR )
                room_num++;
        }            
        num1 = me->query("marks/段/start_gao_quest") +
            me->query("marks/段/have_gao_quest_time") - time();
        num2 = me->query("marks/段/have_gao_quest_time");
        if( room_num < 1 )
        {
            me->add("class_score/镇南王府", -num1/8);
            me->add("negative_score", num1/2);
            tell_object( me, WHT
"高升泰惊奇万分：“你这么半天干什么去啦？没到地方就回来啦？！\n"
"早知道就让别人去了……不过你也算辛苦一场，休息去吧。”\n"YEL
"->你对镇南王府的忠诚度下降了 " + CHINESE_D->chinese_number( num1/8 ) + " 点！\n" +
"->你的负声望增加了 " + CHINESE_D->chinese_number( num1/2 ) + " 点！\n"NOR); 
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( num2/num1 < 2 )
        {
            num1 = num2*10/num1 + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("social_exp", num1*8);
            tell_object( me, WHT
"高升泰略显不快：“哦，走了这么长时间，不知道有什么情况变化？……\n"
"嗯，还要派人再去那地方巡视一下，你休息去吧。”\n"YEL
"->你对镇南王府的忠诚度上升了 " + CHINESE_D->chinese_number( num1 ) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_number( num1*8 ) + " 点！\n"NOR); 
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( num2/num1 < 3 )
        {
            num1 = num2*11/num1 + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("social_exp", num1*8);
            tell_object( me, WHT
"高升泰点点头：“噢，巡视的速度挺快啊，还不错，这些情况有点用。”\n"YEL
"->你对镇南王府的忠诚度上升了 " + CHINESE_D->chinese_number( num1 ) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_number( num1*8 ) + " 点！\n"NOR); 
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( num2/num1 < 4 )
        {
            num1 = num2*12/num1 + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("social_exp", num1*8);
            tell_object( me, WHT
"高升泰比较满意：“效率满高的嘛，这么快就回来了，要是府里\n"
"这样的干才多几个就好了。快休息去吧。”\n"YEL
"->你对镇南王府的忠诚度上升了 " + CHINESE_D->chinese_number( num1 ) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_number( num1*8 ) + " 点！\n"NOR); 
            call_out( "accept2", 1, obj );
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            return 1;
        }
        if( num2/num1 < 5 )
        {
            num1 = num2*13/num1 + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("social_exp", num1*8);
            tell_object( me, WHT
"高升泰相当满意：“嗬，真不错啊，这么及时的情报真是宝贵，府里\n"
"这样的人才真是少见啊。快好好休息一下吧！\n"YEL
"->你对镇南王府的忠诚度上升了 " + CHINESE_D->chinese_number( num1 ) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_number( num1*8 ) + " 点！\n"NOR); 
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            call_out( "accept2", 1, obj );
            return 1;
        }
        else
        {
            num1 = num2*14/num1 + random(3); 
            me->add("class_score/镇南王府", num1);
            me->add("social_exp", num1*8);
            tell_object( me, WHT
"高升泰相当满意：“嗬，真不错啊，这么及时的情报真是宝贵，府里\n"
"这样的人才真是少见啊。快好好休息一下吧！\n"YEL
"->你对镇南王府的忠诚度上升了 " + CHINESE_D->chinese_number( num1 ) + " 点！\n" +
"->你的江湖阅历增加了 " + CHINESE_D->chinese_number( num1*8 ) + " 点！\n"NOR); 
            me->delete( "marks/段/have_gao_quest" );
            me->delete( "marks/段/start_gao_quest" );
            me->delete( "marks/段/have_gao_quest_time" );
            call_out( "accept2", 1, obj );
            return 1;
        }
    }
}

void accept2( object obj )
{
    if( !obj )
        return;
    destruct( obj );
    return;
}
