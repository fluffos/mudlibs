/* Note: The finger daemon truncates titles to 10 characters */

/// \return The generic title for a given player/wizard level
string query_title(int level) {
// if you change this, please update finger.php
  switch (level) {
    case 0..2:     return "Newbie";
    case 3..8:     return "Novice";
    case 9..15:    return "Explorer";
    case 16..25:   return "Adventurer";
    case 26..50:   return "Hero";
    case 51..89:   return "Legend";
    case 90..99:   return "Ancient";
    case 100:      return "Apprentice";
    case 101..109: return "Neophyte";
    case 500..749: return "Archwizard";
    case 750..999: return "Master Wiz";
    case 1000:     return "Mudlib Wiz";
    default:       return "Wizard";
  }
  return "?";
}

/** \return The specific title for a particular player or wizard
 * \note Things poop and die if you try to query info off of a player who
 * is not logged in because of the way we load things up to finger
 * them, SO it is imperative that you pass a name, level, and job
 * title string if you want this function to work when dealing with
 * players who find rl more important than the mud (faithless..)
 */
varargs string query_personal_title(object who,string name,int level,string job) {
// if you change this, please update finger.php
  if (!name) {
    name = who->query_name();
    job = who->query_job_title();
    level = who->query_level();
  }
  switch (name) {
  }
  if (job && job != "none")
    return (job);
  return query_title(level);
}
