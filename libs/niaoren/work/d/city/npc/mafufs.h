int do_ridefs()
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
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/nandajie1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/nandajie2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/nanmen");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/wudang/wdroad1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/wudang/wdroad2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/wudang/wdroad3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/wudang/wdroad4");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hsroad1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hsroad2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hsroad3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hengyang");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hengyang1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hsroad4");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hsroad5");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/henshan/hsroad9");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/foshan/nanling");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/foshan/northgate");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/foshan/street3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/foshan/street4");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/foshan/yingxionglou");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/foshan/majiu");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路順利到達佛山。\n");
        message_vision("\n$N身形一轉，躍下馬來，姿態十分優美。閑人也給$N一大哄 !\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
