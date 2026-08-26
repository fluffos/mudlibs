/*
// Thanks to the folks at Portals for this one...
// Author: Huthar@Portals, TMI
// This file is now a part of the TMI distribution mudlib.
// Depth Indenting and better managment of ending \n's Done by Qixx@Hero
// NB is similar to the identify simul_efun, except for different formatting
//    and does not handle function variables
*/


varargs string dump_variable(mixed arg, int indent)
{
   mixed *index;
   string rtn;
	string spaces;
   int i;
   
	if (indent) spaces="\t\t\t\t\t\t\t\t\t\t\t\t\t"[0..indent-1];
	else spaces="";
	rtn="";
   if(objectp(arg))
      return "("+file_name(arg)+")";
   
   if(stringp(arg))
		return "\""+arg+"\"";
   
   if(intp(arg))
      return "#"+arg;
   
   if(pointerp(arg))
   {
	if (indent==0)
	rtn = "ARRAY:";
      
      for(i = 0; i < sizeof(arg); i++)
	{
		rtn+="\n";
	rtn+=spaces;
		rtn+="["+i+"] == "+dump_variable(arg[i],indent+1);
	}
      
      return rtn;
   }

   if(mapp(arg))
   {
	if (indent==0)
	rtn="MAPPING:";

      index = keys(arg);

      for(i = 0; i < sizeof(index); i++)
		{
		rtn +="\n";
		rtn+=spaces;
		rtn+="["+dump_variable(index[i],0)+"] == "+dump_variable(arg[index[i]],indent+1);
		}

      return rtn;
   }
   if (floatp(arg)) {
      return "%"+arg ;
   }
   return "UNKNOWN";
}
