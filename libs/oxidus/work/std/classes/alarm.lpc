#ifndef __ALARM_C__
#define __ALARM_C__

/**
 * Class representing a scheduled alarm in the alarm daemon.
 *
 * Alarms can be configured to execute at specific times with various
 * recurrence patterns (boot, once, hourly, daily, weekly, yearly).
 *
 * @property {string} type - Alarm type (B/O/H/D/W/Y)
 * @property {string} file - Target file path to execute the alarm in
 * @property {string} func - Function name to call when alarm triggers
 * @property {mixed *} args - Optional arguments to pass to the function
 * @property {int} master - Whether this is a master alarm (1) or not (0)
 * @property {int} last_run - Timestamp of last execution
 * @property {string} pattern - Time pattern specific to alarm type:
 *   - B: seconds after boot
 *   - O: y-m-D@H:M format
 *   - H: minute M
 *   - D: H:M format
 *   - W: D@H:M format (D = day 0-6)
 *   - Y: m-D@H:M format
 * @property {string} id - Unique identifier for the alarm
 */
class Alarm {
  string type;
  string file;
  string func;
  mixed *args;
  int master;
  int last_run;
  string pattern;
  string id;
}

#endif // __ALARM_C__
