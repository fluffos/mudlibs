/*
// File: format_string.c
// A simul_efun from the wonderful folks at Portals.
// This is now a part of the TMI distribution mudlib.
// Delete header files at own risk.
// Purpose: convert a format such as one used by printf or sprintf 
// into a string with the accompanying variables.
// Vaguely, vaguely resembles sprintf().
// Useful if you did not compile with PRINT_F defined.
*/

// bug fixes 2/3/93 by Ichabod@TMI

string format_string (string format, mixed *variables)
{
   string *tmp, ret;
   string tformat, ts;							// Ichabod 2/3/93
   int i, max;
   int tsize, vsize; 							// Ichabod, 2/3/93
   
   // set up to get proper results from explode...
   tformat = "|" + format + "|%s";				// Ichabod
   tmp = explode (tformat,"%s");				// formerly "explode(format..."
   // remove added chars
   if(tmp[0] == "|")							// Ichabod
   		tmp[0] = "";							//    "
   	else										//    "
   		tmp[0] = extract(tmp[0],1);				//    "
   tsize = sizeof(tmp);							//    "
   if(tmp[tsize-1] == "|") {					//    "
  		tmp[tsize-1] = "";						//    "
  	}											//    "
  	else {										//    "
  	  ts = tmp[tsize-1];						//    "
  	  tmp[tsize-1] = extract(ts,0,strlen(ts)-2);//    "
  	}											//    "
  
   //////if (!tmp || sizeof(tmp) < 2 || !variables)
   if (!tmp || (tsize < 1) || !variables)   	// bug fix
      return format;
   vsize = sizeof(variables);					// Ichabod
   //////if (sizeof(tmp) < sizeof(variables)) max = sizeof(variables);
   //////else max = sizeof(tmp);	
   if (tsize < vsize) max = vsize;				// substitute tsize & vsize
   else max = tsize;
   ret = "";
   for (i = 0 ; i < max; i ++) {
      ////// ret += tmp[i] + variables[i];		// causes out of bounds errs
      if(i < tsize)								// ichabod
      	ret +=  tmp[i];							//    "
      if(i < vsize)								//    "
      	ret += variables[i];					//    "
   }
   return ret;
}
