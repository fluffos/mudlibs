//wudang.h test if a person is stranger
void init()
{
        mapping fam;
        object me=this_player();
        add_action("do_bihua","bihua");
        ::init();
/*        if ( (int)me->query("shen") <1000 && (string)me->query("family/master_name") == this_object->query("name"))
        {
                command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ me->query("id"));
        }*/
        if( interactive(this_player()) && !is_fighting() ){
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="武当派"
        || me->query_temp("enemy")){
        command("?");
        command("say 这位" + RANK_D->query_respect(me) +
                "甚是面生，不知怎得进到我武当内院的？");}
        }
}
int do_bihua(object obj)
{
	object ob=this_object();
        object me=this_player();
        int times=ob->query("times");
        int exper=me->query("combat_exp");
        int kee=(int)ob->query("max_qi");
        int old_exp=(int)ob->query("combat_exp");
        mapping fam;
	if (obj!=this_object())
	return 0;
        if (!(fam=me->query("family")) || fam["family_name"]!="武当派") {
        command("say 这位" +RANK_D->query_respect(me)+ "是欺我武当无人吗？");
        command("heng");
        return 1; }
        if(ob->is_fighting()) {
        command("say 你没看到我正忙着吗？");
        return 1; }
        if (times<1) {
        command("say 我有些疲惫，你先自己练练吧。");
        return 1; }
        if (exper>10000 && ob->query("name")=="道童") {
        command("say 惭愧惭愧，我已经没有能力陪你过招了");
        return 1; }
        if (exper>50000 && ob->query("name")=="道士") {
        command("say 惭愧惭愧，我已经没有能力陪你过招了");
        return 1; }
        else
        ob->map_skill("unarmed");
        ob->reset_action();
        ob->set("combat_exp",exper+200);
        command ("say 你既然有心，那我就陪你过上几招。");
        me->fight_ob(ob);
        ob->fight_ob(me);
        ob->add("times",-1);
        if ((int)((int)ob->query("qi")*100/ob->query("max_qi"))<20)
        message_vision("$N对$n抱一抱拳，说道：“好，真不愧为我们武当门下的杰出弟
子。”\n",
                        ob,me);
        if ((int)((int)me->query("qi")*100/me->query("max_qi"))<20)
        {
        message_vision("$N对$n微微一笑，说道：“你还需努力呀。”\n",
                        ob,me);
        ob->set("eff_qi",kee);
        ob->set("qi",kee);
        ob->set("combat_exp",old_exp);
        map_skill("unarmed","taiji-quan");
        return 1;
        }
}
