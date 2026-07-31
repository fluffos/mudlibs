int do_rideyz()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 来人啦！"+ob->query("name")+
                "这个"+RANK_D->query_rude(ob)+"想偷马！\n");
                return 1;
        }
        switch (random(4))
        {
                case 1:
                        hname=MAG"紫骝马"NOR;
                        break;
                case 2:
                        hname=RED"枣红马"NOR;
                        break;
                case 3:
                        hname=HIW"白骆驼"NOR;
                        break;
                default:
                        hname=HIY"黄骠马"NOR;
                        break;
        }
        message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上"+hname+"背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只见$N两腿一夹，"+hname+"穿过军营而去。\n",ob);
        if (ob->query("jing") > 1000) {
            ob->receive_damage("jing", 100);
        }
        if (ob->query("jing") > 200) {
            ob->receive_damage("jing", 50);
        }
        ob->receive_damage("jing", 30);
        ob->move("/d/city/majiu");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达扬州城。\n");
        message_vision("\n$N身形一转，轻松落地，姿态十分优美。闲人也给$N一大哄。\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
