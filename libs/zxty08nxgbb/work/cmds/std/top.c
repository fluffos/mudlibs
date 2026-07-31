#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        
        object *list,*ob;
        int i;
        string msg;
        if((int)me->query_temp("last_top") > time())
        return notify_fail("对不起，不能连续使用该指令!\n");

        me->set_temp("last_top",time() + 10);

      ob = filter_array(ty_users(), (: userp($1) && !wizardp($1)&&!$1->query("env/no_top") :));
      list = sort_array(ob, (: top_list :));               
      msg =  "\n                       ┏ "HIW"在现天涯在线高手排行榜"NOR" ┓\n";
      msg += "┏━━━┯━━━━━━┻━━━┯━━━━━━━━━╇━━━━━┯━━━┓\n";
      msg += "┃ 名次 │    高        手    │    帮      会    │ 评    价 │等 级 ┃\n";
      msg += "┠───┴──────────┴─────────┴─────┴───┨\n";

        for (i = 0 ;i < 15 ; i++) {
        if( i >= sizeof(list)) msg += "┃暂时空缺。 \n";
                else {
                if(list[i] == me) msg += BBLU HIY;
             msg += sprintf(NOR"┃ "+WHT+" %-5s"+HIY" %-22s" " %-37s"
             +HIR" %5d  "+HIC" %5d"+NOR+"  ┃\n"NOR,
             chinese_number(i+1),list[i]->query("name")+"("+
             capitalize(list[i]->query("id"))+")", 
  (string)list[i]->query("banghui")?list[i]->query("tybang/banghui"):HIG"无帮分子"NOR,
        get_score(list[i]),list[i]->query("zjb_dj/dj"));
                }
                         }
      msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
      msg += HIW"  您现在的评价是："+sprintf("%5d",get_score(me)); 
      msg += NOR"    " + NATURE_D->game_time() + "记。\n";
    if ( me->query("env/no_top") )
      msg += HIR"  您现在"HIC"处于隐世"HIR"中，无法进入排行榜\n"NOR;
        write(msg);
        return 1;

}
int top_list(object ob1, object ob2)

{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);

      return score2 - score1;
}

int get_score(object me)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;
        int exp;


   reset_eval_cost();
   score = me->query_skill("literate",1)/5;
   score += me->query_skill("dodge",1)/5;
   score += me->query_skill("force",1)/5;
   score += me->query("max_neili")/2000;
   score += me->query("max_jingli")/2000;
   score += me->query("str") + me->query("int") + me->query("dex") + 
me->query("con");
   score += me->query("spi")/20 + me->query("cps")/20 + me->query("kar")/20;
   exp = me->query_exp();
   exp/= 6000;
   score += exp;
      return score;
}

int help()
{
write(@HELP
指令格式 : top 
 
这个指令可以让你知道在线十五大高手是哪些，别去惹他们。 
 
HELP
    );
    return 1;
}


