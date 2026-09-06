#include <const.h>

main(str) {
   object ob_editor;

   if(this_player()->query_level() < WIZLEVEL) {
      msg("==> [Error] Access denied");
      return;
   }

   if(!str) {
      msg("==> [Format] objedit object");
      return 1;
   }

   ob_editor = clone_object("obj/objedit");
   ob_editor->move(this_player());
   ob_editor->obj_edit(str);

   return 1;
}
