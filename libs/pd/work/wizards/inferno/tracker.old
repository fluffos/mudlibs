static object *ob = ({ });
mapping bob = ([ "test" : "quit" ]);

void add_tower(object o) { ob += ({ o }); }

// void save_me() { save_object("/wizards/inferno/forest/mine"); }

void clean_tower() {
   int i;
   i = sizeof(ob);
   while (i--) {
    if (ob[i])
     ob[i]->remove();
   }
   ob = ({ });
}

object *query_towers() { return ob; }
