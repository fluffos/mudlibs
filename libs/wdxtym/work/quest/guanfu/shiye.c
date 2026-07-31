// /d/city/npc/shiye.c 知府师爷
 
// by dubei update 1997.7.4

#include <ansi.h> 
inherit NPC;
int ask_me(object who);
void create()
{
	set_name("王坏水", ({ "wang huaishui", "wang" }));
	set("title", "知府师爷");
	set("gender", "男性");
	set("age", 57);
        set("combat_exp", 30000);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage",  20);
	set("shen", 0);
                set("inquiry", ([
                "俸禄" : (: ask_me :),
        ]));
	setup();
        carry_object("/clone/misc/cloth")->wear();
}
int ask_me(object who)
{
        object me;
        int times;

        me = this_player();
        times = (int)me->query("gf_job",1);

        if (times<=20){
        command("say 你没为朝廷出过什麽力，还想要俸禄？\n");
        return 1;
        }
        if((int)me->query("gf_gives")<(int)me->query("age")) {
        if (!me->query_temp("mark/huilu")  && times<2500){
        command("look " + me->query("id"));
        command("say 都在这里，你拿去吧！\n");
        who->add_money("gold",times/20);
        command("give "+me->query("id")+" gold");
        write(WHT"你觉得钱的数目好象不大对啊。\n"NOR);
        me->set("gf_gives",(int)me->query("age"));
       return 1;
        }
         if (me->query_temp("mark/huilu")  && times<2500){
         command("hehe " + me->query("id"));
         message_vision("王坏水点头哈腰的说道，这位"+RANK_D->query_respect(me)+"辛苦了，这是您的官俸，"
"以后还望多多关照在下。\n",me);
        who->add_money("gold",10+times/10);
        command("give "+me->query("id")+" gold");
        me->delete_temp("mark/huilu");
        me->set("gf_gives",(int)me->query("age"));
        return 1;
        }
    }
        if (times>2500){
        command("say 在下不过是个知府师爷，怎麽还敢给您发俸禄呢？\n");
        command("flatter " + me->query("id"));
        return 1;
        }
        command("say 没到时间呢，领什麽俸禄？!\n");
        return 1;
}
int accept_object(object me, object obj)    
{
        int times;
        times=me->query("gf_job",1);

        if (!me->query("gf_job")){
        command("say 无缘无故送礼，想贿赂我？\n");
        return 1;
        }
        if(obj->query("money_id")){
        if(obj->value() >= times*100){
        command("hehe "+me->query("id"));
        command("whisper "+me->query("id")+" 你就放心吧，回头我会好好关照你的！");
        me->set_temp("mark/huilu",1);
        return 1;
        }
        else {  
               command("say 这么点钱能干什麽？还不够我去一次丽春院的呢？");
        return 1;
              }
        }
        command("say 拿这个"+obj->name()+"来给我，有什麽用？！");
        return 0;
}
void destroy (object obj)
{
        destruct(obj);
        return;
}
