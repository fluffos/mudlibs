// ai.c


int main(object me, string arg)
{
        mapping fa1,fa2;
        object ob,obj;
        seteuid(getuid());
        if(!arg||!objectp(ob=present(arg,environment(me))) ) 
                return notify_fail("你想和谁亲热?\n");

        if (me->query("marry/lover")!=ob->query("id")) 
                return notify_fail("只有夫妻间才能亲热.\n");

        if (!(userp(ob)))
            return notify_fail("你是不是在装糊涂呀？这不是你爱人！\n");

        if (me->query("jing") < 50)
                return notify_fail("你现在精太少了，还是身子骨要紧啊！\n");

        if (!(environment(me)->query("owner") == me->query("id") || environment(me)->query("owner") == ob->query("id")))
                return notify_fail("你们也不怕被人看见?\n");

         if(me->query_condition("make_love")!=0)
                return notify_fail("刚作完还想来,神仙也受不了啊!\n");

        if (me->query("gender") == "男性")
        {
            message_vision("$N有些不怀好意地看着$n，嘴角露出暧昧的笑容......\n",me,ob);
        }
        else {  message_vision("$N看了$n一眼，脸唰地红了起来，不好意思地转过头去，轻轻地咬着嘴唇......\n",me,ob); }

        if(undefinedp(obj=ob->query_temp("ai_dest"))||obj!=me)  
        {
                me->set_temp("ai_dest",ob);
                return 1;
        }
        if(me->query("gender")=="男性")
        { 
                message_vision("$N羞红了脸,低下头去.\n",ob);
                message_vision("$N轻轻抱起$n走向床边.\n",me,ob); 
        }
        else
        { 
                message_vision("$n呵呵地朝着$N笑.\n",me,ob);
                message_vision("$n轻轻抱起$N走向床边.\n",me,ob); 
        }
        message_vision("\n......................\n.................\n............\n..........\n......\n....\n..\n.\n\n\n",me,ob);
        me->set_temp("block_msg/all",1);
        ob->set_temp("block_msg/all",1);
        me->disable_player("<...中>");
        ob->disable_player("<...中>");
        remove_call_out("wake");
        call_out("wake",25,me,ob);
        return 1;
}
void wake(object me,object ob)
{
        me->add("max_jingli",2);
		
		if (random(20) < SPECIAL_D->query_level(me, "loving-skill"))
		{
			// 特技效果
			ob->add("max_jingli", random(SPECIAL_D->query_level(me, "loving-skill")/2));
		}
        me->add("jing",-50);
        ob->add("jing",-50);
        me->enable_player();
        ob->enable_player();
        me->delete_temp("block_msg/all");
        ob->delete_temp("block_msg/all");
        me->delete("disable_type");
        ob->delete("disable_type");
        me->write_prompt();
        ob->write_prompt();
        me->apply_condition("make_love",30);
        ob->apply_condition("make_love",30);
        message_vision("不知过了多少时候, 床前红烛燃尽.\n",me,ob);
        tell_object(ob,me->name()+"坐起身来对着你笑.\n");
        tell_object(me,ob->name()+"坐起身来对着你笑.\n");
        me->delete_temp("ai_dest");
        ob->delete_temp("ai_dest");
}

int help(object me)
{
        write(@HELP
这个指令可以让夫妻之间作爱。主动提出亲热的一方最大精力可以增加2。
如果主动提出亲热的一方会房中秘术，则对方也可能会增加最大精力。
 
HELP
    );
    return 1;

}
