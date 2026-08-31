inherit "/domains/common/favor/std_favor";

//FAVOR: XP Buff Small

void setup()
{
    set_mission_data(1,"XP Buff Small");
    set_length(30);
    set_description("30 minutes of 20% XP buff for <guild>.");
    set_favor(500);
}

int apply_favor()
{
    object *people = GUILD_D->belongs_to(query_guild());
    people->set_guild_xp_buff(20);
    TBUG("setting 20% on "+sizeof(people)+" people.");
    TBUG("Ends in:"+ends_in());
    return ends_in();
}

void end_favor()
{
    object *people = GUILD_D->belongs_to(query_guild());
    people->clear_guild_xp_buff();
    ::end_favor();
}

