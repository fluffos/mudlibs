// jitan.c
// 3/3/2001  by emnil@sj

#include <ansi.h>

inherit ROOM;

void selectpfm(object);
string dopfm(object,int);
void pfmmsg(object);

void create()
{
        set("short", RED"祭坛"NOR);
        set("long", 
HIW"这间静室内光线十分昏暗，只有中央的祭坛中发出幽幽的红光，而
四周沉浸在一片黑暗之中。这间房间的空间似乎极大，你竟然不能看到
四周的边际，更看不到天花板。你似乎已经进入了另外一个时空。\n"NOR);

        set("exits", ([
                "out" : "/d/sld/pt",
        ]) );

        setup();
}

/*
void init()
{
        add_action("do_canwu", ({"canwu"}));
        add_action("do_pfmmsg", ({"pfmmsg"}));
        add_action("do_wangque", ({"wangque"}));
        add_action("do_jidian", ({"jidian"}));
        add_action("selectpfm1", ({"pfmtype"}));
        add_action("selectpfm2", ({"pfmname"}));
}
*/

int do_canwu(string arg)
{
        object me;
        int i;

        me = this_player();
        if ( me->is_busy() )
                return notify_fail("你正忙着呢。\n");
        if ( me->query_skill("dulong-dafa",1)<256 )
                return notify_fail("你的修为太差了，不能参悟更高深的武学。\n");
        if ( me->query("jing")<1000 )
                return notify_fail("你的精神状态太差了，不能参悟更高深的武学。\n");
        if ( me->query("max_neili")<3000 )
                return notify_fail("你的内力修为太差了，不能参悟更高深的武学。\n");
        if ( me->query("neili")<2000 )
                return notify_fail("你的内力修为太差了，不能参悟更高深的武学。\n");
        if ( (int)me->query("sld_pfm/lvl")>=5 )
                return notify_fail("你的修为已经达到最高境界，再也参悟不出什么了。\n");
        i = time();
        if ( (i-(int)me->query("sld_pfm/ctime"))>3600 ) {
                me->set("sld_pfm/ctime",i);
                me->set("sld_pfm/ctimes",0);
        }
        else {
                if ( (int)me->query("sld_pfm/ctimes")>60 )
                        return notify_fail("你一开始参悟，就感到剧烈的头痛，可能是最近消耗脑力过度了。\n");
                else
                        me->add("sld_pfm/ctimes",1);
        }

        message_vision(HIW"$N盘膝而坐，缓慢的闭上双眼，似乎已经进入内宇宙的无限时空。\n"NOR,me);

        me->add("jing", -200-random(800));
        me->add("neili", -200-random(800));
        me->start_busy(100);
        call_out("canwu_over",15+random(30),me);

        return 1;
}

void canwu_over(object me)
{
        int i;

        me->add("potential",random(me->query_kar()));
        if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
                me->set("potential" , me->query("max_pot", 1) );
        me->start_busy(1);

        switch ((int)me->query("sld_pfm/lvl")) {
                case 0: i=1; break;
		case 1: i=2; break;
                case 2: i=4; break;
                case 3: i=8; break;
                case 4: i=16; break;
        }
        if ( (int)me->query("sld_pfm/ccount") > (i*120*(40-me->query_kar())/20) ) {

                me->set("sld_pfm/ccount",0);
                switch ((int)me->query("sld_pfm/lvl")) {
                        case 0: 
                                message_vision(GRN"$N缓缓的睁开眼睛，头脑中豁然开朗，似乎参悟到了什么！\n"NOR,me);
                                selectpfm(me);
                                break;
                        case 1: 
                                message_vision(YEL"$N缓缓的睁开眼睛，头脑中豁然开朗，修为又精进了一层！\n"NOR,me);
                                me->set("sld_pfm/lvl",2);
                                me->add("sld_pfm/rate",10);
                                me->add("sld_pfm/neili_require",30);
                                me->add("sld_pfm/jingli_require",15);
                                me->add("sld_pfm/neilicost",30);
                                me->add("sld_pfm/jinglicost",15);
                                pfmmsg(me);
                                break;
                        case 2: 
                                message_vision(BLU"$N缓缓的睁开眼睛，头脑中豁然开朗，修为又精进了一层！\n"NOR,me);
                                me->set("sld_pfm/lvl",3);
                                me->add("sld_pfm/rate",15);
                                me->add("sld_pfm/neili_require",30);
                                me->add("sld_pfm/jingli_require",15);
                                me->add("sld_pfm/neilicost",30);
                                me->add("sld_pfm/jinglicost",15);
                                pfmmsg(me);
                                break;
                        case 3: 
                                message_vision(MAG"$N缓缓的睁开眼睛，头脑中豁然开朗，修为又精进了一层！\n"NOR,me);
                                me->set("sld_pfm/lvl",4);
                                me->add("sld_pfm/rate",15);
                                me->add("sld_pfm/neili_require",30);
                                me->add("sld_pfm/jingli_require",15);
                                me->add("sld_pfm/neilicost",30);
                                me->add("sld_pfm/jinglicost",15);
                                pfmmsg(me);
                                break;
                        case 4: 
                                message_vision(RED"$N缓缓的睁开眼睛，头脑中豁然开朗，似乎就要进入最高境界，却又象少了点什么！

\n"NOR,me);
                                me->set("sld_pfm/clvl5",1);
                                break;
                }
        }
        else {
                message_vision(HIY"$N缓缓的睁开眼睛，似乎有所得，又似乎一无所获。\n"NOR,me);
                me->add("sld_pfm/ccount",1);
        }
}

void selectpfm(object me)
{
        tell_object(me,"
请选择欲参悟的绝招种类：
1.缠类          2.连击类        3.消弱敌人类    4.增强自身类
5.化学攻击类    6.消耗内力类    7.用毒类        8.断兵器类
9.消弱防御增强攻击类            10.特殊攻击类
请用 pfmtype x 命令回答（例如：pfmtype 1）。
");
        me->set_temp("sld/pfmtype",1);
}

int selectpfm1(string arg)
{
        int pfmtype;
        object me=this_player();

        if (!me->query_temp("sld/pfmtype")) 
                return 0;
        if ( (!arg) || (sscanf(arg,"%d",pfmtype)<1) || (pfmtype<1) || (pfmtype>10) )
                return notify_fail("请正确选择种类！\n");
        me->delete_temp("sld/pfmtype");

        tell_object(me,"请输入你所参悟的绝招的英文名(不能与你已有的绝招的英文名相同，字数在3~15之间)，
请用 pfmname xxx 命令回答（例如：pfmname yeah）。\n");

        me->set_temp("sld/pfmname",1);
        me->set_temp("sld/pfmt",pfmtype);
        return 1;
}

int selectpfm2(string arg)
{
        int i,pfmtype;
        object me=this_player();

        if (!me->query_temp("sld/pfmname")) 
                return 0;
        i = strlen(arg);
        if ( (i<3) || (i>15) )
                return notify_fail("请控制绝招英文名的长度！\n");
        me->delete_temp("sld/pfmname");
        pfmtype = (int)me->query_temp("sld/pfmt");
        me->delete_temp("sld/pfmt");

        switch (pfmtype) {
                case 1:
                        pfmtype = 1;
                        break;
                case 2:
                        if ( random(2)==1 ) pfmtype=2; else pfmtype=12;
                        break;
                case 3:
                        if ( random(2)==1 ) pfmtype=3; else pfmtype=4;
                        break;
                case 4:
                        if ( random(2)==1 ) pfmtype=5; else pfmtype=6;
                        break;
                case 5:
                        if ( random(2)==1 ) pfmtype=7; else pfmtype=8;
                        break;
                case 6:
                        pfmtype=9;
                        break;
                case 7:
                        if ( random(2)==1 ) pfmtype=10; else pfmtype=11;
                        break;
                case 8:
                        pfmtype=16;
                        break;
                case 9:
                        pfmtype=14;
                        break;
                case 10:
                        if ( random(2)==1 ) pfmtype=13; else pfmtype=15;
                        break;
        }

        me->set("sld_pfm/neili_require",200);
        me->set("sld_pfm/jingli_require",150);
        me->set("sld_pfm/neilicost",100);
        me->set("sld_pfm/jinglicost",50);
        me->set("sld_pfm/weapon",1);
        me->set("sld_pfm/failbusy",2);
        me->set("sld_pfm/succesbusy",3);
        me->set("sld_pfm/rate",85);
        me->set("sld_pfm/diypfm",arg);
        me->set("sld_pfm/pfmtype",pfmtype);
        me->set("sld_pfm/lvl",1);
        me->add("max_neili",-10);

        me->set("sld_pfm/cdiypfm","未命名");
        me->set("sld_pfm/msg","未命名");
        me->set("sld_pfm/failmsg","未命名");
        me->set("sld_pfm/succesmsg","未命名");
        me->set("sld_pfm/succesmsg2","未命名");
        me->set("sld_pfm/endmsg","未命名");

        tell_object(me, "你参悟了 "+arg+" : "+dopfm(me,pfmtype)+"。\n");
        pfmmsg(me);
        return 1;
}

string dopfm(object me,int pfmtype)
{
        switch (pfmtype) {
                case 1:
                        me->set("sld_pfm/failbusy",3);
                        me->set("sld_pfm/bexp",1);
                        return "缠";
                case 2:
                        me->set("sld_pfm/succes",1);
                        me->set("sld_pfm/succesbusy",4);
                        return "连续攻击";
                case 3:
                        me->set("sld_pfm/succes",1);
                        return "消弱对方防御";
                case 4:
                        me->set("sld_pfm/succes",1);
                        return "消弱对方攻击";
                case 5:
                        me->set("sld_pfm/succes",1);
                        return "增强自身防御";
                case 6:
                        me->set("sld_pfm/succes",1);
                        return "增强自身攻击";
                case 7:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/neili_require",350);
                        return "化学攻击，减对方的气";
                case 8:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/neili_require",350);
                        return "化学攻击，减对方的气内力精力";
                case 9:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/neili_require",120);
                        me->set("sld_pfm/rate",55);
                        return "对耗内力";
                case 10:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        return "用毒，减对方的精";
                case 11:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        return "用毒，减对方的气内力精力";
                case 12:
                        me->set("sld_pfm/succes",1);
                        me->set("sld_pfm/neili_require",300);
                        return "增强自身后连续攻击";
                case 13:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/rate",150);
                        return "增强自身后化学攻击";
                case 14:
                        me->set("sld_pfm/succes",1);
                        return "增强自身攻击，消弱自身防御";
                case 15:
                        me->set("sld_pfm/succes",1);
                        me->set("sld_pfm/neili_require",300);
                        return "超强三连击，但在发出攻击前的一段时间内所受的伤害加倍";
                case 16:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        return "断对方兵器";
        }
        return "错误的pfm类别";
}

void pfmmsg(object me)
{
        tell_object(me,"
你需要设置以下参数：
cpfm:           绝招的中文名
msg:            发出绝招时的描述
fmsg:           绝招失败时的描述
smsg:           绝招成功时描述
smsg2:          第二段成功描述
endmsg:         绝招结束时的描述

设置方法：pfmmsg 参数名 内容
例如：pfmmsg cpfm 天外飞仙

描述可以加颜色，方法和nick相同；
描述中可以用$N代表自己，$n代表敌人；
描述可以用\n代表换行。
");
}

int do_pfmmsg(string arg)
{
        string str1,str2;
        object me = this_player();

        if ((!stringp(arg)) || (sscanf(arg,"%s %s",str1,str2)<2))
                return notify_fail("命令格式：pfmmsg 参数名 内容\n");

        switch (str1) {
                case "cpfm":
                        me->set("sld_pfm/cdiypfm",str2);
                        break;
                case "msg":
                        me->set("sld_pfm/msg",str2);
                        break;
                case "fmsg":
                        me->set("sld_pfm/failmsg",str2);
                        break;
                case "smsg":
                        me->set("sld_pfm/succesmsg",str2);
                        break;
                case "smsg2":
                        me->set("sld_pfm/succesmsg2",str2);
                        break;
                case "endmsg":
                        me->set("sld_pfm/endmsg",str2);
                        break;
        }
        
        tell_object(me,"参数设置成功。\n");
        return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int do_wangque(string arg)
{
        object me = this_player();

        if ( (int)me->query("sld_pfm/lvl")<=0 )
                return notify_fail("你并没有参悟到什么，又如何忘却呢？\n");

        if ( !(int)me->query_temp("sld/wangque") ) {
                tell_object(me,"一旦选择忘却，你以前的辛苦劳动可都白费了，请考虑清楚。\n"+
                               "如果你确定要忘却所参悟到的绝学，请再输入一次这条命令。\n" );
                me->set_temp("sld/wangque",1);
        }
        else {
                me->delete_temp("sld/wangque");
                me->add("max_neili",-1);
                message_vision(HIR"$N缓缓闭上双眼，陷入冥思。不久，突然大叫一声，陡然睁开眼睛，\n双眼滴血，脸上透出无比痛苦的

神情。！！！\n"NOR,me);         

                me->delete("sld_pfm/diypfm");
                me->delete("sld_pfm/cdiypfm");
                me->delete("sld_pfm/neili_require");
                me->delete("sld_pfm/jingli_require");
                me->delete("sld_pfm/neilicost");
                me->delete("sld_pfm/jinglicost");
                me->delete("sld_pfm/weapon");
                me->delete("sld_pfm/msg");
                me->delete("sld_pfm/failmsg");
                me->delete("sld_pfm/succesmsg");
                me->delete("sld_pfm/succesmsg2");
                me->delete("sld_pfm/endmsg");
                me->delete("sld_pfm/failbusy");
                me->delete("sld_pfm/succesbusy");
                me->delete("sld_pfm/pfmtype");
                me->delete("sld_pfm/lvl");

                me->delete("sld_pfm/rate");
                me->delete("sld_pfm/succes");
                me->delete("sld_pfm/bjingli");
                me->delete("sld_pfm/bneili");
                me->delete("sld_pfm/bexp");
                me->delete("sld_pfm/bstr");
                me->delete("sld_pfm/bdex");
                me->delete("sld_pfm/bint");
                me->delete("sld_pfm/bkar");
                me->delete("sld_pfm/bskill1");
                me->delete("sld_pfm/bskill2");
                me->delete("sld_pfm/skill1");
                me->delete("sld_pfm/skill2");

                me->delete("sld_pfm/ctime");
                me->delete("sld_pfm/ctimes");
                me->delete("sld_pfm/ccount");
                me->delete("sld_pfm/clvl5");
        }

        return 1;
}

int do_jidian(string arg)
{
        object me,ob,env;

        me = this_player();
        if ( me->id(arg) )
                ob = me;
        else 
                ob = present(arg, me);

        if ( !ob )
                return notify_fail("你要用谁来祭奠自己的灵魂？\n");
        if ( !(int)me->query("sld_pfm/clvl5") )
                return notify_fail("你还没有达到需要祭奠的境界。\n");
        if ( !userp(ob) )
                return notify_fail("你必须用玩家来祭奠自己的灵魂！\n");
        if ( ob->query("combat_exp")<100000 )
                return notify_fail("你用来祭奠的人的精神力量太弱了，无法取得任何收获！\n");

        if ( ob==me )
                message_vision(RED"$N纵身跳入祭坛，祭坛本来昏暗的火焰陡然间放射出妖异的光芒，把$N吞没！\n"NOR,me);
        else
                message_vision(RED"$N把$n投入祭坛，祭坛本来昏暗的火焰陡然间放射出妖异的光芒，把$n吞没！\n"NOR,me,ob);
        tell_object(me,RED"你的脑中突然闪过一道灵光，把以前所参悟的一切融会贯通起来，你参悟了武学的最高境界！\n"NOR);

        me->set("sld_pfm/lvl",5);
        me->delete("sld_pfm/clvl5");
        me->add("sld_pfm/rate",18);
        me->add("sld_pfm/neili_require",39);
        me->add("sld_pfm/jingli_require",20);
        me->add("sld_pfm/neilicost",39);
        me->add("sld_pfm/jinglicost",20);
        pfmmsg(me);

        env = environment(me);
        ob->set_temp("last_damage_from", "被火焰烧");
        ob->die();

        ob=present("corpse", env);
        if (ob)
		destruct(ob);

        return 1;
}
