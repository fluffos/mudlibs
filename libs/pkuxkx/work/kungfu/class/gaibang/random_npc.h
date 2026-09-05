//random_npc By Zine 2011.5 for 丐帮新手任务

int getnpc(object me)
{
    object ob=this_object();
    int n=random(140);
    int m=random(9);
    object thetarget;
    string tar;
    string * target=({"/d/city/npc/jiang","/d/city/npc/xiaoer","/d/city/npc/baobei",
        "/d/beijing/npc/liu","/d/beijing/npc/mei","/d/beijing/npc/wuliuqi",
        "/d/chengdu/npcs/tang","/d/chengdu/npcs/waiter","/d/chengdu/npcs/zhanggui",});
    string * target2=({
        "/d/dalunsi/npc/hu","/d/dalunsi/npc/prince","/d/dalunsi/npc/wenwoer",
        "/d/emei/npc/jingdao","/d/emei/npc/jingfeng","/d/emei/npc/jinghe",
        "/d/fuzhou/npc/linzhennan","/d/fuzhou/npc/linpingzhi","/d/fuzhou/npc/waiter",});
    string * target3=({
        "/d/hangzhou/npc/nie","/d/hangzhou/npc/pei","/d/hangzhou/npc/huoji",
        "/d/jiangzhou/npc/han-yuanwai","/d/jiangzhou/npc/biaojunpc","/d/jiangzhou/npc/diaoyuren",
        "/d/jinyang/npc/dzlc","/d/jinyang/npc/yaopulaoban","/d/jinyang/npc/shusheng",});
    string * target4=({
        "/d/luoyang/npc/dian","/d/luoyang/npc/xiaofeng","/d/luoyang/npc/shenni",
        "/d/murong/npc/cui","/d/murong/npc/yan","/d/murong/npc/ding",
        "/d/nanchang/npc/bai","/d/nanchang/npc/huoji","/d/nanchang/npc/chefu",});
    string * target5=({
        "/d/suzhou/npc/sun","/d/suzhou/npc/feng","/d/suzhou/npc/huoji",
        "/d/taohuadao/npc/gu","/d/taohuadao/npc/yapu","/d/taohuadao/npc/laozhe",
        "/d/xiangyang/npc/mafu","/d/xiangyang/npc/shinv","/d/xiangyang/npc/yang",
        });
    string * target6=({
        "/d/zhenjiang/npc/biaojunpc","/d/zhenjiang/npc/fashi","/d/zhenjiang/npc/kanshou",
        "/d/dalicheng/npc/baiyi","/d/dalicheng/npc/fan-ye","/d/dalicheng/npc/gongzi",
        "/d/guiyunzhuang/npc/wangtie","/d/guiyunzhuang/npc/wangde","/d/guiyunzhuang/npc/yinzhe",});
    string * target7=({"/d/lingzhou/npc/taiyi","/d/lingzhou/npc/ye","/d/lingzhou/npc/yun",
        "/d/quanzhou/npc/hai","/d/quanzhou/npc/zhucong","/d/quanzhou/npc/zhangasheng",
        "/d/yueyang/npc/li","/d/yueyang/npc/zhanggui","/d/yueyang/npc/zhanggui"});
    if (n>119)
    {
        tar=target7[m]+".lpc";
    }
    else if (n>99)
    {
        tar=target6[m]+".lpc";
    }
    else if (n>79)
    {
        tar=target[m]+".lpc"; 
    }
    else if (n>59)
    {
        tar=target2[m]+".lpc"; 
    }
    else if (n>39)
    {
        tar=target3[m]+".lpc"; 
    }
    else if (n>19)
    {
        tar=target4[m]+".lpc"; 
    }
    else 
    {
        tar=target5[m]+".lpc";
    }
    thetarget=find_object(tar);
    thetarget=find_living(thetarget->query("id"));
    if (wizardp(me))
    {
        tell_object(me,tar+"\n");
        tell_object(me,thetarget->query("name")+"\n");
    }
    while (!thetarget)
    {
        getnpc(me);
    }
    remove_call_out("after_random_npc");
    call_out("after_random_npc",1,me,thetarget);
    return 1;
    
    

}