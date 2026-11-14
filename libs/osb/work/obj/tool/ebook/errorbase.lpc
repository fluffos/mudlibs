/*
** Book of Errors
** Error-Database
** Author: Thragor@Nightfall, 19jun96
** Update:
*/

#define REMERR "RememberErrors"
#define RETFUN "ReturnFunction"

#include "ebook.h"

inherit "/lib/string";

public mapping Perrors,Pprops;
// ([<error>:<explanation>])
public string *Punresolved;

private void Set(mixed what,mixed value)
{
  Pprops = Pprops||([]);
  Pprops[what]=value;
}

private mixed Query(mixed what)
{
  return (Pprops||([]))[what];
}

private void LoadBase()
{
  if (Perrors) return;
  if (file_size(ERRORBASE+".o")<1) return;
  seteuid(getuid());
  restore_object(ERRORBASE);
  seteuid(0);
}

private void SaveBase()
{
  seteuid(getuid());
  save_object(ERRORBASE);
  seteuid(0);
}

public string *SetUnresolved(string *s)
{
  if (!TP||!IS_WIZARD(TP)) return 0;
  Punresolved = s;
  SaveBase();
  return Punresolved;
}

public string *QueryUnresolved()
{
  LoadBase();
  return (Punresolved||({}))+({});
}
  
public string *AddUnresolved(string err)
{
  string *unresolved;
  unresolved = QueryUnresolved();
  unresolved-=({err});
  unresolved+=({err});
  return SetUnresolved(unresolved);
}

public string *RemoveUnresolved(string err)
{
  string *unresolved;
  unresolved = QueryUnresolved();
  unresolved-=({err});
  return SetUnresolved(unresolved);
}

public mapping SetErrors(mapping m)
{
  if (!TP||!IS_WIZARD(TP)) return 0;
  Perrors = m;
  SaveBase();
  return Perrors;
}

public mapping QueryErrors()
{
  LoadBase();
  return (Perrors||([]))+([]);
}

public mapping AddError(string error,string descr)
{
  mapping errors;
  errors = QueryErrors();
  errors[error]=descr;
  RemoveUnresolved(error);
  return SetErrors(errors);
}

public mapping RemoveError(string error)
{
  mapping errors;
  errors = QueryErrors();
  m_delete(errors,error);
  return SetErrors(errors);
}

private string check_special(string err)
{
  string s1,s2;
  if (sscanf(err,"%s tried to load %s",s1,s2)==2)
    return wrap(sprintf("%s tried to access %s in some way, e. g. it tried to move into it "
			"or did a call_other() to that object (also check for "
			"load_object!).\n"
			"To remove this error you first should check, if the file %s "
			"is existing and if it can be compiled without any error.\n",
			s1,s2,s2));
  if (sscanf(err,"Variable %s not declared !",s1))
    return wrap("Most of the time you just forgot to declare a variable at "
		"the head of the function or at the head of the file (if it is a global "
		"variable. This error may also occur when you forgot to #include "
		"some defines (or actually forgot to use #define). E. g. if something "
		"like P_xxx is not declared you obviously forgot to "
		"#include <properties.h>.\n");
  return 0;
}

private string explain_err(string err)
{
  mapping errors;
  string descr;
  errors = QueryErrors();
  if (!member(errors,err))
    {
      if (!descr = check_special(err))
	{
	  AddUnresolved(err);
	  descr = "Error not found in database. Will be stored as unresolved error.\n";
	}
    }
  else
    descr = errors[err];
  return err+"\n"+mkstr(strlen(err),"-")+"\n\n"+descr+"\n";
}

public varargs void wait(string fasel,int prompt,closure function,mixed args)
{
  if (!TP) return;
  if (prompt)
    {
      write("\n--- Press ENTER to continue...");
      input_to("wait",0,0,function,args);
      return;
    }
  write("\n");
  if (pointerp(args))
    apply(function,args);
  else
    funcall(function,args);
}

public void end_help()
{
  wait("",1,TP->Query(RETFUN));
}

public varargs void print_help(string *errs,string function,object po)
{
  string text;
  if (!TP) return;
  if (!po) po = previous_object();
  errs = map(errs,SF(explain_err));
  text = implode(errs,"\n\n");
  TP->Set(RETFUN,symbol_function(function,po));
  smore(text,TP->QueryPageSize(),ME,"end_help");
}

private status check_line(int line,mixed data)
{
  if (line<1||line>sizeof(data)+1)
    {
      write("Number out of range.\n\n");
      return 0;
    }
  return 1;
}

public void edit_err_done(string text,string error)
{
  if (!TP||!text) return;
  RemoveUnresolved(error);
  AddError(error,text);
  funcall(TP->Query(RETFUN));
}

private void edit_err(string error)
{
  write("Description of "+error+":\n\n");
  input_text(SF(edit_err_done),({error}),QueryErrors()[error]);
}

public void edit_unresolved();

public void unresolved_command(string cmd)
{
  int line;
  if (!TP) return;
  write("\n");
  if (cmd=="?")
    {
      write("Unresolved-Edit, Commands:\n\n"
	    "<nr>   Create a description for this error.\n"
	    "d<nr> Delete the error.\n"
	    "q        Quit editting.\n"
	    "?        This help.\n\n");
      return edit_unresolved();
    }
  if (sscanf(cmd,"%d",line))
    if (!check_line(line,QueryUnresolved())) return edit_unresolved();
    else
      {
	TP->Set(RETFUN,SF(edit_unresolved));
	return edit_err(QueryUnresolved()[line-1]);
      }
  if (sscanf(cmd,"d%d",line))
    if (!check_line(line,QueryUnresolved())) return edit_unresolved();
    else
      {
	RemoveUnresolved(QueryUnresolved()[line-1]);
	write("Deleted.\n\n");
	return edit_unresolved();
      }
  if (cmd=="q")
    {
      write("Unresolved-Edit ended.\n\n");
      return;
    }
  write("--- !!! Unknown command!\n");
  edit_unresolved();
}

public void unresolved_prompt()
{
  write("\nUnresolved Errors [<nr>, d<nr>, q, ?] ");
  input_to("unresolved_command");
}

public void edit_unresolved()
{
  string *unresolved,text;
  int i;
  if (!TP) return;
  unresolved = QueryUnresolved();
  unresolved = sort_array(unresolved,SF(>));
  SetUnresolved(unresolved);
  text = "Unresolved error-messages\n";
  text+= mkstr(strlen(text)-1,"-")+"\n\n";
  for(i=0;i<sizeof(unresolved);i++)
    text+=sprintf("%02d. %s\n",i+1,unresolved[i]);
  if (!sizeof(unresolved)) text+="No unresolved errors.\n";
  smore(text,TP->QueryPageSize(),ME,"unresolved_prompt");
}

public void edit_errors();

public void errors_command(string cmd)
{
  int line;
  string *errarr;
  if (!TP) return;
  write("\n");
  if (cmd=="?")
    {
      write("Stored Errors, Commands:\n\n"
	    "<nr>   Read the description for this error.\n"
	    "e<nr> Edit the description for this error.\n"
	    "d<nr> Delete the error.\n"
	    "q        Quit editting.\n"
	    "?        This help.\n\n");
      return edit_errors();
    }
  errarr = Query(REMERR);
  if (sscanf(cmd,"%d",line))
    if (!check_line(line,errarr)) return edit_errors();
    else return print_help(({errarr[line-1]}),"edit_errors",ME);
  if (sscanf(cmd,"e%d",line))
    if (!check_line(line,errarr)) return edit_errors();
    else
      {
	TP->Set(RETFUN,SF(edit_errors));
	return edit_err(errarr[line-1]);
      }
  if (sscanf(cmd,"d%d",line))
    if (!check_line(line,errarr)) return edit_errors();
    else
      {
	RemoveError(errarr[line-1]);
	write("Deleted.\n\n");
	return edit_errors();
      }
  if (cmd=="q")
    {
      write("Done.\n\n");
      return;
    }
  write("--- !!! Unknown command!\n");
  edit_errors();
}

public void errors_prompt()
{
  write("\nStored Errors [<nr>, e<nr>, d<nr>, q, ?] ");
  input_to("errors_command");
}

public void edit_errors()
{
  string *errarr,text;
  int i;
  mapping errors;
  if (!TP) return;
  errors = QueryErrors();
  errarr = sort_array(m_indices(errors),SF(>));
  Set(REMERR,errarr);
  text = "Stored errors\n";
  text+= mkstr(strlen(text)-1,"-")+"\n\n";
  for(i=0;i<sizeof(errarr);i++)
    text+=sprintf("%03d. %s\n",i+1,errarr[i]);
  if (!sizeof(errarr)) text+="No errors stored.\n";
  smore(text,TP->QueryPageSize(),ME,"errors_prompt");
}
