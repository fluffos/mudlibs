int do_rideyz()
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
        ob->move("/d/fuzhou/rongcheng");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/dongdajie");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/dongjiekou");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/xidajie");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/ximendajie");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/ximen");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad11");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad9");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad8");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/yanping");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/erbapu");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/fuzhou/fzroad1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad4");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/quanzhou/qzroad1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/taishan/yidao1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/taishan/yidao");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/dongmen");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/dongdajie2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/dongdajie1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
        ob->move("/d/city/majiu");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路順利到達揚州。\n");
        message_vision("\n$N身形一轉，躍下馬來，姿態十分優美。閑人也給$N一大哄 !\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
