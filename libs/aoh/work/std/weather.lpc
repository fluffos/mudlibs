/* std/weather
**
** The basic code for nightday- and weather-servers.
**
**  15-Jun-93 [Mateese] Written from the old /obj/nightday
**  14-Jan-94 [Mateese] Made notification of users more flexible.
**  08-Sep-94 [Mateese] InitStates() added.
**  15-Sep-94 [Mateese] Fixed wrap-around bug in SetState().
*/

#include <config.h>
#include <properties.h>
#include <weather.h>
#include <nightday.h>

#define THIS this_object()
#define ENV  environment

/*-------------------------------------------------------------------------*/

public  int state;        // Actual state
private object *clients;  // objects to notify, a sorted array
private object *clientstodo, *clientsdone; // temp for notifies

public mixed *statedata;

private mixed *c_data;  // For faster access and temporary changes

/*-------------------------------------------------------------------------*/

public int QueryStateLength ();
public varargs int SetState (int new, int no_callout);
public int QueryState ();

/*-------------------------------------------------------------------------*/
public void InitStates()
{
  int i;

  statedata = ({mixed *})NIGHTDAY->QueryStates();
  // Make a value copy in case the inheritor changes it.
  if (pointerp(statedata)) {
    statedata = ({mixed *})NIGHTDAY->QueryStates() + ({});
    for (i=sizeof(statedata); i--; )
      if (pointerp(statedata[i]))
        statedata[i] = statedata[i]+({});
  }
}

public void StartServer() {
  int daytime, len;
  if (!statedata)
    SetState(0);
  else {
    daytime = time() % DAY_LENGTH;
    for (state = 0
        ; state < sizeof(statedata) && daytime >= (len = statedata[state][WD_LENGTH])
        ; daytime -= len, state++
        );
    if (state < sizeof(statedata)) SetState (state);
    else SetState(0);
  }
}

public void create() {
  if (object_name(THIS) == "/std/weather") return;
  clients = ({});
  c_data = allocate (WD_USER);
  InitStates();
  StartServer();
}

/*-------------------------------------------------------------------------*/
// True properties

public mixed *QueryStates () { return statedata; }
public mixed *SetStates (mixed *v) {
  return statedata = v;
}

public mixed * QueryStateEntry (int ix) {
  return statedata[ix];
}
public mixed * SetStateEntry (int ix, mixed v) {
  return statedata[ix] = v;
}

public int CountStates () { return statedata && sizeof(statedata); }
public int TimeLeft()     { return find_call_out ("NextState"); }

/*-------------------------------------------------------------------------*/
// Actually queried functions, including temporary caches.

public varargs mixed QueryStateData (int flag) {
  mixed *s_data;
  s_data = QueryStateEntry(QueryState());
  if (flag) return s_data;
  if (sizeof(c_data) < sizeof(s_data))
    return c_data+s_data[sizeof(c_data)..];
  return c_data;
}
public mixed SetStateData (mixed v) {
  mixed *s_data;
  if (sizeof(v) < sizeof(c_data))
    v += c_data[sizeof(v)..];
  c_data = v;
  s_data = QueryStateEntry(QueryState());
  if (sizeof(c_data) < sizeof(s_data))
    c_data += s_data[sizeof(c_data)..];
  else if (sizeof(c_data) > sizeof(s_data))
    c_data = c_data[0..sizeof(s_data)-1];
  return c_data;
}

public string QueryStateDesc ()        { return c_data[WD_DESC]; }
public string SetStateDesc (string m)  { return c_data[WD_DESC] = m; }

public string QueryChangeDesc ()       { return c_data[WD_CDESC]; }
public string SetChangeDesc (string m) { return c_data[WD_CDESC] = m; }

public int QuerySunLight ()    { return c_data[WD_SUNLIGHT]; }
public int SetSunLight (int i) { return c_data[WD_SUNLIGHT] = i; }

public int QueryStateLength ()    { return c_data[WD_LENGTH]; }
public int SetStateLength (int i) { return c_data[WD_LENGTH] = i; }

/*-------------------------------------------------------------------------
** Handling of the clients-array.
*/

public object *QueryClients()        { return clients; }
public object *SetClients(object *c) {
  clientstodo = 0; clientsdone = 0;
  return clients = c;
}

public void AddClient (object client) {
  clients = (clients || ({}))+({client});
}

public void RemoveClient (object client) {
  clients = (clients || ({}))-({client});
}

public void CleanupClients () {
  if (!clients) return;
  clients = clients - ({ 0 });
}

/*-------------------------------------------------------------------------
** Notify all clients about the current state.
*/

public varargs int IsMyPlayer (object player, object env) {
  int depth;
  mixed env_server, lastenv;

  if (!player)
    return 0;

  // Search the nearest enclosing 'Outdoors' environment and
  // count the depth.
  // If there is none, the room is indoors, but might contain windows,
  // so we simply call ourself responsible.
  env = player;
  lastenv = 0;
  depth = 0;
  env_server = 0;
  while (env) {
    depth++;
    env_server = ({mixed})env->Query(P_OUTDOORS);
    lastenv = env;
    if (env_server)
      break;
    env = ENV(env);
  }

  if (stringp(env_server))
     env_server = load_object(env_server);

  if (!lastenv || (env_server && env_server != THIS))
    return 0;

  return depth;
}

public mixed * FilterData (object client, mixed *data, int newstate) {
  object *envlist, env;
  int depth, i;

  depth = IsMyPlayer(client, &env);
  if (!depth && interactive(client))
    return 0;

  // Collect the list of environments.
  // envlist[0] is the inmost.
  envlist = allocate(depth-1);
  env = client;
  i = 0;
  while (i < depth-1 && (env = ENV(env))) {
    envlist[i] = env;
    i++;
  }

  // Filter the data through the environments
  data = data + ({});  // filter a copy, not the original
  for (i = sizeof(envlist); data && i--;)
    data = ({mixed *})envlist[i]->FilterWeatherData(client, data, newstate);

  return data;
}

public int NotifyClient (object client, mixed *data, int newstate) {
  data = FilterData(client, data, newstate);
  if (data)
    client->Set(P_STATEDATA, data);
  return !!data;
}

private void _notify_clients (mixed *data, int newstate) {
  int amount;

  //dtell("tune", "in _notify_clients\n\n");
  //dtell("tune", sprintf("clientstodo is: %O\n\n", clientstodo));

  if ( (amount = sizeof(clientstodo)) > 100 )
    amount = 100;
  if (amount > 0)
  {
    map (clientstodo[0..amount-1], #'NotifyClient /*'*/, data, newstate);
    clientstodo = clientstodo[amount..];
  }
  if (sizeof(clientstodo))
    call_out ("_notify_clients", 0, data, newstate);
  else {
    //clients = clientsdone;
    clientsdone = 0;
  }
}

public varargs void NotifyClients (mixed *data, int newstate) {
  if (!clients) return;
  //dtell("tune", "after !clients\n\n");
  //dtell("tune", sprintf("Size of clients: %O\n\n", sizeof(clients)));

  if (!data) {
    data = QueryStateData();
    newstate = QueryState();
  }
  filter(users(), #'NotifyClient /*'*/, data, newstate);
  if (sizeof(clients) <= 100)
    map (clients, #'_notify_clients /*'*/, data, newstate);
  else if (clientsdone) // Notify in progress: delay!
    call_out ("NotifyClients", sizeof(clients) / 10, data, newstate);
  else {
    clientstodo = clients + ({}); clientsdone = ({});
    _notify_clients(data, newstate);
  }
}

/*-------------------------------------------------------------------------
** Change the state from to <new>.
** This does merely set the state variable, reloads the c_data cache
** and then notifies all clients.
** If <no_callout> is not set, it also restarts the call_out() to NextState().
*/

public int QueryState () { return state; }
public varargs int SetState (int new, int no_callout) {
  if (!statedata) state = new;
  else            state = new % (CountStates() || 1);
  if(state==0 || !statedata)
    InitStates(); // new data for each day
  c_data = QueryStateEntry(state);
  NotifyClients(c_data, state);
  if (!no_callout) {
    remove_call_out ("NextState");
    call_out ("NextState", c_data[WD_LENGTH]);
  }
  return state;
}

public void NextState () {
  SetState (QueryState()+1);
}

/***************************************************************************/
