#include <ansi.h>

mapping *quest = ({
     ({
     (["name":                "江湖宵小",
      "where" :              "/task/npc/xiaoxiao",]), 
     (["name":                "山贼", 
      "where" :              "/task/npc/shanzei",]),
      }), 
     ({
     (["name":                "山贼", 
    "where" :                 "/task/npc/shanzei",]),
/*   (["name":                "盖一鸣",
     "where" :                "/task/npc/gaiyiming",]),
     (["name":                "常长风",
     "where" :                "/task/npc/chang",]),
      (["name":                "花剑影",
     "where" :                "/task/npc/hua",]),*/
      (["name":                "黄须道人",
     "where" :                "/task/npc/huangxu",]),
     (["name":                "恶僧",
     "where" :                "/task/npc/eseng",]),
      (["name":                "曹化淳",
     "where" :                "/task/npc/cao",]),
      (["name":                "朱安国",
     "where" :                "/task/npc/zhu",]),
      }), 
      ({
     (["name":                "江洋大盗 王三",
     "where" :                "/task/npc/dadao",]),
       (["name":                "草寇",
     "where" :                "/task/npc/caokou",]),
      (["name":                "恶霸",
     "where" :                "/task/npc/eba",]),
      (["name":                "宋扬",
     "where" :                 "/task/npc/songyang",]),
      (["name":               "全二风",
     "where" :                 "/task/npc/quan",]),
      (["name":               "孟正鹏",
     "where" :                 "/task/npc/meng",]),
      (["name":               "鲜于通",
     "where" :                 "/task/npc/xian",]),
      (["name":               "麦鲸",
     "where" :                 "/task/npc/maijing",]),
      (["name":               "过三拳",
     "where" :                 "/task/npc/guo",]),
       }), 
      ({
      (["name":               "赵一伤",
     "where" :                 "/task/npc/zhaoyishang",]),   
      (["name":               "钱二败",
     "where" :                 "/task/npc/qian",]),    
      (["name":               "孙三毁",
     "where" :                 "/task/npc/sun",]),  
      (["name":               "李四摧",
     "where" :                 "task/npc/li",]), 
      (["name":               "周五输",
     "where" :                 "/task/npc/zhou",]), 
      (["name":               "吴六破",
     "where" :                 "/task/npc/wu",]), 
      (["name":               "郑七灭",
     "where" :                 "/task/npc/zheng",]), 
      (["name":               "元广波",
     "where" :                 "/task/npc/yuan",]), 
      (["name":               "徐长老",
     "where" :                 "/task/npc/xu",]), 
/*    (["name":               "单正",
     "where" :                 "/task/npc/shan",]), */
      (["name":               "霍元风",
     "where" :                 "/task/npc/huo",]),
      }), 
      ({
      (["name":               "阿大",
     "where" :                 "/task/npc/ada",]),  
      (["name":               "阿二",
     "where" :                 "/task/npc/aer",]), 
      (["name":               "阿三",
     "where" :                 "/task/npc/asan",]),
     (["name":               "高三娘子",
     "where" :                 "/task/npc/gao3",]),
     (["name":               "风良",
     "where" :                 "/task/npc/feng2",]),
     (["name":               "吕正平",
     "where" :                 "/task/npc/luzhenping",]),
     (["name":               "范一飞",
     "where" :                 "/task/npc/fanyifei",]),
     (["name":               "成大洋",
     "where" :                 "/task/npc/chengdayang",]),
     (["name":               "容彩本",
     "where" :                 "/task/npc/rongcaiben",]),
     (["name":               "洪胜海",
     "where" :                 "/task/npc/hongshenhai",]),     
     (["name":               "郑起云",
     "where" :                 "/task/npc/zhengqiyun",]),
     (["name":               "尤得胜",     
     "where" :                 "/task/npc/youdesheng",]),
     (["name":               "黄伯流",     
     "where" :                 "/task/npc/huangboliu",]),
     (["name":               "程青竹",     
     "where" :                 "/task/npc/chengqingzu",]),            
     (["name":               "萧远山",
     "where" :                 "/task/npc/xiaoyuanshan",]),     
      (["name":               "玉真子",
     "where" :                 "/task/npc/yu",]),    
     }),
     });
mapping *wheres=({
          
      (["chinese":                "扬州",
       "weizhi" :              "/d/city/xjs",]),  
      (["chinese":                "峨嵋",
       "weizhi" :              "/d/emei/xiaowu",]),
       (["chinese":                "武当山",
       "weizhi" :              "/d/wudang/xiaolu2",]),
      (["chinese":                "泰山",   
       "weizhi" :              "/d/taishan/yitian",]),       
      (["chinese":                "襄阳",
       "weizhi" :              "/d/xiangyang/zhuquemen",]),
      (["chinese":                "襄阳",
       "weizhi" :              "/d/xiangyang/hanshui1",]),
       (["chinese":                "雪山",
       "weizhi" :              "/d/xueshan/tianhu",]),
      (["chinese":                "扬州",
       "weizhi" :              "/d/city/miao",]),
      (["chinese":                "雪山",
       "weizhi" :              "/d/xueshan/houzidong",]),
      (["chinese":                "苏州",
       "weizhi" :              "/d/suzhou/lingyansi",]),
      (["chinese":                "苏州",
       "weizhi" :              "/d/suzhou/liuyuan",]),
      (["chinese":                "杭州",
       "weizhi" :              "/d/hz/longjing",]),
      (["chinese":                "杭州",
       "weizhi" :              "/d/hz/huanglongdong",]),
      (["chinese":                "杭州",
       "weizhi" :              "/d/hz/yuhuangshan",]),
      (["chinese":                "杭州",
       "weizhi" :              "/d/hz/tianxianglou",]),
      (["chinese":                "苗疆",
       "weizhi" :              "/d/miaojiang/jiedao4",]),  
      (["chinese":                "佛山镇",
       "weizhi" :              "/d/foshan/duchang",]),
      (["chinese":                "黄河沿岸",
       "weizhi" :              "/d/huanghe/shulin5",]),  
      (["chinese":                "杭州",
       "weizhi" :              "/d/hz/changlang1",]), 
      (["chinese":                "杭州",
       "weizhi" :              "/d/hz/yuquan",]), 
      (["chinese":                "杭州",
       "weizhi" :              "/d/hz/longjing",]), 
      (["chinese":                "星宿海",
       "weizhi" :              "/d/xingxiu/shamo3",]), 
      (["chinese":                "武当",
       "weizhi" :              "/d/wudang/xuanyuemen",]), 
      (["chinese":                "峨嵋",
       "weizhi" :              "/d/emei/guanyinqiao",]), 
      (["chinese":                "峨嵋",
       "weizhi" :              "/d/emei/basipan3",]), 
      (["chinese":                "峨嵋",
       "weizhi" :              "/d/emei/caopeng",]), 
      (["chinese":                "明教",
       "weizhi" :              "/d/mingjiao/bishui",]), 
      (["chinese":                "明教",
       "weizhi" :              "/d/mingjiao/shanting",]), 
      (["chinese":                "福州",
       "weizhi" :              "/d/fuzhou/haigang",]), 
      (["chinese":                "福州",
       "weizhi" :              "/d/fuzhou/laozhai",]), 
      (["chinese":                "星宿海",
       "weizhi" :              "/d/xingxiu/shamo2",]),
       (["chinese":                "嘉兴",
       "weizhi" :              "/d/jiaxing/nanhu",]),
       (["chinese":                "华山村",
       "weizhi" :              "/d/village/shulin",]),
      (["chinese":                "少林寺",
       "weizhi" :              "/d/shaolin/songshu2",]),
       (["chinese":                "嵩山",
       "weizhi" :              "/d/songshan/dmeng",]),
      (["chinese":                "襄阳",
       "weizhi" :              "/d/xiangyang/tanxi",]),
      (["chinese":                "华山",
       "weizhi" :              "/d/huashan/husun",]),
      (["chinese":                "华山",
       "weizhi" :              "/d/huashan/yunu",]),
      (["chinese":                "慕容山庄",
       "weizhi" :              "/d/mr/xiaojing1-2",]),
      (["chinese":                "慕容山庄",
       "weizhi" :              "/d/mr/liulin",]),
      (["chinese":                "苏州城",
       "weizhi" :              "/d/suzhou/shihu",]),
      (["chinese":                "苏州城",
       "weizhi" :              "/d/suzhou/xuanmiaoguan",]),
      (["chinese":                "苏州城",
       "weizhi" :              "/d/suzhou/zijinan",]),
      (["chinese":                "恒山",
      "weizhi" :               "/d/hengshan/cuiping2",]), 
      (["chinese":                "恒山",
      "weizhi" :               "/d/hengshan/guolaoling",]), 
      (["chinese":                "少林寺",
       "weizhi" :              "/d/shaolin/talin1",]),
      (["chinese":                "武当",
       "weizhi" :              "/d/wudang/husunchou",]),
      (["chinese":                "少林寺",
       "weizhi" :              "/d/shaolin/shanlu8",]),
      (["chinese":                "雪山",
       "weizhi" :              "/d/xueshan/shanlu7",]),
      (["chinese":                "佛山镇",
       "weizhi" :              "/d/foshan/road10",]),
      (["chinese":                "佛山镇",
       "weizhi" :              "/d/foshan/xiaolu2",]),
      (["chinese":                "峨嵋",
       "weizhi" :              "/d/emei/jiulaodong",]),
      (["chinese":                "恒山",
      "weizhi" :               "/d/hengshan/beiyuemiao",]), 
      (["chinese":                "丐帮分舵",
       "weizhi" :              "/d/gb/xinglin2",]),
      (["chinese":                "丐帮分舵",
       "weizhi" :              "/d/gb/shangang",]),
      (["chinese":                "福州",
       "weizhi" :              "/d/fuzhou/zhongxin",]),
      (["chinese":                "黄河沿岸",
       "weizhi" :              "/d/huanghe/huanghe4",]),
      (["chinese":                "青城山",
       "weizhi" :              "/d/huanghe/shamo",]),    
      (["chinese":                "峨嵋",
       "weizhi" :              "/d/emei/gudelin3",]),
        
           });
void init()
{
        add_action("do_jie", ({"xian","jie"}));
     
}

int do_jie(string arg)
{
        object me, ob;
        mapping weizhis, target;
        int exp, position, i, j;

        if(!arg) return 0;
        me = this_player();
        ob = this_player(); 
        exp=(int)me->query("combat_exp"); 
        weizhis = wheres[random(sizeof(wheres))];

        if(arg != "wenshu" && arg != "wen") return 0;

        if(me->query_condition("gb_mission") || me->query_condition("gb_busy") || me->query_condition("xx_task")
        || me->query_condition("dali_songxin"))
                return notify_fail("你现在正忙着做其他任务呢！\n");
        if(me->query_condition("gf_busy"))
                return notify_fail("你刚刚做了官府任务，留给其他人吧！\n");                
        if(me->query_condition("guanfu_task"))
                return notify_fail("你已经揭过榜了，难道不想做了？！\n");
        if(me->query_temp("guanfu_task") || present("wenshu", me))
        return notify_fail("你身上还有文书，可以通过(kan wenshu)来查询。\n");
        
        if(me->query_condition("gf_busy"))
        return notify_fail("你发现文书已经被人揭光了，看样子要等一会了！\n");

    if(exp<50000)
                return notify_fail("你刚想伸手，忽然看到上面凶神恶煞的画像，想了想觉得自己的这点功夫，还是算了吧。\n"); 
        if(exp>=775000) position=5;
        else if(exp>=380000) position=4;
        else if(exp>=120000) position=3;
        else if(exp>=50000) position=2;
        else position=1;
        j = i = sizeof(quest[position-1]);
        target = quest[position-1][random(i)]; 
        while (j-- && sizeof(filter_array(children(target["where"]), (: clonep :))) > 0)
                target = quest[position-1][random(i)];
        if (j < 0) return notify_fail("你发现文书已经被人揭光了，看样子要等一会了！\n");

        if(exp>=380000){
        message_vision(
                HIY
                "$N推开围观的行人，走到近前，微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR, me);
        }
        if(exp<=120000){
        message_vision(
                 HIY
                 "$N壮了壮胆，费力拔开行人，来到近前深深吸了口气，竭力镇定一下紧张的心情，四下看了看，悄悄把文书揭了下来。\n"NOR, me);
        }
        if(exp>120000 && exp<380000){
        message_vision(
                 HIY
                 "$N分开行人来到近前，目光淡淡的扫视了几眼告示，嘴角微微一翘，神态自如的把文书揭了下来。\n"NOR, me);
        }
        me->set_temp("mark/gkill1",1);
        me->set_temp("guanfu_target", target["name"]);
        me->set_temp("path_rooms", target["where"]);
        me->set_temp("gstart_rooms", weizhis["weizhi"]);
        me->set_temp("ch_weizhi", weizhis["chinese"]);
        new("/d/city/obj/wenshu")->move(me);
        ob = new(me->query_temp("path_rooms"));
        ob->move(me->query_temp("gstart_rooms"));
        me->apply_condition("guanfu_task", me->set_temp("guanfu_time", random(70)+20));
        me->apply_condition("gf_busy", random(20)+20);
        
        return 1;
}
