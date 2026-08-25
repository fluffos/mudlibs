// train_over.c

#include <train.h>

// #define _DEBUG_ID   "xiaobai"

void big_award(object usr);
void small_award(object usr ,int num);
void release_army(int p_id);

void force_over(int task_id)
{
    string p_leader;
    object usr;

    p_leader = TASK_D->get_task(task_id,"def_leader");

#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf("leader is %s", p_leader) );
#endif  // _DEBUG_ID

    usr = find_body(p_leader);
    if(objectp(usr))
    {
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, "got user object." );
#endif  // _DEBUG_ID

        usr->simple_action
            ("$N无奈地宣布：训练因故终止。\n");
    }
    
    TASK_D->set_task(task_id,"overduetimes", 0);
    TASK_D->set_task(task_id,"successtimes", 0);
    
    train_over(task_id);
}
void train_over(int task_id)
{
   string p_leader;
   object usr,bdy;
   int succ,fail;
   release_army( task_id);
   TASK_D->set_task(task_id,"stage",AFTER_TRAIN);
   TASK_D->set_task(task_id,"timaim",60); // should 
                           // finish within five mins
   p_leader=TASK_D->get_task(task_id,"def_leader");
   bdy=CHAR_D->find_char(p_leader);
   fail=TASK_D->get_task(task_id,"overduetimes");
   succ=TASK_D->get_task(task_id,"successtimes");
   bdy->finish_job("train");
   usr=find_user(p_leader);
   if(((succ-fail)<=0)||(!objectp(usr)))
   {
       if(objectp(usr))
         bdy->simple_action
          ("$N摇头道：很遗憾，本次训练没什么成效，大家还是早点回营去吧。\n");
       TASK_D->remove_task(task_id);
       return;
   }       
   tell_user(p_leader,"训练结束，请回答一个简单的问题。\n");
   ROBOT->robot_test(usr,(:big_award:));
}
void big_award(object usr)
{
    int isrobot,*my_task,task_id;
    int succ,fail;
    string p_area,a_name,p_name;
    string my_id;
    object env;
    usr=usr->query_body();
    if(!objectp(usr)) return;
    isrobot=usr->query_robot();
    my_id=usr->query_id()[0];
    my_task = TASK_D->get_char_task(my_id);
    task_id=my_task[0];
    if(my_task[1]!=TT_TRAIN) return; // strange
    p_area=TASK_D->get_task(task_id,"def_area");
    a_name=AREA_D->get_area(p_area,"name");
    p_name=CHAR_D->get_char(my_id,"name");
    fail=TASK_D->get_task(task_id,"overduetimes");
    succ=TASK_D->get_task(task_id,"successtimes");
    if(isrobot)
    {  usr->simple_action(
          "$N道：今天训练太累了，改日再行赏吧。\n");
       TASK_D->remove_task(task_id);
       return;
    }
    usr->simple_action(
       "$N道：本次共进行了"+chinese_number(fail+succ)+
       "个项目的训练，其中成功了"+chinese_number(succ)+
       "项。\n失败了"+chinese_number(fail)+
       "项。总体效果非常成功，诸位都会有赏。\n");
    succ-=fail;
	succ=succ*15/10;
   AREA_D->set_area(p_area,"train",
       bmin(200,AREA_D->get_area(p_area,"train")+1)); // increase 1 if not some time no reward :(
    AREA_D->set_area(p_area,"morale",           
       bmin(200,AREA_D->get_area(p_area,"morale")+1));
    CHAR_D->set_char(my_id,"reputation",
       CHAR_D->get_char(my_id,"reputation")+succ*10);
    usr->award_exp(succ*20,"");
    CHAR_D->set_char(my_id,"localcontribution",
       CHAR_D->get_char(my_id,"localcontribution")+succ*2);
//    tell_environment(usr,a_name+"士兵的训练度提高了。\n"); // this is done in the train
//    tell_environment(usr,a_name+"士兵的士气提高了。\n");
    tell_environment(usr,p_name+ "的声望上升了。\n");
    tell_environment(usr,p_name+ "的经验增加了。\n");
    tell_environment(usr,p_name+ "地区贡献增大了。\n");
    usr->simple_action("$N高兴地跳了起来。\n");
    usr->simple_action
("$N接着道：大家别走，凡是参加训练的、在这儿的、不傻的都有奖赏。\n");
    env=environment(usr);
    {
       int *party;
       object o;
       party=TASK_D->get_task(task_id,"def_party");
       foreach(string p_id in party)
       {  
          if((p_id!=my_id)&&
            (CHAR_D->get_char(p_id,"status")==STATUS_ONLINE))
          {
             o=present(p_id,env);
             if(objectp(o)) 
             {  o=find_user(p_id);
                if(objectp(o))
                   ROBOT->robot_test(o,(:small_award:),succ);
             }
          }
       }
    }
    usr->simple_action("$N道：领完赏，各位就可以离开啦。\n");
    TASK_D->remove_task(task_id);
}
void small_award(object usr ,int num)
{
    string my_id;
    int isrobot;
    string p_name;
    if(!objectp(usr)) return;
    usr=usr->query_body();
    if(!objectp(usr)) return;
    isrobot=usr->query_robot();
    my_id=usr->query_id()[0];
    p_name=CHAR_D->get_char(my_id,"name");
    if(isrobot)
    {  
usr->simple_action("$N邹了邹眉头：怎么没我的奖赏？\n");
       usr->responda("heng");
       return;
    }
    CHAR_D->set_char(my_id,"reputation",
       CHAR_D->get_char(my_id,"reputation")+num*2);
    usr->award_exp(num*4,"");
    tell_environment(usr,p_name+ "的声望上升了。\n");
    tell_environment(usr,p_name+ "的经验增加了。\n");
}