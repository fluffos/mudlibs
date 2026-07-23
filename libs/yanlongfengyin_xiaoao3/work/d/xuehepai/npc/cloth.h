void init()
{
        object ob;
        object me=this_player();
        mapping fam=(mapping)me->query("family");
        
        if (interactive(me))
        {
                if (fam && fam["family_name"]=="血河派")
                {
                        if (me->query("combat_exp")>=100000 && me->query("combat_exp")< 1000000)
                        {
                                if (me->query("asked")>=1)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat 我现在代表掌门授予"+me->query("name")+"一道金血衣，以之鼓励!");
                                command("say 这件一道金的血衣你收好，它代表你在本派的地位。");
                                ob=new("/d/xuehepai/obj/cloth2");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth2");
                                me->set("asked",1);
                                return;
                        }
                        
                        if (me->query("combat_exp")>=1000000 && me->query("combat_exp")< 10000000)
                        {
                                if (me->query("asked")>=2)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat 我现在代表掌门授予"+me->query("name")+"两道金血衣，以之鼓励!");
                                command("say 这件两道金的血衣你收好，它代表你在本派的地位。");
                                ob=new("/d/xuehepai/obj/cloth3");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth3");
                                 me->set("asked",2);
                                return;
                        }                
                        if (me->query("combat_exp")>=10000000 && me->query("combat_exp")< 100000000)
                        {
                                if (me->query("asked")>=3)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat 我现在代表掌门授予"+me->query("name")+"三道金血衣，以之鼓励!");
                                command("say 这件三道金的血衣你收好，它代表你在本派的地位。");
                                ob=new("/d/xuehepai/obj/cloth4");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth4");
                                me->set("asked",3);
                                return;
                        }                
                        if (me->query("combat_exp")>=100000000)
                        {
                                if (me->query("asked")>=4)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat 我现在代表掌门授予"+me->query("name")+"四道金血衣，以之鼓励!");
                                command("say 这件四道金的血衣你收好，它代表你在本派的地位。");
                                ob=new("/d/xuehepai/obj/cloth5");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth5");
                                me->set("asked",4);
                                return;
                        }                
                }
        }
}

