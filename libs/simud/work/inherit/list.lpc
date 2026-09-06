/** A largely obsolete object, but it is still used in some
 * places. This was designed to overcome LPC's ancient problem
 * of not handling arrays -- if that gives you an idea of how
 * old this code is. It allows you to handle a \\n delimited string as
 * if it were a list. With newer versions of the driver,
 * and ever improving array management, this has become far
 * less critical (this was written first in '96?), but it
 * still finds its uses (the object editor still uses this
 * method for getting variable lists, for example).
 */

int list_size(string list) {
//  int i, count;
//  if(!list || list == "") return 0;
//  count = 0;
//  for(i=0;i<strlen(list);i++) if(list[i]=='\n') count++;
//  return count+1;
   return sizeof( explode(list, "\n") );
}

string *list_to_array(string list) {
//   string *arr;
//   string head;
//   int count, i;

//   count = list_size( list );
//   arr = allocate( count );
//   for( i = 0; i < count - 1; i++ ) {
//      sscanf( list, "%s\n%s", head, list );
//      arr[i] = head;
//   }
//   arr[count - 1] = list;
//   return arr;
   return explode( list, "\n" );
}

string *split_string_by_name(string name, string list) {
   string beginning, middle, end;

   end=list;
   beginning="";
   middle="";
   while(end != 0 && end != "" && middle != name) {
      if(beginning != "") beginning += "\n";
      beginning += middle;

      if(sscanf(end, "%s\n%s", middle, end) != 2) {
         if(end == name) middle = end;
         else {
            if(beginning != "") beginning += "\n";
            beginning += end;
         }
         end = "";
      }
   }
   return ({ beginning, middle, end });
}


string *split_string_by_number(int index, string list) {
   string beginning, middle, end;
   string *arr;
/*
   int i;

   end=list;
   beginning="";
   middle="";
   i=0;

   if(list_size(list) == 1) {
      if(index == 1) return ({ "", list, "" });
      else return ({ list, "", "" });
   }

   while(end != 0 && end != "" && i < index) {
      if(beginning != "") beginning += "\n";
      beginning += middle;

      i++;
      if(sscanf(end, "%s\n%s", middle, end) != 2) {
         if(i == index) middle = end;
         else beginning += "\n" + end;
         end = "";
      }
   }

   return ({ beginning, middle, end });
*/
   arr = explode( list, "\n" );
   if( index == 0 ) beginning = "";
   else beginning = implode(arr[..index-1], "\n");
   middle = arr[index];
   end = implode(arr[index+1..], "\n");
   return ({ beginning, middle, end });
}

string get_item(int index, string list) {
   string *split_list;

//   split_list = split_string_by_number(index, list);
//   return split_list[1];
   split_list = explode(list, "\n");
   if( index >= 0 && index < sizeof(split_list) ) return split_list[index];
   else return 0;
}


int get_pos(string what, string list) {
   string *split_list;

   split_list = split_string_by_name(what, list);

   if(split_list[1] == "") return -1;
   return list_size(split_list[0]) + 1;
}

string add(string what, string list) {
   if(!list)list="";
   if(list != "") list += "\n";
   list += what;
   return list;
}

string add_before(string what, string list) {
   if(!list)list="";
   if(list != "") list = "\n" + list;
   list = what + list;
   return list;
}

string delete_string(string what, string list) {
   string *split_list;

   split_list = split_string_by_name(what, list);
   if(split_list[1] != what) return list;

   if(split_list[0] == "") return split_list[2];
   if(split_list[2] == "") return split_list[0];
   return split_list[0] + "\n" + split_list[2];
}

string delete_num(int which, string list) {
   string *split_list;

   split_list = split_string_by_number(which, list);

   if(split_list[0] == "") return split_list[2];
   if(split_list[2] == "") return split_list[0];
   return split_list[0] + "\n" + split_list[2];
}

string insert_before_string(string what, string list, string addme) {
   string *split_list;

   split_list = split_string_by_name(what, list);
   if(split_list[1] != what) return addme + "\n" + list;

   if(split_list[0] == "") return addme + "\n" + split_list[1] + "\n" + split_list[2];
   if(split_list[2] == "") return split_list[0] + "\n" + addme + "\n" + split_list[1];
   return split_list[0] + "\n" + addme + "\n" + split_list[1] + "\n" + split_list[2];
}

string insert_after_string(string what, string list, string addme) {
   string *split_list;

   split_list = split_string_by_name(what, list);
   if(split_list[1] != what) return list + "\n" + addme;

   if(split_list[0] == "") return split_list[1] + "\n" + addme + "\n" + split_list[2];
   if(split_list[2] == "") return split_list[0] + "\n" + split_list[1] + "\n" + addme;
   return split_list[0] + "\n" + split_list[1] + "\n" + addme + "\n" + split_list[2];
}

string insert_before_num(int which, string list, string addme) {
   string *split_list;

   split_list = split_string_by_number(which, list);

   if(split_list[0] == "") return addme + "\n" + split_list[1] + "\n" + split_list[2];
   if(split_list[2] == "") return split_list[0] + "\n" + addme + "\n" + split_list[1];
   return split_list[0] + "\n" + addme + "\n" + split_list[1] + "\n" + split_list[2];
}

string insert_after_num(int which, string list, string addme) {
   string *split_list;

   split_list = split_string_by_number(which, list);

   if(split_list[0] == "") return split_list[1] + "\n" + addme + "\n" + split_list[2];
   if(split_list[2] == "") return split_list[0] + "\n" + split_list[1] + "\n" + addme;
   return split_list[0] + "\n" + split_list[1] + "\n" + addme + "\n" + split_list[2];
}


void call_each(string list, string funcname) {
   string curr;

   if(!list || list == "")return;

   while(1) {
      if(sscanf(list, "%s\n%s", curr, list) == 2)
         call_other(this_object(), funcname, curr);
      else {
         call_other(this_object(), funcname, list);
         break;
      }
   }
}

void call_out_each(string list, string funcname, int delay) {
   string curr;

   if(list == "" || !list) return;

   while(1) {
      if(sscanf(list, "%s\n%s", curr, list) == 2)
         call_out(funcname, delay, curr);
      else {
         call_out(funcname, delay, list);
         break;
      }
   }
}
