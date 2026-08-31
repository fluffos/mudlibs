inherit "/domains/common/mission/std_mission";

//MISSION: Wood gathering (Large)
int wood_total = 0;
int minimum_wood = 100;
string hiscore_who;
int hiscore;
mapping wood_received = ([]);

void setup()
{
    set_length(60);
    set_mission_data(2, "Wood gathering (Large)");
    set_receive_items(1);
    set_favor(1500);
    set_description("Help <guild> gather wood for heating up their offices. You need to find "
                    "and hand in items within 15 minutes that can be salvaged to " +
                    minimum_wood + " wood scraps. "
                                   "\n\nNOTICE: Adding wood scraps to our storage will *not* "
                                   "help for this mission.");

    set_materials("steel scrap:40,wood scrap:25");
}

void begin_mission()
{
    channel_msg("New mission has begun: " + replace_string(query_description(), "<guild>", query_guild()));
}

int run_mission()
{
    string hi_str;
    if (hiscore_who)
        hi_str = "Current leading contributor is " + hiscore_who + " with " + hiscore + " wood scraps.";

    if (complete())
        channel_msg(query_name() + " mission is COMPLETED with " + query_length() + " of " + query_original_length() + " minutes left. " +
                    "You can still contribute to earn favor. Our total is now at " + wood_total + ". " +
                    (hi_str ? hi_str : ""));
    else
    {
        channel_msg(query_name() + " mission is ongoing with " + query_length() + " of " + query_original_length() + " minutes left. " +
                    "Find items that can be salvaged to wood scraps and give them to me. ");
        channel_msg(wood_total + " wood scraps received of minimum " + minimum_wood + ". " +
                    (hi_str ? hi_str : ""));
    }
    return ::run_mission();
}

void receive_item(object ob)
{
    object *salvage;
    object *wood;

    if (ob->is_salvageable())
    {
        salvage = CRAFTING_D->salvage_parts(ob);
        if (!sizeof(salvage))
        {
            query_mission_ctrl()->simple_action("$N $vtell $t, \"Sorry, but that item gave me nothing.\".", this_body());
            return;
        }
        wood = filter_array(salvage, (
                                         : $1->id("wood scrap")
                                         :));
        salvage -= wood;
        wood_total += sizeof(wood);
        if (!wood_received[this_body()->query_name()])
            wood_received[this_body()->query_name()] = sizeof(wood);
        else
            wood_received[this_body()->query_name()] += sizeof(wood);

        if (wood_received[this_body()->query_name()] > hiscore)
        {
            hiscore = wood_received[this_body()->query_name()];
            hiscore_who = this_body()->query_name();
        }

        if (wood_total >= minimum_wood && !complete())
        {
            set_complete();
            channel_msg("Our " + query_name() + " mission is successful, " + query_favor() + " favor gained!");
        }

        foreach (object s in salvage)
        {
            GUILD_D->add_material(query_guild(), s);
        }

        if (sizeof(wood))
            GUILD_D->add_material(query_guild(), "wood scrap", sizeof(wood));
    }
    else
    {
        query_mission_ctrl()->targetted_action("$N $vgive the item back to $t, \"Sorry, I cannot salvage that item?\".", this_body());
        ob->move(this_body());
        return;
    }
}

void end_mission()
{
    int f = query_favor();
    float favor_pr_wood = 1.0 * f / (wood_total || 1);

    foreach (string player, int num in wood_received)
    {
        object body = find_body(lower_case(player));
        if (body)
        {
            int fave = to_int(num * favor_pr_wood);
            if (complete())
            {
                GUILD_D->add_favor(body, query_guild(), fave);
                tell(body, "You received " + fave + " favor points with " + capitalize(query_guild()) + ".\n");
            }
            else
            {
                tell(body, "You contribution is noted, bad sadly we did not meet the target for the mission.\n");
            }
        }
    }

    ::end_mission();
}