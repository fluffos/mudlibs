/*
 * This is the hash table for the locker daemon
 *
 * Diewarzau 7/12/96
 * DarkeLIB 1.0
 */

#inherit "save_items.h"
#define TABLE_SIZE 256
#define BUCKET_SIZE 5

mixed *hash_table = allocate(TABLE_SIZE);

void init_hash_table();
void grow_bucket(int idx);
void save_bucket(int idx);
int hash_index(string filename);
class locker_room find_locker_room(string filename);
void store_locker_room(class locker_room lroom);
void delete_locker_room(string filename);

int hash_index(string filename) {
  int idx;

  if((idx=strsrch(filename, "/", -1)) <= 3) return 0;
  idx++;
  return ((filename[idx] >> 0) + (filename[idx+1] >> 0) +
	  (filename[idx+2] >> 0))%TABLE_SIZE;
}

void store_locker_room(class locker_room lroom) {
  if(!lroom) return;
  int idx = hash_index(lroom->file_name);
  int sz, i;
  int flag = 0;

  if(!hash_table[idx]) {
    hash_table[idx] = allocate(BUCKET_SIZE);
    hash_table[0] = new(class locker_room);
    hash_table[0] = lroom;
    return;
  }
  sz = sizeof(hash_table[idx]);
  if(hash_table[idx][sz-1]) {
    grow_bucket(idx);
    hash_table[idx][sz] = lroom;
    return;
  }
  for(i=0; i < sz; i++) {
    if(hash_table[idx][i]) continue;
    hash_table[idx][i] = lroom;
  }
  return;
}

void delete_locker_room(string filename) {
  int idx = hash_index(filename);
  int sz, newidx = 0;
  class locker_room *newl;

  if(!find_locker_room(filename)) return;
  sz = sizeof(hash_table[idx]);
  if(!sz) return;
  newl = allocate(sz);
  for(i=0;i < sz; i++) {
    if(filename == (class locker_room)(hash_table[idx][i])->file_name)
      continue;
    newl[newidx++] = hash_table[idx][i];
  }
  hash_table[idx] = copy(newl);
  return;
}

class locker_room find_locker_room(string filename) {
  int idx = hash_index(filename);
  int i, sz;

  if(!hash_table[idx]) return 0;
  sz = sizeof(hash_table[idx]);
  for(i=0; i < sz; i++) {
    if(!hash_table[idx][i]) break;
    if(filename == (class locker_room)(hash_table[idx][i])->file_name)
      return hash_table[idx][i];
  }
  return 0;
}

void grow_bucket(int idx) {
  int orig;
  class locker_room *old;

  if(idx >= TABLE_SIZE) return;
  if(!hash_table[idx]) {
    hash_table[idx] = allocate(BUCKET_SIZE);
    return;
  }
  orig = sizeof(hash_table[idx]);
  old = copy(hash_table[idx]);
  hash_table[idx] = allocate(orig + BUCKET_SIZE);
  while(orig--) hash_table[idx][orig] = old[orig];
  return;
}

void init_hash_table() {
  string *dir, item;
  int idx;

  seteuid(UID_SECURE_DAEMONSAVE);
  dir = get_dir(DIR_SECURE_DAEMONS_SAVE+"/locker_bucket_*.v");
  if(!dir || !sizeof(dir)) return;
  dir = map_array(dir, (: $2 + $1 :), DIR_SECURE_DAEMONS_SAVE+"/");
  foreach(item in dir) {
    if(sscanf(item, DIR_SECURE_DAEMONS_SAVE+"/locker_bucket_%d.v", idx) &&
       idx >= TABLE_SIZE) continue;
    hash_table[idx] = restore_variable(read_file(sprintf(DIR_SECURE_DAEMONS_SAVE+"/locker_bucket_%d.v",
							 idx)));
  }
  seteuid(getuid());
  return;
}

void save_bucket(int idx) {
  if(idx > TABLE_SIZE || !hash_table[idx]) return;
  seteuid(UID_SECURE_DAEMONSAVE);
  if(file_exists(sprintf(DIR_SECURE_DAEMONS_SAVE+"/locker_bucket_%d.v", idx)))
    rm(sprintf(DIR_SECURE_DAEMONS_SAVE+"/locker_bucket_%d.v", idx));
  write_file(sprintf(DIR_SECURE_DAEMONS_SAVE+"/locker_bucket_%d.v", idx),
	     save_variable(hash_table[idx]));
  return;
}

	

    
    
    









