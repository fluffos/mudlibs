// shimo.c 石磨
inherit OBJ;
void setup()
{
  set_unit("个");
  set_id("shimo","石磨", "miller");
  set_long("一个农家用来磨米磨面的石磨，看上去和其它的石磨没什么不同。
但当你仔细观察，便发觉似乎可以挪动（ｐｕｓｈ）。\n\n");
   set_in_room_desc("一个农家用来磨米磨面的石磨。(shimo)\n\n");
}
int press(string s)
{
  if((s=="shimo")||(s=="石磨")||(s=="miller"))
  { environment(this_object())->open_cave();
        return 1;
}
        else
                return 0;
}
