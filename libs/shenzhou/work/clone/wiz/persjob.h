// Code of ShenZhou
// /kungfu/class/emei/pers_job.h
// yasuko: 2000/09/13
#include <ansi.h>

#define BUSY_TIME       180
void setupras( object rascal, object me );
/*
int  per_end(object me,object target);
*/
string *place = ({
        "/d/emei/",
});

string *area = ({
        "峨嵋",
});

string *ras_name = ({
        "流氓",
        "无赖",
        "地痞",
        "武林败类",
        "小混混",
        "叛徒",
        "浪人", 
});



string ask_for_job()
{
        object ob,obj,me=this_player();
        int i,j,k;
         string dir,msg;
        string meet_room,room;
         mixed *file;
        int lvl = me->query_skill("persuading",1);
        int     qn,exp;
        string  bonus;
/*
        if (!wizardp(me))
        return "大神slow吩咐了，这几天不能让大家劝架，贫尼代替slow 向大家道歉，此job 近期开放。"; 
*/
        if (me->query("family/family_name")!="峨嵋派") {
                command ("smile ");
                return RANK_D->query_respect(this_player())+"也会劝驾吗？";
        }
        
        if (me->query_temp("mp_persjob") == 2)
        {
                exp = 180+random(40);
                qn = 70+random(20);
                bonus = sprintf(HIW"你本次任务共得到:%d点经验，%d点潜能。\n"NOR,exp,qn);
                tell_object(me,bonus); 
                command("haha ");
                me->delete_temp("mp_persjob");
                me->add("combat_exp",exp);
                me->add("potential",qn);
                if (me->query("potential") > me->query("max_potential"))
                        me->set("potential",me->query("max_potential"));

                return "干得好，不愧是我们峨嵋弟子啊。";
        
        }
        if (me->query_temp("mp_persjob") == 1) {
                command ("hmm ");
                return "上回交给你的任务还没办完吧......";
        }
        if (time()<me->query("mp_job_time")+BUSY_TIME) {
                command ("hehehe ");
                return "托郭祖师的福，最近好象挺太平的。";
        }

        if (me->query_skill("persuading",1) < 30)
        {
                return "你的渡世济人还不够啊。";
        }
 
      command ("nod ");
        
        dir = place[0];
        file = get_dir(dir, -1);
        i = sizeof(file);
        if (!sizeof(file) || i<1)
                return "托郭祖师的福，最近好象挺太平的。";

        me->set_temp("mp_persjob",1);
        me->set("mp_job_time",time());

        

        for(j = 0; j<=random(i-1);j++ ) {
                if(file[j][0][strlen(file[j][0])-2..strlen(file[j][0])] != ".lpc") continue; 
                        file[j][0]= replace_string(file[j][0],".lpc","");
                
        }
        
        msg = sprintf("%s%s",place[0],file[j][0]);

        if (me->query("combat_exp")<100000)
                msg="/d/emei/hz_guangchang.lpc";
        if (wizardp(me)) tell_object(me,msg);

       meet_room=msg;
       obj=load_object(meet_room);
       room=obj->query("short");
        ob = new("/kungfu/class/emei/rascal");
        setupras(ob,me);
        ob->set("per_mark",me);
        ob->move(meet_room);

        msg = sprintf("有人在%s的%s捣乱，那就相烦%s速去把他劝服(quanfu)。\n",area[0],room,RANK_D->query_respect(this_player()));
/*
        msg = sprintf("有人在%s的%s捣乱，那就相烦速去把他劝服。\n",area[0],room);
*/
        tell_object(me,msg);
        return "还不快去?";
/*
        return "有人在"+area[0]+"的"+room+"捣乱，那就相烦"+RANK_D->query_respect(this_player())+"速去把他劝服。";
*/
}

void setupras( object rascal, object me ) 
{ 
        int myexp = me->query( "combat_exp" ); 
        int level = to_int(pow(myexp*10,0.33333)+1); 
        if (me->query("combat_exp") < 100000)
        {
                level = level/2;
        }
        else
        level = level * 5 / 4;
        
        if ( level < 20 ) level = 20; 
        rascal->set_skill( "strike", level ); 
        rascal->set_skill( "cuff", level ); 
        rascal->set_skill( "force", level ); 
        rascal->set_skill( "parry", level*3/2 ); 
        rascal->set_skill( "dodge", level ); 
        rascal->set_skill( "hand", level );
        rascal->set_skill( "qinnashou", level );
        rascal->set_skill( "liuxing-bu", level );
        rascal->map_skill( "hand", "qinnashou" );
        rascal->map_skill( "dodge", "liuxing-bu" );
        rascal->prepare_skill("hand", "qinnashou");

        rascal->set( "max_qi", me->query("max_qi")); 
        rascal->set( "eff_qi", me->query("max_qi")); 
        rascal->set( "qi", me->query( "max_qi" )); 
        rascal->set( "max_neili", me->query( "max_neili" ) ); 
        rascal->set( "neili", me->query( "max_neili" ) ); 
        rascal->set( "max_jingli", me->query( "max_jingli" ) ); 
        rascal->set( "eff_jingli", me->query( "eff_jingli" ) ); 
        rascal->set( "jingli", me->query( "max_jingli" ) );
        if (level > 100)
        rascal->set("jiali",level/2); 
        rascal->set("combat_exp",me->query("combat_exp"));
} 
/*
int do_quanfu(string who)
{
        object me = this_player();
        object target;
        object where = environment(me);
        int     lvl=me->query_skill("persuading",1);
        mixed busy;
        
        if (!me->query_temp("mp_persjob"))
                return notify_fail("快回去相灭绝师太复命吧。\n");

        if (!who)
                return notify_fail("你要劝服谁？\n");
        
        target = present(who, environment(me));
        if ( !target || target == me || !living(target) || !objectp(target) ) 
                return notify_fail("你想劝服谁？\n");

        if ( busy = me->query_busy() ) {
                if (intp(busy)) me->start_busy(busy+1);
                return notify_fail("你现在正忙着！\n");
        }
        
        if ( target->query("race") != "人类" )
                return notify_fail(target->name() + "听不懂人话！\n");

        if ( target->query("per_mark")!=target)
                return notify_fail("灭绝师太不是让你劝服这个人吧。\n");

        if ( me->query_temp("new_per") == 1)
                return notify_fail("你正在劝服别人。\n");

        if (me->query("jingli") < lvl || me->query("jing")<lvl)
                return notify_fail("你的身体状况不好，没有力气劝架了。\n");

       tell_object(me, HIY + "你对" + EMOTE_D->normal_color(target->name())
              + "说道：" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR); 

       tell_object(target, HIY + me->name() + "对你说道：" +
                persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR);

       message("vision", HIY + me->name() + "对" + EMOTE_D->normal_color(target->name()) 
                + "说道：" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR,
                where, ({ me, target }) );


        me->set_temp("new_per",1);
        me->add("jingli",-(10+random(lvl)));
        me->add("jing",-(10+random(lvl)));

        if (!target->is_fighting())
        {
                message_vision(HIR"$N嘿嘿一笑，你是什么东西，敢劝老子? 老子宰了你。\n"NOR,target,me);
                target->kill_ob(me);
        }
        call_out("per_end",2+random(4),me,target);


        return 1;
}

int     per_end(object me,object target)
{
        int lvl = me->query_skill("persuading",1);
        int myexp = me->query( "combat_exp" ); 
        int level = to_int(pow(myexp*10,0.33333)+1); 

        if (environment(target) != environment(me)) {
                tell_object(me, "善哉，" + target->name() + "已经走了。\n"); 
                me->delete_temp("new_per");
                return 1;
        }

        if ( !living(target) || !target ) {
                tell_object(me, target->name() + "已不能听取你的劝导了！\n");
                me->delete_temp("new_per");
                return 1;
        }


        if (random(lvl) > level || random(15) == 0)
        {
                tell_object(target, HIG + "你受到" + me->name()
                                  + "的感招，决定罢手不斗。\n" + NOR);
                tell_object(me, HIG + EMOTE_D->normal_color(target->name()) 
                              + "受到你佛法感招，决定罢手不斗。\n" + NOR);
              message("vision", CYN"只见" + EMOTE_D->normal_color(target->name()) 
                        + "往后一纵，说道：好！" + me->name() 
                        + succeed_msg[random(sizeof(succeed_msg))] + NOR, 
                        environment(target), ( {me, target} ) );

                target->remove_all_killer();
                destruct(target);
                me->delete_temp("new_per");
                me->delete_temp("mp_persjob");


        }
        else
        {
                tell_object(me, RED + EMOTE_D->normal_color(target->name()) + "冲你大喝一声：“"
                                       + RANK_D->query_rude(me) 
                                       + "多管闲事，看招！”\n" + NOR);
                tell_object(target, CYN + "你冲" + me->name() + "大喝一声：“"
                                          + RANK_D->query_rude(me)
                                          + "多管闲事，看招！”\n" + NOR);
                message("vision", CYN + "只见" + EMOTE_D->normal_color(target->name()) + "冲着"
                                        + me->name() + "大喝一声：“"
                                        + RANK_D->query_rude(me)
                                        + "多管闲事，看招！”\n" + NOR, environment(target),
                                        ( {me, target} ) );
                me->delete_temp("new_per");

        }
        me->start_busy(1+random(1));
        return 1;
}
*/
