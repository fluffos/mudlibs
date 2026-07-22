string *fengyi5_yanlian = ({
HIC"你使一招「白云出岫」，做一起首试，顿时豪情一片，手指蓄试点向前方！"NOR,
HIG"你使一招「天绅倒悬」，满场游走，手指自上而下划出一个大弧，向前方劈砍下去！"NOR,
HIW"你向前跨上一步，手指看似来势既缓，又无力道，但是却突然指尖一转，使出「白虹贯日」直刺前方!"NOR,
HIR"你手指一沉，一式「润物细无声」，无声无息地滑向前方!"NOR,
HIY"你一式「志当存高远」，纵身飘开数尺，运发剑气，手指遥摇指向前方。"NOR,
HIM"你错步上前，使出「来去若梦行」，剑意若有若无，手指淡淡地挥向前方。"NOR,
WHT"你合掌跌坐，一式「我心化云龙」，剑指自怀中跃出，如疾电般射向前方。"NOR,
HIB"你剑指微颤作龙吟，一招「高处不胜寒」，切骨剑气如飓风般裹向前方。"NOR,
YEL"你剑指如云雾变化，正是一招「天柱云气」，极尽诡奇之能事，动向无定，不可捉摸。"NOR,
RED"你突然间身子往斜里窜出，使出「雁回祝融」，凭借内力，竟逼出无数剑气，霎时之间填满前方空间。"NOR,
CYN"你以手代剑，不住晃动，「石廪书声」使将出来，剑招奇变横生，竟无发判断出了多少招。"NOR,
MAG"你剑招攻势极强，却全不理会对方攻势来路，使出一招「鹤翔紫盖」，变化莫测地攻向前方，剑势竟无丝毫迹象可寻。"NOR,
});

int fengyi5_zhuomo(object);

int fengyi5_zhuomo(object me)
{
    if((int)me->query("quest/hsjf/fengyi5_fail")>=5)
    {
         write("你觉得这辈子都无法琢磨透这个剑招了。\n");
         return 1;
     }

    if((int)me->query("quest/hsjf/fy5/yanlian_time")+43200>time())
    {
         write("你刚琢磨过，觉得目前还无法有所进展。\n");
         return 1;
     }

    if((int)me->query("quest/hsjf/fy5/yanlian_exp")+50000>(int)me->query("combat_exp"))
    {
         write("你积累的实战经验尚还够!\n");
         return 1;
     }

    if(me->query("quest/hsjf/fy5/yanlian")=="pass")
    {
         write("你觉得依照自己的水平，实在无法琢磨这高深的剑招！\n");
         return 1;
     }

    write(HIG"你闭上眼睛，静静琢磨着华山剑法。每一招，每一式都历历呈现在眼前。。。\n\n"+
          HIY"你思到深处，不禁以手为剑，比划了起来。此时你已根本不在乎使哪招哪式，\n"+
          HIY"都是信手使出。\n"NOR);

    me->start_busy(999);//防止player乱走动. by lsxk@hsbbs
    call_out("fengyi5_yanlian",3,me);
    return 1;
}

int fengyi5_yanlian(object me)
{
    int i;
    string killer_location;
    if(file_name(environment(me))!="/d/huashan/cave"
      &&file_name(environment(me))!="/u/lsxk/partyskill/newhs/quest/cave")
         return 1;

    if((int)me->query_temp("quest/huashan/fengyi5/yanlian")>7){
        if(!random(4)||me->query("quest/hsjf/fy5/yanlian")=="again"){
          write(HIC"\n你心中竟无半点残渣，这数招使地一气呵成，招招衔接地天衣无缝，完美无\n"+
                     "缺，可是你却依旧觉得无法融合进“有凤来仪”之中，任何一招都嫌有拖滞\n"+
                     "累赘之感。你只觉得，若无高人指点，恐怕难以发挥这“有凤来仪”后招的\n"+
                     "真正威力。\n"NOR);
            me->delete_temp("fengyi5_zhuomo");
            me->delete_temp("quest/huashan/fengyi5/yanlian");
            me->set("quest/hsjf/fy5/meet_killers",1);
            me->set("quest/hsjf/fy5/yanlian","pass");
            me->set("quest/hsjf/fy5/yanlian_time",time());
            me->set("quest/hsjf/fy5/yanlian_exp",me->query("combat_exp"));

            i = random(4);
            switch(i)
            {
                 case 0 : killer_location="qlmnj";break;
                 case 1 : killer_location="zqmnj";break;
                 case 2 : killer_location="xwmnj";break;
                 default : killer_location="bhmnj";break;
             }
            me->start_busy(1);
            me->set("quest/hsjf/fy5/location",killer_location);
            log_file("quest/fengyi5", sprintf(HIG"有凤来仪5Quest记录：%s(%s)在华山秘洞"HIW"琢磨"HIG"成功。经验%d。"NOR, me->name(1),me->query("id"), me->query("combat_exp")) );
            return 1;
        }
        else{
            write(HIR"你觉得似乎有点心得，可能还需要一些实战来积累经验吧。\n"NOR);
            me->delete_temp("fengyi5_zhuomo");
            me->delete_temp("quest/huashan/fengyi5/yanlian");
            me->set("quest/hsjf/fy5/yanlian","failed");
            me->set("quest/hsjf/fy5/yanlian_time",time());
            me->set("quest/hsjf/fy5/yanlian_exp",me->query("combat_exp"));
            me->start_busy(1);
            log_file("quest/fengyi5", sprintf(HIR"有凤来仪5Quest记录：%s(%s)在华山秘洞"HIW"琢磨"HIR"失败。经验%d。"NOR, me->name(1),me->query("id"), me->query("combat_exp")) );
            return 1;
        }
    }
    else{
        write("\n"+fengyi5_yanlian[random(sizeof(fengyi5_yanlian))]+"\n");
        me->add_temp("quest/huashan/fengyi5/yanlian",1);
        call_out("fengyi5_yanlian",5,me);
        return 1;
    }

    return 1;
}
