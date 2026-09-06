/*--------------------------------------------------------------------------
 * /p/daemons/manbase.c   -- The auxilariy manserver
 *
 * Copyright (C) 15jan1998 by Softbyte for OSB
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * [Softbyte 15jan1998]  V1.0 All functions working
 *--------------------------------------------------------------------------
 */

#include <daemons.h>
#include <msgclass.h>

inherit "/std/base";

#define MANDIR(x)  "/doc/"+(x)
#define MANSAVE(x) DAEMONSAVEPATH "man/"+(x)
#define VERSION "V0.4-30mar1998 (c) Softbyte"

#define LINEOFFSET 250

// data:  ([keyword:file;line1;line2+1]) line1(2)==-1 from beginning(til end)
private mapping data;
mapping QueryData() {return data;}

private mapping index;
mapping QueryIndex() {return index;}

private nosave string myname,mydoc,myversion,myfile;
string QueryMyName() {return myname;}
string QueryMyDoc() {return mydoc;}
string QueryMyVersion() {return myversion;}
string QueryMyFile() {return myfile;}
private nosave string *myfiles;
string *QueryFiles() {return myfiles;}


// ------------------------------------------------------------------------
//                    internal auxilary functions
// ------------------------------------------------------------------------

// Save the internal data
void Save()
{
  if (myname==MANBASE) return; // the inehrit file itself
  save_object(myfile);
}

// insert the key:fname;line1,line2 pair into the data mapping
private void insert_data(string key,string fname,int line1,int line2)
{
mixed n_data;
mixed *tmp;
int i,flag;

  // alias or page?
  if (line1==0 && line2==0) n_data=fname; // alias
  else n_data=({fname,line1,line2});

  key=lower_case(key);
  if (!member(data,key))
  {
    data+=([key:({ n_data }) ]);
  }
  else
  {
    tmp=data[key];
    flag=1;
    // do not make double entries...expensive...
    for (i=0;i<sizeof(tmp)&&flag;i++)
    {
      if (stringp(tmp[i]) && stringp(n_data))
      {
        if (tmp[i]==n_data) flag=0;
      }
      else if (pointerp(tmp[i]) && pointerp(n_data))
      {
        if (tmp[i][0]==n_data[0] &&
            tmp[i][1]==n_data[1] &&
            tmp[i][2]==n_data[2])
              flag=0;
      }
      // else there is no match anyways
    }// end for
    if (flag) data[key]+=({ n_data });
  }
}

// Add a complete mapping into the data mapping
int AddData(mapping a_map)
{
  if (!a_map) return 0;
  walk_mapping(a_map,#'insert_data /*'*/);
  return 1;
}

// is a filename a manfile?
private int file_is_doc(string str)
{
  if (-1 !=  strstr(str,".")) return 0;
  if (-1 !=  strstr(str,"-old")) return 0;
  return 1;
}

// Add the full path to the filenames stored in the database
mixed *EnhanceFilename(mixed *n_data)
{
  mixed *m_data;
  int i;

  if (!n_data) return 0;

  // Too bad 'map' does no work as it works alwys on the
  // original array thus modifying our database instead of the result
  m_data=({});
  for (i=0;i<sizeof(n_data);i++)
  {
    if (stringp(n_data[i]))
      m_data+=({ n_data[i] });
    else
      m_data+=({ ({ MANDIR(mydoc+"/"+n_data[i][0]),
                  n_data[i][1], n_data[i][2] }) });
  }
  return m_data;
}

// ------------------------------------------------------------------------
//                    functions
// ------------------------------------------------------------------------

// Get all data to the given key
// format: ({ ({filename:line1;line2}), ({...}), string, ... })
// - if line1 is <0 the whole file is meant otherwise only the portion
//   between line1..line2-1
// - if a string is given instrad of an array it means an aliasstring
//   which will be reolved by the manserver
mixed *GetKeyword(string key)
{
  mixed *n_data;

  if (!key) return 0;
  n_data=data[key];
  n_data=EnhanceFilename(n_data);
  return n_data;
}

// returns an array holding all possible keywords
string *GetAllKeys()
{
  return m_indices(data);
}

// string fname:  the filename of the document
// int verbose:   shall we print some debug output
// the rest are internal paramter
// Return: 2: ok (runnign call_outs), 1: ok, 0:error
varargs int MakeIndex(string fname,int verbose,
                      int line,mixed *a_stack,mapping a_map)
{

string *strs;
string *args;
string command,act,s;
string report;
int i,partial,ret;

  ret=0;
  report="";
  if (line==0)
  {
    a_stack=({});
    a_map=([]);
    partial=0;

    s=read_file(MANDIR(mydoc+"/"+fname));
    if (!s)  // file to large using partial read
    {
      s=read_file(MANDIR(mydoc+"/"+fname),line+1,LINEOFFSET);
      partial=1;
    }
  }
  else
  {
      s=read_file(MANDIR(mydoc+"/"+fname),line+1,LINEOFFSET);
      partial=1;
  }


  if (s)
  {
    strs=explode(s,"\n");
    for (i=0;i<sizeof(strs);i++)
    {
      if (strs[i][0..2]=="<!-")
      {
        if (1==sscanf(strs[i],"<!- %s ->",command))
        {
          report+="command "+command+" found in line "+(line+i)+"\n";
          args=norm_id(command,1);
          switch(args[0])
          {
            case "begin":
              if (sizeof(args)!=2)
                report+="Line "+(line+i)+": Syntax error in begin\n";
              else
              {
                a_stack+=({args[1]});
                a_map+=([args[1]:fname;i+line;-1]);
              }
            break;
            case "end":
              if (sizeof(args)!=1)
                report+="Line "+(line+i)+": Syntax error in end.\n";
              else if (sizeof(a_stack)<1)
                report+="Line "+(line+i)+": End without begin\n";
              else
              {
                act=a_stack[<1];
                a_stack=a_stack[0..<2];
                a_map[act,2]=line+i;
              }
            break;
            case "alias":
              if (sizeof(args)!=3)
                report+="Line "+(line+i)+": Syntax error in alias.\n";
              else
              {
                a_map+=([args[1]:args[2];0;0]);
              }
            break;
            default:
              report+="Line "+(line+i)+": Unknown command '"+args[0]+"'\n";
          } // end switch command
        } // end is command
      } // end if HTML comment
    }// next i
  }// end if s
  else partial=0;  // EOF

  line+=LINEOFFSET;

  if (!partial)  // finished
  {
    if (sizeof(a_stack)>0)
    {
      report+=sprintf("Unresolved begins:\n"+implode(a_stack,", ")+"\n");
    }
   AddData(a_map);
   ret=1;
  }
  else
  {
    call_out("MakeIndex",1,fname,verbose,line,a_stack,a_map);
    ret=2;
  }
  if (this_player() && verbose) msg_write(CMSG_GENERIC,report);
  return ret;
}

// Performs the indexing (MakeIndex) on a file. If verbose is
// given some comments are written. The data is integrated into the
// database
int IndexFile(string fname,int verbose)
{
  int ret;

  if (!fname) return 0;

  if (member(index,fname)) index=m_delete(index,fname);

  if (file_size(MANDIR(mydoc+"/"+fname))<=0) return 0;

  index+=([fname:time()]);

  ret=MakeIndex(fname,verbose);
  if (ret==2 && this_player())
    msg_write(CMSG_GENERIC,"Wait...callouts running...\n");
  return 1;
}

// Adds a dir from the /doc path to the database
mapping IndexDir(string dname)
{
  string *strs;
  int i;
  mapping a_map;

  if (!dname) return 0;
  if (file_size(MANDIR(dname))!=-2) return 0; // no directory

  strs=get_dir(MANDIR(dname)+"/*");
  strs=filter(strs,#'file_is_doc /*'*/);

  myfiles=strs;  // all doc files of this server

  a_map=([]);
  for (i=0;i<sizeof(strs);i++)
  {
    a_map+=([strs[i]:strs[i];-1;-1]);
  }

  return a_map;
}

// ------------------------------------------------------------------------
//                    Creation
// ------------------------------------------------------------------------

// Initialises this module
int InitModule()
{
  mapping a_map;

  a_map=IndexDir(mydoc);
  AddData(a_map);
  Save();
  return 1;
}

void create()
{
string *idx;
  ::create();
  if (is_clone())
  {
    destruct(this_object());
    return;
  }


  myname=blueprint(this_object());
  idx=explode(myname,"/");

  myfile=MANSAVE(idx[<1]);
  mydoc=explode(myname,"/")[<1];
  myversion=VERSION;
  myfiles=({});


  //write("Info:"+myname+" - "+mydoc+" - "+myfile+" - "+myversion+"\n");

  if (myname==MANBASE) return; // the inherit file itself

  seteuid(getuid());
  if (file_size(myfile+".o")<0)
  {
    data=([]);
    index=([]);
    InitModule();
  }
  else
  {
    restore_object(myfile);
  }
}

public varargs int remove(int arg)
{
  Save();
  return ::remove(arg);
}

