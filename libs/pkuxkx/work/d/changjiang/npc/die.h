void unconcious()
{
    this_object()->die();
}

void die()
{
    object killer;
    killer = this_object()->get_damage_origin_object();
    if(!killer || !objectp(killer))
    {
		return;
    }
    else
    {
//        message("chat",sprintf(HIW+"【长江】%s: %s(%s)卑鄙无耻，残杀无辜艄公！真是武林败类！\n"+NOR,this_object()->query("name"),killer->query("name"),killer->query("id")),users());
          tell_object(killer,"你在光天化日之下公然行凶，成为武林公敌！\n");
//        ::die();
	set("eff_qi",this_object()->query("max_qi"));
	set("qi",this_object()->query("max_qi"));
	set("eff_jing",this_object()->query("max_jing"));
	set("jing",this_object()->query("max_jing"));        
        return;
    }
}
    