inherit "/domains/common/mission/std_mission";

//MISSION: Making Bullets
int steel_total = 0;
int lead_total = 0;
int minimum_steel = 30;
int minimum_lead = 20;
int minimum_contrib = 10;

string hiscore_who;
int hiscore;
mapping scraps_received = ([]);

void setup()
{
    set_length(15);
    set_mission_data(1, "Making Bullets");
    set_receive_items(1);
    set_favor(500);
    set_description("Help <guild> gather steel and lead for bullet casings. We need to produce ammunition for "
                    "our weapons! We need ITEMS to salvage into at least " +
                    minimum_steel + " steel scraps and " + minimum_lead + " lead scraps " +
                    "to produce the bullets we need.\n\n" +
                    "REWARD: Ammunition will be rewarded to people who contribute over " +
                    minimum_contrib + " scraps of any kind." +
                    "\n\nNOTICE: Adding metal scraps to our storage will *not* help for this mission.");
    set_materials("steel scrap:10,wood scrap:30,waste oil:5");
}

void begin_mission()
{
    channel_msg("New mission has begun: " + replace_string(query_description(), "<guild>", query_guild()));
}

int run_mission()
{
    string hi_str;
    if (hiscore_who)
        hi_str = "Current leading contributor is " + hiscore_who + " with " + hiscore + " metal scraps.";

    if (complete())
        channel_msg(query_name() + " mission is COMPLETED with " + query_length() + " of " + query_original_length() + " minutes left. " +
                    "You can still contribute to earn favor. Our total is now at " + steel_total + " steel and " + lead_total + " lead scraps. " +
                    (hi_str ? hi_str : ""));
    else
    {
        channel_msg(query_name() + " mission is ongoing with " + query_length() + " of " + query_original_length() + " minutes left. " +
                    "Find items that can be salvaged to steel and lead scraps and give them to me. ");
        channel_msg(steel_total + " steel and " + lead_total + " lead scraps received of minimum " +
                    minimum_steel + " steel and " + minimum_lead + " lead. " +
                    (hi_str ? hi_str : ""));
    }
    return ::run_mission();
}

void receive_item(object ob)
{
    object *salvage;
    object *steel, *lead;

    if (ob->is_salvageable())
    {
        salvage = CRAFTING_D->salvage_parts(ob);
        if (!sizeof(salvage))
        {
            query_mission_ctrl()->simple_action("$N $vtell $t, \"Sorry, but that item gave me nothing.\".", this_body());
            return;
        }
        steel = filter_array(salvage, (
                                          : $1->id("steel scrap")
                                          :));
        lead = filter_array(salvage, (
                                         : $1->id("lead scrap")
                                         :));
        salvage -= steel;
        salvage -= lead;
        steel_total += sizeof(steel);
        lead_total += sizeof(lead);
        if (!scraps_received[this_body()->query_name()])
            scraps_received[this_body()->query_name()] = sizeof(steel) + sizeof(lead);
        else
            scraps_received[this_body()->query_name()] += sizeof(steel) + sizeof(lead);

        if (scraps_received[this_body()->query_name()] > hiscore)
        {
            hiscore = scraps_received[this_body()->query_name()];
            hiscore_who = this_body()->query_name();
        }

        if (steel_total >= minimum_steel && lead_total >= minimum_lead && !complete())
        {
            set_complete();
            channel_msg("Our " + query_name() + " mission is successful, " + query_favor() + " favor gained!");
        }

        foreach (object s in salvage)
        {
            GUILD_D->add_material(query_guild(), s);
        }

        if (sizeof(steel))
            GUILD_D->add_material(query_guild(), "steel scrap", sizeof(steel));
        if (sizeof(lead))
            GUILD_D->add_material(query_guild(), "lead scrap", sizeof(lead));
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
    float favor_pr_scrap = 1.0 * f / (lead_total + steel_total || 1);

    foreach (string player, int num in scraps_received)
    {
        object body = find_body(lower_case(player));
        if (body)
        {
            int fave = to_int(num * favor_pr_scrap);
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