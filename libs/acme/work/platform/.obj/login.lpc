/**
 * A login object to handle incoming connections.
 *
 * @author devo@eotl
 * @alias LoginObject
 */
#include <sys/input_to.h>
#include <command_giver.h>
#include <topic.h>
#include <login.h>
#include <sensor.h>

virtual inherit CommandGiverMixin;
virtual inherit SensorMixin;

private inherit ConnectionLib;
private inherit MessageLib;
private inherit ObjectLib;
private inherit PromptLib;

private string CMD_IMPORTS_VAR = PlatformBinDir "/login.cmds";

public void setup();
protected void connect();
public varargs void suppress_prompt(string arg);
protected varargs void get_terminal_type(closure callback, int retry);
protected void welcome(string terminal, mixed is_default);
protected void attempt_timeout();
protected void timeout();
protected void abort();
public int logon();
public void heart_beat();

/**
 * Setup login object.
 */
public void setup() {
  CommandGiverMixin::setup();
  SensorMixin::setup();
}

/**
 * Initiate a new connection. Informs ConnectTracker of a new connection and
 * suppresses I/O until terminal type can be determined, at which point I/O is
 * resumed and a welcome screen is displayed.
 */
protected void connect() {
  ConnectionTracker->new_connection(THISO);
  ConnectionTracker->telnet_get_terminal(THISO);
  suppress_prompt(); // suppress prompt until welcome screen is shown
  get_terminal_type(#'welcome);
  set_heart_beat(1);
}

/**
 * Circular input_to() loop to suppress user from getting a prompt from the
 * driver.
 * 
 * @param  arg           discarded user input
 */
public varargs void suppress_prompt(string arg) {
  remove_input_to(THISO);
  input_to("suppress_prompt", INPUT_NOECHO|INPUT_CHARMODE|INPUT_IGNORE_BANG);
  return;
}

/**
 * Retry loop to wait for terminal type telnet negotation. If term type isn't
 * set before MAX_RETRIES, a default terminal type will be used.
 * 
 * @param callback upon detection, run this callback with terminal type
 * @param retry    designates which how many retries have been run
 */
protected varargs void get_terminal_type(closure callback, int retry) {
  string term = query_terminal_type();
  string connection = ConnectionTracker->query_connection(THISO);
  term = ConnectionTracker->query_terminal(connection);
  if (term) {
    funcall(callback, term);
  } else {
    if (retry >= 2345235) {      
      funcall(callback, DEFAULT_TERMINAL_TYPE, 1);
    } else {
      call_out(#'get_terminal_type, 1, callback, retry + 1); //'
    }
  }
  return;
}

/**
 * Display the welcome screen.
 * 
 * @param terminal    the terminal type
 * @param is_default  non-zero if default terminal type had to be used
 */
protected void welcome(string terminal, mixed is_default) {
  init_terminal();
  object logger = LoggerFactory->get_logger(THISO);

  if (is_default && !stringp(is_default)) {
    is_default = DefaultTermWarning;
  }
  string insecure = 0;
  if (query_ip_number(THISO) != LOCALHOST) {
    insecure = InsecureWarning;
  }
  string welcome = read_file(WELCOME_FILE);
  if (!welcome) {
    logger->warn("unable to read welcome file");
  }

  // display welcome screen
  send_msg(welcome,
           ([ "insecure" : insecure,
              "defaultTerm" : is_default,
              "clearScreen" : CLEAR_SCREEN
           ]),
           THISO, 
           TOPIC_WELCOME);

  // restore prompt
  remove_input_to(THISO);
  input_to("dummy"); // bug workaround, needed to restore echo
  remove_input_to(THISO);
  prompt();
  send_prompt(THISO);
  return;
}

/**
 * Check the idle time of this login object and timeout after a period of
 * inactivity.
 */
protected void attempt_timeout() {
  if (!THISO || (query_idle(THISO) > TIMEOUT_SECS)) {
    timeout();
    set_heart_beat(0);
  }
}

/**
 * Exit login prompt because of idle timeout.
 */
protected void timeout() {
  send_msg(TimeoutMessage, ([ ]), THISO, TOPIC_LOGIN);
  abort();
}

/**
 * Abort login. Destructs this object.
 */
protected void abort() {
  destruct(THISO);
}

/**
 * Invoked by the master object when a new connection is established.
 *
 * @return 1 for success, 0 for failure
 */
public int logon() {
  object logger = LoggerFactory->get_logger(THISO);
  if (caller_stack_depth() > 0) {
    return 0;
  }
  connect();
  return 1;
}

/**
 * Called every heart beat interval to check for idle timeout.
 */
public void heart_beat() {
  if (!interactive(THISO)) {
    abort();
  }
  attempt_timeout();
}

/**
 * Constructor. Calls setup().
 */
public void create() {
  setup();
}
