string ask_for_join()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "峨嵋派")) 
        return ("你和峨嵋沒有淵源，貧尼不敢給你剃度。\n");
//    if ( (int)me->query("combat_exp") > 100000 && 
//         (int)me->query("betrayer") > (int)me->query("K_betrayer"))
//    {
//         command("heng");
//         return "本派法度嚴謹，象施主這樣三心二意的人。善哉！善哉！貧尼不能給你剃度。\n";
//    }
    if( (string)me->query("class")=="bonze" )
        return "阿彌陀佛！出家人不打誑語。你已經不是俗家人了。\n";
    if( (string)me->query("gender") != "女性" )
        return "阿彌陀佛！善哉！善哉！施主若真心皈依我佛，可去少林寺受戒。\n";
    me->set_temp("pending/join_bonze", 1);
        command ("say 阿彌陀佛！善哉！善哉！施主若真心皈依我佛，請跪下(kneel)受戒。\n");
        return "記住，一旦出了家，是不能還俗的，否則將會受到懲罰。\n";
}

int do_kneel()
{
        object me = this_player();

        string *prename =
         ({ "靈","文"});
        string name, new_name;
        if( !me->query_temp("pending/join_bonze") )
                return 0;
        message_vision(
        "$N你雙手合十，恭恭敬敬地跪了下來。\n\n"
        "$n看著$N說道：好吧，你就在本庵修行吧。\n\n"
        "$n伸出手掌，在$N頭頂輕輕地摩挲了几下，將$N的頭發盡數剃去。\n\n",
        me, this_object() );
        name = me->query("name");
        new_name = prename[random(sizeof(prename))] + name[0..1];
        command("say 從今以后你的法名叫做" + new_name + "。");
        command("chat "+name+"削發為尼，在峨嵋山修行，取法名"+new_name+"。");
        command("smile");
        me->set("marks/old_name",name);
        me->delete_temp("pending/join_bonze");
        me->set("name", new_name);
        me->set("class", "bonze");
        me->set("K_record", me->query("PKS") + me->query("MKS"));
        me->set("shen_record", me->query("shen"));
        me->set("shen", 0);

        return 1;
}

