// Group module (/std/module/group.c)
// Coded by Donky - 25/09/96

// Donky @ 29th June 1999
// Modified add_leader() to add the person as a member if they are not
// already one.  Also modified remove_member() to remove someone as a
// leader if they are one.

// Shaydz - 07-02-2001 modified lots and added senior support stuff

//inherit "/secure/std/classes/group";

class profile {
  int    date_created;
  string creator;    // person who created the object

  string name;       // name
  string short;      // title
  string long;       // description of purpose
}

class member {
  string *groups;    // groups member belongs to

  class  profile info;
}

class group {
  string *members;   // members who belong to the group
  string *leaders;   // leaders of the group
  string *seniors;    // seniors of a group
  
  class  profile info;
}

private class group *groups;
private class member *members;

protected void mudlib_setup() {
  groups = ({ });
  members = ({ });
} /* mudlib_setup() */

private int find_group(string name) {
  int offset, found;
  class group group;

  foreach (group in groups) {
    if (group -> info -> name == name) {
      found++;
      break;
    }

    offset++;
  }

  if (found)
    return offset;
  else
    return -1;
}

private int find_member(string name) {
  int offset, found;
  class member member;

  foreach (member in members) {
    if (member -> info -> name == name) {
      found++;
      break;
    }

    offset++;
  }

  if (found)
    return offset;
  else
    return -1;
}

int create_member(string name) {
  string creator;
  class member new_member;

  // can only create properly named members that don't already exist

  if (!stringp(name) || (find_member(name) != -1))
    return 0;

  if (this_player())
    creator = this_player() -> query_name();

  new_member = new(class member);
  new_member -> info = new(class profile);
  new_member -> info -> name = name;
  new_member -> info -> creator = creator;
  new_member -> info -> date_created = time();

  members += ({ new_member });

  return 1;
}

int delete_member(string name) {
  int i, mi;
  class group group;

  if (!stringp(name) || ((mi = find_member(name)) == -1))
    return 0;

  members = delete(members, mi, 1);

  // possible optimised version.. member -> groups

  foreach (group in groups) {
    if (arrayp(group -> members))
      if ((i = member_array(name, group -> members)) != -1)
        group -> members = delete(group -> members, i, 1);

    if (arrayp(group -> leaders))
      if ((i = member_array(name, group -> leaders)) != -1)
        group -> leaders = delete(group -> leaders, i, 1);
  }

  return 1;
} /* delete_member() */

varargs int query_member(string group, string name) {
  int mi, gi;

  if (!stringp(name) && stringp(group))
    return (find_member(group) != -1);

  if ((gi = find_group(group)) == -1 || (mi = find_member(name)) == -1)
    return 0;

  if (arrayp(members[mi] -> groups))
    return member_array(group, members[mi] -> groups) != -1;
  else
    return 0;
}

mixed query_member_thing() {
  if(!adminp(TP)) return 0;  //Temp function, but let's not take chances.
  return members;
}

string *query_members(string group) {
  int gi;
  class member member;
  string *names = ({ });

  if (stringp(group)) {
    if ((gi = find_group(group)) == -1)
      return 0;

    return groups[gi] -> members;
  }

  foreach (member in members)
    names += ({ member -> info -> name });

  return names;
}

mixed add_member(string group, string name) {
  int mi, gi;

  // can only add existing members to existing groups if they don't already
  // belong

  if ((gi = find_group(group)) == -1 || (mi = find_member(name)) == -1 ||
    query_member(group, name))
      return 0;

  if (arrayp(groups[gi] -> members))
    groups[gi] -> members += ({ name });
  else
    groups[gi] -> members = ({ name });

  if (arrayp(members[mi] -> groups))
    members[mi] -> groups += ({ group });
  else
    members[mi] -> groups = ({ group });

  return 1;
}

mixed remove_member(string group, string name) {
  int i, mi, gi;
  string *grps;

  // can only remove existing members of existing groups if they belong

  if ((gi = find_group(group)) == -1 || (mi = find_member(name)) == -1 ||
      !query_member(group, name))
    return 0;

  grps = members[mi] -> groups;

  // Removing someone as a member should implicitly mean they need to be
  // removed as a leader as well.

  if (arrayp(grps) && member_array(group, grps) != -1) {
    groups[gi] -> members -= ({ name });
    groups[gi] -> leaders -= ({ name });
    members[mi] -> groups -= ({ group });
    i = 1;
  }

  return i;
} /* remove_member() */

int query_leader(string group, string name) {
  int gi;
  class group grp;

  if (!stringp(name) && stringp(group)) {
    foreach (grp in groups)
      if (arrayp(grp -> leaders))
      if (member_array(group, grp -> leaders) != -1)
        return 1;

    return 0;
  }

  if ((gi = find_group(group)) == -1 || find_member(name) == -1)
    return 0;

  if (arrayp(groups[gi] -> leaders))
    return (member_array(name, groups[gi] -> leaders) != -1);

  return 0;
}

string *query_leaders(string name) {
  int gi;
  class group group;
  string leader, *names = ({ });

  if (stringp(name)) {
    if ((gi = find_group(name)) == -1)
      return 0;

    if (arrayp(groups[gi] -> leaders))
      return groups[gi] -> leaders;
    else
      return ({ });
  }

  foreach (group in groups)
    foreach (leader in group -> leaders)
      if (member_array(leader, names) == -1)
        names += ({ leader });

  return names;
}

mixed add_leader(string group, string name) {
  int gi, mi;

  // can only add leaders to existing groups if they aren't already

  if ((gi = find_group(group)) == -1 ||
      (mi = find_member(name)) == -1 ||
      query_leader(group, name))
    return 0;

  // Adding someone as a leader should implicitly add them as a
  // member.  Yeah, yeah, had some problems with this.

  if (arrayp(groups[gi] -> members)) {
    if (member_array(name, groups[gi] -> members) == -1)
      groups[gi] -> members += ({ name });
  } else
    groups[gi] -> members = ({ name });

  if (arrayp(members[mi] -> groups)) {
    if (member_array(group, members[mi] -> groups) == -1)
      members[mi] -> groups += ({ group });
  } else
    members[mi] -> groups = ({ name });

  if (arrayp(groups[gi] -> leaders))
    groups[gi] -> leaders += ({ name });
  else
    groups[gi] -> leaders = ({ name });

  return 1;
}

mixed remove_leader(string group, string name) {
  int i, gi;

  // can only remove existing leaders of existing groups

  if ((gi = find_group(group)) == -1 || find_member(name) == -1 ||
    !query_leader(group, name))
      return 0;

  if (arrayp(groups[gi] -> leaders) &&
      (i = member_array(name, groups[gi] -> leaders)) != -1) {
    groups[gi] -> leaders = delete(groups[gi] -> leaders, i, 1);
    return 1;
  }

  return 0;
}

// Seniors.

int query_senior(string group, string name) {
  int gi;
  class group grp;

  if (!stringp(name) && stringp(group)) {
    foreach (grp in groups)
      if (arrayp(grp -> seniors))
      if (member_array(group, grp -> seniors) != -1)
        return 1;

    return 0;
  }

  if ((gi = find_group(group)) == -1 || find_member(name) == -1)
    return 0;

  if (arrayp(groups[gi] -> seniors))
    return (member_array(name, groups[gi] -> seniors) != -1);

  return 0;
}

string *query_seniors(string name) {
  int gi;
  class group group;
  string senior, *names = ({ });

  if (stringp(name)) {
    if ((gi = find_group(name)) == -1)
      return 0;

    if (arrayp(groups[gi] -> seniors))
      return groups[gi] -> seniors;
    else
      return ({ });
  }

  foreach (group in groups)
    foreach (senior in group -> seniors)
      if (member_array(senior, names) == -1)
        names += ({ senior });

  return names;
}

mixed add_senior(string group, string name) {
  int gi, mi;

  // can only add seniors to existing groups if they aren't already

  if ((gi = find_group(group)) == -1 ||
      (mi = find_member(name)) == -1 ||
      query_senior(group, name))
    return 0;

  // Adding someone as a senior should implicitly add them as a member.

  if (arrayp(groups[gi] -> members)) {
    if (member_array(name, groups[gi] -> members) == -1)
      groups[gi] -> members += ({ name });
  } else
    groups[gi] -> members = ({ name });

  if (arrayp(members[mi] -> groups)) {
    if (member_array(group, members[mi] -> groups) == -1)
      members[mi] -> groups += ({ group });
  } else
    members[mi] -> groups = ({ name });

  if (arrayp(groups[gi] -> seniors))
    groups[gi] -> seniors += ({ name });
  else
    groups[gi] -> seniors = ({ name });

  return 1;
}

mixed remove_senior(string group, string name) {
  int i, gi;

  // can only remove existing seniors of existing groups

  if ((gi = find_group(group)) == -1 || find_member(name) == -1 ||
    !query_senior(group, name))
      return 0;

  if (arrayp(groups[gi] -> seniors) &&
      (i = member_array(name, groups[gi] -> seniors)) != -1) {
    groups[gi] -> seniors = delete(groups[gi] -> seniors, i, 1);
    return 1;
  }

  return 0;
}

int add_group(string name) {
  int gi;
  string creator;
  class group new_group;

  // can only add groups that don't already exist

  if ((gi = find_group(name)) != -1)
    return 0;

  if (this_player())
    creator = this_player() -> query_name();

  new_group = new(class group);
  new_group -> members = ({ });
  new_group -> leaders = ({ });
  new_group -> seniors = ({ });
  new_group -> info = new(class profile);
  new_group -> info -> name = name;
  new_group -> info -> creator = creator;
  new_group -> info -> date_created = time();

  groups += ({ new_group });

  return 1;
}

int remove_group(string name) {
  int gi;
  class member member;

  // can only remove existing groups

  if ((gi = find_group(name)) == -1)
    return 0;

  // remove all references to the group in internal player lists

  foreach (member in members)
    if (arrayp(member -> groups))
      member -> groups -= ({ name });

  // remove the group itself

  groups = delete(groups, gi, 1);

  return 1;
} /* remove_group() */

int query_group(string name) {
  return (find_group(name) != -1);
}
// return list of groups
// return list of groups a member belongs to

string *query_groups(string name) {
  int gi;
  string *names = ({ });
  class group group;

  if (stringp(name)) {
    if ((gi = find_member(name)) == -1)
      return names;

    names = members[gi] -> groups;

    if (arrayp(names))
      return names;
    else
      return ({ });
  }

  foreach (group in groups)
    names += ({ group -> info -> name });

  return names;
} /* query_groups() */