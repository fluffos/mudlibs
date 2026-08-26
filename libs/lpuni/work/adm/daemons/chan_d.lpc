/* chan_d.c

 Tacitus @ LPUniversity
 30-SEPT-05
 Modular Channel Daemon

 Version 2.5

*/

/* Last modified by Tacitus on July 5th, 2006 */

int registerModule(string name, string path);
int registerCh(string moduleName, string chName);
int removeModule(string modulename);
int removeCh(string chName);
int tune(string channel, string user, int flag);
int valid_ch(string chName);
int valid_module(string moduleName);
int snd_msg(string channel, string user, string msg);
int filter_listing(string element);
string *getChls(string moduleName);
string *getMods();
string *getTuned(string argument);
void rec_msg(string channel, string msg);

mapping channels;
mapping modules;

void create()
{
     string str, err, *arr;
     int i, time;

     channels = ([]);
     modules = ([]);

     str = read_file("/adm/daemons/chmodules/modInstalled");

     if (!str) {
          return;
     }

     arr = explode(str, "\n");
     write("\n");

     for (i = 0; i < sizeof(arr); i++)
     {
          if (arr[i][0] == '#' || arr[i][0] == ' ' || !arr[i] ) {
               continue;
          }

        if(find_object(arr[i])) destruct(find_object(arr[i]));
          write("  Loading channel module: " + arr[i] + "...");
          err = catch(load_object(arr[i]));

          if (err != 0) {
               write("\t\nError " + err + " when loading " + arr[i] + "\n");

          }

          else
          {
               time = time() - time;
               write("(" + time/60 + "." + time % 60 + ") ");
          }
     }
}

int registerModule(string name, string path)
{
     string *keys;

     keys = keys(modules);
     if(!name || !path) return 0;

     if(member_array(name, keys) != -1)
     {
          if(modules[name] == path) return 1;
          else return -1;
     }
     modules[name] = path;

     return 1;
}

int unregisterModule(string moduleName)
{
    string *keys = keys(modules);

    if(!moduleName || member_array(moduleName, keys) == -1) return 0;

    if(modules[moduleName] != file_name(previous_object())) return 0;

    foreach(mixed key, mixed value in channels)
    {
        if(value["module"] == moduleName) map_delete(channels, key);
    }

    return 1;
}

int registerCh(string moduleName, string chName)
{
     string *keys;
     string newName = chName;

     keys = keys(modules);
     if(member_array(moduleName, keys) == -1) return -1;
     keys = keys(channels);

     if(modules[moduleName] != file_name(previous_object())) return 0;

     if(member_array(chName, keys) != -1)
     {
          if(channels[chName]["module"] == moduleName)
          {
              channels[chName]["listeners"] = ({});
              return 1;
          }
          else newName = moduleName[0..3] + chName;
     }
     channels[newName] = (["module" : moduleName, "real_name" : chName, "listeners" : ({})]);

     return 1;
}

int removeCh(string chName)
{
     string *keys;

     keys = keys(channels);
     if(member_array(chName, keys) == -1) return 0;
     map_delete(channels, chName);

     return 1;
}

int tune(string channel, string user, int flag)
{
     string *keys;
     object modObj;

     keys = keys(channels);
     if(member_array(channel, keys) == -1) return 0;

     if(!valid_module(channels[channel]["module"]))
     {
          map_delete(channels, channel);
          return 0;
     }

     modObj = find_object(modules[channels[channel]["module"]]);

     if(!modObj->isAllowed(channels[channel]["real_name"], user, flag)) return 0;
     if(flag == 1 && member_array(user, channels[channel]["listeners"]) == -1)
          channels[channel]["listeners"] += ({user});
     if(flag == 0 && member_array(user, channels[channel]["listeners"]) != -1)
          channels[channel]["listeners"] -= ({user});

     return 1;
}

int valid_ch(string chName)
{
     string *keys;

     keys = keys(channels);
     if(member_array(chName, keys) != -1) return 1;

     return 0;
}

int valid_module(string moduleName)
{
     string *keys;

     keys = keys(modules);
     if(member_array(moduleName, keys) != -1) return 1;

     return 0;
}

int snd_msg(string channel, string user, string msg)
{
     object modObj;
     string *keys;

     keys = keys(channels);
     if(member_array(channel, keys) == -1) return 0;

     if(!valid_module(channels[channel]["module"]))
     {
          map_delete(channels, channel);
          return 0;
     }
     modObj = find_object(modules[channels[channel]["module"]]);

     if(member_array(user, channels[channel]["listeners"]) == -1) return 0;
     if(!modObj->isAllowed(channels[channel]["real_name"], user)) return 0;
     if(!msg) return(notify_fail("Syntax: <channel> <msg>\n"));
     if(modObj->rec_msg(channels[channel]["real_name"], user, msg)) return 1;
     else return 0;
}

string *getChls(string moduleName)
{
     string *ret = ({}), *keys;
     int i;

     keys = keys(channels);

     if(moduleName == "all") ret = keys;
     else {

          for(i = 0; i < sizeof(keys); i++)
          if(channels[keys[i]]["module"] == moduleName) ret += ({keys[i]});
     }

     ret = filter_array(ret, "filter_listing", this_object());
     ret = sort_array(ret, 1);

     return ret;

}

string *getTuned(string argument)
{
     string *ret = ({});

     if(!argument) return ret;
     if(sizeof(channels[argument]["listeners"]) <= 0) return ret;
     ret = channels[argument]["listeners"];
     foreach(string name in ret)
         if(find_living(name))
             if(!interactive(find_living(name))) ret -= ({ name });
     return ret;
}

int filter_listing(string element)
{
     object modObj;
     modObj = find_object(modules[channels[element]["module"]]);
     if(modObj->isAllowed(element, this_player()->query_name())) return 1;
     return 0;
}

string *getMods()
{
     string *keys = keys(modules);

     return keys;
}

void rec_msg(string channel, string msg)
{
     string *listeners;
     string *keys;
     int i;
     object ob;

     keys = keys(channels);
     if(member_array(channel, keys) == -1) return 0;

     if(!valid_module(channels[channel]["module"]))
     {
          map_delete(channels, channel);
          return 0;
     }

     listeners = channels[channel]["listeners"];

     for(i = 0; i < sizeof(listeners); i ++)
     {
          ob = find_living(listeners[i]);

          if(!objectp(ob))
          {
              channels[channel]["listeners"] -= ({ listeners[i] });
              continue;
          }

          tell_object(ob, msg + NOR);
     }
}
