// Last edited by deforce on 04-27-2010
inherit OBJ;

int last_search_time = 0;

void setup()
{
   set_id("box");
   set_long("This box looks like it contains ship parts.  Perhaps you could search it without anyone noticing.");
   set_attached(1);
}

void do_search()
{
   object guard = present("ship parts box guard");

   if (guard)
   {
      guard->do_game_command("say Hey, don't take anything from that box!");
   }
   else
   {
      object player = previous_object(1);

      if ((time() - last_search_time) > 3600)
      {
         last_search_time = time();

         player->simple_action("$N $vsearch through the box and $vfind some ship parts.");

         new("/d/obj/toolbox", ([ "ship" : 10 + random(11) ]))->move(player);
      }
      else
      {
         player->simple_action("$N $vsearch through the box and $vfind nothing but packing materials.");
      }
   }
}