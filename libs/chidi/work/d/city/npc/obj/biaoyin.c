// mihan.c


inherit ITEM;

void create()
{
        set_name( "镖银", ({ "biao yin", "biao","yin" }) );
        set_weight(2000+random(3000));
        set("no_put", 1);                       // 这样东西不能放入容量
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "箱");
                set("long", "一箱镖局托付给你的镖银。\n");
        }
}

void init()
{
        add_action("do_give", "give");

        remove_call_out("attract_robber");
        call_out("attract_robber", 1);

        if(query("target") ) {
                remove_call_out("set_target");
                call_out("set_target", 4, query("target"));
                delete("target");               // add 4 seconds' delay, can't be so fast
        }
}

void set_target(string target)
{
        set("target", target);
}

int do_give(string arg)
{
        object me,ob,home;
        string obj,target;
        int i;
       if(!arg || arg==" ")
            return 0;
        if (sscanf(arg,"%s to %s", obj, target)!=2 )
                if(sscanf(arg,"%s %s", target, obj) !=2 )       
                        return 0;

        if(!id(obj) )   return 0;

        me = this_player();

        if(!ob = present(target,environment(me)) ) {
                tell_object(me,"你想要把镖银交给谁？\n");
                return 1;
        }
        if(!ob->id(query("target")) || userp(ob)) {
                tell_object(me, "你不能把这样东西给这个人。\n");
                return 1;
        }
        if(!living(ob) ) {
                tell_object(me,ob->query("name")+"已经无法收下这样东西了。\n");
                return 1;
        }

        if(!home = find_object(ob->query("startroom")) )
                home = load_object(ob->query("startroom"));
    if (environment(ob)!=home){
                message_vision(CYN+"$N说道：我现在正忙着呢！等我回去再说吧！"+NOR,ob);
        return 1;
    }
        message_vision("$N拿出一箱镖银交给了" + ob->query("name") + "。\n", me);
        if((time()-me->query( "biao_start" ))>me->query( "biao_time" ) ) {
                message_vision(CYN+"$N很生气地对$n说道：这么点儿事都办不好，真没用！\n"+NOR, ob, me);
                tell_object(me, "你没有及时把镖银送到" + ob->query("name") + "的手中，你的任务失败了！\n");
                me->set("biao_failed", 1);
        }
        else {
                message_vision(CYN+"$N对$n笑道：很好！这是一成的红利，你拿去吧！\n"+NOR, ob, me);
                tell_object(me, "你成功地将镖银送到了" + ob->query("name") + "的手中。\n");
                i = 250 + random(me->query( "biao_time" )-time()+me->query( "biao_start" ))/5;
                tell_object(me, sprintf(WHT"你获得了%s点战斗经验！\n"NOR, chinese_number(i)) );
                me->add("combat_exp", i);
                me->add("potential",i/20+1);
                tell_object(me, sprintf(WHT"%s点潜能\n"NOR, chinese_number(i/20+1)) );
                        ob=new(SILVER_OB);
                        if (!ob->move(me))
                                        ob->move(environment(me));
                        ob->add_amount(random(50)+30);
                me->delete("biao_start");
                me->delete("biao_time");
        }

        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);

        destruct(this_object());

        return 1;
}

// 设置强盗
void attract_robber()
{
        object ob, robber, room;

        if(!userp(ob = environment(this_object())) ) return;
        if (time()-ob->query( "biao_start" )>ob->query( "biao_time" )+300 ){
            destruct(this_object());
            return;
        }
        room = environment(ob);

        if(room->query("outdoors") && !present("mask robber",room) ) {
            robber = new("/d/npc/robber");
            robber->move(room);
            message_vision("$N走了过来。\n",robber);
        }

        remove_call_out("attract_robber");
        call_out("attract_robber", 1);
}
void owner_is_killed() { destruct(this_object()); }

