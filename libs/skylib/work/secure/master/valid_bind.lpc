/*  -*- LPC -*-  */

int valid_bind(object binder, object old_owner, object new_owner) {
   string *womble;
   string fname;

   if(binder == find_object("/secure/simul_efun")) {
      return 1;
   }

   if(file_name(new_owner)[0..7] == "/secure/") {
      return 0;
   }

   if(interactive(new_owner)) {
      return 0;
   }
   
   womble = explode(file_name(old_owner), "/");
   if (sizeof(womble) < 1) {
      return 0;
   }
   fname = womble[<1];
   if (fname[0] != '.') {
      return 0;
   }
   return old_owner == binder;
} /* valid_bind() */
