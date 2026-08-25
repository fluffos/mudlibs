/* Do not remove the headers from this file! see /USAGE for more info. */

inherit __DIR__ "scr_command";

private
void main(string *args)
{
   string brief = implode(args, " ");
   string fname;

   if (!(fname = get_file_name()))
      return;
   if (change_attribute(fname, "brief", brief))
      write("Done.\n");
   update(fname);
}
