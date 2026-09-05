// 游方和尚 By Zine
#include <title.h>               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
int ask_finish();
int ask_relationship();
void create()
{
	set_name("游方和尚", ({ "youfang heshang","heshang","monk"}));
        
	set("long",
	"他是一个有着大智慧的人，一辈子都在苦行中渡过，看惯了人世的悲欢离合。\n"
         );
	set("title",HIC"心如止水"NOR);
	set("gender", "男性");
	
	set("age", 90);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
    set("uni_target",1);
    set("no_get",1);
	set("max_qi", 1000000);
    set("qi", 1000000);
    set("max_jing", 1000000);
    set("jing", 1000000);
    set("max_jingli", 1000000);
    set("jingli", 1000000);
    set("neili", 900000);
	set("max_neili", 900000);
	set("jiali", 500);
    set_skill("hand", 5000);
	set_skill("parry",5000);
	set_skill("dodge", 5000);
	set_skill("force",5000);
	set_skill("literate",5000);
    set_skill("fishing",5000);
	set("combat_exp", 650000+random(100000000));
	set("random_npc",1);
    set("inquiry", ([
			"亲戚" : (: ask_relationship :),
            "relative" : (: ask_relationship :),
            "quest" : (: ask_quest :),
            "新人里程碑" : (: ask_quest :),
            "finish" : (: ask_finish :),
            "完成" : (: ask_finish :),
     
       	]) );    
        setup();
        carry_object(__DIR__"obj/m-cloth")->wear();
        call_out("adv",1);
        
	

}

void init()
{
    object me=this_player();
    string gift;
    add_action("do_select","select");
    if (me->query("statistics/newbie_target/gift_reward")&&me->query("combat_exp")>200000)
    {
        gift=me->query("statistics/newbie_target/gift_reward");
        me->delete("statistics/newbie_target/gift_reward");
        if (gift!="str"&&gift!="int"&&gift!="dex")
        {
            return;
        }
        me->add(gift,1);
        me->add("xiantian/"+gift+"/newbie_target",1);
        if (gift=="str")
        {
            tell_object(me,HIW+"因为早年完成的【襄阳从军】的任务，此刻你福至心灵，获得了一点先天臂力。\n"+NOR);
        }
        if (gift=="int")
        {
            tell_object(me,HIC+"因为早年完成的【周处除三害】的任务，此刻你福至心灵，获得了一点先天悟性。\n"+NOR);
        }
        if (gift=="str")
        {
            tell_object(me,HIG+"因为早年完成的【游方天下】的任务，此刻你福至心灵，获得了一点先天身法。\n"+NOR);
        }
        return;
    }
}

int ask_quest()
{
    object me=this_player();
    string msg;
    if (me->query("statistics/newbie_target/guo_finish"))
    {
        command("say 后生可畏啊，你已完成了襄阳从军任务，并获得了『侠之大者』的称号。");
        return 1;
    }
    if (me->query("statistics/newbie_target/zc_finish"))
    {
        command("say 后生可畏啊，你已完成了周处除三害任务，并获得了『降龙伏虎』的称号。");
        return 1;
    }
    if (me->query("statistics/newbie_target/youfang_finish"))
    {
        command("say 后生可畏啊，你已完成了游方天下任务，并获得了『神行千里』的称号。");
        return 1;
    }
    if (me->query("statistics/newbie_target/selected")==3)
    {
        command("say 你已经选过了游历任务，快去完成吧。");
        return 1;
    }
    if (me->query("statistics/newbie_target/selected")==1)
    {
        command("say 你已经选过了襄阳从军任务，快去完成吧。");
        return 1;
    }
    if (me->query("statistics/newbie_target/selected")==2)
    {
        command("say 你已经选过了周处除三害任务，快去完成吧。");
        return 1;
    }
    command("say 新人立足江湖不易，有些历练或可帮助于你。");
    command("say 郭大侠在襄阳招募豪杰助守襄阳城，周处在义兴县也遇到了困难，或者你也可以像老衲一样游方天下。");
    msg="你可以任选(select)下列游历任务，"+HIR+BLINK+"切记一人一生只能选择一次，慎重！"+NOR+"\n";
    msg+="[1]襄阳从军任务       可获得【"+HIW+"侠之大者"+NOR+"】头衔，有几率获得先天臂力奖励。\n";
    msg+="[2]周处除三害任务     可获得【"+HIC+"降龙伏虎"+NOR+"】头衔，有几率获得先天悟性奖励。\n";
    msg+="[3]游方天下任务       可获得【"+HIG+"神行千里"+NOR+"】头衔，有几率获得先天身法及福源奖励。\n";
    msg+=BLINK+HIW+"除福缘外，其余先天属性将在经验至少二十万后和我再见面时获得。\n"+NOR;
    me->set_temp("statistics/newbie_target/selected",1);
    tell_object(me,msg);
    return 1;
}

int ask_finish()
{
    object me=this_player();
    int i;

    if (me->query("statistics/newbie_target/selected")!=3)
    {
        command("say 大胆鼠辈，竟敢戏弄你佛爷？");
        return 1;
    }
    if (me->query("statistics/newbie_target/youfang_finish"))
    {
        command("say 善哉善哉。");
        return 1;
    }
    if (time()-(int)me->query("statistics/newbie_target/youfang_time")<600)
    {
        command("say 你也太快了吧，这是游历还是逃荒？");
        return 1;
    }
    if (sizeof(me->query("found_region//d/"))<random(20)+35)
    {
        command("say 你去的地方太少了。");
        return 1;
    }
    me->set("statistics/newbie_target/youfang_finish",1);
    me->add("combat_exp",5000);
    CHANNEL_D->do_channel(this_object(), "rw", HIC + me->query("name")+HIC+"完成了游方天下的任务。");
    tell_object(me,HIC+"完成游方天下的Quest，你获得了五千点经验！\n"+NOR);
        if (me->query("combat_exp")<200000&&!random(6))
        {
            me->set("statistics/newbie_target/gift_reward","dex");
        }
        if (me->query("combat_exp")<200000)
        {
            me->add("kar",1);
            tell_object(me,HIW+"你获得了一点福源作为奖励。\n"+NOR);
        }
        
        me->set("title",HIG+"神行千里"+NOR);
        me->set_title(({TITLE_QUEST1,TITLE_QUEST2,TITLE_QUEST3,TITLE_QUEST4,TITLE_QUEST5,TITLE_QUEST6,TITLE_QUEST7,TITLE_QUEST8,TITLE_QUEST9,TITLE_QUEST10}), HIG+"神行千里"+NOR);
        tell_object(me,HIG+"你获得了『神行千里』的称号！\n"+NOR);
        return 1;
}

int do_select(string arg)
{
    object me=this_player();
    int no;
    if (!me->query_temp("statistics/newbie_target/selected"))
    {
        return 0;
    }
    if (!arg||sscanf(arg, "%d", no)!=1)
    {
        tell_object(me,"你只能选择有效的游历任务[1-3]编号！");
        return 1;
    }
    if (no<=0||no>3)
    {
        tell_object(me,"你只能选择有效的游历任务[1-3]编号！");
        return 1;
    }
    me->delete_temp("statistics/newbie_target/selected");
    me->set("statistics/newbie_target/selected",no);
    if (no==1)
    {
        command("say 你选择了帮助郭大侠，去襄阳完成从军任务吧。");
    }
    else if (no==2)
    {
        command("say 你选择了帮助周处，去义兴（镇江府往南）完成除三害任务吧。");
    }
    else
    {
        command("say 你选择了帮助老衲，且去各处游历一番吧。");
        command("say 每到一个新的区域，你会发现这个地方的不同，去过了若干地方之后，回我这里ask monk about finish完成任务。");
        me->set("statistics/newbie_target/youfang_time",time());
    }
    return 1;
}

int adv()
{
    int i;
    object *all_player = filter_array(children(USER_OB), (: userp :));
	if (!environment()||base_name(environment())!="/d/changan/zhuque")
	{
		return 1;
	}
    all_player = filter_array(all_player, (: environment :));
    all_player = filter_array(all_player, (: !$1->query("relationship/target") :) );
    all_player = filter_array(all_player, (: living($1) :) );
    for (i=0;i<sizeof(all_player);i++)
    {
        if (random(20)==7)
        {
            all_player[i]->set_temp("游方和尚找亲戚帮助作弊",1);
            command("tell "+all_player[i]->query("id")+" 你还没找到之前失散的亲戚吧？");
        }
        if (all_player[i]->query("combat_exp")<200000&&!all_player[i]->query("statistics/newbie_target/selected")&&!random(30))
        {
            command("tell "+all_player[i]->query("id")+" 你知道什么是新人里程碑吗？不知道吧？快来跟我请教请教吧。");
        }
    }
    remove_call_out("adv");
    call_out("adv",7200);
    return 1;
}
int change(string id)
{
	object pl;
	if (!wizardp(this_player())) return 0;
	pl=find_player(id);
	if (!pl) return notify_fail("此人不在。\n");
	pl->delete("relationship");
	pl->set_temp("游方和尚找亲戚帮助作弊");
	tell_object(pl,"你可以去找长安老和尚了。\n");
	return 1;
}
int ask_relationship()
{
    object me=this_player();
    object where,target,*inv;
    int i,count=0;
    if (me->is_busy()||me->is_fighting())
    {
        command("say 看你手忙脚乱的。");
        command("smile");
        return 1;
    }
    if (me->query("relationship/target"))
    {
        command("say 我不是告诉你了嘛，快去找到他吧。");
        return 1;
    }
    if (me->query("combat_exp")<1000000)
    {
        command("say 我也没有任何线索，你迟些再来吧。");
        return 1;
    }
    if (me->query("mud_age")-me->query("relationship/last_time")<12*60*60)
    {
        command("say 跟你说了迟些再来，就不能等等吗？");
        return 1;
    }
    if (me->query("combat_exp")-me->query("relationship/last_exp")<1000000)
    {
        command("say 跟你说了迟些再来，就不能等等吗？");
        return 1;
    }
    if (random(10)==7||me->query_temp("游方和尚找亲戚帮助作弊"))
    {
        me->delete_temp("游方和尚找亲戚帮助作弊");
        while(!target && count < 5)
        {
            where = TASK_D->random_place();
            inv = all_inventory(where);
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类")
                    continue;
                if(inv[i]->query("uni_target") || inv[i]->query("random_npc"))
                    continue;
                target = inv[i];
            }
            count++;
        }
        if (target)
        {
            me->set("relationship/target",1);
            me->set("relationship/target_name",target->query("name"));
            me->set("relationship/target_id",target->query("id"));
            me->set("relationship/target_exp",target->query("combat_exp"));
            tell_object(me,this_object()->name()+"道：“我在"+TASK_D->place_belong(where)+"的"+where->query("short")+"修行的时候，听说"+target->query("name")+"很可能是你早年失散的家人。”\n");
            return 1;
        }
        else
        {
            me->set("relationship/last_time",me->query("mud_age"));
            me->set("relationship/last_exp",me->query("combat_exp"));
            command("say 还是没有找到你的家人，过段时间再来吧。");
            return 1;
        }
        
    }
    else
    {
        me->set("relationship/last_time",me->query("mud_age"));
        me->set("relationship/last_exp",me->query("combat_exp"));
        command("say 还是没有找到你的家人，过段时间再来吧。");
        return 1;
    }
}

void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}