// miejue.h
// 灭绝

void attempt_apprentice(object ob)
{
        string *prename =
         ({ "静", "静" });
        string name, new_name;
        if( (string)ob->query("gender") != "女性" )
        {
                command ("say 阿弥陀佛！施主呀，贫尼可不敢开这等玩笑啊。");
        return;
        }
        if( (string)ob->query("class")!="bonze" )
        {
                command ("say 阿弥陀佛！贫尼不收『俗家弟子』。");
        return;
        }
        if( (int)ob->query_skill("linji-zhuang", 1) < 120 )
        {
                command("say 老尼我不收练功不勤之人，你还是多练练你的临济十二庄吧。");
        return;
        }
        if( (int)ob->query_skill("force", 1) < 100 )
        {
                command("say 老尼我不收练功不勤之人，你还是多练练你的基本内功吧。");
        return;
        }
        if( (int)ob->query("shen") < - 50000 ) 
        {
                command("say 老尼我最不喜欢的就是凶恶之徒。");
        return;
        }

        name = ob->query("name");
        new_name = prename[random(sizeof(prename))] + name[2..3];
        command("say 从今以后你的法名叫做" + new_name + "。");
        command("say 阿弥陀佛，善哉！善哉！");
        command("smile");
        command("recruit " + ob->query("id"));
        ob->set("name", new_name);
        ob->set("title", "峨嵋派第四代弟子");
}

void kill_ob(object me)
{       
         command("sneer " + me->query("id"));
        ::kill_ob(me);
}

void unconcious()
{
          command("say 哀叹道：可惜我们峨嵋掌门尚未选出，谁要是能找到..环交给.风..就能当掌..");
        ::unconcious();
}

int pass_yitian(object me, object ob)
{
    COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
    if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
        command("sneer");
        command("say 如此不济，也想打倚天剑的主意？！");
        ob->set("max_qi", 2000);
        ob->set("max_jing", 2000);
        ob->set("neili", 2000);
        ob->set("max_neili", 2000);
        ob->set("jiali", 100);
        ob->set("combat_exp", 1200000);
        if (present("yitian jian",ob))
        destruct(present("yitian jian", ob));
        ob->carry_object("/d/emei/obj/changjian")->wield();
        return 0;
    }
    return 1;
}

int ask_sword()
{
    object me = this_player();
    object ob = this_object();
    object tmp;
    if( present("yitian jian", me)) {
        command("say 你身上不是有倚天剑了么？怎么还问我？");
        command("sneer " + me->query("id"));
        command("consider " + me->query("id"));
        return 1;
    }
    if(me->query_temp("marks/pass_yitian")) {
        command("say 不是说了么？把掌门的铁指环找来，倚天剑就可给与你用。");
        return 1;
    }

    if (ob->is_busy()) {
        command("nonsense miejue shitai");
        command("nonsense");
        return 1;
    }
    if( ob->is_fighting() ) {
        command("nonsense miejue shitai");
        command("nonsense");
        return 1;
    }

    if( me->query("age") < 20 || (int)me->query("combat_exp", 1) < 300000 ) {
        command("say 无名鼠辈也想打倚天剑的注意？");
        this_object()->kill_ob(this_player());
        this_player()->kill_ob(this_object());
        return 1;
    }
    tmp = unew("/clone/weapon/yitian-jian");
    if (!objectp(tmp)) {
        command("say 倚天剑我已经给人了。");
        return 1;
    }
    else destruct(tmp);
    command("say 屠龙宝刀，号令天下，倚天不出，谁与争锋，哈哈哈哈！");
    set("combat_exp", 2000000);
    set("max_qi", 2000);
    set("eff_jingli", 2000);
    set("eff_jing", 2000);
    set("qi", 2000);
    set("max_neili", 2000);
    set("neili", 2000);
    set("jingli", 2000);
    set("jing", 2000);
    set("jiali", 100);
    if(present("changjian", ob)) {
        command("unwield changjian");
        destruct(present("changjian", ob));
    }
    if(!present("yitian jian", ob)) {
        carry_object("/clone/weapon/yitian-jian")->wield();
    }
    prepare_skill("strike");
    prepare_skill("sword");
    ob->reset_action();
    prepare_skill("strike", "sixiang-zhang");
        
    command("say 好吧，既然想得到倚天剑，那么就接老尼几招。\n");
    command("grin " + me->name());
        
    if ( !pass_yitian(me, ob) ) return 1;
    if ( !pass_yitian(me, ob) ) return 1;
    if ( !pass_yitian(me, ob) ) return 1;
    if ( !pass_yitian(me, ob) ) return 1;
    if ( !pass_yitian(me, ob) ) return 1;
    if ( !pass_yitian(me, ob) ) return 1;
    if ( !pass_yitian(me, ob) ) return 1;
    if ( !pass_yitian(me, ob) ) return 1;
//    if( me->query("family/family_name") == "峨嵋派") {
        command("say 好吧，你把掌门指环找来，倚天剑就可给与你用。\n");  
        tell_room(environment(me), "灭绝师太对" + me->name() + "说道：好吧，你把掌门的铁指环找来，倚天剑就可给与你用。\n", ({me}));
        me->set_temp("marks/pass_yitian", 1);
        ob->set("max_qi", 2000);
        ob->set("max_jing", 2000);
        ob->set("neili", 2000);
        ob->set("max_neili", 2000);
        ob->set("jiali", 30);
        ob->set("combat_exp", 1200000);
        if (present("yitian jian",ob))
            destruct(present("yitian jian", ob));
        carry_object("/d/emei/obj/changjian")->wield();
        return 1; 
//    }
    /*
    else {
        command("say 就算你抗住了我十招也不行，拿命来吧。");    
        if (!present("changjian",ob))
            carry_object("/d/emei/obj/changjian")->wield();
        else command("wield changjian");
        prepare_skill("strike");
        prepare_skill("sword");
        ob->reset_action();
        ob->set("combat_exp", 2200000);
        ob->set("jiali", 100);
        this_object()->kill_ob(this_player());
        this_player()->kill_ob(this_object());
        if (present("yitian jian",ob))
            destruct(present("yitian jian", ob));
        carry_object("/d/emei/obj/changjian")->wield();
        return 1;
    }
    */
//    return 1; 
}


int accept_object(object who, object ob)
{
    object sword, me; 
    mapping fam;
    me = this_object();
    if( !who || environment(who) != environment() ) return 0;
    if ( !objectp(ob) ) return 0; 
    if ( !present(ob, who) ) return notify_fail("你没有这件东西。");
    if(!(who->query_temp("marks/pass_yitian"))) {
        command("say 你也配用倚天剑？\n");
        return 0;
    }
    if (!(who->query_temp("marks/get_ring"))) {
        command("say 这铁指环是你找来的么？\n");
        return 0;
    }
/*
    if (!(fam = this_player()->query("family")) || fam["family_name"] !="峨嵋派") {
        command("thank "+ (string)who->query("id"));
        command("say 你与本派素无来往，不知为何送如此厚礼? \n");
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), ob);
        return 1;
    }
*/    
    if ( (string)ob->query("id") == "zhi huan") {
        sword = unew("/clone/weapon/yitian-jian");
        if (!objectp(sword) ){
            command("say 啊！真老糊涂了，剑不知放哪了。\n");
            return 0;
        }
        sword->move(who);
        who->delete_temp("marks/get_ring");
        who->delete_temp("marks/pass_yitian");
        command("say 你如果用这剑为非做歹，我必取你性命!\n");
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), ob);
        return 1;
    }         
    remove_call_out("destroying");
    call_out("destroying", 1, this_object(), ob);
    return 1;
}

void destroying(object me, object obj)
{     
        destruct(obj);
        return;
}     

int ask_guo()
{
    object me=this_player();
    if( !me->query_skill("jiuyin-baiguzhua", 1) ) {
        message_vision("灭绝师太不屑地看了$N一眼，一脸不爱搭理的样子。\n", me);
        return 1;
    }
    if( me->query("shen") < -10000 ) {
        command("say 看你一身邪气，还敢打听郭大侠的名号？\n");
        command("consider "+ me->query("id"));
        return 1;
    }

    command("say 本派的创派祖师郭女侠，乃是当年大侠郭靖的小女儿。郭大侠当年名震天下，生平有两
项绝艺，其一是行军打仗的兵法，其二便是武功。郭大侠的夫人黄蓉黄女侠最是聪明机智
，她眼见元兵势大，襄阳终不可守，他夫妇二人决意以死报国，那是知其不可而为之的赤
心精忠，但郭大侠的绝艺如果就此失传，岂不可惜？何况她料想蒙古人纵然一时占得了中
国，我汉人终究不甘为鞑子奴隶。日后中原血战，那兵法和武功两项，将有极大的用处。
因此她聘得高手匠人，将杨过杨大侠赠送本派郭祖师的一柄玄铁重剑熔了，再加以西方精
金，铸成了一柄屠龙刀，一柄倚天剑。\n");
        me->set_temp("jiuyin140", 1);
        return 1;
}

int ask_zhou()
{
    object me=this_player();
//    object ob = this_object();
    if( me->query_temp("jiuyin140") >= 1 ) {
        command("say 周芷若是我派的第四代弟子，此刻虽然不及众位师姊，日后却是不可限量。\n");
        me->set_temp("jiuyin140", 2 );
        return 1;
    }
    command("say 你问她做什么？\n");
    command("say " + me->query("name") + "定然是看上了她，要她堕入你的彀中。\n");
    command("consider " + me->query("id") );
    return 1;
}

int ask_dragon()
{
    object me=this_player();
    object ob = this_object();
    if( me->query_temp("jiuyin140") < 4 ) {
        command("say 我派的重大秘密你怎么知道了？拿命来！\n");
        ob->set("neili", 3999);
        ob->kill_ob(me);
        return 1;
    }
    command("say 既然周芷若难成大器，那你就给我起个誓吧。\n");
    me->set_temp("jiuyin140", 5 );
    return 1;
}

