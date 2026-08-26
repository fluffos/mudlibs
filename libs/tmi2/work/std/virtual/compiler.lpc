/*
 * compiler.c [virtual object compiler]
 * description: a generic object description language parser.  This is meant
 *              to be the base object that other ODL compilers inherit from.
 * history:
 *    07/01/92 [huthar] - created
 *    12/08/92 [wayfarer] - cleaned up, added // comment support
 *                          multiple line variables, subgroups
 *    12/09/92 [wayfarer] - bug fixing for items, objects, etc.
 *    12/10/92 [wayfarer] - allowed a non-fixed base object to be used
 */

// history: this object comes from the Portals mudlib.  It is a nice
// abstraction of the room description language originally done by Truilkan.

#undef DEBUG

#include <config.h>
#include <uid.h>

private nosave string opcode, error_string;
private nosave int line_done;
private nosave object target;
nosave string subgroup, filename;
#define YES 1
#define NO 0

void end_subgroup()
{
  string fun;
  if (subgroup)
    {
      fun = subgroup+"_done";
      call_other (this_object(), fun);
    }
}

string parse_line (string line)
{
  string op, val;
  int i;
  
  if (!line || line[0] == '#' || line == "" || line[0..1] == "//")
    return "";
  
  if (sscanf(line, "%s: %s",op,val) == 2)
    {
       opcode = op;
       line_done = YES;
    }
  else if (sscanf(line, "%s:",op) == 1)
    {
      opcode = op;
      line_done = NO;
      return "";
    }
  else
    {
      val = line;
      if (line_done)
	line_done = NO;
      if (val[0..1] == "**" || val == "." || val == "---")
	{
	  line_done = YES;
	  return "";
	}
      else if (val == "{")
	{
	  if (!subgroup)
	    {
	      subgroup = opcode;
	      return "";
	    }
	  else
	    {
	      error_string = "Can't have multiply nested subgroups.";
	      return 0;
	    }
	}
      else if (val == "}")
	{
	  if (subgroup)
	    {
	      end_subgroup();
	      subgroup = NO;
	      opcode = NO;
	      line_done = YES;
	      return "";
	    }
	  else
	    {
	      error_string = "End subgroup found when no subgroup started.";
	      return 0;
	    }
	}
      else
	val += "\n";

    }
  
  for(i = 0; i < strlen(val); i++)
    if(i != ' ' && i != '\t')
      break;
  
  if(i == strlen(val))
    {
      opcode = op;
      line_done = NO;
      return "";
    }
  
  return val[i .. -1];
}

void set_target(object ob)
{
   target = ob;
   ob->set_file_name (filename);
}

object query_target()
{
   return target;
}


int make_target (string name)
{
  object ob;
  
  if (!name)
     name = (string)this_object()->default_base_object();
  if (name)
  {
     seteuid(creator_file(filename));
     ob = new (name);
     set_target(ob);
  }
  if (!target)
     return 0;
  export_uid(target);
  return 1;
}

void error (string val)
{
  write (val);
  if (target)
     target->remove();
}

object compile_object (string file)
{
  string *lines;
  string tmp, value, ret;
  int i;
 
  file = file + (string)this_object()->extension();
  if (file_size(file) == -1)
  {
    write ("No such file or directory: "+ file + "\n");
    return 0;
  }
  seteuid(ROOT_UID);
  tmp = read_file("/"+file);
  if(!tmp || tmp == "")
  {
    write ("File is empty: "+ file + "\n");
    return 0;
  }
  lines = explode(tmp,"\n");

  target = 0;
  filename = file;
  subgroup = NO;
  error_string = 0;

  for(i = 0; i < sizeof(lines); i++)
    {
      line_done = YES;
      value = "";
      tmp = parse_line(lines[i]);
      if (tmp == 0)
	{
	  error ("Error Compiling '"+filename+"': "+error_string+"\n");
	  return 0;
	}
      if ((tmp == "") && line_done)
        continue;
      value = tmp;
      while (line_done == NO)
	{
	  if (i >= (sizeof(lines)-1))
	    break;
	  value += parse_line(lines[++i]);
	}
      if(!opcode)
	{
	  error("Error Compiling '"+filename+"': Opcode missing in line #"+i+"\n");
	  return 0;
	}
      if (subgroup)
	opcode = subgroup + "_" + opcode;
#ifdef DEBUG
      printf ("<final> %s = %s\n",opcode,value);
#endif
      if (!target && opcode != "base_object")
        {
	  if (!make_target(0))
	  {
     	     error ("Error Compiling '"+filename+"': No base object defined.\n");
	     return 0;
	  }
	}
      switch(call_other(this_object(),opcode,value,target))
	{
	case 0:
	  write("Warning Compiling '"+filename+"': Unknown opcode '"+opcode+
		"' in line #"+i+"\n");
	  break;
	case 2:                // Fatal Compile Error
	  error("Fatal compile error: " + filename + "\n");
	  return 0;
	  break;
	}
    }
  if (function_exists("compilation_finished",this_object()) &&
    	!((int)this_object()->compilation_finished()))
    return 0;
  
  return target;
}

/*
 * no shadowing of ODL compilers!
 */
int query_prevent_shadow ()
{
  return 1;
}
