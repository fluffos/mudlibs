// Altered by pallando to take into account that you won't always
// have a this_player()   920114

varargs void shout(string msg, mixed exclude)
{
   if (objectp(exclude))
      exclude = ({ exclude });
   else if (!pointerp(exclude))
      exclude = ({ });
   if (this_player())
      exclude += ({ this_player() });
   message("shout", msg, users(), exclude);
}
