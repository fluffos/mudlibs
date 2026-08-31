/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// party_D - Daemon for storing groups of players on the mud and
//          awarding experience proportionally to those players
//          if experience is used.
// March 1, 1997: Iizuka@Lima Bean created.

// ## Change access system to use leaders, and members marked in different way.

#define PARTIES_SAVE

#ifdef PARTIES_SAVE
inherit M_DAEMON_DATA;
inherit CLASS_PARTY;
#else
#define save_me()
#define restore_me()
#endif

private
int DIFF = 5;
private
mapping parties = ([]);

nomask int register_party(string name, string owner, string password)
{
   class party new_party = new (class party);

   if (parties[name])
      return 0;

   // When we first create the party, the creator
   // has 100% of the experience shares and has
   // the highest access level.
   new_party.name = name;
   new_party.members = ([]);
   new_party.members[owner] = 1;
   new_party.kills = ([]);
   new_party.kills[owner] = 0;
   new_party.password = crypt(password, 0);
   new_party.total_kills = 0;
   parties[name] = new_party;
   save_me();
   return 1;
}

mapping query_party(string te)
{
   return parties[te];
}

mixed test(string name)
{
   class party t = parties[name];
}

// Either the password matches the crypt or the entire crypt is input
nomask int check_password(string pname, string passwd)
{
   return crypt(passwd, ((class party)parties[pname]).password) == ((class party)parties[pname]).password ||
          passwd == ((class party)parties[pname]).password;
}

nomask int award_experience(object slayer, string name, object *viable, int level)
{
   class party tmp = parties[name];
   string *party_members = keys(tmp.members);
   int x = 0;
   float total = 0.0;

   parties[name].total_kills++;

   foreach (string member_name in party_members)
   {
      object b = find_body(lower_case(member_name));
      if (b && member_array(b, viable) != -1)
      {
         if (slayer && slayer == b)
            parties[name].kills[member_name]++;

         total += b->query_level();
      }
   }

   foreach (string member_name in party_members)
   {
      object b = find_body(lower_case(member_name));
      int amount;
      if (b && member_array(b, viable) != -1)
      {
         amount = b->calc_xp_for(b->query_level(), level);
         TBUG("Party XP: " + member_name + " amount: " + amount + " level of receiver: " + b->query_level() +
              " level for: " + level);
         b->add_experience(to_int(amount * (find_body(lower_case(member_name))->query_level() / total)));
      }
   }

   if (!tmp.kill_list)
      tmp.kill_list = ({});
   tmp.kill_list += ({previous_object()->query_in_room_desc()});
   if (sizeof(tmp.kill_list) > 10)
      tmp.kill_list = tmp.kill_list[1..];

   save_me();
   return 1;
}

#ifdef USE_KARMA
nomask void modify_karma(string name, object *viable, int karma_impact)
{
   class party tmp = parties[name];
   string *party_members = keys(tmp.members);
   int x = 0;

   foreach (string member_name in party_members)
   {
      object b = find_body(lower_case(member_name));
      if (b && arrayp(viable) && member_array(b, viable) != -1)
         b->modify_karma(karma_impact);
   }
}
#endif

//: FUNCTION flip_mapping
// Reverses the keys and values in a mapping if
// the values are compatible as keys.
mapping flip_mapping(mapping map)
{
   mapping new_map = ([]);
   map_mapping(map, ( : $(new_map)[$2] = $1:));
   return new_map;
}

nomask string query_owner(string pname)
{
   mapping members = ((class party)parties[pname]).members;
   int min = min(values(members));
   return flip_mapping(members)[min];
}

nomask string *query_party_members(string pname)
{
   return keys(((class party)parties[pname]).members);
}

nomask int add_member(string new_member, string pname, string password)
{
   object body = find_body(lower_case(new_member));
   int access;
   string *members = query_party_members(pname);

   if (!check_password(pname, password))
      return 0;

   /*
      //Broken right now

      // If the difference in levels between the new member
      // and any existing member of the party is greater
      // than DIFF, do not add the new member.
      if (body->query_level() > ((class party)parties[pname]).min_level + DIFF ||
          body->query_level() < ((class party)parties[pname]).max_level - DIFF)
         return 0;
   */

   // Update the new minimum and maximum levels for the party if needed.
   if (body->query_level() > ((class party)parties[pname]).max_level)
      ((class party)parties[pname]).max_level = body->query_level();
   if (body->query_level() < ((class party)parties[pname]).min_level)
      ((class party)parties[pname]).min_level = body->query_level();

   access = sizeof(((class party)parties[pname]).members) + 1;

   ((class party)parties[pname]).members[new_member] = access;
   ((class party)parties[pname]).kills[new_member] = 0;

   foreach (string m in members)
   {
      object b = find_body(lower_case(m));
      if (b)
         tell(b, new_member + " has joined the party.\n");
   }
   save_me();
   return 1; // Member has been added
}

mapping move_access(mapping members, int access)
{
   foreach (string m, int a in members)
   {
      if (a > access)
         members[m] = --a;
   }
   return members;
}

void swap_access(string member, string member2, string pname)
{
   class party party = ((class party)parties[pname]);
   int a1, a2;
   a1 = party.members[member];
   a2 = party.members[member2];

   // Swap the access levels.
   party.members[member] = a2;
   party.members[member2] = a1;

   save_me();
}

nomask int remove_member(string member, string pname)
{

   if (!((class party)parties[pname]).members[member])
      return 0; // no such member
   else
   {
      map_delete(((class party)parties[pname]).members, member);
      ((class party)parties[pname]).members =
          move_access(((class party)parties[pname]).members, ((class party)parties[pname]).members[member]);
   }

   save_me();
   return 1;
}

nomask string locate_access_member(string pname, int access)
{
   string *members;

   members = keys(((class party)parties[pname]).members);
   foreach (string name in members)
   {
      if (((class party)parties[pname]).members[name] == access)
         return name;
   }
   return 0;
}

// Because two users cannot have the same access levels, when one member's
// access changes, at least one other member's must also. When a user is
// assigned access level X, every user between access level X and the
// user's current access level have their access level incremented (which,
// in game terms, means lowered) =)
private
int change_access(string pname, string member, int access)
{
   string current_member;
   int old_access;

   current_member = locate_access_member(pname, access);
   old_access = ((((class party)parties[pname]).members[member]));
   ((((class party)parties[pname]).members[current_member])) = old_access;
   ((((class party)parties[pname]).members[member])) = access;

   save_me();
   return 1;
}

string query_theme(string pname)
{
   class party party = (class party)parties[pname];

   return party.theme || "none";
}

void set_theme(string t, string pname)
{
   class party party = (class party)parties[pname];

   party.theme = t;
   save_me();
}

nomask string locate_user(string name)
{
   string *p = keys(parties);

   foreach (string s in p)
   {
      if (member_array(name, keys(((class party)parties[s]).members)) != -1)
         return s;
   }
   //   return filter(keys(parties), (: member_array(name,
   //            keys(((class party)parties[$1]).members)) :));
}

nomask mapping list_all_parties()
{
   mapping p = ([]);
   foreach (string name, class party party in parties)
   {
      p[name] = ({party.total_kills, sizeof(party.members),party.theme});
   }

   return p;
}

nomask int query_party_kills(string pname)
{
   return ((class party)parties[pname]).total_kills;
}

nomask string *query_kill_list(string pname)
{
   return ((class party)parties[pname]).kill_list;
}

nomask int query_member_access(string pname, string member)
{
   return ((((class party)parties[pname]).members[member]));
}

nomask int query_member_kills(string pname, string member)
{
   return ((((class party)parties[pname]).kills[member]));
}

// Find a user in the party 'pname' with a given access level.
nomask string locate_member_by_access(string pname, int access)
{
   string *m;

   m = keys(((class party)parties[pname]).members);
   foreach (string s in m)
   {
      if (((((class party)parties[pname]).members[s])) == access)
         return s;
   }
   return 0;
}

// The maximum number of members that can be active in one login.
nomask int query_max_active(string pname)
{
   return ((class party)parties[pname]).max_active;
}

nomask void set_max_active(string pname, int n)
{
   ((class party)parties[pname]).max_active = n;
   save_me();
}

nomask string *query_active_members(string pname)
{
   int max;
   string *all;

   max = ((class party)parties[pname]).max_active;
   all = ({});
   // If there is no limit, list all users. Default is no limit.
   if (max == 0)
      return query_party_members(pname);

   for (int x = 0; x < max; x++)
      all += ({locate_member_by_access(pname, x)});

   return all;
}

nomask void set_title(string pname, string title)
{
   ((class party)parties[pname]).title = title;
   save_me();
}

nomask string query_title(string pname)
{
   return ((class party)parties[pname]).title;
}

nomask void set_password(string pname, string password)
{
   ((class party)parties[pname]).password = crypt(password, 0);
   save_me();
}

nomask string query_password(string pname)
{
   return ((class party)parties[pname]).password;
}

nomask void remove_party(string pname)
{
   map_delete(parties, pname);
   save_me();
}

nomask int party_exists(string pname)
{
   return pname ? (parties[pname] ? 1 : 0) : 0;
}

void create()
{
   restore_me();
}
