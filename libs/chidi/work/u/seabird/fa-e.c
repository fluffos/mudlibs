// fa-e.c 罚恶使者
// modify by jzw 2006/2/6 for fix bug

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define SHIZHE NPCDATA + "fa-e"
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
string query_save_file()
{
    return SHIZHE;
}
int rm_file()
{
    seteuid(getuid());
    rm(query_save_file()+__SAVE_EXTENSION__);
    destruct(this_object());
    return 1;
}
void create()
{
    seteuid(getuid());
    if (!restore()) {
    set_name("西方月", ({ "fae shizhe", "fae", "shizhe" }) );
    set("title", "罚恶使者" );
    set("gender", "男性" );
    set("age", 35);
      set("long","一位神色严峻的中年武人，他就是嫉恶如仇，侠名远播的武林罚恶使者。\n");
    set("attitude", "heroism");
    set("generation", 0);
    set("winner", "NONE");
    set("str", 25);
    set("con", 25);
    set("int", 25);
    set("dex", 25);
    set("max_qi", 500);
    set("eff_qi", 500);
    set("qi", 500);
    set("max_jing", 300);
    set("jing", 300);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 30);
    set("shen_type", 0);
    set("no_clean_up",1);
    set("no_get",1);
    set("combat_exp", 400000);
    set_skill("force",  160); 
    set_skill("unarmed",160);
    set_skill("sword",  160);
    set_skill("dodge",  160);
    set_skill("parry",  160);
    set("my_weapon", "/d/shaolin/obj/changjian");
    set("my_armor", "/d/city/obj/cloth");
    setup();
    carry_object("/d/shaolin/obj/changjian")->wield();
    carry_object("/d/city/obj/cloth")->wear();        
    }
    else {
        set("id", "fae");
        set_name(query("name"), ({ "fae shizhe", "fae", "shizhe"  }));
        set("no_get",1);
        setup();
        if( this_object()->query("my_weapon") ) carry_object(this_object()->query("my_weapon"))->wield();
        if( this_object()->query("my_armor") )  carry_object(this_object()->query("my_armor"))->wear();        
      UPDATE_D->check_user(this_object());
    }
    set("no_suck",1);
}
void init()
{
    object me = this_object();
    object ob = this_player();
    if (base_name(environment())!=me->query("startroom")) return;
    
    if(ob->query("daoxin"))
{
  tell_object(ob, "你只不过是个残疾人,也配做当今罚恶使者?\n");
return 0;
}

    if ( me->query("winner") == ob->query("id")
      && me->query("age") <= ob->query("age")
      && time()-me->query("recover")>60){
        ob->set("eff_jing",ob->query("max_jing"));
        ob->set("jing",ob->query("max_jing"));
        ob->set("eff_qi",ob->query("max_qi"));
        ob->set("qi",ob->query("max_qi"));
        if (ob->query("neili")<ob->query("max_neili"))
            ob->set("neili",ob->query("max_neili"));
        if (ob->query("jingli")<ob->query("max_jingli"))
            ob->set("jingli",ob->query("max_jingli"));
        me->set("recover",time());
    }
    add_action("do_recopy",  "recopy");
    add_action("do_recover", "recover");
    add_action("do_kill", "kill");
    add_action("do_gengxin","gengxin");
}
int do_kill(string arg)
{
    object ob;
    int i;
    if (!this_object()->id(arg)) return 0;
    command("say 你想谋害本使者，当真是自找死路！ 座下红衣武士何在！");
    message_vision("四周的红衣武士群起对$N发动攻击！\n", this_player());
    for(i=0; i<4; i++) {
        if( objectp( ob = present("wei shi " + (i+1), environment(this_object())) ) )
                 ob->kill_ob(this_player());    
        else    this_object()->kill_ob(this_player());      
    }
    return 1;
}
int accept_fight(object ob)
{
    object me, mengzhu, shangshan ,xinxiu;
    string name1, name2 ,name3;
 
    me  = this_object();
        
    if(!( mengzhu = find_living("wulin mengzhu")) )
    if(!( mengzhu = find_object(__DIR__"meng-zhu")) )
    mengzhu = load_object(__DIR__"meng-zhu");
    mengzhu->restore();
    name1 = mengzhu->query("winner");
    if( this_player()->query("id")==name1 ){
        command("say 盟主大人，在下罚恶使者怎么是您的对手？！\n");
        return 0;
    }
    /*
    if(!( shangshan = find_living("shangshan shizhe")) )
    if(!( shangshan = find_object(__DIR__"shang-shan")) )
    shangshan = load_object(__DIR__"shang-shan");
    shangshan->restore();
    name2 = shangshan->query("winner");
    if( this_player()->query("id")==name2 ){
        command("say 你是赏善使者，我是罚恶使者，我们打什么架？！\n");
        return 0;
    }
    if(!( xinxiu = find_living("jianghu xinxiu")) )
    if(!( xinxiu = find_object(__DIR__"xin-xiu")) )
    xinxiu = load_object(__DIR__"xin-xiu");
    xinxiu->restore();
    name3 = xinxiu->query("winner");
    if( this_player()->query("id")==name3 ){
        command("say 你是江湖新秀，我是罚恶使者，我们打什么架？！\n");
        return 0;
    }
*/
 if(!this_player()->query_temp("agree")) {
   this_player()->set_temp("agree",1); 
   this_player()->start_busy(2); 
        message("system",HIW"【罚恶守卫】: "+this_player()->query("id")+"正在挑战罚恶使者!特此告之!!!\n"NOR,users());
   tell_object(this_player(), HIW"这个象的目前主人可能正在用这个象,如果你确定打象,请再下一次fight!!!\n"NOR);
return 0;
}
    if ( me->query("winner") == ob->query("id") ) 
         {                 remove_call_out("do_copy");
                call_out("do_copy", 1, me, ob);
        command("say 你跟你自己打什么架？！\n");
        return 0;
       }
    if (wizardp(this_player())){
        command("say 巫师不能抢使者之位！\n");
        return 0;
    }
    if (me->is_fighting() || me->query("fighting"))
        return notify_fail("已经有人正在挑战罚恶使者！\n");
    me->set("eff_qi", me->query("max_qi"));
    me->set("qi",     me->query("max_qi"));
    me->set("jing",   me->query("max_jing"));
    me->set("neili",  me->query("max_neili"));
    remove_call_out("checking");
    call_out("checking", 1, me, ob);
    
    return 1;
}
int checking(object me, object ob)
{
    int my_max_qi, his_max_qi;
    object *enemy=me->query_enemy();
    if (sizeof(enemy)>1)    return 1;
    if (!ob)    return 1;
    my_max_qi  = me->query("max_qi");
    his_max_qi = ob->query("max_qi");
    if (me->is_fighting()) {
        if ( (me->query("qi")/ my_max_qi*100 ) <= 80 )
            command("exert recover");
        call_out("checking", 1, me, ob);
        return 1;
    }
    if ( !present(ob, environment()) ) return 1; 
    if (( (int)me->query("qi")/ my_max_qi*100 ) <= 50 ) {
        if (!living(me))    me->revive();
        command("say 果然厉害，恭喜你成为当今罚恶使者！\n");
        command("chat 哈哈哈，到底是长江後浪推前浪，一代新人换旧人！\n");
        command("chat 恭喜" + ob->query("name") + "被推举为当今罚恶使者！\n");
        me->set("fighting",1);
        remove_call_out("do_copy");
        call_out("do_copy", 1, me, ob);
        return 1;
    }
    if (( (int)ob->query("qi")/ his_max_qi*100 ) < 80 ) {
        command("say 看来" + RANK_D->query_respect(ob) + 
            "还得多加练习，方能在当今武林中出人头地 !\n");
        return 1;
    }
    return 1;  
}
int do_copy(object me, object ob)
{
    object shizhe,xinxiu,room;
    string name;
    if(!( shizhe = find_living("shangshan shizhe")) )
    shizhe = load_object("/d/taishan/npc/shang-shan");
    name = shizhe->query("winner");
    
    if( ob->query("id") == name ){
        shizhe->rm_file();
      if (!room=find_object("/d/taishan/xiayi"))
      room=load_object("/d/taishan/xiayi");
      room->reset();
     }
     
    /* 
    if(!( shizhe = find_living("fae shizhe")) )
    shizhe = load_object("/d/taishan/npc/fa_e");
    name = shizhe->query("winner");
    if( ob->query("id") == name ){
        shizhe->rm_file();
      if (!room=find_object("/d/taishan/zhengqi"))
      room=load_object("/d/taishan/zhengqi");
      room->reset();
     }
     */
     
   if(!( xinxiu = find_living("jianghu xinxiu")) )
    xinxiu = load_object("/d/taishan/npc/xin-xiu");
    name = xinxiu->query("winner");
   
    if( ob->query("id") == name ){
        xinxiu->rm_file();
      if (!room=find_object("/d/taishan/newplayer1"))
      room=load_object("/d/taishan/newplayer1");
      room->reset();
     }
     
    seteuid(getuid());
    if (!living(me))    me->revive();
    me->set("winner", ob->query("id"));
    me->add("generation", 1);   
    me->set("name",  ob->query("name") );
    
    ob->delete("party");
    ob->set("party/party_name",HIW+"第" + chinese_number(me->query("generation")) + "代"+ NOR );
    ob->set("party/rank",HIW+"罚恶使者"+NOR);
  
    me->set("short", HIW+"第" + chinese_number(me->query("generation")) + "代罚恶使者" + NOR+" " + me->query("name") + "(Fae shizhe)");
    me->delete("title");
    remove_call_out("do_clone");
    call_out("do_clone", 0, me, ob);
    return 1;
}
int do_recopy(object me, object ob)
{
    me = this_object();
    ob = this_player();
    if (me->is_fighting() || ob->is_fighting() || me->query("fighting"))
        return notify_fail("现在这里正打的不亦乐乎！等会吧！\n");
    if ( me->query("winner") != ob->query("id")||me->query("age")>ob->query("age")|| me->query("birthday")!= ob->query("birthday")) 
        return notify_fail("你不是现任罚恶使者！\n");;
    me->set("name",  ob->query("name") );
    ob->delete("party");
    ob->set("party/party_name",HIW+"第" + chinese_number(me->query("generation")) + "代"+ NOR );
    ob->set("party/rank",HIW+"罚恶使者"+NOR);
    me->set("short", HIW+"第" + chinese_number(me->query("generation")) + "代罚恶使者" + NOR+" " + me->query("name") + "(Fae shizhe)");
    me->delete("title");
    remove_call_out("do_clone");
    call_out("do_clone", 0, me, ob);
    return 1;
}
int do_clone(object me, object ob)
{
    object *inv, newob,weapon;
    mapping hp_status, skill_status, map_status;
    string *sname, *mname;
    int i, temp;
    string skill1,skill2;
    seteuid( geteuid(me) );
    if (!living(me))    me->revive();
/* delete and copy skills */
    if (mapp(skill_status=ob->query("weapon")))
        me->set("weapon",skill_status);
    else    me->delete("weapon");
    if ( mapp(skill_status = me->query_skills()) ) {
        skill_status = me->query_skills();
        sname  = keys(skill_status);
        temp = sizeof(skill_status);
        for(i=0; i<temp; i++) {
            me->delete_skill(sname[i]);
        }
    }
    if ( mapp(skill_status = ob->query_skills()) ) {
        skill_status = ob->query_skills();
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            me->set_skill(sname[i], skill_status[sname[i]]);
        }
    }
    
/* delete and copy skill maps */
    if ( mapp(map_status = me->query_skill_map()) ) {
        mname  = keys(map_status);
        temp = sizeof(map_status);
        for(i=0; i<temp; i++) {
            me->map_skill(mname[i]);
        }
    }
    if ( mapp(map_status = ob->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            me->map_skill(mname[i], map_status[mname[i]]);
        }
    }
    
/* unwield and remove weapon & armor */
    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++) {
        destruct(inv[i]);
    }
    set("my_weapon", 0);
    set("my_armor", 0);
/* wield and wear weapon & armor */
    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++) {
        if( inv[i]->query("weapon_prop/damage") > 100 
        ||  inv[i]->query("armor_prop/armor") > 100
        ||  inv[i]->query("shaolin")
                ||  inv[i]->query("value")>100000 ) continue;
        if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
            if (!inv[i]->id(query("weapon/id"))){
//            carry_object(base_name(inv[i]))->wield();
            me->set("my_weapon", base_name(inv[i]));
                        }
        }
        else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
//            carry_object(base_name(inv[i]))->wear();
            me->set("my_armor", base_name(inv[i]));
        }
    }

/* copy entire dbase values */
    hp_status = ob->query_entire_dbase();
       hp_status = ob->query_entire_dbase();
     me->set("winner", ob->query("id"));
        me->set("str", hp_status["str"]);
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]);
        me->set("dex", hp_status["dex"]);
        me->set("age", hp_status["age"]);
        me->set("max_qi",    hp_status["max_qi"]);
        me->set("eff_qi",    hp_status["eff_qi"]);
        me->set("qi",        hp_status["qi"]);
        me->set("max_jing",  hp_status["max_jing"]);
        me->set("eff_jing",  hp_status["eff_jing"]);
        me->set("jing",      hp_status["jing"]);
        me->set("max_neili", hp_status["max_neili"]);
        me->set("neili",     2*hp_status["max_neili"]);
        me->set("max_jingli",hp_status["max_jingli"]);
        me->set("jingli",    hp_status["jingli"]);
        me->set("jiali",     hp_status["jiali"]);
        me->set("gender",    hp_status["gender"]);
        me->set("combat_exp",hp_status["combat_exp"]);
        me->set("birthday",hp_status["birthday"]);
       me->set("jh_dj/dj",ob->query("jh_dj/dj"));
        me->set("int",ob->query("int"));
        me->set("dex",ob->query("dex"));
        me->set("str",ob->query("str"));
        me->set("con",ob->query("con"));
        
        me->delete("fighting");
        if (objectp(weapon=me->query_temp("weapon"))){
            skill1=weapon->query("skill_type");
            if (objectp(weapon=me->query_temp("secondaly_weapon")))
                    skill2=weapon->query("skill_type");
        }
    if ( mapp(skill_status = me->query_skills()) ) {
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            command("enable unarmed "+sname[i]);
            command("enable force "+sname[i]);
            command("enable parry "+sname[i]);
            command("enable dodge "+sname[i]);
                        if (stringp(skill1))
            command("enable "+skill1+" "+sname[i]);
                        if (stringp(skill2))
            command("enable "+skill2+" "+sname[i]);
        }
    }

    command("enforce max");
    command("enable unarmed liumai-shenjian");
      me->set("winner", ob->query("id"));
    save();
    tell_object(ob, "状态储存完毕。\n");
    newob = new("/d/taishan/npc/fa-e");
    newob->move("/d/taishan/zhengqi");
    destruct(me);
    return 1;
}

int do_recover()
{
    object me, ob;
    mapping skill_status, map_status;
    string *sname, *mname;
    int i;
    me = this_object();
    ob = this_player();
    if (me->is_fighting() || ob->is_fighting() || me->query("fighting"))
        return notify_fail("现在这里正打的不亦乐乎！等会吧！\n");
    if ( me->query("winner") != ob->query("id")  || (me->query("age")-1)>ob->query("age")|| me->query("birthday")!= ob->query("birthday")) 
        return notify_fail("你不是现任罚恶使者！\n");
    
    //if(me->query("combat_exp",1)/2>ob->query("combat_exp",1))
    //return notify_fail("你的实力和现在的使者的实力差太多了吧？\n");
    // if(me->query("combat_exp",1)/2<ob->query("combat_exp",1))
   // return notify_fail("你的实力和现在的使者的实力差太多了吧？\n");
   // if(me->query("max_neili",1)>ob->query("max_neili",1)+100
    
    // ||me->query("max_jingli",1)>ob->query("max_jingli",1)+100)
  //  return notify_fail("你的内力和精力不可以发生变化？\n");
if (me->query("jh_dj/dj",1)!=ob->query("jh_dj/dj",1))
return notify_fail("您偷偷的跑去升级了吧,还是先recopy重新存记录吧,要不然不能恢复的?\n");
/*
  if (me->query("int")!=ob->query("int"))
    return notify_fail("您偷偷的跑去升级属性了吧,还是先recopy重新存记录吧,要不然不能恢复的?\n");
    if (me->query("dex")!=ob->query("dex"))
    return notify_fail("您偷偷的跑去升级属性了吧,还是先recopy重新存记录吧,要不然不能恢复的?\n");
    if (me->query("str")!=ob->query("str"))
    return notify_fail("您偷偷的跑去升级属性了吧,还是先recopy重新存记录吧,要不然不能恢复的?\n");
    if (me->query("con")!=ob->query("con"))
    return notify_fail("您偷偷的跑去升级属性了吧,还是先recopy重新存记录吧,要不然不能恢复的?\n");
     if (me->query("jh_dj/dj")!=ob->query("jh_dj/dj"))
    return notify_fail("您偷偷的跑去升级了吧,还是先recopy重新存记录吧,要不然不能恢复的?\n");
    */
    if (time()-me->query("recover")<10)
        return notify_fail("状态暂时不能复元。\n");
/* delete and copy skills */
    if ( random(100) > 50)//50%兼容成功机会
    if ( mapp(skill_status = ob->query_skills()) ) {
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            ob->delete_skill(sname[i]);
        }
    }
    if ( mapp(skill_status = me->query_skills()) ) {
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
            ob->set_skill(sname[i], skill_status[sname[i]]);
        }
    }
    
/* delete and copy skill maps */
    if ( mapp(map_status = ob->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            ob->map_skill(mname[i]);
        }
    }
    if ( mapp(map_status = me->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            ob->map_skill(mname[i], map_status[mname[i]]);
        }
    }
    
/* copy combat exp values */
   // ob->set("combat_exp", me->query("combat_exp"));
    ob->set("jh_dj/dj",me->query("jh_dj/dj"));
    me->set("recover",time());
    write("状态复元完毕。\n");
    return 1;
}

int do_gengxin()
{
    object me, ob, room;
    me = this_object();
    ob = this_player();
    if (me->is_fighting() || ob->is_fighting() || me->query("fighting"))
        return notify_fail("现在这里正打的不亦乐乎！等会吧！\n");
    if ( me->query("winner") != ob->query("id") ) 
        return notify_fail("你不是现任罚恶使者！\n");
    command("chat 我已看清世间名利，现在决定退出江湖归隐山林。\n");
    command("chat 我退出江湖后，罚恶使者之位将由西方月大侠暂时接任。\n");
    rm(query_save_file()+__SAVE_EXTENSION__);
    room=new("/d/taishan/npc/fa-e");
    room->move("/d/taishan/zhengqi");
     seteuid(getuid());
    destruct(me);
    destruct("winner");
         destruct("id");

      ob->start_busy(4);
    return 1;
}
