/* teleportation error object  - Mythos <12-3-97>
    file containing the list of room paths is /open/TELE_ERR
    <note: there are default error rooms in case file is wiped
*/

#define FILE "/open/TELE_ERR"
#define DEF 10
/* used to be 10-15% failure */
#define FAIL_PERCENTAGE 5 + random(6)     /* we boosted the cost.  5-10% failure [v] */
string path;
int num_path;

reset(arg) {
  if(arg) return;
  if(!read_file(FILE)) {
    path = allocate(DEF);
    num_path = DEF;
    pathset();
  } else {
    setting();
  }
call_out("check",1);
}

check() {
  if(environment(this_object())) destruct(this_object());
return 1; }

pathset() {
   path[0] = "room/shop";
   path[1] = "room/church";
   path[2] = "room/slope";
   path[3] = "room/mount_pass";
   path[4] = "room/farmroad1";
   path[5] = "room/sea";
   path[6] = "room/inn";
   path[7] = "room/fortress";
   path[8] = "room/path1";
   path[9] = "room/big_tree";
}

setting() {
  string reader;
  int h;
  reader = explode(read_file(FILE),"\n");
  num_path = DEF + sizeof(reader);   /*number of paths */
  path = allocate(num_path);
  pathset();
  for(h = 0;h<sizeof(reader);h++)
    path[(DEF - 1) + h] = reader[h];

}

/* function to call when doing a teleport */

teleport() {
   if(random(100) < FAIL_PERCENTAGE) return path[random(num_path)];
   return 0;
}

/* thus to do a teleport one does the following:
     string where;
     if(where = call_other("obj/base_tele","teleport"))
               teleportingobject->move_player("with an astonished look#"+where);
    else teleport_ok_code;
*/

