#include <ansi.h> 
 
mapping *dizhia=({
      (["cdizhi":                "苗疆",
       "weizhi2" :              "/d/miaojiang/jiedao4",]),  
      (["cdizhi":                "扬州",
       "weizhi2" :              "/d/city/xjs",]),  
      (["cdizhi":                "杭州",
       "weizhi2" :              "/d/hz/changlang1",]), 
      (["cdizhi":                "杭州",
       "weizhi2" :              "/d/hz/yuquan",]), 
      (["cdizhi":                "杭州",
       "weizhi2" :              "/d/hz/longjing",]), 
      (["cdizhi":                "杭州",
       "weizhi2" :              "/d/hz/huanglongdong",]),
      (["cdizhi":                "武当",
       "weizhi2" :              "/d/wudang/shijie1",]), 
      (["cdizhi":                "武当",
       "weizhi2" :              "/d/wudang/xuanyuemen",]), 
      (["cdizhi":                "峨嵋",
       "weizhi2" :              "/d/emei/guanyinqiao",]), 
      (["cdizhi":                "峨嵋",
       "weizhi2" :              "/d/emei/basipan3",]), 
      (["cdizhi":                "峨嵋",
       "weizhi2" :              "/d/emei/caopeng",]), 
      (["cdizhi":                "明教",
       "weizhi2" :              "/d/mingjiao/bishui",]), 
      (["cdizhi":                "明教",
       "weizhi2" :              "/d/mingjiao/shanting",]), 
      (["cdizhi":                "福州",
       "weizhi2" :              "/d/fuzhou/haigang",]), 
      (["cdizhi":                "福州",
       "weizhi2" :              "/d/fuzhou/laozhai",]), 
      (["cdizhi":                "星宿海",
       "weizhi2" :              "/d/xingxiu/shamo3",]),
      (["cdizhi":                "少林寺",
       "weizhi2" :              "/d/shaolin/songshu2",]),
      (["cdizhi":                "襄阳",
       "weizhi2" :              "/d/xiangyang/tanxi",]),
      (["cdizhi":                "雪山",
       "weizhi2" :              "/d/xueshan/shanlu1",]),
      (["cdizhi":                "华山",
       "weizhi2" :              "/d/huashan/yunu",]),
      (["cdizhi":                "华山村",
       "weizhi2" :              "/d/village/zhongxin",]),
      (["cdizhi":                "慕容山庄",
       "weizhi2" :              "/d/mr/xiaojing1-2",]),
      (["cdizhi":                "慕容山庄",
       "weizhi2" :              "/d/mr/liulin",]),
      (["cdizhi":                "苏州城",
       "weizhi2" :              "/d/suzhou/baodaiqiao",]),
      (["cdizhi":                "苏州城",
       "weizhi2" :              "/d/suzhou/shihu",]),
      (["cdizhi":                "苏州城",
       "weizhi2" :              "/d/suzhou/xuanmiaoguan",]),
      (["cdizhi":                "苏州城",
       "weizhi2" :              "/d/suzhou/zijinan",]),
      (["cdizhi":                "少林寺",
       "weizhi2" :              "/d/shaolin/xiaolu-3",]),
      (["cdizhi":                "少林寺",
       "weizhi2" :              "/d/shaolin/talin1",]),
      (["cdizhi":                "武当",
       "weizhi2" :              "/d/wudang/husunchou",]),
      (["cdizhi":                "少林寺",
       "weizhi2" :              "/d/shaolin/shanlu8",]),
      (["cdizhi":                "星宿海",
       "weizhi2" :              "/d/xingxiu/mogaoku",]),
      (["cdizhi":                "峨嵋",
       "weizhi2" :              "/d/emei/jiulaodong",]),
      (["cdizhi":                "峨嵋",
       "weizhi2" :              "/d/emei/gudelin3",]),
      (["cdizhi":                "恒山",
       "weizhi2" :               "/d/hengshan/cuiping2",]), 
      (["cdizhi":                "恒山",
       "weizhi2" :               "/d/hengshan/guolaoling",]), 
      (["cdizhi":                "佛山镇",
       "weizhi2" :              "/d/foshan/duchang",]),
      (["cdizhi":                "黄河沿岸",
       "weizhi2" :              "/d/huanghe/shulin5",]),  
      (["cdizhi":                "佛山镇",
       "weizhi2" :              "/d/foshan/road10",]),
      (["cdizhi":                "佛山镇",
       "weizhi2" :              "/d/foshan/xiaolu2",]),
      (["cdizhi":                "恒山",
       "weizhi2" :               "/d/hengshan/beiyuemiao",]), 
      (["cdizhi":                "丐帮分舵",
       "weizhi2" :              "/d/gb/xinglin2",]),
      (["cdizhi":                "丐帮分舵",
       "weizhi2" :              "/d/gb/shangang",]),
      (["cdizhi":                "黄河沿岸",
       "weizhi2" :              "/d/huanghe/huanghe4",]),
      (["cdizhi":                "青城山",
       "weizhi2" :              "/d/huanghe/shamo",]),    
      });

// add by Yuj@SJ to avoid same name BUG. 19991216
varargs mixed query(string prop, int raw)
{
	if (prop == "color") return HIR;
	if (prop == "name") return ::query(prop, raw)+SAVEC;
	return ::query(prop, raw);
}

int dest_flag = 0;

void init()
{
        object ob, me;
        mapping dizhis;
        int exp, nei, nei1;

        ::init();

        ob = this_player();
        me = this_object();
        nei = me->query("neili",1);
        nei1 = ob->query("neili",1);
        

        dizhis = dizhia[random(sizeof(dizhia))];
        exp = me->query("combat_exp");

        set("no_quest",1);
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );

        if (interactive(ob)
                && !environment(ob)->query("no_fight")
                && present("wenshu", ob)
                && (string)me->query("name") == ob->query_temp("guanfu_target")) {
                        if (ob->query_temp("mark/gkill1")){
                                message_vision(
                                HIR"$n看到$N目光冷冷注视着自己一动不动，不由停下了脚步。\n"NOR, ob, me);

                switch(random(4)) {
           case 0:
                                message_vision(
                                        "$n嘿嘿奸笑几声，连忙赔笑道，这位"+RANK_D->query_respect(ob)+"是"
"官府的捕头吧？！大家都是武林中人，今天能否高抬贵手？我必有重谢！你好好斟酌一下，是否愿意？\n",ob,me);
                        write (HIY"你可以选择同意(yes)或者拒绝(no)。\n"NOR);
                        ob->set_temp("guanf_huida1", me->query("name"));
                        break;
                case 1:
                        message_vision(
                                HIR"$n阴笑一声说道，这麽多不怕死的？再来十个大爷我也不怕！\n"
                                "随即眼睛一瞪，向着$N就冲了过去！\n"NOR,ob,me);
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                        ob->delete_temp("mark/gkill1");
                        break;
                case 2:
                        message_vision(
        WHT"$n待$N走到近前，冷冷一笑，说道，你千里追到这里，我看你又能奈我何！\n"NOR,ob,me);
                        write (WHT"你感到一股无形的杀气，心中不由一颤。\n"NOR);
                        ob->delete_temp("mark/gkill1");
                        break;
                case 3:
                        message_vision(
                        "$n忽然泪流满面，一幅可怜的神情对$N说道，小人上有老下有小，而且完全是官府被\n"
                        "陷害才落此地步，望你老明察秋毫，网开一面，我今生一定感激不禁。\n",ob,me);    
           ob->delete_temp("mark/gkill1");
                }
        }
        if (ob->query_temp("mark/gkill1")
        && (string)me->query("name") == ob->query_temp("guanfu_huida1")){
                message_vision(
                        HIR"$n看到$N走到近前，狠狠的骂道，不识抬举的东西，我好言相劝没用，\n"
                        "今天就让你尝尝大爷的厉害。\n"NOR,ob,me);
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
                ob->delete_temp("guanf_huida1");
                ob->delete_temp("mark/gkill1");
                me->add("combat_exp",exp/4);
        }
        if (ob->query_temp("mark/gkill2")){
        switch(random(4)) {
                case 0:
                        message_vision(
                                HIR"$n额头青筋跳动，冷哼了一声，瞪着通红的眼睛向着$N就冲了过去。\n"NOR,
                                ob,me);
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                        break;
                case 1:
                        message_vision(
                        HIY"$n一看到$N，嘿嘿一笑，头也不回挤进行人之中，脚下抹油溜了。\n"NOR,ob,me); 
                        ob->delete_temp("mark/gkill2");
                        ob->set_temp("mark/gkill3",1); 
                case 2:
                        message_vision(
                                HIR"$n额头青筋跳动，冷哼了一声，瞪着通红的眼睛向着$N就冲了过去。\n"NOR,
                                ob,me);
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                        break;
                case 3:
                        message_vision(
                                HIR"$n额头青筋跳动，冷哼了一声，瞪着通红的眼睛向着$N就冲了过去。\n"NOR,
                                ob,me);
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                        break;
write(WHT"「"+ob->query_temp("guanfu_target")+"」好象往「"+dizhis["cdizhi"]+"」的方向逃去了。\n"NOR);
           me->move(dizhis["weizhi2"]);
           return; 
                }         
        }
        if (ob->query_temp("mark/gkill3")){
message_vision(HIR"$n气急败坏的对$N嚷道，杀人不过头点地，你一再苦苦向逼，大爷今天就和你拼个鱼死网破。\n"NOR,ob,me);
                if(nei<nei1&&
                !me->query_temp("gf_nlset")){
                me->set("neili",nei1);
                me->set_temp("gf_nlset",1);
                }
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
                me->add("combat_exp",exp/5);
                me->reincarnate(); 
        }
        add_action("do_yes","yes");
        add_action("do_no","no");
        }
        if (!dest_flag) call_out("dest", 1800); 
        dest_flag = 1;
} 

int do_yes()
{
        object me, ob;
        me = this_object();
        ob = this_player();

        if (!ob->query_temp("guanf_huida1"))
        return 0;
        if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
        return 0;

        if ((int)ob->query("shen") < 1){
        command("say 这位"+RANK_D->query_respect(ob)+"一定前途远大，嘿嘿，我是不会亏待你的。\n");
        me->add_money("gold",20+random(20));
        command("give "+ob->query("id")+" gold");
        message_vision("$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        ob->delete_temp("guanfu_target");
        destruct(me);
        return 1;
        }
        else
        {
        command("say 这位"+RANK_D->query_respect(ob)+"前途远大，一身正气，嘿嘿，佩服。\n");
        me->add_money("gold",20+random(30));
        command("give "+ob->query("id")+" gold");
        ob->add("shen",-1000);
        message_vision("$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        ob->delete_temp("guanfu_target");
        destruct(me);
        return 1;
        }
        return 1;
}
   

int do_no()
{
        object me, ob;
        me = this_object();
        ob = this_player();

        if (!ob->query_temp("guanf_huida1"))
        return 0;
        if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
        return 0;
        if ((int)ob->query("shen") < 1){
        command("say 这位"+RANK_D->query_respect(ob)+"一身瘴气，你我本是一路货色，却在这里装什么侠义英雄呢？！\n");
        ob->delete_temp("guanf_huida1");
        ob->delete_temp("mark/gkill1");
        return 1;
        }
        command("say 这位"+RANK_D->query_respect(ob)+"一身正气，不愧名门正派弟子，不过不知道功夫怎麽样？！\n");
        command("hehe " + ob->query("id"));
        ob->delete_temp("guanf_huida1");
        ob->delete_temp("mark/gkill1");
        return 1;
}

void die()
{
        object ob, me;
        mapping dizhis;
        
        ob = this_object();
        me = query_temp("last_damage_from");
	if (!objectp(me)) return;
        dizhis = dizhia[random(sizeof(dizhia))];  
        
        if (!me->query_temp("mark/gkill3")
        &&  !me->query_temp("mark/gkill2")
        && (string)ob->query("name") == me->query_temp("guanfu_target")){
        message_vision(WHT"$N深吸口气，冷笑道，好身手！说完强忍伤痛纵身向「"+dizhis["cdizhi"]+"」处逃走。\n"NOR,ob,me);
 me->set_temp("mark/gkill2",1);
me->set_temp("ch_weizhi",dizhis["cdizhi"]);
        new(me->query_temp("path_rooms"))->move(dizhis["weizhi2"]);
        destruct(ob);
        return;
        }
        if (me->query_temp("mark/gkill2")
        && (string)ob->query("name") == me->query_temp("guanfu_target")){
        message_vision(WHT"$N冷笑一声，说道，好俊的功夫！说完纵身向「"+dizhis["cdizhi"]+"」处逃走。\n"NOR,ob,me);
        me->delete_temp("mark/gkill2");
me->set_temp("ch_weizhi",dizhis["cdizhi"]);
        me->set_temp("mark/gkill3",1);
        new(me->query_temp("path_rooms"))->move(dizhis["weizhi2"]);
        destruct(ob);
        return;
        }
        if (ob->query("name") != me->query_temp("guanfu_target")) {
                ob->revive(1);
                command("chat "+me->name(1)+"，你不得好死，我要向闪电报告！");
                destruct(ob);
                return;
        }
        ::die();
}

void unconcious()
{
       die();
}

int accept_fight(object me)
{
        command("say 大爷我正要赶路，没心思和你动手。");
        return 0;
}
void dest()
{
       object ob;
       ob = this_object();
    if (environment())
       message_vision("只见$N忽然急转身行，纵身钻进行人中，转眼就踪迹皆无。\n", ob);  
       destruct(this_object());
}
