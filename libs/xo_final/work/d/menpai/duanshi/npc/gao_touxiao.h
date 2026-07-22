//这是高升泰对新人投效的反应
int do_accept_me()
{               
    object obj, me=this_player();

    if( me->query("class")=="duanshi" )
    {
        command("smile "+me->query("id") );
        command("say “这位"+RANK_D->query_respect(me)+
        "，你现在已经在为大理皇家效力了，无须再问我了。”");
    }
    else
    {
        if( me->query("family")!=0 )
        {
            command("say “呵呵，"+RANK_D->query_respect(me)+
            "既然已经有名师高就，怎好再屈就这卫士之职呢？”");
            command("shake "+me->query("id"));
        }
        else
        {
            if( me->query("marks/艺成")==0 )
            {
                command("smile "+me->query("id") );
                command("say “这位"+RANK_D->query_respect(me)+
                "恐怕学艺尚不够精深，不如先到王府作一名家丁如何？”");
            }
            else
            {                               
                if( !me->query_temp("marks/段/拿到令牌") )
                {
                    switch( me->query("marks/艺成") )
                    {
                        case "无量剑派东宗":
                            command("nod");
                            command("say “左先生是我们素来久仰的，他门下的弟子想来不会错。”");
                            break;
                        case "无量剑派西宗":
                            command("nod");
                            command("say “辛掌门是位巾帼英雄，她门下的弟子自然是出类拔萃。”");
                            break;
                        case "伏牛派":
                            command("nod");
                            command("say “南阳柯老英雄急公好义，世人尽知，伏牛的弟子自然个个是英雄好汉。”");
                            break;
                        case "崆峒派":
                            command("nod");
                            command("say “木灵子道长以七伤拳名动江湖，在下佩服之致。想来"+RANK_D->query_respect(me)+"已尽得木道长真传。”");
                            break;
                        case "少林派":
                            command("nod");
                            command("say “江湖上无人不知天下武功出少林，现在"+RANK_D->query_respect(me)+"肯为大理皇家效力，高某深感荣幸。”");
                            break;
                        case "蓬莱派":
                            command("nod");
                            command("say “周老镖头在江湖上闯荡多年，我等虽远在大理也听说过威名。”");
                        break;
                    }
                    command("say “我替王爷收下你了！你可凭我的令牌找四大卫护学功夫，担任卫士一职。”");
                    obj = new(__DIR__"obj/lingpai");
                    obj->move(me);
                    me->set_temp("marks/段/拿到令牌");
                    message_vision("$N交给$n一块令牌。\n",this_object(), me);
                }
                else
                {
                    command("say “拿了我的令牌就可以了，不必再找我了。”\n");
                }
            }
        }
    }
    return 1;
}
