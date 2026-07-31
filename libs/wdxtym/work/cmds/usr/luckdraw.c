//2020.11.7 修改者；笑傲
//qq 1487256970
#include <ansi.h>

int start_ken(object me);
int main(object me, string arg)
{ 
string str;
int cishua,baodicichu;
baodicichu = me->query("jiangchibaodi",1);
cishua =100-baodicichu;

    if (! arg){
		str = ZJOBLONG"幸运抽奖";
        str += ZJBR"【贵重物资16.67%，普通物资52.67%】";
		str += ZJBR"【技能物资09.33%，宝石物资21.33%】";
        str += ZJBR"100灵石抽一次, 888灵石十连抽。";
		str += ZJBR"你还差。"+cishua+"次触发保底";
        str += ZJBR"修为修为足够技能提升到180级再进行抽奖！";
        str += ZJBR"否则抽到公共技能下线等级会掉！！";
        str += ZJBR"概不负责！！";
        str += "\n"ZJOBACTS2+ZJMENUF(4,4,8,30); 
        if (present("ten card",me))
        str += "十连抽:luckdraw ten"ZJSEP;
        if (present("one card",me))
        str += "单抽卡:luckdraw one"ZJSEP;
        str += "欧皇单抽:luckdraw yuanbao"ZJSEP;
        str += "幸运十连:luckdraw yuanbao_sl";
        write(str+"\n");
        return 1;
    }
    if(arg == "yuanbao"){
        if(me->query("yuanbao")<100)
            return notify_fail("请确保你有足够的灵石。\n");       
            me->add("yuanbao",-100);
            start_ken(me);
    }
    
    if (arg == "yuanbao_sl")
    {
        int i;
        
        if (me->query("yuanbao") < 888)
            return notify_fail("请确保你有足够的灵石。\n");
        
        me->add("yuanbao", -888);
        for(i = 0; i < 10; i++)
        {
            start_ken(me);
        }
        return 1;
    }
    
    if(arg == "one")
    {
    	object ob;
    	if (!objectp(ob = present("one card",me)))
    		return notify_fail("你又没有单抽卡，喵。\n");
    	ob->add_amount(-1);
    	start_ken(me);
    	return 1;
    }
    
    if (arg == "ten")
    { 
    object ob;
    int i=0;
       if (!objectp(ob = present("ten card",me)))
       return notify_fail("你又没有十连抽卡，喵。\n");    
       ob->add_amount(-1);
       while (i<10)
       {
       start_ken(me);
       i++;
       }
       return 1;
    }
    return 1;

}
int start_ken(object me)
{
//贵重物品 灵石几率
    string *ob_list = ({
		"/clone/gift/xuanling",
		"/clone/gift/wujueling",
		"/clone/tianji1/huanyutianjing",		
		"/clone/tianji1/huanyutianjings",
		"/clone/tianji1/huanyutianjings1",
		"/clone/tianji1/huanyutianjings2",
		"/clone/tianji1/huanyutianjings3",
		"/clone/tianji1/huanyutianjings4",
		"/clone/tianji1/huanyutianjings5",
		"/clone/tianji1/huanyutianjings6",
		"/clone/tianji1/bookbadao",
		"/clone/tianji1/bookhongyanlinglongwu",
		"/clone/tianji1/bookliangyiyinyangjue",
		"/clone/tianji1/booklunhui",
		"/clone/tianji1/bookshiertian",
		"/clone/tianji1/booktianrenheyi",
		"/clone/tianji1/bookwanmofuti",
		"/clone/tianji1/zhanling",
		"/clone/tianji1/taotiejiubingfu",
		"/clone/tianji1/wujuetieling",
		"/clone/tianji1/yuanbaok",
		"/clone/tianji1/GMSSS5",
		"/clone/tianji1/GMSSS6",
		"/clone/tianji1/GMSSS7",
		"/clone/tianji1/GMSSS8",
		"/clone/tianji1/GMSSS9",
    });
    
    //葡萄类的
    string *pt_list = ({
        "/u/cx/luck/putao",
        "/u/cx/luck/daputao",
        "/u/cx/luck/daputao",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
        "/clone/gift/hundunshi",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
		 "/u/cx/luck/daputao",
        "/u/cx/luck/daputao",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
        "/clone/gift/hundunshi",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
        "/u/cx/luck/putao",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
		 "/u/cx/luck/putao",
        "/u/cx/luck/putao",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
        "/clone/gift/hundunshi",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
		 "/u/cx/luck/daputao",
        "/u/cx/luck/daputao",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
        "/clone/gift/hundunshi",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
        "/u/cx/luck/daputao",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
        "/clone/gift/hundunshi",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
		 "/u/cx/luck/daputao",
        "/u/cx/luck/daputao",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
        "/clone/gift/hundunshi",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
        "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
		 "/u/cx/luck/putao",
        "/u/cx/luck/lingzhi1",
         "/clone/gift/dan_chongmai1",
        "/clone/gift/dan_chongmai2",
    });
    
    //技能类的
    string *skill_list = ({
        "zhuihun-jian",
        "yunlong-bian",
        "hanxing-bada",
        "bizhen-qingzhang",
        "huanyin-zhi",
        "ningxue-shenzhao",
        "sanfen-jianshu",
        "zijinbagua-dao",
        "huanyin-zhi",
        "ningxue-shenzhao",
        "sanfen-jianshu",
        "zijinbagua-dao",		
		"jiuyang-shengong",
        "shenzhaojing",
        "qishang-quan",
        "baihua-quan",
        "hanbing-mianzhang",
        "xuanming-zhang",
        "sougu",
        "zhuihun-jian",
        "yunlong-bian",
        "hanxing-bada",
        "bizhen-qingzhang",
        "huanyin-zhi",
        "ningxue-shenzhao",
        "sanfen-jianshu",
        "zijinbagua-dao",
        "zhuihun-jian",
        "yunlong-bian",
        "hanxing-bada",
        "bizhen-qingzhang",
        "huanyin-zhi",
        "ningxue-shenzhao",
        "sanfen-jianshu",
        "zijinbagua-dao",		
        "wuyin-jianjing",
        "zhuihun-jian",
        "yunlong-bian",
        "hanxing-bada",
        "bizhen-qingzhang",
        "huanyin-zhi",
        "ningxue-shenzhao",
        "sanfen-jianshu",
        "zijinbagua-dao",
    });

    //宝石类的
    string *gem_list = ({
        "/clone/gem/hujiagem",
        "/clone/gem/lonelygem",
        "/clone/gem/xuedaogem",
         "/clone/gem/xueshangem",
         "/clone/gem/manmiao-gem",
         "/clone/gem/hmgonggem",
         "/clone/gem/liumai-qi",
         "/clone/gem/liumai-six",
         "/clone/gem/xianglong-xiang",
         "/clone/gem/qitun-gem",
         "/clone/gem/shedao-chang1",
        "/clone/gem/hujiagem",
        "/clone/gem/lonelygem",
        "/clone/gem/xuedaogem",
         "/clone/gem/xueshangem",
         "/clone/gem/manmiao-gem",
         "/clone/gem/hmgonggem",
         "/clone/gem/liumai-qi",
         "/clone/gem/liumai-six",
         "/clone/gem/xianglong-xiang",
         "/clone/gem/qitun-gem",
         "/clone/gem/shedao-chang1",
        "/clone/gem/hujiagem",
        "/clone/gem/lonelygem",
        "/clone/gem/xuedaogem",
         "/clone/gem/xueshangem",
         "/clone/gem/manmiao-gem",
         "/clone/gem/hmgonggem",
         "/clone/gem/liumai-qi",
         "/clone/gem/liumai-six",
         "/clone/gem/xianglong-xiang",
         "/clone/gem/qitun-gem",
         "/clone/gem/shedao-chang1",
    });
    
     mapping skills;
    string str,*sk,skill;
    int random,i;
    object obj;
    
 random = random(100)+1;
 //保底检测
			if(me->query("jiangchibaodi",1)==100){
		   me->set("jiangchibaodi",0);
		   obj = new(gem_list[random(sizeof(gem_list))]);
		   CHANNEL_D->do_channel(this_object(),"rumor","触发保底!\n");
		//   me->add("youbao",1400);
           }else if(random<=2){
            obj = new(gem_list[random(sizeof(gem_list))]);
			//抽到大奖保底清零
			me->set("jiangchibaodi",0);
			   CHANNEL_D->do_channel(this_object(),"rumor","保底机制清零!\n");
        }else if(random<=5){
            skill = skill_list[random(sizeof(skill_list))];
            //判断会的技能中有没有此技能，有则退款
            skills = me->query_skills();
		    sk = keys(skills);
            for(i=0; i<sizeof(skills); i++) {
                if(skill == sk[i]){
                	log_file("luckdraw", ctime(time()) + "   " + me->name() + me->query("id") + "  抽到已拥有武功" + skill + "\n");
					
					CHANNEL_D->do_channel(this_object(),"rumor",me->query("name")+"抽到了一个他已经有的技能【"+ skill +"】!\n");
					CHANNEL_D->do_channel(this_object(),"rumor","已退还灵石88!\n");
                    write("你抽到了一个你已经学会的技能，这次就不算啦！\n");
					 me->add("youbao",88);
					 //me->add("jiangchibaodi",1); 为增加保底条件
					  me->add("jiangchibaodi",1);
                    return 1;
                }
            }

            me->set_skill(skill,200);
       //     me->add("yuanbao",-150);
            log_file("luckdraw", ctime(time()) + "   " + me->name() + me->query("id") +  "  抽到" + skill + "\n");
            write("恭喜抽到【"+ skill +"】!\n");
			  me->add("jiangchibaodi",1);
            CHANNEL_D->do_channel(this_object(),"rumor",me->query("name")+"抽到了一个技能【"+ skill +"】!\n");
            return 1;
        }else if(random<=101){
            obj = new(pt_list[random(sizeof(pt_list))]);
        }else{
            obj = new(ob_list[random(sizeof(ob_list))]);
        }
       log_file("luckdraw", ctime(time()) + "   " + me->name() + me->query("id") + "  抽到" + obj->name() + "\n");
        obj->move(me);
          me->add("jiangchibaodi",1);
        write("恭喜抽到【"+ obj->query("name") +"】!\n");
  //      me->add("yuanbao",-150);
       // CHANNEL_D->do_channel(this_object(),"rumor",me->query("name")+"抽到了一个物品【"+ obj->query("name") +"】!\n");
        return 1;
}