#include <combat.h>

object npc_name2();
object npc_name();

int update(object obj)
{
        int i;
        object *inv;
        inv = all_inventory(obj);
        i = sizeof(inv);

        while(i--)
                if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
                else inv[i] = 0;
        destruct(obj);
        return 1;
}

void fullup(object obj) 
{
        if(!obj) return;
        obj->set("kee",250);
        obj->set("eff_kee",(int)obj->query("max_kee")*(5+random(5))/10);
        obj->set("sen",250);
        obj->set("eff_sen",(int)obj->query("max_sen"));
        obj->set("force",0);
        obj->set("mana",0);
}

int do_none( )
{
        string arg = query_verb();
        if( arg=="go" || arg=="chat" || arg=="eat" 
          || arg=="exert" || arg=="look" || arg=="l" 
          || arg=="chat" || arg=="tell" || arg=="i" 
          || arg=="hp" || arg=="full" || arg=="goto" 
          || arg=="quit" 
          || arg=="fly" || arg=="home" || arg=="drop" 
          || arg=="chat*" || arg=="updir" || arg=="enter" ) 
                return 0;
       if( wizardp(this_player()) )  return 0;
        tell_object(this_player(),HIY">"NOR"什么？\n");
        return 1;
}

void alternative_die(object me)
{
        if( userp(me) )
        {
                fullup(me);
                me->move(__DIR__"migong1");
                message("channel:rumor",HIY"【"+BLU"死亡岛"+HIY"】沙织(Sha zhi):"+HIW+me->name()+ HIY"在死亡迷宫中遇到不名的攻击!\n"NOR,users());  
                message_vision("$N退守到迷宫入口。\n",this_player() );  
                update(this_object());
        }
        else  destruct(me);
}

object npc_name( )
{
        int i;
        object ob,*players;
        players = users();
        i = random(sizeof(players));
        ob = players[i];
        if( !objectp(ob) || wizardp(ob) ) ob = npc_name2();
        return ob;
}

object npc_name2( )
{
        object ob;
        string *npc1,*npc2;
        npc1 = ({
                "/d/9sky/guzhanchang/npc/shouhuzhe1","/d/9sky/guzhanchang/npc/shouhuzhe2

",
                "/d/9sky/guzhanchang/npc/shouhuzhe3","/d/9sky/guzhanchang/npc/shouhuzhe4",
                "/d/9sky/guzhanchang/npc/shouhuzhe5","/d/9sky/guzhanchang/npc/shouhuzhe6",
                "/d/9sky/guzhanchang/npc/shouhuzhe7","/d/9sky/guzhanchang/npc/shouhuzhe8",
                "/d/9sky/guzhanchang/npc/shouhuzhe9","/d/9sky/guzhanchang/npc/tianzun",
        });
        npc2 = ({
                "/d/death/npc/dizhang","/d/death/npc/dizhang1","/d/jjf/npc/chengyaojin",
                "/d/jjf/npc/luocheng","/d/jjf/npc/qinqiong","/d/moon/npc/chimeng",
                "/d/moon/npc/change","/d/moon/npc/xiwangmu","/d/pansi/npc/zixia",
                "/d/pansi/npc/qingxia","/d/lingtai/npc/puti","/d/sea/npc/longwang",
                "/d/qujing/kusong/npc/honghaier","/d/nanhai/npc/guanyin",
                "/d/shushan/npc/jiansheng","/d/qujing/wuzhuang/npc/zhenyuan",
                "/d/sanjie/npc/zhaoyang","/d/youxia/npc/shaolong","/d/youxia/npc/yegucheng",
                "/d/youxia/npc/tianji","/d/youxia/npc/liuxiang","/d/youxia/npc/xiaofeng",
                "/d/emei/npc/li","/d/emei/npc/baimei","/d/shaolin/npc/damo",
                "/d/kunlun/npc/tianzun","/d/swordman/npc/jianxin","/d/tiankongjie/npc/xiewu",
                "/d/tiankongjie/npc/huiming","/d/sfighter/npc/gouki","/d/mojie/npc/kongque",
                "/d/mojie/npc/wu tian","/d/mingjiao/npc/zhangwuji",
});
        if( random(8)>5 )
                ob = new(npc1[random(sizeof(npc1))]);
        else    ob = new(npc2[random(sizeof(npc2))]);
        return ob;
}

int do_go(string arg)
{
        mapping act;
        int pot,i,damage;
        object me,env,target;
        string msg,t_name;
        me = this_player();
        env = this_object();
        pot = me->query_kar();

        if( !arg )
        {
                message_vision(CYN"$N"CYN"象没头苍蝇似的到处乱撞。\n"NOR,me);
                me->set_temp("death_msg","乱闯"HIG"秘境"HIM"，结果奔跑乏力而亡！"NOR);
                me->delete_temp("last_damage_from");
                me->receive_damage("kee",50+random(150));
                me->receive_damage("sen",50+random(150));
                return 1;
        }
        
        if( me->is_busy() )
        {
                write("你现在正忙着呢。\n");
                return 1;
        }
        
        if( random(10)<=3 )
                target = npc_name();
        else    target = npc_name2();

        if( !target || !objectp(target) )
                return 1;
        msg = "$N在浓雾中小心翼翼的往前摸索。\n";
        msg+= "到了！$N终于在浓雾中发现一个出口。\n";
        message_vision(msg,me);
        pot = random(pot);
        pot+=random(10);
        if( pot>=25 )
                return 0;
                
        msg="忽然雾气一闪，$W从深处冲了出来！\n";
        msg+=HIR"看起来$W"HIR"像要杀了$N"HIR"!\n"NOR;
        if ( target && stringp(target->query("name")) )
        {
            msg = replace_string(msg,"$W",(string)target->query("name"));
        }
        message_vision(msg,me);
        for ( i=0;i<(5+random(5));i++ )
        {
                damage = 200+random(1500);
                if( !mapp(target->query("actions")) ) 
                {
                        msg = "$N一式「我流之招」随心所欲的使出！$n躲闪不及，$l正中一击！\n";
                        msg+= COMBAT_D->damage_msg(damage,"重伤");
                }
                else    
                { 
                        act = target->query("actions");
                        msg = "\n" + act["action"] + "！\n";
                        msg += COMBAT_D->damage_msg(damage, act["damage_type"]);
                        if( objectp(target->query_temp("weapon")) ) 
                                t_name = target->query_temp("weapon")->name();
                        else if( (string)act["weapon"] )
                                t_name = (string)act["weapon"];
                        else    t_name = ({"劲气","真气","罡气",})[random(3)];
                        msg = replace_string(msg,"$w",t_name);
                }
                msg = replace_string(msg,"$l",me->query("limbs")[random(sizeof(me->query("limbs")))]);
                message_vision(msg,target,me);
                  me->set_temp("death_msg","乱闯"HIG"秘境"HIM"，结果被幻象杀死了！"NOR);
                me->delete_temp("last_damage_from");
                me->receive_damage("kee",damage);
                COMBAT_D->report_status(me);
                me->start_busy(1);
                if( target && !userp(target) )  destruct(target);
                return 1;
        }
}

void init() 
{ 
        add_action("do_none","",1);
        add_action("do_go","go");
} 

void setup()
{
    ::setup();
   set("alternative_die",1);
}
