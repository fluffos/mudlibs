void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object me = this_player();
        object boss = present(query("work/boss"), environment(me));
        string respect = RANK_D->query_respect(me);
        object* inv;
        int i;

        if(me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if(!objectp(boss) || !living(boss))
                return notify_fail("现在没人给你安排工作，等一等吧。\n");
        if(me->query("age")<18)
        {
                write(CYN+boss->name()+"笑道：「"+respect+"说笑了，我可不敢雇用童工，还是长大些再来吧！」\n"NOR);
                return 1;
        }
        inv = all_inventory(this_object());
        for(i=sizeof(inv)-1; i>=0; i--)
        {
                if(inv[i] == me)
                        continue;
                if(inv[i]->query("class") == "bonze")
                        continue;
                if(inv[i]->name()[0..<2] == me->name()[0..<2])
                {
                        write(CYN+boss->name()+"皱了皱眉，道：「已经有一位姓"+me->name()[0..<2]+"的在干活了，"
                                +respect+"还是去别处看看吧。\n"NOR);
                        return 1;
                }
                else if(inv[i]->query("id")[0..<1] == me->query("id")[0..<1])
                {
                        write(CYN+boss->name()+"皱了皱眉，道：「已经有一位"+me->query("id")[0..<1]+"在干活了，"
                                +respect+"还是去别处看看吧。\n"NOR);
                        return 1;
                }
        }
        me->start_busy(2);
        message_vision(query("work/msg"+random(query("work/msg_num"))), me);
        if(random(2) && me->query_temp("apply/"+query("work/gift")) < 30)
        {
                write(HIR"你感到你的"+query("work/gift_name")+"提高了！\n"NOR);
                me->add_temp("apply/"+query("work/gift"), 1);
        }
        return 1;
}
