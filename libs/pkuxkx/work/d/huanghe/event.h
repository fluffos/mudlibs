
int valid_leave(object me,string dir)
{  
    int i;
    object clue;
	if (dir=="out")
    {
        me->delete_temp("riverpass");
        if (!this_player()->query_temp("hhquest")&& (int)me->query("combat_exp")-(int)me->query("hhquestexp")>(int)me->query("combat_exp")/100
            && (int)me->query("combat_exp")-(int)me->query("hhquestexp")>10000)
        {
    
        i=random(300); // 1/30概率触发渡船事件。
        this_player()->set_temp("hhquest",1);
        if (i>293+random(5)&&me->query("antirobot/deactivity")<2)
        {
            me->set("hhquestexp",me->query("combat_exp"));
            switch (random(6))
            {
                case 0:
                tell_object(this_player(),"你忽然发现旧船舷处刻的图案有些奇特，赶紧把它记录下来。\n");
                tell_object(this_player(),"你找到了一些奇怪的线索。\n");
                clue=new("/d/changjiang/obj/clue");
                clue->set("owner",this_player()->query("id"));
                clue->move(this_player());
                break;
                case 1:
                tell_object(this_player(),"船底处刻的图案有些奇特，你心中一动，把它牢记在心中。\n");
                tell_object(this_player(),"你找到了一些奇怪的线索。\n");
                clue=new("/d/changjiang/obj/clue");
                clue->set("owner",this_player()->query("id"));
                clue->move(this_player());
                break;
                case 2:
                tell_object(this_player(),"你摸摸了船顶的乌篷，把图案记在心里。\n");
                tell_object(this_player(),"你找到了一些奇怪的线索。\n");
                clue=new("/d/changjiang/obj/clue");
                clue->set("owner",this_player()->query("id"));
                clue->move(this_player());
                break;
                case 3:
                tell_object(this_player(),"船老大和你聊起过往听到的故事，有些还是很传奇的。\n");
                tell_object(this_player(),"你找到了一些奇怪的线索。\n");
                clue=new("/d/changjiang/obj/clue");
                clue->set("owner",this_player()->query("id"));
                clue->move(this_player());
                break;
                case 4:
                tell_object(this_player(),"水中有张纸一时浮起，一时沉下，你赶紧把它捞了起来。\n");
                tell_object(this_player(),"你找到了一些奇怪的线索。\n");
                clue=new("/d/changjiang/obj/clue");
                clue->set("owner",this_player()->query("id"));
                clue->move(this_player());
                break;
                case 5:
                    tell_object(me,"船上有一封信，你把它捡了起来。\n");
                   
                    clue=new("/d/changjiang/obj/letter");
                    clue->set("owner",me->query("id"));
                    clue->move(me);
                    break;
            }
            
        }
    }
    }
	return ::valid_leave(me, dir);
}