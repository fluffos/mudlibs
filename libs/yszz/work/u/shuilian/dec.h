
string direction_name(string);
string direction_rev(string);
string direction_name(string arg)
{
   if ( arg == "east" ) return "东面";
   else if ( arg == "west" ) return "西面";
   else if ( arg == "south" ) return "南面";
   else if ( arg == "north" ) return "北面";
   else return "不知道哪儿";
}

string direction_rev(string arg)
{
   if ( arg == "east" ) return "西面";
   else if ( arg == "west" ) return "东面";
   else if ( arg == "south" ) return "北面";
   else if ( arg == "north" ) return "南面";
   else return "不知道哪儿";
}
