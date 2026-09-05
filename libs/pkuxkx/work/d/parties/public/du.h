#define DU_BONUS1 15
#define DU_BONUS2 30
#define DU_BONUS3 45
#define DU_BONUS4 60
#include <skill.h>

#include "/d/parties/public/change_name.h"
void init()
{
    add_action("do_study","study");
    add_action("do_study","du");
    add_action("do_gua","gua");
    add_action("do_gua","guashang");
    add_action("do_zhai","zhai");
}
int do_study(string arg)
{
    object me=this_player();
    object where = environment(me);
    object ob;
    string msg,book;
    mapping skill;
    int my_skill, gin_cost, times, bonus,realtimes=0;
    int imp_skill;
    object ct=load_object(__DIR__"biguanchu");
    if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
    if( !me->query_skill("literate", 1) )
        return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

    if(!arg || (sscanf(arg, "%s for %d",book,times) != 2 ))
        return notify_fail("指令格式：du|study <物品id> for <次数>\n");
    if (times < 1 || times>50)
        return notify_fail("读书次数应该在 1-50 次之间！\n");
    if( me->is_fighting() )
        return notify_fail("你无法在战斗中专心下来研读新知！\n");
    if( !objectp(ob = present(book, me)) )
        return notify_fail("你身上没有 "+book+" 这种东西,请用 id 指令看看物品 id 。\n");
    //以下过滤几本可以读特殊武功的书
    if ( ( ob->query("name") == "乾坤大挪移心法" ) && ( where->query("placefor_qkdny") != 1 ) )
        return notify_fail(ob->name()+"只能在密室里读！\n");

    if ( ( ob->query("name") == "飞仙古画" ) && ( where->query("placefor_xksh") != 1 ) )
        return notify_fail(ob->name()+"只能在密室里读！\n");

    if ( ( ob->query("name") == GRN "玉女心经" NOR) || ( ob->query("name") == GRN "玉女心经「下」" NOR))
        if ( (string)me->query("family/family_name")!="全真派" && (string)me->query("family/family_name")!="古墓派" )
            return notify_fail("只有古墓和全真弟子才能学习"+ob->name()+"！\n");

    if ( ( ob->query("name") == "云龙鞭法")
            || ( ob->query("name") == "云龙剑谱「上册」")
            || ( ob->query("name") == "云龙经「上卷」" ) )
        if ( (string)me->query("family/family_name")!="天地会")
            return notify_fail("你不是天地会弟子，怎能偷学"+ob->name()+"！\n");

    if( !mapp(skill = ob->query("skill")) )
        return notify_fail(ob->name()+"上面没有记载什么值得学习的东西。\n");

    //添加valid_study函数，特殊的书的限制要么写在书上，要么写在对应的功夫上，以后不要再往study里加
    //by icer
    if (function_exists("valid_study",load_object(SKILL_D(skill["name"]))))
    		if( !SKILL_D(skill["name"])->valid_study(me) ) return 0;

    if( (int)me->query("combat_exp") < skill["exp_required"] )
        return notify_fail(sprintf("%s需要%d点经验才能读。\n",ob->name(),skill["exp_required"]));
    if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
        return notify_fail(sprintf("%s需要%d级的%s才能理解其中的意义。\n",
            ob->name(), skill["min_skill"], to_chinese(skill["name"])));
    if( me->query_int() < skill["difficulty"] )
        return notify_fail(sprintf("%s需要悟性大于 %d 才能领会。\n",ob->name(),skill["difficulty"]));
    if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;
    
    if (!environment(me)->query("least_msg"))
        message("vision", me->name() + "正专心地研读" + ob->name() + "。\n", environment(me), me);
    msg = "你从身上拿出一"+ob->query("unit")+ob->name()+"准备好好研读。\n";
    gin_cost = skill["jing_cost"];
    if (gin_cost < 10) gin_cost = 10; // minimum cost

    for ( int i=0; i < times; i++ )
    {
        //最高等级
        if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
        {
            msg += sprintf("你的%s等级已经高于 %d，没法再从%s学到任何东西了。\n",
                to_chinese(skill["name"]), skill["max_skill"], ob->name());
            break;
        }
            
        my_skill = me->query_skill(skill["name"], 1);
        if( (string)SKILL_D(skill["name"])->type()=="martial"
                &&  my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
        {
            msg += HIR"你的武功等级受到经验限制，等级的三次方不能大于经验值的十倍。\n"NOR;
            break;
        }

        if( (int)me->query("jing") < gin_cost )
        {
            msg +=HIR"你现在过于疲倦，无法专心下来研读新知。\n"NOR;
            break;
        }
        realtimes++;
        imp_skill = (int)me->query_skill("literate", 1)/5+1;
        imp_skill = imp_skill * SPEWEEK_D->query_learn_bonus()/100;

        imp_skill *=  REWARD_D->get_global_factor("study");
        if (ct->query("du_level")==1)
        {
            bonus=DU_BONUS1;
        }
        else if (ct->query("du_level")==2)
        {
            bonus=DU_BONUS2;
        }
        else if (ct->query("du_level")==3)
        {
            bonus=DU_BONUS3;
        }
        else if (ct->query("du_level")==4)
        {
            bonus=DU_BONUS4;
        }
        else
        {
            bonus=0;
        }
        if (!ct->valid_access(me))
        {
            bonus=0;
        }
        imp_skill=(bonus+100)/100;
        me->improve_skill(skill["name"], imp_skill);
        me->receive_damage("jing",gin_cost);
    }
    if (realtimes)
        msg +=sprintf("你研读了"+chinese_number(realtimes)+"次有关%s的技巧，似乎有点心得。\n", to_chinese(skill["name"]));
    write(msg);
    return 1;
}
