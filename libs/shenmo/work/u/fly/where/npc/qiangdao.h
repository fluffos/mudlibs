inherit NPC;
#include <ansi.h> 
string query_family_type(string fam);
void copy_status(object me,object ob,int lv);

void init()
{
        object ob, me;
        int exp, nei, nei1;

        ::init();
        ob = this_player();
        me = this_object();
        nei = me->query("force",1);
        nei1 = ob->query("force",1);      
        exp = me->query("combat_exp");
      
        
 if (interactive(ob)
                 //  如果 ob 是一个可互动的玩家, 就传回非零值.
    && me->query("id2") == ob->query("id")) {
                if (ob->query_temp("yidao/gkill1")){
                                message_vision(RED"\n$n看到$N目光冷冷注视着自己一动不动，不由停下了脚步。\n"NOR, ob, me);
                                copy_status(me,ob,1);
                       
                                message_vision(YEL"$n嘿嘿奸笑几声，连忙赔笑道，这位"NOR+RANK_D->query_respect(ob)+YEL"是官府的捕头吗？\n"NOR,ob,me);
                                message_vision(YEL"$n接着道:大家都是妖神中人，今天能否高抬贵手？我必有重谢！你是否愿意？\n"NOR,ob,me);
                                write (HBYEL"你可以选择同意(yes)或者拒绝(no)。\n"NOR);
                                ob->set_temp("yidao/guanf_huida1", me->query("name"));
                        }
              if (ob->query_temp("yidao/gkill1")
                 && (string)me->query("name") == ob->query_temp("yidao/guanfu_huida1")){
                message_vision(HIR"$n看到$N走到近前，狠狠的骂道，不识抬举的东西，我好言相劝没用。\n"NOR,ob,me);
                message_vision(HIR"$N,今天就让你尝尝大爷我$n的厉害。\n"NOR,ob,me);
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
                ob->delete_temp("yidao/guanf_huida1");
                ob->delete_temp("yidao/gkill1");
                me->add("combat_exp",exp/10);
                me->add("force",500);
                me->add("mana",500);
               }
             if (ob->query_temp("yidao/gkill2")){
            
                        message_vision(HIR"\n$n额头青筋跳动，冷哼了一声，瞪着通红的眼睛向着$N就冲了过去。\n"NOR,ob,me);
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                        copy_status(me,ob,2);  
                   }
        if (ob->query_temp("yidao/gkill3")){
                me->set("title", HIY"逍遥山庄 叛徒"NOR);
                copy_status(me,ob,2);
                message_vision(HIR"\n$n气急败坏的对$N嚷道，杀人不过头点地，你一再苦苦向逼，大爷今天就和你拼个鱼死亡破。\n"NOR,ob,me);
                message_vision(HIR"$N惊讶道:原来你是逍遥山庄的叛徒。\n"NOR,ob,me);
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
                me->add("mana",ob->query("max_mana")/5);
                me->add("force",ob->query("max_force")/4);
                me->add("combat_exp",ob->query("combat_exp")/10);
        }
                }
        call_out("dest", 2000); 
        add_action("do_yes","yes");
        add_action("do_kill","kill");
        add_action("do_no","no");
} 

int do_yes()
{
        object r_shen, me, ob;
        me = this_object();
        ob = this_player();

        if (!ob->query_temp("yidao/guanf_huida1"))
        return 0;
        if (ob->query_temp("yidao/guanf_huida1") != (string)me->query("name"))
        return 0;

    
      if(random(5)==1){
        command("say 这位"+RANK_D->query_respect(ob)+"真是义薄云天，这个小礼物敬请务必收下。\n");
        me->add_money("gold",50+random(30));
        command("give "+ob->query("id")+" gold");
      }
        message_vision("$N嘿嘿奸笑两声，悄悄塞给了$n一棵人参。\n",me,ob);
        r_shen=new("/u/fly/job/guanfu/renshen");
        r_shen->move(ob);
        message_vision("\n$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        destruct(me);
   
        return 1;
}
   

int do_no()
{
        object me, ob;
        me = this_object();
        ob = this_player();

        if (!ob->query_temp("yidao/guanf_huida1"))
        return 0;
        if (ob->query_temp("yidao/guanf_huida1") != (string)me->query("name"))
        return 0;
        if (query_family_type(ob->query("family/family_name"))=="yao"){
        command("say 这位"+RANK_D->query_respect(ob)+"一身瘴气，你我本是一路货色，却在这里装什么侠义英雄呢？！\n");
        ob->delete_temp("yidao/guanf_huida1");
        ob->delete_temp("yidao/gkill1");
        return 1;
        }
        command("say 这位"+RANK_D->query_respect(ob)+"一身正气，不愧名门正派弟子，不过不知道功夫怎麽样？！\n");
        command("hehe " + ob->query("id"));
        ob->delete_temp("yidao/guanf_huida1");
        ob->delete_temp("yidao/gkill1");
        return 1;
}

void die()
{
        object ob, me,ob2;
        
        ob = this_object();
        me = query_temp("last_damage_from");
     if (!me) return;
        
        if (!me->query_temp("yidao/gkill3")
        &&  !me->query_temp("yidao/gkill2")
        && ob->query("id2") == me->query("id")){
        message_vision("\n$N深吸口气，冷笑道，好身手！。\n",ob,me);
        message_vision("\n$N喝了一声,走！\n",ob,me);
        me->set_temp("yidao/gkill2",1);
        me->delete_temp("yidao/gkill1");
        ob2=new("/u/fly/where/npc/qiangdao");
        ob2->move("/d/kaifeng/taishan/daizong");
        ob2->set("name2",ob->query("name2"));
        ob2->set("id2",ob->query("id2"));
        message_vision(FLA+HIY"\n$N似乎去了泰山的岱宗坊！\n\n"NOR,ob,me);
        destruct(ob);
        return;
        }
        if (me->query_temp("yidao/gkill2")
        && ob->query("id2") == me->query("id")){
        message_vision("\n$N冷笑一声，说道，好俊的功夫！\n",ob,me);
        me->delete_temp("yidao/gkill2");
        me->set_temp("yidao/gkill3",1);
        
        message_vision("\n$N喝了一声,走！\n",ob,me);
        ob2=new("/u/fly/where/npc/qiangdao");
        ob2->move("/d/kaifeng/taishan/yuhuang");
        ob2->set("name2",ob->query("name2"));
        ob2->set("id2",ob->query("id2"));
        message_vision(FLA+HIY"\n$N似乎去了泰山的玉皇顶！\n"NOR,ob,me);
        destruct(ob);
        return;
        }
        me->set_temp("yidao/taskok",1);
        ::die();
}
int accept_fight(object me)
{
        command("say 大爷我正要赶路，没心思和你动手。");
        return 0;
}

int do_kill()
{
        object me, ob;
        me = this_object();
        ob = this_player();

 if (interactive(ob)
    && me->query("id2") == ob->query("id")) {
message_vision("$N看样子想杀死$n，决不手下留情。\n",ob,me);
                me->call_out("kill_ob", 1, ob);
                ob->call_out("kill_me", 1, me);
   return 0;
    }
else {
message_vision("$N看样子想杀死$n，决不手下留情。\n",ob,me);
message_vision("$n说道：嘘。。。小声点！大灰狼听到了会把你叼走的！。\n",ob,me);
   return 1;
}
}

void dest()
{
       object ob;
       ob = this_object();
       if (environment())
       message_vision(FLA+HIB"只见$N忽然急转身行，纵身钻进行人中，转眼就踪迹皆无。\n"NOR, ob);  
       destruct(this_object());
}
void copy_status(object me,object ob,int lv)
{
      
        int j, lvl;
        int base=5;
        int max_sk;
        mapping skill=ob->query_skills();
        int i=sizeof(skill);
        string* key;
        int max_level;
        int max_sen, max_kee;
        lvl=lv+base-random(2);
        
            if(i>0) {
                key=keys(skill);
                max_level=skill[key[0]];
                while(i--) { // find out victim's maximum level
                    if(skill[key[i]]>max_level&&key[i]!="literate")
                        max_level=skill[key[i]];
                }
                max_sk=max_level;
                max_level=max_level*lvl/base;

            } else max_level=1;
     
            max_sen=ob->query("max_sen")*(2+lv)/2;
            max_kee=ob->query("max_kee")*(600+random(max_level/3)+max_level*2/3)/600;

            me->set("eff_sen",max_sen);
            me->set("eff_kee",max_kee);
            me->set("sen",max_sen);
            me->set("kee",max_kee);
            me->set("max_sen",max_sen);
            me->set("max_kee",max_kee);
            max_kee=max_sk*15;
            max_sen=max_sk*15;
            me->set("max_force",max_kee);
            me->set("force",max_kee*3/2);
            me->set("force_factor",max_kee/50);
            me->set("max_mana",max_sen*2/3);
            me->set("mana",max_sen*4/5);
            me->set("mana_factor",max_sen/50);
            me->set("combat_exp",ob->query("combat_exp")*(8+lv)/8);
            lv=lv+7+random(2);
            me->set_skills(max_level,lv);
}

string query_family_type(string fam)
{
    if(fam=="东海龙宫"||fam=="方寸山三星洞"||fam=="五庄观"||
        fam=="月宫"||fam=="南海普陀山")
        return "xian";
    return "yao";       
}



