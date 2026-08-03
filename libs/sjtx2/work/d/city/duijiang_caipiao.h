//对奖专用。 by lsxk@hsbbs 2007/9/26

int do_duijiang()
{
    int i, k, j;
    string strDuijiang, strReport, strReportLog, *strTemp, *strTemp2, *strReportTemp;
    object me = this_player();

    if(!present("cai piao",me)){
        me->delete("caipiao");
        me->delete("caipiao_id");
        return notify_fail("你的摸彩凭证呢？\n"NOR);
    }

    if(!query("no_buy")) return notify_fail("还没开奖呢，凑啥热闹？该干啥干啥去。。\n"NOR);

    if(!(i=sizeof(me->query("caipiao")))) return notify_fail("你还没买彩票，来兑什么奖？一边凉快去！\n"NOR);

    if(me->query("caipiao_id")!=This_Source){
        me->delete("caipiao");
        me->delete("caipiao_id");
        tell_object(me,"小样！拿过期的彩票来对奖？当Wiz都傻的啊？\n"NOR);
        destruct(present("cai piao",me));
        return 1;
    }

    strDuijiang = me->query("caipiao/第"+chinese_number(i)+"张/my_caipiao");

    for(k=0;k<SIZE_OF_SOURCE/2;k++){
        if(!strTemp) strTemp = ({duijiang_char[k]+duijiang_char[k+1]});
        else strTemp  += ({duijiang_char[k*2]+duijiang_char[k*2+1]});
    }

    strTemp2 = explode(strDuijiang, "-");
    for(k=0;k<SIZE_OF_SOURCE/2;k++){
        for(j=0;j<SIZE_OF_SOURCE/2;j++){
            if(strTemp[k]==strTemp2[j]){
               me->set("caipiao_zhongjiang_list/"+strTemp[k], 1);
               me->add("caipiao_shot",me->query("caipiao_shot")+sizeof(me->query("caipiao_zhongjiang_list")));
               if(k==j) me->add("caipiao_shot",sizeof(me->query("caipiao_zhongjiang_list")));
               j = SIZE_OF_SOURCE/2;
            }
        }
    }

    strReport = HIM"您这次中奖的序号排列为:\n"HIG;
    strReportLog = " ";
    if(me->query("caipiao_zhongjiang_list")){
        strReportTemp = keys(me->query("caipiao_zhongjiang_list"));
        for(k=0;k<sizeof(me->query("caipiao_zhongjiang_list"));k++){
            strReport += strReportTemp[k] + " ";
            strReportLog += strReportTemp[k]+" ";
        }
        tell_object(me, strReport + "\n"NOR);

        log_file("caipiao", sprintf(HIG"%s(%s)第%d张彩票：%s 中奖，系统中奖号：%s 中奖排列:%s"NOR,me->name(),me->query("id"),i,me->query("caipiao/第"+chinese_number(i)+"张/my_caipiao"),strPriKaijiang, strReportLog));
        if(me->query("caipiao/第"+chinese_number(i)+"张/huobi")=="黄金"){
            tell_object(me,HIY"恭喜!此次中奖,使你获得了"+HIW+chinese_number((int)me->query("caipiao_shot")*GOLD_COST/10000)+HIY+"锭黄金!\n"NOR);
            me->add("balance",(int)me->query("caipiao_shot")*GOLD_COST);
        }
    }
    else tell_object(me, HIR"很遗憾,这张彩票,您没有中任何奖,感谢您的参与,祝您下次中奖!\n"NOR);

    me->delete("caipiao/第"+chinese_number(i)+"张");
    me->delete("caipiao_zhongjiang_list");
    me->delete("caipiao_shot");

    if(!sizeof(me->query("caipiao"))){
        me->delete("caipiao");
        me->delete("caipiao_id");
        destruct(present("cai piao", me));
    }

    return 1;
}
