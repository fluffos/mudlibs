// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;

void setup()
{
  set_unit("条");
  set_id("river", "小河", "water");
  set_long(
"一条小河由东而来，缓缓地流向西去。它不很深，要淌过它去北方不是个问题。\n");
  set_size(TOO_LARGE);
set_flag(ATTACHED);
}

mixed swim()
{

  this_body()->simple_action("$N在河里游了一会儿。\n"
                             "当$n爬上岸时，洞地忽然震动了一下。");
  call_out((: environment(this_object())->open_passage() :), 3);
  return 1;
}

mixed wade()
{
  this_body()->simple_action("$N在河里淌了一会儿水。\n"
                             "当$n上岸时，洞地忽然震动了一下。");
  call_out((: environment(this_object())->open_passage() :), 3);
  return 1;
}


