string color;

int menpai(object ob)
{
    
    if (ob->query("family/family_name")=="星宿派")
    {
        color=HIB;
    }
    if (ob->query("family/family_name")=="白驼山")
    {
        color=WHT;
    }
    if (ob->query("family/family_name")=="大轮寺")
    {
        color=YEL;
    }
    if (ob->query("family/family_name")=="丐帮")
    {
        color=HIY;
    }
    if (ob->query("family/family_name")=="古墓派")
    {
        color=HIW;
    }
    if (ob->query("family/family_name")=="华山派")
    {
        color=HIM;
    }
    if (ob->query("family/family_name")=="灵鹫宫")
    {
        color=HIG;
    }
    if (ob->query("family/family_name")=="明教")
    {
        color=HIR;
    }
    if (ob->query("family/family_name")=="姑苏慕容")
    {
        color=CYN;
    }
    if (ob->query("family/family_name")=="全真派")
    {
        color=HIR;
    }
    if (ob->query("family/family_name")=="日月神教")
    {
        color=RED;
    }
    if (ob->query("family/family_name")=="少林派")
    {
        color=HIG;
    }
    if (ob->query("family/family_name")=="神龙教")
    {
        color=BLU;
    }
    if (ob->query("family/family_name")=="桃花岛")
    {
        color=HIC;
    }
    if (ob->query("family/family_name")=="天地会")
    {
        color=MAG;
    }
    if (ob->query("family/family_name")=="天龙寺")
    {
        color=HIR;
    }
    if (ob->query("family/family_name")=="武当派")
    {
        color=HIW;
    }
    if (ob->query("family/family_name")=="峨嵋派")
    {
        color=HIM;
    }
    else
    {
        color=GRN;
    }
}

void unconcious()
{
    object killer;
    object ob=this_object();
    string menpai=ob->query("family/family_name");
    
    
    menpai(ob);
    killer = ob->get_damage_origin_object();
    if ( objectp(killer) )
    {
      command("mp "+killer->query("name")+"("+killer->query("id")+")偷袭了我，"+menpai+"弟子注意，此人是我派大敌！\n");
      tell_object(killer,"你在光天化日之下公然对"+ob->query("name")+"行凶，"+menpai+"公敌！\n");
    }
    ::unconcious();
    return;
}

void die()
{
    object killer;
    object ob=this_object();
    string menpai=ob->query("family/family_name");
    menpai(ob);
    killer = this_object()->get_damage_origin_object();
    if(!killer || !objectp(killer))
    {
		return;
    }
    else
    {
        command("mp "+killer->query("name")+"("+killer->query("id")+")偷袭了我，"+menpai+"弟子注意，此人是我派大敌！\n");
        tell_object(killer,"你在光天化日之下公然对"+ob->query("name")+"行凶，"+menpai+"公敌！\n");
        ::die();
        return;
    }
}
    