inherit ITEM;
//add by luoyun
void create()
{
        set_name("信件", ({"xin", "letter"}));
        set("weight", 5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是信差托付你的信件。\n");
                set("unit", "封");
                set("no_get", 1);
set("no_put", 1);//add by luoyun
        }
        setup();
}



void init()
{
        add_action("do_give", "give");

        if(query("target") ) {
                remove_call_out("set_target");
                call_out("set_target", 6, query("target"));
                delete("target");               // add 4 seconds' delay, can't be so fast
        }
}

void set_target(string target)
{
        set("target", target);
}

int do_give(string arg)
{
        object me,ob;
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
                tell_object(me,"你想要把信交给谁？\n");
                return 1;
        }
        if( ob->short() != query("target")) {
                tell_object(me, "你不能把信交给这个人。\n");
                return 1;
        }
        if(!living(ob) ) {
                tell_object(me,ob->query("name")+"已经无法收下这样东西了。\n");
                return 1;
        }

        message("vision",me->name()+"拿出一封信交给了" + ob->name() + "。\n", environment(me),({ me, ob }));
        if((time() > me->query( "letter/task_time" )) ) {
                tell_object(me,ob->name()+"拿起信看了看，生气地瞪了你一眼。\n");
                tell_object(me, "你没有及时把信送到" + ob->query("name") + "的手中，你的任务失败了！\n");
        } else {
                tell_object(me,ob->name()+"说道：多谢，多谢！\n");
                tell_object(me, "你成功地把信送到了" + ob->name() + "的手中。\n");
                //i = random(80)+( me->query("letter/task_time")-time())/3;//原来奖励
                i = random(80000)+( me->query("letter/task_time")-time())*3;//修改后的奖励
                tell_object(me, sprintf(WHT"你获得了%s点战斗经验！\n"NOR, chinese_number(i)) );
                me->add("combat_exp", i);
                me->add("potential",i/4);
                //me->add("potential",i/20+1);//原来奖励
                tell_object(me, sprintf(WHT"%s点潜能\n"NOR, chinese_number(i/4)) );
                ob=new(SILVER_OB);
                if (!ob->move(me))
                      ob->move(environment(me));
                      ob->add_amount(random(50)+30);
                me->delete("letter");
        }
        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);
        destruct(this_object());
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

