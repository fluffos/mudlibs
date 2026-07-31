// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);

void create()
{
        set_name("欠单", ({ "dan"}));
        set("long", "待定。\n");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 60);
        set("no_drop", 1);
        set("no_get", 1);
                set("unit", "张");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","shouzhang");
}
int do_shouzhang(string arg)
{
object ob=this_object(),me=this_player();
string targ;
        if (!arg||!ob=present(arg,environment(me)))
                return notify_fail("你要找谁讨债？\n");
        targ=ob->query("name");
        if ( targ != me->query_temp("subject") ) return notify_fail("这是向"+me->query_temp("subject")+"讨的债!你怎么能乱要??\n");
        if (me->query_temp("qljob")!=1)
                return notify_fail("你不能用这张账单去收帐。\n");
        if (userp(ob)) return notify_fail("你弄错人了吧？\n");
//        tell_object(me,"你把信交给了"+targ+"。\n" NOR );
        if (me->query_temp("qljob")!=1)
                return notify_fail("你不能用这张账单去收帐。\n");
        message_vision(HIW"\n$N从袖中掏出一张欠单，猛地一抖，大声喝道：“"+ob->query("name")+
                "，你欠我们白驼山庄的"+chinese_number(me->query_temp("money"))+
                "两银子也该还了吧？”\n"NOR,me);
        me->set_temp("qljob",2);
        me->apply_condition("jyfail",30);
        call_out("qljob_1", 3, me, ob);
        return 1;
}

int qljob_1(object me,object ob)
{
        object to_ob;

        to_ob = present("silver_money", me);

        if (environment(me)==environment(ob))
        {
                if (random(100) > 70)
                {
                        message_vision("\n" + HIW + ob->query("name")+"被吓得打了一个哆嗦，忙不迭声的道：“还！还！还！”\n"NOR,me);
                        message_vision("\n" + HIW + ob->query("name")+"急急忙忙从衣襟下掏出一个小钱袋，拿出了一些碎银子给了$N\n"NOR,me);
                        if( !to_ob ) {
                                to_ob = new("/clone/money/silver");
                                to_ob->move(this_player());
                                to_ob->set_amount(me->query_temp("money"));
                        } else
                                to_ob->add_amount(me->query_temp("money"));
                        message_vision("\n" + HIW + "$N点了点头道：“这样做好，你我都好办事。”，说完将欠账单撕掉了。\n\n"NOR, me);
                        me->set_temp("qljob",3);
                        me->apply_condition("jyfail",0);
                        destruct(this_object());
                        return 1;
                }
                else
                {
                        message_vision("\n" + HIW + ob->query("name")+"面露难色，小心翼翼陪着笑脸道：“我最近手里没钱，您看能不能宽限几天？”\n"NOR, me);
                        message_vision("\n" + HIW + "$N皱了皱眉头：“什么！没钱！？”\n"NOR, me);
                        write(HIR"\n是否杀掉"+ob->query("name")+"(杀(Y)，不杀(N))："NOR);
                        me->set_temp("block_msg/all");
                        input_to("qljob_2", me, ob);
                        return 1;
                }
        }

        write("看来你收帐的对象溜掉了，钱是收不到了。\n");
        return 1;
}

void qljob_2(string sel,object me,object ob)
{
        me->delete_temp("block_msg/all");

        if (sel=="Y"||sel=="y")
        {
                message_vision("\n" + HIY + "$N拍案而起，目露凶光怒道：“没钱？我看你是成心捣乱，真是找死！”\n\n"NOR ,me);
                me->kill_ob(ob);
                ob->kill_ob(me);
                call_out("qljob_3",0,me);
                return;
        }
        else if(sel=="N"||sel=="n")
        {
                message_vision("\n" + HIG + "$N叹了口气道：“算了，这笔帐我帮你还上吧。”，说罢把欠账单撕了粉碎。\n"NOR,me);
                message_vision("\n" + HIG + "$n感激得简直不知道该说些什么了。"NOR,me,ob);
                me->set_temp("qljob",5);
                destruct(this_object());
                return;
        }
        else{
                write(HIR"请选择N or Y："NOR);
                input_to("qljob_2", me, ob);
        }
        return;
}

void qljob_3(object me)
{
        object ob;

        ob = new(__DIR__"xiashi");
        ob->set("combat_exp",me->query("combat_exp") * 5 / 5);
        ob->set("max_qi",me->query("max_qi"));
        ob->set("eff_qi",me->query("max_qi"));
        ob->set("qi",me->query("max_qi"));
        ob->set("max_jingli",me->query("max_jingli"));
        ob->set("eff_jingli",me->query("max_jingli"));
        ob->set("jingli",me->query("max_jingli"));
        ob->set("max_neili",me->query("max_neili"));
        ob->set("neili",me->query("max_neili"));
        ob->set_skill("force", consider_lv(ob, 7));
        ob->set_skill("huifeng-jian", consider_lv(ob, 7));
        ob->set_skill("kunlun-shenfa", consider_lv(ob, 7));
        ob->set_skill("strike", consider_lv(ob, 7));
        ob->set_skill("kunlun-zhang",consider_lv(ob, 7));
        ob->set_skill("dodge", consider_lv(ob, 7)); 
        ob->set_skill("sword", consider_lv(ob, 7)); 
        ob->set_skill("linji-zhuang", consider_lv(ob, 7)); 
        ob->set_skill("parry", consider_lv(ob, 7)); 
        ob->set_skill("literate", consider_lv(ob, 7));
        ob->set("shen",(me->query("combat_exp")/20));
        ob->move(environment(me));
        message_vision("\n" + HIW + "突然一条人影向$N扑了过来。\n"NOR, me);
        message_vision("\n" + HIR + "$n对$N大喝一声：“你这个白驼山庄的走狗，还不受死！”\n"NOR, me, ob);
        me->kill_ob(ob);
        ob->kill_ob(me);
        destruct(this_object());
}

int consider_lv(object ob,int a)
{
        int level; 
        float exper;

        exper = to_float(ob->query("combat_exp"));
        level = ceil( pow( exper*10.0, 0.333333) );

        level = level * a / 10;

        return level;
}