/* move_tracker.c
 *
 * global object for tracking the direction pkillers used
 * to leave rooms recently
 * by illarion@nirvana
 * suggested by fred
 */

#define TIME_LIMIT 60
 
mapping blood_locations;

reset() {
  /* clean out the mapping every reset so it doesn't get too huge */
  blood_locations=([]);
}

add_blood(string location) {
  blood_locations[location]=time();
}

check_blood(string location) {
  if(blood_locations[location]
  && time() < blood_locations[location]+TIME_LIMIT)
    return 1;
  return 0;
}