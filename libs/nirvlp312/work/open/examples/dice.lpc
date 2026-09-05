/*
 * Llew coded this.
 */

dice(string str)
{
   int num;
   if (str)
   sscanf(str, "%d", num);
   if (num <= 0) num = 100;
   say(this_player()->query_name()+" rolls a magical "+num+"-sided die.\n");
   write("You roll a magical "+num+"-sided die.\n");
   tell_room(environment(this_player()), "The result is: "+(random(num)+1)+"\n");
   return 1;
}
