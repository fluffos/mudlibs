/*
 * This file will hold the deprecated efuns that LD does not recognize.
 * Add code to convert old efuns into the new syntax here for compatibility
 * with the LDMud driver
 * -- Rumplemintz
 */

//---------------------------------------------------------------------------
/* member_array has been changed to member */
int member_array(mixed item, mixed *arr) {
  return member(arr, item);
}

//---------------------------------------------------------------------------
/* file_name has been changed to object_name */
string file_name(object ob) { return object_name(ob); }

//---------------------------------------------------------------------------
/* basename should be changed to use load_name */
string basename(object ob) { return load_name(ob); }

