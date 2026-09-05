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
        killer->apply_condition("killer", 500);
        tell_object(killer,"你在光天化日之下公然行凶，已经被官府通缉了！\n");
        destruct(this_object());
        return;
    }
}
    