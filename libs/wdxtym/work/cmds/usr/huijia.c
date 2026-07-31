inherit F_CLEAN_UP;
mapping mlist =
([
"丐帮"     : "d/city/gbxiaowu",
"明教" : "d/mingjiao/dadian",
"全真教"   : "d/quanzhen/shiweishi",
"峨嵋派"   : "d/emei/hcahoudian",
"古墓派"   : "d/gumu/zhengting",
"华山派"   : "d/huashan/qunxianguan",
"灵鹫宫"   : "d/lingjiu/dating",
"少林派"   : "d/shaolin/fzlou2",
"神龙教"   : "d/shenlong/dating",
"桃花岛"   : "d/taohua/dating",
"武当派"   : "d/wudang/xiaoyuan.c",
"逍遥派"   : "d/xiaoyao/qingcaop",
"星宿派"   : "d/xingxiu/riyuedong",
"血刀门"   : "d/xuedao/shandong3",
"雪山寺"   : "d/xueshan/neidian",
"段氏皇族" : "d/dali/neitang",
"慕容世家" : "d/yanziwu/shangyu",
"欧阳世家" : "d/baituo/dating",
"关外胡家" : "d/guanwai/xiaowu",
"华山剑宗" : "d/huashan/xiaowu",
"日月神教" : "d/heimuya/up1",
"唐门" : "d/tangmen/qianliju",
]);

int main(object me) {

/**
    if (me->is_busy()) {
        return notify_fail("你正忙著呢。\n");
    }
    if (me->is_ghost()) {
        return notify_fail("等你还了阳再说吧。\n");
    }

    if (me->is_in_prison()) {
        return notify_fail("你正在做牢呢。\n");
    }
    if (!me->query("born")) {
        return notify_fail("你还没有出生呢！\n");
    }
    if (me->query("doing")) {
        return notify_fail("你还想干什么？！\n");
    }


        if (me->is_ghost()){
            return notify_fail("等你还了阳再说吧。\n");
        }

            if (me->query("doing")){
            return notify_fail("你还想干什么？！\n");
        } */

    string my_fam = me->query("family/family_name");

    me->move(mlist[my_fam]);
    return 1;

};
  