/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE:
//
//     |  ``locate <target>``
//     |  ``locate -u``
//
// Find any file containing the specified target within its name.
//
// The system relies on a database of filenames for speed.
// To rebuild that database, use a -u flag.
//
// .. TAGS: RST

inherit CMD;

// ************ Wizard info *************
// If you are receiving warnings or errors, reduce this value to a smaller value.
// This will, however, increase the time taken to rebuild the database.
#define ITERS_PER_CALL 50

// Do not touch these.
#define DATA_FILE "/data/locate.codes"
#define TMP_DATA_FILE "/data/locate.tmp"

mixed *stack;
string path;
int building_database = 0;
int started_at;

private
void end_building()
{
   cp(TMP_DATA_FILE, DATA_FILE);
   rm(TMP_DATA_FILE);
   printf("Locate DB build done in " + time_to_string(time() - started_at) + ".\n");
   building_database = 0;
}

private
void rebuild_locate_db()
{
   int i = ITERS_PER_CALL;
   string *this_dir;

   while (i--)
   {
      string new_path;

      if (!sizeof(stack))
      {
         end_building();
         return;
      }

      if (intp(stack[0]))
      {
         /* hit the sentinel. pop up one directory level */
         stack = stack[1..];
         path = split_path(path)[0];
         i++;
         continue;
      }

      new_path = path + stack[0] + "/";
      stack = stack[1..];
      this_dir = get_dir(new_path + "*", -1);

      if (arrayp(this_dir))
      {
         int w;

         if ((w = member_array(".", get_dir(new_path + "*"))) != -1)
            this_dir = this_dir[0..(w - 1)] + this_dir[(w + 2)..];
      }
      else
         continue;

      /* prepend the dir and write into the file */
      map(this_dir, ( : write_file(TMP_DATA_FILE, join_path($(new_path), $1[0]) + "\n") :));

      /* filter out just the dirs and extract the names */
      this_dir = map(filter(this_dir, ( : $1[1] == -2 :)), ( : $1[0] :));

      /* push onto stack w/ a sentinel to go up the dir tree */
      if (sizeof(this_dir))
      {
         stack = this_dir + ({0}) + stack;
         path = new_path;
      }
   }

   // If your players complain when you run the 'locate -u' command, increase this value to 2 or even 3.
   call_out(( : rebuild_locate_db:), 1);
}

private
void begin_database_build()
{
   stack = ({""});
   path = "";
   if (is_file(TMP_DATA_FILE) && !rm(TMP_DATA_FILE))
   {
      out("You don't have permission to do that.\n");
      return;
   }
   rebuild_locate_db();
   building_database = 1;
}

private
void main(mixed *arg, mapping flags)
{
   string find;
   string outstr;

   if (!arg[0] && !flags["u"])
   {
      out("Syntax: locate <string>\n" + "        locate -u (to update the database)");
      return;
   }
   if (flags["u"])
   {
      if (building_database)
      {
         out("Already building database.\n");
         return;
      }
      out("Building database... This can take a while for large MUDs.\n");
      started_at = time();
      begin_database_build();
      return;
   }
   else
   {
      /* arg[0] is an array of strings. use just the first */
      find = arg[0];
      ed_start(DATA_FILE);
      outstr = ed_cmd(sprintf("1,$g#%s#p", find));
      if (!sizeof(outstr))
         out("No matching files found.\n");
      else
         out(outstr);
      ed_cmd("q");
      return;
   }
}
