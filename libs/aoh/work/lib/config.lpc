//---------------------------------------------------------------------------
// ini file reader
//
// This file reads in windows like ini files for the use of OSB
// (c) Softbyte 12nov97
//     non commercial use for OSB granted
//
//
// [Softbyte] 12nov97         : Creation and basic functions
//---------------------------------------------------------------------------
/**
  @author Softbyte
  @version V1.0
*/
/** @synopsis
       "/lib/config"->fun()
              or
       inherit "/lib/config"
*/
/** @description
 This file allows you to read in windows like ini files, i.e. getting
 information out of ascii files in key=data pairs. The data can be
 Arranged in sections as well

 Functions:
 ..... mixed GetKeyValue(string file,string section,string key)
 ..... [Read data belonging to 'key' from 'file' in a certain 'section'
 ..... string *GetSections(string file)
 ..... [Returns an array holding all section names of the ini file]
 ..... string *GetKeys(string file,string section)
 ..... [Returns an array holding all keynames of a given section]

 Optional functions:
 ..... int LoadIni(string file)
 ..... [Forces the reload of the inifile]
 ..... int UnloadIni(string file)
 ..... [Unloads the inifile from memory to save memory; will be done
 .....  automatically after a certain time]


 Inifile format:
 Lines starting with ';' or '*' are ignored (comments)
 Lines with '[mysection]' are considered a section named 'mysection'
 Lines with 'mykey=mydata' are key-data pairs to the corresponding
 .  section if following lines have the same keyword their arguments
 .  are concatted

 Data format:
 Integer:      a single number, e.g. '1'
 String:       text or text in "", e.g. Hello or "Hello"
 ............  "\n" are expanded correctly
 Integerarray: numbers seprated by ',', e.g. 1,2,3,4
 Stringarray:  strings separated by ',', e.g. a,b,c,d
 mappings:     key:data pairs separated by ',', e.g. red:1,blue:2

*/
/** @example
 Example ini file
 ; This is a test data file

 [section1]
 item1=1
 item2=Hello

 [section2]
 item1=2
 item2=Hello world
 item3=1,2,3,4
 item4=Hello this is a test!
 item5="12323"
 item6=a,b,c,d
 item7=a:1,b:2,c:hello

*/
/** @bugs Strings with a ":" in them must be quoted or they will be
          interpreted as mapping
*/
/** @see
*/


#include <config.h>
#include <properties.h>
#include <msgclass.h>
#include <string.h>

inherit "/std/base";

#define UNLOAD_TIME    90    // unload inifile after this time to save memory

private nosave mapping mydata;
mapping QueryData() {return mydata;}

// ********************** Internal functions ******************************
// Remove comments from the inifile
private int remove_comments(string s)
{
   s=({string})L_STR->clip_blanks(s);
   if (s[0]==';' || s[0]=='*') return 0;
   return 1;
}

// Check whether the argument is an mapping
private mapping MakeMapping(string *s)
{
mapping map;
int i;
string *s1;
int m_i;
string m_s;

  if (!s) return 0;
  map=([]);
  for (i=0;i<sizeof(s);i++)
  {
    s1=explode(s[i],":");
	if (!s1 || sizeof(s1)!=2) return 0;  // wrong syntax

    // An integer ?
    if (2==sscanf(s1[1],"%d%s",m_i,m_s) && sizeof(m_s)==0)
	  map+=([ s1[0] : m_i ]);
	else
	  map+=([ s1[0] : s1[1] ]);
  }
  return map;
}

// Check whether the argument is an string array or an integer array
private mixed *MakeArray(string *s)
{
int i;
int *a_i;
int m_i;
string m_s;
  if (!s) return 0;
  a_i=({});
  for (i=0;i<sizeof(s);i++)
  {
    // An integer ?
    if (2==sscanf(s[i],"%d%s",m_i,m_s) && sizeof(m_s)==0)
	{
	  a_i+=({m_i});
	}
	else return s;  // no integer array
  }
  return a_i;       // integer array
}

// Replace special characters in a string
private string MakeString(string s)
{
  s=implode(explode(s,"\\n"),"\n");
  return s;
}

// Analyse a string and return a proper data type
private mixed AnalyseString(string s)
{
int m_i;
string m_s;
string *m_a;
mapping m_m;
  // A string in ""
  if (sizeof(s) >= 2 && s[0]=='\"' && s[<1]=='\"') return MakeString(s[1..<2]);

  // An integer ?
  if (2==sscanf(s,"%d%s",m_i,m_s) && sizeof(m_s)==0) return m_i;


  // An array or mapping?
  m_a=explode(s,",");
  if (m_a && sizeof(m_a)>1)
  {
    m_m=MakeMapping(m_a);
	// A mapping!
	if (m_m) return m_m;

    // An array!
    return MakeArray(m_a);
  }

  // The common string is meant to be a mapping
  m_m=MakeMapping(({s}));
  if (m_m) return m_m;

  // Return a common string
  return MakeString(s);
}

void create()
{
  ::create();
  if (member(object_name(this_object()), '#') != -1)
  {
    destruct (this_object());
    return;
  }
  seteuid(getuid());
}



// ********************** Public functions ********************************
/**
  @function
   Explicitely load an ini file
  @param string file: Filename of the inifile, if the file does not exists
         ".ini"is appended to the filename and its tried again
  @return  0: Error, 1: Ok
*/
int LoadIni(string file)
{
string s;
string *a_s;
string ext;
  if (!mydata) mydata=([]);

  // Is the file already in memory?
  if (member(mydata,file)) mydata=m_delete(mydata,file);
  else call_out("UnloadIni",UNLOAD_TIME,file);

  ext="";

  if (file_size(file)<=0)
  {
    ext=".ini";
    if (file_size(file+ext)<=0)
      return 0;    // file not found
  }
  s=read_file(file+ext);
  a_s=explode(s,"\n")-({})-({0})-({""});
  a_s=filter(a_s,#'remove_comments /*'*/);
  mydata+=([file:a_s]);
  return 1;
}

/**
  @function
   Unload an ini file to free memory [Optional]
  @param string file: The name of the inifile, exactely as given to LoadIni
  @return 1: Ok, 0: Error
*/
int UnloadIni(string file)
{
  if (!file) return 0;
  if (!mydata) mydata=([]);
  if (member(mydata,file)) mydata=m_delete(mydata,file);
  return 1;
}

/**
  @function
     Gets the data from an inifile. When the inifile is already readin
     it is cached. This means that you have to explecitely "LoadIni"
     your inifile if you have changed it after usage. Otherwise no
     the loading of the inifile is performed automatically
  @param string file: The name of the inifile [with or without *.ini
  @param string section: The section of the inifile, "[section]
  @param string key: The key in the section "key=blabla
  @return string data: Any data corresponding to the key,section pair
          0: key or section or file not found
*/
mixed GetKeyValue(string file,string section,string key)
{
mixed data;
int i,j,idx;
string *a_s;
string s,s1;
  if (!mydata) mydata=([]);
  if (!file || !section || !key) return 0;
  // Try to load the file if it is not available
  if (!member(mydata,file))
  {
    if (!LoadIni(file)) return 0;
  }
  a_s=mydata[file];

  idx=member(a_s, "["+section+"]");
  if (idx<0) return 0;        // section not found

  for (i=idx+1;i<sizeof(a_s);i++)
  {
    // next section began ... aborting
    if (a_s[i][0]=='[' && a_s[i][<1]==']')
	{
	  return 0;
	}
    // possibly found the key
    if (strstr(a_s[i],key)==0)
	{
	  s=a_s[i][sizeof(key)..<1];
	  s=({string})L_STR->clip_blanks(s);
	  if (s[0]=='=')
	  {
	    s=s[1..<1];    // strip '='

        // Check whether we have to combine following lines
		j=i+1;
		do
		{
		  if (j>=sizeof(a_s)) break;
		  if (strstr(a_s[j],key)==0)
		  {
		    s1=a_s[j][sizeof(key)..<1];
		    s1=({string})L_STR->clip_blanks(s1);
		    if (s1[0]=='=')
			{
			  s+=s1[1..<1];
			  j++;
            }
			else s1=0;
		  }
		  else s1=0;
		}while(j<sizeof(a_s) && s1 && s1[0]=='=');
		i=j-1;

		data=AnalyseString(s);
		return data;
	  }
	}
  }

  return 0;
}

/**
  @function
    Returns the names of all sections found in the ini file
  @param   file: The name of the inifile [with or without *.ini]
  @return  Array holding all section names or 0 for error
*/
string *GetSections(string file)
{
string *a_s;
string *result;
int i;
  if (!mydata) mydata=([]);
  if (!file) return 0;
  // Try to load the file if it is not available
  if (!member(mydata,file))
  {
    if (!LoadIni(file)) return 0;
  }
  a_s=mydata[file];

  result=({});
  // Search the sections
  for (i=0;i<sizeof(a_s);i++)
  {
    if (a_s[i][0]=='[' && a_s[i][<1]==']') result+=({a_s[i][1..<2]});
  }
  return result;
}

/**
  @function
    Returns the names of all keys found in the given section of the ini file
  @param string file: The name of the inifile [with or without *.ini]
  @param string section: the section to be searched
  @return Array holding all key names or 0 for error
*/
string *GetKeys(string file,string section)
{
string *a_s;
string *result;
int i,idx;
string s;
  if (!mydata) mydata=([]);
  if (!file || !section) return 0;
  // Try to load the file if it is not available
  if (!member(mydata,file))
  {
    if (!LoadIni(file)) return 0;
  }
  a_s=mydata[file];


  // Search the section
  idx=member(a_s, "["+section+"]");
  if (idx<0) return 0;        // section not found

  result=({});
  for (i=idx+1;i<sizeof(a_s);i++)
  {
    // next section began ... returning
    if (a_s[i][0]=='[' && a_s[i][<1]==']')
	{
	  return result;
	}
	if (1==sscanf(a_s[i],"%s=",s))
	{
      s=({string})L_STR->clip_blanks(s);
	  result+=({s});
    }
  }
  return result;
}
