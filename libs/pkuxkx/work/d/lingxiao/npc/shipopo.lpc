// shipopo.c 史婆婆
// whuan
inherit NPC;
int ask_jwd();
void create()
{
        set_name("史婆婆", ({ "shi", "popo" }));
        set("title", "金乌派掌门人");
        set("gender", "女性");
        set("long", "她是雪山派掌门人白自在的妻子，虽说现在人已显得苍老，\n"
        "但几十年前提起“江湖一枝花”史小翠来，武林中却是无人不知。\n");
        set("age", 68);

        set("int", 30);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 500);
        set("max_jing", 500);
        set("shen_type", 1);

        set("combat_exp", 75000);
        set("attitude", "friendly");

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("blade", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("jinwu-daofa", 200);
        set_skill("yanyi-shenfa", 200);
        set_skill("force",200);
        set_skill("xueshan-neigong",200);

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 135);

        map_skill("force","xueshan-neigong");
        map_skill("blade", "jinwu-daofa");
        map_skill("parry", "jinwu-daofa");
        map_skill("dodge", "yanyi-shenfa");
           set("inquiry",([
              "金乌刀法" :   ( : ask_jwd : ),
              "刀法" :   ( : ask_jwd : ),
                ]));              	
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/lingxiao/npc/obj/changpao")->wear();
}
void init()
{
        add_action("do_answer","answer");
}
int do_answer(string answer)
{
	      object me,ob;
        me=this_player();
        ob=this_object();
        if(!answer || !me->query_temp("can_learn_jwd"))
        {
        	return 0;
        } 	
        if(answer!="yes"&&answer!="愿意")
        {
        say("史婆婆道：“很可惜啊。”\n");
        return 1;
        }
        command("say 很好，你去附近搜下，看看有没有刀，我教你一套刀法。");
        me->set_temp("can_learn_jwd2",1);
        return 1;
}
int ask_jwd()
{
		    object me,ob,cd;
        me=this_player();
        ob=this_object();
        if (!me->query_temp("can_learn_jwd2"))
        {
        	command("heng");
        	command("say 你问这个干什么？");
        	return 1;
        }
        if (me->query("lingxiao/jinwudao"))
        {
        	command("say 学会了就不要再问了。");
        	return 1;
        }
        cd = present("chai dao", me);
        if (!(cd))
        {
        	command("laf");
        	command("say 你没有似乎没有合适的工具。");
          return 1;
        }
       command("hahafaint");
       command("say 想不到我金乌派他日望重武林，威震江湖，全是以这柄……这柄宝刀起家。哈哈！");
       tell_object(me,"史婆婆花了许久时间，终于将金乌刀法全部传授给你。\n");
       me->set_skill("jinwu-daofa",100);
       me->add("combat_exp",100000);
       me->add("repute",50000);
       tell_object(me,"你的经验和声望进步了！你的“金乌刀法”进步了！\n");
       command("rumor "+this_player()->query("name")+"机缘巧合，学到了金乌刀法了！\n");
       me->set("lingxiao/jinwudao",1);
       me->delete("jinwudao");
       me->save();
       return 1;
}

