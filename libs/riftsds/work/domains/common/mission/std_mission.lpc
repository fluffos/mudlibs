/*
* Tsath, 2020
* Standard Mission object.
*/

private
string name;
private
int tier;
private
int length = 10;
private
int favor;
private
string description;
private
string materials;
int left = 10;
string guild = " ";
int receive_items = 0;
int complete;

object mission_ctrl;

void set_receive_items(int i)
{
    receive_items = i;
}

int set_complete()
{
    complete = 1;
}

string query_guild()
{
    return guild;
}

void set_favor(int f)
{
    favor = f;
}

int query_favor()
{
    return favor;
}

int complete()
{
    return complete;
}

int query_receive_items()
{
    return receive_items;
}

void set_length(int i)
{
    length = i;
    left = i;
}

void set_description(string d)
{
    description = d;
}

string query_description()
{
    return description;
}

void set_materials(string d)
{
    materials = d;
}

string query_materials()
{
    return materials;
}

int query_length()
{
    return left;
}

int query_original_length()
{
    return length;
}

object query_mission_ctrl()
{
    if (!mission_ctrl)
        mission_ctrl = GUILD_D->mission_ctrl_npc(guild);
    mission_ctrl->set_active_mission(this_object());

    return mission_ctrl;
}

int run_mission()
{
    left--;
    return left;
}

int is_mission()
{
    return 1;
}

void channel_msg(string s)
{
    if (!guild)
        return;
    CHANNEL_D->deliver_channel(guild, query_mission_ctrl()->query_name() + ": " + s);
}

void notify_guild_members(string s)
{
    object *members = filter_array(bodies(), (
                                                 : member_array(guild, $1->guilds_belong()) != -1
                                                 :));
    members = filter_array(members, (
                                        : present("guild_pager_ob", $1) && member_array(guild, present("guild_pager_ob", $1)->query_guilds()) != -1
                                        :));
    tell(members, s);
}

void pager_message(string m)
{
    notify_guild_members("Your pager ba-bweeps, \"%^GREEN%^" + upper_case(m) + ".%^RESET%^\".\n");
}

void setup(string g)
{
}

void real_remove()
{
    destruct();
}

void remove()
{
    if (!clonep())
        return;
    if (complete())
        GUILD_D->add_log(guild, "Tier " + tier + " mission '" + name + "' completed.");
    else
        GUILD_D->add_log(guild, "Tier " + tier + " mission '" + name + "' failed.");
    pager_message(guild + " mission ended. Thank you for your assistance");
    query_mission_ctrl()->end_mission();
    call_out("real_remove", 5);
}

string query_name()
{
    return name;
}

int query_tier()
{
    return tier;
}

void set_mission_data(int t, string n)
{
    tier = t;
    name = n;
}

void begin_mission()
{
    
}

void end_mission()
{
    call_out("remove", 10);
}

void create(string g)
{
    guild = g;
    setup(g);

    if (!clonep())
        return;
    query_mission_ctrl();

    call_out("pager_message",
             2,
             guild + " mission just started. Tune into our channel");
    begin_mission();
}