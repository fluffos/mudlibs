#include <ansi.h>
/******************************************************************************
 * Program: map_test.c
 * Path: /open/dragnar
 * Type: Obj
 * Created: Oct 8th, 2015 by Dragnar
 *
 * Purpose: A tool to help wizards learn arrays and mappings. 
 * History:
 *          10/08/2015 - Dragnar
 *            Created
 ******************************************************************************/

/** Mapping for skills **/
mapping skills_m;

/** Two arrays to track skills **/
int *skill_values;
string *skill_types;

/** One array to track skills **/
mixed *skills_a;

id(string str) {

   return str == "test" || str == "mapping test";
}

short() { return "Mapping Test"; }

long() {
  write("Type test to run it, set to change the values.\n");
}

init() {
  add_action("test","test");
  add_action("set","set");
}

reset() {

  /** Mapping **/
  skills_m = ([ "Earth" : 0
               ,"Wind"  : 0
               ,"Water" : 0 
               ,"Fire"  : 0 ]);

  /** Store as two arrays **/
  skill_types = ({ "Earth", "Wind", "Water", "Fire" });
  skill_values = ({ 0, 0, 0, 0 });

  /** Store as a single array **/
  skills_a = ({ "Earth", 0, "Wind", 0, "Water", 0, "Fire", 0 });
}

set( string str ) {
  int amt, idx;
  string skill;

  if(!str) {
    write("What skill do you want to set?\n");
    return 1;
  }

  if( sscanf(str, "%s %d", skill, amt) != 2 ) {
    write("set <skill> <amount>\n");
    return 1;
  }
  skill = capitalize(skill);
  
  /** Easy to set the mapping **/
  skills_m[ skill ] = amt;

  /** Double Array - find the index it is stored at **/
  idx = member( skill_types, skill );
  /** Now set the value of same index in the skill value array **/
  if( idx >= 0 ) {
    skill_values[idx] = amt; 
  }
  else {
    write("Error setting skill amount.\n");
    return 1;
  }

  /** Single Array - first need to determine index **/
  idx = member( skills_a, skill );
  /** Now set the value of the next index **/
  if( idx >= 0 ) {
    skills_a[idx + 1 ] = amt; 
  }
  else {
    write("Error setting skill amount.\n");
    return 1;
  }
  return 1;
}

test() {
  int i;
  string *mapping_skills;

  /** Mapping **/
  write(HIW+"Mapping:\n");
  mapping_skills = m_indices( skills_m );
  for( i=0; i < sizeof(mapping_skills); i++ )
    write( "\t" + mapping_skills[i] + ": " +skills_m[ mapping_skills[i] ]+ "\n");
  write(NORM+"\n");

  /** Double Array **/
  write(HIG+"Double array: \n" );
  for( i=0; i < sizeof(skills_a); i += 2 )
    write( "\t" + skills_a[i] + ": " +skills_a[i+1] + "\n");
  write( NORM+"\n" );

  /** Single Array **/
  write(HIR+"Single array: \n");
  for( i=0; i < sizeof(skill_values); i++ ) 
    write( "\t" + skill_types[i] + ": " +skill_values[i] + "\n");
  write( NORM+"\n" );

  
  return 1;
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
