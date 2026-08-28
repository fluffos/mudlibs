int
main (string str)
{
   string receivers, spam, *rec;
   
   if (!str)
	 return 1;
   
   sscanf (str, "%s %s", receivers, spam);
   
   rec = explode(receivers, ",");
   
   for (int i=0;i<sizeof(rec);i++)
	 tell_object (find_player (rec[i]), spam + "\n");
   
   return 1;
}
