// room description language (rdl) compiler
// written by Truilkan@TMI - 92/05 
// Modified by Buddha@TMI on 5-14-92 for the room_0.

#include <uid.h>


#ifdef DEBUG
#define BUG(x) tell_object(find_player("buddha"),x);
#else
#define BUG(x)
#endif

#define MY_ROOM "/std/room"

int query_prevent_shadow() { return 1; }

object compile_object(string s) {
   string *lines;
   mapping objects;
   mapping exits;
   mapping items;
   string path, long, short, word, tmp, name, item_name;
   int current, max, l, in_item;
   object robj;

   objects = ([]);
   exits = ([]);
   items = ([]);
   BUG("inside b_server\n");
   s += ".b";
   if (file_size(s) == -1) return 0;
   seteuid(creator_file(s));
   robj = new(MY_ROOM);
   lines = explode(read_file(s),"\n");
   max = sizeof(lines);
   in_item = 0;
   for (current = 0; current < max; ) {
      BUG("line = " + lines[current] + "\n");
      if (word = lines[current])
         sscanf(lines[current],"%s %*s",word);
      switch (word) {
         case "//" : // comment
         break;
         case "}" :
            in_item--;
            item_name = "";
         break;
         case "item:" :
            sscanf(lines[current],"item: %s",item_name);
            current++; // skip the {
            in_item++;
            items[item_name] = allocate_mapping(2);
            break;
         case "object:" :
            if(sscanf(lines[current],"object: %s %s",name,path) == 2)
		objects += ([ name : path ]);
            break;
         case "exit:" :
            if(sscanf(lines[current],"exit: %s %s",name,path) == 2)
            	exits += ([ name : path ]);
            break;
         case "light:" :
            sscanf(lines[current],"light: %d",l);
            robj->set("light", l);
            break;
         case "long:" :
            current++;
            for (long = ""; lines[current] != "**"; current++) {
               long += lines[current] + "\n";
            }
            BUG("setting long: " + long);
            if (!in_item)
               robj->set("long", long);
            else {
               items[item_name]["long"] = long;
            }
            break;
         case "short:" :
            sscanf(lines[current],"short: %s",tmp);
            if (!in_item)
               robj->set("short", tmp);
            else items[item_name]["short"] = tmp;
            break;
         default :
            break;
      }
      current++;
   }
   if (keys(exits)) robj->set("exits", exits);
   if (keys(items)) robj->set("items", items);
   if (keys(objects)) robj->set("objects", objects);
   return robj;
}

