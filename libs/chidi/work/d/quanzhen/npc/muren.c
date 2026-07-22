// mu-ren.c 木人
inherit BHNPC;
void create()
{
    set_name("木人", ({ "mu ren", "mu", "wood man", "wood" }) );
    set("gender", "男性" );
    set("age", 30);
    set("long", "一个练功用的比武木人，制作精巧，如同真人一般。\n");
    set("attitude", "heroism");
    set("str", 25);
    set("cor", 25);
    set("cps", 25);
    set("int", 25);
    
      set("no_get",1);
    set("no_suck",1);           // 不能吸jing,neili
    set("no_die",1);
    
    set("max_qi", 300);
    set("eff_qi", 300);
    set("qi", 300);
    set("max_jing", 100);
    set("jing", 100);
    set("unit","个");
    set("neili", 300);
    set("max_neili", 300);
    set("jiali", 10);
    set("shen_type", 0);
    set("combat_exp", 50000);
    set_skill("force", 30); 
    set_skill("unarmed", 30);
    set_skill("dodge", 30);
    set_skill("parry", 30);
    set("fight_times", 0);  
    setup();
        
}
int accept_fight(object ob)
{
    object me;
    mapping hp_status, skill_status, map_status;
    string *sname, *mname;
    int i, temp;
    me = this_object();
    if (is_fighting()) return 0;
    if (me->query("damaged")){
        tell_object(ob,"这个木人已经被打坏了！\n"); 
        return 0;
    }
    if (random(me->query("fight_times")) >= 10) {
        me->set("damaged", 1);
        tell_object(ob,"这个木人已经被打坏了！\n"); 
        return 0;
    }
    if (me->query("last_fighter") == ob->query("id")){
        tell_object(ob,"你刚跟这个木人练过功！\n");     
        return 0;
    }
    me->set("last_fighter", ob->query("id"));
    me->add("fight_times", 1);
    remove_call_out("renewing");    
    call_out("renewing", 300 + random(300), me);    
/* delete and copy skills */
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
    
    
    hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]);
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]);
        me->set("dex", hp_status["dex"]);
        me->set("max_qi",    hp_status["max_qi"]);
        me->set("eff_qi",    hp_status["eff_qi"]);
        me->set("qi",        hp_status["qi"]);
        me->set("max_jing",  hp_status["max_jing"]);
        me->set("eff_jing",  hp_status["eff_jing"]);
        me->set("jing",      hp_status["jing"]);
        me->set("max_neili", hp_status["max_neili"]);
        me->set("neili",     hp_status["neili"]);
        me->set("jiali",     hp_status["jiali"]);
        if (random(hp_status["combat_exp"] )>6000000) command("enforce "+random(200));
  if (hp_status["combat_exp"] < 20000000)       me->set("combat_exp",hp_status["combat_exp"]+2000);
else                 me->set("combat_exp",20000000);
    return 1;
}
void renewing(object me)
{
    me->delete("last_fighter");
}

void die()
{
    object ob;
    message_vision("$N轰隆一声，掉在地上，散了架了！\n", this_object());
//   ob = new(__DIR__"obj/mugun");
//   ob->move(environment(this_object()));
    destruct(this_object());
}
