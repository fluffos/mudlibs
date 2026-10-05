#include <ansi.h>
#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
string ask_me();
string ask_rename();
inherit NPC;
void create()
{
        set_name(HIW"阿飞"NOR, ({ "a fei" }));        
        set("title", YEL"天神"NOR);
        set("gender", "男性");
        set("age", 25);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("inquiry", ([
      "生日":(:ask_me:),
      	"改兵器":(:ask_rename:),
    ]) );
        set("long", "他，就是夕阳再现的巫师之一，为人性格怪癖，你最好不要惹他。\n");
        set("combat_exp", 900000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 3000);
        set_skill("force", 3000);
        set_skill("dodge", 3000);
        set_skill("parry", 3000);
        set_skill("taixuan-gong", 3000);
        set_skill("liumai-shenjian", 3000);
        set_skill("pixie-jian", 2000);
        set_temp("apply/attack", 6000);
        set_temp("apply/defense", 6000);
        set_temp("apply/armor", 6000);
        set_temp("apply/damage", 6000);
        map_skill("force", "taixuan-gong");
        map_skill("unarmed", "liumai-shenjian");
        map_skill("parry", "liumai-shenjian");
        map_skill("dodge", "pixie-jian");         
        set("qi", 2250000);
        set("max_qi", 2250000);
        set("jiali", 100000); 
        set("neili", 9000000); 
        set("max_neili", 9000000); 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.liumai" :),
                (: perform_action, "unarmed.liumai" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) );        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who, object ob)
{
	int time;
    if (ob->query("money_id") && ob->value() >= 300000000)
	{
        message_vision("阿飞对$N说：好！这位" + RANK_D->query_respect(who) + "既然这么有心，我就告诉你吧。\n" , who);
				who->set_temp("shengri",1);
       	return 1;
	}
    else  
		message_vision("阿飞皱眉对$N说：你的诚意不够，还是请回吧！\n", who);
	return 0;
}
string ask_me()
{
		int i,j;
    object me,ob;
    ob=this_player();
    me=this_object();
    if(!ob->query_temp("shengri")){
 		message_vision("$N说道：这可是得罪东方MM的冒风险的事儿，阁下的“诚意”似乎不够吧。。。\n",me);
 	}else{
		j=ob->query("birthday");
		i=j%90+10;
		message_vision("$N高兴地拍了拍$n的头，"+CHINESE_D->chinese_number(i)+"你可得记好了。\n",me,ob);
		ob->delete_temp("shengri");
	}
	return "今天这事可千万别告诉东方MM。\n";
}
string ask_rename()
{
	object ob=this_player();
    write("我这儿可以打造以下兵器：\n"+
          "     剑(jian)\n"+
          "     刀(dao)\n"+
          "     棍(gun)\n"+
          "     杖(staff)\n"+
          "     鞭(whip)\n");       
    return "这位"+RANK_D->query_respect(ob)+"要造什么兵器？决定了告诉我(rename)。\n";
}
/* void init()
{
        ::init();
        add_action("do_zhu","rename");
}
int do_zhu(string arg)
{
		string id,name;
		object me;
		me = this_player();
		if(!me->query("weapon/make") )
			return notify_fail("你都没有造兵器，乱改什么！\n");
		if (me->query("rename"))
			return notify_fail("对不起，你已经改过一次了。\n");
		if( !arg )
			return notify_fail("阿飞认真的说：想好武器的名称及代号后在对我说。\n");
		message("vision",me->name()+"对阿飞轻声说了几句。\n",environment(me), ({me}) );
    switch (arg) {
      case "jian" :
        me->set("weapon/type","剑");
        me->set("weapon/id","my sword");
        me->set("rename",1);
        message("vision","这下你该满足了吧！"+me->name()+"!\n",me);
        break;
      case "dao" :
        me->set("weapon/type","刀");
        me->set("weapon/id","my blade");
        me->set("rename",1);
        message("vision","这下你该满足了吧！"+me->name()+"!\n",me);
        break;
      case "gun" :
        me->set("weapon/type","棍");
        me->set("weapon/id","my club");
        me->set("rename",1);
        message("vision","这下你该满足了吧！"+me->name()+"!\n",me);
        break;
      case "staff" :
        me->set("weapon/type","杖");
        me->set("weapon/id","my staff");
        me->set("rename",1);
        message("vision","这下你该满足了吧！"+me->name()+"!\n",me);
        break;
      case "whip" :
        me->set("weapon/type","鞭");
        me->set("weapon/id","my whip");
				me->set("rename",1);
        message("vision","这下你该满足了吧！"+me->name()+"!\n",me);
        break;
      default :
        message_vision(HIC "阿飞一脸狐疑：什么兵器？\n" NOR,me);
        return notify_fail("阿飞仔细的说：此事不可儿戏，请慎重!!\n");
    }
    me->save();
    return 1;
} */
