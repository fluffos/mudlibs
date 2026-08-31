/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** materials.c -- material command
**
*/

//: PLAYERCOMMAND
//$$ see: skills, hp, stats,score
// USAGE
//
//  |  ``materials``
//  |  ``materials all`` - show all materials on the MUD
//
// Shows your materials and all the materials in it.
//
// .. TAGS: RST

inherit CMD;
inherit M_FRAME;

private
void main(string arg)
{
   mapping p_materials = this_body()->query_materials();
   string *mat_cats = CRAFTING_D->query_material_categories();
   string acc;
   int per_row;
   int total_count;
   int widest_category, width;
   int longest_mat = CRAFTING_D->query_longest_mat();
   string content = "", header = "";

   if (!sizeof(mat_cats))
   {
      write("No materials defined, yet.\n");
      return;
   }

   frame_init_user();
   acc = "<" + raw_accent() + ">";
   foreach (string category in mat_cats)
      if (strlen(category) > widest_category)
         widest_category = strlen(category);

   width = this_user()->query_screen_width() - widest_category;
   per_row = width / (longest_mat + 8);

   foreach (string category in mat_cats)
   {
      string *mats = CRAFTING_D->query_materials(category);
      string mat_line = "";
      int line = 0;
      int count = 0;
      int line_count = 1;
      foreach (string mat in mats)
      {
         if (member_array(mat, keys(p_materials)) != -1)
         {
            count++;
            total_count++;
         }
         mat_line += sprintf("%" + longest_mat + "." + longest_mat + "s: " + acc + "%-3.3s<res> ", capitalize(mat),
                             "" + (p_materials[mat] ? p_materials[mat] : ""));
         line++;

         // Out of items for this line, but are we done?
         if (line == per_row && member_array(mat, mats) != (sizeof(mats) - 1))
         {
            mat_line += "\n";
            line = 0;
            line_count++;
         }
      }
      if (line != 0)
      {
         mat_line += "\n\n";
         line_count++;
      }
      if (count || arg == "all")
      {
         header += capitalize(category) + repeat_string("\n", line_count);
         content += mat_line;
      }
   }

   set_frame_title("Materials - " + total_count + "/" + CRAFTING_D->count_materials());
   set_frame_left_header(); // This frame will use left header
   if (strlen(header) == 0)
      header = "None";
   if (!arg || arg != "all")
      content += "Use 'materials all' to see all materials on " + mud_name() + ".";
   set_frame_content(content);
   set_frame_header(header);
   out(frame_render());
}
