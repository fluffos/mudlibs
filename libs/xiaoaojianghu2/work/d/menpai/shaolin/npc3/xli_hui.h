//xli

#define SI_MEN "/d/menpai/shaolin/luohan_zhen/"+sprintf("neiting%d",2*random(4)+2)
#define SHENG_MEN "/d/menpai/shaolin/luohan_zhen/"+sprintf("neiting%d",2*random(4)+1)
#define DATING "/d/menpai/shaolin/luohan_zhen/luohan_dating"

int attempt_apprentice(object who)
{
    if(who->query("gender")=="女性")
        command("say  阿弥陀佛，女施主不要跟老纳开玩笑。");
    else if (who->query("class")!="bonze")
        command("say 未得方丈准许，老纳不敢擅收俗家弟子。施主还是请回吧.");
    else
        command("say 阿弥陀佛，老衲向来不收弟子。");
    return 0;
}

int accept_fight(object who)
{
    if((string)who->query("class")=="bonze")
        command("say 阿弥陀佛！出家人戒逞强恶斗！贫僧不敢违反清规。");

    else
        command("say 施主既然身负绝艺，贫僧佩服便是，也不必较量了。");
    return 0;
}
int valid_teach( object ppl, string skill )
{
    command( "say “你可要专心迎战啊。”" );
    return 0; 

}


int accept_bihua(object who)
{
    return accept_fight(who);
}

/*  added by xli,1998.10 */
int lose_bihua( object ppl )
{
    int num;
    command("nod "+ppl->query("id"));
    command("say 不错，不错！老衲自愧弗如！");
    num = ppl->query("xli_marks/bp");
    ppl->set("xli_marks/bp",num+1); 
    
    call_out("ArrayChange",1,ppl);
    return 1;
}

void ArrayChange(object ppl)
{
    tell_object(ppl,BLU"只见阵形变动，你眼前一花，"+
        this_object()->query("name")+"已不知所踪。\n\n"NOR);
    if(random(10)>4)
        move(SI_MEN); // 移动到死门去休息
    else
        move(SHENG_MEN);
    tell_object(ppl,YEL"又见火光突然一灭，你感到伸手不见五指...\n\n"NOR);
    tell_object(ppl,RED"只觉身边人影嗖嗖来去，却无法触及。\n"NOR);
    tell_object(ppl,YEL"火光重新燃起时，你发现你已不在刚才的地方了。\n\n"NOR);
    if(random(5)>1)
        ppl->move(SI_MEN);
    else
        ppl->move(SHENG_MEN); 
}        

int win_bihua( object ppl )
{
    command("shake"+ppl->query("id"));
    if( !ppl->is_ghost() )
    {
        command("say 你既然难以闯过本阵，就请出去吧！");
        tell_object(ppl,HIY"你只觉一阵眩晕，身子一飘，来到了罗汉大厅。\n\n"NOR);
        ppl->set("xli_marks/闯阵失败",1);
        ppl->move(DATING);
    }
    return 1;
}
