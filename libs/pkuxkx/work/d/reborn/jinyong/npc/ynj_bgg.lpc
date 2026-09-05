//kiden <越女剑>之白公公
inherit NPC;

void create()
{
        set_name("白猿", ({ "bai yuan", "yuan" }) );
        set("race", "野兽");
        set("age", 80);
        set("long", "一只浑身长着寸许长白毛的老猿。\n");
        set("str", 30);
        set("dex", 30);
              set("int", 30);
              set("con", 30);
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
              set("combat_exp", 19999000);
              set_skill("unarmed", 550);
              set_skill("parry", 550);
              set_skill("dodge", 550);
              set("max_qi", 9999);
              set("max_jing", 9999);
              set("jingli", 9999);
              set("max_jingli", 9999);
              set("neili", 9999);
              set("max_neili", 9999);
              set("jiali", 300);
        set_temp("apply/attack", 200);
        set_temp("apply/armor", 500);
        setup();           
}
void init()
{
        add_action("do_none","");     
}

int do_none(string arg)                                                       
{                                                                             
        string verb = query_verb();                                           
                                                                              
        if(verb != "give" && verb != "go" && verb != "look"&& verb != "chat"&& verb != "rumor")
        {                                                                     
                write("你偷偷摸摸的不知道想干什么，白猿警惕的看着你。\n");                            
                return 1;                                                     
        }                                                                     
        return 0;                                                             
}
int accept_object(object who, object ob)                                                                             
{
       if(ob->query("id")=="banana")
       {
                write("白猿高兴得抓耳挠腮，赶紧窜上一颗大树，一会儿就不见了！\n"); 
                call_out("do_dest", 1, this_object());
                return 1;
       }
       return 0;
}               
void do_dest(object ob)
{
        if(!objectp(ob))
                return;
        destruct(ob);
}	
                        
