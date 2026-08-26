/*
// File: path_file.c
// From the wonderful people at Portals.
// seteuid(getuid(this_player())) changed to seteuid(geteuid(previous_object()))
// by Pallando on advice from Ellery  930110
*/

mixed *path_file(mixed full_path) {
   mixed *tmp, *dirs;
   int i;

   if(!this_player()) seteuid("TEMP");
   else seteuid(geteuid(previous_object()));

   if(pointerp(full_path)) {
      dirs = allocate(2);
      dirs[0] = ({ });
      dirs[1] = ({ });
      for(i = 0; i < sizeof(full_path); i++) {
         tmp = path_file(full_path[i]);
         dirs[0] = dirs[0] + ({ tmp[0] });
         dirs[1] = dirs[1] + ({ tmp[1] });
      }
      return dirs;
   }

   if(full_path == "/")
      return ({ "/","" });

   if(file_size(full_path) == -2)
      return ({ full_path, "" });
   dirs = explode(full_path,"/");
  tmp = dirs[0..<2];
   return ({ "/" + implode(tmp,"/"), dirs[sizeof(dirs) - 1] });
}
