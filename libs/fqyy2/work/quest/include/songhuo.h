// songhuo.h 送货任务
// derondog@xhcII

object OBJ;

string ask_job()
{
        object me;
        int time, swt;
        string str;
        me = this_player();
        time = 400 + random(100);
        swt = random(8);

        if ( base_name(environment(this_object()))!="/d/quanzhou/haigang" )
                return "嗯～～，难办啊……\n";

//        if ( me->query("combat_exp") > 300000 )
//                return "不知阁下做这些事情是否觉得大材小用呢？\n";

        if ( me->query_str() < 25 )
                return "阁下身体太过单薄，我担心你受不了这个苦啊！\n";

        if ( me->query_dex() < 25 )
                return "阁下脚下功夫可能还差了点，我担心你无法及时把货物送到。\n";

        if ( me->query("quest/quest_type")=="送货" )
                return "我不是给了你任务了吗？\n";

        if ( me->query("quest") )
                return "你还有其他的任务吧？”\n";

        if ( me->query("fail_time") && me->query("fail_time") + 300 > time() )
                return "你上一次任务失败了，我是不会相信你的。”\n";

        me->set("quest/quest_type", "送货");
        me->set("quest/task_time", time() + time); 
        me->set("quest/time", time);

        OBJ = new("/quest/obj/pingbanche");
        OBJ->move(environment(this_object()));
        OBJ->set("time", time() + time);
        OBJ->set_name(me->name(1) + "的平板车", ({ me->query("id") + "'s che", "che" }));

        switch(swt) {
                case 0:
                        OBJ->set("dst", "/d/city/kedian");
                        me->set("quest/quest", "去扬州客栈");
                        str = "请你把这车货送到扬州客栈，我会给些好处。\n";
                        break;
                case 1:
                        OBJ->set("dst", "/d/city/datiepu");
                        me->set("quest/quest", "去扬州铁匠铺");
                        str = "请你把这车货送到扬州铁匠铺，我会给些好处。\n";
                        break;
                case 2:
                        OBJ->set("dst", "/d/city2/kedian");
                        me->set("quest/quest", "去北京客店");
                        str = "请你把这车货送到北京客店，我会给些好处。\n";
                        break; 
                case 3:
                        OBJ->set("dst", "/d/changan/ca8");
                        me->set("quest/quest", "去长安打铁铺");
                        str = "请你把这车货送到长安打铁铺，我会给些好处。\n";
                        break; 
                case 4:
                        OBJ->set("dst", "/d/changan/ca2");
                        me->set("quest/quest", "去长安万福酒楼");
                        str = "请你把这车货送到长安万福酒楼，我会给些好处。\n";
                        break;
                case 5:
                        OBJ->set("dst", "/d/dali/kezhan");
                        me->set("quest/quest", "去大理客栈");
                        str = "请你把这车货送到大理客栈，我会给些好处。\n";
                        break;
                case 6:
                        OBJ->set("dst", "/d/city3/kedian");
                        me->set("quest/quest", "去成都假日客店");
                        str = "请你把这车货送到成都假日客店，我会给些好处。\n";
                        break;
                case 7:
                        OBJ->set("dst", "/d/city3/mujiangpu");
                        me->set("quest/quest", "去成都木匠铺");
                        str = "请你把这车货送到成都木匠铺，我会给些好处。\n";
                        break;
                case 8:
                        OBJ->set("dst", "/d/nanyang/kedian1");
                        me->set("quest/quest", "去南阳悦来客栈");
                        str = "请你把这车货送到南阳悦来客栈，我会给些好处。\n";
                        break;
                default :
                        str = "出错啦！！请通知在线的管理员解决！！或者在巫师会客室留言。\n";
                        }
        tell_object(me, WHT + str + NOR);
        return "快点动身吧！\n";
}

string ask_fail()
{
        object me = this_player();
        
        if ( me->query("quest/quest_type")!="送货" || !me->query("quest") )
                return "你脑袋有包啊？我又没有给你什么任务！";

        if ( objectp(OBJ) ) {
                message_vision("一个零担行的伙计跑了过来，推着$N向前方离去了。\n", OBJ);
                destruct(OBJ);
                }

        me->delete("quest");
        me->set("fail_time", time());
        return "唉，这点小事情都做不好，你也太龌龊了吧！\n";
}

