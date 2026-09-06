#include <const.h>

int main( string param ) {
   object tree;
   string *tree_types = ({ "appletree", "bananatree", "cherrytree",
                           "coconuttree", "lemontree", "olivetree", "orangetree",
                           "pine", "plumtree" });
   string current_type;
   int count = 0;

   /**Do each tree by itself**/
   foreach( current_type : tree_types ) {
      foreach(tree : all_clones("/econ/trees/"+current_type)) {
         if(environment(environment(tree))->query_is_building()) {
            destruct(tree);
            count++;
         }
      }
   }
   debug("Invalid trees killed: " + count);
   return 1;
}
