#include <ansi.h>

inherit F_DBASE;
#define MPFILE "/data/npc/menpai.o"
#define MPFILEA "/data/npc/menpai1.o"
void init_creat_job();
void get_job();
void do_clone(mapping target);
mapping *where=({
        (["party":        "少林派",
        "where" :         "/d/shaolin/guangchang2",]),
        (["party":      "武当派",
        "where" :       "/d/wudang/guangchang",]),
        (["party":       "灵鹫宫",
        "where" :       "/d/lingjiu/dating",]),
        (["party":       "华山派",
        "where" :       "/d/huashan/qunxianguan",]),
        (["party":       "丐帮",
         "where" :       "/d/city/pomiao",]),
         (["party":       "大理段家",
         "where" :       "/d/dali/wfdating",]),
       (["party":       "古墓派",
         "where" :       "/d/gumu/qianting",]),
              (["party":       "星宿派",
         "where" :       "/d/xingxiu/xxh2",]),
               (["party":       "神龙教",
         "where" :       "/d/shenlong/dating",]),
               (["party":       "逍遥派",
         "where" :       "/d/xiaoyao/qingcaop",]),
               (["party":       "铁掌帮",
         "where" :       "/d/tiezhang/wztang",]),
                (["party":       "昆仑派",
         "where" :       "/d/kunlun/guangchang",]),
               (["party":       "桃花岛",
         "where" :       "/d/taohua/dating",]),
              (["party":       "白驼山派",
         "where" :       "/d/baituo/dating",]),
               (["party":       "雪山寺",
         "where" :       "/d/xueshan/dadian",]),
               (["party":       "全真教",
         "where" :       "/d/quanzhen/datang1",]),
                (["party":       "姑苏慕容",
         "where" :       "/d/mr/yanziwu",]),
                (["party":       "凌霄城",
         "where" :       "/d/lingxiao/dadian",]),
                (["party":       "五毒教",
         "where" :       "/d/wudujiao/dating",]),
                (["party":       "唐门",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "飞天御剑流",
         "where" :       "/d/feitian/daochang",]),

 });
 
mapping *where2=({
        (["party":        "少林派",
        "where" :         "/d/shaolin/guangchang2",]),
        (["party":      "武当派",
        "where" :       "/d/wudang/guangchang",]),
        (["party":       "灵鹫宫",
        "where" :       "/d/lingjiu/dating",]),
        (["party":       "华山派",
        "where" :       "/d/huashan/qunxianguan",]),
        (["party":       "丐帮",
         "where" :       "/d/city/pomiao",]),
         (["party":       "大理段家",
         "where" :       "/d/dali/wfdating",]),
       (["party":       "古墓派",
         "where" :       "/d/gumu/qianting",]),
              (["party":       "星宿派",
         "where" :       "/d/xingxiu/xxh2",]),
               (["party":       "神龙教",
         "where" :       "/d/shenlong/dating",]),
               (["party":       "逍遥派",
         "where" :       "/d/xiaoyao/qingcaop",]),
               (["party":       "铁掌帮",
         "where" :       "/d/tiezhang/wztang",]),
                (["party":       "昆仑派",
         "where" :       "/d/kunlun/guangchang",]),
               (["party":       "桃花岛",
         "where" :       "/d/guiyun/qianyuan",]),
              (["party":       "白驼山派",
         "where" :       "/d/baituo/dating",]),
               (["party":       "雪山寺",
         "where" :       "/d/xueshan/dadian",]),
               (["party":       "全真教",
         "where" :       "/d/quanzhen/datang1",]),
                (["party":       "姑苏慕容",
         "where" :       "/d/mr/yanziwu",]),
                (["party":       "凌霄城",
         "where" :       "/d/lingxiao/dadian",]),
                (["party":       "五毒教",
         "where" :       "/d/wudujiao/dating",]),
                (["party":       "唐门",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "飞天御剑流",
         "where" :       "/d/feitian/daochang",]),

 });	

void create()
{
        seteuid(getuid());
        set("channel_id", "任务精灵");
        set("id", "JOB");
        init_creat_job();
}
void init_creat_job()
{
        CHANNEL_D->do_channel( this_object(), "sys", "浩劫任务加载成功！");
        remove_call_out("get_job");
  call_out("get_job",600);
}
void get_job()
{
        object *obs = users(), ob, robot,killer1,killer2;
        string ppl;
        mapping target;
        string *dir,roomname;
        object room;
        int i,j,k,a,b,c;
        target=where[random(sizeof(where))];
if (random(2)==0)
target=where2[random(sizeof(where2))];	
                j=random(24)+1;
        robot = clone_object("/quest/haojie/jobnpc/"+j);
if (robot->query("family/family_name") == target["party"])
{
j=random(24)+1;
robot = clone_object("/quest/haojie/jobnpc/"+j);
}
if (robot->query("family/family_name") == target["party"])
{
j=random(24)+1;
robot = clone_object("/quest/haojie/jobnpc/"+j);
}

if (robot->query("family/family_name") != target["party"])
{
message("channel:chat", HIC"\n【江湖浩劫】"+robot->query("family/family_name") + ":众弟子听令!"NOR"。\n", users());
message("channel:chat", HIC"\n【江湖浩劫】"+robot->query("family/family_name") + ":顺我者生，逆我者亡!"NOR"。\n", users());
message("channel:chat", HIC"\n【江湖浩劫】"+robot->query("family/family_name") + ":" + target["party"]+"与我派做对，这一次誓必要消灭"+target["party"]+"!"NOR"。\n", users());
write_file(MPFILE,sprintf("%s",
	robot->query("family/family_name")),1);

write_file(MPFILEA,sprintf("%s",
	target["party"]),1);
a=random(3000000)+1000000;
b=random(6000)+1800;
c=random(420)+100;        
        remove_call_out("do_dest");
        call_out("do_dest",800,robot);
        for(k=0;k<=7;k++)
        {
                killer1=clone_object("/quest/haojie/jobnpc/"+j);
                killer1->set("hated",target["party"]);
                if( room = find_object(target["where"]+".c")){
                        CHANNEL_D->do_channel( this_object(), "sys","查找成功，目前"+killer1->query("name")+"在"+file_name(room)+"\n");
                killer1=clone_object("/quest/haojie/jobnpc/"+j);
                killer1->set("hated",target["party"]);
                killer1->set("combat_exp",a);
                killer1->set("max_qi",b);
                killer1->set("qi",b);
                killer1->set("max_jing",b);
                killer1->set("jing",b);
                killer1->set("max_neili",b*2);
                killer1->set("neili",b*2);
                killer1->move(room);
                killer1->random_move();
                }else if(room = load_object(target["where"]+".c")){
                        CHANNEL_D->do_channel( this_object(), "sys","查找成功，目前"+killer1->query("name")+"在"+file_name(room)+"\n");
                killer1=clone_object("/quest/haojie/jobnpc/"+j);
                killer1->set("hated",target["party"]);
                killer1->set("combat_exp",a);
                killer1->set("max_qi",b);
                killer1->set("qi",b);
                killer1->set("max_jing",b);
                killer1->set("jing",b);
                killer1->set("max_neili",b*2);
                killer1->set("neili",b*2);
                killer1->move(room);
                killer1->random_move();
                }
        }
}
}

void do_dest(object robot)
{
        object *obj=users(),ob;
       int i;
if (robot)
{
message("channel:chat", HIC"\n【江湖浩劫】"+robot->query("family/family_name") + ":哼，这次就先放你们一马，下次一定杀得你们鸡犬不留！"NOR"。\n", users());
//        CHANNEL_D->do_channel(robot, "chat",HIR"哼，这次就先放你们一马，下次一定杀得你们鸡犬不留！"NOR);
        destruct(robot);
}
        remove_call_out("get_job");
        call_out("get_job",1800);
}
