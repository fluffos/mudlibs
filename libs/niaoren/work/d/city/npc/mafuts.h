int do_ridets()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat 來人啦！"+ob->query("name")+
                "這個"+RANK_D->query_rude(ob)+"想偷馬！\n");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"紫騮馬"NOR;
                        break;
                case 2:
                        hname=RED"棗紅馬"NOR;
                        break;
                default:
                        hname=HIY"黃驃馬"NOR;
                        break;
        }
        message_vision(
"馬夫隨手給$N牽來一匹"+hname+"。$N翻身躍上馬背。動作瀟洒利索。路邊行人一陣
起哄: 喔噢喔噢。\n"NOR , ob );
        message_vision("\n只見$N騎兩腿一夾，"+hname+"穿過客店而去。\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/city/xidajie1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/city/xidajie2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/city/ximen");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/city/ximenroad");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/xxroad1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/xxroad2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/xxroad3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/jiayuguan");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/silk1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/silk2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/silk3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/silk4");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/shanjiao");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/beijiang");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n");
        ob->move("/d/xingxiu/majiu");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路順利到達天山腳下的北疆小鎮。\n");
        message_vision("\n$N身形一轉，躍下馬來，姿態十分優美。閑人也給$N一大哄。\n",ob);
        tell_room(environment(ob),hname+"一路疾馳到達天山腳下。\n");
        ob->delete_temp("marks/horserent");
        return 1;
}
