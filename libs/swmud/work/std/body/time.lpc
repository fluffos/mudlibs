// Last edited by deforce on 03-22-2010
private int character_birthday;
private int total_connected_time;
private mixed time_zone;

int query_character_birthday()
{
   return character_birthday;
}

void set_character_birthday(int birthday)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s character birthday to " + ctime(birthday), previous_object(-1)); }

   character_birthday = birthday;
}

int query_total_connected_time()
{
   return total_connected_time;
}

void set_total_connected_time(int time)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s total connected time to " + convert_time(time), previous_object(-1)); }

   total_connected_time = time;
}

int query_current_character_age()
{
   return total_connected_time + (time() - LAST_LOGIN_D->query_last(this_body()->query_userid())[0]);
}

void set_current_character_age(int time)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s current character age to " + convert_time(time), previous_object(-1)); }

   total_connected_time = total_connected_time + (time() - LAST_LOGIN_D->query_last(this_body()->query_userid())[0]);
}

mixed query_time_zone()
{
    return time_zone;
}

void set_time_zone(mixed tmp)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s time zone to " + tmp, previous_object(-1)); }

   time_zone = tmp;
}